/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

#ifndef YY_YY_AST_PARSER_HPP_INCLUDED
# define YY_YY_AST_PARSER_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
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
    BREAK = 284,
    CONTINUE = 285,
    IF = 286,
    ELSE = 287,
    FOR = 288,
    WHILE = 289,
    COMMA = 290,
    COLON = 291,
    SEMICOLON = 292,
    QUATATION = 293,
    EQ = 294,
    NE = 295,
    GR = 296,
    GE = 297,
    LW = 298,
    LE = 299,
    AND = 300,
    OR = 301,
    LowerThanElse = 302
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 24 "AST_parser.y" /* yacc.c:1909  */

  int symbol;
  string *str;
  VariableExprNode *var;
  ExprNode *expr;
  vector<VarDecStatementNode*> *vars;
  vector<ExprNode*> *exprs;
  BlockExprNode *block;
  StatementNode *statement;
  VarDecStatementNode *var_dec;

#line 114 "AST_parser.hpp" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_AST_PARSER_HPP_INCLUDED  */
