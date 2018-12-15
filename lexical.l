%{
  #include <string>
  #include <iostream>
  #include "codeGenerator.h"
  #include "yacc.tab.h"
  #define SYMBOL(t)  (yylval.symbol = t)
  extern int lineNum;
%}

%option noyywrap

%%

"return"            return SYMBOL(RETURN);

"int"               						{ yylval.string = new string(yytext, yyleng); return INT; }
"double"            						{ yylval.string = new string(yytext, yyleng); return DOUBLE; }
"float"             						{ yylval.string = new string(yytext, yyleng); return FLOAT; }
"char"													{ yylval.string = new string(yytext, yyleng); return CHAR; }
"void"													{ yylval.string = new string(yytext, yyleng); return VOID; }

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

"="															return SYMBOL(EQUAL);

";"															return SYMBOL(SEMICOLON);

[ \t\r]*												;

"\n"														lineNum += 1;

^"#include ".+									;

.																cout << "Unknow SYMBOL! text: " << yytext << endl; yyterminate();

%%