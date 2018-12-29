%{
  #include <cstdio>
  #include <cstdlib>
  #include <iostream>
  #include <string>
  #include <map>
  #include "codeGenerator.h"

  BlockExprNode *root;

  void yyerror(char *) {};

  int yylex(void);

  int lineNum = 1;
  map<string, E_TYPE> varTable;

  void setVarType(VariableExprNode *);
  void addNewVar(string name, E_TYPE type);
  E_TYPE checkExprType(ExprNode *left, ExprNode *right);
%}

%union {
  int symbol;
  string *string;
  VariableExprNode *var;
  ExprNode *expr;
  vector<VarDecStatementNode*> *vars;
  vector<ExprNode*> *exprs;
  BlockExprNode *block;
  StatementNode *statement;
  VarDecStatementNode *var_dec;
}

%token <string> INT DOUBLE FLOAT CHAR VOID
%token <string> CSTR CINT CDOUBLE CCHAR
%token <string> VAR

%token <symbol> LBRACK RBRACK LPAREN RPAREN LBRACE RBRACE
%token <symbol> EQUAL ADD SUB MUL DIV SADD SSUB SMUL SDIV
%token <symbol> RETURN
%token <symbol> IF ELSE FOR WHILE
%token <symbol> COMMA COLON SEMICOLON
%token <symbol> EQ NE GR GE LW LE AND OR


%type <var> variable type
%type <vars> function_args
%type <expr> expr logic_expr const
%type <exprs> invoke_args
%type <block> block global_block local_block
%type <statement> global_statement local_statement
%type <statement> function_declaration array_declaration
%type <var_dec> variable_declaration  // source of problems
%type <statement> condition loop
%type <symbol> compare

%left EQUAL
%left OR
%left AND 
%left ADD SUB SADD SSUB
%left MUL DIV SMUL SDIV

%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

%%

program: global_block { root = $1; };

global_block: global_statement              { $$ = new BlockExprNode(); $$->statements->push_back($<statement>1); }
            | global_block global_statement { $$->statements->push_back($<statement>2); }
            ;

global_statement: function_declaration      { $$ = $1; }
                | expr SEMICOLON            { $$ = new ExprStatementNode($1); }
                ;

function_declaration: type variable LPAREN function_args RPAREN block { $$ = new FuncDecStatementNode($1, $2, $4, $6); }; /*为啥这里不记录*/

type: INT       { $$ = new VariableExprNode(*$1, E_INT); delete $1; }
    | DOUBLE    { $$ = new VariableExprNode(*$1, E_DOUBLE); delete $1; }
    | CHAR      { $$ = new VariableExprNode(*$1, E_CHAR); delete $1; }
    | VOID      { $$ = new VariableExprNode(*$1, E_VOID); delete $1; }
    ;

variable: VAR     { $$ = new VariableExprNode(*$1); delete $1; }
        | SUB VAR { std::string tempstr = "-"; $$ = new VariableExprNode(tempstr + *$2); delete $2; std::cout << tempstr + *$2 << endl; }
        ;

function_args:                                          { $$ = new vector<VarDecStatementNode*>(); }                // to edit
             | variable_declaration                     { $$ = new vector<VarDecStatementNode*>(); $$->push_back($1); }
             | function_args COMMA variable_declaration { $1->push_back($<var_dec>3); $$ = $1; }
             ; 

block: LBRACE local_block RBRACE  { $$ = $2; };

local_block: /* NULL */                   { $$ = new BlockExprNode(); }
           | local_statement              { $$ = new BlockExprNode(); $$->statements->push_back($<statement>1); }
           | local_block local_statement  { $$->statements->push_back($<statement>2); }
           ;

local_statement: variable_declaration SEMICOLON { $$ = $1; }
               | array_declaration SEMICOLON    { $$ = $1; }
               | condition                      { $$ = $1; }
               | loop                           { $$ = $1; }
               | expr SEMICOLON                 { $$ = new ExprStatementNode($1); }
               | RETURN expr SEMICOLON          { $$ = new ReturnStatementNode($2); }
               | SEMICOLON                      { /* NULL */ }
               ;

variable_declaration: type variable             { $2->_type = $1->_type; $$ = new VarDecStatementNode($1, $2); addNewVar($2->name, $2->_type); }
                    | type variable EQUAL expr  { $2->_type = $1->_type; $$ = new VarDecStatementNode($1, $2, $4); addNewVar($2->name, $2->_type); }
                    ;

array_declaration: type variable LBRACK CINT RBRACK                             { $$ = new ArrayDecStatementNode($1, $2, atol($4->c_str())); }
                 | type variable LBRACK RBRACK EQUAL LBRACE invoke_args RBRACE  { $$ = new ArrayDecStatementNode($1, $2, $7); }
                 | type variable LBRACK RBRACK EQUAL CSTR                       { $$ = new ArrayDecStatementNode($1, $2, *$6); } /*!!!!*/
                 ;

condition: IF LPAREN logic_expr RPAREN block %prec LOWER_THAN_ELSE    { $$ = new IfStatementNode($3, $5); }
         | IF LPAREN logic_expr RPAREN block ELSE block               { $$ = new IfStatementNode($3, $5, $7); }
         ;

loop: FOR LPAREN expr SEMICOLON logic_expr SEMICOLON expr RPAREN block  { $$ = new ForStatementNode($3, $5, $7, $9); }
    | WHILE LPAREN logic_expr RPAREN block                              { $$ = new WhileStatementNode($3, $5); }
    ;

