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

#include "../tokens.hpp"
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
    lex_error(yytext);
    return 1;
}

cmp::Statement *root = nullptr;



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
    PRINT = 561
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
#define YYFINAL  38
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   332

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  65
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  13
/* YYNRULES -- Number of rules.  */
#define YYNRULES  71
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  175

#define YYUNDEFTOK  2
#define YYMAXUTOK   562

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
    63,    64,     2
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] = {
    0,   127,   127,   131,   134,   138,   142,   146,   150,   154,
    158,   162,   166,   170,   175,   178,   185,   189,   192,   196,
    199,   203,   208,   214,   217,   221,   224,   229,   232,   234,
    239,   242,   245,   250,   253,   256,   259,   264,   266,   268,
    270,   272,   274,   276,   278,   280,   285,   288,   293,   296,
    301,   303,   305,   310,   312,   314,   316,   318,   320,   322,
    327,   329,   331,   333,   336,   338,   341,   345,   350,   355,
    357,   362
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] = {
    "$end", "error", "$undefined", "ID", "INTEGER", "REAL", "BOOLEAN",
    "STRING", "NIL", "IF", "THEN", "ELSIF", "ELSE", "WHILE", "UNTIL", "DO",
    "UNLESS", "WHEN", "CASE", "END", "RETURN", "COMMA", "COLON", "SEMICOLON",
    "DOT", "LPAREN", "RPAREN", "LBRACK", "RBRACK", "LBRACE", "RBRACE",
    "ASSIGN", "PLUSASSIGN", "MINUSASSIGN", "MULASSIGN", "DIVASSIGN",
    "MODASSIGN", "ANDASSIGN", "ORASSIGN", "BANDASSIGN", "BORASSIGN",
    "XORASSIGN", "PLUS", "MINUS", "TIMES", "DIVIDE", "MOD", "UMINUS",
    "BINAND", "BINOR", "BINXOR", "BINNOT", "EQ", "NEQ", "LT", "LE", "GT",
    "GE", "AND", "OR", "NOT", "ARRAY", "DEF", "UNDEF", "PRINT", "$accept",
    "ROOT", "statement", "ifstm", "whenstm", "stmseq", "expression",
    "argumentlist", "expressionlist", "expr2", "expr3", "expr4",
    "designator", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] = {
    0,   256,   562,   500,   501,   502,   503,   504,   505,   506,
    507,   508,   509,   510,   511,   512,   513,   514,   515,   516,
    517,   518,   519,   520,   521,   522,   523,   524,   525,   526,
    527,   528,   529,   530,   531,   532,   533,   534,   535,   536,
    537,   538,   539,   540,   541,   542,   543,   544,   545,   546,
    547,   548,   549,   550,   551,   552,   553,   554,   555,   556,
    557,   558,   559,   560,   561
};
# endif

#define YYPACT_NINF -163

#define yypact_value_is_default(Yystate) \
    (!!((Yystate) == (-163)))

#define YYTABLE_NINF -16

