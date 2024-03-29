/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "AST_parser.y" /* yacc.c:339  */

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
  map<string, E_TYPE> variableTable;

  void setVariableType(VariableExprNode *);
  void definitionVar(string name, E_TYPE type);
  E_TYPE checkVariableType(ExprNode *left, ExprNode *right);
  void noSemicolonError();

#line 89 "AST_parser.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "AST_parser.hpp".  */
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
#line 24 "AST_parser.y" /* yacc.c:355  */

  int symbol;
  string *str;
  VariableExprNode *var;
  ExprNode *expr;
  vector<VarDecStatementNode*> *vars;
  vector<ExprNode*> *exprs;
  BlockExprNode *block;
  StatementNode *statement;
  VarDecStatementNode *var_dec;

#line 189 "AST_parser.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_AST_PARSER_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 206 "AST_parser.cpp" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  25
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   373

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  84
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  154

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   302

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
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
      45,    46,    47
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    70,    70,    72,    73,    76,    77,    78,    81,    83,
      84,    85,    86,    89,    90,    93,    94,    95,    98,    99,
     102,   103,   104,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   123,   124,   127,
     128,   129,   132,   133,   136,   137,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   163,   164,   165,
     168,   169,   170,   173,   174,   175,   176,   177,   178,   181,
     182,   183,   184,   185,   186
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "DOUBLE", "FLOAT", "CHAR", "VOID",
  "CSTR", "CINT", "CDOUBLE", "CCHAR", "VAR", "LBRACK", "RBRACK", "LPAREN",
  "RPAREN", "LBRACE", "RBRACE", "EQUAL", "ADD", "SUB", "MUL", "DIV",
  "SADD", "SSUB", "SMUL", "SDIV", "RETURN", "BREAK", "CONTINUE", "IF",
  "ELSE", "FOR", "WHILE", "COMMA", "COLON", "SEMICOLON", "QUATATION", "EQ",
  "NE", "GR", "GE", "LW", "LE", "AND", "OR", "LowerThanElse", "$accept",
  "program", "globalBlock", "globalStatement", "functionDeclaration",
  "type", "variable", "functionArgs", "block", "localBlock",
  "localStatement", "variableDeclaration", "arrayDeclaration", "condition",
  "loop", "expr", "invokeArgs", "logicExpr", "const", "compare", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302
};
# endif

