%{
  #include <cstdio>
  #include <cstdlib>
  #include <iostream>
  #include <map>
  #include "codeGenerator.h"

  BlockExprNode *root;

  void yyerror(char *) {};

  int yylex(void);

  int lineNum = 1;
  map<string, E_TYPE> varTable;

  void setVarType(VariableExprNode *);
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
%token <symbol> EQUAL
%token <symbol> SEMICOLON
%token <symbol> RETURN

%type <var> variable type
%type <vars> function_args
%type <expr> expr logic_expr
%type <exprs> invoke_args
%type <block> global_block local_block
%type <statement> global_statement local_statement
%type <statement> function_declaration array_declaration
%type <var_dec> variable_declaration  // source of problems
%type <statement> condition loop
%type <token> compare

%left EQUAL

%nonassoc LOWER_THAN_ELSE

%%

program: global_block { root = $1; };

global_block: global_statement              { $$ = new BlockExprNode(); $$->statements->push_back($<statement>1); }
            | global_block global_statement { $$->statements->push_back($<statement>2); }
            ;

global_statement: function_declaration      { $$ = $1; }
                | expr SEMICOLON            { $$ = new ExprStatementNode($1); }
                ;

function_declaration: type variable LPAREN function_args RPAREN block { $$ = new FuncDecStatementNode($1, $2, $4, $6); };

type: INT       { $$ = new VariableExprNode(*$1, E_INT); delete $1; }
    | DOUBLE    { $$ = new VariableExprNode(*$1, E_DOUBLE); delete $1; }
    | CHAR      { $$ = new VariableExprNode(*$1, E_CHAR); delete $1; }
    | VOID      { $$ = new VariableExprNode(*$1, E_VOID); delete $1; }
    ;

variable: VAR   { $$ = new VariableExprNode(*$1); delete $1; };

function_args:                                          { $$ = new vector<VarDecStatementNode*>(); }                // to edit
             | variable_declaration                     { $$ = new vector<VarDecStatementNode*>(); $$->push_back($1); }
             | function_args COMMA variable_declaration { $1->push_back($<var_dec>3); $$ = $1; }
             ; 

block: LBRACE local_block RBRACE  { $$ = $2; };

local_block: local_statement              { $$ = new BlockExprNode(); $$->statements->push_back($<statement>1); }
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

/*
condition: IF LPAREN logic_expr RPAREN block ;
*/

loop: FOR LPAREN expr SEMICOLON logic_expr SEMICOLON expr RPAREN block  { $$ = new ForStatementNode($3, $5, $7, $9); }
    | WHILE LPAREN logic_expr RPAREN block                              { $$ = new WhileStatementNode($3, $5); }
    ;

expr: variable            { $<var>$ = $1; }
    | const               { $$ = $1; }
    | expr ADD expr       { $$ = new OperatorExprNode($1, $2, $3); $$->_type = checkExprType($1, $3); }
    | expr SUB expr       { $$ = new OperatorExprNode($1, $2, $3); $$->_type = checkExprType($1, $3); }
    | expr MUL expr       { $$ = new OperatorExprNode($1, $2, $3); $$->_type = checkExprType($1, $3); }
    | expr DIV expr       { $$ = new OperatorExprNode($1, $2, $3); $$->_type = checkExprType($1, $3); }
    | variable SADD expr  { $$ = new OperatorExprNode($1, $2, $3); $$ = new AssignExprNode($1, $$); setVarType($1); $$->_type = checkExprType($1, $3); }
    | variable SSUB expr  { $$ = new OperatorExprNode($1, $2, $3); $$ = new AssignExprNode($1, $$); setVarType($1); $$->_type = checkExprType($1, $3); }
    | variable SMUL expr  { $$ = new OperatorExprNode($1, $2, $3); $$ = new AssignExprNode($1, $$); setVarType($1); $$->_type = checkExprType($1, $3); }
    | variable SDIV expr  { $$ = new OperatorExprNode($1, $2, $3); $$ = new AssignExprNode($1, $$); setVarType($1); $$->_type = checkExprType($1, $3); }
    | expr compare 
                 


%%

void addNewVar(string name, E_TYPE type) {
  map<string, E_TYPE>::iterator it;
  it = varTable.find(name);
  if (it == varTable.end()) {
    varTable[name] = type;
  } else if (type == E_FUNC) {
    varTable[name] = type;
  } else {
    cout << "line " << lineNumber << ": redefinition of variable " << name << endl;
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
