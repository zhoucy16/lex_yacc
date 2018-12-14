%{
#include <stdio.h> 
#define LT					1
#define	LE					2
#define GT					3
#define	GE					4
#define	EQ					5
#define NE					6

#define WHILE				18
#define	DO					19
#define ID          20
#define NUMBER      21
#define RELOP       22

#define NEWLINE     23
#define ERRORCHAR   24

int yylval;
%}

 
delim		[ \t \n]
ws			{delim}+
letter	[A-Za-z_]
digit		[0-9]
id			{letter}({letter}|{digit})*
number	{digit}+(\.{digit}+)?(E[+-]?{digit}+)?



%%

  
{ws}	          {;/* 此时词法分析器没有动作，也不返回，而是继续分析。 */}
while	          {return (WHILE);}
do		          {return (DO);}
{id}	          {yylval = installID (); return (ID);}
{number}	      {yylval = installNum (); return (NUMBER);}
"<"	            {yylval = LT; return (RELOP);}
"<="	          {yylval = LE; return (RELOP);}
"="	            {yylval = EQ; return (RELOP);}
"<>"	          {yylval = NE; return (RELOP);}
">"	            {yylval = GT; return (RELOP);}
">="	          {yylval = GE; return (RELOP);}

.								{yylval = ERRORCHAR; return ERRORCHAR;}
 
%%

int installID () {
  /* 把词法单元装入符号表并返回指针。*/
	return ID;
}


int installNum () {
	/* 类似上面的过程，但词法单元不是标识符而是数 */
  return NUMBER;
}


int yywrap (){
  return 1;
}

void writeout(int c){
  switch(c){
  	case ERRORCHAR: fprintf(yyout, "(ERRORCHAR, \"%s\") ", yytext);break;
  	case RELOP: fprintf(yyout, "(RELOP, \"%s\") ", yytext);break;  	  
    case WHILE: fprintf(yyout, "(WHILE, \"%s\") ", yytext);break;
    case DO: fprintf(yyout, "(DO, \"%s\") ", yytext);break;
    case NUMBER: fprintf(yyout, "(NUM, \"%s\") ", yytext);break;
    case ID: fprintf(yyout, "(ID, \"%s\") ", yytext);break;
    case NEWLINE: fprintf(yyout, "\n");break;
    default:break;
  }
  return;
}


int main (int argc, char ** argv){
	int c,j=0;
	if (argc>=2){
	  if ((yyin = fopen(argv[1], "r")) == NULL){
	    printf("Can't open file %s\n", argv[1]);
	    return 1;
	  }
	  if (argc>=3){
	    yyout=fopen(argv[2], "w");
	  }
	}
	/* yyin和yyout是lex中定义的输入输出文件指针，它们指明了
	 * lex生成的词法分析器从哪里获得输入和输出到哪里。
	 * 默认：键盘输入，屏幕输出。 
	 */
	while (c = yylex()){
		writeout(c);
		j++;
		if (j%5 == 0) writeout(NEWLINE);
	}
	if(argc>=2){
	  fclose(yyin);
	  if (argc>=3) fclose(yyout);
	}
	return 0;
}