expr: variable                                  { $<var>$ = $1; }
    | const                                     { $$ = $1; }
    | expr ADD expr                             { $$ = new OperatorExprNode($1, $2, $3); $$->_type = checkExprType($1, $3); }
    | expr SUB expr                             { $$ = new OperatorExprNode($1, $2, $3); $$->_type = checkExprType($1, $3); }
    | expr MUL expr                             { $$ = new OperatorExprNode($1, $2, $3); $$->_type = checkExprType($1, $3); }
    | expr DIV expr                             { $$ = new OperatorExprNode($1, $2, $3); $$->_type = checkExprType($1, $3); }
    | variable SADD expr                        { $$ = new OperatorExprNode($1, $2, $3); $$ = new AssignExprNode($1, $$); setVarType($1); $$->_type = checkExprType($1, $3); }
    | variable SSUB expr                        { $$ = new OperatorExprNode($1, $2, $3); $$ = new AssignExprNode($1, $$); setVarType($1); $$->_type = checkExprType($1, $3); }
    | variable SMUL expr                        { $$ = new OperatorExprNode($1, $2, $3); $$ = new AssignExprNode($1, $$); setVarType($1); $$->_type = checkExprType($1, $3); }
    | variable SDIV expr                        { $$ = new OperatorExprNode($1, $2, $3); $$ = new AssignExprNode($1, $$); setVarType($1); $$->_type = checkExprType($1, $3); }
    | expr compare expr                         { $$ = new OperatorExprNode($1, $2, $3); $$->_type = E_INT; }
    | variable EQUAL expr                       { $$ = new AssignExprNode($1, $3); setVarType($1); checkExprType($1, $3); $$->_type = $1->_type; }
    | variable LPAREN invoke_args RPAREN        { $$ = new FuncExprNode($1, $3); addNewVar($1->name, E_FUNC); setVarType($1); $$->_type =$1->_type; }
    | variable LBRACK expr RBRACK               { $$ = new IndexExprNode($1, $3); $$->_type = $1->_type; }
    | variable LBRACK expr RBRACK EQUAL expr    { $$ = new IndexExprNode($1, $3); checkExprType($1, $6); $$->_type = $1->_type; }
    | variable LBRACK expr RBRACK SADD expr     { $$ = new IndexExprNode($1, $3); $$ = new OperatorExprNode($$, $5, $6); $$ = new IndexExprNode($1, $3, $$); checkExprType($1, $6); $$->_type = $1->_type; }    
    | variable LBRACK expr RBRACK SSUB expr     { $$ = new IndexExprNode($1, $3); $$ = new OperatorExprNode($$, $5, $6); $$ = new IndexExprNode($1, $3, $$); checkExprType($1, $6); $$->_type = $1->_type; }    
    | variable LBRACK expr RBRACK SMUL expr     { $$ = new IndexExprNode($1, $3); $$ = new OperatorExprNode($$, $5, $6); $$ = new IndexExprNode($1, $3, $$); checkExprType($1, $6); $$->_type = $1->_type; }    
    | variable LBRACK expr RBRACK SDIV expr     { $$ = new IndexExprNode($1, $3); $$ = new OperatorExprNode($$, $5, $6); $$ = new IndexExprNode($1, $3, $$); checkExprType($1, $6); $$->_type = $1->_type; }    
    | LPAREN expr RPAREN                        { $$ = $2; }
    | LPAREN type RPAREN expr                   { $$ = new CastExprNode($2, $4); $$->_type = $2->_type; }
    ;

invoke_args: /* NULL */               { $$ = new vector<ExprNode*>(); }
           | expr                     { $$ = new vector<ExprNode*>(); $$->push_back($1); }
           | invoke_args COMMA expr   { $1->push_back($3); $$ = $1; }
           ;

logic_expr: logic_expr OR logic_expr  { $$ = new OperatorExprNode($1, $2, $3); }
          | logic_expr AND logic_expr { $$ = new OperatorExprNode($1, $2, $3); }
          | expr                      { $$ = $1;}
          ;

block: LBRACE local_block RBRACE   { $$ = $2; }
     | local_statement             { $$ = new BlockExprNode(); $$->statements->push_back($<statement>1); }
     ;

const: CINT                         { $$ = new IntExprNode(atoi($1->c_str())); delete $1; }
     | CDOUBLE                      { $$ = new DoubleExprNode(atoi($1->c_str())); delete $1; }
     | CCHAR                        { $$ = new CharExprNode($1->front()); delete $1; }
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

void addNewVar(string name, E_TYPE type) {
  map<string, E_TYPE>::iterator it;
  it = varTable.find(name);
  if (it == varTable.end()) {
    varTable[name] = type;
  } else if (type == E_FUNC) {
    varTable[name] = type;
  } else {
    cout << "line " << lineNum << ": redefinition of variable " << name << endl;
    varTable[name] = type;
  }
}

E_TYPE checkExprType(ExprNode *left, ExprNode *right) {
  // to edit
}

void setVarType(VariableExprNode *var){
  map<string, E_TYPE>::iterator it;
  it = varTable.find(var->name);
  if(it == varTable.end()){
    var->_type = E_UNKNOWN;    
  }
  else{
    var->_type = (*it).second;
  }
}