#define yytable_value_is_error(Yytable_value) \
    0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] = {
    32,  -163,    80,    80,    80,    80,    80,    80,    32,     9,
    9,   -22,    23,     3,  -163,   160,  -163,  -163,  -163,    11,
    80,    80,    80,    80,    20,    55,   196,  -163,    13,    19,
    28,    37,   -16,  -163,  -163,    26,  -163,    80,  -163,    32,
    80,    80,    80,    80,    80,    80,    80,    80,    80,    80,
    80,    80,    35,    31,   198,  -163,  -163,  -163,  -163,    32,
    80,    80,    80,    80,    80,    80,    80,    80,    80,    80,
    80,    80,    80,    80,    80,    80,    80,    32,    32,    32,
    80,    41,     2,    39,    44,  -163,    46,  -163,  -163,  -163,
    -163,  -163,  -163,  -163,  -163,  -163,  -163,  -163,    80,  -163,
    80,    81,   196,   196,   -21,   -21,   -21,   -21,   -21,   -21,
    -21,   -21,  -163,  -163,  -163,  -163,  -163,  -163,    50,    42,
    61,    -6,    53,    80,    32,    64,    60,    80,  -163,  -163,
    73,    75,    80,    32,  -163,  -163,  -163,  -163,  -163,    32,
    -163,    32,    92,    84,    32,     9,  -163,  -163,    83,    96,
    102,   106,    25,    32,  -163,   107,  -163,    32,  -163,  -163,
    32,    80,  -163,  -163,    25,  -163,    81,   108,   118,  -163,
    -163,  -163,    32,    25,  -163
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] = {
    0,    71,     0,     0,     0,     0,     0,     0,     0,     0,
    0,     0,     0,    36,     2,     0,    67,    68,    69,     0,
    0,     0,     0,     0,     0,    37,    50,    53,    70,     0,
    0,     0,     0,    26,    33,     0,    25,     0,     1,    35,
    0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    0,     0,     0,     0,    70,    60,    61,    63,    62,     0,
    0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    0,     0,     0,    49,     0,    34,     0,     3,     4,     5,
    6,     7,     8,     9,    10,    11,    12,    13,     0,    64,
    0,     0,    51,    52,    38,    39,    40,    41,    42,    43,
    44,    45,    54,    55,    56,    57,    58,    59,     0,     0,
    0,     0,     0,     0,     0,     0,    47,     0,    14,    15,
    0,     0,     0,     0,    29,    16,    66,    17,    18,     0,
    19,     0,     0,     0,     0,     0,    48,    65,    66,     0,
    0,     0,     0,     0,    24,     0,    46,     0,    28,    20,
    0,     0,    32,    21,     0,    23,     0,     0,     0,    22,
    27,    31,     0,     0,    30
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] = {
    -163,  -163,   110,   -34,  -162,    10,   171,   -15,   -36,   140,
        -28,    45,     0
    };

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] = {
    -1,    12,    13,   135,   163,    14,    83,   125,    84,    25,
        26,    27,    28
    };

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] = {
    15,    80,   169,    37,    86,     1,   139,    81,    15,    35,
    36,   174,     1,   140,     1,    16,    17,    18,    34,    54,
    2,    60,    61,    38,     3,     4,    39,     5,   124,     6,
    59,     7,   102,   103,    77,     1,    19,   160,    76,    15,
    118,     2,   161,    78,   162,     3,     4,    79,     5,    85,
    6,    82,     7,    20,    21,     8,    98,    99,   123,    15,
    127,   137,    22,   141,   131,    55,    56,    57,    58,   101,
    128,    23,   129,     9,    10,    11,   136,    15,    15,    15,
    138,   145,   126,     1,    16,    17,    18,   119,   120,   121,
    144,   146,   132,   133,     9,    10,    11,    60,    61,   147,
    134,   148,   153,   154,   -15,    19,   157,    62,    63,    64,
    65,    66,    67,    68,    69,   112,   113,   114,   115,   116,
    117,   158,    20,    21,    15,   159,   165,   171,   172,    52,
    156,    22,   170,    15,   143,     0,     0,     0,     0,    15,
    23,    15,     0,   150,    15,   126,     0,     0,     0,   151,
    0,   152,     0,    15,   155,     0,     0,    15,     0,     0,
    15,     0,     0,   164,     0,     0,     0,   166,     0,     0,
    167,     0,    15,    24,    29,    30,    31,    32,    33,     0,
    0,     0,   173,     0,     0,    40,     0,     0,     0,     0,
    53,    41,    42,    43,    44,    45,    46,    47,    48,    49,
    50,    51,   104,   105,   106,   107,   108,   109,   110,   111,
    0,     0,    87,    88,    89,    90,    91,    92,    93,    94,
    95,    96,    97,   100,     0,     0,     0,     0,     0,    41,
    42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
    70,    71,    72,     0,    73,    74,    75,     0,     0,     0,
    0,   122,     0,     0,     0,     0,     0,     0,     0,     0,
    0,     0,     0,     0,     0,     0,     0,     0,     0,   130,
    0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    0,     0,     0,     0,   142,     0,     0,     0,     0,     0,
    0,     0,     0,   149,     0,     0,     0,     0,     0,     0,
    0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    0,     0,   168
};

