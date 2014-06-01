/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 1 "parser.y"

#include "public.h"
#include <cstdio>
#include <cctype>
#include <string>
#include "scanner.h"
#include <cstdlib>
using namespace std;
#define YYSTYPE TreeNode *
#ifndef YYPARSER
#include "parser.hpp"
#endif
string s,s1,s2,name;
int x;
TreeNode *id;
int yyerror(string);

/* Line 371 of yacc.c  */
#line 86 "parser.cpp"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
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
   by #include "parser.hpp".  */
#ifndef YY_YY_PARSER_HPP_INCLUDED
# define YY_YY_PARSER_HPP_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     AND = 258,
     ARRAY = 259,
     ASSIGN = 260,
     BEGINP = 261,
     CASE = 262,
     CHAR = 263,
     COLON = 264,
     COMMA = 265,
     CONST = 266,
     DIV = 267,
     DO = 268,
     SYS_CON = 269,
     PROCEDURE = 270,
     DOT = 271,
     DOTDOT = 272,
     DOWNTO = 273,
     OR = 274,
     ELSE = 275,
     END = 276,
     EQUAL = 277,
     FOR = 278,
     FUNCTION = 279,
     GE = 280,
     GOTO = 281,
     GT = 282,
     ID = 283,
     IF = 284,
     INTEGER = 285,
     LB = 286,
     LE = 287,
     LP = 288,
     LT = 289,
     MINUS = 290,
     MOD = 291,
     MUL = 292,
     NOT = 293,
     OF = 294,
     PLUS = 295,
     PROGRAM = 296,
     RB = 297,
     SYS_TYPE = 298,
     READ = 299,
     REAL = 300,
     RECORD = 301,
     REPEAT = 302,
     RP = 303,
     SEMI = 304,
     STRING = 305,
     THEN = 306,
     TO = 307,
     TYPE = 308,
     UNEQUAL = 309,
     UNTIL = 310,
     VAR = 311,
     WHILE = 312,
     SYS_FUNCT = 313,
     SYS_PROC = 314,
     MINUST = 315
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

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

