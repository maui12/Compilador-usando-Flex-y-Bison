/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

#include "ast.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void yyerror(const char *s);
extern int yylex();

NodoAST* raiz_ast = NULL;

#define MAX_VARS 100
static Simbolo tabla_simbolos[MAX_VARS];
static int num_simbolos = 0;

void imprimir_valor(Simbolo* s) {
    if (s->tipo == TIPO_ENTERO) {
        printf("%d\n", s->valor.entero);
    } else if (s->tipo == TIPO_FLOTANTE) {
        printf("%f\n", s->valor.flotante);
    } else if (s->tipo == TIPO_CADENA) {
        printf("%s\n", s->valor.cadena);
    }
}

int ejecutar = 1;
int ultima_condicion = 0;

#line 100 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ENTERO = 3,                     /* ENTERO  */
  YYSYMBOL_FLOTANTE = 4,                   /* FLOTANTE  */
  YYSYMBOL_CADENA = 5,                     /* CADENA  */
  YYSYMBOL_SI = 6,                         /* SI  */
  YYSYMBOL_SINO = 7,                       /* SINO  */
  YYSYMBOL_MIENTRAS = 8,                   /* MIENTRAS  */
  YYSYMBOL_IMPRIMIR = 9,                   /* IMPRIMIR  */
  YYSYMBOL_LEER = 10,                      /* LEER  */
  YYSYMBOL_ID = 11,                        /* ID  */
  YYSYMBOL_ENTERO_LIT = 12,                /* ENTERO_LIT  */
  YYSYMBOL_FLOTANTE_LIT = 13,              /* FLOTANTE_LIT  */
  YYSYMBOL_CADENA_LIT = 14,                /* CADENA_LIT  */
  YYSYMBOL_AND = 15,                       /* AND  */
  YYSYMBOL_OR = 16,                        /* OR  */
  YYSYMBOL_NOT = 17,                       /* NOT  */
  YYSYMBOL_IGUAL = 18,                     /* IGUAL  */
  YYSYMBOL_NO_IGUAL = 19,                  /* NO_IGUAL  */
  YYSYMBOL_MENOR = 20,                     /* MENOR  */
  YYSYMBOL_MAYOR = 21,                     /* MAYOR  */
  YYSYMBOL_MENOR_IGUAL = 22,               /* MENOR_IGUAL  */
  YYSYMBOL_MAYOR_IGUAL = 23,               /* MAYOR_IGUAL  */
  YYSYMBOL_ASSIGN = 24,                    /* ASSIGN  */
  YYSYMBOL_25_ = 25,                       /* '+'  */
  YYSYMBOL_26_ = 26,                       /* '-'  */
  YYSYMBOL_27_ = 27,                       /* '*'  */
  YYSYMBOL_28_ = 28,                       /* '/'  */
  YYSYMBOL_29_ = 29,                       /* ';'  */
  YYSYMBOL_30_ = 30,                       /* '('  */
  YYSYMBOL_31_ = 31,                       /* ')'  */
  YYSYMBOL_32_ = 32,                       /* '{'  */
  YYSYMBOL_33_ = 33,                       /* '}'  */
  YYSYMBOL_YYACCEPT = 34,                  /* $accept  */
  YYSYMBOL_programa = 35,                  /* programa  */
  YYSYMBOL_lista_declaraciones = 36,       /* lista_declaraciones  */
  YYSYMBOL_declaracion = 37,               /* declaracion  */
  YYSYMBOL_declaracion_entero = 38,        /* declaracion_entero  */
  YYSYMBOL_declaracion_flotante = 39,      /* declaracion_flotante  */
  YYSYMBOL_declaracion_cadena = 40,        /* declaracion_cadena  */
  YYSYMBOL_asignacion = 41,                /* asignacion  */
  YYSYMBOL_si = 42,                        /* si  */
  YYSYMBOL_mientras = 43,                  /* mientras  */
  YYSYMBOL_bloque = 44,                    /* bloque  */
  YYSYMBOL_imprimir = 45,                  /* imprimir  */
  YYSYMBOL_leer = 46,                      /* leer  */
  YYSYMBOL_condicion = 47,                 /* condicion  */
  YYSYMBOL_expresion = 48,                 /* expresion  */
  YYSYMBOL_termino = 49,                   /* termino  */
  YYSYMBOL_factor = 50                     /* factor  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  32
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   101

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  34
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  17
/* YYNRULES -- Number of rules.  */
#define YYNRULES  45
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  88

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   279


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      30,    31,    27,    25,     2,    26,     2,    28,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    29,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    32,     2,    33,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    62,    62,    66,    67,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    82,    88,    94,   100,   105,   110,
     118,   123,   124,   127,   144,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   178,   179,   180,   183,   184,
     185,   188,   189,   193,   197,   198
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "ENTERO", "FLOTANTE",
  "CADENA", "SI", "SINO", "MIENTRAS", "IMPRIMIR", "LEER", "ID",
  "ENTERO_LIT", "FLOTANTE_LIT", "CADENA_LIT", "AND", "OR", "NOT", "IGUAL",
  "NO_IGUAL", "MENOR", "MAYOR", "MENOR_IGUAL", "MAYOR_IGUAL", "ASSIGN",
  "'+'", "'-'", "'*'", "'/'", "';'", "'('", "')'", "'{'", "'}'", "$accept",
  "programa", "lista_declaraciones", "declaracion", "declaracion_entero",
  "declaracion_flotante", "declaracion_cadena", "asignacion", "si",
  "mientras", "bloque", "imprimir", "leer", "condicion", "expresion",
  "termino", "factor", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-28)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      48,   -10,    -5,     3,    -1,    17,    20,     5,    42,    16,
      69,    48,   -28,    54,    61,    64,    65,   -28,   -28,   -28,
      67,    68,   -28,   -28,   -28,    -2,    -2,    49,   -28,    49,
     -28,    35,   -28,   -28,   -28,   -28,   -28,   -28,   -28,   -28,
     -28,   -28,   -28,   -28,    49,    49,    40,    66,   -23,   -28,
      70,   -18,    50,   -28,    50,    39,    63,    49,    49,    49,
      49,    49,    49,    49,    49,    49,    49,    49,    49,    63,
     -28,   -28,    91,    50,    50,    50,    50,    50,    50,    50,
      50,   -23,   -23,   -28,   -28,   -28,    63,   -28
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     2,     3,     0,     0,     0,     0,     9,    10,    13,
       0,     0,    14,    15,    16,     0,     0,     0,    24,     0,
      22,     0,     1,     4,     5,     6,     7,     8,    11,    12,
      45,    42,    43,    44,     0,     0,     0,    34,    37,    40,
       0,     0,    17,    21,    33,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      23,    41,    18,    31,    32,    25,    26,    27,    28,    29,
      30,    35,    36,    38,    39,    20,     0,    19
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -28,   -28,    90,    -8,   -28,   -28,   -28,   -28,   -28,   -28,
     -14,   -28,   -28,    74,   -27,     8,    10
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    46,    47,    48,    49
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      51,    22,    52,    33,    67,    68,    23,    65,    66,    40,
      41,    42,    43,    70,    24,    44,    28,    54,    55,     1,
       2,     3,     4,    33,     5,     6,     7,     8,    45,    25,
      73,    74,    75,    76,    77,    78,    79,    80,     1,     2,
       3,     4,    72,     5,     6,     7,     8,    26,     9,    30,
      27,     1,     2,     3,     4,    85,     5,     6,     7,     8,
      40,    41,    42,    43,    65,    66,    29,     9,    53,    32,
      71,    56,    87,    81,    82,    65,    66,    83,    84,    45,
       9,    57,    58,    34,    59,    60,    61,    62,    63,    64,
      35,    65,    66,    36,    37,     9,    38,    39,    86,    31,
      50,    69
};

