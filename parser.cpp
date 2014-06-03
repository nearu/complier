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
#include <iostream>
#include <fstream>
using namespace std;
#define YYSTYPE TreeNode *
#ifndef YYPARSER
#include "parser.hpp"
#endif
#define currentToken yytext

int yyerror(string);
static void tp(const string);
static int yylex();
string s,s1,s2,name;
int x;
TreeNode *id;
extern char* yytext;
extern FILE *yyin, *yyout;
extern int traceScan;
extern string idstr;
ProgramTreeNode *root;
int traceParse = TRUE;
ofstream parserOut("parserOut");

/* Line 371 of yacc.c  */
#line 99 "parser.cpp"

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



/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 222 "parser.cpp"

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
#define YYLAST   359

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  61
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  73
/* YYNRULES -- Number of rules.  */
#define YYNRULES  144
/* YYNRULES -- Number of states.  */
#define YYNSTATES  275

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
     184,   186,   190,   194,   196,   199,   201,   203,   207,   208,
     209,   214,   216,   218,   220,   222,   224,   226,   228,   230,
     232,   234,   235,   240,   241,   249,   250,   251,   259,   261,
     262,   268,   270,   271,   277,   278,   284,   288,   294,   297,
     298,   303,   308,   309,   319,   321,   323,   329,   332,   334,
     339,   340,   346,   349,   353,   357,   361,   365,   369,   373,
     375,   379,   383,   387,   389,   393,   397,   401,   405,   407,
     409,   410,   416,   418,   419,   425,   427,   431,   434,   437,
     438,   444,   445,   450,   454
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
       4,    31,    83,    42,    39,    78,    -1,    46,    81,    21,
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
      97,     9,    83,    -1,    97,    -1,    56,    66,    -1,    66,
      -1,   112,    -1,    99,   100,    49,    -1,    -1,    -1,    30,
     101,     9,   102,    -1,   102,    -1,   103,    -1,   108,    -1,
     112,    -1,   113,    -1,   115,    -1,   116,    -1,   117,    -1,
     120,    -1,   124,    -1,    -1,    28,   104,     5,   125,    -1,
      -1,    28,   105,    31,   125,    42,     5,   125,    -1,    -1,
      -1,    28,   106,    16,    28,   107,     5,   125,    -1,    28,
      -1,    -1,    28,   109,    33,   133,    48,    -1,    59,    -1,
      -1,    59,   110,    33,   133,    48,    -1,    -1,    44,   111,
      33,   128,    48,    -1,     6,    99,    21,    -1,    29,   125,
      51,   100,   114,    -1,    20,   100,    -1,    -1,    47,    99,
      55,   125,    -1,    57,   125,    13,   100,    -1,    -1,    23,
      28,   118,     5,   125,   119,   125,    13,   100,    -1,    52,
      -1,    18,    -1,     7,   125,    39,   121,    21,    -1,   121,
     122,    -1,   122,    -1,    73,     9,   100,    49,    -1,    -1,
      28,   123,     9,   100,    49,    -1,    26,    30,    -1,   125,
      25,   126,    -1,   125,    27,   126,    -1,   125,    32,   126,
      -1,   125,    34,   126,    -1,   125,    22,   126,    -1,   125,
      54,   126,    -1,   126,    -1,   126,    40,   127,    -1,   126,
      35,   127,    -1,   126,    19,   127,    -1,   127,    -1,   127,
      37,   128,    -1,   127,    12,   128,    -1,   127,    36,   128,
      -1,   127,     3,   128,    -1,   128,    -1,    28,    -1,    -1,
      28,   129,    33,   133,    48,    -1,    58,    -1,    -1,    58,
     130,    33,   133,    48,    -1,    73,    -1,    33,   125,    48,
      -1,    38,   128,    -1,    35,   128,    -1,    -1,    28,   131,
      31,   125,    42,    -1,    -1,    28,   132,    16,    28,    -1,
     133,    10,   125,    -1,   125,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    38,    38,    45,    45,    50,    55,    60,    67,    72,
      74,    77,    79,    79,    85,    85,    93,    94,    95,    96,
      97,    99,   102,   104,   110,   117,   117,   122,   123,   124,
     126,   131,   136,   141,   148,   153,   157,   161,   165,   169,
     175,   183,   183,   189,   192,   194,   198,   205,   210,   215,
     220,   226,   232,   234,   234,   239,   239,   244,   248,   250,
     255,   262,   266,   270,   275,   279,   283,   290,   295,   297,
     297,   299,   301,   302,   303,   304,   305,   308,   309,   310,
     311,   313,   313,   319,   319,   324,   324,   324,   330,   331,
     331,   334,   335,   335,   337,   337,   341,   346,   351,   352,
     354,   359,   364,   364,   371,   372,   374,   379,   380,   382,
     383,   383,   386,   391,   392,   393,   394,   395,   396,   397,
     399,   400,   401,   402,   404,   405,   406,   407,   408,   410,
     411,   411,   413,   414,   414,   416,   417,   418,   419,   420,
     420,   422,   422,   425,   430
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
  "SYS_PROC", "MINUST", "$accept", "program", "program_head", "$@1",
  "routine", "name_list", "routine_head", "label_part", "const_part",
  "const_expr_list", "$@2", "$@3", "const_value", "type_part",
  "type_decl_list", "type_definition", "$@4", "type_decl",
  "array_type_decl", "record_type_decl", "field_decl_list", "field_decl",
  "simple_type_decl", "$@5", "var_part", "var_decl_list", "var_decl",
  "routine_part", "function_decl", "$@6", "procedure_decl", "$@7",
  "parameters", "para_decl_list", "para_type_list", "var_para_list",
  "val_para_list", "routine_body", "stmt_list", "stmt", "$@8",
  "non_label_stmt", "assign_stmt", "$@9", "$@10", "$@11", "$@12",
  "proc_stmt", "$@13", "$@14", "$@15", "compound_stmt", "if_stmt",
  "else_clause", "repeat_stmt", "while_stmt", "for_stmt", "$@16",
  "direction", "case_stmt", "case_expr_list", "case_expr", "$@17",
  "goto_stmt", "expression", "expr", "term", "factor", "$@18", "$@19",
  "$@20", "$@21", "args_list", YY_NULL
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
      94,    95,    95,    95,    96,    97,    98,    99,    99,   101,
     100,   100,   102,   102,   102,   102,   102,   102,   102,   102,
     102,   104,   103,   105,   103,   106,   107,   103,   108,   109,
     108,   108,   110,   108,   111,   108,   112,   113,   114,   114,
     115,   116,   118,   117,   119,   119,   120,   121,   121,   122,
     123,   122,   124,   125,   125,   125,   125,   125,   125,   125,
     126,   126,   126,   126,   127,   127,   127,   127,   127,   128,
     129,   128,   128,   130,   128,   128,   128,   128,   128,   131,
     128,   132,   128,   133,   133
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
       1,     3,     3,     1,     2,     1,     1,     3,     0,     0,
       4,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     4,     0,     7,     0,     0,     7,     1,     0,
       5,     1,     0,     5,     0,     5,     3,     5,     2,     0,
       4,     4,     0,     9,     1,     1,     5,     2,     1,     4,
       0,     5,     2,     3,     3,     3,     3,     3,     3,     1,
       3,     3,     3,     1,     3,     3,     3,     3,     1,     1,
       0,     5,     1,     0,     5,     1,     3,     2,     2,     0,
       5,     0,     4,     3,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     9,     3,     1,     0,     0,    11,     0,
       2,    68,     5,    66,     0,    22,     4,     0,    14,    10,
       0,    44,     0,    96,     0,     0,    88,     0,    69,    94,
      68,     0,    91,     0,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,     0,    12,    25,    21,    24,     0,
      52,    18,    20,   129,    16,     0,     0,     0,    17,    19,
     132,   135,     0,   119,   123,   128,   102,   112,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    67,     0,
       0,     0,    23,     7,     0,    43,    46,     0,     0,     8,
      50,    51,     0,     0,     0,     0,   138,   137,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    45,
      55,    53,    48,    49,     0,     0,     0,   136,     0,   117,
     113,   114,   115,   116,   110,     0,     0,   108,   118,   122,
     121,   120,   127,   125,   126,   124,     0,    82,     0,    86,
     144,     0,    99,    70,     0,   100,   101,     0,    15,     0,
       0,    36,     0,     0,    35,     0,     0,     0,    28,    29,
      27,     0,     6,    58,    58,     0,     0,   142,     0,     0,
       0,   106,   107,     0,     0,     0,     0,    90,     0,    97,
      95,    93,    13,     0,     0,     0,     0,     0,     0,    33,
       0,    26,    47,     0,     0,     0,   131,   140,   134,     0,
       0,   105,   104,     0,     0,     0,   143,    98,     0,     0,
      37,     0,     0,    31,    32,    38,     0,    65,     0,    60,
       0,    63,     9,     0,     0,   109,     0,    84,    87,     0,
      42,     0,    39,     0,    64,    57,     0,     0,     0,     0,
       0,   111,     0,     0,    40,    34,    59,    61,    62,    56,
       9,   103,    30,     0,    54
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     9,     6,    84,     7,     8,    15,    19,
      80,    44,    61,    21,    47,    48,    81,   177,   178,   179,
     208,   209,   180,   204,    50,    85,    86,    89,    90,   184,
      91,   183,   214,   238,   239,   240,   241,    12,    17,    33,
      73,    34,    35,    68,    69,    70,   195,    36,    71,    77,
      74,    37,    38,   199,    39,    40,    41,   113,   223,    42,
     146,   147,   189,    43,   160,    63,    64,    65,    92,    98,
      93,    94,   161
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -231
static const yytype_int16 yypact[] =
{
     -28,    25,    27,  -231,  -231,  -231,     9,    63,    66,    31,
    -231,  -231,  -231,  -231,    55,    32,  -231,    58,  -231,    68,
      69,    45,   192,  -231,    90,    89,   119,   192,  -231,  -231,
    -231,   192,    87,    91,  -231,  -231,  -231,  -231,  -231,  -231,
    -231,  -231,  -231,  -231,   116,  -231,  -231,    69,  -231,   114,
      51,  -231,  -231,   223,  -231,   192,   192,   192,  -231,  -231,
     108,  -231,   250,     1,   157,  -231,  -231,  -231,   140,   118,
     135,   123,   261,   152,   129,   100,    -3,   131,  -231,    59,
     146,   148,  -231,  -231,    33,   114,  -231,   143,   144,    51,
    -231,  -231,   145,   150,   161,   275,  -231,  -231,   149,   192,
     192,   192,   192,   192,    86,   192,   192,   192,   192,   192,
     192,   192,   192,   179,   192,   192,   159,   192,   160,   169,
     192,   192,   160,   192,   142,    59,   201,   201,   168,  -231,
    -231,  -231,  -231,  -231,   192,   192,   171,  -231,   192,     1,
       1,     1,     1,     1,  -231,   199,     7,  -231,     1,   157,
     157,   157,  -231,  -231,  -231,  -231,   192,   305,   286,  -231,
     305,     6,   190,  -231,   163,   305,  -231,     8,  -231,   165,
     181,   204,   114,    59,  -231,   114,   206,   183,  -231,  -231,
    -231,   184,  -231,   202,   202,    22,   292,  -231,    24,   232,
     160,  -231,  -231,   244,   243,   247,   192,  -231,   160,  -231,
    -231,  -231,  -231,   210,   240,    28,   248,    36,     2,  -231,
      59,  -231,  -231,   -17,   215,   258,  -231,  -231,  -231,   160,
     224,  -231,  -231,   192,   192,   192,   305,  -231,   217,   246,
    -231,   113,   201,  -231,  -231,  -231,   114,   269,    42,  -231,
     271,   272,  -231,   210,   238,  -231,   236,   305,   305,   252,
    -231,    59,  -231,   245,   269,  -231,   -17,   210,   210,   254,
     256,  -231,   160,   201,  -231,  -231,  -231,  -231,  -231,  -231,
    -231,  -231,  -231,   257,  -231
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -231,  -231,  -231,  -231,  -230,  -158,  -231,  -231,  -231,  -231,
    -231,  -231,   -78,  -231,  -231,   263,  -231,  -124,  -231,  -231,
    -231,    77,  -199,  -231,  -231,  -231,   207,  -231,   212,  -231,
     227,  -231,   115,  -231,    65,  -231,  -231,  -231,   295,  -116,
    -231,   203,  -231,  -231,  -231,  -231,  -231,  -231,  -231,  -231,
    -231,   324,  -231,  -231,  -231,  -231,  -231,  -231,  -231,  -231,
    -231,   187,  -231,  -231,   -22,   242,     4,   -49,  -231,  -231,
    -231,  -231,    -1
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -142
static const yytype_int16 yytable[] =
{
      62,   124,   162,   181,   228,    72,   166,    96,    97,    76,
     122,    83,   259,     1,   205,    51,   196,   207,   196,    99,
     106,    52,   100,   233,   101,    10,   145,     5,   191,   102,
      83,   103,   196,    95,   196,   144,   107,    54,   128,   236,
     273,   108,   127,   128,   260,   232,   128,   169,   176,   176,
     207,   105,    58,     4,   197,   237,   201,    59,   267,   268,
     152,   153,   154,   155,    11,    22,    87,    51,   145,    11,
     216,   164,   218,    52,   220,    88,   230,    14,   254,    23,
      16,    24,   227,    18,    25,    20,    26,    27,    28,    54,
     255,   256,   157,   158,    51,   206,    45,    46,   237,   165,
      52,    49,    29,   244,    58,    30,    11,    22,   253,    59,
     149,   150,   151,   186,   144,    31,    54,    32,    66,    67,
     -92,    51,   167,    24,   -81,   176,    25,    52,    26,    27,
      28,    58,   235,   185,   193,   -85,    59,   188,    79,   272,
      78,  -133,    83,    54,    29,   114,   271,    30,   251,   115,
     -83,   116,   -89,   252,   176,   121,   117,    31,    58,    32,
     109,   119,   120,    59,   123,   176,    11,    22,   125,   110,
     126,   130,   131,   264,   226,    11,    22,   136,   134,   176,
     176,   135,   138,    24,   156,   176,    25,   159,    26,    27,
      28,   168,    24,   111,   112,    25,   182,    26,    27,   187,
      51,   246,   247,   248,    29,   170,    52,    30,   190,    51,
     198,   200,   203,    29,   202,    52,    30,    31,    51,    32,
      53,   -41,    54,   210,    52,    55,    31,    56,    32,   171,
      57,    54,   211,   212,   172,   213,   173,    58,   171,  -141,
      54,   219,    59,   172,   174,   173,    58,   175,   224,   262,
      60,    59,   225,   174,  -139,    58,  -130,   229,    99,   249,
      59,   100,   221,   101,   242,   231,    99,   243,   102,   100,
     103,   101,    99,   245,   250,   100,   102,   101,   103,   128,
     257,   258,   102,    99,   103,   234,   100,   261,   101,   104,
     105,   263,   129,   102,   265,   103,   222,    99,   105,   215,
     100,   132,   101,   269,   105,   270,   274,   102,    99,   103,
      82,   100,   118,   101,    99,   105,   133,   100,   102,   101,
     103,   266,   163,   137,   102,    75,   103,    99,   194,   105,
     100,    13,   101,   192,   217,     0,     0,   102,     0,   103,
     105,   139,   140,   141,   142,   143,   105,   148,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   105
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-231)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      22,    79,   118,   127,   203,    27,   122,    56,    57,    31,
      13,    28,   242,    41,   172,     8,    10,   175,    10,    22,
      19,    14,    25,    21,    27,    16,   104,     0,    21,    32,
      28,    34,    10,    55,    10,    28,    35,    30,    10,    56,
     270,    40,     9,    10,   243,     9,    10,   125,   126,   127,
     208,    54,    45,    28,    48,   213,    48,    50,   257,   258,
     109,   110,   111,   112,     6,     7,    15,     8,   146,     6,
      48,   120,    48,    14,   190,    24,    48,    11,   236,    21,
      49,    23,   198,    28,    26,    53,    28,    29,    30,    30,
      48,    49,   114,   115,     8,   173,    28,    28,   256,   121,
      14,    56,    44,   219,    45,    47,     6,     7,   232,    50,
     106,   107,   108,   135,    28,    57,    30,    59,    28,    30,
      33,     8,   123,    23,     5,   203,    26,    14,    28,    29,
      30,    45,   210,   134,   156,    16,    50,   138,    22,   263,
      49,    33,    28,    30,    44,     5,   262,    47,    35,    31,
      31,    16,    33,   231,   232,    55,    33,    57,    45,    59,
       3,     9,    33,    50,    33,   243,     6,     7,    22,    12,
      22,    28,    28,   251,   196,     6,     7,    16,    33,   257,
     258,    31,    33,    23,     5,   263,    26,    28,    28,    29,
      30,    49,    23,    36,    37,    26,    28,    28,    29,    28,
       8,   223,   224,   225,    44,     4,    14,    47,     9,     8,
      20,    48,    31,    44,    49,    14,    47,    57,     8,    59,
      28,    17,    30,    17,    14,    33,    57,    35,    59,    28,
      38,    30,    49,    49,    33,    33,    35,    45,    28,    16,
      30,     9,    50,    33,    43,    35,    45,    46,     5,    13,
      58,    50,     5,    43,    31,    45,    33,    17,    22,    42,
      50,    25,    18,    27,    49,    17,    22,     9,    32,    25,
      34,    27,    22,    49,    28,    25,    32,    27,    34,    10,
       9,     9,    32,    22,    34,   208,    25,    49,    27,    39,
      54,    39,    85,    32,    49,    34,    52,    22,    54,   184,
      25,    89,    27,    49,    54,    49,    49,    32,    22,    34,
      47,    25,    51,    27,    22,    54,    89,    25,    32,    27,
      34,   256,   119,    48,    32,    30,    34,    22,    42,    54,
      25,     7,    27,   146,    42,    -1,    -1,    32,    -1,    34,
      54,    99,   100,   101,   102,   103,    54,   105,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    54
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    41,    62,    63,    28,     0,    65,    67,    68,    64,
      16,     6,    98,   112,    11,    69,    49,    99,    28,    70,
      53,    74,     7,    21,    23,    26,    28,    29,    30,    44,
      47,    57,    59,   100,   102,   103,   108,   112,   113,   115,
     116,   117,   120,   124,    72,    28,    28,    75,    76,    56,
      85,     8,    14,    28,    30,    33,    35,    38,    45,    50,
      58,    73,   125,   126,   127,   128,    28,    30,   104,   105,
     106,   109,   125,   101,   111,    99,   125,   110,    49,    22,
      71,    77,    76,    28,    66,    86,    87,    15,    24,    88,
      89,    91,   129,   131,   132,   125,   128,   128,   130,    22,
      25,    27,    32,    34,    39,    54,    19,    35,    40,     3,
      12,    36,    37,   118,     5,    31,    16,    33,    51,     9,
      33,    55,    13,    33,    73,    22,    22,     9,    10,    87,
      28,    28,    89,    91,    33,    31,    16,    48,    33,   126,
     126,   126,   126,   126,    28,    73,   121,   122,   126,   127,
     127,   127,   128,   128,   128,   128,     5,   125,   125,    28,
     125,   133,   100,   102,   128,   125,   100,   133,    49,    73,
       4,    28,    33,    35,    43,    46,    73,    78,    79,    80,
      83,    78,    28,    92,    90,   133,   125,    28,   133,   123,
       9,    21,   122,   125,    42,   107,    10,    48,    20,   114,
      48,    48,    49,    31,    84,    66,    73,    66,    81,    82,
      17,    49,    49,    33,    93,    93,    48,    42,    48,     9,
     100,    18,    52,   119,     5,     5,   125,   100,    83,    17,
      48,    17,     9,    21,    82,    73,    56,    66,    94,    95,
      96,    97,    49,     9,   100,    49,   125,   125,   125,    42,
      28,    35,    73,    78,    66,    48,    49,     9,     9,    65,
      83,    49,    13,    39,    73,    49,    95,    83,    83,    49,
      49,   100,    78,    65,    49
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
#line 38 "parser.y"
    {
tp("pargram");
root = new ProgramTreeNode(((ProgramHeadTreeNode*)(yyvsp[(1) - (3)]))->getName(), (RoutineTreeNode *)(yyvsp[(2) - (3)]));
(yyval) = root;
;
}
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 45 "parser.y"
    { name = currentToken; }
    break;

  case 4:
/* Line 1792 of yacc.c  */
#line 45 "parser.y"
    {
  tp("program head");
  (yyval) = new ProgramHeadTreeNode(currentToken);
}
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 50 "parser.y"
    {
  tp("routine");
  (yyval) = new RoutineTreeNode((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
}
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 55 "parser.y"
    {
  tp("name list 1");
  (yyval) = (yyvsp[(1) - (3)]);
  (yyval)->insert(new TreeNode(currentToken));
}
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 60 "parser.y"
    {
   tp("name list 2");
   vector<TreeNode *> list;
   list.push_back(new TreeNode(currentToken));
   (yyval) = new ListTreeNode("name_list", list);
}
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 67 "parser.y"
    {
   tp("routine head");
   (yyval) = new RoutineHeadTreeNode((yyvsp[(2) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(4) - (5)]), (yyvsp[(5) - (5)]));
}
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 72 "parser.y"
    {}
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 74 "parser.y"
    {
  tp("const part1");
  (yyval) = (yyvsp[(2) - (2)]);
}
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 77 "parser.y"
    {tp("const part 2"); (yyval) = new ListTreeNode("non const part");}
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 79 "parser.y"
    { name = currentToken; }
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 80 "parser.y"
    {
  tp("const expr list 1");
  (yyval) = (yyvsp[(1) - (6)]);
  (yyval)->insert(new ConstTreeNode(name, (yyvsp[(5) - (6)])));
}
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 85 "parser.y"
    {name = currentToken;}
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 86 "parser.y"
    {
  tp("const expr list 2");
  vector<TreeNode *> list;
  (yyval) = new ListTreeNode("const_value_list",list);
  (yyval)->insert(new ConstTreeNode(name, (yyvsp[(4) - (5)])));
}
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 93 "parser.y"
    {tp("const value 1");(yyval) = new NumberTreeNode<int>(atoi(currentToken), "integer");}
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 94 "parser.y"
    {tp("const value 2");(yyval) = new NumberTreeNode<double>(atof(currentToken), "real");}
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 95 "parser.y"
    {tp("const value 3");(yyval) = new NumberTreeNode<char>(currentToken[0], "char");}
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 96 "parser.y"
    {tp("const value 4");(yyval) = new NumberTreeNode<string>(currentToken, "string");}
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 97 "parser.y"
    {tp("const value 5");(yyval) = new NumberTreeNode<string>(currentToken, "sys_con");}
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 99 "parser.y"
    {
  tp("type part 1");
  (yyval) = (yyvsp[(2) - (2)]);
}
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 102 "parser.y"
    {tp("type part 2"); (yyval) = new ListTreeNode("non type part");}
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 105 "parser.y"
    {
  tp("type_decl_list 1");
  (yyval) = (yyvsp[(1) - (2)]);
  (yyval)->insert((yyvsp[(2) - (2)]));
}
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 110 "parser.y"
    {
  tp("type_decl_list 2");
  vector<TreeNode *> list;
  list.push_back((yyvsp[(1) - (1)]));
  (yyval) = new ListTreeNode("type_decl_list",list);
}
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 117 "parser.y"
    {name = currentToken;}
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 117 "parser.y"
    {
  tp("type_definition");
  (yyval) = new CustomTypeTreeNode(name, (yyvsp[(4) - (5)]));
}
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 122 "parser.y"
    {tp("type_decl 1");(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 123 "parser.y"
    {tp("type_decl 2");(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 124 "parser.y"
    {tp("type_decl 3");(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 126 "parser.y"
    {
  tp("array_type_decl");
  (yyval) = new ArrayTypeTreeNode((yyvsp[(3) - (6)]),(yyvsp[(6) - (6)]));
}
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 131 "parser.y"
    {
  tp("record_type_decl");
  (yyval) = new RecordTypeTreeNode((yyvsp[(2) - (3)]));
}
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 136 "parser.y"
    {
  tp("field_decl_list 1");
  (yyval) = (yyvsp[(1) - (2)]);
  (yyval)->insert((yyvsp[(2) - (2)]));
}
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 141 "parser.y"
    {
  tp("field_decl_list 2");
  vector<TreeNode *> list;
  list.push_back((yyvsp[(1) - (1)]));
  (yyval) = new ListTreeNode("field_decl_list",list);
}
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 148 "parser.y"
    {
  tp("field_decl");
  (yyval) = new VariableTreeNode((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
}
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 153 "parser.y"
    {                
                  tp("simple_type_decl 1");
                  (yyval) = new SysTypeTreeNode(currentToken);
                }
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 157 "parser.y"
    {
                  tp("simple_type_decl 2");                
                  (yyval) = new CustomTypeTreeNode(currentToken);
                }
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 161 "parser.y"
    {
                  tp("simple_type_decl 3");                
                  (yyval) = new EnumTypeTreeNode((yyvsp[(2) - (3)]));
                }
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 165 "parser.y"
    {
                  tp("simple_type_decl 4");                
                  (yyval) = new SubRangeTypeTreeNode((yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]));
                }
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 169 "parser.y"
    {
                  tp("simple_type_decl 5");                
                  NumberTreeNode<int>* n = (NumberTreeNode<int>*)(yyvsp[(1) - (4)]);
                  n->set(-(int)(n->get()));
                  (yyval) = new SubRangeTypeTreeNode((yyvsp[(1) - (4)]),(yyvsp[(3) - (4)]));
                }
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 175 "parser.y"
    {
                  tp("simple_type_decl 6");                
                  NumberTreeNode<int>* n1 = (NumberTreeNode<int>*)(yyvsp[(1) - (5)]);
                  NumberTreeNode<int>* n2 = (NumberTreeNode<int>*)(yyvsp[(2) - (5)]);
                  n1->set(-(int)(n1->get()));
                  n2->set(-(int)(n2->get()));
                  (yyval) = new SubRangeTypeTreeNode((yyvsp[(1) - (5)]),(yyvsp[(3) - (5)])); 
                }
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 183 "parser.y"
    {s1 = currentToken;}
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 183 "parser.y"
    {
                  tp("simple_type_decl 7");                
                  s2 = currentToken;
                  (yyval) = new RecordElemTreeNode(s1, s2);
                }
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 189 "parser.y"
    {
  tp("var part 1");
  (yyval) = (yyvsp[(2) - (2)]);
}
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 192 "parser.y"
    {tp("var part 2");(yyval) = new ListTreeNode("non var part");}
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 194 "parser.y"
    {
  tp("var_decl_list 1");
  (yyval) = (yyvsp[(1) - (2)]);
  (yyval)->insert((yyvsp[(2) - (2)]));
}
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 198 "parser.y"
    {
  tp("var_decl_list 2");
  vector<TreeNode *> list;
  list.push_back((yyvsp[(1) - (1)]));
  (yyval) = new ListTreeNode("var_decl_list",list);
}
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 205 "parser.y"
    {
  tp("var_decl");
  (yyval) = new VariableTreeNode((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]), 1);
}
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 210 "parser.y"
    {
                tp("routine part 1");
                (yyval) = (yyvsp[(1) - (2)]);
                (yyval)->insert((yyvsp[(2) - (2)]));
              }
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 215 "parser.y"
    {
              tp("routine part 2");
              (yyval) = (yyvsp[(1) - (2)]);
              (yyval)->insert((yyvsp[(2) - (2)]));
              }
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 220 "parser.y"
    {
                tp("routine part 3");
                vector<TreeNode *> list;
                list.push_back((yyvsp[(1) - (1)]));
                (yyval) = new ListTreeNode("function_decl_list",list);
              }
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 226 "parser.y"
    {
                tp("routine part 4");            
                vector<TreeNode *> list;
                list.push_back((yyvsp[(1) - (1)]));
                (yyval) = new ListTreeNode("procedure_decl_list",list);
            }
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 232 "parser.y"
    {tp("routine part 5");(yyval) = new ListTreeNode("non routine part");}
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 234 "parser.y"
    {name = currentToken;}
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 234 "parser.y"
    {
  tp("function decl");  
  (yyval) = new FunctionTreeNode(name, (yyvsp[(4) - (9)]), (yyvsp[(6) - (9)]), (yyvsp[(8) - (9)]));
}
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 239 "parser.y"
    {name = currentToken;}
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 239 "parser.y"
    {
  tp("procedure decl");
  (yyval) = new ProcedureTreeNode(name, (yyvsp[(4) - (7)]), (yyvsp[(6) - (7)])); 
}
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 244 "parser.y"
    {
  tp("paramters 1");
  (yyval) = (yyvsp[(2) - (3)]); 
}
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 248 "parser.y"
    {tp("paramters 2");(yyval) = NULL;}
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 250 "parser.y"
    {
  tp("para_decl_list 1");
  (yyval) = (yyvsp[(1) - (3)]);
  (yyval)->insert((yyvsp[(3) - (3)]));
}
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 255 "parser.y"
    {
  tp("para_decl_list 2");
  vector<TreeNode *> list;
  list.push_back((yyvsp[(1) - (1)]));
  (yyval) = new ListTreeNode("para_type_list",list);
}
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 262 "parser.y"
    {
  tp("para_type_list 1");
  (yyval) = new VariableTreeNode((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]),1);
}
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 266 "parser.y"
    {
  tp("para_type_list 2");
  (yyval) = new VariableTreeNode((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), 0); 
}
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 270 "parser.y"
    {
  tp("para_type_list 3");
  (yyval) = new VariableTreeNode((yyvsp[(1) - (1)]));  
}
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 275 "parser.y"
    {
  tp("var_para_list");
  (yyval) = (yyvsp[(2) - (2)]);
}
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 279 "parser.y"
    {
  tp("val_para_list");
  (yyval) = (yyvsp[(1) - (1)]);
}
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 283 "parser.y"
    {
  tp("routine_body");
  (yyval) = (yyvsp[(1) - (1)]);
}
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 290 "parser.y"
    {
    tp("stmt list 1");
    (yyval) = (yyvsp[(1) - (3)]);
  	(yyval)->insert((yyvsp[(2) - (3)]));
}
    break;

  case 68:
/* Line 1792 of yacc.c  */
#line 295 "parser.y"
    {tp("stmt list 2");(yyval) = new ListTreeNode("stmt");}
    break;

  case 69:
/* Line 1792 of yacc.c  */
#line 297 "parser.y"
    {x = atoi(currentToken);}
    break;

  case 70:
/* Line 1792 of yacc.c  */
#line 298 "parser.y"
    {tp("stmt 1");(yyval) = (yyvsp[(3) - (4)]);((StmtTreeNode*)(yyval))->setLabel(x);}
    break;

  case 71:
/* Line 1792 of yacc.c  */
#line 299 "parser.y"
    {tp("stmt 2");(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 72:
/* Line 1792 of yacc.c  */
#line 301 "parser.y"
    {tp("non_label_stmt 1");(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 73:
/* Line 1792 of yacc.c  */
#line 302 "parser.y"
    {tp("non_label_stmt 2");(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 74:
/* Line 1792 of yacc.c  */
#line 303 "parser.y"
    {tp("non_label_stmt 3");(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 75:
/* Line 1792 of yacc.c  */
#line 304 "parser.y"
    {tp("non_label_stmt 4");(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 76:
/* Line 1792 of yacc.c  */
#line 305 "parser.y"
    {tp("non_label_stmt 5");(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 77:
/* Line 1792 of yacc.c  */
#line 308 "parser.y"
    {tp("non_label_stmt 6");(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 78:
/* Line 1792 of yacc.c  */
#line 309 "parser.y"
    {tp("non_label_stmt 7");(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 79:
/* Line 1792 of yacc.c  */
#line 310 "parser.y"
    {tp("non_label_stmt 8");(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 80:
/* Line 1792 of yacc.c  */
#line 311 "parser.y"
    {tp("non_label_stmt 9");(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 81:
/* Line 1792 of yacc.c  */
#line 313 "parser.y"
    {s = idstr;}
    break;

  case 82:
/* Line 1792 of yacc.c  */
#line 313 "parser.y"
    {
                tp("assign stmt 1");
                cout << "name = " << idstr;
                VariableTreeNode* x = new VariableTreeNode(s);
                (yyval) = new BinaryExprTreeNode("=",x,(yyvsp[(4) - (4)]));
            }
    break;

  case 83:
/* Line 1792 of yacc.c  */
#line 319 "parser.y"
    {s = idstr;}
    break;

  case 84:
/* Line 1792 of yacc.c  */
#line 319 "parser.y"
    {
                tp("assign stmt 2");
                TreeNode* x = new ArrayElemTreeNode(s,(yyvsp[(4) - (7)]));
                (yyval) = new BinaryExprTreeNode("=",x,(yyvsp[(7) - (7)]));
            }
    break;

  case 85:
/* Line 1792 of yacc.c  */
#line 324 "parser.y"
    {s1 = idstr;}
    break;

  case 86:
/* Line 1792 of yacc.c  */
#line 324 "parser.y"
    {s2 = idstr;}
    break;

  case 87:
/* Line 1792 of yacc.c  */
#line 324 "parser.y"
    {
                tp("assign stmt 3");
                TreeNode* x = new RecordElemTreeNode(s1,s2);
                (yyval) = new BinaryExprTreeNode("=",x,(yyvsp[(7) - (7)]));
            }
    break;

  case 88:
/* Line 1792 of yacc.c  */
#line 330 "parser.y"
    {tp("proc_stmt 1");(yyval) = new CallExprTreeNode(currentToken);}
    break;

  case 89:
/* Line 1792 of yacc.c  */
#line 331 "parser.y"
    {s = currentToken;}
    break;

  case 90:
/* Line 1792 of yacc.c  */
#line 332 "parser.y"
    {//cout << $1 << "," << $2 << ","<< $3 << "," << $4 << $5;
          tp("proc_stmt 2");(yyval) = new CallExprTreeNode(s,((ListTreeNode*)(yyvsp[(4) - (5)]))->getList());}
    break;

  case 91:
/* Line 1792 of yacc.c  */
#line 334 "parser.y"
    {tp("proc_stmt 3");(yyval) = new CallExprTreeNode(currentToken);}
    break;

  case 92:
/* Line 1792 of yacc.c  */
#line 335 "parser.y"
    {s = currentToken;}
    break;

  case 93:
/* Line 1792 of yacc.c  */
#line 336 "parser.y"
    {tp("proc_stmt 4");(yyval) = new CallExprTreeNode(s,((ListTreeNode*)(yyvsp[(4) - (5)]))->getList());}
    break;

  case 94:
/* Line 1792 of yacc.c  */
#line 337 "parser.y"
    {s = currentToken;}
    break;

  case 95:
/* Line 1792 of yacc.c  */
#line 338 "parser.y"
    {tp("proc_stmt 5");(yyval) = new CallExprTreeNode(s,((ListTreeNode*)(yyvsp[(4) - (5)]))->getList());}
    break;

  case 96:
/* Line 1792 of yacc.c  */
#line 341 "parser.y"
    {
    tp("compound stmt");
    (yyval) = new CompoundStmtTreeNode((yyvsp[(2) - (3)]));
}
    break;

  case 97:
/* Line 1792 of yacc.c  */
#line 346 "parser.y"
    {
    tp("if stmt");
    (yyval) = new IfStmtTreeNode((yyvsp[(2) - (5)]),(yyvsp[(4) - (5)]),(yyvsp[(5) - (5)]));
}
    break;

  case 98:
/* Line 1792 of yacc.c  */
#line 351 "parser.y"
    {tp("else clause 1");(yyval) = (yyvsp[(2) - (2)]);}
    break;

  case 99:
/* Line 1792 of yacc.c  */
#line 352 "parser.y"
    {tp("else clause 2");(yyval) = NULL;}
    break;

  case 100:
/* Line 1792 of yacc.c  */
#line 354 "parser.y"
    {
    tp("repeat stmt");
    (yyval) = new RepeatStmtTreeNode((yyvsp[(2) - (4)]),(yyvsp[(4) - (4)]));
}
    break;

  case 101:
/* Line 1792 of yacc.c  */
#line 359 "parser.y"
    {
    tp("while stmt");
    (yyval) = new WhileStmtTreeNode((yyvsp[(4) - (4)]),(yyvsp[(2) - (4)]));
}
    break;

  case 102:
/* Line 1792 of yacc.c  */
#line 364 "parser.y"
    {name = currentToken;}
    break;

  case 103:
/* Line 1792 of yacc.c  */
#line 364 "parser.y"
    {
    tp("for stmt");
    VariableTreeNode * v = new VariableTreeNode(name);
    BinaryExprTreeNode *be = new BinaryExprTreeNode(":=",v,(yyvsp[(5) - (9)]));
    (yyval) = new ForStmtTreeNode(be,(yyvsp[(6) - (9)])->getName(),(yyvsp[(7) - (9)]),(yyvsp[(9) - (9)]));
}
    break;

  case 104:
/* Line 1792 of yacc.c  */
#line 371 "parser.y"
    {(yyval) = new TreeNode("to");}
    break;

  case 105:
/* Line 1792 of yacc.c  */
#line 372 "parser.y"
    {(yyval) = new TreeNode("downto");}
    break;

  case 106:
/* Line 1792 of yacc.c  */
#line 374 "parser.y"
    {
    tp("case stmt");
    (yyval) = new SwitchStmtTreeNode((yyvsp[(2) - (5)]),(yyvsp[(4) - (5)]));
}
    break;

  case 107:
/* Line 1792 of yacc.c  */
#line 379 "parser.y"
    {tp("case expr list 1");(yyval) = (yyvsp[(1) - (2)]); (yyval)->insert((yyvsp[(2) - (2)]));}
    break;

  case 108:
/* Line 1792 of yacc.c  */
#line 380 "parser.y"
    {tp("case expr list 2");(yyval) = new ListTreeNode("case"); (yyval)->insert((yyvsp[(1) - (1)]));}
    break;

  case 109:
/* Line 1792 of yacc.c  */
#line 382 "parser.y"
    {tp("case expr 1");(yyval) = new CaseExprTreeNode((yyvsp[(1) - (4)]),(yyvsp[(3) - (4)]));}
    break;

  case 110:
/* Line 1792 of yacc.c  */
#line 383 "parser.y"
    {id = new VariableTreeNode(currentToken);}
    break;

  case 111:
/* Line 1792 of yacc.c  */
#line 384 "parser.y"
    {tp("case expr 2");(yyval) = new CaseExprTreeNode(id,(yyvsp[(4) - (5)]));}
    break;

  case 112:
/* Line 1792 of yacc.c  */
#line 386 "parser.y"
    {
    tp("got stmt");
    (yyval) = new GotoStmtTreeNode(currentToken);
}
    break;

  case 113:
/* Line 1792 of yacc.c  */
#line 391 "parser.y"
    {tp("expression 1");(yyval) = new BinaryExprTreeNode(">=",(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]));}
    break;

  case 114:
/* Line 1792 of yacc.c  */
#line 392 "parser.y"
    {tp("expressoin 2");(yyval) = new BinaryExprTreeNode(">",(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]));}
    break;

  case 115:
/* Line 1792 of yacc.c  */
#line 393 "parser.y"
    {tp("expression 3");(yyval) = new BinaryExprTreeNode("<=",(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]));}
    break;

  case 116:
/* Line 1792 of yacc.c  */
#line 394 "parser.y"
    {tp("expression 4");(yyval) = new BinaryExprTreeNode("<",(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]));}
    break;

  case 117:
/* Line 1792 of yacc.c  */
#line 395 "parser.y"
    {tp("expression 5");(yyval) = new BinaryExprTreeNode("==",(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]));}
    break;

  case 118:
/* Line 1792 of yacc.c  */
#line 396 "parser.y"
    {tp("expression 6");(yyval) = new BinaryExprTreeNode("!=",(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]));}
    break;

  case 119:
/* Line 1792 of yacc.c  */
#line 397 "parser.y"
    {tp("expression 7");(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 120:
/* Line 1792 of yacc.c  */
#line 399 "parser.y"
    {tp("expr 1");(yyval) = new BinaryExprTreeNode("+",(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]));}
    break;

  case 121:
/* Line 1792 of yacc.c  */
#line 400 "parser.y"
    {tp("expr 2");(yyval) = new BinaryExprTreeNode("-",(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]));}
    break;

  case 122:
/* Line 1792 of yacc.c  */
#line 401 "parser.y"
    {tp("expr 3");(yyval) = new BinaryExprTreeNode("||",(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]));}
    break;

  case 123:
/* Line 1792 of yacc.c  */
#line 402 "parser.y"
    {tp("expr 4");(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 124:
/* Line 1792 of yacc.c  */
#line 404 "parser.y"
    {tp("term 1");(yyval) = new BinaryExprTreeNode("*",(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]));}
    break;

  case 125:
/* Line 1792 of yacc.c  */
#line 405 "parser.y"
    {tp("term 2");(yyval) = new BinaryExprTreeNode("/",(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]));}
    break;

  case 126:
/* Line 1792 of yacc.c  */
#line 406 "parser.y"
    {tp("term 3");(yyval) = new BinaryExprTreeNode("%",(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]));}
    break;

  case 127:
/* Line 1792 of yacc.c  */
#line 407 "parser.y"
    {tp("term 4");(yyval) = new BinaryExprTreeNode("&&",(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]));}
    break;

  case 128:
/* Line 1792 of yacc.c  */
#line 408 "parser.y"
    {tp("term 5");(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 129:
/* Line 1792 of yacc.c  */
#line 410 "parser.y"
    {tp("factor 1");(yyval) = new VariableTreeNode(currentToken);}
    break;

  case 130:
/* Line 1792 of yacc.c  */
#line 411 "parser.y"
    {s = currentToken;}
    break;

  case 131:
/* Line 1792 of yacc.c  */
#line 412 "parser.y"
    {tp("factor 2");(yyval) = new CallExprTreeNode(s,((ListTreeNode*)(yyvsp[(4) - (5)]))->getList());}
    break;

  case 132:
/* Line 1792 of yacc.c  */
#line 413 "parser.y"
    {tp("factor 3");(yyval) = new CallExprTreeNode(currentToken);}
    break;

  case 133:
/* Line 1792 of yacc.c  */
#line 414 "parser.y"
    {s = currentToken;}
    break;

  case 134:
/* Line 1792 of yacc.c  */
#line 415 "parser.y"
    {tp("factor 4");(yyval) = new CallExprTreeNode(s,((ListTreeNode*)(yyvsp[(4) - (5)]))->getList());}
    break;

  case 135:
/* Line 1792 of yacc.c  */
#line 416 "parser.y"
    {tp("factor 5");(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 136:
/* Line 1792 of yacc.c  */
#line 417 "parser.y"
    {tp("factor 6");(yyval) = (yyvsp[(2) - (3)]);}
    break;

  case 137:
/* Line 1792 of yacc.c  */
#line 418 "parser.y"
    {tp("factor 7");(yyval) = new UnaryExprTreeNode("~",(yyvsp[(2) - (2)]));}
    break;

  case 138:
/* Line 1792 of yacc.c  */
#line 419 "parser.y"
    {tp("factor 8");(yyval) = new UnaryExprTreeNode("-",(yyvsp[(2) - (2)]));}
    break;

  case 139:
/* Line 1792 of yacc.c  */
#line 420 "parser.y"
    {s = currentToken;}
    break;

  case 140:
/* Line 1792 of yacc.c  */
#line 421 "parser.y"
    {tp("factor 9");(yyval) = new ArrayElemTreeNode(s,(yyvsp[(4) - (5)]));}
    break;

  case 141:
/* Line 1792 of yacc.c  */
#line 422 "parser.y"
    {s1 = currentToken;}
    break;

  case 142:
/* Line 1792 of yacc.c  */
#line 423 "parser.y"
    {tp("factor 10");s2 = currentToken; (yyval) = new RecordElemTreeNode(s1,s2);}
    break;

  case 143:
/* Line 1792 of yacc.c  */
#line 425 "parser.y"
    {
    tp("args_list 1");
    (yyval) = (yyvsp[(1) - (3)]);
    (yyval)->insert((yyvsp[(3) - (3)]));
}
    break;

  case 144:
/* Line 1792 of yacc.c  */
#line 430 "parser.y"
    {tp("args_list 2"); (yyval) = new ListTreeNode("args_list");  (yyval)->insert((yyvsp[(1) - (1)]));}
    break;


/* Line 1792 of yacc.c  */
#line 2763 "parser.cpp"
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
#line 434 "parser.y"

static int yylex() {
  return getToken();
}

static void tp(const string msg) {
  if(traceParse) {parserOut << lineno << " " << msg  << endl;}
}
//main() 
//{
//  traceScan = TRUE;
//  yyparse();
//  printAST(root);
//  return 0;
//}



int yyerror(string s) {
	fprintf(stderr, "%s\n", s.c_str());
	return 0;
}

