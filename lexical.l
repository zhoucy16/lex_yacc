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

"int"               						{ yylval.string = new string(yytext, yyleng); return INT; }
"double"            						{ yylval.string = new string(yytext, yyleng); return DOUBLE; }
"float"             						{ yylval.string = new string(yytext, yyleng); return FLOAT; }
"char"										{ yylval.string = new string(yytext, yyleng); return CHAR; }
"void"										{ yylval.string = new string(yytext, yyleng); return VOID; }

"else if"									return SYMBOL(ELIF);
"if"                            			return SYMBOL(IF);
"else"                          			return SYMBOL(ELSE);
"for"                           			return SYMBOL(FOR);
"while"                         			return SYMBOL(WHILE);


["].*["]												{
																	yylval.string = new string(yytext, yyleng);
																	yylval.string->erase(yylval.string->begin());
																	yylval.string->erase(yylval.string->end() - 1);
																	return CSTR;
																}
[_A-Za-z][_0-9A-Za-z]*					{ yylval.string = new string(yytext, yyleng); return VAR; }
-?[0-9]+\.[0-9]*								{ yylval.string = new string(yytext, yyleng); return CDOUBLE; }
-?[0-9]*\.[0-9]+								{ yylval.string = new string(yytext, yyleng); return CDOUBLE; }
-?[0-9]+												{ yylval.string = new string(yytext, yyleng); return CINT; }
['].[']													{
																	yylval.string = new string(yytext, yyleng);
																	yylval.string->erase(yylval.string->begin());
																	yylval.string->erase(yylval.string->end() - 1);
																	return CCHAR;
																}

"["															return SYMBOL(LBRACK);
"]"															return SYMBOL(RBRACK);
"("															return SYMBOL(LPAREN);
")"															return SYMBOL(RPAREN);
"{"															return SYMBOL(LBRACE);
"}"															return SYMBOL(RBRACE);

"="															return SYMBOL(EQUAL);

"=="                            							return SYMBOL(EQ);
"!="                            							return SYMBOL(NE);
">"                             							return SYMBOL(GR);
">="                            							return SYMBOL(GE);
"<"                            								return SYMBOL(LW);
"<="                            							return SYMBOL(LE);

"&&"                            return SYMBOL(AND);
"||"                            return SYMBOL(OR);


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