#endif /* !YY_YY_PARSER_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 212 "parser.cpp"

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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

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
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   390

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  61
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  72
/* YYNRULES -- Number of rules.  */
#define YYNRULES  142
/* YYNRULES -- Number of states.  */
#define YYNSTATES  274

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   315

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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     7,     8,    13,    16,    20,    22,    28,
      29,    32,    33,    34,    41,    42,    48,    50,    52,    54,
      56,    58,    61,    62,    65,    67,    68,    74,    76,    78,
      80,    87,    91,    94,    96,   101,   103,   105,   109,   113,
     118,   124,   125,   130,   133,   134,   137,   139,   144,   147,
     150,   152,   154,   155,   156,   166,   167,   175,   179,   180,
     184,   186,   190,   194,   197,   199,   201,   205,   206,   207,
     212,   214,   216,   218,   220,   222,   224,   226,   228,   230,
     232,   233,   238,   239,   247,   248,   249,   257,   259,   260,
     266,   268,   269,   275,   276,   282,   286,   292,   295,   296,
     301,   306,   315,   317,   319,   325,   328,   330,   335,   336,
     342,   345,   349,   353,   357,   361,   365,   369,   371,   375,
     379,   383,   385,   389,   393,   397,   401,   403,   405,   406,
     412,   414,   415,   421,   423,   427,   430,   433,   434,   440,
     441,   446,   450
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      62,     0,    -1,    63,    65,    16,    -1,    -1,    41,    28,
      64,    49,    -1,    67,    98,    -1,    66,    10,    28,    -1,
      28,    -1,    68,    69,    74,    85,    88,    -1,    -1,    11,
      70,    -1,    -1,    -1,    70,    28,    71,    22,    73,    49,
      -1,    -1,    28,    72,    22,    73,    49,    -1,    30,    -1,
      45,    -1,     8,    -1,    50,    -1,    14,    -1,    53,    75,
      -1,    -1,    75,    76,    -1,    76,    -1,    -1,    28,    77,
      22,    78,    49,    -1,    83,    -1,    79,    -1,    80,    -1,
       4,    31,    83,    42,     9,    78,    -1,    46,    81,    21,
      -1,    81,    82,    -1,    82,    -1,    66,     9,    78,    49,
      -1,    43,    -1,    28,    -1,    33,    66,    48,    -1,    73,
      17,    73,    -1,    35,    73,    17,    73,    -1,    35,    73,
      17,    35,    73,    -1,    -1,    28,    84,    17,    28,    -1,
      56,    86,    -1,    -1,    86,    87,    -1,    87,    -1,    66,
       9,    78,    49,    -1,    88,    89,    -1,    88,    91,    -1,
      89,    -1,    91,    -1,    -1,    -1,    24,    28,    90,    93,
       9,    83,    49,    65,    49,    -1,    -1,    15,    28,    92,
      93,    49,    65,    49,    -1,    33,    94,    48,    -1,    -1,
      94,    49,    95,    -1,    95,    -1,    96,     9,    83,    -1,
      97,     9,    83,    -1,    56,    66,    -1,    66,    -1,   112,
      -1,    99,   100,    49,    -1,    -1,    -1,    30,   101,     9,
     102,    -1,   102,    -1,   103,    -1,   108,    -1,   112,    -1,
     113,    -1,   115,    -1,   116,    -1,   117,    -1,   119,    -1,
     123,    -1,    -1,    28,   104,     5,   124,    -1,    -1,    28,
     105,    31,   124,    42,     5,   124,    -1,    -1,    -1,    28,
     106,    16,    28,   107,     5,   124,    -1,    28,    -1,    -1,
      28,   109,    33,   132,    48,    -1,    59,    -1,    -1,    59,
     110,    33,   132,    48,    -1,    -1,    44,   111,    33,   127,
      48,    -1,     6,    99,    21,    -1,    29,   124,    51,   100,
     114,    -1,    20,   100,    -1,    -1,    47,    99,    55,   124,
      -1,    57,   124,    13,   100,    -1,    23,    28,     5,   124,
     118,   124,    13,   100,    -1,    52,    -1,    18,    -1,     7,
     124,    39,   120,    21,    -1,   120,   121,    -1,   121,    -1,
      73,     9,   100,    49,    -1,    -1,    28,   122,     9,   100,
      49,    -1,    26,    30,    -1,   124,    25,   125,    -1,   124,
      27,   125,    -1,   124,    32,   125,    -1,   124,    34,   125,
      -1,   124,    22,   125,    -1,   124,    54,   125,    -1,   125,
      -1,   125,    40,   126,    -1,   125,    35,   126,    -1,   125,
      19,   126,    -1,   126,    -1,   126,    37,   127,    -1,   126,
      12,   127,    -1,   126,    36,   127,    -1,   126,     3,   127,
      -1,   127,    -1,    28,    -1,    -1,    28,   128,    33,   132,
      48,    -1,    58,    -1,    -1,    58,   129,    33,   132,    48,
      -1,    73,    -1,    33,   124,    48,    -1,    38,   127,    -1,
      35,   127,    -1,    -1,    28,   130,    31,   124,    42,    -1,
      -1,    28,   131,    16,    28,    -1,   132,    10,   124,    -1,
     124,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    25,    25,    29,    29,    33,    37,    41,    47,    51,
      53,    55,    57,    57,    62,    62,    69,    70,    71,    72,
      73,    75,    77,    79,    84,    90,    90,    94,    95,    96,
      98,   102,   106,   110,   116,   120,   123,   126,   129,   132,
     137,   144,   144,   149,   151,   153,   156,   162,   166,   170,
     174,   179,   184,   186,   186,   190,   190,   194,   197,   199,
     203,   209,   212,   215,   218,   221,   227,   231,   233,   233,
     234,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     246,   246,   250,   250,   254,   254,   254,   259,   260,   260,
     262,   263,   263,   265,   265,   269,   273,   277,   278,   280,
     284,   288,   292,   293,   295,   299,   300,   302,   303,   303,
     306,   310,   311,   312,   313,   314,   315,   316,   318,   319,
     320,   321,   323,   324,   325,   326,   327,   329,   330,   330,
     332,   333,   333,   335,   336,   337,   338,   339,   339,   341,
     341,   344,   348
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "AND", "ARRAY", "ASSIGN", "BEGINP",
  "CASE", "CHAR", "COLON", "COMMA", "CONST", "DIV", "DO", "SYS_CON",
  "PROCEDURE", "DOT", "DOTDOT", "DOWNTO", "OR", "ELSE", "END", "EQUAL",
  "FOR", "FUNCTION", "GE", "GOTO", "GT", "ID", "IF", "INTEGER", "LB", "LE",
  "LP", "LT", "MINUS", "MOD", "MUL", "NOT", "OF", "PLUS", "PROGRAM", "RB",
  "SYS_TYPE", "READ", "REAL", "RECORD", "REPEAT", "RP", "SEMI", "STRING",
  "THEN", "TO", "TYPE", "UNEQUAL", "UNTIL", "VAR", "WHILE", "SYS_FUNCT",
  "SYS_PROC", "MINUST", "$accept", "program", "program_head", "@1",
  "routine", "name_list", "routine_head", "label_part", "const_part",
  "const_expr_list", "$@2", "$@3", "const_value", "type_part",
  "type_decl_list", "type_definition", "$@4", "type_decl",
  "array_type_decl", "record_type_decl", "field_decl_list", "field_decl",
  "simple_type_decl", "$@5", "var_part", "var_decl_list", "var_decl",
  "routine_part", "function_decl", "@6", "procedure_decl", "@7",
  "parameters", "para_decl_list", "para_type_list", "var_para_list",
  "val_para_list", "routine_body", "stmt_list", "stmt", "$@8",
  "non_label_stmt", "assign_stmt", "$@9", "$@10", "$@11", "@12",
  "proc_stmt", "$@13", "$@14", "$@15", "compound_stmt", "if_stmt",
  "else_clause", "repeat_stmt", "while_stmt", "for_stmt", "direction",
  "case_stmt", "case_expr_list", "case_expr", "$@16", "goto_stmt",
  "expression", "expr", "term", "factor", "$@17", "$@18", "$@19", "$@20",
  "args_list", YY_NULL
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    61,    62,    64,    63,    65,    66,    66,    67,    68,
      69,    69,    71,    70,    72,    70,    73,    73,    73,    73,
      73,    74,    74,    75,    75,    77,    76,    78,    78,    78,
      79,    80,    81,    81,    82,    83,    83,    83,    83,    83,
      83,    84,    83,    85,    85,    86,    86,    87,    88,    88,
      88,    88,    88,    90,    89,    92,    91,    93,    93,    94,
      94,    95,    95,    96,    97,    98,    99,    99,   101,   100,
     100,   102,   102,   102,   102,   102,   102,   102,   102,   102,
     104,   103,   105,   103,   106,   107,   103,   108,   109,   108,
     108,   110,   108,   111,   108,   112,   113,   114,   114,   115,
     116,   117,   118,   118,   119,   120,   120,   121,   122,   121,
     123,   124,   124,   124,   124,   124,   124,   124,   125,   125,
     125,   125,   126,   126,   126,   126,   126,   127,   128,   127,
     127,   129,   127,   127,   127,   127,   127,   130,   127,   131,
     127,   132,   132
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     0,     4,     2,     3,     1,     5,     0,
       2,     0,     0,     6,     0,     5,     1,     1,     1,     1,
       1,     2,     0,     2,     1,     0,     5,     1,     1,     1,
       6,     3,     2,     1,     4,     1,     1,     3,     3,     4,
       5,     0,     4,     2,     0,     2,     1,     4,     2,     2,
       1,     1,     0,     0,     9,     0,     7,     3,     0,     3,
       1,     3,     3,     2,     1,     1,     3,     0,     0,     4,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     4,     0,     7,     0,     0,     7,     1,     0,     5,
       1,     0,     5,     0,     5,     3,     5,     2,     0,     4,
       4,     8,     1,     1,     5,     2,     1,     4,     0,     5,
       2,     3,     3,     3,     3,     3,     3,     1,     3,     3,
       3,     1,     3,     3,     3,     3,     1,     1,     0,     5,
       1,     0,     5,     1,     3,     2,     2,     0,     5,     0,
       4,     3,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     9,     3,     1,     0,     0,    11,     0,
       2,    67,     5,    65,     0,    22,     4,     0,    14,    10,
       0,    44,     0,    95,     0,     0,    87,     0,    68,    93,
      67,     0,    90,     0,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,     0,    12,    25,    21,    24,     0,
      52,    18,    20,   127,    16,     0,     0,     0,    17,    19,
     130,   133,     0,   117,   121,   126,     0,   110,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    66,     0,
       0,     0,    23,     7,     0,    43,    46,     0,     0,     8,
      50,    51,     0,     0,     0,     0,   136,   135,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    45,
      55,    53,    48,    49,     0,     0,     0,   134,     0,   115,
     111,   112,   113,   114,   108,     0,     0,   106,   116,   120,
     119,   118,   125,   123,   124,   122,     0,    81,     0,    85,
     142,     0,    98,    69,     0,    99,   100,     0,    15,     0,
       0,    36,     0,     0,    35,     0,     0,     0,    28,    29,
      27,     0,     6,    58,    58,     0,     0,   140,     0,     0,
       0,   104,   105,   103,   102,     0,     0,     0,     0,    89,
       0,    96,    94,    92,    13,     0,     0,     0,     0,     0,
       0,    33,     0,    26,    47,     0,     0,     0,   129,   138,
     132,     0,     0,     0,     0,     0,   141,    97,     0,     0,
      37,     0,     0,    31,    32,    38,     0,    64,     0,    60,
       0,     0,     9,     0,     0,   107,     0,    83,    86,     0,
      42,     0,    39,     0,    63,    57,     0,     0,     0,     0,
       0,   109,   101,     0,    40,    34,    59,    61,    62,    56,
       9,    30,     0,    54
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     9,     6,    84,     7,     8,    15,    19,
      80,    44,    61,    21,    47,    48,    81,   177,   178,   179,
     210,   211,   180,   206,    50,    85,    86,    89,    90,   184,
      91,   183,   216,   238,   239,   240,   241,    12,    17,    33,
      73,    34,    35,    68,    69,    70,   197,    36,    71,    77,
      74,    37,    38,   201,    39,    40,    41,   195,    42,   146,
     147,   189,    43,   160,    63,    64,    65,    92,    98,    93,
      94,   161
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -209
static const yytype_int16 yypact[] =
{
     -29,    -6,    24,  -209,  -209,  -209,    10,    25,    27,   -13,
    -209,  -209,  -209,  -209,    42,    29,  -209,    14,  -209,    44,
      52,    21,   171,  -209,    57,    60,    78,   171,  -209,  -209,
    -209,   171,    55,    56,  -209,  -209,  -209,  -209,  -209,  -209,
    -209,  -209,  -209,  -209,    86,  -209,  -209,    52,  -209,    82,
      15,  -209,  -209,   107,  -209,   171,   171,   171,  -209,  -209,
      85,  -209,   272,    49,    20,  -209,   128,  -209,   134,   111,
     127,   112,   280,   140,   117,    72,   238,   119,  -209,    67,
     131,   142,  -209,  -209,    19,    82,  -209,   144,   150,    15,
    -209,  -209,   149,   152,   175,   303,  -209,  -209,   159,   171,
     171,   171,   171,   171,   106,   171,   171,   171,   171,   171,
     171,   171,   171,   171,   171,   171,   165,   171,   118,   161,
     171,   171,   118,   171,   146,    67,   203,   203,   168,  -209,
    -209,  -209,  -209,  -209,   171,   171,   169,  -209,   171,    49,
      49,    49,    49,    49,  -209,   189,   236,  -209,    49,    20,
      20,    20,  -209,  -209,  -209,  -209,   266,   336,   311,  -209,
     336,     3,   192,  -209,   166,   336,  -209,     4,  -209,   151,
     182,   202,    82,    67,  -209,    82,   205,   174,  -209,  -209,
    -209,   177,  -209,   191,   191,     5,   322,  -209,     6,   218,
     118,  -209,  -209,  -209,  -209,   171,   223,   227,   171,  -209,
     118,  -209,  -209,  -209,  -209,   226,   220,     7,   222,    94,
      -3,  -209,    67,  -209,  -209,    -9,   186,   232,  -209,  -209,
    -209,   118,   193,   255,   171,   171,   336,  -209,   201,   217,
    -209,   180,   203,  -209,  -209,  -209,    82,   237,    73,  -209,
     243,   246,  -209,   226,   209,  -209,   118,   336,   336,   253,
    -209,    67,  -209,   224,   237,  -209,    -9,   226,   226,   225,
     229,  -209,  -209,   203,  -209,  -209,  -209,  -209,  -209,  -209,
    -209,  -209,   230,  -209
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -209,  -209,  -209,  -209,  -208,  -169,  -209,  -209,  -209,  -209,
    -209,  -209,   -77,  -209,  -209,   228,  -209,  -126,  -209,  -209,
    -209,    75,  -198,  -209,  -209,  -209,   198,  -209,   178,  -209,
     206,  -209,   124,  -209,    34,  -209,  -209,  -209,   271,  -114,
    -209,   184,  -209,  -209,  -209,  -209,  -209,  -209,  -209,  -209,
    -209,   289,  -209,  -209,  -209,  -209,  -209,  -209,  -209,  -209,
     164,  -209,  -209,   -22,    58,    63,   -46,  -209,  -209,  -209,
    -209,    -8
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -140
static const yytype_int16 yytable[] =
{
      62,   181,   124,   207,   162,    72,   209,   228,   166,    76,
      96,    97,     1,   198,   198,   198,   198,   128,   233,    83,
      11,    22,     4,   109,     5,    83,    10,   145,   127,   128,
      87,    11,   110,    95,   259,    23,    16,    24,    14,    88,
      25,   209,    26,    27,    28,   260,   237,   236,   169,   176,
     176,   199,   203,   218,   220,   230,   111,   112,    29,   267,
     268,    30,   272,   152,   153,   154,   155,   254,   106,   145,
      18,    31,    45,    32,   164,    51,   222,    49,    11,    22,
      46,    52,    20,   -80,   107,    66,   227,   237,   -91,   108,
      67,   156,   157,   158,   -84,    24,   208,    54,    25,   165,
      26,    27,    28,   232,   128,    78,   253,   244,    79,   -82,
      83,   -88,    58,   186,    51,   167,    29,    59,  -131,    30,
      52,   255,   256,  -139,    11,    22,   185,   121,   176,    31,
     188,    32,   262,   113,   144,   235,    54,   271,  -137,   114,
    -128,    24,   115,   116,    25,   117,    26,    27,    28,   119,
     120,    58,   123,   125,   252,   176,    59,   139,   140,   141,
     142,   143,    29,   148,   126,    30,   176,    11,    22,   149,
     150,   151,   130,   223,   264,    31,   226,    32,   131,    51,
     176,   176,   134,   135,    24,    52,   176,    25,    51,    26,
      27,   136,   138,   159,    52,   168,   182,   187,   190,    53,
     204,    54,   247,   248,    55,    29,    56,   170,    30,    57,
      54,    51,   200,   205,   202,   251,    58,    52,    31,   -41,
      32,    59,   212,   213,   215,    58,   214,   221,   224,    60,
      59,   171,   225,    54,    51,   242,   172,   229,   173,   231,
      52,   243,   245,   249,    51,   250,   174,   128,    58,   175,
      52,   122,   257,    59,   171,   258,    54,   191,   261,   172,
      99,   173,   263,   100,   144,   101,    54,   132,   246,   174,
     102,    58,   103,   265,   269,    82,    59,    99,   270,   273,
     100,    58,   101,   129,   193,   234,    59,   102,    99,   103,
     266,   100,   105,   101,    99,   133,    13,   100,   102,   101,
     103,    75,    99,   163,   102,   100,   103,   101,   217,   105,
     192,   104,   102,     0,   103,     0,     0,     0,   194,     0,
     105,     0,     0,     0,     0,    99,   105,     0,   100,     0,
     101,   118,     0,    99,   105,   102,   100,   103,   101,     0,
       0,     0,     0,   102,    99,   103,     0,   100,     0,   101,
       0,   137,     0,   196,   102,     0,   103,   105,    99,     0,
       0,   100,     0,   101,   219,   105,     0,     0,   102,     0,
     103,     0,     0,     0,     0,     0,   105,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     105
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-209)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      22,   127,    79,   172,   118,    27,   175,   205,   122,    31,
      56,    57,    41,    10,    10,    10,    10,    10,    21,    28,
       6,     7,    28,     3,     0,    28,    16,   104,     9,    10,
      15,     6,    12,    55,   242,    21,    49,    23,    11,    24,
      26,   210,    28,    29,    30,   243,   215,    56,   125,   126,
     127,    48,    48,    48,    48,    48,    36,    37,    44,   257,
     258,    47,   270,   109,   110,   111,   112,   236,    19,   146,
      28,    57,    28,    59,   120,     8,   190,    56,     6,     7,
      28,    14,    53,     5,    35,    28,   200,   256,    33,    40,
      30,   113,   114,   115,    16,    23,   173,    30,    26,   121,
      28,    29,    30,     9,    10,    49,   232,   221,    22,    31,
      28,    33,    45,   135,     8,   123,    44,    50,    33,    47,
      14,    48,    49,    16,     6,     7,   134,    55,   205,    57,
     138,    59,   246,     5,    28,   212,    30,   263,    31,     5,
      33,    23,    31,    16,    26,    33,    28,    29,    30,     9,
      33,    45,    33,    22,   231,   232,    50,    99,   100,   101,
     102,   103,    44,   105,    22,    47,   243,     6,     7,   106,
     107,   108,    28,   195,   251,    57,   198,    59,    28,     8,
     257,   258,    33,    31,    23,    14,   263,    26,     8,    28,
      29,    16,    33,    28,    14,    49,    28,    28,     9,    28,
      49,    30,   224,   225,    33,    44,    35,     4,    47,    38,
      30,     8,    20,    31,    48,    35,    45,    14,    57,    17,
      59,    50,    17,    49,    33,    45,    49,     9,     5,    58,
      50,    28,     5,    30,     8,    49,    33,    17,    35,    17,
      14,     9,    49,    42,     8,    28,    43,    10,    45,    46,
      14,    13,     9,    50,    28,     9,    30,    21,    49,    33,
      22,    35,     9,    25,    28,    27,    30,    89,    13,    43,
      32,    45,    34,    49,    49,    47,    50,    22,    49,    49,
      25,    45,    27,    85,    18,   210,    50,    32,    22,    34,
     256,    25,    54,    27,    22,    89,     7,    25,    32,    27,
      34,    30,    22,   119,    32,    25,    34,    27,   184,    54,
     146,    39,    32,    -1,    34,    -1,    -1,    -1,    52,    -1,
      54,    -1,    -1,    -1,    -1,    22,    54,    -1,    25,    -1,
      27,    51,    -1,    22,    54,    32,    25,    34,    27,    -1,
      -1,    -1,    -1,    32,    22,    34,    -1,    25,    -1,    27,
      -1,    48,    -1,    42,    32,    -1,    34,    54,    22,    -1,
      -1,    25,    -1,    27,    42,    54,    -1,    -1,    32,    -1,
      34,    -1,    -1,    -1,    -1,    -1,    54,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      54
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    41,    62,    63,    28,     0,    65,    67,    68,    64,
      16,     6,    98,   112,    11,    69,    49,    99,    28,    70,
      53,    74,     7,    21,    23,    26,    28,    29,    30,    44,
      47,    57,    59,   100,   102,   103,   108,   112,   113,   115,
     116,   117,   119,   123,    72,    28,    28,    75,    76,    56,
      85,     8,    14,    28,    30,    33,    35,    38,    45,    50,
      58,    73,   124,   125,   126,   127,    28,    30,   104,   105,
     106,   109,   124,   101,   111,    99,   124,   110,    49,    22,
      71,    77,    76,    28,    66,    86,    87,    15,    24,    88,
      89,    91,   128,   130,   131,   124,   127,   127,   129,    22,
      25,    27,    32,    34,    39,    54,    19,    35,    40,     3,
      12,    36,    37,     5,     5,    31,    16,    33,    51,     9,
      33,    55,    13,    33,    73,    22,    22,     9,    10,    87,
      28,    28,    89,    91,    33,    31,    16,    48,    33,   125,
     125,   125,   125,   125,    28,    73,   120,   121,   125,   126,
     126,   126,   127,   127,   127,   127,   124,   124,   124,    28,
     124,   132,   100,   102,   127,   124,   100,   132,    49,    73,
       4,    28,    33,    35,    43,    46,    73,    78,    79,    80,
      83,    78,    28,    92,    90,   132,   124,    28,   132,   122,
       9,    21,   121,    18,    52,   118,    42,   107,    10,    48,
      20,   114,    48,    48,    49,    31,    84,    66,    73,    66,
      81,    82,    17,    49,    49,    33,    93,    93,    48,    42,
      48,     9,   100,   124,     5,     5,   124,   100,    83,    17,
      48,    17,     9,    21,    82,    73,    56,    66,    94,    95,
      96,    97,    49,     9,   100,    49,    13,   124,   124,    42,
      28,    35,    73,    78,    66,    48,    49,     9,     9,    65,
      83,    49,   100,     9,    73,    49,    95,    83,    83,    49,
      49,    78,    65,    49
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
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

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
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
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
  FILE *yyo = yyoutput;
  YYUSE (yyo);
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
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
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
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
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




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

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
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

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
/* Line 1792 of yacc.c  */
#line 25 "parser.y"
    {
(yyval) = new ProgramTreeNode(((ProgramHeadTreeNode*)(yyvsp[(1) - (3)]))->getName(), (RoutineTreeNode *)(yyvsp[(2) - (3)]));
}
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 29 "parser.y"
    {
  (yyval) = new ProgramHeadTreeNode(currentToken);
}
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 33 "parser.y"
    {
  (yyval) = new RoutineTreeNode((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
}
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 37 "parser.y"
    {
  (yyval) = (yyvsp[(1) - (3)]);
  (yyval)->insert(new TreeNode(currentToken));
}
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 41 "parser.y"
    {
   vector<TreeNode *> list;
   list.push_back(new TreeNode(currentToken));
   (yyval) = new ListTreeNode("name_list", list);
}
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 47 "parser.y"
    {
   (yyval) = new RoutineHeadTreeNode((yyvsp[(2) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(4) - (5)]), (yyvsp[(5) - (5)]));
}
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 51 "parser.y"
    {}
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 53 "parser.y"
    {
  (yyval) = (yyvsp[(2) - (2)]);
}
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 57 "parser.y"
    {name = currentToken;}
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 58 "parser.y"
    {
  (yyval) = (yyvsp[(1) - (6)]);
  (yyval)->insert(new ConstTreeNode(name, (yyvsp[(4) - (6)])));
}
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 62 "parser.y"
    {name = currentToken;}
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 63 "parser.y"
    {
  vector<TreeNode *> list;
  (yyval) = new ListTreeNode("const_value_list",list);
  (yyval)->insert(new ConstTreeNode(name, (yyvsp[(3) - (5)])));
}
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 69 "parser.y"
    {(yyval) = new NumberTreeNode<int>(atoi(currentToken.c_str()));}
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 70 "parser.y"
    {(yyval) = new NumberTreeNode<double>(atof(currentToken.c_str()));}
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 71 "parser.y"
    {(yyval) = new NumberTreeNode<char>(currentToken[0]);}
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 72 "parser.y"
    {(yyval) = new NumberTreeNode<string>(currentToken);}
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 73 "parser.y"
    {(yyval) = new NumberTreeNode<string>(currentToken);}
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 75 "parser.y"
    {
  (yyval) = (yyvsp[(2) - (2)]);
}
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 80 "parser.y"
    {
  (yyval) = (yyvsp[(1) - (2)]);
  (yyval)->insert((yyvsp[(2) - (2)]));
}
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 84 "parser.y"
    {
  vector<TreeNode *> list;
  list.push_back((yyvsp[(1) - (1)]));
  (yyval) = new ListTreeNode("type_decl_list",list);
}
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 90 "parser.y"
    {name = currentToken;}
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 90 "parser.y"
    {
  (yyval) = new CustomTypeTreeNode(name, (yyvsp[(3) - (5)]));
}
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 94 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 95 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 96 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 98 "parser.y"
    {
  (yyval) = new ArrayTypeTreeNode((yyvsp[(3) - (6)]),(yyvsp[(6) - (6)]));
}
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 102 "parser.y"
    {
  (yyval) = new RecordTypeTreeNode((yyvsp[(2) - (3)]));
}
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 106 "parser.y"
    {
  (yyval) = (yyvsp[(1) - (2)]);
  (yyval)->insert((yyvsp[(2) - (2)]));
}
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 110 "parser.y"
    {
  vector<TreeNode *> list;
  list.push_back((yyvsp[(1) - (1)]));
  (yyval) = new ListTreeNode("field_decl_list",list);
}
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 116 "parser.y"
    {
  (yyval) = new VariableTreeNode((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
}
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 120 "parser.y"
    {
                  (yyval) = new SysTypeTreeNode(currentToken);
                }
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 123 "parser.y"
    {
                  (yyval) = new CustomTypeTreeNode(currentToken);
                }
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 126 "parser.y"
    {
                  (yyval) = new EnumTypeTreeNode((yyvsp[(2) - (3)]));
                }
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 129 "parser.y"
    {
                  (yyval) = new SubRangeTypeTreeNode((yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]));
                }
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 132 "parser.y"
    {
                  NumberTreeNode<int>* n = (NumberTreeNode<int>*)(yyvsp[(1) - (4)]);
                  n->set(-(int)(n->get()));
                  (yyval) = new SubRangeTypeTreeNode((yyvsp[(1) - (4)]),(yyvsp[(3) - (4)]));
                }
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 137 "parser.y"
    {
                  NumberTreeNode<int>* n1 = (NumberTreeNode<int>*)(yyvsp[(1) - (5)]);
                  NumberTreeNode<int>* n2 = (NumberTreeNode<int>*)(yyvsp[(2) - (5)]);
                  n1->set(-(int)(n1->get()));
                  n2->set(-(int)(n2->get()));
                  (yyval) = new SubRangeTypeTreeNode((yyvsp[(1) - (5)]),(yyvsp[(3) - (5)])); 
                }
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 144 "parser.y"
    {s1 = currentToken;}
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 144 "parser.y"
    {
                  s2 = currentToken;
                  (yyval) = new RecordElemTreeNode(s1, s2);
                }
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 149 "parser.y"
    {
  (yyval) = (yyvsp[(2) - (2)]);
}
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 153 "parser.y"
    {
  (yyval) = (yyvsp[(1) - (2)]);
  (yyval)->insert((yyvsp[(2) - (2)]));
}
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 156 "parser.y"
    {
  vector<TreeNode *> list;
  list.push_back((yyvsp[(1) - (1)]));
  (yyval) = new ListTreeNode("var_decl_list",list);
}
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 162 "parser.y"
    {
  (yyval) = new VariableTreeNode((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]), 1);
}
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 166 "parser.y"
    {
                (yyval) = (yyvsp[(1) - (2)]);
                (yyval)->insert((yyvsp[(2) - (2)]));
              }
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 170 "parser.y"
    {
              (yyval) = (yyvsp[(1) - (2)]);
              (yyval)->insert((yyvsp[(2) - (2)]));
              }
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 174 "parser.y"
    {
                vector<TreeNode *> list;
                list.push_back((yyvsp[(1) - (1)]));
                (yyval) = new ListTreeNode("function_decl_list",list);
              }
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 179 "parser.y"
    {
                vector<TreeNode *> list;
                list.push_back((yyvsp[(1) - (1)]));
                (yyval) = new ListTreeNode("procedure_decl_list",list);
            }
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 186 "parser.y"
    {name = currentToken;}
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 186 "parser.y"
    {
  (yyval) = new FunctionTreeNode(name, (yyvsp[(3) - (9)]), (yyvsp[(5) - (9)]), (yyvsp[(7) - (9)]));
}
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 190 "parser.y"
    {name = currentToken;}
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 190 "parser.y"
    {
 (yyval) = new ProcedureTreeNode(name, (yyvsp[(3) - (7)]), (yyvsp[(5) - (7)])); 
}
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 194 "parser.y"
    {
  (yyval) = (yyvsp[(2) - (3)]); 
}
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 199 "parser.y"
    {
  (yyval) = (yyvsp[(1) - (3)]);
  (yyval)->insert((yyvsp[(3) - (3)]));
}
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 203 "parser.y"
    {
  vector<TreeNode *> list;
  list.push_back((yyvsp[(1) - (1)]));
  (yyval) = new ListTreeNode("para_type_list",list);
}
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 209 "parser.y"
    {
  (yyval) = new VariableTreeNode((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]),1);
}
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 212 "parser.y"
    {
 (yyval) = new VariableTreeNode((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), 0); 
}
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 215 "parser.y"
    {
  (yyval) = (yyvsp[(2) - (2)]);
}
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 218 "parser.y"
    {
  (yyval) = (yyvsp[(1) - (1)]);
}
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 221 "parser.y"
    {
  (yyval) = (yyvsp[(1) - (1)]);
}
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 227 "parser.y"
    {
    (yyval) = (yyvsp[(1) - (3)]);
  	(yyval)->insert((yyvsp[(2) - (3)]));
}
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 231 "parser.y"
    {(yyval) = new ListTreeNode("stmt");}
    break;

  case 68:
/* Line 1792 of yacc.c  */
#line 233 "parser.y"
    {x = atoi(currentToken.c_str());}
    break;

  case 69:
/* Line 1792 of yacc.c  */
#line 233 "parser.y"
    {(yyval) = (yyvsp[(3) - (4)]);((StmtTreeNode*)(yyval))->setLabel(x);}
    break;

  case 70:
/* Line 1792 of yacc.c  */
#line 234 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 71:
/* Line 1792 of yacc.c  */
#line 236 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 72:
/* Line 1792 of yacc.c  */
#line 237 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 73:
/* Line 1792 of yacc.c  */
#line 238 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 74:
/* Line 1792 of yacc.c  */
#line 239 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 75:
/* Line 1792 of yacc.c  */
#line 240 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 76:
/* Line 1792 of yacc.c  */
#line 241 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 77:
/* Line 1792 of yacc.c  */
#line 242 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 78:
/* Line 1792 of yacc.c  */
#line 243 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 79:
/* Line 1792 of yacc.c  */
#line 244 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 80:
/* Line 1792 of yacc.c  */
#line 246 "parser.y"
    {name = currentToken;}
    break;

  case 81:
/* Line 1792 of yacc.c  */
#line 246 "parser.y"
    {
                VariableTreeNode* x = new VariableTreeNode(name);
                (yyval) = new BinaryExprTreeNode("=",x,(yyvsp[(3) - (4)]));
            }
    break;

  case 82:
/* Line 1792 of yacc.c  */
#line 250 "parser.y"
    {s = currentToken;}
    break;

  case 83:
/* Line 1792 of yacc.c  */
#line 250 "parser.y"
    {
                TreeNode* x = new ArrayElemTreeNode(s,(yyvsp[(3) - (7)]));
                (yyval) = new BinaryExprTreeNode("=",x,(yyvsp[(6) - (7)]));
            }
    break;

  case 84:
/* Line 1792 of yacc.c  */
#line 254 "parser.y"
    {s1 = currentToken;}
    break;

  case 85:
/* Line 1792 of yacc.c  */
#line 254 "parser.y"
    {s2 = currentToken;}
    break;

  case 86:
/* Line 1792 of yacc.c  */
#line 254 "parser.y"
    {
                TreeNode* x = new RecordElemTreeNode(s1,s2);
                (yyval) = new BinaryExprTreeNode("=",x,(yyvsp[(5) - (7)]));
            }
    break;

  case 87:
/* Line 1792 of yacc.c  */
#line 259 "parser.y"
    {(yyval) = new CallExprTreeNode(currentToken);}
    break;

  case 88:
/* Line 1792 of yacc.c  */
#line 260 "parser.y"
    {s = currentToken;}
    break;

  case 89:
/* Line 1792 of yacc.c  */
#line 261 "parser.y"
    {(yyval) = new CallExprTreeNode(s,((ListTreeNode*)(yyvsp[(3) - (5)]))->getList());}
    break;

  case 90:
/* Line 1792 of yacc.c  */
#line 262 "parser.y"
    {(yyval) = new CallExprTreeNode(currentToken);}
    break;

  case 91:
/* Line 1792 of yacc.c  */
#line 263 "parser.y"
    {s = currentToken;}
    break;

  case 92:
/* Line 1792 of yacc.c  */
#line 264 "parser.y"
    {(yyval) = new CallExprTreeNode(s,((ListTreeNode*)(yyvsp[(3) - (5)]))->getList());}
    break;

  case 93:
/* Line 1792 of yacc.c  */
#line 265 "parser.y"
    {s = currentToken;}
    break;

  case 94:
/* Line 1792 of yacc.c  */
#line 266 "parser.y"
    {(yyval) = new CallExprTreeNode(s,((ListTreeNode*)(yyvsp[(3) - (5)]))->getList());}
    break;

  case 95:
/* Line 1792 of yacc.c  */
#line 269 "parser.y"
    {
    (yyval) = new CompoundStmtTreeNode((yyvsp[(2) - (3)]));
}
    break;

  case 96:
/* Line 1792 of yacc.c  */
#line 273 "parser.y"
    {
    (yyval) = new IfStmtTreeNode((yyvsp[(2) - (5)]),(yyvsp[(4) - (5)]),(yyvsp[(5) - (5)]));
}
    break;

  case 97:
/* Line 1792 of yacc.c  */
#line 277 "parser.y"
    {(yyval) = (yyvsp[(2) - (2)]);}
    break;

  case 98:
/* Line 1792 of yacc.c  */
#line 278 "parser.y"
    {(yyval) = NULL;}
    break;

  case 99:
/* Line 1792 of yacc.c  */
#line 280 "parser.y"
    {
    (yyval) = new RepeatStmtTreeNode((yyvsp[(2) - (4)]),(yyvsp[(4) - (4)]));
}
    break;

  case 100:
/* Line 1792 of yacc.c  */
#line 284 "parser.y"
    {
    (yyval) = new WhileStmtTreeNode((yyvsp[(4) - (4)]),(yyvsp[(2) - (4)]));
}
    break;

  case 101:
/* Line 1792 of yacc.c  */
#line 288 "parser.y"
    {
    (yyval) = new ForStmtTreeNode((yyvsp[(4) - (8)]),(yyvsp[(5) - (8)])->getName(),(yyvsp[(6) - (8)]),(yyvsp[(8) - (8)]));
}
    break;

  case 102:
/* Line 1792 of yacc.c  */
#line 292 "parser.y"
    {(yyval) = new TreeNode("to");}
    break;

  case 103:
/* Line 1792 of yacc.c  */
#line 293 "parser.y"
    {(yyval) = new TreeNode("downto");}
    break;

  case 104:
/* Line 1792 of yacc.c  */
#line 295 "parser.y"
    {
    (yyval) = new SwitchStmtTreeNode((yyvsp[(2) - (5)]),(yyvsp[(4) - (5)]));
}
    break;

  case 105:
/* Line 1792 of yacc.c  */
#line 299 "parser.y"
    {(yyval) = (yyvsp[(1) - (2)]); (yyval)->insert((yyvsp[(2) - (2)]));}
    break;

  case 106:
/* Line 1792 of yacc.c  */
#line 300 "parser.y"
    {(yyval) = new ListTreeNode("case"); (yyval)->insert((yyvsp[(1) - (1)]));}
    break;

  case 107:
/* Line 1792 of yacc.c  */
#line 302 "parser.y"
    {(yyval) = new CaseExprTreeNode((yyvsp[(1) - (4)]),(yyvsp[(3) - (4)]));}
    break;

  case 108:
/* Line 1792 of yacc.c  */
#line 303 "parser.y"
    {id = new VariableTreeNode(currentToken);}
    break;

  case 109:
/* Line 1792 of yacc.c  */
#line 304 "parser.y"
    {(yyval) = new CaseExprTreeNode(id,(yyvsp[(3) - (5)]));}
    break;

  case 110:
/* Line 1792 of yacc.c  */
#line 306 "parser.y"
    {
    (yyval) = new GotoStmtTreeNode(currentToken);
}
    break;

  case 111:
/* Line 1792 of yacc.c  */
#line 310 "parser.y"
    {(yyval) = new BinaryExprTreeNode(">=",(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]));}
    break;

  case 112:
/* Line 1792 of yacc.c  */
#line 311 "parser.y"
    {(yyval) = new BinaryExprTreeNode(">",(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]));}
    break;

  case 113:
