%{
  #include <string>
  #include <iostream>
  #include "codeGenerator.h"
  #include "AST_parser.hpp"
  #define SYMBOL(t)  (yylval.symbol = t)
  extern int lineNum;
%}

%option noyywrap

%%

"return"           							return SYMBOL(RETURN);
"break"										return SYMBOL(BREAK);
"continue"									return SYMBOL(CONTINUE);

"int"               						{ yylval.str = new string(yytext, yyleng); return INT; }
"double"            						{ yylval.str = new string(yytext, yyleng); return DOUBLE; }
"float"             						{ yylval.str = new string(yytext, yyleng); return FLOAT; }
"char"										{ yylval.str = new string(yytext, yyleng); return CHAR; }
"void"										{ yylval.str = new string(yytext, yyleng); return VOID; }

"if"                            			return SYMBOL(IF);
"else"                          			return SYMBOL(ELSE);
"for"                           			return SYMBOL(FOR);
"while"                         			return SYMBOL(WHILE);


["].*["]									{
												yylval.str = new string(yytext, yyleng);
												yylval.str->erase(yylval.str->begin());
												yylval.str->erase(yylval.str->end() - 1);
												return CSTR;
											}
[_A-Za-z][_0-9A-Za-z]*						{ yylval.str = new string(yytext, yyleng); return VAR; }
[0-9]+\.[0-9]*								{ yylval.str = new string(yytext, yyleng); return CDOUBLE; }
[0-9]*\.[0-9]+								{ yylval.str = new string(yytext, yyleng); return CDOUBLE; }
[0-9]+										{ yylval.str = new string(yytext, yyleng); return CINT; }
['].[']										{
												yylval.str = new string(yytext, yyleng);
												yylval.str->erase(yylval.str->begin());
												yylval.str->erase(yylval.str->end() - 1);
												return CCHAR;
											}

"["											return SYMBOL(LBRACK);
"]"											return SYMBOL(RBRACK);
"("											return SYMBOL(LPAREN);
")"											return SYMBOL(RPAREN);
"{"											return SYMBOL(LBRACE);
"}"											return SYMBOL(RBRACE);

"="											return SYMBOL(EQUAL);

"=="                            			return SYMBOL(EQ);
"!="                            			return SYMBOL(NE);
">"                             			return SYMBOL(GR);
">="                            			return SYMBOL(GE);
"<"                            				return SYMBOL(LW);
"<="                            			return SYMBOL(LE);

"&&"                            			return SYMBOL(AND);
"||"                            			return SYMBOL(OR);


"+"                             return SYMBOL(ADD);
"-"                             return SYMBOL(SUB);
"*"                             return SYMBOL(MUL);
"/"                             return SYMBOL(DIV);

"+="                            return SYMBOL(SADD);
"-="                            return SYMBOL(SSUB);
"*="                            return SYMBOL(SMUL);
"/="                            return SYMBOL(SDIV);

","															return SYMBOL(COMMA);
":"															return SYMBOL(COLON);
";"															return SYMBOL(SEMICOLON);

[ \t\r]*												;

"\n"														lineNum += 1;

^"#include ".+									;

.																cout << "Unknow SYMBOL! text: " << yytext << endl; yyterminate();

%%