static const yytype_int8 yycheck[] =
{
      27,    11,    29,    11,    27,    28,    11,    25,    26,    11,
      12,    13,    14,    31,    11,    17,    11,    44,    45,     3,
       4,     5,     6,    31,     8,     9,    10,    11,    30,    30,
      57,    58,    59,    60,    61,    62,    63,    64,     3,     4,
       5,     6,    56,     8,     9,    10,    11,    30,    32,    33,
      30,     3,     4,     5,     6,    69,     8,     9,    10,    11,
      11,    12,    13,    14,    25,    26,    24,    32,    33,     0,
      31,    31,    86,    65,    66,    25,    26,    67,    68,    30,
      32,    15,    16,    29,    18,    19,    20,    21,    22,    23,
      29,    25,    26,    29,    29,    32,    29,    29,     7,     9,
      26,    31
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,     8,     9,    10,    11,    32,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    11,    11,    11,    30,    30,    30,    11,    24,
      33,    36,     0,    37,    29,    29,    29,    29,    29,    29,
      11,    12,    13,    14,    17,    30,    47,    48,    49,    50,
      47,    48,    48,    33,    48,    48,    31,    15,    16,    18,
      19,    20,    21,    22,    23,    25,    26,    27,    28,    31,
      31,    31,    44,    48,    48,    48,    48,    48,    48,    48,
      48,    49,    49,    50,    50,    44,     7,    44
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    34,    35,    36,    36,    37,    37,    37,    37,    37,
      37,    37,    37,    37,    38,    39,    40,    41,    42,    42,
      43,    44,    44,    45,    46,    47,    47,    47,    47,    47,
      47,    47,    47,    47,    47,    48,    48,    48,    49,    49,
      49,    50,    50,    50,    50,    50
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     2,     2,     2,     2,     1,
       1,     2,     2,     1,     2,     2,     2,     3,     5,     7,
       5,     3,     2,     4,     2,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     1,     3,     3,     1,     3,     3,
       1,     3,     1,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

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
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* programa: lista_declaraciones  */
#line 62 "parser.y"
                              { raiz_ast = (yyvsp[0].nodo); }
#line 1190 "parser.tab.c"
    break;

  case 4: /* lista_declaraciones: lista_declaraciones declaracion  */
#line 67 "parser.y"
                                      { (yyval.nodo) = crear_nodo(';', (yyvsp[-1].nodo), (yyvsp[0].nodo), TIPO_DESCONOCIDO); }
#line 1196 "parser.tab.c"
    break;

  case 5: /* declaracion: declaracion_entero ';'  */
#line 71 "parser.y"
                           { (yyval.nodo) = (yyvsp[-1].nodo); }
#line 1202 "parser.tab.c"
    break;

  case 6: /* declaracion: declaracion_flotante ';'  */
#line 72 "parser.y"
                               { (yyval.nodo) = (yyvsp[-1].nodo); }
#line 1208 "parser.tab.c"
    break;

  case 7: /* declaracion: declaracion_cadena ';'  */
#line 73 "parser.y"
                             { (yyval.nodo) = (yyvsp[-1].nodo); }
#line 1214 "parser.tab.c"
    break;

  case 8: /* declaracion: asignacion ';'  */
#line 74 "parser.y"
                     { (yyval.nodo) = (yyvsp[-1].nodo); }
#line 1220 "parser.tab.c"
    break;

  case 11: /* declaracion: imprimir ';'  */
#line 77 "parser.y"
                   { (yyval.nodo) = (yyvsp[-1].nodo); }
#line 1226 "parser.tab.c"
    break;

  case 12: /* declaracion: leer ';'  */
#line 78 "parser.y"
               { (yyval.nodo) = (yyvsp[-1].nodo); }
#line 1232 "parser.tab.c"
    break;

  case 14: /* declaracion_entero: ENTERO ID  */
#line 82 "parser.y"
                              { 
    (yyval.nodo) = crear_nodo('D', crear_hoja(ID, (yyvsp[0].cadena), TIPO_ENTERO), NULL, TIPO_ENTERO);
    agregar_simbolo((yyvsp[0].cadena), TIPO_ENTERO);
}
#line 1241 "parser.tab.c"
    break;

  case 15: /* declaracion_flotante: FLOTANTE ID  */
#line 88 "parser.y"
                                  { 
    (yyval.nodo) = crear_nodo('D', crear_hoja(ID, (yyvsp[0].cadena), TIPO_FLOTANTE), NULL, TIPO_FLOTANTE);
    agregar_simbolo((yyvsp[0].cadena), TIPO_FLOTANTE);
}
#line 1250 "parser.tab.c"
    break;

  case 16: /* declaracion_cadena: CADENA ID  */
#line 94 "parser.y"
                              { 
    (yyval.nodo) = crear_nodo('D', crear_hoja(ID, (yyvsp[0].cadena), TIPO_CADENA), NULL, TIPO_CADENA);
    agregar_simbolo((yyvsp[0].cadena), TIPO_CADENA);
}
#line 1259 "parser.tab.c"
    break;

  case 17: /* asignacion: ID ASSIGN expresion  */
#line 100 "parser.y"
                                { 
    (yyval.nodo) = crear_nodo('=', crear_hoja(ID, (yyvsp[-2].cadena), TIPO_DESCONOCIDO), (yyvsp[0].nodo), TIPO_DESCONOCIDO); 
}
#line 1267 "parser.tab.c"
    break;

  case 18: /* si: SI '(' condicion ')' bloque  */
#line 105 "parser.y"
                                { 
    (yyval.nodo) = crear_nodo(SI, (yyvsp[-2].nodo), (yyvsp[0].nodo), TIPO_DESCONOCIDO); 
    ultima_condicion = evaluar_condicion((yyvsp[-2].nodo));
    ejecutar = ultima_condicion;
}
#line 1277 "parser.tab.c"
    break;

  case 19: /* si: SI '(' condicion ')' bloque SINO bloque  */
#line 110 "parser.y"
                                           { 
    (yyval.nodo) = crear_nodo(SI, (yyvsp[-4].nodo), (yyvsp[-2].nodo), TIPO_DESCONOCIDO);
    (yyval.nodo)->extra = (yyvsp[0].nodo);
    ultima_condicion = evaluar_condicion((yyvsp[-4].nodo));
    ejecutar = ultima_condicion;
}
#line 1288 "parser.tab.c"
    break;

  case 20: /* mientras: MIENTRAS '(' condicion ')' bloque  */
#line 118 "parser.y"
                                            { 
    (yyval.nodo) = crear_nodo(MIENTRAS, (yyvsp[-2].nodo), (yyvsp[0].nodo), TIPO_DESCONOCIDO); 
}
#line 1296 "parser.tab.c"
    break;

  case 21: /* bloque: '{' lista_declaraciones '}'  */
#line 123 "parser.y"
                                    { (yyval.nodo) = (yyvsp[-1].nodo); }
#line 1302 "parser.tab.c"
    break;

  case 22: /* bloque: '{' '}'  */
#line 124 "parser.y"
                { (yyval.nodo) = NULL; }
#line 1308 "parser.tab.c"
    break;

  case 23: /* imprimir: IMPRIMIR '(' expresion ')'  */
#line 127 "parser.y"
                                     {
    if (ejecutar) {
        if ((yyvsp[-1].nodo)->tipo_nodo == ID) {
            Simbolo* s = buscar_simbolo((yyvsp[-1].nodo)->nombre);
            if (s) imprimir_valor(s);
        } else if ((yyvsp[-1].nodo)->tipo_nodo == ENTERO_LIT) {
            printf("%d\n", (yyvsp[-1].nodo)->valor.entero);
        } else if ((yyvsp[-1].nodo)->tipo_nodo == FLOTANTE_LIT) {
            printf("%f\n", (yyvsp[-1].nodo)->valor.flotante);
        } else if ((yyvsp[-1].nodo)->tipo_nodo == CADENA_LIT) {
            printf("%s\n", (yyvsp[-1].nodo)->valor.cadena);
        }
    }
    (yyval.nodo) = crear_nodo(IMPRIMIR, (yyvsp[-1].nodo), NULL, TIPO_DESCONOCIDO);
}
#line 1328 "parser.tab.c"
    break;

  case 24: /* leer: LEER ID  */
#line 144 "parser.y"
              { 
    (yyval.nodo) = crear_nodo(LEER, crear_hoja(ID, (yyvsp[0].cadena), TIPO_DESCONOCIDO), NULL, TIPO_DESCONOCIDO); 
    Simbolo* s = buscar_simbolo((yyvsp[0].cadena));
    if (!s) {
        fprintf(stderr, "Error: Variable '%s' no declarada\n", (yyvsp[0].cadena));
        exit(EXIT_FAILURE);
    }
    if (ejecutar) {
        if (s->tipo == TIPO_ENTERO) {
            scanf("%d", &s->valor.entero);
        } else if (s->tipo == TIPO_FLOTANTE) {
            scanf("%f", &s->valor.flotante);
        } else if (s->tipo == TIPO_CADENA) {
            char buffer[256];
            scanf("%255s", buffer);
            if (s->valor.cadena) free(s->valor.cadena);
            s->valor.cadena = strdup(buffer);
        }
    }
}
#line 1353 "parser.tab.c"
    break;

  case 25: /* condicion: expresion IGUAL expresion  */
#line 166 "parser.y"
                                     { (yyval.nodo) = crear_nodo(IGUAL, (yyvsp[-2].nodo), (yyvsp[0].nodo), TIPO_DESCONOCIDO); }
#line 1359 "parser.tab.c"
    break;

  case 26: /* condicion: expresion NO_IGUAL expresion  */
#line 167 "parser.y"
                                        { (yyval.nodo) = crear_nodo(NO_IGUAL, (yyvsp[-2].nodo), (yyvsp[0].nodo), TIPO_DESCONOCIDO); }
#line 1365 "parser.tab.c"
    break;

  case 27: /* condicion: expresion MENOR expresion  */
#line 168 "parser.y"
                                     { (yyval.nodo) = crear_nodo(MENOR, (yyvsp[-2].nodo), (yyvsp[0].nodo), TIPO_DESCONOCIDO); }
#line 1371 "parser.tab.c"
    break;

  case 28: /* condicion: expresion MAYOR expresion  */
#line 169 "parser.y"
                                     { (yyval.nodo) = crear_nodo(MAYOR, (yyvsp[-2].nodo), (yyvsp[0].nodo), TIPO_DESCONOCIDO); }
#line 1377 "parser.tab.c"
    break;

  case 29: /* condicion: expresion MENOR_IGUAL expresion  */
#line 170 "parser.y"
                                           { (yyval.nodo) = crear_nodo(MENOR_IGUAL, (yyvsp[-2].nodo), (yyvsp[0].nodo), TIPO_DESCONOCIDO); }
#line 1383 "parser.tab.c"
    break;

  case 30: /* condicion: expresion MAYOR_IGUAL expresion  */
#line 171 "parser.y"
                                           { (yyval.nodo) = crear_nodo(MAYOR_IGUAL, (yyvsp[-2].nodo), (yyvsp[0].nodo), TIPO_DESCONOCIDO); }
#line 1389 "parser.tab.c"
    break;

  case 31: /* condicion: expresion AND expresion  */
#line 172 "parser.y"
                                   { (yyval.nodo) = crear_nodo(AND, (yyvsp[-2].nodo), (yyvsp[0].nodo), TIPO_DESCONOCIDO); }
#line 1395 "parser.tab.c"
    break;

  case 32: /* condicion: expresion OR expresion  */
#line 173 "parser.y"
                                  { (yyval.nodo) = crear_nodo(OR, (yyvsp[-2].nodo), (yyvsp[0].nodo), TIPO_DESCONOCIDO); }
#line 1401 "parser.tab.c"
    break;

  case 33: /* condicion: NOT expresion  */
#line 174 "parser.y"
                         { (yyval.nodo) = crear_nodo(NOT, (yyvsp[0].nodo), NULL, TIPO_DESCONOCIDO); }
#line 1407 "parser.tab.c"
    break;

  case 34: /* condicion: expresion  */
#line 175 "parser.y"
                     { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1413 "parser.tab.c"
    break;

  case 35: /* expresion: expresion '+' termino  */
#line 178 "parser.y"
                                 { (yyval.nodo) = crear_nodo('+', (yyvsp[-2].nodo), (yyvsp[0].nodo), TIPO_DESCONOCIDO); }
#line 1419 "parser.tab.c"
    break;

  case 36: /* expresion: expresion '-' termino  */
#line 179 "parser.y"
                                 { (yyval.nodo) = crear_nodo('-', (yyvsp[-2].nodo), (yyvsp[0].nodo), TIPO_DESCONOCIDO); }
#line 1425 "parser.tab.c"
    break;

  case 37: /* expresion: termino  */
#line 180 "parser.y"
                   { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1431 "parser.tab.c"
    break;

  case 38: /* termino: termino '*' factor  */
#line 183 "parser.y"
                            { (yyval.nodo) = crear_nodo('*', (yyvsp[-2].nodo), (yyvsp[0].nodo), TIPO_DESCONOCIDO); }
#line 1437 "parser.tab.c"
    break;

  case 39: /* termino: termino '/' factor  */
#line 184 "parser.y"
                            { (yyval.nodo) = crear_nodo('/', (yyvsp[-2].nodo), (yyvsp[0].nodo), TIPO_DESCONOCIDO); }
#line 1443 "parser.tab.c"
    break;

  case 40: /* termino: factor  */
#line 185 "parser.y"
                { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1449 "parser.tab.c"
    break;

  case 41: /* factor: '(' expresion ')'  */
#line 188 "parser.y"
                          { (yyval.nodo) = (yyvsp[-1].nodo); }
#line 1455 "parser.tab.c"
    break;

  case 42: /* factor: ENTERO_LIT  */
#line 189 "parser.y"
                   { 
          (yyval.nodo) = crear_hoja(ENTERO_LIT, NULL, TIPO_ENTERO);
          (yyval.nodo)->valor.entero = (yyvsp[0].entero);
        }
#line 1464 "parser.tab.c"
    break;

  case 43: /* factor: FLOTANTE_LIT  */
#line 193 "parser.y"
                     { 
          (yyval.nodo) = crear_hoja(FLOTANTE_LIT, NULL, TIPO_FLOTANTE);
          (yyval.nodo)->valor.flotante = (yyvsp[0].flotante);
        }
#line 1473 "parser.tab.c"
    break;

  case 44: /* factor: CADENA_LIT  */
#line 197 "parser.y"
                   { (yyval.nodo) = crear_hoja(CADENA_LIT, (yyvsp[0].cadena), TIPO_CADENA); }
#line 1479 "parser.tab.c"
    break;

  case 45: /* factor: ID  */
#line 198 "parser.y"
           { (yyval.nodo) = crear_hoja(ID, (yyvsp[0].cadena), TIPO_DESCONOCIDO); }
#line 1485 "parser.tab.c"
    break;


#line 1489 "parser.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 201 "parser.y"


void yyerror(const char *s) {
    extern char *yytext;
    fprintf(stderr, "Error sintáctico en '%s': %s\n", yytext, s);
}

int main() {
    raiz_ast = NULL;
    yyparse();
    
    if (raiz_ast) {
        ejecutar_ast(raiz_ast);
        liberar_ast(raiz_ast);
    }
    
    return 0;
}

Simbolo* buscar_simbolo(const char* nombre) {
    for (int i = 0; i < num_simbolos; i++) {
        if (strcmp(tabla_simbolos[i].nombre, nombre) == 0) {
            return &tabla_simbolos[i];
        }
    }
    return NULL;
}

void agregar_simbolo(const char* nombre, TipoDato tipo) {
    if (buscar_simbolo(nombre) {
        fprintf(stderr, "Error: Variable '%s' ya declarada\n", nombre);
        exit(EXIT_FAILURE);
    }
    if (num_simbolos >= MAX_VARS) {
        fprintf(stderr, "Error: Tabla de símbolos llena\n");
        exit(EXIT_FAILURE);
    }
    tabla_simbolos[num_simbolos].nombre = strdup(nombre);
    tabla_simbolos[num_simbolos].tipo = tipo;
    num_simbolos++;
}
