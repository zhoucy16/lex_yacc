%{
  #include <cstdio>
  #include <cstdlib>
  #include <iostream>
  #include <string>
  #include <map>
  #include "codeGenerator.h"

  BlockExprNode *root;

  int yyerror(char *msg);

  int yylex(void);

  int lineNum = 1;
  map<string, E_TYPE> variableTable;

  void setVariableType(VariableExprNode *);
  void definitionVar(string name, E_TYPE type);
  E_TYPE checkVariableType(ExprNode *left, ExprNode *right);
  void noSemicolonError();
%}

%union {
  int symbol;
  string *str;
  VariableExprNode *var;
  ExprNode *expr;
  vector<VarDecStatementNode*> *vars;
  vector<ExprNode*> *exprs;
  BlockExprNode *block;
  StatementNode *statement;
  VarDecStatementNode *var_dec;
}

%token <str> INT DOUBLE FLOAT CHAR VOID
%token <str> CSTR CINT CDOUBLE CCHAR
%token <str> VAR

%token <symbol> LBRACK RBRACK LPAREN RPAREN LBRACE RBRACE
%token <symbol> EQUAL ADD SUB MUL DIV SADD SSUB SMUL SDIV
%token <symbol> RETURN BREAK CONTINUE
%token <symbol> IF ELSE FOR WHILE
%token <symbol> COMMA COLON SEMICOLON QUATATION
%token <symbol> EQ NE GR GE LW LE AND OR
%type <symbol> compare

%type <var> variable type
%type <vars> functionArgs
%type <expr> expr logicExpr const
%type <exprs> invokeArgs
%type <block> block globalBlock localBlock
%type <statement> globalStatement localStatement
%type <statement> functionDeclaration arrayDeclaration
%type <var_dec> variableDeclaration  // source of problems
%type <statement> condition loop


%left EQUAL
%left OR
%left AND 
%left ADD SUB SADD SSUB
%left MUL DIV SMUL SDIV

%nonassoc LowerThanElse
%nonassoc ELSE

%%

program: globalBlock { root = $1; };

globalBlock: globalStatement              { $$ = new BlockExprNode(); $$->statements->push_back($<statement>1); }
            | globalBlock globalStatement { $$->statements->push_back($<statement>2); }
            ;

globalStatement: functionDeclaration        { $$ = $1; }
                | expr SEMICOLON            { $$ = new ExprStatementNode($1); }
                | expr error                { noSemicolonError(); $$ = new ExprStatementNode($1); }   
                ;

functionDeclaration: type variable LPAREN functionArgs RPAREN block { $$ = new FuncStatementNode($1, $2, $4, $6); }; /*为啥这里不记录*/

type: INT       { $$ = new VariableExprNode(*$1, E_INT); delete $1; }
    | DOUBLE    { $$ = new VariableExprNode(*$1, E_DOUBLE); delete $1; }
    | CHAR      { $$ = new VariableExprNode(*$1, E_CHAR); delete $1; }
    | VOID      { $$ = new VariableExprNode(*$1, E_VOID); delete $1; }
    ;

variable: VAR     { $$ = new VariableExprNode(*$1); delete $1; }
        | SUB VAR { std::string tempstr = "-"; $$ = new VariableExprNode(tempstr + *$2); delete $2; }
        ;

functionArgs:                                          { $$ = new vector<VarDecStatementNode*>(); }                // to edit
             | variableDeclaration                     { $$ = new vector<VarDecStatementNode*>(); $$->push_back($1); }
             | functionArgs COMMA variableDeclaration  { $1->push_back($<var_dec>3); $$ = $1; }
             ; 

block: LBRACE localBlock RBRACE  { $$ = $2; }
     | localStatement            { $$ = new BlockExprNode(); $$->statements->push_back($<statement>1); }
     ;

localBlock: /* NULL */                   { $$ = new BlockExprNode(); }
           | localStatement              { $$ = new BlockExprNode(); $$->statements->push_back($<statement>1); }
           | localBlock localStatement  { $$->statements->push_back($<statement>2); }
           ;

