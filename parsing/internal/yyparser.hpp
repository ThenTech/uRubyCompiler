/* A Bison parser, made by GNU Bison 3.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */

#pragma once
#include "../tokens.hpp"
#include "yylexer.hpp"
#include "../fwd.hpp"
#include "../Expression.hpp"
#include "../Statement.hpp"
#include "../../utils/utils_lib/utils_misc.hpp"
#include "../../utils/utils_lib/utils_string.hpp"

#define YYERROR_VERBOSE
#define ENUM_VAL(X) utils::traits::to_underlying(X)

extern char *yytext;

int yyerror(const char *msg) {
    utils::Logger::WriteLn("");
    utils::Logger::Error("BISON: %s", msg);
    cmp::parse_flags.ErrorIllegalChar({yytext, size_t(yyleng)});
    return 1;
}

void ppos(const char *rule = "\0") {
#if CMP_VERBOSE_CTORS
    cmp::parse_flags.LogPosition(rule);
#endif
}

static cmp::Statement *root = nullptr;



#ifndef YY_NULLPTR
    #if defined __cplusplus
        #if 201103L <= __cplusplus
            #define YY_NULLPTR nullptr
        #else
            #define YY_NULLPTR 0
        #endif
    #else
        #define YY_NULLPTR ((void*)0)
    #endif
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
    #undef YYERROR_VERBOSE
    #define YYERROR_VERBOSE 1
#else
    #define YYERROR_VERBOSE 0
#endif


/* Debug traces.  */
#ifndef YYDEBUG
    #define YYDEBUG 0
#endif
#if YYDEBUG
    extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
enum yytokentype {
    ID = 500,
    INTEGER = 501,
    REAL = 502,
    BOOLEANVAR = 503,
    STRING = 504,
    NIL = 505,
    IF = 506,
    THEN = 507,
    ELSIF = 508,
    ELSE = 509,
    WHILE = 510,
    UNTIL = 511,
    DO = 512,
    UNLESS = 513,
    WHEN = 514,
    CASE = 515,
    END = 516,
    RETURN = 517,
    COMMA = 518,
    COLON = 519,
    SEMICOLON = 520,
    DOT = 521,
    LPAREN = 522,
    RPAREN = 523,
    LBRACK = 524,
    RBRACK = 525,
    LBRACE = 526,
    RBRACE = 527,
    ASSIGN = 528,
    PLUSASSIGN = 529,
    MINUSASSIGN = 530,
    MULASSIGN = 531,
    DIVASSIGN = 532,
    MODASSIGN = 533,
    ANDASSIGN = 534,
    ORASSIGN = 535,
    BANDASSIGN = 536,
    BORASSIGN = 537,
    XORASSIGN = 538,
    PLUS = 539,
    MINUS = 540,
    TIMES = 541,
    DIVIDE = 542,
    MOD = 543,
    UMINUS = 544,
    BINAND = 545,
    BINOR = 546,
    BINXOR = 547,
    BINNOT = 548,
    EQ = 549,
    NEQ = 550,
    LT = 551,
    LE = 552,
    GT = 553,
    GE = 554,
    AND = 555,
    OR = 556,
    NOT = 557,
    ARRAY = 558,
    DEF = 559,
    UNDEF = 560,
    PRINT = 561,
    ENDTOKEN = 562
};
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE {

    cmp::Statement      *stm;
    cmp::Expression     *exp;
    cmp::IdExpression   *idexp;
    cmp::ExpressionList *expli;

    char   *string;
    int32_t integer;
    double  real;
    bool    boolean;


};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse(void);





#ifdef short
    #undef short
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
    typedef unsigned short yytype_uint16;
#endif

#ifdef YYTYPE_INT16
    typedef YYTYPE_INT16 yytype_int16;
#else
    typedef short yytype_int16;
#endif

#ifndef YYSIZE_T
    #ifdef __SIZE_TYPE__
        #define YYSIZE_T __SIZE_TYPE__
    #elif defined size_t
        #define YYSIZE_T size_t
    #elif ! defined YYSIZE_T
        #include <stddef.h> /* INFRINGES ON USER NAME SPACE */
        #define YYSIZE_T size_t
    #else
        #define YYSIZE_T unsigned
    #endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
    #if defined YYENABLE_NLS && YYENABLE_NLS
        #if ENABLE_NLS
            #include <libintl.h> /* INFRINGES ON USER NAME SPACE */
            #define YY_(Msgid) dgettext ("bison-runtime", Msgid)
        #endif
    #endif
    #ifndef YY_
        #define YY_(Msgid) Msgid
    #endif
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
    #define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
    #define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
    #define YYUSE(E) ((void) (E))
#else
    #define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
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
    #define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
    #define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
    #define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

#ifdef YYSTACK_USE_ALLOCA
    #if YYSTACK_USE_ALLOCA
        #ifdef __GNUC__
            #define YYSTACK_ALLOC __builtin_alloca
        #elif defined __BUILTIN_VA_ARG_INCR
            #include <alloca.h> /* INFRINGES ON USER NAME SPACE */
        #elif defined _AIX
            #define YYSTACK_ALLOC __alloca
        #elif defined _MSC_VER
            #include <malloc.h> /* INFRINGES ON USER NAME SPACE */
            #define alloca _alloca
        #else
            #define YYSTACK_ALLOC alloca
            #if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
                #include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
                /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
                #ifndef EXIT_SUCCESS
                    #define EXIT_SUCCESS 0
                #endif
            #endif
        #endif
    #endif
#endif

# ifdef YYSTACK_ALLOC
/* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
    and a page size can be as small as 4096 bytes.  So we cannot safely
    invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
    to allow for a few compiler-allocated temporary stack slots.  */
    #define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#ifndef YYSTACK_ALLOC_MAXIMUM
    #define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#ifndef EXIT_SUCCESS
    #define EXIT_SUCCESS 0
#endif
#  endif
#ifndef YYMALLOC
    #define YYMALLOC malloc
    #if ! defined malloc && ! defined EXIT_SUCCESS
        void *malloc(YYSIZE_T);  /* INFRINGES ON USER NAME SPACE */
    #endif
#endif
#ifndef YYFREE
    #define YYFREE free
    #if ! defined free && ! defined EXIT_SUCCESS
        void free(void *);  /* INFRINGES ON USER NAME SPACE */
    #endif
#endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc {
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
#define YYFINAL  44
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   271

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  66
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  112
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  212

#define YYUNDEFTOK  2
#define YYMAXUTOK   563