#define YYPACT_NINF -81

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-81)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     331,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,
     331,   190,     7,   331,   -81,   -81,    15,   332,    22,   -81,
     -12,   250,   -81,   -81,   -81,   -81,   -81,     2,    41,   352,
     352,   352,   352,   352,   352,   352,   -81,   352,   352,   352,
     352,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   352,   352,
     -81,   187,   211,   289,   -15,   289,    51,    51,   128,   128,
      51,    51,   128,   128,   289,   289,    15,    -7,   -81,   103,
     -81,   352,    -4,   145,   187,   352,   352,   352,   352,   352,
     289,   352,   209,   248,   -20,    23,    53,    55,    57,   -81,
      15,   -81,   -81,     4,    10,   -81,   -81,    66,   -81,   289,
      51,    51,   128,   128,   289,   177,   -81,   -81,    97,   -81,
     -81,   352,   352,   352,    -1,   -81,   -81,   -81,   -81,   -81,
     -81,   -81,   -81,   -81,   -81,   289,     5,   283,     8,    87,
     145,   352,   352,   352,   145,    70,     3,    65,   -81,    40,
     113,   -81,   -81,    38,   145,   352,   -81,   352,   -81,   258,
      34,   145,   -81,   -81
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     9,    10,    11,    12,    76,    73,    74,    75,    13,
       0,     0,     0,     2,     3,     5,     0,    46,     0,    47,
       0,     0,    77,    78,    14,     1,     4,     0,     0,     0,
      67,     0,     0,     0,     0,     0,     7,     0,     0,     0,
       0,     6,    79,    80,    81,    82,    83,    84,     0,     0,
      65,    15,     0,    68,     0,    57,    52,    53,    54,    55,
      48,    49,    50,    51,    56,    66,     0,     0,    16,    59,
      58,     0,    37,     0,     0,     0,     0,     0,     0,     0,
      69,     0,    20,     0,     0,     0,     0,     0,     0,    32,
       0,     8,    19,     0,     0,    25,    26,     0,    17,    60,
      61,    62,    63,    64,    38,     0,    21,    29,     0,    30,
      31,     0,     0,     0,    37,    33,    23,    34,    24,    35,
      27,    18,    22,    36,    28,    72,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    42,    71,    70,
       0,    45,    39,     0,     0,     0,    41,    67,    43,     0,
       0,     0,    40,    44
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -81,   -81,   -81,    86,   -81,     6,    -8,   -81,   -30,   -81,
     -80,   -48,   -81,   -81,   -81,     0,   -45,    11,   -81,   -81
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    12,    13,    14,    15,    90,    17,    67,    91,   105,
      92,    93,    94,    95,    96,    97,    54,   126,    19,    48
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      18,    70,   106,    68,    49,   115,    16,    25,    28,    73,
      21,   117,   129,    18,    24,    81,    20,   109,    81,    16,
      71,   130,   143,    36,   134,   122,    98,     9,    74,    52,
      53,    55,    56,    57,    58,    59,    27,    60,    61,    62,
      63,   116,    37,    38,    39,    40,   146,   118,    64,    65,
     131,   132,   152,   131,   132,   147,    51,    66,    72,    41,
     110,    42,    43,    44,    45,    46,    47,   119,   111,    71,
     112,    80,   113,    39,    40,    99,   100,   101,   102,   103,
      66,   104,   114,   108,   142,   131,    37,    38,    39,    40,
      42,    43,    44,    45,    46,    47,   135,   144,   123,    26,
     137,   136,   150,   120,   141,    42,    43,    44,    45,    46,
      47,   125,   127,   125,   148,     0,     0,    37,    38,    39,
      40,   153,    75,     0,   128,     0,     0,    76,    77,    78,
      79,   125,   125,   125,   124,     0,    42,    43,    44,    45,
      46,    47,   138,   139,   140,   149,     0,    53,     1,     2,
     145,     3,     4,     5,     6,     7,     8,     9,   131,   132,
      10,     0,    82,     0,     0,     0,    11,    42,    43,    44,
      45,    46,    47,    83,    84,    85,    86,     0,    87,    88,
       1,     2,    89,     3,     4,     5,     6,     7,     8,     9,
       1,     2,    10,     3,     4,   121,     0,     0,    11,    22,
      23,     0,    24,     0,     0,    83,    84,    85,    86,     0,
      87,    88,     1,     2,    89,     3,     4,     5,     6,     7,
       8,     9,     0,     0,    10,    69,     0,     0,     0,     0,
      11,    37,    38,    39,    40,     0,     0,    83,    84,    85,
      86,     0,    87,    88,     0,     0,    89,     0,     0,     0,
      42,    43,    44,    45,    46,    47,     5,     6,     7,     8,
       9,     0,     0,    10,     0,     0,    50,     0,     0,    11,
      37,    38,    39,    40,   151,     0,     0,     0,    37,    38,
      39,    40,     0,     0,     0,   107,     0,     0,     0,    42,
      43,    44,    45,    46,    47,     0,     0,    42,    43,    44,
      45,    46,    47,    37,    38,    39,    40,     0,     0,    37,
      38,    39,    40,     0,     0,     0,     0,     0,     0,     0,
     133,     0,    42,    43,    44,    45,    46,    47,    42,    43,
      44,    45,    46,    47,     1,     2,     0,     3,     4,     5,
       6,     7,     8,     9,     0,    29,    10,    30,     0,     0,
       0,    31,    11,     0,     0,     0,    32,    33,    34,    35,
       5,     6,     7,     8,     9,     0,     0,    10,     0,     0,
       0,     0,     0,    11
};