localStatement: variableDeclaration SEMICOLON   { $$ = $1; }
               | arrayDeclaration SEMICOLON     { $$ = $1; }
               | condition                      { $$ = $1; }
               | loop                           { $$ = $1; }
               | expr SEMICOLON                 { $$ = new ExprStatementNode($1); }
               | RETURN expr SEMICOLON          { $$ = new ReturnStatementNode($2); }
               | RETURN SEMICOLON               { $$ = new ReturnStatementNode(); }
               | BREAK SEMICOLON                { $$ = new BreakStatementNode(); }
               | CONTINUE SEMICOLON             { $$ = new ContinueStatementNode(); }
               | SEMICOLON                      { /* NULL */ }
               | variableDeclaration error      { noSemicolonError(); $$ = $1; }
               | arrayDeclaration error         { noSemicolonError(); $$ = $1; }
               | expr error                     { noSemicolonError(); $$ = new ExprStatementNode($1); }
               | RETURN expr error              { noSemicolonError(); $$ = new ReturnStatementNode($2); }
               ;

variableDeclaration: type variable             { $2->_type = $1->_type; $$ = new VarDecStatementNode($1, $2); definitionVar($2->name, $2->_type); }
                    | type variable EQUAL expr  { $2->_type = $1->_type; $$ = new VarDecStatementNode($1, $2, $4); definitionVar($2->name, $2->_type); }
                    ;

arrayDeclaration: type variable LBRACK CINT RBRACK                             { $$ = new ArrayDecStatementNode($1, $2, atol($4->c_str())); }
                 | type variable LBRACK RBRACK EQUAL LBRACE invokeArgs RBRACE  { $$ = new ArrayDecStatementNode($1, $2, $7); }
                 | type variable LBRACK RBRACK EQUAL CSTR                       { $$ = new ArrayDecStatementNode($1, $2, *$6); } /*!!!!*/
                 ;

condition: IF LPAREN logicExpr RPAREN block %prec LowerThanElse    { $$ = new IfStatementNode($3, $5); }
         | IF LPAREN logicExpr RPAREN block ELSE block               { $$ = new IfStatementNode($3, $5, $7); }
         ;

loop: FOR LPAREN expr SEMICOLON logicExpr SEMICOLON expr RPAREN block  { $$ = new ForStatementNode($3, $5, $7, $9); }
    | WHILE LPAREN logicExpr RPAREN block                              { $$ = new WhileStatementNode($3, $5); }
    ;

expr: variable                                  { $<var>$ = $1; }
    | const                                     { $$ = $1; }
    | expr ADD expr                             { $$ = new OperatorExprNode($1, $2, $3); $$->_type = checkVariableType($1, $3); }
    | expr SUB expr                             { $$ = new OperatorExprNode($1, $2, $3); $$->_type = checkVariableType($1, $3); }
    | expr MUL expr                             { $$ = new OperatorExprNode($1, $2, $3); $$->_type = checkVariableType($1, $3); }
    | expr DIV expr                             { $$ = new OperatorExprNode($1, $2, $3); $$->_type = checkVariableType($1, $3); }
    | variable SADD expr                        { $$ = new OperatorExprNode($1, $2, $3); $$ = new AssignExprNode($1, $$); setVariableType($1); $$->_type = checkVariableType($1, $3); }
    | variable SSUB expr                        { $$ = new OperatorExprNode($1, $2, $3); $$ = new AssignExprNode($1, $$); setVariableType($1); $$->_type = checkVariableType($1, $3); }
    | variable SMUL expr                        { $$ = new OperatorExprNode($1, $2, $3); $$ = new AssignExprNode($1, $$); setVariableType($1); $$->_type = checkVariableType($1, $3); }
    | variable SDIV expr                        { $$ = new OperatorExprNode($1, $2, $3); $$ = new AssignExprNode($1, $$); setVariableType($1); $$->_type = checkVariableType($1, $3); }
    | expr compare expr                         { $$ = new OperatorExprNode($1, $2, $3); $$->_type = E_INT; }
    | variable EQUAL expr                       { $$ = new AssignExprNode($1, $3); setVariableType($1); checkVariableType($1, $3); $$->_type = $1->_type; }
    | variable LPAREN invokeArgs RPAREN        { $$ = new FuncExprNode($1, $3); definitionVar($1->name, E_FUNC); setVariableType($1); $$->_type =$1->_type; }
    | variable LBRACK expr RBRACK               { $$ = new IndexExprNode($1, $3); $$->_type = $1->_type; }
    | variable LBRACK expr RBRACK EQUAL expr    { $$ = new IndexExprNode($1, $3, $6); checkVariableType($1, $6); $$->_type = $1->_type; }
    | variable LBRACK expr RBRACK SADD expr     { $$ = new IndexExprNode($1, $3); $$ = new OperatorExprNode($$, $5, $6); $$ = new IndexExprNode($1, $3, $$); checkVariableType($1, $6); $$->_type = $1->_type; }    
    | variable LBRACK expr RBRACK SSUB expr     { $$ = new IndexExprNode($1, $3); $$ = new OperatorExprNode($$, $5, $6); $$ = new IndexExprNode($1, $3, $$); checkVariableType($1, $6); $$->_type = $1->_type; }    
    | variable LBRACK expr RBRACK SMUL expr     { $$ = new IndexExprNode($1, $3); $$ = new OperatorExprNode($$, $5, $6); $$ = new IndexExprNode($1, $3, $$); checkVariableType($1, $6); $$->_type = $1->_type; }    
    | variable LBRACK expr RBRACK SDIV expr     { $$ = new IndexExprNode($1, $3); $$ = new OperatorExprNode($$, $5, $6); $$ = new IndexExprNode($1, $3, $$); checkVariableType($1, $6); $$->_type = $1->_type; }    
    | LPAREN expr RPAREN                        { $$ = $2; }
    | LPAREN type RPAREN expr                   { $$ = new CastExprNode($2, $4); $$->_type = $2->_type; }
    ;