/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
    ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] = {
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
    2,     2,     2,     2,     2,     2,     1,     2,     2,     2,
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
    3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
    13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
    23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
    33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
    43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
    53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
    63,    64,    65,     2
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] = {
    0,   142,   142,   146,   150,   151,   155,   156,   157,   158,
    162,   163,   164,   165,   169,   170,   174,   178,   179,   183,
    184,   185,   186,   190,   201,   205,   209,   210,   211,   212,
    216,   220,   224,   225,   229,   230,   231,   232,   236,   240,
    244,   247,   251,   254,   258,   264,   269,   272,   275,   280,
    283,   285,   290,   293,   296,   315,   317,   322,   324,   353,
    354,   355,   356,   360,   361,   365,   367,   369,   371,   373,
    375,   377,   379,   381,   384,   387,   391,   395,   399,   403,
    407,   411,   415,   419,   423,   430,   433,   435,   439,   442,
    444,   448,   450,   452,   457,   459,   461,   463,   465,   467,
    469,   474,   476,   478,   480,   483,   486,   489,   493,   498,
    503,   505,   510
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] = {
    "$end", "error", "$undefined", "ID", "INTEGER", "REAL", "BOOLEANVAR",
    "STRING", "NIL", "IF", "THEN", "ELSIF", "ELSE", "WHILE", "UNTIL", "DO",
    "UNLESS", "WHEN", "CASE", "END", "RETURN", "COMMA", "COLON", "SEMICOLON",
    "DOT", "LPAREN", "RPAREN", "LBRACK", "RBRACK", "LBRACE", "RBRACE",
    "ASSIGN", "PLUSASSIGN", "MINUSASSIGN", "MULASSIGN", "DIVASSIGN",
    "MODASSIGN", "ANDASSIGN", "ORASSIGN", "BANDASSIGN", "BORASSIGN",
    "XORASSIGN", "PLUS", "MINUS", "TIMES", "DIVIDE", "MOD", "UMINUS",
    "BINAND", "BINOR", "BINXOR", "BINNOT", "EQ", "NEQ", "LT", "LE", "GT",
    "GE", "AND", "OR", "NOT", "ARRAY", "DEF", "UNDEF", "PRINT", "ENDTOKEN",
    "$accept", "ROOT", "ifmark", "elifmark", "thenmark", "elsemark",
    "endmark", "defmark", "lparenmark", "rparenmark", "returnmark",
    "whilemark", "unlessmark", "domark", "untillmark", "casemark",
    "whenmark", "commamark", "statement", "ifstm", "whenstm", "stmseq",
    "stmseq2", "endmarker2", "endmarker", "expression", "argumentlist",
    "expressionlist", "expr2", "expr3", "expr4", "designator", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] = {
    0,   256,   563,   500,   501,   502,   503,   504,   505,   506,
    507,   508,   509,   510,   511,   512,   513,   514,   515,   516,
    517,   518,   519,   520,   521,   522,   523,   524,   525,   526,
    527,   528,   529,   530,   531,   532,   533,   534,   535,   536,
    537,   538,   539,   540,   541,   542,   543,   544,   545,   546,
    547,   548,   549,   550,   551,   552,   553,   554,   555,   556,
    557,   558,   559,   560,   561,   562
};
# endif

#define YYPACT_NINF -153

#define yypact_value_is_default(Yystate) \
    (!!((Yystate) == (-153)))

#define YYTABLE_NINF -59

