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

%token <symbol> LBRACK RBRACK
%token <symbol> EQUAL
%token <symbol> SEMICOLON
%token <symbol> RETURN

%type <var> variable type
%type <block> global_block

%%

program: global_block { root = $1; };

global_block: global_statement              {$$ = new BlockExprNode(); $$->statements->push_back($1);}
            | global_block global_statement {$$->statements->push_back($2);}