static const yytype_int16 yycheck[] =
{
       0,    16,    82,    51,    16,     1,     0,     0,    16,    16,
      10,     1,    13,    13,    12,    19,    10,    37,    19,    13,
      35,    16,    19,     1,    16,   105,    74,    12,    35,    29,
      30,    31,    32,    33,    34,    35,    21,    37,    38,    39,
      40,    37,    20,    21,    22,    23,     8,    37,    48,    49,
      45,    46,    18,    45,    46,    17,    15,    51,    66,    37,
      37,    39,    40,    41,    42,    43,    44,     1,    15,    35,
      15,    71,    15,    22,    23,    75,    76,    77,    78,    79,
      74,    81,    90,    83,    14,    45,    20,    21,    22,    23,
      39,    40,    41,    42,    43,    44,     9,    32,     1,    13,
     130,    14,   147,    37,   134,    39,    40,    41,    42,    43,
      44,   111,   112,   113,   144,    -1,    -1,    20,    21,    22,
      23,   151,    19,    -1,   113,    -1,    -1,    24,    25,    26,
      27,   131,   132,   133,    37,    -1,    39,    40,    41,    42,
      43,    44,   131,   132,   133,   145,    -1,   147,     3,     4,
      37,     6,     7,     8,     9,    10,    11,    12,    45,    46,
      15,    -1,    17,    -1,    -1,    -1,    21,    39,    40,    41,
      42,    43,    44,    28,    29,    30,    31,    -1,    33,    34,
       3,     4,    37,     6,     7,     8,     9,    10,    11,    12,
       3,     4,    15,     6,     7,    18,    -1,    -1,    21,     9,
      10,    -1,    12,    -1,    -1,    28,    29,    30,    31,    -1,
      33,    34,     3,     4,    37,     6,     7,     8,     9,    10,
      11,    12,    -1,    -1,    15,    14,    -1,    -1,    -1,    -1,
      21,    20,    21,    22,    23,    -1,    -1,    28,    29,    30,
      31,    -1,    33,    34,    -1,    -1,    37,    -1,    -1,    -1,
      39,    40,    41,    42,    43,    44,     8,     9,    10,    11,
      12,    -1,    -1,    15,    -1,    -1,    16,    -1,    -1,    21,
      20,    21,    22,    23,    16,    -1,    -1,    -1,    20,    21,
      22,    23,    -1,    -1,    -1,    37,    -1,    -1,    -1,    39,
      40,    41,    42,    43,    44,    -1,    -1,    39,    40,    41,
      42,    43,    44,    20,    21,    22,    23,    -1,    -1,    20,
      21,    22,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      37,    -1,    39,    40,    41,    42,    43,    44,    39,    40,
      41,    42,    43,    44,     3,     4,    -1,     6,     7,     8,
       9,    10,    11,    12,    -1,    13,    15,    15,    -1,    -1,
      -1,    19,    21,    -1,    -1,    -1,    24,    25,    26,    27,
       8,     9,    10,    11,    12,    -1,    -1,    15,    -1,    -1,
      -1,    -1,    -1,    21
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     6,     7,     8,     9,    10,    11,    12,
      15,    21,    49,    50,    51,    52,    53,    54,    63,    66,
      53,    63,     9,    10,    12,     0,    51,    21,    54,    13,
      15,    19,    24,    25,    26,    27,     1,    20,    21,    22,
      23,    37,    39,    40,    41,    42,    43,    44,    67,    16,
      16,    15,    63,    63,    64,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    53,    55,    59,    14,
      16,    35,    54,    16,    35,    19,    24,    25,    26,    27,
      63,    19,    17,    28,    29,    30,    31,    33,    34,    37,
      53,    56,    58,    59,    60,    61,    62,    63,    59,    63,
      63,    63,    63,    63,    63,    57,    58,    37,    63,    37,
      37,    15,    15,    15,    54,     1,    37,     1,    37,     1,
      37,    18,    58,     1,    37,    63,    65,    63,    65,    13,
      16,    45,    46,    37,    16,     9,    14,    56,    65,    65,
      65,    56,    14,    19,    32,    37,     8,    17,    56,    63,
      64,    16,    18,    56
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    48,    49,    50,    50,    51,    51,    51,    52,    53,
      53,    53,    53,    54,    54,    55,    55,    55,    56,    56,
      57,    57,    57,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    59,    59,    60,
      60,    60,    61,    61,    62,    62,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    63,    64,    64,    64,
      65,    65,    65,    66,    66,    66,    66,    66,    66,    67,
      67,    67,    67,    67,    67
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     2,     2,     6,     1,
       1,     1,     1,     1,     2,     0,     1,     3,     3,     1,
       0,     1,     2,     2,     2,     1,     1,     2,     3,     2,
       2,     2,     1,     2,     2,     2,     3,     2,     4,     5,
       8,     6,     5,     7,     9,     5,     1,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     4,     4,
       6,     6,     6,     6,     6,     3,     4,     0,     1,     3,
       3,     3,     1,     1,     1,     1,     1,     2,     2,     1,
       1,     1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
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

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
     '$$ = $1'.

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
#line 70 "AST_parser.y" /* yacc.c:1646  */
    { root = (yyvsp[0].block); }
#line 1433 "AST_parser.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 72 "AST_parser.y" /* yacc.c:1646  */
    { (yyval.block) = new BlockExprNode(); (yyval.block)->statements->push_back((yyvsp[0].statement)); }
#line 1439 "AST_parser.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 73 "AST_parser.y" /* yacc.c:1646  */
    { (yyval.block)->statements->push_back((yyvsp[0].statement)); }
#line 1445 "AST_parser.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 76 "AST_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[0].statement); }
#line 1451 "AST_parser.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 77 "AST_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new ExprStatementNode((yyvsp[-1].expr)); }
#line 1457 "AST_parser.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 78 "AST_parser.y" /* yacc.c:1646  */
    { noSemicolonError(); (yyval.statement) = new ExprStatementNode((yyvsp[-1].expr)); }
#line 1463 "AST_parser.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 81 "AST_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new FuncStatementNode((yyvsp[-5].var), (yyvsp[-4].var), (yyvsp[-2].vars), (yyvsp[0].block)); }
#line 1469 "AST_parser.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 83 "AST_parser.y" /* yacc.c:1646  */
    { (yyval.var) = new VariableExprNode(*(yyvsp[0].str), E_INT); delete (yyvsp[0].str); }
#line 1475 "AST_parser.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 84 "AST_parser.y" /* yacc.c:1646  */
    { (yyval.var) = new VariableExprNode(*(yyvsp[0].str), E_DOUBLE); delete (yyvsp[0].str); }
#line 1481 "AST_parser.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 85 "AST_parser.y" /* yacc.c:1646  */
    { (yyval.var) = new VariableExprNode(*(yyvsp[0].str), E_CHAR); delete (yyvsp[0].str); }
#line 1487 "AST_parser.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 86 "AST_parser.y" /* yacc.c:1646  */
    { (yyval.var) = new VariableExprNode(*(yyvsp[0].str), E_VOID); delete (yyvsp[0].str); }
#line 1493 "AST_parser.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 89 "AST_parser.y" /* yacc.c:1646  */
    { (yyval.var) = new VariableExprNode(*(yyvsp[0].str)); delete (yyvsp[0].str); }
#line 1499 "AST_parser.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 90 "AST_parser.y" /* yacc.c:1646  */
    { std::string tempstr = "-"; (yyval.var) = new VariableExprNode(tempstr + *(yyvsp[0].str)); delete (yyvsp[0].str); }
#line 1505 "AST_parser.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 93 "AST_parser.y" /* yacc.c:1646  */
    { (yyval.vars) = new vector<VarDecStatementNode*>(); }
#line 1511 "AST_parser.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 94 "AST_parser.y" /* yacc.c:1646  */
    { (yyval.vars) = new vector<VarDecStatementNode*>(); (yyval.vars)->push_back((yyvsp[0].var_dec)); }
#line 1517 "AST_parser.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 95 "AST_parser.y" /* yacc.c:1646  */
    { (yyvsp[-2].vars)->push_back((yyvsp[0].var_dec)); (yyval.vars) = (yyvsp[-2].vars); }
#line 1523 "AST_parser.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 98 "AST_parser.y" /* yacc.c:1646  */
    { (yyval.block) = (yyvsp[-1].block); }
#line 1529 "AST_parser.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 99 "AST_parser.y" /* yacc.c:1646  */
    { (yyval.block) = new BlockExprNode(); (yyval.block)->statements->push_back((yyvsp[0].statement)); }
#line 1535 "AST_parser.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 102 "AST_parser.y" /* yacc.c:1646  */
    { (yyval.block) = new BlockExprNode(); }
#line 1541 "AST_parser.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 103 "AST_parser.y" /* yacc.c:1646  */
    { (yyval.block) = new BlockExprNode(); (yyval.block)->statements->push_back((yyvsp[0].statement)); }
#line 1547 "AST_parser.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 104 "AST_parser.y" /* yacc.c:1646  */
    { (yyval.block)->statements->push_back((yyvsp[0].statement)); }
#line 1553 "AST_parser.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 107 "AST_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[-1].var_dec); }
#line 1559 "AST_parser.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 108 "AST_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[-1].statement); }
#line 1565 "AST_parser.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 109 "AST_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[0].statement); }
#line 1571 "AST_parser.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 110 "AST_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[0].statement); }
#line 1577 "AST_parser.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 111 "AST_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new ExprStatementNode((yyvsp[-1].expr)); }
#line 1583 "AST_parser.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 112 "AST_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new ReturnStatementNode((yyvsp[-1].expr)); }
#line 1589 "AST_parser.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 113 "AST_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new ReturnStatementNode(); }
#line 1595 "AST_parser.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 114 "AST_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new BreakStatementNode(); }
#line 1601 "AST_parser.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 115 "AST_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new ContinueStatementNode(); }
#line 1607 "AST_parser.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 116 "AST_parser.y" /* yacc.c:1646  */
    { /* NULL */ }
#line 1613 "AST_parser.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 117 "AST_parser.y" /* yacc.c:1646  */
    { noSemicolonError(); (yyval.statement) = (yyvsp[-1].var_dec); }
#line 1619 "AST_parser.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 118 "AST_parser.y" /* yacc.c:1646  */
    { noSemicolonError(); (yyval.statement) = (yyvsp[-1].statement); }
#line 1625 "AST_parser.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 119 "AST_parser.y" /* yacc.c:1646  */
    { noSemicolonError(); (yyval.statement) = new ExprStatementNode((yyvsp[-1].expr)); }
#line 1631 "AST_parser.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 120 "AST_parser.y" /* yacc.c:1646  */
    { noSemicolonError(); (yyval.statement) = new ReturnStatementNode((yyvsp[-1].expr)); }
#line 1637 "AST_parser.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 123 "AST_parser.y" /* yacc.c:1646  */
    { (yyvsp[0].var)->_type = (yyvsp[-1].var)->_type; (yyval.var_dec) = new VarDecStatementNode((yyvsp[-1].var), (yyvsp[0].var)); definitionVar((yyvsp[0].var)->name, (yyvsp[0].var)->_type); }
#line 1643 "AST_parser.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 124 "AST_parser.y" /* yacc.c:1646  */
    { (yyvsp[-2].var)->_type = (yyvsp[-3].var)->_type; (yyval.var_dec) = new VarDecStatementNode((yyvsp[-3].var), (yyvsp[-2].var), (yyvsp[0].expr)); definitionVar((yyvsp[-2].var)->name, (yyvsp[-2].var)->_type); }
#line 1649 "AST_parser.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 127 "AST_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new ArrayDecStatementNode((yyvsp[-4].var), (yyvsp[-3].var), atol((yyvsp[-1].str)->c_str())); }
#line 1655 "AST_parser.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 128 "AST_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new ArrayDecStatementNode((yyvsp[-7].var), (yyvsp[-6].var), (yyvsp[-1].exprs)); }
#line 1661 "AST_parser.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 129 "AST_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new ArrayDecStatementNode((yyvsp[-5].var), (yyvsp[-4].var), *(yyvsp[0].str)); }
#line 1667 "AST_parser.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 132 "AST_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new IfStatementNode((yyvsp[-2].expr), (yyvsp[0].block)); }
#line 1673 "AST_parser.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 133 "AST_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new IfStatementNode((yyvsp[-4].expr), (yyvsp[-2].block), (yyvsp[0].block)); }
#line 1679 "AST_parser.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 136 "AST_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new ForStatementNode((yyvsp[-6].expr), (yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].block)); }
#line 1685 "AST_parser.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 137 "AST_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new WhileStatementNode((yyvsp[-2].expr), (yyvsp[0].block)); }
#line 1691 "AST_parser.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 140 "AST_parser.y" /* yacc.c:1646  */
    { (yyval.var) = (yyvsp[0].var); }
#line 1697 "AST_parser.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 141 "AST_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1703 "AST_parser.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 142 "AST_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new OperatorExprNode((yyvsp[-2].expr), (yyvsp[-1].symbol), (yyvsp[0].expr)); (yyval.expr)->_type = checkVariableType((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1709 "AST_parser.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 143 "AST_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new OperatorExprNode((yyvsp[-2].expr), (yyvsp[-1].symbol), (yyvsp[0].expr)); (yyval.expr)->_type = checkVariableType((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1715 "AST_parser.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 144 "AST_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new OperatorExprNode((yyvsp[-2].expr), (yyvsp[-1].symbol), (yyvsp[0].expr)); (yyval.expr)->_type = checkVariableType((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1721 "AST_parser.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 145 "AST_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new OperatorExprNode((yyvsp[-2].expr), (yyvsp[-1].symbol), (yyvsp[0].expr)); (yyval.expr)->_type = checkVariableType((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1727 "AST_parser.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 146 "AST_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new OperatorExprNode((yyvsp[-2].var), (yyvsp[-1].symbol), (yyvsp[0].expr)); (yyval.expr) = new AssignExprNode((yyvsp[-2].var), (yyval.expr)); setVariableType((yyvsp[-2].var)); (yyval.expr)->_type = checkVariableType((yyvsp[-2].var), (yyvsp[0].expr)); }
#line 1733 "AST_parser.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 147 "AST_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new OperatorExprNode((yyvsp[-2].var), (yyvsp[-1].symbol), (yyvsp[0].expr)); (yyval.expr) = new AssignExprNode((yyvsp[-2].var), (yyval.expr)); setVariableType((yyvsp[-2].var)); (yyval.expr)->_type = checkVariableType((yyvsp[-2].var), (yyvsp[0].expr)); }
#line 1739 "AST_parser.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 148 "AST_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new OperatorExprNode((yyvsp[-2].var), (yyvsp[-1].symbol), (yyvsp[0].expr)); (yyval.expr) = new AssignExprNode((yyvsp[-2].var), (yyval.expr)); setVariableType((yyvsp[-2].var)); (yyval.expr)->_type = checkVariableType((yyvsp[-2].var), (yyvsp[0].expr)); }
#line 1745 "AST_parser.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 149 "AST_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new OperatorExprNode((yyvsp[-2].var), (yyvsp[-1].symbol), (yyvsp[0].expr)); (yyval.expr) = new AssignExprNode((yyvsp[-2].var), (yyval.expr)); setVariableType((yyvsp[-2].var)); (yyval.expr)->_type = checkVariableType((yyvsp[-2].var), (yyvsp[0].expr)); }
#line 1751 "AST_parser.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 150 "AST_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new OperatorExprNode((yyvsp[-2].expr), (yyvsp[-1].symbol), (yyvsp[0].expr)); (yyval.expr)->_type = E_INT; }
#line 1757 "AST_parser.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 151 "AST_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new AssignExprNode((yyvsp[-2].var), (yyvsp[0].expr)); setVariableType((yyvsp[-2].var)); checkVariableType((yyvsp[-2].var), (yyvsp[0].expr)); (yyval.expr)->_type = (yyvsp[-2].var)->_type; }
#line 1763 "AST_parser.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 152 "AST_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new FuncExprNode((yyvsp[-3].var), (yyvsp[-1].exprs)); definitionVar((yyvsp[-3].var)->name, E_FUNC); setVariableType((yyvsp[-3].var)); (yyval.expr)->_type =(yyvsp[-3].var)->_type; }
#line 1769 "AST_parser.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 153 "AST_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new IndexExprNode((yyvsp[-3].var), (yyvsp[-1].expr)); (yyval.expr)->_type = (yyvsp[-3].var)->_type; }
#line 1775 "AST_parser.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 154 "AST_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new IndexExprNode((yyvsp[-5].var), (yyvsp[-3].expr), (yyvsp[0].expr)); checkVariableType((yyvsp[-5].var), (yyvsp[0].expr)); (yyval.expr)->_type = (yyvsp[-5].var)->_type; }
#line 1781 "AST_parser.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 155 "AST_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new IndexExprNode((yyvsp[-5].var), (yyvsp[-3].expr)); (yyval.expr) = new OperatorExprNode((yyval.expr), (yyvsp[-1].symbol), (yyvsp[0].expr)); (yyval.expr) = new IndexExprNode((yyvsp[-5].var), (yyvsp[-3].expr), (yyval.expr)); checkVariableType((yyvsp[-5].var), (yyvsp[0].expr)); (yyval.expr)->_type = (yyvsp[-5].var)->_type; }
#line 1787 "AST_parser.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 156 "AST_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new IndexExprNode((yyvsp[-5].var), (yyvsp[-3].expr)); (yyval.expr) = new OperatorExprNode((yyval.expr), (yyvsp[-1].symbol), (yyvsp[0].expr)); (yyval.expr) = new IndexExprNode((yyvsp[-5].var), (yyvsp[-3].expr), (yyval.expr)); checkVariableType((yyvsp[-5].var), (yyvsp[0].expr)); (yyval.expr)->_type = (yyvsp[-5].var)->_type; }
#line 1793 "AST_parser.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 157 "AST_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new IndexExprNode((yyvsp[-5].var), (yyvsp[-3].expr)); (yyval.expr) = new OperatorExprNode((yyval.expr), (yyvsp[-1].symbol), (yyvsp[0].expr)); (yyval.expr) = new IndexExprNode((yyvsp[-5].var), (yyvsp[-3].expr), (yyval.expr)); checkVariableType((yyvsp[-5].var), (yyvsp[0].expr)); (yyval.expr)->_type = (yyvsp[-5].var)->_type; }
#line 1799 "AST_parser.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 158 "AST_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new IndexExprNode((yyvsp[-5].var), (yyvsp[-3].expr)); (yyval.expr) = new OperatorExprNode((yyval.expr), (yyvsp[-1].symbol), (yyvsp[0].expr)); (yyval.expr) = new IndexExprNode((yyvsp[-5].var), (yyvsp[-3].expr), (yyval.expr)); checkVariableType((yyvsp[-5].var), (yyvsp[0].expr)); (yyval.expr)->_type = (yyvsp[-5].var)->_type; }
#line 1805 "AST_parser.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 159 "AST_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[-1].expr); }
#line 1811 "AST_parser.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 160 "AST_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new CastExprNode((yyvsp[-2].var), (yyvsp[0].expr)); (yyval.expr)->_type = (yyvsp[-2].var)->_type; }
#line 1817 "AST_parser.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 163 "AST_parser.y" /* yacc.c:1646  */
    { (yyval.exprs) = new vector<ExprNode*>(); }
#line 1823 "AST_parser.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 164 "AST_parser.y" /* yacc.c:1646  */
    { (yyval.exprs) = new vector<ExprNode*>(); (yyval.exprs)->push_back((yyvsp[0].expr)); }
#line 1829 "AST_parser.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 165 "AST_parser.y" /* yacc.c:1646  */
    { (yyvsp[-2].exprs)->push_back((yyvsp[0].expr)); (yyval.exprs) = (yyvsp[-2].exprs); }
#line 1835 "AST_parser.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 168 "AST_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new OperatorExprNode((yyvsp[-2].expr), (yyvsp[-1].symbol), (yyvsp[0].expr)); }
#line 1841 "AST_parser.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 169 "AST_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new OperatorExprNode((yyvsp[-2].expr), (yyvsp[-1].symbol), (yyvsp[0].expr)); }
#line 1847 "AST_parser.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 170 "AST_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);}
#line 1853 "AST_parser.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 173 "AST_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new IntExprNode(atoi((yyvsp[0].str)->c_str())); delete (yyvsp[0].str); }
#line 1859 "AST_parser.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 174 "AST_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new DoubleExprNode(atoi((yyvsp[0].str)->c_str())); delete (yyvsp[0].str); }
#line 1865 "AST_parser.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 175 "AST_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new CharExprNode((yyvsp[0].str)->front()); delete (yyvsp[0].str); }
#line 1871 "AST_parser.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 176 "AST_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new StringExprNode(*(yyvsp[0].str)); delete (yyvsp[0].str); }
#line 1877 "AST_parser.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 177 "AST_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new IntExprNode(-atoi((yyvsp[0].str)->c_str())); delete (yyvsp[0].str); }
#line 1883 "AST_parser.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 178 "AST_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new IntExprNode(-atoi((yyvsp[0].str)->c_str())); delete (yyvsp[0].str); }
#line 1889 "AST_parser.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 181 "AST_parser.y" /* yacc.c:1646  */
    { (yyval.symbol) = (yyvsp[0].symbol); }
#line 1895 "AST_parser.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 182 "AST_parser.y" /* yacc.c:1646  */
    { (yyval.symbol) = (yyvsp[0].symbol); }
#line 1901 "AST_parser.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 183 "AST_parser.y" /* yacc.c:1646  */
    { (yyval.symbol) = (yyvsp[0].symbol); }
#line 1907 "AST_parser.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 184 "AST_parser.y" /* yacc.c:1646  */
    { (yyval.symbol) = (yyvsp[0].symbol); }
#line 1913 "AST_parser.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 185 "AST_parser.y" /* yacc.c:1646  */
    { (yyval.symbol) = (yyvsp[0].symbol); }
#line 1919 "AST_parser.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 186 "AST_parser.y" /* yacc.c:1646  */
    { (yyval.symbol) = (yyvsp[0].symbol); }
#line 1925 "AST_parser.cpp" /* yacc.c:1646  */
    break;


#line 1929 "AST_parser.cpp" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
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

  /* Else will try to reuse lookahead token after shifting the error
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

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 189 "AST_parser.y" /* yacc.c:1906  */


void definitionVar(string name, E_TYPE type) {
  map<string, E_TYPE>::iterator it;
  it = variableTable.find(name);
  if (it == variableTable.end()) {
    variableTable[name] = type;
  } else if (type == E_FUNC) {
    variableTable[name] = type;
  } else {
    cout << "line " << lineNum << ": redefinition of variable " << name << endl;
    variableTable[name] = type;
  }
}

E_TYPE checkVariableType(ExprNode *left, ExprNode *right) {
  if (left ->_type == E_UNKNOWN) {
    cout << "line" << lineNum << "left has unknown type" << endl;
    return E_UNKNOWN;
  }
  if (right ->_type == E_UNKNOWN) {
    cout << "line" << lineNum << "right has unknown type" << endl;
    return E_UNKNOWN;
  }


}

void setVariableType(VariableExprNode *var){
  map<string, E_TYPE>::iterator it;
  it = variableTable.find(var->name);
  if(it == variableTable.end()){
    var->_type = E_UNKNOWN;    
  }
  else{
    var->_type = (*it).second;
  }
}

void noSemicolonError() {
  cout << "line" << lineNum << ": 缺少分号" << endl;
}


int yyerror(char *msg)
{
	cout << "line" << lineNum << ": 有无法匹配的内容" << endl;
	return 1;	
}
