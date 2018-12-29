/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



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
     QUATATION = 291,
     EQ = 292,
     NE = 293,
     GR = 294,
     GE = 295,
     LW = 296,
     LE = 297,
     AND = 298,
     OR = 299,
     LOWER_THAN_ELSE = 300
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
#define QUATATION 291
#define EQ 292
#define NE 293
#define GR 294
#define GE 295
#define LW 296
#define LE 297
#define AND 298
#define OR 299
#define LOWER_THAN_ELSE 300




/* Copy the first part of user declarations.  */
#line 1 "AST_parser.y"

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
  map<string, E_TYPE> varTable;

  void setVarType(VariableExprNode *);
  void addNewVar(string name, E_TYPE type);
  E_TYPE checkExprType(ExprNode *left, ExprNode *right);
  void noSemicolonError();


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 24 "AST_parser.y"
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
/* Line 193 of yacc.c.  */
#line 221 "AST_parser.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 234 "AST_parser.cpp"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  25
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   351

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  82
/* YYNRULES -- Number of states.  */
#define YYNSTATES  149

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   300

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,    10,    12,    15,    18,    25,
      27,    29,    31,    33,    35,    38,    39,    41,    45,    49,
      50,    52,    55,    58,    61,    63,    65,    68,    72,    74,
      77,    80,    83,    87,    90,    95,   101,   110,   117,   123,
     131,   141,   147,   149,   151,   155,   159,   163,   167,   171,
     175,   179,   183,   187,   191,   196,   201,   208,   215,   222,
     229,   236,   240,   245,   246,   248,   252,   256,   260,   262,
     266,   268,   270,   272,   274,   276,   279,   282,   284,   286,
     288,   290,   292
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      47,     0,    -1,    48,    -1,    49,    -1,    48,    49,    -1,
      50,    -1,    61,    35,    -1,    61,     1,    -1,    51,    52,
      15,    53,    16,    54,    -1,     3,    -1,     4,    -1,     6,
      -1,     7,    -1,    12,    -1,    21,    12,    -1,    -1,    57,
      -1,    53,    33,    57,    -1,    17,    55,    18,    -1,    -1,
      56,    -1,    55,    56,    -1,    57,    35,    -1,    58,    35,
      -1,    59,    -1,    60,    -1,    61,    35,    -1,    28,    61,
      35,    -1,    35,    -1,    57,     1,    -1,    58,     1,    -1,
      61,     1,    -1,    28,    61,     1,    -1,    51,    52,    -1,
      51,    52,    19,    61,    -1,    51,    52,    13,     9,    14,
      -1,    51,    52,    13,    14,    19,    17,    62,    18,    -1,
      51,    52,    13,    14,    19,     8,    -1,    29,    15,    63,
      16,    54,    -1,    29,    15,    63,    16,    54,    30,    54,
      -1,    31,    15,    61,    35,    63,    35,    61,    16,    54,
      -1,    32,    15,    63,    16,    54,    -1,    52,    -1,    64,
      -1,    61,    20,    61,    -1,    61,    21,    61,    -1,    61,
      22,    61,    -1,    61,    23,    61,    -1,    52,    24,    61,
      -1,    52,    25,    61,    -1,    52,    26,    61,    -1,    52,
      27,    61,    -1,    61,    65,    61,    -1,    52,    19,    61,
      -1,    52,    15,    62,    16,    -1,    52,    13,    61,    14,
      -1,    52,    13,    61,    14,    19,    61,    -1,    52,    13,
      61,    14,    24,    61,    -1,    52,    13,    61,    14,    25,
      61,    -1,    52,    13,    61,    14,    26,    61,    -1,    52,
      13,    61,    14,    27,    61,    -1,    15,    61,    16,    -1,
      15,    51,    16,    61,    -1,    -1,    61,    -1,    62,    33,
      61,    -1,    63,    44,    63,    -1,    63,    43,    63,    -1,
      61,    -1,    17,    55,    18,    -1,    56,    -1,     9,    -1,
      10,    -1,    11,    -1,     8,    -1,    21,     9,    -1,    21,
      10,    -1,    37,    -1,    38,    -1,    39,    -1,    40,    -1,
      41,    -1,    42,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    70,    70,    72,    73,    76,    77,    78,    81,    83,
      84,    85,    86,    89,    90,    93,    94,    95,    98,   100,
     101,   102,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   118,   119,   122,   123,   124,   127,   128,
     131,   132,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   158,   159,   160,   163,   164,   165,   168,
     169,   172,   173,   174,   175,   176,   177,   180,   181,   182,
     183,   184,   185
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "DOUBLE", "FLOAT", "CHAR", "VOID",
  "CSTR", "CINT", "CDOUBLE", "CCHAR", "VAR", "LBRACK", "RBRACK", "LPAREN",
  "RPAREN", "LBRACE", "RBRACE", "EQUAL", "ADD", "SUB", "MUL", "DIV",
  "SADD", "SSUB", "SMUL", "SDIV", "RETURN", "IF", "ELSE", "FOR", "WHILE",
  "COMMA", "COLON", "SEMICOLON", "QUATATION", "EQ", "NE", "GR", "GE", "LW",
  "LE", "AND", "OR", "LOWER_THAN_ELSE", "$accept", "program",
  "global_block", "global_statement", "function_declaration", "type",
  "variable", "function_args", "block", "local_block", "local_statement",
  "variable_declaration", "array_declaration", "condition", "loop", "expr",
  "invoke_args", "logic_expr", "const", "compare", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    46,    47,    48,    48,    49,    49,    49,    50,    51,
      51,    51,    51,    52,    52,    53,    53,    53,    54,    55,
      55,    55,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    57,    57,    58,    58,    58,    59,    59,
      60,    60,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    62,    62,    62,    63,    63,    63,    54,
      54,    64,    64,    64,    64,    64,    64,    65,    65,    65,
      65,    65,    65
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     2,     2,     6,     1,
       1,     1,     1,     1,     2,     0,     1,     3,     3,     0,
       1,     2,     2,     2,     1,     1,     2,     3,     1,     2,
       2,     2,     3,     2,     4,     5,     8,     6,     5,     7,
       9,     5,     1,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     4,     4,     6,     6,     6,     6,
       6,     3,     4,     0,     1,     3,     3,     3,     1,     3,
       1,     1,     1,     1,     1,     2,     2,     1,     1,     1,
       1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     9,    10,    11,    12,    74,    71,    72,    73,    13,
       0,     0,     0,     2,     3,     5,     0,    42,     0,    43,
       0,     0,    75,    76,    14,     1,     4,     0,     0,     0,
      63,     0,     0,     0,     0,     0,     7,     0,     0,     0,
       0,     6,    77,    78,    79,    80,    81,    82,     0,     0,
      61,    15,     0,    64,     0,    53,    48,    49,    50,    51,
      44,    45,    46,    47,    52,    62,     0,     0,    16,    55,
      54,     0,    33,     0,     0,     0,     0,     0,     0,     0,
      65,     0,    19,     0,     0,     0,     0,    28,     0,     8,
      70,     0,     0,    24,    25,     0,    17,    56,    57,    58,
      59,    60,    34,     0,    20,     0,     0,     0,     0,    33,
      29,    22,    30,    23,    31,    26,    18,    21,    32,    27,
      68,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    38,    67,    66,     0,    41,    35,     0,     0,
       0,    37,    63,    39,     0,     0,     0,    36,    40
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    12,    13,    14,    15,    88,    17,    67,    89,   103,
      90,    91,    92,    93,    94,    95,    54,   121,    19,    48
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -76
static const yytype_int16 yypact[] =
{
     309,   -76,   -76,   -76,   -76,   -76,   -76,   -76,   -76,   -76,
     309,   105,     8,   309,   -76,   -76,     2,   310,    21,   -76,
      -4,   238,   -76,   -76,   -76,   -76,   -76,    35,    57,   330,
     330,   330,   330,   330,   330,   330,   -76,   330,   330,   330,
     330,   -76,   -76,   -76,   -76,   -76,   -76,   -76,   330,   330,
     -76,   189,   211,    47,   -12,    47,   259,   259,    96,    96,
     259,   259,    96,    96,    47,    47,     2,    76,   -76,   148,
     -76,   330,    31,   149,   189,   330,   330,   330,   330,   330,
      47,   330,   209,   330,    59,    79,    82,   -76,     2,   -76,
     -76,     1,    10,   -76,   -76,    81,   -76,    47,   259,   259,
      96,    96,    47,   179,   -76,   109,   330,   330,   330,    77,
     -76,   -76,   -76,   -76,   -76,   -76,   -76,   -76,   -76,   -76,
      47,     9,   269,    11,    84,   149,   330,   330,   330,   149,
      85,    92,    70,   -76,    98,   -26,   -76,   -76,     7,   149,
     330,   -76,   330,   -76,   246,   -13,   149,   -76,   -76
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -76,   -76,   -76,   100,   -76,     6,   -15,   -76,   -34,   -76,
     -75,   -48,   -76,   -76,   -76,     0,   -18,   -62,   -76,   -76
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      18,    28,   110,    68,    70,   147,    16,   104,    25,   140,
      21,   112,    49,    18,     9,   141,    20,   126,   127,    16,
      71,    71,    36,    27,   142,   125,    96,   129,   117,    52,
      53,    55,    56,    57,    58,    59,   111,    60,    61,    62,
      63,    37,    38,    39,    40,   113,   123,    24,    64,    65,
      81,    72,   126,   127,   126,   127,    41,    66,    42,    43,
      44,    45,    46,    47,   133,   134,   135,    37,    38,    39,
      40,    80,    51,   109,   106,    97,    98,    99,   100,   101,
      66,   102,   114,   105,    42,    43,    44,    45,    46,    47,
     124,   132,    73,   130,   107,   136,    81,   108,   131,   137,
     139,    37,    38,    39,    40,   143,   120,   122,   120,    74,
     118,   138,   148,    26,    22,    23,   115,    24,    42,    43,
      44,    45,    46,    47,   145,     0,   120,   120,   120,    37,
      38,    39,    40,    42,    43,    44,    45,    46,    47,     0,
     144,   126,    53,     0,   119,     0,    42,    43,    44,    45,
      46,    47,     1,     2,     0,     3,     4,     5,     6,     7,
       8,     9,     0,     0,    10,     0,    82,    75,     0,     0,
      11,     0,    76,    77,    78,    79,     0,    83,    84,     0,
      85,    86,     1,     2,    87,     3,     4,     5,     6,     7,
       8,     9,     1,     2,    10,     3,     4,   116,     0,     0,
      11,     0,     0,     0,     0,     0,     0,    83,    84,     0,
      85,    86,     1,     2,    87,     3,     4,     5,     6,     7,
       8,     9,     0,     0,    10,    69,     0,     0,     0,     0,
      11,    37,    38,    39,    40,     0,     0,    83,    84,     0,
      85,    86,     0,     0,    87,     0,     0,     0,    42,    43,
      44,    45,    46,    47,    50,     0,     0,     0,    37,    38,
      39,    40,   146,     0,     0,     0,    37,    38,    39,    40,
       0,     0,     0,     0,     0,    42,    43,    44,    45,    46,
      47,    39,    40,    42,    43,    44,    45,    46,    47,    37,
      38,    39,    40,     0,     0,     0,    42,    43,    44,    45,
      46,    47,     0,     0,   128,     0,    42,    43,    44,    45,
      46,    47,     1,     2,     0,     3,     4,     5,     6,     7,
       8,     9,     0,    29,    10,    30,     0,     0,     0,    31,
      11,     0,     0,     0,    32,    33,    34,    35,     5,     6,
       7,     8,     9,     0,     0,    10,     0,     0,     0,     0,
       0,    11
};