invokeArgs: /* NULL */                               { $$ = new vector<ExprNode*>(); }
           | expr                                     { $$ = new vector<ExprNode*>(); $$->push_back($1); }
           | invokeArgs COMMA expr                   { $1->push_back($3); $$ = $1; }
           ;

logicExpr: logicExpr OR logicExpr  { $$ = new OperatorExprNode($1, $2, $3); }
          | logicExpr AND logicExpr { $$ = new OperatorExprNode($1, $2, $3); }
          | expr                      { $$ = $1;}
          ;

const: CINT                         { $$ = new IntExprNode(atoi($1->c_str())); delete $1; }
     | CDOUBLE                      { $$ = new DoubleExprNode(atoi($1->c_str())); delete $1; }
     | CCHAR                        { $$ = new CharExprNode($1->front()); delete $1; }
     | CSTR                         { $$ = new StringExprNode(*$1); delete $1; }
     | SUB CINT                     { $$ = new IntExprNode(-atoi($2->c_str())); delete $2; }
     | SUB CDOUBLE                  { $$ = new IntExprNode(-atoi($2->c_str())); delete $2; }
     ;

compare: EQ         { $$ = $1; }
       | NE         { $$ = $1; }
       | GR         { $$ = $1; }
       | GE         { $$ = $1; }
       | LW         { $$ = $1; }
       | LE         { $$ = $1; }
       ;

%%

void definitionVar(string name, E_TYPE type) {
  map<string, E_TYPE>::iterator it;
  it = variableTable.find(name);
  if (it == variableTable.end()) {
    variableTable[name] = type;
  } else if (type == E_FUNC) {
    variableTable[name] = type;
  } else {
    cout << "line " << lineNum << ": redefinition of variable " << name << endl;
    variableTable[name] = type;
  }
}

E_TYPE checkVariableType(ExprNode *left, ExprNode *right) {
  if (left ->_type == E_UNKNOWN) {
    cout << "line" << lineNum << "left has unknown type" << endl;
    return E_UNKNOWN;
  }
  if (right ->_type == E_UNKNOWN) {
    cout << "line" << lineNum << "right has unknown type" << endl;
    return E_UNKNOWN;
  }


}

void setVariableType(VariableExprNode *var){
  map<string, E_TYPE>::iterator it;
  it = variableTable.find(var->name);
  if(it == variableTable.end()){
    var->_type = E_UNKNOWN;    
  }
  else{
    var->_type = (*it).second;
  }
}

void noSemicolonError() {
  cout << "line" << lineNum << ": 缺少分号" << endl;
}


int yyerror(char *msg)
{
	cout << "line" << lineNum << ": 有无法匹配的内容" << endl;
	return 1;	
}