#define yytable_value_is_error(Yytable_value) \
    0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] = {
    121,  -153,  -153,  -153,  -153,  -153,  -153,  -153,  -153,  -153,
    185,   -56,   185,   185,   185,   185,  -153,    10,    -7,    27,
    185,    10,   121,  -153,   185,   185,   185,   185,    57,  -153,
    -153,   195,   169,  -153,   230,  -153,  -153,  -153,    -7,  -153,
    -153,  -153,  -153,   185,  -153,    -8,    -7,   -16,   -19,    21,
    -8,    21,    -9,    57,    57,  -153,  -153,   121,   185,   185,
    185,   185,   185,   185,   185,   185,   185,   185,   185,   185,
    185,   185,   185,   185,   185,   185,   185,   185,   185,   185,
    185,   185,   185,   185,   185,   185,   -16,   -19,   -36,    32,
    121,    10,   -28,     0,   185,    49,    89,  -153,    58,   116,
    121,   121,   121,  -153,    30,   185,  -153,  -153,    11,  -153,
    169,   169,   -18,   -18,   -18,   -18,   -18,   -18,   -18,   -18,
    -153,  -153,  -153,  -153,  -153,  -153,  -153,  -153,  -153,  -153,
    -153,  -153,  -153,  -153,  -153,  -153,  -153,   -19,   185,    57,
    -153,    68,    20,   -19,   -16,  -153,    75,   -19,  -153,    82,
    -153,    83,    16,    29,    16,  -153,    -8,  -153,  -153,  -153,
    -153,  -153,    84,    57,   133,   185,   121,  -153,  -153,   121,
    10,  -153,  -153,  -153,  -153,   135,  -153,    71,   121,  -153,
    -153,   121,  -153,  -153,  -153,    86,    57,    -8,    16,    16,
    -153,    16,    26,  -153,  -153,   121,  -153,  -153,  -153,   157,
    121,  -153,   185,  -153,    20,    16,    -8,  -153,  -153,   121,
    26,  -153
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] = {
    0,   112,   108,   109,   110,     3,    24,    30,    25,    31,
    0,    18,     0,     0,     0,     0,    16,     0,     0,     0,
    0,     0,     0,    47,     0,     0,     0,     0,    64,     2,
    48,    65,    91,    94,   111,    23,    17,   101,   111,   102,
    104,   103,    46,    90,     1,     0,     0,     0,    48,     0,
    0,     0,     0,    61,    59,    55,    63,    56,     0,     0,
    0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    0,     0,     0,     0,     0,    90,    89,     0,     9,     0,
    0,    87,    37,     0,     0,    22,     0,   105,    29,     0,
    0,     0,     0,    33,     0,     0,    62,    60,    64,    57,
    92,    93,    66,    67,    68,    69,    70,    71,    72,    73,
    95,    96,    97,    98,    99,   100,    74,    75,    76,    77,
    78,    79,    80,    81,    82,    83,    84,     0,    90,    64,
    7,     8,     0,     0,    86,    35,    36,     0,    20,    21,
    27,    28,     0,     0,     0,    32,     0,   107,    88,    38,
    6,     5,    13,     0,     0,     0,     0,    51,    39,     0,
    87,    34,   106,    19,    26,     0,    40,     0,     0,    42,
    41,     0,    11,    15,     4,    12,     0,     0,     0,     0,
    85,     0,     0,    10,    14,     0,    50,    45,    43,     0,
    0,    54,     0,    44,     0,     0,     0,    49,    53,     0,
    0,    52
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] = {
    -153,  -153,  -153,  -153,   -44,  -152,     6,  -153,   132,    -5,
        -153,  -153,  -153,   106,  -153,  -153,   109,   -66,    -3,   -37,
        -39,   -13,  -153,   -50,    36,   -10,     3,   -59,   139,    34,
        48,    38
    };

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] = {
    -1,    19,    20,   165,    90,   166,   167,    21,    22,    97,
        23,    24,    25,   100,    26,    27,   202,    94,    28,   168,
        203,    29,    55,    56,    57,    30,   143,    87,    31,    32,
        33,    34
    };

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] = {
    35,   178,    88,   106,   107,    92,   101,    95,   103,    36,
    45,   -58,    48,     1,    49,    50,    51,    52,    11,    47,
    138,   146,   -58,   -58,    58,    59,   137,    44,   -58,   140,
    -58,   161,   162,    86,    53,   163,    98,   145,   162,   163,
    200,   162,   141,   103,   109,   163,    96,   155,   163,    93,
    38,    38,    38,    38,   108,    42,   104,    89,   200,    46,
    37,    39,    40,    41,   126,   127,   128,   129,   130,   131,
    132,   133,   134,   135,   136,    86,    54,   142,   170,   158,
    53,   175,   139,   185,   147,   164,    99,   152,   153,   154,
    186,   199,   110,   111,   177,   156,    38,    38,    38,    38,
    38,    38,    38,    38,    38,    38,    38,    38,    38,    38,
    38,    38,   181,   183,   148,   149,   120,   121,   122,   123,
    124,   125,    54,   150,     1,     2,     3,     4,    86,   144,
    5,   151,   157,   160,     6,     7,   194,     8,   169,     9,
    171,    10,   172,   195,   184,   185,    11,   173,   174,   182,
    43,   193,   186,   188,   186,   187,   189,   102,   176,   179,
    180,   105,   209,    12,    13,   191,    85,   207,   192,   185,
    85,   211,    14,   190,   155,   159,   186,     0,    91,     0,
    0,    15,   204,    16,    17,    18,     0,   205,     1,     2,
    3,     4,   206,     0,   196,   197,   210,   198,   201,   112,
    113,   114,   115,   116,   117,   118,   119,     0,   144,     0,
    11,   208,     0,    68,    69,    70,   201,    71,    72,    73,
    0,     0,     0,     0,     0,     0,     0,    12,    13,     0,
    0,     0,     0,     0,     0,     0,    14,    58,    59,     0,
    0,     0,     0,     0,     0,    15,     0,    60,    61,    62,
    63,    64,    65,    66,    67,    11,     0,     0,     0,     0,
    0,    74,    75,    76,    77,    78,    79,    80,    81,    82,
    83,    84
};

static const yytype_int16 yycheck[] = {
    10,   153,    10,    53,    54,    21,    50,    26,    17,    65,
    20,     0,    22,     3,    24,    25,    26,    27,    25,    22,
    86,    21,    11,    12,    42,    43,    85,     0,    17,    65,
    19,    11,    12,    43,    23,    19,    15,    65,    12,    19,
    192,    12,    10,    17,    57,    19,    65,    17,    19,    65,
    12,    13,    14,    15,    57,    17,    65,    65,   210,    21,
    12,    13,    14,    15,    74,    75,    76,    77,    78,    79,
    80,    81,    82,    83,    84,    85,    65,    90,   144,   138,
    23,    65,    87,    12,    94,    65,    65,   100,   101,   102,
    19,    65,    58,    59,    65,   105,    58,    59,    60,    61,
    62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
    72,    73,   156,   163,    65,    26,    68,    69,    70,    71,
    72,    73,    65,    65,     3,     4,     5,     6,   138,    91,
    9,    15,   137,    65,    13,    14,   186,    16,   143,    18,
    65,    20,   147,   187,    11,    12,    25,    65,    65,    65,
    18,    65,    19,   166,    19,   165,   169,    51,   152,   153,
    154,    52,   206,    42,    43,   178,    34,   204,   181,    12,
    38,   210,    51,   170,    17,   139,    19,    -1,    46,    -1,
    -1,    60,   195,    62,    63,    64,    -1,   200,     3,     4,
    5,     6,   202,    -1,   188,   189,   209,   191,   192,    60,
    61,    62,    63,    64,    65,    66,    67,    -1,   170,    -1,
    25,   205,    -1,    44,    45,    46,   210,    48,    49,    50,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    51,    42,    43,    -1,
    -1,    -1,    -1,    -1,    -1,    60,    -1,    52,    53,    54,
    55,    56,    57,    58,    59,    25,    -1,    -1,    -1,    -1,
    -1,    31,    32,    33,    34,    35,    36,    37,    38,    39,
    40,    41
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] = {
    0,     3,     4,     5,     6,     9,    13,    14,    16,    18,
    20,    25,    42,    43,    51,    60,    62,    63,    64,    67,
    68,    73,    74,    76,    77,    78,    80,    81,    84,    87,
    91,    94,    95,    96,    97,    91,    65,    96,    97,    96,
    96,    96,    97,    74,     0,    91,    97,    84,    91,    91,
    91,    91,    91,    23,    65,    88,    89,    90,    42,    43,
    52,    53,    54,    55,    56,    57,    58,    59,    44,    45,
    46,    48,    49,    50,    31,    32,    33,    34,    35,    36,
    37,    38,    39,    40,    41,    74,    91,    93,    10,    65,
    70,    74,    21,    65,    83,    26,    65,    75,    15,    65,
    79,    70,    79,    17,    65,    82,    89,    89,    84,    87,
    95,    95,    94,    94,    94,    94,    94,    94,    94,    94,
    96,    96,    96,    96,    96,    96,    91,    91,    91,    91,
    91,    91,    91,    91,    91,    91,    91,    93,    83,    75,
    65,    10,    87,    92,    97,    65,    21,    91,    65,    26,
    65,    15,    87,    87,    87,    17,    91,    75,    93,    90,
    65,    11,    12,    19,    65,    69,    71,    72,    85,    75,
    83,    65,    75,    65,    65,    65,    72,    65,    71,    72,
    72,    70,    65,    89,    11,    12,    19,    91,    87,    87,
    92,    87,    87,    65,    89,    70,    72,    72,    72,    65,
    71,    72,    82,    86,    87,    87,    91,    85,    72,    70,
    87,    86
};

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] = {
    0,    66,    67,    68,    69,    69,    70,    70,    70,    70,
    71,    71,    71,    71,    72,    72,    73,    74,    74,    75,
    75,    75,    75,    76,    77,    78,    79,    79,    79,    79,
    80,    81,    82,    82,    83,    83,    83,    83,    84,    84,
    84,    84,    84,    84,    84,    84,    84,    84,    84,    85,
    85,    85,    86,    86,    86,    87,    87,    88,    88,    89,
    89,    89,    89,    90,    90,    91,    91,    91,    91,    91,
    91,    91,    91,    91,    91,    91,    91,    91,    91,    91,
    91,    91,    91,    91,    91,    92,    92,    92,    93,    93,
    93,    94,    94,    94,    95,    95,    95,    95,    95,    95,
    95,    96,    96,    96,    96,    96,    96,    96,    96,    96,
    96,    96,    97
};

/* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] = {
    0,     2,     1,     1,     2,     1,     3,     2,     2,     1,
    3,     2,     2,     1,     3,     2,     1,     2,     1,     3,
    2,     2,     1,     2,     1,     1,     3,     2,     2,     1,
    1,     1,     2,     1,     3,     2,     2,     1,     5,     5,
    5,     5,     5,     7,     7,     7,     2,     1,     1,     5,
    3,     1,     5,     3,     1,     2,     2,     2,     2,     1,
    2,     1,     2,     1,     0,     1,     3,     3,     3,     3,
    3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
    3,     3,     3,     3,     3,     3,     1,     0,     3,     1,
    0,     1,     3,     3,     1,     3,     3,     3,     3,     3,
    3,     2,     2,     2,     2,     3,     5,     4,     1,     1,
    1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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

#ifndef YYFPRINTF
    #include <stdio.h> /* INFRINGES ON USER NAME SPACE */
    #define YYFPRINTF fprintf
#endif

# define YYDPRINTF(Args)                        \
    do {                                            \
        if (yydebug)                                  \
            YYFPRINTF Args;                             \
    } while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
    #define YY_LOCATION_PRINT(File, Loc) ((void) 0)
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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print(FILE *yyo, int yytype, YYSTYPE const *const yyvaluep) {
    FILE *yyoutput = yyo;
    YYUSE(yyoutput);

    if (!yyvaluep)
        return;

# ifdef YYPRINT

    if (yytype < YYNTOKENS)
        YYPRINT(yyo, yytoknum[yytype], *yyvaluep);

# endif
    YYUSE(yytype);
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print(FILE *yyo, int yytype, YYSTYPE const *const yyvaluep) {
    YYFPRINTF(yyo, "%s %s (",
              yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

    yy_symbol_value_print(yyo, yytype, yyvaluep);
    YYFPRINTF(yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print(yytype_int16 *yybottom, yytype_int16 *yytop) {
    YYFPRINTF(stderr, "Stack now");

    for (; yybottom <= yytop; yybottom++) {
        int yybot = *yybottom;
        YYFPRINTF(stderr, " %d", yybot);
    }

    YYFPRINTF(stderr, "\n");
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
yy_reduce_print(yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule) {
    unsigned long yylno = yyrline[yyrule];
    int yynrhs = yyr2[yyrule];
    int yyi;
    YYFPRINTF(stderr, "Reducing stack by rule %d (line %lu):\n",
              yyrule - 1, yylno);

    /* The symbols being reduced.  */
    for (yyi = 0; yyi < yynrhs; yyi++) {
        YYFPRINTF(stderr, "   $%d = ", yyi + 1);
        yy_symbol_print(stderr,
                        yystos[yyssp[yyi + 1 - yynrhs]],
                        &yyvsp[(yyi + 1) - (yynrhs)]
                       );
        YYFPRINTF(stderr, "\n");
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
    #define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
    #define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen(const char *yystr) {
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
yystpcpy(char *yydest, const char *yysrc) {
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
yytnamerr(char *yyres, const char *yystr) {
    if (*yystr == '"') {
        YYSIZE_T yyn = 0;
        char const *yyp = yystr;

        for (;;)
            switch (*++yyp) {
                case '\'':
                case ',':
                    goto do_not_strip_quotes;

                case '\\':
                    if (*++yyp != '\\')
                        goto do_not_strip_quotes;
                    else
                        goto append;

append:

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
        return yystrlen(yystr);

    return (YYSIZE_T)(yystpcpy(yyres, yystr) - yyres);
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
yysyntax_error(YYSIZE_T *yymsg_alloc, char **yymsg,
               yytype_int16 *yyssp, int yytoken) {
    YYSIZE_T yysize0 = yytnamerr(YY_NULLPTR, yytname[yytoken]);
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
    if (yytoken != YYEMPTY) {
        int yyn = yypact[*yyssp];
        yyarg[yycount++] = yytname[yytoken];

        if (!yypact_value_is_default(yyn)) {
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
                    && !yytable_value_is_error(yytable[yyx + yyn])) {
                    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM) {
                        yycount = 1;
                        yysize = yysize0;
                        break;
                    }

                    yyarg[yycount++] = yytname[yyx];
                    {
                        YYSIZE_T yysize1 = yysize + yytnamerr(YY_NULLPTR, yytname[yyx]);

                        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                            yysize = yysize1;
                        else
                            return 2;
                    }
                }
        }
    }

    switch (yycount) {
# define YYCASE_(N, S)                      \
case N:                               \
    yyformat = S;                       \
    break

        default: /* Avoid compiler warnings. */
            YYCASE_(0, YY_("syntax error"));
            YYCASE_(1, YY_("syntax error, unexpected %s"));
            YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
            YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
            YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
            YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

    {
        YYSIZE_T yysize1 = yysize + yystrlen(yyformat);

        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
            yysize = yysize1;
        else
            return 2;
    }

    if (*yymsg_alloc < yysize) {
        *yymsg_alloc = 2 * yysize;

        if (!(yysize <= *yymsg_alloc
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
            if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount) {
                yyp += yytnamerr(yyp, yyarg[yyi++]);
                yyformat += 2;
            } else {
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
yydestruct(const char *yymsg, int yytype, YYSTYPE *yyvaluep) {
    YYUSE(yyvaluep);

    if (!yymsg)
        yymsg = "Deleting";

    YY_SYMBOL_PRINT(yymsg, yytype, yyvaluep, yylocationp);

    YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
    YYUSE(yytype);
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
yyparse(void) {
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

    YYDPRINTF((stderr, "Starting parse\n"));

    yystate = 0;
    yyerrstatus = 0;
    yynerrs = 0;
    yychar = YYEMPTY; /* Cause a token to be read.  */
    goto yysetstate;


    /*------------------------------------------------------------.
    | yynewstate -- push a new state, which is found in yystate.  |
    `------------------------------------------------------------*/
yynewstate:
    /* In all cases, when you get here, the value and location stacks
       have just been pushed.  So pushing a state here evens the stacks.  */
    yyssp++;


    /*--------------------------------------------------------------------.
    | yynewstate -- set current state (the top of the stack) to yystate.  |
    `--------------------------------------------------------------------*/
yysetstate:
    YYDPRINTF((stderr, "Entering state %d\n", yystate));
    YY_ASSERT(0 <= yystate && yystate < YYNSTATES);
    *yyssp = (yytype_int16) yystate;

    if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
        goto yyexhaustedlab;

#else
    {
        /* Get the current used size of the three stacks, in elements.  */
        YYSIZE_T yysize = (YYSIZE_T)(yyssp - yyss + 1);

# if defined yyoverflow
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
            yyoverflow(YY_("memory exhausted"),
                       &yyss1, yysize * sizeof(*yyssp),
                       &yyvs1, yysize * sizeof(*yyvsp),
                       &yystacksize);
            yyss = yyss1;
            yyvs = yyvs1;
        }
# else /* defined YYSTACK_RELOCATE */

        /* Extend the stack our own way.  */
        if (YYMAXDEPTH <= yystacksize)
            goto yyexhaustedlab;

        yystacksize *= 2;

        if (YYMAXDEPTH < yystacksize)
            yystacksize = YYMAXDEPTH;

        {
            yytype_int16 *yyss1 = yyss;
            union yyalloc *yyptr =
                    (union yyalloc *) YYSTACK_ALLOC(YYSTACK_BYTES(yystacksize));

            if (! yyptr)
                goto yyexhaustedlab;

            YYSTACK_RELOCATE(yyss_alloc, yyss);
            YYSTACK_RELOCATE(yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE

            if (yyss1 != yyssa)
                YYSTACK_FREE(yyss1);
        }
# endif

        yyssp = yyss + yysize - 1;
        yyvsp = yyvs + yysize - 1;

        YYDPRINTF((stderr, "Stack size increased to %lu\n",
                   (unsigned long) yystacksize));

        if (yyss + yystacksize - 1 <= yyssp)
            YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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

    if (yypact_value_is_default(yyn))
        goto yydefault;

    /* Not known => get a lookahead token if don't already have one.  */

    /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
    if (yychar == YYEMPTY) {
        YYDPRINTF((stderr, "Reading a token: "));
        yychar = yylex();
    }

    if (yychar <= YYEOF) {
        yychar = yytoken = YYEOF;
        YYDPRINTF((stderr, "Now at end of input.\n"));
    } else {
        yytoken = YYTRANSLATE(yychar);
        YY_SYMBOL_PRINT("Next token is", yytoken, &yylval, &yylloc);
    }

    /* If the proper action on seeing token YYTOKEN is to reduce or to
       detect an error, take that action.  */
    yyn += yytoken;

    if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
        goto yydefault;

    yyn = yytable[yyn];

    if (yyn <= 0) {
        if (yytable_value_is_error(yyn))
            goto yyerrlab;

        yyn = -yyn;
        goto yyreduce;
    }

    /* Count tokens shifted since error; after three, turn off error
       status.  */
    if (yyerrstatus)
        yyerrstatus--;

    /* Shift the lookahead token.  */
    YY_SYMBOL_PRINT("Shifting", yytoken, &yylval, &yylloc);

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
    | yyreduce -- do a reduction.  |
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
    yyval = yyvsp[1 - yylen];


    YY_REDUCE_PRINT(yyn);

    switch (yyn) {
        case 2:
        { (yyval.stm) = (yyvsp[0].stm); root = (yyval.stm); }
        break;

        case 3:
        {}
        break;

        case 4:
        {}
        break;

        case 5:
        {}
        break;

        case 6:
        {}
        break;

        case 7:
        {}
        break;

        case 8:
        {}
        break;

        case 9:
        {}
        break;

        case 10:
        {}
        break;

        case 11:
        {}
        break;

        case 12:
        {}
        break;

        case 13:
        {}
        break;

        case 14:
        {}
        break;

        case 15:
        {}
        break;

        case 16:
        { cmp::parse_flags.EnterDefinition(); }
        break;

        case 17:
        {}
        break;

        case 18:
        {}
        break;

        case 19:
        {}
        break;

        case 20:
        {}
        break;

        case 21:
        {}
        break;

        case 22:
        {}
        break;

        case 23: {
            ppos("stm::RETURN");

            if (cmp::parse_flags.EnteredDefinition()) {
                (yyval.stm) = new cmp::ReturnStatement((yyvsp[0].exp));
            } else {
                yyerror("syntax error, RETURN token outside of function block!");
                YYERROR;
            }
        }
        break;

        case 24:
        {}
        break;

        case 25:
        {}
        break;

        case 26:
        {}
        break;

        case 27:
        {}
        break;

        case 28:
        {}
        break;

        case 29:
        {}
        break;

        case 30:
        {}
        break;

        case 31:
        {}
        break;

        case 32:
        {}
        break;

        case 33:
        {}
        break;

        case 34:
        {}
        break;

        case 35:
        {}
        break;

        case 36:
        {}
        break;

        case 37:
        {}
        break;

        case 38: {
            ppos("stm::PRINT(explist)");
            (yyval.stm) = new cmp::PrintStatement((yyvsp[-2].expli));
        }
        break;

        case 39: {
            ppos("stm::IF");
            (yyval.stm) = new cmp::IfStatement((yyvsp[-3].exp), (yyvsp[-1].stm), (yyvsp[0].stm));
        }
        break;

        case 40: {
            ppos("stm::WHILE");
            (yyval.stm) = new cmp::WhileStatement((yyvsp[-3].exp), (yyvsp[-1].stm));
        }
        break;

        case 41: {
            ppos("stm::UNTIL");
            (yyval.stm) = new cmp::UntilStatement((yyvsp[-3].exp), (yyvsp[-1].stm));
        }
        break;

        case 42: {
            ppos("stm::UNLESS");
            (yyval.stm) = new cmp::UnlessStatement((yyvsp[-3].exp), (yyvsp[-1].stm));
        }
        break;

        case 43: {
            ppos("stm::UNLESS ELSE");
            (yyval.stm) = new cmp::UnlessStatement((yyvsp[-5].exp), (yyvsp[-3].stm), (yyvsp[-1].stm));
        }
        break;

        case 44: {
            ppos("stm::CASE");
            (yyval.stm) = new cmp::CaseStatement((yyvsp[-5].exp),
                                                 new cmp::WhenStatement((yyvsp[-3].exp), (yyvsp[-1].stm), (yyvsp[0].stm)));
        }
        break;

        case 45: {
            ppos("stm::DEF id(args)");
            cmp::parse_flags.LeaveDefinition();
            (yyval.stm) = new cmp::FunctionStatement((yyvsp[-5].idexp), (yyvsp[-3].expli), (yyvsp[-1].stm));
        }
        break;

        case 46: {
            ppos("stm::UNDEF");
            (yyval.stm) = new cmp::UndefStatement((yyvsp[0].idexp));
        }
        break;

        case 47: {
            ppos("stm::returnmark");
            (yyval.stm) = (yyvsp[0].stm);
        }
        break;

        case 48: {
            ppos("stm::expr");
            (yyval.stm) = new cmp::ExpressionStatement((yyvsp[0].exp));
        }
        break;

        case 49: {
            ppos("ifstm::ELSIF");
            (yyval.stm) = new cmp::IfStatement((yyvsp[-3].exp), (yyvsp[-1].stm), (yyvsp[0].stm));
        }
        break;

        case 50: {
            ppos("ifstm::ELSE");
            (yyval.stm) = (yyvsp[-1].stm);
        }
        break;

        case 51: {
            ppos("ifstm::END");
            (yyval.stm) = nullptr;
        }
        break;

        case 52: {
            ppos("whenstm::WHEN");
            (yyval.stm) = new cmp::WhenStatement((yyvsp[-3].exp), (yyvsp[-1].stm), (yyvsp[0].stm));
        }
        break;

        case 53: {
            ppos("whenstm::ELSE");
            (yyval.stm) = new cmp::WhenStatement(nullptr, (yyvsp[-1].stm));
        }
        break;

        case 54: {
            ppos("whenstm::END");
            (yyval.stm) = nullptr;
        }
        break;

        case 55: {
            ppos("stmseq::stm stmseq2");
            (yyval.stm) = new cmp::CompoundStatement((yyvsp[-1].stm), (yyvsp[0].stm));
        }
        break;

        case 56: {
            ppos("stmseq::stm endmarker");
            (yyval.stm) = (yyvsp[-1].stm);
        }
        break;

        case 57: {
            ppos("stmseq2::endmarker stmseq");
            (yyval.stm) = (yyvsp[0].stm);
        }
        break;

        case 58: {
            ppos("stmseq2::endmarker stm");
            (yyval.stm) = (yyvsp[0].stm);
        }
        break;

        case 59:
        { ppos("endmarker2::ENDTOKEN"); }
        break;

        case 60:
        { ppos("endmarker2::ENDTOKEN endmarker2"); }
        break;

        case 61:
        { ppos("endmarker2::SEMICOLON"); }
        break;

        case 62:
        { ppos("endmarker2::SEMICOLON endmarker2"); }
        break;

        case 63:
        { ppos("endmarker::2"); }
        break;

        case 64:
        { ppos("endmarker::?EMPTY?"); }
        break;

        case 65: {
            ppos("expr::expr2");
            (yyval.exp) = (yyvsp[0].exp);
        }
        break;

        case 66: {
            ppos("expr::EQ");
            (yyval.exp) = new cmp::BinCompareExpression((yyvsp[-2].exp), cmp::BinCompare::EQ, (yyvsp[0].exp));
        }
        break;

        case 67: {
            ppos("expr::NEQ");
            (yyval.exp) = new cmp::BinCompareExpression((yyvsp[-2].exp), cmp::BinCompare::NEQ, (yyvsp[0].exp));
        }
        break;

        case 68: {
            ppos("expr::LT");
            (yyval.exp) = new cmp::BinCompareExpression((yyvsp[-2].exp), cmp::BinCompare::LT, (yyvsp[0].exp));
        }
        break;

        case 69: {
            ppos("expr::LE");
            (yyval.exp) = new cmp::BinCompareExpression((yyvsp[-2].exp), cmp::BinCompare::LE, (yyvsp[0].exp));
        }
        break;

        case 70: {
            ppos("expr::GT");
            (yyval.exp) = new cmp::BinCompareExpression((yyvsp[-2].exp), cmp::BinCompare::GT, (yyvsp[0].exp));
        }
        break;

        case 71: {
            ppos("expr::GE");
            (yyval.exp) = new cmp::BinCompareExpression((yyvsp[-2].exp), cmp::BinCompare::GE, (yyvsp[0].exp));
        }
        break;

        case 72: {
            ppos("expr::AND");
            (yyval.exp) = new cmp::BinCompareExpression((yyvsp[-2].exp), cmp::BinCompare::AND, (yyvsp[0].exp));
        }
        break;

        case 73: {
            ppos("expr::OR");
            (yyval.exp) = new cmp::BinCompareExpression((yyvsp[-2].exp), cmp::BinCompare::OR, (yyvsp[0].exp));
        }
        break;

        case 74: {
            ppos("expr::id ASSIGN exp");
            (yyval.exp) = new cmp::AssignExpression((yyvsp[-2].idexp), (yyvsp[0].exp));
        }
        break;

        case 75: {
            ppos("expr::id PLUSASSIGN exp");
            (yyval.exp) = new cmp::AssignExpression(new cmp::IdExpression(*(yyvsp[-2].idexp)),
                                                    new cmp::BinOperandExpression((yyvsp[-2].idexp), cmp::BinaryOperand::Plus, (yyvsp[0].exp)));
        }
        break;

        case 76: {
            ppos("expr::id MINUSASSIGN exp");
            (yyval.exp) = new cmp::AssignExpression(new cmp::IdExpression(*(yyvsp[-2].idexp)),
                                                    new cmp::BinOperandExpression((yyvsp[-2].idexp), cmp::BinaryOperand::Minus, (yyvsp[0].exp)));
        }
        break;

        case 77: {
            ppos("expr::id MULASSIGN exp");
            (yyval.exp) = new cmp::AssignExpression(new cmp::IdExpression(*(yyvsp[-2].idexp)),
                                                    new cmp::BinOperandExpression((yyvsp[-2].idexp), cmp::BinaryOperand::Times, (yyvsp[0].exp)));
        }
        break;

        case 78: {
            ppos("expr::id DIVASSIGN exp");
            (yyval.exp) = new cmp::AssignExpression(new cmp::IdExpression(*(yyvsp[-2].idexp)),
                                                    new cmp::BinOperandExpression((yyvsp[-2].idexp), cmp::BinaryOperand::Div, (yyvsp[0].exp)));
        }
        break;

        case 79: {
            ppos("expr::id MODASSIGN exp");
            (yyval.exp) = new cmp::AssignExpression(new cmp::IdExpression(*(yyvsp[-2].idexp)),
                                                    new cmp::BinOperandExpression((yyvsp[-2].idexp), cmp::BinaryOperand::Mod, (yyvsp[0].exp)));
        }
        break;

        case 80: {
            ppos("expr::id ANDASSIGN exp");
            (yyval.exp) = new cmp::AssignExpression(new cmp::IdExpression(*(yyvsp[-2].idexp)),
                                                    new cmp::BinCompareExpression((yyvsp[-2].idexp), cmp::BinCompare::AND, (yyvsp[0].exp)));
        }
        break;

        case 81: {
            ppos("expr::id ORASSIGN exp");
            (yyval.exp) = new cmp::AssignExpression(new cmp::IdExpression(*(yyvsp[-2].idexp)),
                                                    new cmp::BinCompareExpression((yyvsp[-2].idexp), cmp::BinCompare::OR, (yyvsp[0].exp)));
        }
        break;

        case 82: {
            ppos("expr::id ANDASSIGN exp");
            (yyval.exp) = new cmp::AssignExpression(new cmp::IdExpression(*(yyvsp[-2].idexp)),
                                                    new cmp::BinOperandExpression((yyvsp[-2].idexp), cmp::BinaryOperand::BinAnd, (yyvsp[0].exp)));
        }
        break;

        case 83: {
            ppos("expr::id ORASSIGN exp");
            (yyval.exp) = new cmp::AssignExpression(new cmp::IdExpression(*(yyvsp[-2].idexp)),
                                                    new cmp::BinOperandExpression((yyvsp[-2].idexp), cmp::BinaryOperand::BinOr, (yyvsp[0].exp)));
        }
        break;

        case 84: {
            ppos("expr::id XORASSIGN exp");
            (yyval.exp) = new cmp::AssignExpression(new cmp::IdExpression(*(yyvsp[-2].idexp)),
                                                    new cmp::BinOperandExpression((yyvsp[-2].idexp), cmp::BinaryOperand::BinXor, (yyvsp[0].exp)));
        }
        break;

        case 85: {
            ppos("arglist::id COMMA args");
            (yyval.expli) = new cmp::PairExpressionList((yyvsp[-2].idexp), (yyvsp[0].expli));
        }
        break;

        case 86: {
            ppos("arglist::id");
            (yyval.expli) = new cmp::LastExpressionList((yyvsp[0].idexp));
        }
        break;

        case 87:
        { (yyval.expli) = nullptr; }
        break;

        case 88: {
            ppos("explist::exp COMMA explist");
            (yyval.expli) = new cmp::PairExpressionList((yyvsp[-2].exp), (yyvsp[0].expli));
        }
        break;

        case 89: {
            ppos("explist::exp");
            (yyval.expli) = new cmp::LastExpressionList((yyvsp[0].exp));
        }
        break;

        case 90:
        { (yyval.expli) = nullptr; }
        break;

        case 91: {
            ppos("expr2::expr3");
            (yyval.exp) = (yyvsp[0].exp);
        }
        break;

        case 92: {
            ppos("expr2::PLUS");
            (yyval.exp) = new cmp::BinOperandExpression((yyvsp[-2].exp), cmp::BinaryOperand::Plus, (yyvsp[0].exp));
        }
        break;

        case 93: {
            ppos("expr2::MINUS");
            (yyval.exp) = new cmp::BinOperandExpression((yyvsp[-2].exp), cmp::BinaryOperand::Minus, (yyvsp[0].exp));
        }
        break;

        case 94: {
            ppos("expr3::expr4");
            (yyval.exp) = (yyvsp[0].exp);
        }
        break;

        case 95: {
            ppos("expr3::TIMES");
            (yyval.exp) = new cmp::BinOperandExpression((yyvsp[-2].exp), cmp::BinaryOperand::Times, (yyvsp[0].exp));
        }
        break;

        case 96: {
            ppos("expr3::DIVIDE");
            (yyval.exp) = new cmp::BinOperandExpression((yyvsp[-2].exp), cmp::BinaryOperand::Div, (yyvsp[0].exp));
        }
        break;

        case 97: {
            ppos("expr3::MOD");
            (yyval.exp) = new cmp::BinOperandExpression((yyvsp[-2].exp), cmp::BinaryOperand::Mod, (yyvsp[0].exp));
        }
        break;

        case 98: {
            ppos("expr3::BINAND");
            (yyval.exp) = new cmp::BinOperandExpression((yyvsp[-2].exp), cmp::BinaryOperand::BinAnd, (yyvsp[0].exp));
        }
        break;

        case 99: {
            ppos("expr3::BINOR");
            (yyval.exp) = new cmp::BinOperandExpression((yyvsp[-2].exp), cmp::BinaryOperand::BinOr, (yyvsp[0].exp));
        }
        break;

        case 100: {
            ppos("expr3::BINXOR");
            (yyval.exp) = new cmp::BinOperandExpression((yyvsp[-2].exp), cmp::BinaryOperand::BinXor, (yyvsp[0].exp));
        }
        break;

        case 101: {
            ppos("expr4::PLUS");
            (yyval.exp) = new cmp::UnaryOperandExpression(cmp::UnaryOperand::Plus, (yyvsp[0].exp));
        }
        break;

        case 102: {
            ppos("expr4::MINUS");
            (yyval.exp) = new cmp::UnaryOperandExpression(cmp::UnaryOperand::Minus, (yyvsp[0].exp));
        }
        break;

        case 103: {
            ppos("expr4::NOT");
            (yyval.exp) = new cmp::UnaryOperandExpression(cmp::UnaryOperand::Not, (yyvsp[0].exp));
        }
        break;

        case 104: {
            ppos("expr4::BINNOT");
            (yyval.exp) = new cmp::UnaryOperandExpression(cmp::UnaryOperand::BinNot, (yyvsp[0].exp));
        }
        break;

        case 105: {
            ppos("expr4::(exp)");
            (yyval.exp) = (yyvsp[-1].exp);
        }
        break;

        case 106: {
            ppos("expr4::(stm,exp)");
            (yyval.exp) = new cmp::ExpseqExpression((yyvsp[-3].stm), (yyvsp[-1].exp));
        }
        break;

        case 107: {
            ppos("expr4::id(explist)");
            (yyval.exp) = new cmp::FunctionExpression((yyvsp[-3].idexp), (yyvsp[-1].expli));
        }
        break;

        case 108: {
            ppos("expr4::int");
            std::string raw{yytext, size_t(yyleng)};
            utils::string::erase_all(raw, "_");
            const auto val = utils::misc::lexical_cast<int32_t>(raw);
            (yyval.exp) = new cmp::ValueExpression(val);
        }
        break;

        case 109: {
            ppos("expr4::real");
            std::string raw{yytext, size_t(yyleng)};
            utils::string::erase_all(raw, "_");
            const double val = utils::misc::lexical_cast<double>(raw);
            (yyval.exp) = new cmp::ValueExpression(val);
        }
        break;

        case 110: {
            ppos("expr4::bool");
            (yyval.exp) = new cmp::ValueExpression(yytext[0] == 't');
        }
        break;

        case 111: {
            ppos("expr4::id");
            (yyval.exp) = (yyvsp[0].idexp);
        }
        break;

        case 112: {
            ppos("id::id");
            (yyval.idexp) = new cmp::IdExpression(std::string_view{yytext, size_t(yyleng)});
        }
        break;



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
    YY_SYMBOL_PRINT("-> $$ =", yyr1[yyn], &yyval, &yyloc);

    YYPOPSTACK(yylen);
    yylen = 0;
    YY_STACK_PRINT(yyss, yyssp);

    *++yyvsp = yyval;

    /* Now 'shift' the result of the reduction.  Determine what state
       that goes to, based on the state we popped back to and the rule
       number reduced by.  */
    {
        const int yylhs = yyr1[yyn] - YYNTOKENS;
        const int yyi = yypgoto[yylhs] + *yyssp;
        yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
                   ? yytable[yyi]
                   : yydefgoto[yylhs]);
    }

    goto yynewstate;


    /*--------------------------------------.
    | yyerrlab -- here on detecting error.  |
    `--------------------------------------*/
yyerrlab:
    /* Make sure we have latest lookahead translation.  See comments at
       user semantic actions for why this is necessary.  */
    yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE(yychar);

    /* If not already recovering from an error, report this error.  */
    if (!yyerrstatus) {
        ++yynerrs;
#if ! YYERROR_VERBOSE
        yyerror(YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
        {
            char const *yymsgp = YY_("syntax error");
            int yysyntax_error_status;
            yysyntax_error_status = YYSYNTAX_ERROR;

            if (yysyntax_error_status == 0)
                yymsgp = yymsg;
            else if (yysyntax_error_status == 1) {
                if (yymsg != yymsgbuf)
                    YYSTACK_FREE(yymsg);

                yymsg = (char *) YYSTACK_ALLOC(yymsg_alloc);

                if (!yymsg) {
                    yymsg = yymsgbuf;
                    yymsg_alloc = sizeof yymsgbuf;
                    yysyntax_error_status = 2;
                } else {
                    yysyntax_error_status = YYSYNTAX_ERROR;
                    yymsgp = yymsg;
                }
            }

            yyerror(yymsgp);

            if (yysyntax_error_status == 2)
                goto yyexhaustedlab;
        }
# undef YYSYNTAX_ERROR
#endif
    }



    if (yyerrstatus == 3) {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        if (yychar <= YYEOF) {
            /* Return failure if at end of input.  */
            if (yychar == YYEOF)
                YYABORT;
        } else {
            yydestruct("Error: discarding",
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

    /* Pacify compilers when the user code never invokes YYERROR and the
       label yyerrorlab therefore never appears in user code.  */
    if (0)
        YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    YYPOPSTACK(yylen);
    yylen = 0;
    YY_STACK_PRINT(yyss, yyssp);
    yystate = *yyssp;
    goto yyerrlab1;


    /*-------------------------------------------------------------.
    | yyerrlab1 -- common code for both syntax error and YYERROR.  |
    `-------------------------------------------------------------*/
yyerrlab1:
    yyerrstatus = 3;      /* Each real token shifted decrements this.  */

    for (;;) {
        yyn = yypact[yystate];

        if (!yypact_value_is_default(yyn)) {
            yyn += YYTERROR;

            if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR) {
                yyn = yytable[yyn];

                if (0 < yyn)
                    break;
            }
        }

        /* Pop the current state because it cannot handle the error token.  */
        if (yyssp == yyss)
            YYABORT;


        yydestruct("Error: popping",
                   yystos[yystate], yyvsp);
        YYPOPSTACK(1);
        yystate = *yyssp;
        YY_STACK_PRINT(yyss, yyssp);
    }

    YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
    *++yyvsp = yylval;
    YY_IGNORE_MAYBE_UNINITIALIZED_END


    /* Shift the error token.  */
    YY_SYMBOL_PRINT("Shifting", yystos[yyn], yyvsp, yylsp);

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
    yyerror(YY_("memory exhausted"));
    yyresult = 2;
    /* Fall through.  */
#endif


    /*-----------------------------------------------------.
    | yyreturn -- parsing is finished, return the result.  |
    `-----------------------------------------------------*/
yyreturn:

    if (yychar != YYEMPTY) {
        /* Make sure we have latest lookahead translation.  See comments at
           user semantic actions for why this is necessary.  */
        yytoken = YYTRANSLATE(yychar);
        yydestruct("Cleanup: discarding lookahead",
                   yytoken, &yylval);
    }

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    YYPOPSTACK(yylen);
    YY_STACK_PRINT(yyss, yyssp);

    while (yyssp != yyss) {
        yydestruct("Cleanup: popping",
                   yystos[*yyssp], yyvsp);
        YYPOPSTACK(1);
    }

#ifndef yyoverflow

    if (yyss != yyssa)
        YYSTACK_FREE(yyss);

#endif
#if YYERROR_VERBOSE

    if (yymsg != yymsgbuf)
        YYSTACK_FREE(yymsg);

#endif
    return yyresult;
}
