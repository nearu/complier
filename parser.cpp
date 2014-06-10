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
#include "code_generator.h"
using namespace std;
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
extern string curLine;
extern LabelManager *labelManager;
ProgramTreeNode *root;
int traceParse = TRUE;
ofstream parserOut("parserOut");

/* Line 371 of yacc.c  */
#line 100 "parser.cpp"

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
#line 223 "parser.cpp"

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
#define YYLAST   372

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  61
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  56
/* YYNRULES -- Number of rules.  */
#define YYNRULES  127
/* YYNRULES -- Number of states.  */
#define YYNSTATES  259

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
       0,     0,     3,     7,    11,    14,    18,    20,    26,    27,
      30,    31,    37,    42,    44,    46,    48,    50,    52,    55,
      56,    59,    61,    66,    68,    70,    72,    79,    83,    86,
      88,    93,    95,    97,   101,   105,   110,   116,   120,   123,
     124,   127,   129,   134,   137,   140,   142,   144,   145,   154,
     161,   165,   168,   172,   174,   178,   182,   184,   187,   189,
     191,   195,   196,   197,   202,   204,   206,   208,   210,   212,
     214,   216,   218,   220,   222,   226,   233,   239,   241,   246,
     248,   253,   258,   262,   268,   271,   272,   277,   282,   283,
     293,   295,   297,   303,   306,   308,   313,   314,   320,   323,
     327,   331,   335,   339,   343,   347,   349,   353,   357,   361,
     363,   367,   371,   375,   379,   381,   383,   388,   390,   391,
     397,   399,   403,   406,   409,   414,   418,   422
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      62,     0,    -1,    63,    64,    16,    -1,    41,    28,    49,
      -1,    66,    91,    -1,    65,    10,    28,    -1,    28,    -1,
      67,    68,    71,    80,    83,    -1,    -1,    11,    69,    -1,
      -1,    69,    28,    22,    70,    49,    -1,    28,    22,    70,
      49,    -1,    30,    -1,    45,    -1,     8,    -1,    50,    -1,
      14,    -1,    53,    72,    -1,    -1,    72,    73,    -1,    73,
      -1,    28,    22,    74,    49,    -1,    79,    -1,    75,    -1,
      76,    -1,     4,    31,    79,    42,    39,    74,    -1,    46,
      77,    21,    -1,    77,    78,    -1,    78,    -1,    65,     9,
      74,    49,    -1,    43,    -1,    28,    -1,    33,    65,    48,
      -1,    70,    17,    70,    -1,    35,    70,    17,    70,    -1,
      35,    70,    17,    35,    70,    -1,    28,    17,    28,    -1,
      56,    81,    -1,    -1,    81,    82,    -1,    82,    -1,    65,
       9,    74,    49,    -1,    83,    84,    -1,    83,    85,    -1,
      84,    -1,    85,    -1,    -1,    24,    28,    86,     9,    79,
      49,    64,    49,    -1,    15,    28,    86,    49,    64,    49,
      -1,    33,    87,    48,    -1,    33,    48,    -1,    87,    49,
      88,    -1,    88,    -1,    89,     9,    79,    -1,    90,     9,
      79,    -1,    90,    -1,    56,    65,    -1,    65,    -1,    98,
      -1,    92,    93,    49,    -1,    -1,    -1,    30,    94,     9,
      95,    -1,    95,    -1,    96,    -1,    97,    -1,    98,    -1,
      99,    -1,   101,    -1,   102,    -1,   103,    -1,   106,    -1,
     110,    -1,    28,     5,   111,    -1,    28,    31,   111,    42,
       5,   111,    -1,    28,    16,    28,     5,   111,    -1,    28,
      -1,    28,    33,   116,    48,    -1,    59,    -1,    59,    33,
     116,    48,    -1,    44,    33,   114,    48,    -1,     6,    92,
      21,    -1,    29,   111,    51,    93,   100,    -1,    20,    93,
      -1,    -1,    47,    92,    55,   111,    -1,    57,   111,    13,
      93,    -1,    -1,    23,    28,   104,     5,   111,   105,   111,
      13,    93,    -1,    52,    -1,    18,    -1,     7,   111,    39,
     107,    21,    -1,   107,   108,    -1,   108,    -1,    70,     9,
      93,    49,    -1,    -1,    28,   109,     9,    93,    49,    -1,
      26,    30,    -1,   111,    25,   112,    -1,   111,    27,   112,
      -1,   111,    32,   112,    -1,   111,    34,   112,    -1,   111,
      22,   112,    -1,   111,    54,   112,    -1,   112,    -1,   112,
      40,   113,    -1,   112,    35,   113,    -1,   112,    19,   113,
      -1,   113,    -1,   113,    37,   114,    -1,   113,    12,   114,
      -1,   113,    36,   114,    -1,   113,     3,   114,    -1,   114,
      -1,    28,    -1,    28,    33,   116,    48,    -1,    58,    -1,
      -1,    58,   115,    33,   116,    48,    -1,    70,    -1,    33,
     111,    48,    -1,    38,   114,    -1,    35,   114,    -1,    28,
      31,   111,    42,    -1,    28,    16,    28,    -1,   116,    10,
     111,    -1,   111,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    39,    39,    46,    51,    56,    61,    68,    73,    75,
      78,    80,    86,    93,    94,    97,    98,   101,   103,   106,
     108,   114,   121,   126,   127,   128,   130,   135,   140,   145,
     152,   157,   161,   165,   169,   173,   180,   189,   194,   197,
     199,   203,   210,   215,   220,   225,   231,   237,   239,   244,
     249,   253,   255,   260,   267,   271,   275,   280,   284,   288,
     295,   300,   302,   302,   304,   306,   307,   308,   309,   310,
     312,   313,   314,   315,   317,   322,   327,   333,   334,   335,
     336,   337,   340,   345,   350,   351,   353,   358,   363,   363,
     371,   372,   374,   379,   380,   382,   383,   383,   386,   391,
     392,   393,   394,   395,   396,   397,   399,   400,   401,   402,
     404,   405,   406,   407,   408,   410,   411,   414,   415,   415,
     417,   418,   419,   420,   421,   422,   425,   430
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
  "SYS_PROC", "MINUST", "$accept", "program", "program_head", "routine",
  "name_list", "routine_head", "label_part", "const_part",
  "const_expr_list", "const_value", "type_part", "type_decl_list",
  "type_definition", "type_decl", "array_type_decl", "record_type_decl",
  "field_decl_list", "field_decl", "simple_type_decl", "var_part",
  "var_decl_list", "var_decl", "routine_part", "function_decl",
  "procedure_decl", "parameters", "para_decl_list", "para_type_list",
  "var_para_list", "val_para_list", "routine_body", "stmt_list", "stmt",
  "$@1", "non_label_stmt", "assign_stmt", "proc_stmt", "compound_stmt",
  "if_stmt", "else_clause", "repeat_stmt", "while_stmt", "for_stmt", "$@2",
  "direction", "case_stmt", "case_expr_list", "case_expr", "$@3",
  "goto_stmt", "expression", "expr", "term", "factor", "$@4", "args_list", YY_NULL
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
       0,    61,    62,    63,    64,    65,    65,    66,    67,    68,
      68,    69,    69,    70,    70,    70,    70,    70,    71,    71,
      72,    72,    73,    74,    74,    74,    75,    76,    77,    77,
      78,    79,    79,    79,    79,    79,    79,    79,    80,    80,
      81,    81,    82,    83,    83,    83,    83,    83,    84,    85,
      86,    86,    87,    87,    88,    88,    88,    89,    90,    91,
      92,    92,    94,    93,    93,    95,    95,    95,    95,    95,
      95,    95,    95,    95,    96,    96,    96,    97,    97,    97,
      97,    97,    98,    99,   100,   100,   101,   102,   104,   103,
     105,   105,   106,   107,   107,   108,   109,   108,   110,   111,
     111,   111,   111,   111,   111,   111,   112,   112,   112,   112,
     113,   113,   113,   113,   113,   114,   114,   114,   115,   114,
     114,   114,   114,   114,   114,   114,   116,   116
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     3,     2,     3,     1,     5,     0,     2,
       0,     5,     4,     1,     1,     1,     1,     1,     2,     0,
       2,     1,     4,     1,     1,     1,     6,     3,     2,     1,
       4,     1,     1,     3,     3,     4,     5,     3,     2,     0,
       2,     1,     4,     2,     2,     1,     1,     0,     8,     6,
       3,     2,     3,     1,     3,     3,     1,     2,     1,     1,
       3,     0,     0,     4,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     6,     5,     1,     4,     1,
       4,     4,     3,     5,     2,     0,     4,     4,     0,     9,
       1,     1,     5,     2,     1,     4,     0,     5,     2,     3,
       3,     3,     3,     3,     3,     1,     3,     3,     3,     1,
       3,     3,     3,     3,     1,     1,     4,     1,     0,     5,
       1,     3,     2,     2,     4,     3,     3,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     8,     0,     1,     0,     0,    10,     3,
       2,    61,     4,    59,     0,    19,     0,     0,     9,     0,
      39,     0,    82,     0,     0,    77,     0,    62,     0,    61,
       0,    79,     0,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,     0,     0,     0,    18,    21,     0,    47,
      15,    17,   115,    13,     0,     0,     0,    14,    16,   117,
     120,     0,   105,   109,   114,    88,    98,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    60,     0,     0,
       0,    20,     6,     0,    38,    41,     0,     0,     7,    45,
      46,     0,     0,     0,     0,   123,   122,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    74,     0,     0,   127,     0,     0,     0,
       0,     0,     0,     0,    12,     0,     0,    32,     0,     0,
      31,     0,     0,     0,    24,    25,    23,     0,     0,    40,
       0,     0,    43,    44,   125,     0,     0,   121,     0,   103,
      99,   100,   101,   102,    96,     0,     0,    94,   104,   108,
     107,   106,   113,   111,   112,   110,     0,     0,     0,     0,
      78,    85,    63,    81,    86,    87,    80,    11,     0,     0,
       0,     0,     0,     0,    29,     0,    22,     0,     5,     0,
       0,     0,   124,   116,     0,     0,     0,    92,    93,     0,
      76,     0,   126,     0,    83,     0,    37,    33,     0,     0,
      27,    28,    34,    42,    51,     0,    58,     0,    53,     0,
      56,     8,     0,   119,     0,     0,    91,    90,     0,    75,
      84,     0,     0,    35,     0,    57,    50,     0,     0,     0,
       0,     0,     0,    95,     0,     0,    36,    30,    52,    54,
      55,    49,     8,    97,     0,    26,     0,    89,    48
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     6,    83,     7,     8,    15,    18,    60,
      20,    46,    47,   133,   134,   135,   183,   184,   136,    49,
      84,    85,    88,    89,    90,   190,   217,   218,   219,   220,
      12,    16,    32,    72,    33,    34,    35,    36,    37,   204,
      38,    39,    40,   112,   228,    41,   156,   157,   195,    42,
     116,    62,    63,    64,    97,   117
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -203
static const yytype_int16 yypact[] =
{
     -23,    -2,    40,  -203,   -20,  -203,    38,    68,    59,  -203,
    -203,  -203,  -203,  -203,    56,    34,    95,    75,    80,    86,
      47,   198,  -203,   107,    81,   144,   198,  -203,    72,  -203,
     198,    99,    92,  -203,  -203,  -203,  -203,  -203,  -203,  -203,
    -203,  -203,  -203,    77,   121,   125,    86,  -203,   123,    29,
    -203,  -203,    97,  -203,   198,   198,   198,  -203,  -203,   126,
    -203,   269,    64,    83,  -203,  -203,  -203,   198,   135,   198,
     198,   282,   155,   198,   127,   104,   198,  -203,   116,    77,
     216,  -203,  -203,    33,   123,  -203,   138,   141,    29,  -203,
    -203,   142,   198,   198,   303,  -203,  -203,   143,   198,   198,
     198,   198,   198,    27,   198,   198,   198,   198,   198,   198,
     198,   198,   173,   243,   174,   307,   243,     1,   166,   193,
     137,   198,   166,    12,  -203,   134,   156,   171,   123,    77,
    -203,   123,   176,   152,  -203,  -203,  -203,   216,   162,  -203,
     169,   169,  -203,  -203,  -203,   318,    13,  -203,   198,    64,
      64,    64,    64,    64,  -203,   194,     6,  -203,    64,    83,
      83,    83,  -203,  -203,  -203,  -203,   198,   198,   200,   198,
    -203,   188,  -203,  -203,   243,  -203,  -203,  -203,   239,   181,
      15,   197,    71,     0,  -203,    77,  -203,   168,  -203,    50,
     178,   202,  -203,  -203,    21,   206,   166,  -203,  -203,   268,
     243,   198,   243,   166,  -203,   187,  -203,  -203,     2,   216,
    -203,  -203,  -203,  -203,  -203,   123,   208,   113,  -203,   223,
     225,  -203,   239,  -203,   166,   186,  -203,  -203,   198,   243,
    -203,   199,    77,  -203,   190,   208,  -203,   -11,   239,   239,
     192,   196,   205,  -203,   251,   216,  -203,  -203,  -203,  -203,
    -203,  -203,  -203,  -203,   166,  -203,   209,  -203,  -203
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -203,  -203,  -203,  -202,  -125,  -203,  -203,  -203,  -203,   -41,
    -203,  -203,   211,  -136,  -203,  -203,  -203,    88,  -163,  -203,
    -203,   158,  -203,   167,   172,   122,  -203,    42,  -203,  -203,
    -203,   252,  -114,  -203,   161,  -203,  -203,   280,  -203,  -203,
    -203,  -203,  -203,  -203,  -203,  -203,  -203,   132,  -203,  -203,
     -21,   264,   -13,   -43,  -203,   -69
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -119
static const yytype_int16 yytable[] =
{
      61,   187,    78,   180,   171,    71,   182,   123,   175,    75,
      50,   169,    95,    96,    50,   205,    51,    82,     1,   240,
      51,   210,   169,   169,   146,   138,     4,   197,    82,     9,
     120,   169,    53,    94,   154,    50,    53,   232,   125,   132,
       5,    51,   137,   138,    86,   215,   113,    57,   115,   170,
     256,    57,    58,    87,    10,   154,    58,    53,   182,   241,
     176,   193,   155,   207,   216,   162,   163,   164,   165,   223,
      14,   145,    57,   234,    11,   249,   250,    58,    82,   194,
     209,   138,   225,   105,    17,    50,   108,    19,   181,   230,
     235,    51,   159,   160,   161,   109,   132,    43,   214,   106,
     174,    11,    21,    48,   107,    73,   215,    53,    44,   255,
     242,    66,   216,    91,    45,   155,    22,   122,    23,   110,
     111,    24,    57,    25,    26,    27,    98,    58,    92,    99,
      93,   100,    76,    11,    21,    65,   101,   132,   102,    28,
     257,    77,    29,    79,   212,   199,   200,    80,   202,    67,
      23,    82,    30,    24,    31,    25,    26,    27,   104,  -118,
      68,   236,   237,   114,   119,   124,   140,   233,   132,   141,
     144,    28,    11,    21,    29,    69,   148,    70,   166,   167,
     229,   132,   121,   177,    30,   173,    31,   178,   179,    23,
     188,   246,    24,   185,    25,    26,    27,   132,   132,    11,
      21,   186,   189,   196,   132,   201,    50,   244,   203,   206,
      28,   222,    51,    29,   208,   224,    23,   213,   138,    24,
     126,    25,    26,    30,    50,    31,    52,   221,    53,   231,
      51,    54,   238,    55,   239,   243,    56,    28,   245,   247,
      29,   251,   139,    57,   127,   252,    53,    50,    58,   128,
      30,   129,    31,    51,   253,   142,    59,    81,   258,   130,
     143,    57,   131,   191,   254,    98,    58,   127,    99,    53,
     100,   211,   128,    98,   129,   101,    99,   102,   100,   248,
     172,    74,   130,   101,    57,   102,   226,    13,   198,    58,
      98,    98,     0,    99,    99,   100,   100,   104,     0,     0,
     101,   101,   102,   102,    98,   104,     0,    99,   103,   100,
       0,     0,     0,     0,   101,     0,   102,     0,     0,     0,
     227,     0,   104,   104,     0,    98,     0,     0,    99,    98,
     100,     0,    99,   118,   100,   101,   104,   102,     0,   101,
      98,   102,     0,    99,     0,   100,     0,     0,     0,   168,
     101,   147,   102,     0,     0,     0,     0,   104,     0,     0,
     192,   104,   149,   150,   151,   152,   153,     0,   158,     0,
       0,     0,   104
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-203)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      21,   137,    43,   128,   118,    26,   131,    76,   122,    30,
       8,    10,    55,    56,     8,   178,    14,    28,    41,   221,
      14,    21,    10,    10,    93,    10,    28,    21,    28,    49,
      73,    10,    30,    54,    28,     8,    30,    35,    79,    80,
       0,    14,     9,    10,    15,    56,    67,    45,    69,    48,
     252,    45,    50,    24,    16,    28,    50,    30,   183,   222,
      48,    48,   103,    48,   189,   108,   109,   110,   111,    48,
      11,    92,    45,   209,     6,   238,   239,    50,    28,   148,
       9,    10,   196,    19,    28,     8,     3,    53,   129,   203,
     215,    14,   105,   106,   107,    12,   137,    22,    48,    35,
     121,     6,     7,    56,    40,    33,    56,    30,    28,   245,
     224,    30,   237,    16,    28,   156,    21,    13,    23,    36,
      37,    26,    45,    28,    29,    30,    22,    50,    31,    25,
      33,    27,    33,     6,     7,    28,    32,   178,    34,    44,
     254,    49,    47,    22,   185,   166,   167,    22,   169,     5,
      23,    28,    57,    26,    59,    28,    29,    30,    54,    33,
      16,    48,    49,    28,     9,    49,    28,   208,   209,    28,
      28,    44,     6,     7,    47,    31,    33,    33,     5,     5,
     201,   222,    55,    49,    57,    48,    59,    31,    17,    23,
      28,   232,    26,    17,    28,    29,    30,   238,   239,     6,
       7,    49,    33,     9,   245,     5,     8,   228,    20,    28,
      44,     9,    14,    47,    17,     9,    23,    49,    10,    26,
       4,    28,    29,    57,     8,    59,    28,    49,    30,    42,
      14,    33,     9,    35,     9,    49,    38,    44,    39,    49,
      47,    49,    84,    45,    28,    49,    30,     8,    50,    33,
      57,    35,    59,    14,    49,    88,    58,    46,    49,    43,
      88,    45,    46,   141,    13,    22,    50,    28,    25,    30,
      27,   183,    33,    22,    35,    32,    25,    34,    27,   237,
     119,    29,    43,    32,    45,    34,    18,     7,   156,    50,
      22,    22,    -1,    25,    25,    27,    27,    54,    -1,    -1,
      32,    32,    34,    34,    22,    54,    -1,    25,    39,    27,
      -1,    -1,    -1,    -1,    32,    -1,    34,    -1,    -1,    -1,
      52,    -1,    54,    54,    -1,    22,    -1,    -1,    25,    22,
      27,    -1,    25,    51,    27,    32,    54,    34,    -1,    32,
      22,    34,    -1,    25,    -1,    27,    -1,    -1,    -1,    42,
      32,    48,    34,    -1,    -1,    -1,    -1,    54,    -1,    -1,
      42,    54,    98,    99,   100,   101,   102,    -1,   104,    -1,
      -1,    -1,    54
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    41,    62,    63,    28,     0,    64,    66,    67,    49,
      16,     6,    91,    98,    11,    68,    92,    28,    69,    53,
      71,     7,    21,    23,    26,    28,    29,    30,    44,    47,
      57,    59,    93,    95,    96,    97,    98,    99,   101,   102,
     103,   106,   110,    22,    28,    28,    72,    73,    56,    80,
       8,    14,    28,    30,    33,    35,    38,    45,    50,    58,
      70,   111,   112,   113,   114,    28,    30,     5,    16,    31,
      33,   111,    94,    33,    92,   111,    33,    49,    70,    22,
      22,    73,    28,    65,    81,    82,    15,    24,    83,    84,
      85,    16,    31,    33,   111,   114,   114,   115,    22,    25,
      27,    32,    34,    39,    54,    19,    35,    40,     3,    12,
      36,    37,   104,   111,    28,   111,   111,   116,    51,     9,
     114,    55,    13,   116,    49,    70,     4,    28,    33,    35,
      43,    46,    70,    74,    75,    76,    79,     9,    10,    82,
      28,    28,    84,    85,    28,   111,   116,    48,    33,   112,
     112,   112,   112,   112,    28,    70,   107,   108,   112,   113,
     113,   113,   114,   114,   114,   114,     5,     5,    42,    10,
      48,    93,    95,    48,   111,    93,    48,    49,    31,    17,
      65,    70,    65,    77,    78,    17,    49,    74,    28,    33,
      86,    86,    42,    48,   116,   109,     9,    21,   108,   111,
     111,     5,   111,    20,   100,    79,    28,    48,    17,     9,
      21,    78,    70,    49,    48,    56,    65,    87,    88,    89,
      90,    49,     9,    48,     9,    93,    18,    52,   105,   111,
      93,    42,    35,    70,    74,    65,    48,    49,     9,     9,
      64,    79,    93,    49,   111,    39,    70,    49,    88,    79,
      79,    49,    49,    49,    13,    74,    64,    93,    49
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
#line 39 "parser.y"
    {
tp("pargram");
root = new ProgramTreeNode(((ProgramHeadTreeNode*)(yyvsp[(1) - (3)]))->getName(), (RoutineTreeNode *)(yyvsp[(2) - (3)]));
(yyval) = root;
;
}
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 46 "parser.y"
    {
  tp("program head");
  (yyval) = new ProgramHeadTreeNode((yyvsp[(2) - (3)])->getName());
}
    break;

  case 4:
/* Line 1792 of yacc.c  */
#line 51 "parser.y"
    {
  tp("routine");
  (yyval) = new RoutineTreeNode((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
}
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 56 "parser.y"
    {
  tp("name list 1");
  (yyval) = (yyvsp[(1) - (3)]);
  (yyval)->insert(new TreeNode((yyvsp[(3) - (3)])->getName()));
}
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 61 "parser.y"
    {
   tp("name list 2");
   vector<TreeNode *> list;
   list.push_back(new TreeNode((yyvsp[(1) - (1)])->getName()));
   (yyval) = new ListTreeNode("name_list", list);
}
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 68 "parser.y"
    {
   tp("routine head");
   (yyval) = new RoutineHeadTreeNode((yyvsp[(2) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(4) - (5)]), (yyvsp[(5) - (5)]));
}
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 73 "parser.y"
    {}
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 75 "parser.y"
    {
  tp("const part1");
  (yyval) = (yyvsp[(2) - (2)]);
}
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 78 "parser.y"
    {tp("const part 2"); (yyval) = new ListTreeNode("non const part");}
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 81 "parser.y"
    {
  tp("const expr list 1");
  (yyval) = (yyvsp[(1) - (5)]);
  (yyval)->insert(new ConstTreeNode((yyvsp[(2) - (5)])->getName(), (yyvsp[(4) - (5)])));
}
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 86 "parser.y"
    {
  tp("const expr list 2");
  vector<TreeNode *> list;
  (yyval) = new ListTreeNode("const_value_list",list);
  (yyval)->insert(new ConstTreeNode((yyvsp[(1) - (4)])->getName(), (yyvsp[(3) - (4)])));
}
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 93 "parser.y"
    {tp("const value 1");(yyval) = new NumberTreeNode(currentToken, "integer");}
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 94 "parser.y"
    {tp("const value 2");(yyval) = new NumberTreeNode(currentToken, "real");
                          constRealMap[currentToken] = labelManager->getRealLabel();
                          }
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 97 "parser.y"
    {tp("const value 3");(yyval) = new NumberTreeNode(currentToken, "char");}
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 98 "parser.y"
    {tp("const value 4");(yyval) = new NumberTreeNode(currentToken, "string");
                          constStringMap[currentToken] = labelManager->getStringLabel();
                          }
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 101 "parser.y"
    {tp("const value 5");(yyval) = new NumberTreeNode(currentToken, "sys_con");}
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 103 "parser.y"
    {
  tp("type part 1");
  (yyval) = (yyvsp[(2) - (2)]);
}
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 106 "parser.y"
    {tp("type part 2"); (yyval) = new ListTreeNode("non type part");}
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 109 "parser.y"
    {
  tp("type_decl_list 1");
  (yyval) = (yyvsp[(1) - (2)]);
  (yyval)->insert((yyvsp[(2) - (2)]));
}
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 114 "parser.y"
    {
  tp("type_decl_list 2");
  vector<TreeNode *> list;
  list.push_back((yyvsp[(1) - (1)]));
  (yyval) = new ListTreeNode("type_decl_list",list);
}
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 121 "parser.y"
    {
  tp("type_definition");
  (yyval) = new CustomTypeTreeNode((yyvsp[(1) - (4)])->getName(), (yyvsp[(3) - (4)]));
}
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 126 "parser.y"
    {tp("type_decl 1");(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 127 "parser.y"
    {tp("type_decl 2");(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 128 "parser.y"
    {tp("type_decl 3");(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 130 "parser.y"
    {
  tp("array_type_decl");
  (yyval) = new ArrayTypeTreeNode((yyvsp[(3) - (6)]),(yyvsp[(6) - (6)]));
}
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 135 "parser.y"
    {
  tp("record_type_decl");
  (yyval) = new RecordTypeTreeNode((yyvsp[(2) - (3)]));
}
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 140 "parser.y"
    {
  tp("field_decl_list 1");
  (yyval) = (yyvsp[(1) - (2)]);
  (yyval)->insert((yyvsp[(2) - (2)]));
}
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 145 "parser.y"
    {
  tp("field_decl_list 2");
  vector<TreeNode *> list;
  list.push_back((yyvsp[(1) - (1)]));
  (yyval) = new ListTreeNode("field_decl_list",list);
}
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 152 "parser.y"
    {
  tp("field_decl");
  (yyval) = new VariableTreeNode((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
}
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 157 "parser.y"
    {                
                  tp("simple_type_decl 1");
                  (yyval) = new SysTypeTreeNode(currentToken);
                }
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 161 "parser.y"
    {
                  tp("simple_type_decl 2");                
                  (yyval) = new CustomTypeTreeNode((yyvsp[(1) - (1)])->getName());
                }
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 165 "parser.y"
    {
                  tp("simple_type_decl 3");                
                  (yyval) = new EnumTypeTreeNode((yyvsp[(2) - (3)]));
                }
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 169 "parser.y"
    {
                  tp("simple_type_decl 4");                
                  (yyval) = new SubRangeTypeTreeNode((yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]));
                }
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 173 "parser.y"
    {
                  tp("simple_type_decl 5");                
                  NumberTreeNode* n = (NumberTreeNode*)(yyvsp[(2) - (4)]);
                  string minus = "-";
                  n->set(minus+((NumberTreeNode*)(yyvsp[(2) - (4)]))->get());
                  (yyval) = new SubRangeTypeTreeNode((yyvsp[(2) - (4)]),(yyvsp[(4) - (4)]));
                }
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 180 "parser.y"
    {
                  tp("simple_type_decl 6");                
                  NumberTreeNode* n1 = (NumberTreeNode*)(yyvsp[(2) - (5)]);
                  NumberTreeNode* n2 = (NumberTreeNode*)(yyvsp[(5) - (5)]);
                  string minus = "-";
                  n1->set(minus + n1->get());
                  n2->set(minus + n2->get());
                  (yyval) = new SubRangeTypeTreeNode((yyvsp[(2) - (5)]),(yyvsp[(5) - (5)])); 
                }
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 189 "parser.y"
    {
                  tp("simple_type_decl 7");                
                  (yyval) = new RecordElemTreeNode((yyvsp[(1) - (3)])->getName(), (yyvsp[(3) - (3)])->getName());
                }
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 194 "parser.y"
    {
  tp("var part 1");
  (yyval) = (yyvsp[(2) - (2)]);
}
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 197 "parser.y"
    {tp("var part 2");(yyval) = new ListTreeNode("non var part");}
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 199 "parser.y"
    {
  tp("var_decl_list 1");
  (yyval) = (yyvsp[(1) - (2)]);
  (yyval)->insert((yyvsp[(2) - (2)]));
}
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 203 "parser.y"
    {
  tp("var_decl_list 2");
  vector<TreeNode *> list;
  list.push_back((yyvsp[(1) - (1)]));
  (yyval) = new ListTreeNode("var_decl_list",list);
}
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 210 "parser.y"
    {
  tp("var_decl");
  (yyval) = new VariableTreeNode((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]), 1);
}
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 215 "parser.y"
    {
                tp("routine part 1");
                (yyval) = (yyvsp[(1) - (2)]);
                (yyval)->insert((yyvsp[(2) - (2)]));
              }
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 220 "parser.y"
    {
                tp("routine part 2");
                (yyval) = (yyvsp[(1) - (2)]);
                (yyval)->insert((yyvsp[(2) - (2)]));
              }
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 225 "parser.y"
    {
                tp("routine part 3");
                vector<TreeNode *> list;
                list.push_back((yyvsp[(1) - (1)]));
                (yyval) = new ListTreeNode("function_decl_list",list);
              }
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 231 "parser.y"
    {
                tp("routine part 4");            
                vector<TreeNode *> list;
                list.push_back((yyvsp[(1) - (1)]));
                (yyval) = new ListTreeNode("procedure_decl_list",list);
            }
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 237 "parser.y"
    {tp("routine part 5");(yyval) = new ListTreeNode("non routine part");}
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 239 "parser.y"
    {
  tp("function decl");  
  (yyval) = new FunctionTreeNode((yyvsp[(2) - (8)])->getName(), (yyvsp[(3) - (8)]), (yyvsp[(5) - (8)]), (yyvsp[(7) - (8)]));
}
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 244 "parser.y"
    {
  tp("procedure decl");
  (yyval) = new FunctionTreeNode((yyvsp[(2) - (6)])->getName(), (yyvsp[(3) - (6)]), new TypeTreeNode(), (yyvsp[(5) - (6)]), 1);
}
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 249 "parser.y"
    {
  tp("paramters 1");
  (yyval) = (yyvsp[(2) - (3)]); 
}
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 253 "parser.y"
    {tp("paramters 2");(yyval) = new ListTreeNode("para_type_list");}
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 255 "parser.y"
    {
  tp("para_decl_list 1");
  (yyval) = (yyvsp[(1) - (3)]);
  (yyval)->insert((yyvsp[(3) - (3)]));
}
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 260 "parser.y"
    {
  tp("para_decl_list 2");
  vector<TreeNode *> list;
  list.push_back((yyvsp[(1) - (1)]));
  (yyval) = new ListTreeNode("para_type_list",list);
}
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 267 "parser.y"
    {
  tp("para_type_list 1");
  (yyval) = new VariableTreeNode((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]),1);
}
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 271 "parser.y"
    {
  tp("para_type_list 2");
  (yyval) = new VariableTreeNode((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), 0); 
}
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 275 "parser.y"
    {
  tp("para_type_list 3");
  (yyval) = new VariableTreeNode((yyvsp[(1) - (1)]));  
}
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 280 "parser.y"
    {
  tp("var_para_list");
  (yyval) = (yyvsp[(2) - (2)]);
}
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 284 "parser.y"
    {
  tp("val_para_list");
  (yyval) = (yyvsp[(1) - (1)]);
}
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 288 "parser.y"
    {
  tp("routine_body");
  (yyval) = (yyvsp[(1) - (1)]);
}
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 295 "parser.y"
    {
    tp("stmt list 1");
    (yyval) = (yyvsp[(1) - (3)]);
  	(yyval)->insert((yyvsp[(2) - (3)]));
}
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 300 "parser.y"
    {tp("stmt list 2");(yyval) = new ListTreeNode("stmt");}
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 302 "parser.y"
    {x = atoi(currentToken);}
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 303 "parser.y"
    {tp("stmt 1");(yyval) = (yyvsp[(3) - (4)]);((StmtTreeNode*)(yyval))->setLabel(x);}
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 304 "parser.y"
    {tp("stmt 2");(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 306 "parser.y"
    {tp("non_label_stmt 1");(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 307 "parser.y"
    {tp("non_label_stmt 2");(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 308 "parser.y"
    {tp("non_label_stmt 3");(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 68:
/* Line 1792 of yacc.c  */
#line 309 "parser.y"
    {tp("non_label_stmt 4");(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 69:
/* Line 1792 of yacc.c  */
#line 310 "parser.y"
    {tp("non_label_stmt 5");(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 70:
/* Line 1792 of yacc.c  */
#line 312 "parser.y"
    {tp("non_label_stmt 6");(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 71:
/* Line 1792 of yacc.c  */
#line 313 "parser.y"
    {tp("non_label_stmt 7");(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 72:
/* Line 1792 of yacc.c  */
#line 314 "parser.y"
    {tp("non_label_stmt 8");(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 73:
/* Line 1792 of yacc.c  */
#line 315 "parser.y"
    {tp("non_label_stmt 9");(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 74:
/* Line 1792 of yacc.c  */
#line 317 "parser.y"
    {
                tp("assign stmt 1");
                VariableTreeNode* x = new VariableTreeNode((yyvsp[(1) - (3)])->getName());
                (yyval) = new BinaryExprTreeNode("=",x,(yyvsp[(3) - (3)]));
            }
    break;

  case 75:
/* Line 1792 of yacc.c  */
#line 322 "parser.y"
    {
                tp("assign stmt 2");
                TreeNode* x = new ArrayElemTreeNode((yyvsp[(1) - (6)])->getName(),(yyvsp[(3) - (6)]));
                (yyval) = new BinaryExprTreeNode("=",x,(yyvsp[(6) - (6)]));
            }
    break;

  case 76:
/* Line 1792 of yacc.c  */
#line 327 "parser.y"
    {
                tp("assign stmt 3");
                TreeNode* x = new RecordElemTreeNode((yyvsp[(1) - (5)])->getName(),(yyvsp[(3) - (5)])->getName());
                (yyval) = new BinaryExprTreeNode("=",x,(yyvsp[(5) - (5)]));
            }
    break;

  case 77:
/* Line 1792 of yacc.c  */
#line 333 "parser.y"
    {tp("proc_stmt 1");(yyval) = new CallExprTreeNode((yyvsp[(1) - (1)])->getName(), 1);}
    break;

  case 78:
/* Line 1792 of yacc.c  */
#line 334 "parser.y"
    {tp("proc_stmt 2");(yyval) = new CallExprTreeNode((yyvsp[(1) - (4)])->getName(),((ListTreeNode*)(yyvsp[(3) - (4)]))->getList(), 1);}
    break;

  case 79:
/* Line 1792 of yacc.c  */
#line 335 "parser.y"
    {tp("proc_stmt 3");(yyval) = new CallExprTreeNode((yyvsp[(1) - (1)])->getName(),1);}
    break;

  case 80:
/* Line 1792 of yacc.c  */
#line 336 "parser.y"
    {tp("proc_stmt 4");(yyval) = new CallExprTreeNode((yyvsp[(1) - (4)])->getName(),((ListTreeNode*)(yyvsp[(3) - (4)]))->getList(), 1);}
    break;

  case 81:
/* Line 1792 of yacc.c  */
#line 337 "parser.y"
    {tp("proc_stmt 5");(yyval) = new CallExprTreeNode((yyvsp[(1) - (4)])->getName(),((ListTreeNode*)(yyvsp[(3) - (4)]))->getList(), 1);}
    break;

  case 82:
/* Line 1792 of yacc.c  */
#line 340 "parser.y"
    {
    tp("compound stmt");
    (yyval) = new CompoundStmtTreeNode((yyvsp[(2) - (3)]));
}
    break;

  case 83:
/* Line 1792 of yacc.c  */
#line 345 "parser.y"
    {
    tp("if stmt");
    (yyval) = new IfStmtTreeNode((yyvsp[(2) - (5)]),(yyvsp[(4) - (5)]),(yyvsp[(5) - (5)]));
}
    break;

  case 84:
/* Line 1792 of yacc.c  */
#line 350 "parser.y"
    {tp("else clause 1");(yyval) = (yyvsp[(2) - (2)]);}
    break;

  case 85:
/* Line 1792 of yacc.c  */
#line 351 "parser.y"
    {tp("else clause 2");(yyval) = NULL;}
    break;

  case 86:
/* Line 1792 of yacc.c  */
#line 353 "parser.y"
    {
    tp("repeat stmt");
    (yyval) = new RepeatStmtTreeNode((yyvsp[(2) - (4)]),(yyvsp[(4) - (4)]));
}
    break;

  case 87:
/* Line 1792 of yacc.c  */
#line 358 "parser.y"
    {
    tp("while stmt");
    (yyval) = new WhileStmtTreeNode((yyvsp[(4) - (4)]),(yyvsp[(2) - (4)]));
}
    break;

  case 88:
/* Line 1792 of yacc.c  */
#line 363 "parser.y"
    {name = currentToken;}
    break;

  case 89:
/* Line 1792 of yacc.c  */
#line 363 "parser.y"
    {
    tp("for stmt");
    VariableTreeNode * v = new VariableTreeNode(name);
    BinaryExprTreeNode *be = new BinaryExprTreeNode("=",v,(yyvsp[(5) - (9)]));
    BinaryExprTreeNode *br = new BinaryExprTreeNode("==",v,(yyvsp[(7) - (9)]));
    (yyval) = new ForStmtTreeNode(be,(yyvsp[(6) - (9)])->getName(),br,(yyvsp[(9) - (9)]));
}
    break;

  case 90:
/* Line 1792 of yacc.c  */
#line 371 "parser.y"
    {(yyval) = new TreeNode("to");}
    break;

  case 91:
/* Line 1792 of yacc.c  */
#line 372 "parser.y"
    {(yyval) = new TreeNode("downto");}
    break;

  case 92:
/* Line 1792 of yacc.c  */
#line 374 "parser.y"
    {
    tp("case stmt");
    (yyval) = new SwitchStmtTreeNode((yyvsp[(2) - (5)]),(yyvsp[(4) - (5)]));
}
    break;

  case 93:
/* Line 1792 of yacc.c  */
#line 379 "parser.y"
    {tp("case expr list 1");(yyval) = (yyvsp[(1) - (2)]); (yyval)->insert((yyvsp[(2) - (2)]));}
    break;

  case 94:
/* Line 1792 of yacc.c  */
#line 380 "parser.y"
    {tp("case expr list 2");(yyval) = new ListTreeNode("case"); (yyval)->insert((yyvsp[(1) - (1)]));}
    break;

  case 95:
/* Line 1792 of yacc.c  */
#line 382 "parser.y"
    {tp("case expr 1");(yyval) = new CaseExprTreeNode((yyvsp[(1) - (4)]),(yyvsp[(3) - (4)]));}
    break;

  case 96:
/* Line 1792 of yacc.c  */
#line 383 "parser.y"
    {id = new VariableTreeNode(currentToken);}
    break;

  case 97:
/* Line 1792 of yacc.c  */
#line 384 "parser.y"
    {tp("case expr 2");(yyval) = new CaseExprTreeNode(id,(yyvsp[(4) - (5)]));}
    break;

  case 98:
/* Line 1792 of yacc.c  */
#line 386 "parser.y"
    {
    tp("got stmt");
    (yyval) = new GotoStmtTreeNode(currentToken);
}
    break;

  case 99:
/* Line 1792 of yacc.c  */
#line 391 "parser.y"
    {tp("expression 1");(yyval) = new BinaryExprTreeNode(">=",(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]));}
    break;

  case 100:
/* Line 1792 of yacc.c  */
#line 392 "parser.y"
    {tp("expressoin 2");(yyval) = new BinaryExprTreeNode(">",(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]));}
    break;

  case 101:
/* Line 1792 of yacc.c  */
#line 393 "parser.y"
    {tp("expression 3");(yyval) = new BinaryExprTreeNode("<=",(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]));}
    break;

  case 102:
/* Line 1792 of yacc.c  */
#line 394 "parser.y"
    {tp("expression 4");(yyval) = new BinaryExprTreeNode("<",(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]));}
    break;

  case 103:
/* Line 1792 of yacc.c  */
#line 395 "parser.y"
    {tp("expression 5");(yyval) = new BinaryExprTreeNode("==",(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]));}
    break;

  case 104:
/* Line 1792 of yacc.c  */
#line 396 "parser.y"
    {tp("expression 6");(yyval) = new BinaryExprTreeNode("!=",(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]));}
    break;

  case 105:
/* Line 1792 of yacc.c  */
#line 397 "parser.y"
    {tp("expression 7");(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 106:
/* Line 1792 of yacc.c  */
#line 399 "parser.y"
    {tp("expr 1");(yyval) = new BinaryExprTreeNode("+",(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]));}
    break;

  case 107:
/* Line 1792 of yacc.c  */
#line 400 "parser.y"
    {tp("expr 2");(yyval) = new BinaryExprTreeNode("-",(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]));}
    break;

  case 108:
/* Line 1792 of yacc.c  */
#line 401 "parser.y"
    {tp("expr 3");(yyval) = new BinaryExprTreeNode("||",(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]));}
    break;

  case 109:
/* Line 1792 of yacc.c  */
#line 402 "parser.y"
    {tp("expr 4");(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 110:
/* Line 1792 of yacc.c  */
#line 404 "parser.y"
    {tp("term 1");(yyval) = new BinaryExprTreeNode("*",(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]));}
    break;

  case 111:
/* Line 1792 of yacc.c  */
#line 405 "parser.y"
    {tp("term 2");(yyval) = new BinaryExprTreeNode("/",(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]));}
    break;

  case 112:
/* Line 1792 of yacc.c  */
#line 406 "parser.y"
    {tp("term 3");(yyval) = new BinaryExprTreeNode("%",(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]));}
    break;

  case 113:
/* Line 1792 of yacc.c  */
#line 407 "parser.y"
    {tp("term 4");(yyval) = new BinaryExprTreeNode("&&",(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]));}
    break;

  case 114:
/* Line 1792 of yacc.c  */
#line 408 "parser.y"
    {tp("term 5");(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 115:
/* Line 1792 of yacc.c  */
#line 410 "parser.y"
    {tp("factor 1");(yyval) = new VariableTreeNode((yyvsp[(1) - (1)])->getName());}
    break;

  case 116:
/* Line 1792 of yacc.c  */
#line 411 "parser.y"
    {
          tp("factor 2");(yyval) = new CallExprTreeNode((yyvsp[(1) - (4)])->getName(),((ListTreeNode*)(yyvsp[(3) - (4)]))->getList());
          }
    break;

  case 117:
/* Line 1792 of yacc.c  */
#line 414 "parser.y"
    {tp("factor 3");(yyval) = new CallExprTreeNode((yyvsp[(1) - (1)])->getName());}
    break;

  case 118:
/* Line 1792 of yacc.c  */
#line 415 "parser.y"
    {s = (yyvsp[(1) - (1)])->getName();}
    break;

  case 119:
/* Line 1792 of yacc.c  */
#line 416 "parser.y"
    {tp("factor 4");(yyval) = new CallExprTreeNode(s,((ListTreeNode*)(yyvsp[(4) - (5)]))->getList());}
    break;

  case 120:
/* Line 1792 of yacc.c  */
#line 417 "parser.y"
    {tp("factor 5");(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 121:
/* Line 1792 of yacc.c  */
#line 418 "parser.y"
    {tp("factor 6");(yyval) = (yyvsp[(2) - (3)]);}
    break;

  case 122:
/* Line 1792 of yacc.c  */
#line 419 "parser.y"
    {tp("factor 7");(yyval) = new UnaryExprTreeNode("~",(yyvsp[(2) - (2)]));}
    break;

  case 123:
/* Line 1792 of yacc.c  */
#line 420 "parser.y"
    {tp("factor 8");(yyval) = new UnaryExprTreeNode("-",(yyvsp[(2) - (2)]));}
    break;

  case 124:
/* Line 1792 of yacc.c  */
#line 421 "parser.y"
    {tp("factor 9");(yyval) = new ArrayElemTreeNode((yyvsp[(1) - (4)])->getName(),(yyvsp[(3) - (4)]));}
    break;

  case 125:
/* Line 1792 of yacc.c  */
#line 423 "parser.y"
    {tp("factor 10");(yyval) = new RecordElemTreeNode((yyvsp[(1) - (3)])->getName(),(yyvsp[(3) - (3)])->getName());}
    break;

  case 126:
/* Line 1792 of yacc.c  */
#line 425 "parser.y"
    {
    tp("args_list 1");
    (yyval) = (yyvsp[(1) - (3)]);
    (yyval)->insert((yyvsp[(3) - (3)]));
}
    break;

  case 127:
/* Line 1792 of yacc.c  */
#line 430 "parser.y"
    {tp("args_list 2"); (yyval) = new ListTreeNode("args_list");  (yyval)->insert((yyvsp[(1) - (1)]));}
    break;


/* Line 1792 of yacc.c  */
#line 2648 "parser.cpp"
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
  cout << lineno << ": " << curLine << " \n syntex error at token '" << currentToken << "'";
	// fprintf(stderr, "%s\n", s.c_str());
  exit(-1);
	return 0;
}