static const yytype_int16 yycheck[] = {
    0,    17,   164,    25,    40,     3,    12,    23,     8,     9,
    10,   173,     3,    19,     3,     4,     5,     6,     8,    19,
    9,    42,    43,     0,    13,    14,    23,    16,    26,    18,
    10,    20,    60,    61,    15,     3,    25,    12,    25,    39,
    76,     9,    17,    15,    19,    13,    14,    10,    16,    39,
    18,    25,    20,    42,    43,    23,    21,    26,    17,    59,
    21,    19,    51,    10,   100,    20,    21,    22,    23,    59,
    26,    60,    26,    62,    63,    64,    26,    77,    78,    79,
    19,    21,    82,     3,     4,     5,     6,    77,    78,    79,
    26,   127,    11,    12,    62,    63,    64,    42,    43,    26,
    19,    26,    10,    19,    21,    25,    10,    52,    53,    54,
    55,    56,    57,    58,    59,    70,    71,    72,    73,    74,
    75,    19,    42,    43,   124,    19,    19,    19,    10,    19,
    145,    51,   166,   133,   124,    -1,    -1,    -1,    -1,   139,
    60,   141,    -1,   133,   144,   145,    -1,    -1,    -1,   139,
    -1,   141,    -1,   153,   144,    -1,    -1,   157,    -1,    -1,
    160,    -1,    -1,   153,    -1,    -1,    -1,   157,    -1,    -1,
    160,    -1,   172,     2,     3,     4,     5,     6,     7,    -1,
    -1,    -1,   172,    -1,    -1,    25,    -1,    -1,    -1,    -1,
    19,    31,    32,    33,    34,    35,    36,    37,    38,    39,
    40,    41,    62,    63,    64,    65,    66,    67,    68,    69,
    -1,    -1,    41,    42,    43,    44,    45,    46,    47,    48,
    49,    50,    51,    25,    -1,    -1,    -1,    -1,    -1,    31,
    32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
    44,    45,    46,    -1,    48,    49,    50,    -1,    -1,    -1,
    -1,    80,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    98,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,   123,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,   132,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,   161
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] = {
    0,     3,     9,    13,    14,    16,    18,    20,    23,    62,
    63,    64,    66,    67,    70,    77,     4,     5,     6,    25,
    42,    43,    51,    60,    71,    74,    75,    76,    77,    71,
    71,    71,    71,    71,    70,    77,    77,    25,     0,    23,
    25,    31,    32,    33,    34,    35,    36,    37,    38,    39,
    40,    41,    67,    71,    77,    76,    76,    76,    76,    10,
    42,    43,    52,    53,    54,    55,    56,    57,    58,    59,
    44,    45,    46,    48,    49,    50,    25,    15,    15,    10,
    17,    23,    25,    71,    73,    70,    73,    71,    71,    71,
    71,    71,    71,    71,    71,    71,    71,    71,    21,    26,
    25,    70,    75,    75,    74,    74,    74,    74,    74,    74,
    74,    74,    76,    76,    76,    76,    76,    76,    73,    70,
    70,    70,    71,    17,    26,    72,    77,    21,    26,    26,
    71,    73,    11,    12,    19,    68,    26,    19,    19,    12,
    19,    10,    71,    70,    26,    21,    73,    26,    26,    71,
    70,    70,    70,    10,    19,    70,    72,    10,    19,    19,
    12,    17,    19,    69,    70,    19,    70,    70,    71,    69,
    68,    19,    10,    70,    69
};

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] = {
    0,    65,    66,    67,    67,    67,    67,    67,    67,    67,
    67,    67,    67,    67,    67,    67,    67,    67,    67,    67,
    67,    67,    67,    67,    67,    67,    67,    68,    68,    68,
    69,    69,    69,    70,    70,    70,    70,    71,    71,    71,
    71,    71,    71,    71,    71,    71,    72,    72,    73,    73,
    74,    74,    74,    75,    75,    75,    75,    75,    75,    75,
    76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
    76,    77
};

/* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] = {
    0,     2,     1,     3,     3,     3,     3,     3,     3,     3,
    3,     3,     3,     3,     4,     4,     5,     5,     5,     5,
    7,     7,     8,     7,     6,     2,     2,     5,     3,     1,
    5,     3,     1,     2,     3,     2,     1,     1,     3,     3,
    3,     3,     3,     3,     3,     3,     3,     1,     3,     1,
    1,     3,     3,     1,     3,     3,     3,     3,     3,     3,
    2,     2,     2,     2,     3,     5,     4,     1,     1,     1,
    1,     1
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

        case 3: {
            ppos("stm::id ASSIGN exp");
            (yyval.stm) = new cmp::AssignStatement((yyvsp[-2].idexp), (yyvsp[0].exp));
        }
        break;

        case 4: {
            ppos("stm::id PLUSASSIGN exp");
            (yyval.stm) = new cmp::AssignStatement(new cmp::IdExpression(*(yyvsp[-2].idexp)),
                                                   new cmp::BinOperandExpression((yyvsp[-2].idexp), cmp::BinaryOperand::Plus, (yyvsp[0].exp)));
        }
        break;

        case 5: {
            ppos("stm::id MINUSASSIGN exp");
            (yyval.stm) = new cmp::AssignStatement(new cmp::IdExpression(*(yyvsp[-2].idexp)),
                                                   new cmp::BinOperandExpression((yyvsp[-2].idexp), cmp::BinaryOperand::Minus, (yyvsp[0].exp)));
        }
        break;

        case 6: {
            ppos("stm::id MULASSIGN exp");
            (yyval.stm) = new cmp::AssignStatement(new cmp::IdExpression(*(yyvsp[-2].idexp)),
                                                   new cmp::BinOperandExpression((yyvsp[-2].idexp), cmp::BinaryOperand::Times, (yyvsp[0].exp)));
        }
        break;

        case 7: {
            ppos("stm::id DIVASSIGN exp");
            (yyval.stm) = new cmp::AssignStatement(new cmp::IdExpression(*(yyvsp[-2].idexp)),
                                                   new cmp::BinOperandExpression((yyvsp[-2].idexp), cmp::BinaryOperand::Div, (yyvsp[0].exp)));
        }
        break;

        case 8: {
            ppos("stm::id MODASSIGN exp");
            (yyval.stm) = new cmp::AssignStatement(new cmp::IdExpression(*(yyvsp[-2].idexp)),
                                                   new cmp::BinOperandExpression((yyvsp[-2].idexp), cmp::BinaryOperand::Mod, (yyvsp[0].exp)));
        }
        break;

        case 9: {
            ppos("stm::id ANDASSIGN exp");
            (yyval.stm) = new cmp::AssignStatement(new cmp::IdExpression(*(yyvsp[-2].idexp)),
                                                   new cmp::BinCompareExpression((yyvsp[-2].idexp), cmp::BinCompare::AND, (yyvsp[0].exp)));
        }
        break;

        case 10: {
            ppos("stm::id ORASSIGN exp");
            (yyval.stm) = new cmp::AssignStatement(new cmp::IdExpression(*(yyvsp[-2].idexp)),
                                                   new cmp::BinCompareExpression((yyvsp[-2].idexp), cmp::BinCompare::OR, (yyvsp[0].exp)));
        }
        break;

        case 11: {
            ppos("stm::id ANDASSIGN exp");
            (yyval.stm) = new cmp::AssignStatement(new cmp::IdExpression(*(yyvsp[-2].idexp)),
                                                   new cmp::BinOperandExpression((yyvsp[-2].idexp), cmp::BinaryOperand::BinAnd, (yyvsp[0].exp)));
        }
        break;

        case 12: {
            ppos("stm::id ORASSIGN exp");
            (yyval.stm) = new cmp::AssignStatement(new cmp::IdExpression(*(yyvsp[-2].idexp)),
                                                   new cmp::BinOperandExpression((yyvsp[-2].idexp), cmp::BinaryOperand::BinOr, (yyvsp[0].exp)));
        }
        break;

        case 13: {
            ppos("stm::id XORASSIGN exp");
            (yyval.stm) = new cmp::AssignStatement(new cmp::IdExpression(*(yyvsp[-2].idexp)),
                                                   new cmp::BinOperandExpression((yyvsp[-2].idexp), cmp::BinaryOperand::BinXor, (yyvsp[0].exp)));
        }
        break;

        case 14: {
            ppos("stm::PRINT(explist)");
            (yyval.stm) = new cmp::PrintStatement((yyvsp[-1].expli));
        }
        break;

        case 15: {
            ppos("stm::id(explist)");

            if (((yyvsp[-3].idexp))->id == "print")
                (yyval.stm) = new cmp::PrintStatement((yyvsp[-1].expli));
            else
                (yyval.stm) = new cmp::FunctionStatement((yyvsp[-3].idexp), (yyvsp[-1].expli));
        }
        break;

        case 16: {
            ppos("stm::IF");
            (yyval.stm) = new cmp::IfStatement((yyvsp[-3].exp), (yyvsp[-1].stm), (yyvsp[0].stm));
        }
        break;

        case 17: {
            ppos("stm::WHILE");
            (yyval.stm) = new cmp::WhileStatement((yyvsp[-3].exp), (yyvsp[-1].stm));
        }
        break;

        case 18: {
            ppos("stm::UNTIL");
            (yyval.stm) = new cmp::UntilStatement((yyvsp[-3].exp), (yyvsp[-1].stm));
        }
        break;

        case 19: {
            ppos("stm::UNLESS");
            (yyval.stm) = new cmp::UnlessStatement((yyvsp[-3].exp), (yyvsp[-1].stm));
        }
        break;

        case 20: {
            ppos("stm::UNLESS ELSE");
            (yyval.stm) = new cmp::UnlessStatement((yyvsp[-5].exp), (yyvsp[-3].stm), (yyvsp[-1].stm));
        }
        break;

        case 21: {
            ppos("stm::CASE");
            (yyval.stm) = new cmp::CaseStatement((yyvsp[-5].exp),
                                                 new cmp::WhenStatement((yyvsp[-3].exp), (yyvsp[-1].stm), (yyvsp[0].stm)));
        }
        break;

        case 22: {
            ppos("stm::CASE");
            (yyval.stm) = new cmp::CaseStatement((yyvsp[-6].exp),
                                                 new cmp::WhenStatement((yyvsp[-3].exp), (yyvsp[-1].stm), (yyvsp[0].stm)));
        }
        break;

        case 23: {
            ppos("stm::DEF id(args)");
            (yyval.stm) = new cmp::FunctionStatement((yyvsp[-5].idexp), (yyvsp[-3].expli), (yyvsp[-1].stm));
        }
        break;

        case 24: {
            ppos("stm::DEF id()");
            (yyval.stm) = new cmp::FunctionStatement((yyvsp[-4].idexp), (yyvsp[-1].stm));
        }
        break;

        case 25: {
            ppos("stm::UNDEF");
            (yyval.stm) = new cmp::UndefStatement((yyvsp[0].idexp));
        }
        break;

        case 26: {
            ppos("stm::RETURN");
            (yyval.stm) = new cmp::ReturnStatement((yyvsp[0].exp));
        }
        break;

        case 27: {
            ppos("ifstm::ELSIF");
            (yyval.stm) = new cmp::IfStatement((yyvsp[-3].exp), (yyvsp[-1].stm), (yyvsp[0].stm));
        }
        break;

        case 28: {
            ppos("ifstm::ELSE");
            (yyval.stm) = (yyvsp[-1].stm);
        }
        break;

        case 29: {
            ppos("ifstm::END");
            (yyval.stm) = nullptr;
        }
        break;

        case 30: {
            ppos("whenstm::WHEN");
            (yyval.stm) = new cmp::WhenStatement((yyvsp[-3].exp), (yyvsp[-1].stm), (yyvsp[0].stm));
        }
        break;

        case 31: {
            ppos("whenstm::ELSE");
            (yyval.stm) = new cmp::WhenStatement(nullptr, (yyvsp[-1].stm));
        }
        break;

        case 32: {
            ppos("whenstm::END");
            (yyval.stm) = nullptr;
        }
        break;

        case 33: {
            ppos("stmseq::SEMICOLON stm");
            (yyval.stm) = (yyvsp[0].stm);
        }
        break;

        case 34: {
            ppos("stmseq::stm SEMICOLON stmseq");
            (yyval.stm) = new cmp::CompoundStatement((yyvsp[-2].stm), (yyvsp[0].stm));
        }
        break;

        case 35: {
            ppos("stmseq::stm SEMICOLON");
            (yyval.stm) = (yyvsp[-1].stm);
        }
        break;

        case 36: {
            ppos("stmseq::stm");
            (yyval.stm) = (yyvsp[0].stm);
        }
        break;

        case 37: {
            ppos("expr::expr2");
            (yyval.exp) = (yyvsp[0].exp);
        }
        break;

        case 38: {
            ppos("expr::EQ");
            (yyval.exp) = new cmp::BinCompareExpression((yyvsp[-2].exp), cmp::BinCompare::EQ, (yyvsp[0].exp));
        }
        break;

        case 39: {
            ppos("expr::NEQ");
            (yyval.exp) = new cmp::BinCompareExpression((yyvsp[-2].exp), cmp::BinCompare::NEQ, (yyvsp[0].exp));
        }
        break;

        case 40: {
            ppos("expr::LT");
            (yyval.exp) = new cmp::BinCompareExpression((yyvsp[-2].exp), cmp::BinCompare::LT, (yyvsp[0].exp));
        }
        break;

        case 41: {
            ppos("expr::LE");
            (yyval.exp) = new cmp::BinCompareExpression((yyvsp[-2].exp), cmp::BinCompare::LE, (yyvsp[0].exp));
        }
        break;

        case 42: {
            ppos("expr::GT");
            (yyval.exp) = new cmp::BinCompareExpression((yyvsp[-2].exp), cmp::BinCompare::GT, (yyvsp[0].exp));
        }
        break;

        case 43: {
            ppos("expr::GE");
            (yyval.exp) = new cmp::BinCompareExpression((yyvsp[-2].exp), cmp::BinCompare::GE, (yyvsp[0].exp));
        }
        break;

        case 44: {
            ppos("expr::AND");
            (yyval.exp) = new cmp::BinCompareExpression((yyvsp[-2].exp), cmp::BinCompare::AND, (yyvsp[0].exp));
        }
        break;

        case 45: {
            ppos("expr::OR");
            (yyval.exp) = new cmp::BinCompareExpression((yyvsp[-2].exp), cmp::BinCompare::OR, (yyvsp[0].exp));
        }
        break;

        case 46: {
            ppos("arglist::id COMMA args");
            (yyval.expli) = new cmp::PairExpressionList((yyvsp[-2].idexp), (yyvsp[0].expli));
        }
        break;

        case 47: {
            ppos("arglist::id");
            (yyval.expli) = new cmp::LastExpressionList((yyvsp[0].idexp));
        }
        break;

        case 48: {
            ppos("explist::exp COMMA explist");
            (yyval.expli) = new cmp::PairExpressionList((yyvsp[-2].exp), (yyvsp[0].expli));
        }
        break;

        case 49: {
            ppos("explist::exp");
            (yyval.expli) = new cmp::LastExpressionList((yyvsp[0].exp));
        }
        break;

        case 50: {
            ppos("expr2::expr3");
            (yyval.exp) = (yyvsp[0].exp);
        }
        break;

        case 51: {
            ppos("expr2::PLUS");
            (yyval.exp) = new cmp::BinOperandExpression((yyvsp[-2].exp), cmp::BinaryOperand::Plus, (yyvsp[0].exp));
        }
        break;

        case 52: {
            ppos("expr2::MINUS");
            (yyval.exp) = new cmp::BinOperandExpression((yyvsp[-2].exp), cmp::BinaryOperand::Minus, (yyvsp[0].exp));
        }
        break;

        case 53: {
            ppos("expr3::expr4");
            (yyval.exp) = (yyvsp[0].exp);
        }
        break;

        case 54: {
            ppos("expr3::TIMES");
            (yyval.exp) = new cmp::BinOperandExpression((yyvsp[-2].exp), cmp::BinaryOperand::Times, (yyvsp[0].exp));
        }
        break;

        case 55: {
            ppos("expr3::DIVIDE");
            (yyval.exp) = new cmp::BinOperandExpression((yyvsp[-2].exp), cmp::BinaryOperand::Div, (yyvsp[0].exp));
        }
        break;

        case 56: {
            ppos("expr3::MOD");
            (yyval.exp) = new cmp::BinOperandExpression((yyvsp[-2].exp), cmp::BinaryOperand::Mod, (yyvsp[0].exp));
        }
        break;

        case 57: {
            ppos("expr3::BINAND");
            (yyval.exp) = new cmp::BinOperandExpression((yyvsp[-2].exp), cmp::BinaryOperand::BinAnd, (yyvsp[0].exp));
        }
        break;

        case 58: {
            ppos("expr3::BINOR");
            (yyval.exp) = new cmp::BinOperandExpression((yyvsp[-2].exp), cmp::BinaryOperand::BinOr, (yyvsp[0].exp));
        }
        break;

        case 59: {
            ppos("expr3::BINXOR");
            (yyval.exp) = new cmp::BinOperandExpression((yyvsp[-2].exp), cmp::BinaryOperand::BinXor, (yyvsp[0].exp));
        }
        break;

        case 60: {
            ppos("expr4::PLUS");
            (yyval.exp) = new cmp::UnaryOperandExpression(cmp::UnaryOperand::Plus, (yyvsp[0].exp));
        }
        break;

        case 61: {
            ppos("expr4::MINUS");
            (yyval.exp) = new cmp::UnaryOperandExpression(cmp::UnaryOperand::Minus, (yyvsp[0].exp));
        }
        break;

        case 62: {
            ppos("expr4::NOT");
            (yyval.exp) = new cmp::UnaryOperandExpression(cmp::UnaryOperand::Not, (yyvsp[0].exp));
        }
        break;

        case 63: {
            ppos("expr4::BINNOT");
            (yyval.exp) = new cmp::UnaryOperandExpression(cmp::UnaryOperand::BinNot, (yyvsp[0].exp));
        }
        break;

        case 64: {
            ppos("expr4::(exp)");
            (yyval.exp) = (yyvsp[-1].exp);
        }
        break;

        case 65: {
            ppos("expr4::(stm,exp)");
            (yyval.exp) = new cmp::ExpseqExpression((yyvsp[-3].stm), (yyvsp[-1].exp));
        }
        break;

        case 66: {
            ppos("expr4::id(explist)");
            (yyval.exp) = new cmp::FunctionExpression((yyvsp[-3].idexp), (yyvsp[-1].expli));
        }
        break;

        case 67: {
            ppos("expr4::int");
            std::string raw{yytext, size_t(yyleng)};
            utils::string::erase_all(raw, "_");
            const auto val = utils::misc::lexical_cast<int32_t>(raw);
            (yyval.exp) = new cmp::ValueExpression(val);
        }
        break;

        case 68: {
            ppos("expr4::real");
            std::string raw{yytext, size_t(yyleng)};
            utils::string::erase_all(raw, "_");
            const auto val = utils::misc::lexical_cast<double>(raw);
            (yyval.exp) = new cmp::ValueExpression(val);
        }
        break;

        case 69: {
            ppos("expr4::bool");
            (yyval.exp) = new cmp::ValueExpression(yytext[0] == 't');
        }
        break;

        case 70: {
            ppos("expr4::id");
            (yyval.exp) = (yyvsp[0].idexp);
        }
        break;

        case 71: {
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