/* Line 1792 of yacc.c  */
#line 312 "parser.y"
    {(yyval) = new BinaryExprTreeNode("<=",(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]));}
    break;

  case 114:
/* Line 1792 of yacc.c  */
#line 313 "parser.y"
    {(yyval) = new BinaryExprTreeNode("<",(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]));}
    break;

  case 115:
/* Line 1792 of yacc.c  */
#line 314 "parser.y"
    {(yyval) = new BinaryExprTreeNode("==",(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]));}
    break;

  case 116:
/* Line 1792 of yacc.c  */
#line 315 "parser.y"
    {(yyval) = new BinaryExprTreeNode("!=",(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]));}
    break;

  case 117:
/* Line 1792 of yacc.c  */
#line 316 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 118:
/* Line 1792 of yacc.c  */
#line 318 "parser.y"
    {(yyval) = new BinaryExprTreeNode("+",(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]));}
    break;

  case 119:
/* Line 1792 of yacc.c  */
#line 319 "parser.y"
    {(yyval) = new BinaryExprTreeNode("-",(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]));}
    break;

  case 120:
/* Line 1792 of yacc.c  */
#line 320 "parser.y"
    {(yyval) = new BinaryExprTreeNode("||",(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]));}
    break;

  case 121:
/* Line 1792 of yacc.c  */
#line 321 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 122:
/* Line 1792 of yacc.c  */
#line 323 "parser.y"
    {(yyval) = new BinaryExprTreeNode("*",(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]));}
    break;

  case 123:
/* Line 1792 of yacc.c  */
#line 324 "parser.y"
    {(yyval) = new BinaryExprTreeNode("/",(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]));}
    break;

  case 124:
/* Line 1792 of yacc.c  */
#line 325 "parser.y"
    {(yyval) = new BinaryExprTreeNode("%",(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]));}
    break;

  case 125:
/* Line 1792 of yacc.c  */
#line 326 "parser.y"
    {(yyval) = new BinaryExprTreeNode("&&",(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]));}
    break;

  case 126:
/* Line 1792 of yacc.c  */
#line 327 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 127:
/* Line 1792 of yacc.c  */
#line 329 "parser.y"
    {(yyval) = new CallExprTreeNode(currentToken);}
    break;

  case 128:
/* Line 1792 of yacc.c  */
#line 330 "parser.y"
    {s = currentToken;}
    break;

  case 129:
/* Line 1792 of yacc.c  */
#line 331 "parser.y"
    {(yyval) = new CallExprTreeNode(s,((ListTreeNode*)(yyvsp[(3) - (5)]))->getList());}
    break;

  case 130:
/* Line 1792 of yacc.c  */
#line 332 "parser.y"
    {(yyval) = new CallExprTreeNode(currentToken);}
    break;

  case 131:
/* Line 1792 of yacc.c  */
#line 333 "parser.y"
    {s = currentToken;}
    break;

  case 132:
/* Line 1792 of yacc.c  */
#line 334 "parser.y"
    {(yyval) = new CallExprTreeNode(s,((ListTreeNode*)(yyvsp[(3) - (5)]))->getList());}
    break;

  case 133:
/* Line 1792 of yacc.c  */
#line 335 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 134:
/* Line 1792 of yacc.c  */
#line 336 "parser.y"
    {(yyval) = (yyvsp[(2) - (3)]);}
    break;

  case 135:
/* Line 1792 of yacc.c  */
#line 337 "parser.y"
    {(yyval) = new UnaryExprTreeNode("~",(yyvsp[(2) - (2)]));}
    break;

  case 136:
/* Line 1792 of yacc.c  */
#line 338 "parser.y"
    {(yyval) = new UnaryExprTreeNode("-",(yyvsp[(2) - (2)]));}
    break;

  case 137:
/* Line 1792 of yacc.c  */
#line 339 "parser.y"
    {s = currentToken;}
    break;

  case 138:
/* Line 1792 of yacc.c  */
#line 340 "parser.y"
    {(yyval) = new ArrayElemTreeNode(s,(yyvsp[(3) - (5)]));}
    break;

  case 139:
/* Line 1792 of yacc.c  */
#line 341 "parser.y"
    {s1 = currentToken;}
    break;

  case 140:
/* Line 1792 of yacc.c  */
#line 342 "parser.y"
    {s2 = currentToken; (yyval) = new RecordElemTreeNode(s1,s2);}
    break;

  case 141:
/* Line 1792 of yacc.c  */
#line 344 "parser.y"
    {
    (yyval) = (yyvsp[(1) - (3)]);
    (yyval)->insert((yyvsp[(3) - (3)]));
}
    break;

  case 142:
/* Line 1792 of yacc.c  */
#line 348 "parser.y"
    {(yyval) = new ListTreeNode("expr"); (yyval)->insert((yyvsp[(1) - (1)]));}
    break;


/* Line 1792 of yacc.c  */
#line 2649 "parser.cpp"
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


/* Line 2055 of yacc.c  */
#line 352 "parser.y"


main() 
{
	return yyparse();
}



int yyerror(string s) {
	fprintf(stderr, "%s\n", s.c_str());
	return 0;
}