static const yytype_int16 yycheck[] =
{
       0,    16,     1,    51,    16,    18,     0,    82,     0,    35,
      10,     1,    16,    13,    12,     8,    10,    43,    44,    13,
      33,    33,     1,    21,    17,    16,    74,    16,   103,    29,
      30,    31,    32,    33,    34,    35,    35,    37,    38,    39,
      40,    20,    21,    22,    23,    35,   108,    12,    48,    49,
      19,    66,    43,    44,    43,    44,    35,    51,    37,    38,
      39,    40,    41,    42,   126,   127,   128,    20,    21,    22,
      23,    71,    15,    88,    15,    75,    76,    77,    78,    79,
      74,    81,     1,    83,    37,    38,    39,    40,    41,    42,
      13,   125,    16,     9,    15,   129,    19,    15,    14,    14,
      30,    20,    21,    22,    23,   139,   106,   107,   108,    33,
       1,    19,   146,    13,     9,    10,    35,    12,    37,    38,
      39,    40,    41,    42,   142,    -1,   126,   127,   128,    20,
      21,    22,    23,    37,    38,    39,    40,    41,    42,    -1,
     140,    43,   142,    -1,    35,    -1,    37,    38,    39,    40,
      41,    42,     3,     4,    -1,     6,     7,     8,     9,    10,
      11,    12,    -1,    -1,    15,    -1,    17,    19,    -1,    -1,
      21,    -1,    24,    25,    26,    27,    -1,    28,    29,    -1,
      31,    32,     3,     4,    35,     6,     7,     8,     9,    10,
      11,    12,     3,     4,    15,     6,     7,    18,    -1,    -1,
      21,    -1,    -1,    -1,    -1,    -1,    -1,    28,    29,    -1,
      31,    32,     3,     4,    35,     6,     7,     8,     9,    10,
      11,    12,    -1,    -1,    15,    14,    -1,    -1,    -1,    -1,
      21,    20,    21,    22,    23,    -1,    -1,    28,    29,    -1,
      31,    32,    -1,    -1,    35,    -1,    -1,    -1,    37,    38,
      39,    40,    41,    42,    16,    -1,    -1,    -1,    20,    21,
      22,    23,    16,    -1,    -1,    -1,    20,    21,    22,    23,
      -1,    -1,    -1,    -1,    -1,    37,    38,    39,    40,    41,
      42,    22,    23,    37,    38,    39,    40,    41,    42,    20,
      21,    22,    23,    -1,    -1,    -1,    37,    38,    39,    40,
      41,    42,    -1,    -1,    35,    -1,    37,    38,    39,    40,
      41,    42,     3,     4,    -1,     6,     7,     8,     9,    10,
      11,    12,    -1,    13,    15,    15,    -1,    -1,    -1,    19,
      21,    -1,    -1,    -1,    24,    25,    26,    27,     8,     9,
      10,    11,    12,    -1,    -1,    15,    -1,    -1,    -1,    -1,
      -1,    21
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     6,     7,     8,     9,    10,    11,    12,
      15,    21,    47,    48,    49,    50,    51,    52,    61,    64,
      51,    61,     9,    10,    12,     0,    49,    21,    52,    13,
      15,    19,    24,    25,    26,    27,     1,    20,    21,    22,
      23,    35,    37,    38,    39,    40,    41,    42,    65,    16,
      16,    15,    61,    61,    62,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    51,    53,    57,    14,
      16,    33,    52,    16,    33,    19,    24,    25,    26,    27,
      61,    19,    17,    28,    29,    31,    32,    35,    51,    54,
      56,    57,    58,    59,    60,    61,    57,    61,    61,    61,
      61,    61,    61,    55,    56,    61,    15,    15,    15,    52,
       1,    35,     1,    35,     1,    35,    18,    56,     1,    35,
      61,    63,    61,    63,    13,    16,    43,    44,    35,    16,
       9,    14,    54,    63,    63,    63,    54,    14,    19,    30,
      35,     8,    17,    54,    61,    62,    16,    18,    54
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 70 "AST_parser.y"
    { root = (yyvsp[(1) - (1)].block); ;}
    break;

  case 3:
#line 72 "AST_parser.y"
    { (yyval.block) = new BlockExprNode(); (yyval.block)->statements->push_back((yyvsp[(1) - (1)].statement)); ;}
    break;

  case 4:
#line 73 "AST_parser.y"
    { (yyval.block)->statements->push_back((yyvsp[(2) - (2)].statement)); ;}
    break;

  case 5:
#line 76 "AST_parser.y"
    { (yyval.statement) = (yyvsp[(1) - (1)].statement); ;}
    break;

  case 6:
#line 77 "AST_parser.y"
    { (yyval.statement) = new ExprStatementNode((yyvsp[(1) - (2)].expr)); ;}
    break;

  case 7:
#line 78 "AST_parser.y"
    { noSemicolonError(); (yyval.statement) = new ExprStatementNode((yyvsp[(1) - (2)].expr)); ;}
    break;

  case 8:
#line 81 "AST_parser.y"
    { (yyval.statement) = new FuncDecStatementNode((yyvsp[(1) - (6)].var), (yyvsp[(2) - (6)].var), (yyvsp[(4) - (6)].vars), (yyvsp[(6) - (6)].block)); ;}
    break;

  case 9:
#line 83 "AST_parser.y"
    { (yyval.var) = new VariableExprNode(*(yyvsp[(1) - (1)].string), E_INT); delete (yyvsp[(1) - (1)].string); ;}
    break;

  case 10:
#line 84 "AST_parser.y"
    { (yyval.var) = new VariableExprNode(*(yyvsp[(1) - (1)].string), E_DOUBLE); delete (yyvsp[(1) - (1)].string); ;}
    break;

  case 11:
#line 85 "AST_parser.y"
    { (yyval.var) = new VariableExprNode(*(yyvsp[(1) - (1)].string), E_CHAR); delete (yyvsp[(1) - (1)].string); ;}
    break;

  case 12:
#line 86 "AST_parser.y"
    { (yyval.var) = new VariableExprNode(*(yyvsp[(1) - (1)].string), E_VOID); delete (yyvsp[(1) - (1)].string); ;}
    break;

  case 13:
#line 89 "AST_parser.y"
    { (yyval.var) = new VariableExprNode(*(yyvsp[(1) - (1)].string)); delete (yyvsp[(1) - (1)].string); ;}
    break;

  case 14:
#line 90 "AST_parser.y"
    { std::string tempstr = "-"; (yyval.var) = new VariableExprNode(tempstr + *(yyvsp[(2) - (2)].string)); delete (yyvsp[(2) - (2)].string); ;}
    break;

  case 15:
#line 93 "AST_parser.y"
    { (yyval.vars) = new vector<VarDecStatementNode*>(); ;}
    break;

  case 16:
#line 94 "AST_parser.y"
    { (yyval.vars) = new vector<VarDecStatementNode*>(); (yyval.vars)->push_back((yyvsp[(1) - (1)].var_dec)); ;}
    break;

  case 17:
#line 95 "AST_parser.y"
    { (yyvsp[(1) - (3)].vars)->push_back((yyvsp[(3) - (3)].var_dec)); (yyval.vars) = (yyvsp[(1) - (3)].vars); ;}
    break;

  case 18:
#line 98 "AST_parser.y"
    { (yyval.block) = (yyvsp[(2) - (3)].block); ;}
    break;

  case 19:
#line 100 "AST_parser.y"
    { (yyval.block) = new BlockExprNode(); ;}
    break;

  case 20:
#line 101 "AST_parser.y"
    { (yyval.block) = new BlockExprNode(); (yyval.block)->statements->push_back((yyvsp[(1) - (1)].statement)); ;}
    break;

  case 21:
#line 102 "AST_parser.y"
    { (yyval.block)->statements->push_back((yyvsp[(2) - (2)].statement)); ;}
    break;

  case 22:
#line 105 "AST_parser.y"
    { (yyval.statement) = (yyvsp[(1) - (2)].var_dec); ;}
    break;

  case 23:
#line 106 "AST_parser.y"
    { (yyval.statement) = (yyvsp[(1) - (2)].statement); ;}
    break;

  case 24:
#line 107 "AST_parser.y"
    { (yyval.statement) = (yyvsp[(1) - (1)].statement); ;}
    break;

  case 25:
#line 108 "AST_parser.y"
    { (yyval.statement) = (yyvsp[(1) - (1)].statement); ;}
    break;

  case 26:
#line 109 "AST_parser.y"
    { (yyval.statement) = new ExprStatementNode((yyvsp[(1) - (2)].expr)); ;}
    break;

  case 27:
#line 110 "AST_parser.y"
    { (yyval.statement) = new ReturnStatementNode((yyvsp[(2) - (3)].expr)); ;}
    break;

  case 28:
#line 111 "AST_parser.y"
    { /* NULL */ ;}
    break;

  case 29:
#line 112 "AST_parser.y"
    { noSemicolonError(); (yyval.statement) = (yyvsp[(1) - (2)].var_dec); ;}
    break;

  case 30:
#line 113 "AST_parser.y"
    { noSemicolonError(); (yyval.statement) = (yyvsp[(1) - (2)].statement); ;}
    break;

  case 31:
#line 114 "AST_parser.y"
    { noSemicolonError(); (yyval.statement) = new ExprStatementNode((yyvsp[(1) - (2)].expr)); ;}
    break;

  case 32:
#line 115 "AST_parser.y"
    { noSemicolonError(); (yyval.statement) = new ReturnStatementNode((yyvsp[(2) - (3)].expr)); ;}
    break;

  case 33:
#line 118 "AST_parser.y"
    { (yyvsp[(2) - (2)].var)->_type = (yyvsp[(1) - (2)].var)->_type; (yyval.var_dec) = new VarDecStatementNode((yyvsp[(1) - (2)].var), (yyvsp[(2) - (2)].var)); addNewVar((yyvsp[(2) - (2)].var)->name, (yyvsp[(2) - (2)].var)->_type); ;}
    break;

  case 34:
#line 119 "AST_parser.y"
    { (yyvsp[(2) - (4)].var)->_type = (yyvsp[(1) - (4)].var)->_type; (yyval.var_dec) = new VarDecStatementNode((yyvsp[(1) - (4)].var), (yyvsp[(2) - (4)].var), (yyvsp[(4) - (4)].expr)); addNewVar((yyvsp[(2) - (4)].var)->name, (yyvsp[(2) - (4)].var)->_type); ;}
    break;

  case 35:
#line 122 "AST_parser.y"
    { (yyval.statement) = new ArrayDecStatementNode((yyvsp[(1) - (5)].var), (yyvsp[(2) - (5)].var), atol((yyvsp[(4) - (5)].string)->c_str())); ;}
    break;

  case 36:
#line 123 "AST_parser.y"
    { (yyval.statement) = new ArrayDecStatementNode((yyvsp[(1) - (8)].var), (yyvsp[(2) - (8)].var), (yyvsp[(7) - (8)].exprs)); ;}
    break;

  case 37:
#line 124 "AST_parser.y"
    { (yyval.statement) = new ArrayDecStatementNode((yyvsp[(1) - (6)].var), (yyvsp[(2) - (6)].var), *(yyvsp[(6) - (6)].string)); ;}
    break;

  case 38:
#line 127 "AST_parser.y"
    { (yyval.statement) = new IfStatementNode((yyvsp[(3) - (5)].expr), (yyvsp[(5) - (5)].block)); ;}
    break;

  case 39:
#line 128 "AST_parser.y"
    { (yyval.statement) = new IfStatementNode((yyvsp[(3) - (7)].expr), (yyvsp[(5) - (7)].block), (yyvsp[(7) - (7)].block)); ;}
    break;

  case 40:
#line 131 "AST_parser.y"
    { (yyval.statement) = new ForStatementNode((yyvsp[(3) - (9)].expr), (yyvsp[(5) - (9)].expr), (yyvsp[(7) - (9)].expr), (yyvsp[(9) - (9)].block)); ;}
    break;

  case 41:
#line 132 "AST_parser.y"
    { (yyval.statement) = new WhileStatementNode((yyvsp[(3) - (5)].expr), (yyvsp[(5) - (5)].block)); ;}
    break;

  case 42:
#line 135 "AST_parser.y"
    { (yyval.var) = (yyvsp[(1) - (1)].var); ;}
    break;

  case 43:
#line 136 "AST_parser.y"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); ;}
    break;

  case 44:
#line 137 "AST_parser.y"
    { (yyval.expr) = new OperatorExprNode((yyvsp[(1) - (3)].expr), (yyvsp[(2) - (3)].symbol), (yyvsp[(3) - (3)].expr)); (yyval.expr)->_type = checkExprType((yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 45:
#line 138 "AST_parser.y"
    { (yyval.expr) = new OperatorExprNode((yyvsp[(1) - (3)].expr), (yyvsp[(2) - (3)].symbol), (yyvsp[(3) - (3)].expr)); (yyval.expr)->_type = checkExprType((yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 46:
#line 139 "AST_parser.y"
    { (yyval.expr) = new OperatorExprNode((yyvsp[(1) - (3)].expr), (yyvsp[(2) - (3)].symbol), (yyvsp[(3) - (3)].expr)); (yyval.expr)->_type = checkExprType((yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 47:
#line 140 "AST_parser.y"
    { (yyval.expr) = new OperatorExprNode((yyvsp[(1) - (3)].expr), (yyvsp[(2) - (3)].symbol), (yyvsp[(3) - (3)].expr)); (yyval.expr)->_type = checkExprType((yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 48:
#line 141 "AST_parser.y"
    { (yyval.expr) = new OperatorExprNode((yyvsp[(1) - (3)].var), (yyvsp[(2) - (3)].symbol), (yyvsp[(3) - (3)].expr)); (yyval.expr) = new AssignExprNode((yyvsp[(1) - (3)].var), (yyval.expr)); setVarType((yyvsp[(1) - (3)].var)); (yyval.expr)->_type = checkExprType((yyvsp[(1) - (3)].var), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 49:
#line 142 "AST_parser.y"
    { (yyval.expr) = new OperatorExprNode((yyvsp[(1) - (3)].var), (yyvsp[(2) - (3)].symbol), (yyvsp[(3) - (3)].expr)); (yyval.expr) = new AssignExprNode((yyvsp[(1) - (3)].var), (yyval.expr)); setVarType((yyvsp[(1) - (3)].var)); (yyval.expr)->_type = checkExprType((yyvsp[(1) - (3)].var), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 50:
#line 143 "AST_parser.y"
    { (yyval.expr) = new OperatorExprNode((yyvsp[(1) - (3)].var), (yyvsp[(2) - (3)].symbol), (yyvsp[(3) - (3)].expr)); (yyval.expr) = new AssignExprNode((yyvsp[(1) - (3)].var), (yyval.expr)); setVarType((yyvsp[(1) - (3)].var)); (yyval.expr)->_type = checkExprType((yyvsp[(1) - (3)].var), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 51:
#line 144 "AST_parser.y"
    { (yyval.expr) = new OperatorExprNode((yyvsp[(1) - (3)].var), (yyvsp[(2) - (3)].symbol), (yyvsp[(3) - (3)].expr)); (yyval.expr) = new AssignExprNode((yyvsp[(1) - (3)].var), (yyval.expr)); setVarType((yyvsp[(1) - (3)].var)); (yyval.expr)->_type = checkExprType((yyvsp[(1) - (3)].var), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 52:
#line 145 "AST_parser.y"
    { (yyval.expr) = new OperatorExprNode((yyvsp[(1) - (3)].expr), (yyvsp[(2) - (3)].symbol), (yyvsp[(3) - (3)].expr)); (yyval.expr)->_type = E_INT; ;}
    break;

  case 53:
#line 146 "AST_parser.y"
    { (yyval.expr) = new AssignExprNode((yyvsp[(1) - (3)].var), (yyvsp[(3) - (3)].expr)); setVarType((yyvsp[(1) - (3)].var)); checkExprType((yyvsp[(1) - (3)].var), (yyvsp[(3) - (3)].expr)); (yyval.expr)->_type = (yyvsp[(1) - (3)].var)->_type; ;}
    break;

  case 54:
#line 147 "AST_parser.y"
    { (yyval.expr) = new FuncExprNode((yyvsp[(1) - (4)].var), (yyvsp[(3) - (4)].exprs)); addNewVar((yyvsp[(1) - (4)].var)->name, E_FUNC); setVarType((yyvsp[(1) - (4)].var)); (yyval.expr)->_type =(yyvsp[(1) - (4)].var)->_type; ;}
    break;

  case 55:
#line 148 "AST_parser.y"
    { (yyval.expr) = new IndexExprNode((yyvsp[(1) - (4)].var), (yyvsp[(3) - (4)].expr)); (yyval.expr)->_type = (yyvsp[(1) - (4)].var)->_type; ;}
    break;

  case 56:
#line 149 "AST_parser.y"
    { (yyval.expr) = new IndexExprNode((yyvsp[(1) - (6)].var), (yyvsp[(3) - (6)].expr)); checkExprType((yyvsp[(1) - (6)].var), (yyvsp[(6) - (6)].expr)); (yyval.expr)->_type = (yyvsp[(1) - (6)].var)->_type; ;}
    break;

  case 57:
#line 150 "AST_parser.y"
    { (yyval.expr) = new IndexExprNode((yyvsp[(1) - (6)].var), (yyvsp[(3) - (6)].expr)); (yyval.expr) = new OperatorExprNode((yyval.expr), (yyvsp[(5) - (6)].symbol), (yyvsp[(6) - (6)].expr)); (yyval.expr) = new IndexExprNode((yyvsp[(1) - (6)].var), (yyvsp[(3) - (6)].expr), (yyval.expr)); checkExprType((yyvsp[(1) - (6)].var), (yyvsp[(6) - (6)].expr)); (yyval.expr)->_type = (yyvsp[(1) - (6)].var)->_type; ;}
    break;

  case 58:
#line 151 "AST_parser.y"
    { (yyval.expr) = new IndexExprNode((yyvsp[(1) - (6)].var), (yyvsp[(3) - (6)].expr)); (yyval.expr) = new OperatorExprNode((yyval.expr), (yyvsp[(5) - (6)].symbol), (yyvsp[(6) - (6)].expr)); (yyval.expr) = new IndexExprNode((yyvsp[(1) - (6)].var), (yyvsp[(3) - (6)].expr), (yyval.expr)); checkExprType((yyvsp[(1) - (6)].var), (yyvsp[(6) - (6)].expr)); (yyval.expr)->_type = (yyvsp[(1) - (6)].var)->_type; ;}
    break;

  case 59:
#line 152 "AST_parser.y"
    { (yyval.expr) = new IndexExprNode((yyvsp[(1) - (6)].var), (yyvsp[(3) - (6)].expr)); (yyval.expr) = new OperatorExprNode((yyval.expr), (yyvsp[(5) - (6)].symbol), (yyvsp[(6) - (6)].expr)); (yyval.expr) = new IndexExprNode((yyvsp[(1) - (6)].var), (yyvsp[(3) - (6)].expr), (yyval.expr)); checkExprType((yyvsp[(1) - (6)].var), (yyvsp[(6) - (6)].expr)); (yyval.expr)->_type = (yyvsp[(1) - (6)].var)->_type; ;}
    break;

  case 60:
#line 153 "AST_parser.y"
    { (yyval.expr) = new IndexExprNode((yyvsp[(1) - (6)].var), (yyvsp[(3) - (6)].expr)); (yyval.expr) = new OperatorExprNode((yyval.expr), (yyvsp[(5) - (6)].symbol), (yyvsp[(6) - (6)].expr)); (yyval.expr) = new IndexExprNode((yyvsp[(1) - (6)].var), (yyvsp[(3) - (6)].expr), (yyval.expr)); checkExprType((yyvsp[(1) - (6)].var), (yyvsp[(6) - (6)].expr)); (yyval.expr)->_type = (yyvsp[(1) - (6)].var)->_type; ;}
    break;

  case 61:
#line 154 "AST_parser.y"
    { (yyval.expr) = (yyvsp[(2) - (3)].expr); ;}
    break;

  case 62:
#line 155 "AST_parser.y"
    { (yyval.expr) = new CastExprNode((yyvsp[(2) - (4)].var), (yyvsp[(4) - (4)].expr)); (yyval.expr)->_type = (yyvsp[(2) - (4)].var)->_type; ;}
    break;

  case 63:
#line 158 "AST_parser.y"
    { (yyval.exprs) = new vector<ExprNode*>(); ;}
    break;

  case 64:
#line 159 "AST_parser.y"
    { (yyval.exprs) = new vector<ExprNode*>(); (yyval.exprs)->push_back((yyvsp[(1) - (1)].expr)); ;}
    break;

  case 65:
#line 160 "AST_parser.y"
    { (yyvsp[(1) - (3)].exprs)->push_back((yyvsp[(3) - (3)].expr)); (yyval.exprs) = (yyvsp[(1) - (3)].exprs); ;}
    break;

  case 66:
#line 163 "AST_parser.y"
    { (yyval.expr) = new OperatorExprNode((yyvsp[(1) - (3)].expr), (yyvsp[(2) - (3)].symbol), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 67:
#line 164 "AST_parser.y"
    { (yyval.expr) = new OperatorExprNode((yyvsp[(1) - (3)].expr), (yyvsp[(2) - (3)].symbol), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 68:
#line 165 "AST_parser.y"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr);;}
    break;

  case 69:
#line 168 "AST_parser.y"
    { (yyval.block) = (yyvsp[(2) - (3)].block); ;}
    break;

  case 70:
#line 169 "AST_parser.y"
    { (yyval.block) = new BlockExprNode(); (yyval.block)->statements->push_back((yyvsp[(1) - (1)].statement)); ;}
    break;

  case 71:
#line 172 "AST_parser.y"
    { (yyval.expr) = new IntExprNode(atoi((yyvsp[(1) - (1)].string)->c_str())); delete (yyvsp[(1) - (1)].string); ;}
    break;

  case 72:
#line 173 "AST_parser.y"
    { (yyval.expr) = new DoubleExprNode(atoi((yyvsp[(1) - (1)].string)->c_str())); delete (yyvsp[(1) - (1)].string); ;}
    break;

  case 73:
#line 174 "AST_parser.y"
    { (yyval.expr) = new CharExprNode((yyvsp[(1) - (1)].string)->front()); delete (yyvsp[(1) - (1)].string); ;}
    break;

  case 74:
#line 175 "AST_parser.y"
    { (yyval.expr) = new StringExprNode(*(yyvsp[(1) - (1)].string)); delete (yyvsp[(1) - (1)].string); ;}
    break;

  case 75:
#line 176 "AST_parser.y"
    { (yyval.expr) = new IntExprNode(-atoi((yyvsp[(2) - (2)].string)->c_str())); delete (yyvsp[(2) - (2)].string); ;}
    break;

  case 76:
#line 177 "AST_parser.y"
    { (yyval.expr) = new IntExprNode(-atoi((yyvsp[(2) - (2)].string)->c_str())); delete (yyvsp[(2) - (2)].string); ;}
    break;

  case 77:
#line 180 "AST_parser.y"
    { (yyval.symbol) = (yyvsp[(1) - (1)].symbol); ;}
    break;

  case 78:
#line 181 "AST_parser.y"
    { (yyval.symbol) = (yyvsp[(1) - (1)].symbol); ;}
    break;

  case 79:
#line 182 "AST_parser.y"
    { (yyval.symbol) = (yyvsp[(1) - (1)].symbol); ;}
    break;

  case 80:
#line 183 "AST_parser.y"
    { (yyval.symbol) = (yyvsp[(1) - (1)].symbol); ;}
    break;

  case 81:
#line 184 "AST_parser.y"
    { (yyval.symbol) = (yyvsp[(1) - (1)].symbol); ;}
    break;

  case 82:
#line 185 "AST_parser.y"
    { (yyval.symbol) = (yyvsp[(1) - (1)].symbol); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 2010 "AST_parser.cpp"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 188 "AST_parser.y"


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
  if (left ->_type == E_UNKNOWN) {
    cout << "line" << lineNum << "left has unknown type" << endl;
    return E_UNKNOWN;
  }
  if (right ->_type == E_UNKNOWN) {
    cout << "line" << lineNum << "right has unknown type" << endl;
    return E_UNKNOWN;
  }


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

void noSemicolonError() {
  cout << "line" << lineNum << ": missed Semicolon." << endl;
}


int yyerror(char *msg)
{
	cout << "line" << lineNum << ": 有无法匹配的内容" << endl;
	return 1;	
}
