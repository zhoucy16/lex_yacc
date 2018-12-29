/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INT = 258,
     DOUBLE = 259,
     FLOAT = 260,
     CHAR = 261,
     VOID = 262,
     CSTR = 263,
     CINT = 264,
     CDOUBLE = 265,
     CCHAR = 266,
     VAR = 267,
     LBRACK = 268,
     RBRACK = 269,
     LPAREN = 270,
     RPAREN = 271,
     LBRACE = 272,
     RBRACE = 273,
     EQUAL = 274,
     ADD = 275,
     SUB = 276,
     MUL = 277,
     DIV = 278,
     SADD = 279,
     SSUB = 280,
     SMUL = 281,
     SDIV = 282,
     RETURN = 283,
     IF = 284,
     ELSE = 285,
     FOR = 286,
     WHILE = 287,
     COMMA = 288,
     COLON = 289,
     SEMICOLON = 290,
     EQ = 291,
     NE = 292,
     GR = 293,
     GE = 294,
     LW = 295,
     LE = 296,
     AND = 297,
     OR = 298,
     LOWER_THAN_ELSE = 299
   };
#endif
/* Tokens.  */
#define INT 258
#define DOUBLE 259
#define FLOAT 260
#define CHAR 261
#define VOID 262
#define CSTR 263
#define CINT 264
#define CDOUBLE 265
#define CCHAR 266
#define VAR 267
#define LBRACK 268
#define RBRACK 269
#define LPAREN 270
#define RPAREN 271
#define LBRACE 272
#define RBRACE 273
#define EQUAL 274
#define ADD 275
#define SUB 276
#define MUL 277
#define DIV 278
#define SADD 279
#define SSUB 280
#define SMUL 281
#define SDIV 282
#define RETURN 283
#define IF 284
#define ELSE 285
#define FOR 286
#define WHILE 287
#define COMMA 288
#define COLON 289
#define SEMICOLON 290
#define EQ 291
#define NE 292
#define GR 293
#define GE 294
#define LW 295
#define LE 296
#define AND 297
#define OR 298
#define LOWER_THAN_ELSE 299




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 23 "AST_parser.y"
{
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
/* Line 1529 of yacc.c.  */
#line 149 "AST_parser.hpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

