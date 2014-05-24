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

/* Line 371 of yacc.c  */
#line 79 "parser.cpp"

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
#line 205 "parser.cpp"

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
#define YYLAST   361

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  61
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  56
/* YYNRULES -- Number of rules.  */
#define YYNRULES  126
/* YYNRULES -- Number of states.  */
#define YYNSTATES  258

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
     118,   124,   128,   131,   132,   135,   137,   142,   145,   148,
     150,   152,   153,   162,   169,   173,   174,   178,   180,   184,
     188,   191,   193,   195,   199,   200,   204,   206,   208,   210,
     212,   214,   216,   218,   220,   222,   224,   228,   235,   241,
     243,   248,   250,   255,   260,   264,   270,   273,   274,   279,
     284,   293,   295,   297,   303,   306,   308,   313,   318,   321,
     325,   329,   333,   337,   341,   345,   347,   351,   355,   359,
     361,   365,   369,   373,   377,   379,   381,   386,   388,   393,
     395,   399,   402,   405,   410,   414,   418
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      62,     0,    -1,    63,    65,    16,    -1,    -1,    41,    28,
      64,    49,    -1,    67,    95,    -1,    66,    10,    28,    -1,
      28,    -1,    68,    69,    74,    84,    87,    -1,    -1,    11,
      70,    -1,    -1,    -1,    70,    28,    71,    22,    73,    49,
      -1,    -1,    28,    72,    22,    73,    49,    -1,    30,    -1,
      45,    -1,     8,    -1,    50,    -1,    14,    -1,    53,    75,
      -1,    -1,    75,    76,    -1,    76,    -1,    -1,    28,    77,
      22,    78,    49,    -1,    83,    -1,    79,    -1,    80,    -1,
       4,    31,    83,    42,     9,    78,    -1,    46,    81,    21,
      -1,    81,    82,    -1,    82,    -1,    66,     9,    78,    49,
      -1,    43,    -1,    28,    -1,    33,    66,    48,    -1,    73,
      17,    73,    -1,    35,    73,    17,    73,    -1,    35,    73,
      17,    35,    73,    -1,    28,    17,    28,    -1,    56,    85,
      -1,    -1,    85,    86,    -1,    86,    -1,    66,     9,    78,
      49,    -1,    87,    88,    -1,    87,    89,    -1,    88,    -1,
      89,    -1,    -1,    24,    28,    90,     9,    83,    49,    65,
      49,    -1,    15,    28,    90,    49,    65,    49,    -1,    33,
      91,    48,    -1,    -1,    91,    49,    92,    -1,    92,    -1,
      93,     9,    83,    -1,    94,     9,    83,    -1,    56,    66,
      -1,    66,    -1,   101,    -1,    96,    97,    49,    -1,    -1,
      30,     9,    98,    -1,    98,    -1,    99,    -1,   100,    -1,
     101,    -1,   102,    -1,   104,    -1,   105,    -1,   106,    -1,
     108,    -1,   111,    -1,    28,     5,   112,    -1,    28,    31,
     112,    42,     5,   112,    -1,    28,    16,    28,     5,   112,
      -1,    28,    -1,    28,    33,   116,    48,    -1,    59,    -1,
      59,    33,   116,    48,    -1,    44,    33,   115,    48,    -1,
       6,    96,    21,    -1,    29,   112,    51,    97,   103,    -1,
      20,    97,    -1,    -1,    47,    96,    55,   112,    -1,    57,
     112,    13,    97,    -1,    23,    28,     5,   112,   107,   112,
      13,    97,    -1,    52,    -1,    18,    -1,     7,   112,    39,
     109,    21,    -1,   109,   110,    -1,   110,    -1,    73,     9,
      97,    49,    -1,    28,     9,    97,    49,    -1,    26,    30,
      -1,   112,    25,   113,    -1,   112,    27,   113,    -1,   112,
      32,   113,    -1,   112,    34,   113,    -1,   112,    22,   113,
      -1,   112,    54,   113,    -1,   113,    -1,   113,    40,   114,
      -1,   113,    35,   114,    -1,   113,    19,   114,    -1,   114,
      -1,   114,    37,   115,    -1,   114,    12,   115,    -1,   114,
      36,   115,    -1,   114,     3,   115,    -1,   115,    -1,    28,
      -1,    28,    33,   116,    48,    -1,    58,    -1,    58,    33,
     116,    48,    -1,    73,    -1,    33,   112,    48,    -1,    38,
     115,    -1,    35,   115,    -1,    28,    31,   112,    42,    -1,
      28,    16,    28,    -1,   116,    10,   112,    -1,   112,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    18,    18,    22,    22,    26,    30,    34,    40,    44,
      46,    48,    50,    50,    55,    55,    62,    63,    64,    65,
      66,    68,    70,    72,    76,    82,    82,    86,    87,    88,
      90,    94,    98,   102,   108,   114,   114,   114,   115,   116,
     117,   118,   119,   119,   120,   120,   121,   122,   122,   123,
     123,   123,   124,   125,   126,   127,   128,   128,   129,   130,
     131,   132,   133,   134,   134,   135,   135,   136,   136,   136,
     136,   136,   136,   136,   136,   136,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   148,   149,   150,
     151,   152,   152,   153,   154,   154,   155,   156,   157,   158,
     158,   158,   159,   159,   160,   160,   161,   161,   161,   161,
     162,   162,   163,   163,   163,   164,   164,   164,   165,   166,
     166,   167,   167,   167,   168,   169,   169
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
  "simple_type_decl", "var_part", "var_decl_list", "var_decl",
  "routine_part", "function_decl", "procedure_decl", "parameters",
  "para_decl_list", "para_type_list", "var_para_list", "val_para_list",
  "routine_body", "stmt_list", "stmt", "non_label_stmt", "assign_stmt",
  "proc_stmt", "compound_stmt", "if_stmt", "else_clause", "repeat_stmt",
  "while_stmt", "for_stmt", "direction", "case_stmt", "case_expr_list",
  "case_expr", "goto_stmt", "expression", "expr", "term", "factor",
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
      83,    83,    84,    84,    85,    85,    86,    87,    87,    87,
      87,    87,    88,    89,    90,    90,    91,    91,    92,    92,
      93,    94,    95,    96,    96,    97,    97,    98,    98,    98,
      98,    98,    98,    98,    98,    98,    99,    99,    99,   100,
     100,   100,   100,   100,   101,   102,   103,   103,   104,   105,
     106,   107,   107,   108,   109,   109,   110,   110,   111,   112,
     112,   112,   112,   112,   112,   112,   113,   113,   113,   113,
     114,   114,   114,   114,   114,   115,   115,   115,   115,   115,
     115,   115,   115,   115,   115,   116,   116
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     0,     4,     2,     3,     1,     5,     0,
       2,     0,     0,     6,     0,     5,     1,     1,     1,     1,
       1,     2,     0,     2,     1,     0,     5,     1,     1,     1,
       6,     3,     2,     1,     4,     1,     1,     3,     3,     4,
       5,     3,     2,     0,     2,     1,     4,     2,     2,     1,
       1,     0,     8,     6,     3,     0,     3,     1,     3,     3,
       2,     1,     1,     3,     0,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     6,     5,     1,
       4,     1,     4,     4,     3,     5,     2,     0,     4,     4,
       8,     1,     1,     5,     2,     1,     4,     4,     2,     3,
       3,     3,     3,     3,     3,     1,     3,     3,     3,     1,
       3,     3,     3,     3,     1,     1,     4,     1,     4,     1,
       3,     2,     2,     4,     3,     3,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     9,     3,     1,     0,     0,    11,     0,
       2,    64,     5,    62,     0,    22,     4,     0,    14,    10,
       0,    43,     0,    84,     0,     0,    79,     0,     0,     0,
      64,     0,    81,     0,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,     0,    12,    25,    21,    24,     0,
      51,    18,    20,   115,    16,     0,     0,     0,    17,    19,
     117,   119,     0,   105,   109,   114,     0,    98,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    63,     0,
       0,     0,    23,     7,     0,    42,    45,     0,     0,     8,
      49,    50,     0,     0,     0,     0,   122,   121,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    76,     0,     0,   126,     0,     0,
      65,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      44,    55,    55,    47,    48,   124,     0,     0,   120,     0,
     103,    99,   100,   101,   102,     0,     0,     0,    95,   104,
     108,   107,   106,   113,   111,   112,   110,     0,     0,     0,
       0,    80,    87,    83,    88,    89,    82,    15,     0,     0,
      36,     0,     0,    35,     0,     0,     0,    28,    29,    27,
       0,     6,     0,     0,     0,   123,   116,   118,     0,     0,
      93,    94,    92,    91,     0,    78,     0,   125,     0,    85,
      13,     0,     0,     0,     0,     0,     0,    33,     0,    26,
      46,     0,    61,     0,    57,     0,     0,     9,     0,     0,
       0,     0,    77,    86,     0,    41,    37,     0,     0,    31,
      32,    38,    60,    54,     0,     0,     0,     0,     0,    97,
      96,     0,     0,     0,    39,     0,    56,    58,    59,    53,
       9,    90,     0,    40,    34,     0,    30,    52
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     9,     6,    84,     7,     8,    15,    19,
      80,    44,    61,    21,    47,    48,    81,   176,   177,   178,
     206,   207,   179,    50,    85,    86,    89,    90,    91,   183,
     213,   214,   215,   216,    12,    17,    33,    34,    35,    36,
      37,    38,   199,    39,    40,    41,   194,    42,   147,   148,
      43,   117,    63,    64,    65,   118
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -207
static const yytype_int16 yypact[] =
{
     -29,    -3,    31,  -207,  -207,  -207,    20,    66,    70,    36,
    -207,  -207,  -207,  -207,    75,    52,  -207,    35,  -207,    86,
      93,    67,   153,  -207,   107,   109,   203,   153,   137,   120,
    -207,   153,   122,   103,  -207,  -207,  -207,  -207,  -207,  -207,
    -207,  -207,  -207,  -207,   138,  -207,  -207,    93,  -207,   141,
      45,  -207,  -207,    77,  -207,   153,   153,   153,  -207,  -207,
     144,  -207,   243,    -1,   159,  -207,   177,  -207,   153,   156,
     153,   153,   251,    83,   153,    90,   220,   153,  -207,    54,
     165,   170,  -207,  -207,    78,   141,  -207,   172,   173,    45,
    -207,  -207,   174,   153,   153,   274,  -207,  -207,   153,   153,
     153,   153,   153,   153,   140,   153,   153,   153,   153,   153,
     153,   153,   153,   153,   307,   200,   282,   307,     5,   150,
    -207,   158,   153,   150,     7,   163,    54,   185,   185,   186,
    -207,   183,   183,  -207,  -207,  -207,   293,     9,  -207,    11,
      -1,    -1,    -1,    -1,    -1,   212,   213,   196,  -207,    -1,
     159,   159,   159,  -207,  -207,  -207,  -207,   237,   153,   218,
     153,  -207,   205,  -207,   307,  -207,  -207,  -207,   178,   198,
     215,   141,    54,  -207,   141,   221,   188,  -207,  -207,  -207,
     191,  -207,    -2,   194,   235,  -207,  -207,  -207,   150,   150,
    -207,  -207,  -207,  -207,   153,   307,   153,   307,   150,  -207,
    -207,     2,   222,    19,   232,   119,    -8,  -207,    54,  -207,
    -207,   141,   246,    95,  -207,   248,   252,  -207,     2,   214,
     217,   226,   307,  -207,   225,  -207,  -207,    72,   185,  -207,
    -207,  -207,   246,  -207,    -2,     2,     2,   223,   230,  -207,
    -207,   150,   272,    54,  -207,   238,  -207,  -207,  -207,  -207,
    -207,  -207,   185,  -207,  -207,   239,  -207,  -207
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -207,  -207,  -207,  -207,  -206,  -168,  -207,  -207,  -207,  -207,
    -207,  -207,   -77,  -207,  -207,   245,  -207,  -127,  -207,  -207,
    -207,    80,  -103,  -207,  -207,   199,  -207,   201,   204,   162,
    -207,    61,  -207,  -207,  -207,   268,  -115,   227,  -207,  -207,
     296,  -207,  -207,  -207,  -207,  -207,  -207,  -207,  -207,   164,
    -207,   -22,   249,    57,   -34,   -70
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
      62,   180,   125,   203,   162,    72,   205,   124,   165,    76,
      51,   237,     1,   229,   212,   160,    52,   160,   106,   160,
      83,   160,    96,    97,   137,     4,    83,   146,   139,   129,
     170,     5,    54,    95,   107,   171,    10,   172,   205,   108,
     121,    11,    22,   232,   255,   173,   114,    58,   116,   168,
     175,   175,    59,   161,   211,   166,    23,   186,    24,   187,
      87,    25,    51,    26,    27,    28,   212,   226,    52,    88,
     146,   136,    11,   219,   220,   153,   154,   155,   156,    29,
      51,    14,    30,   223,    54,    16,    52,   128,   129,    11,
      22,   157,    31,    92,    32,   204,    11,    22,   224,    58,
     164,   245,    54,    18,    59,    20,    24,   243,    93,    25,
      94,    26,    27,    24,    45,   238,    25,    58,    26,    27,
      28,    46,    59,    49,   175,   256,   251,    29,   228,   129,
      30,   231,   247,   248,    29,    66,   195,    30,   197,    67,
      31,   175,    32,   233,   234,   122,    73,    31,    51,    32,
     244,   175,    78,    74,    52,    77,    11,    22,   175,   175,
      79,    51,   109,   150,   151,   152,   253,    52,   145,    83,
      54,   110,   221,    24,   222,   175,    25,    98,    26,    27,
      28,    53,   113,    54,   115,    58,    55,   126,    56,   169,
      59,    57,   127,    51,    29,   111,   112,    30,    58,    52,
     131,   132,   135,    59,    51,   158,   163,    31,    68,    32,
      52,    60,   167,   170,   181,    54,   182,   190,   171,    69,
     172,   188,   189,   196,   145,   198,    54,   200,   173,   201,
      58,   174,   202,   123,    70,    59,    71,   209,   208,   241,
     210,    58,    99,   217,   218,   100,    59,   101,    99,   227,
     225,   100,   102,   101,   103,   192,   129,   235,   102,    99,
     103,   236,   100,   239,   101,    99,   240,   242,   100,   102,
     101,   103,   249,    99,   105,   102,   100,   103,   101,   250,
     105,   252,   104,   102,   130,   103,   230,   254,   257,   193,
     133,   105,    82,   134,   184,   246,    99,   105,    75,   100,
     120,   101,   119,    13,    99,   105,   102,   100,   103,   101,
       0,   191,     0,     0,   102,    99,   103,     0,   100,     0,
     101,     0,   138,     0,   159,   102,     0,   103,   105,    99,
       0,     0,   100,     0,   101,   185,   105,     0,     0,   102,
       0,   103,     0,     0,     0,     0,     0,   105,   140,   141,
     142,   143,   144,     0,   149,     0,     0,     0,     0,     0,
       0,   105
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-207)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      22,   128,    79,   171,   119,    27,   174,    77,   123,    31,
       8,   217,    41,    21,   182,    10,    14,    10,    19,    10,
      28,    10,    56,    57,    94,    28,    28,   104,    98,    10,
      28,     0,    30,    55,    35,    33,    16,    35,   206,    40,
      74,     6,     7,   211,   250,    43,    68,    45,    70,   126,
     127,   128,    50,    48,    56,    48,    21,    48,    23,    48,
      15,    26,     8,    28,    29,    30,   234,    48,    14,    24,
     147,    93,     6,   188,   189,   109,   110,   111,   112,    44,
       8,    11,    47,   198,    30,    49,    14,     9,    10,     6,
       7,   113,    57,    16,    59,   172,     6,     7,   201,    45,
     122,   228,    30,    28,    50,    53,    23,    35,    31,    26,
      33,    28,    29,    23,    28,   218,    26,    45,    28,    29,
      30,    28,    50,    56,   201,   252,   241,    44,     9,    10,
      47,   208,   235,   236,    44,    28,   158,    47,   160,    30,
      57,   218,    59,    48,    49,    55,     9,    57,     8,    59,
     227,   228,    49,    33,    14,    33,     6,     7,   235,   236,
      22,     8,     3,   106,   107,   108,   243,    14,    28,    28,
      30,    12,   194,    23,   196,   252,    26,    33,    28,    29,
      30,    28,     5,    30,    28,    45,    33,    22,    35,     4,
      50,    38,    22,     8,    44,    36,    37,    47,    45,    14,
      28,    28,    28,    50,     8,     5,    48,    57,     5,    59,
      14,    58,    49,    28,    28,    30,    33,    21,    33,    16,
      35,     9,     9,     5,    28,    20,    30,    49,    43,    31,
      45,    46,    17,    13,    31,    50,    33,    49,    17,    13,
      49,    45,    22,    49,     9,    25,    50,    27,    22,    17,
      28,    25,    32,    27,    34,    18,    10,     9,    32,    22,
      34,     9,    25,    49,    27,    22,    49,    42,    25,    32,
      27,    34,    49,    22,    54,    32,    25,    34,    27,    49,
      54,     9,    39,    32,    85,    34,   206,    49,    49,    52,
      89,    54,    47,    89,   132,   234,    22,    54,    30,    25,
      73,    27,    51,     7,    22,    54,    32,    25,    34,    27,
      -1,   147,    -1,    -1,    32,    22,    34,    -1,    25,    -1,
      27,    -1,    48,    -1,    42,    32,    -1,    34,    54,    22,
      -1,    -1,    25,    -1,    27,    42,    54,    -1,    -1,    32,
      -1,    34,    -1,    -1,    -1,    -1,    -1,    54,    99,   100,
     101,   102,   103,    -1,   105,    -1,    -1,    -1,    -1,    -1,
      -1,    54
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    41,    62,    63,    28,     0,    65,    67,    68,    64,
      16,     6,    95,   101,    11,    69,    49,    96,    28,    70,
      53,    74,     7,    21,    23,    26,    28,    29,    30,    44,
      47,    57,    59,    97,    98,    99,   100,   101,   102,   104,
     105,   106,   108,   111,    72,    28,    28,    75,    76,    56,
      84,     8,    14,    28,    30,    33,    35,    38,    45,    50,
      58,    73,   112,   113,   114,   115,    28,    30,     5,    16,
      31,    33,   112,     9,    33,    96,   112,    33,    49,    22,
      71,    77,    76,    28,    66,    85,    86,    15,    24,    87,
      88,    89,    16,    31,    33,   112,   115,   115,    33,    22,
      25,    27,    32,    34,    39,    54,    19,    35,    40,     3,
      12,    36,    37,     5,   112,    28,   112,   112,   116,    51,
      98,   115,    55,    13,   116,    73,    22,    22,     9,    10,
      86,    28,    28,    88,    89,    28,   112,   116,    48,   116,
     113,   113,   113,   113,   113,    28,    73,   109,   110,   113,
     114,   114,   114,   115,   115,   115,   115,   112,     5,    42,
      10,    48,    97,    48,   112,    97,    48,    49,    73,     4,
      28,    33,    35,    43,    46,    73,    78,    79,    80,    83,
      78,    28,    33,    90,    90,    42,    48,    48,     9,     9,
      21,   110,    18,    52,   107,   112,     5,   112,    20,   103,
      49,    31,    17,    66,    73,    66,    81,    82,    17,    49,
      49,    56,    66,    91,    92,    93,    94,    49,     9,    97,
      97,   112,   112,    97,    83,    28,    48,    17,     9,    21,
      82,    73,    66,    48,    49,     9,     9,    65,    83,    49,
      49,    13,    42,    35,    73,    78,    92,    83,    83,    49,
      49,    97,     9,    73,    49,    65,    78,    49
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
#line 18 "parser.y"
    {
(yyval) = new ProgramTreeNode((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]));
}
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 22 "parser.y"
    {
  (yyval) = new ProgramHeadTreeNode(currentToken);
}
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 26 "parser.y"
    {
  (yyval) = new RoutineTreeNode((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
}
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 30 "parser.y"
    {
  (yyval) = (yyvsp[(1) - (3)]);
  (yyval).insert(new VariableTreeNode(currentToken));
}
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 34 "parser.y"
    {
   vector<TreeNode *> list;
   list.push_back(new VariableTreeNode(currentToken));
   (yyval) = new ListTreeNode("name_list", list);
}
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 40 "parser.y"
    {
   (yyval) = new RoutineHeadTreeNode((yyvsp[(2) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(4) - (5)]), (yyvsp[(5) - (5)]));
}
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 44 "parser.y"
    {}
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 46 "parser.y"
    {
  (yyval) = (yyvsp[(2) - (2)]);
}
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 50 "parser.y"
    {string name = currentToken;}
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 51 "parser.y"
    {
  (yyval) = (yyvsp[(1) - (6)]);
  (yyval).insert(new ConstTreeNode(name,(yyvsp[(4) - (6)])));
}
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 55 "parser.y"
    {string name = currentToken;}
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 56 "parser.y"
    {
  vector<TreeNode *> list;
  (yyval) = new ListTreeNode(list);
  (yyval).insert(new ConstTreeNode(name, (yyvsp[(3) - (5)])));
}
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 62 "parser.y"
    {(yyval) = new NumberTreeNode<int>(atoi(currentToken.c_str()));}
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 63 "parser.y"
    {(yyval) = new NumberTreeNode<double>(atof(currentToken.c_str));}
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 64 "parser.y"
    {(yyval) = new NumberTreeNode<char>(atof(currentToken[0]));}
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 65 "parser.y"
    {(yyval) = new NumberTreeNode<string>(currentToken);}
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 66 "parser.y"
    {(yyval) = new NumberTreeNode<string>(currentToken);}
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 68 "parser.y"
    {
  (yyval) = (yyvsp[(2) - (2)]);
}
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 72 "parser.y"
    {
  (yyval) = (yyvsp[(1) - (2)]);
  (yyval).insert((yyvsp[(2) - (2)]));
}
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 76 "parser.y"
    {
  vector<TreeNode *> list;
  list.push_back((yyvsp[(1) - (1)]));
  (yyval) = new ListTreeNode(list);
}
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 82 "parser.y"
    {string name = currentToken;}
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 82 "parser.y"
    {
  (yyval) = new CustomTypeTreeNode(name, (yyvsp[(3) - (5)]));
}
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 86 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 87 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 88 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 90 "parser.y"
    {
  (yyval) = new ArrayTypeTreeNode((yyvsp[(3) - (6)]),(yyvsp[(6) - (6)]));
}
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 94 "parser.y"
    {
  (yyval) = new RecordTypeTreeNode((yyvsp[(2) - (3)]));
}
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 98 "parser.y"
    {
  (yyval) = (yyvsp[(1) - (2)]);
  (yyval).insert((yyvsp[(2) - (2)]));
}
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 102 "parser.y"
    {
  vector<TreeNode *> list;
  list.push_back((yyvsp[(1) - (1)]));
  (yyval) = new ListTreeNode("field_decl_list",list);
}
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 108 "parser.y"
    {
  for(int i = 0; i < (yyvsp[(1) - (4)]).size(); ++i) {

  }
}
    break;


/* Line 1792 of yacc.c  */
#line 1886 "parser.cpp"
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
#line 172 "parser.y"


main() 
{
  return yyparse();
}



int yyerror(char *s) {
  fprintf(stderr, "%s\n", s);
  return 0;
}D  LP  args_list  RP  |  SYS_FUNCT 
| SYS_FUNCT  LP  args_list  RP 
|  const_value  |  LP  expression  RP
|  NOT  factor  |  MINUS  factor  |  ID  LB  expression  RB
|  ID  DOT  ID
args_list : args_list  COMMA  expression  |  expression

%%

main() 
{
	return yyparse();
}



int yyerror(char *s) {
	fprintf(stderr, "%s\n", s);
	return 0;
}