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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

/* AST Node Structure */
#include "ast.h"

/* Function Prototypes */
void free_symbol_table(void);

/* External declarations from the lexer */
extern int yylex();
extern int line_count;
extern char* yytext;
extern FILE* yyin;
void print_symbol_table(void);

void yyerror(const char *s);

/* Root of the AST */
ASTNode *ast_root = NULL;

#line 96 "parser.tab.c"

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
  YYSYMBOL_IDENTIFIER = 3,                 /* IDENTIFIER  */
  YYSYMBOL_INT_CONST = 4,                  /* INT_CONST  */
  YYSYMBOL_FLOAT_CONST = 5,                /* FLOAT_CONST  */
  YYSYMBOL_CHAR_CONST = 6,                 /* CHAR_CONST  */
  YYSYMBOL_BIN_CONST = 7,                  /* BIN_CONST  */
  YYSYMBOL_COMPLEX_CONST = 8,              /* COMPLEX_CONST  */
  YYSYMBOL_STRING_LITERAL = 9,             /* STRING_LITERAL  */
  YYSYMBOL_BIT_STRING = 10,                /* BIT_STRING  */
  YYSYMBOL_HEX_STRING = 11,                /* HEX_STRING  */
  YYSYMBOL_KEYWORD_DECLARE = 12,           /* KEYWORD_DECLARE  */
  YYSYMBOL_KEYWORD_PROCEDURE = 13,         /* KEYWORD_PROCEDURE  */
  YYSYMBOL_KEYWORD_OPTIONS = 14,           /* KEYWORD_OPTIONS  */
  YYSYMBOL_KEYWORD_MAIN = 15,              /* KEYWORD_MAIN  */
  YYSYMBOL_KEYWORD_RECURSIVE = 16,         /* KEYWORD_RECURSIVE  */
  YYSYMBOL_KEYWORD_RETURNS = 17,           /* KEYWORD_RETURNS  */
  YYSYMBOL_KEYWORD_RETURN = 18,            /* KEYWORD_RETURN  */
  YYSYMBOL_KEYWORD_CALL = 19,              /* KEYWORD_CALL  */
  YYSYMBOL_KEYWORD_END = 20,               /* KEYWORD_END  */
  YYSYMBOL_KEYWORD_FIXED = 21,             /* KEYWORD_FIXED  */
  YYSYMBOL_KEYWORD_FLOAT = 22,             /* KEYWORD_FLOAT  */
  YYSYMBOL_KEYWORD_BINARY = 23,            /* KEYWORD_BINARY  */
  YYSYMBOL_KEYWORD_DECIMAL = 24,           /* KEYWORD_DECIMAL  */
  YYSYMBOL_KEYWORD_BIT = 25,               /* KEYWORD_BIT  */
  YYSYMBOL_KEYWORD_CHARACTER = 26,         /* KEYWORD_CHARACTER  */
  YYSYMBOL_KEYWORD_COMPLEX = 27,           /* KEYWORD_COMPLEX  */
  YYSYMBOL_KEYWORD_POINTER = 28,           /* KEYWORD_POINTER  */
  YYSYMBOL_KEYWORD_VARYING = 29,           /* KEYWORD_VARYING  */
  YYSYMBOL_KEYWORD_INITIAL = 30,           /* KEYWORD_INITIAL  */
  YYSYMBOL_KEYWORD_IF = 31,                /* KEYWORD_IF  */
  YYSYMBOL_KEYWORD_THEN = 32,              /* KEYWORD_THEN  */
  YYSYMBOL_KEYWORD_ELSE = 33,              /* KEYWORD_ELSE  */
  YYSYMBOL_KEYWORD_DO = 34,                /* KEYWORD_DO  */
  YYSYMBOL_KEYWORD_WHILE = 35,             /* KEYWORD_WHILE  */
  YYSYMBOL_KEYWORD_UNTIL = 36,             /* KEYWORD_UNTIL  */
  YYSYMBOL_KEYWORD_TO = 37,                /* KEYWORD_TO  */
  YYSYMBOL_KEYWORD_BY = 38,                /* KEYWORD_BY  */
  YYSYMBOL_KEYWORD_LEAVE = 39,             /* KEYWORD_LEAVE  */
  YYSYMBOL_KEYWORD_ITERATE = 40,           /* KEYWORD_ITERATE  */
  YYSYMBOL_KEYWORD_SELECT = 41,            /* KEYWORD_SELECT  */
  YYSYMBOL_KEYWORD_WHEN = 42,              /* KEYWORD_WHEN  */
  YYSYMBOL_KEYWORD_OTHERWISE = 43,         /* KEYWORD_OTHERWISE  */
  YYSYMBOL_KEYWORD_GO = 44,                /* KEYWORD_GO  */
  YYSYMBOL_KEYWORD_GOTO = 45,              /* KEYWORD_GOTO  */
  YYSYMBOL_KEYWORD_PUT = 46,               /* KEYWORD_PUT  */
  YYSYMBOL_KEYWORD_GET = 47,               /* KEYWORD_GET  */
  YYSYMBOL_KEYWORD_SKIP = 48,              /* KEYWORD_SKIP  */
  YYSYMBOL_KEYWORD_LIST = 49,              /* KEYWORD_LIST  */
  YYSYMBOL_KEYWORD_EDIT = 50,              /* KEYWORD_EDIT  */
  YYSYMBOL_OP_EXPONENT = 51,               /* OP_EXPONENT  */
  YYSYMBOL_OP_CONCAT = 52,                 /* OP_CONCAT  */
  YYSYMBOL_OP_NE = 53,                     /* OP_NE  */
  YYSYMBOL_OP_NLT = 54,                    /* OP_NLT  */
  YYSYMBOL_OP_NGT = 55,                    /* OP_NGT  */
  YYSYMBOL_OP_LE = 56,                     /* OP_LE  */
  YYSYMBOL_OP_GE = 57,                     /* OP_GE  */
  YYSYMBOL_ARROW = 58,                     /* ARROW  */
  YYSYMBOL_OP_NOT = 59,                    /* OP_NOT  */
  YYSYMBOL_LOWER_THAN_ELSE = 60,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_61_ = 61,                       /* '|'  */
  YYSYMBOL_62_ = 62,                       /* '&'  */
  YYSYMBOL_63_ = 63,                       /* '='  */
  YYSYMBOL_64_ = 64,                       /* '<'  */
  YYSYMBOL_65_ = 65,                       /* '>'  */
  YYSYMBOL_66_ = 66,                       /* '+'  */
  YYSYMBOL_67_ = 67,                       /* '-'  */
  YYSYMBOL_68_ = 68,                       /* '*'  */
  YYSYMBOL_69_ = 69,                       /* '/'  */
  YYSYMBOL_UMINUS = 70,                    /* UMINUS  */
  YYSYMBOL_71_ = 71,                       /* ':'  */
  YYSYMBOL_72_ = 72,                       /* ';'  */
  YYSYMBOL_73_ = 73,                       /* '('  */
  YYSYMBOL_74_ = 74,                       /* ')'  */
  YYSYMBOL_75_ = 75,                       /* ','  */
  YYSYMBOL_76_ = 76,                       /* '.'  */
  YYSYMBOL_YYACCEPT = 77,                  /* $accept  */
  YYSYMBOL_program = 78,                   /* program  */
  YYSYMBOL_stmts = 79,                     /* stmts  */
  YYSYMBOL_stmt = 80,                      /* stmt  */
  YYSYMBOL_labels = 81,                    /* labels  */
  YYSYMBOL_simple = 82,                    /* simple  */
  YYSYMBOL_do_group = 83,                  /* do_group  */
  YYSYMBOL_opt_by = 84,                    /* opt_by  */
  YYSYMBOL_select_stmt = 85,               /* select_stmt  */
  YYSYMBOL_whens = 86,                     /* whens  */
  YYSYMBOL_opt_other = 87,                 /* opt_other  */
  YYSYMBOL_opt_params = 88,                /* opt_params  */
  YYSYMBOL_proc_opts = 89,                 /* proc_opts  */
  YYSYMBOL_decl_list = 90,                 /* decl_list  */
  YYSYMBOL_decl = 91,                      /* decl  */
  YYSYMBOL_attrs = 92,                     /* attrs  */
  YYSYMBOL_attr = 93,                      /* attr  */
  YYSYMBOL_io_opts = 94,                   /* io_opts  */
  YYSYMBOL_opt_id = 95,                    /* opt_id  */
  YYSYMBOL_id_list = 96,                   /* id_list  */
  YYSYMBOL_expr_list = 97,                 /* expr_list  */
  YYSYMBOL_ref = 98,                       /* ref  */
  YYSYMBOL_base = 99,                      /* base  */
  YYSYMBOL_expr = 100                      /* expr  */
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
typedef yytype_uint8 yy_state_t;

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   558

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  77
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  106
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  243

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   316


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
       2,     2,     2,     2,     2,     2,     2,     2,    62,     2,
      73,    74,    68,    66,    75,    67,    76,    69,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    71,    72,
      64,    63,    65,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    61,     2,     2,     2,     2,     2,
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
      55,    56,    57,    58,    59,    60,    70
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    72,    72,    78,    79,    83,    87,    88,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   106,   108,   109,
     110,   112,   113,   114,   115,   119,   121,   123,   125,   130,
     131,   135,   137,   142,   143,   148,   149,   153,   154,   158,
     159,   161,   163,   168,   169,   173,   175,   177,   179,   184,
     185,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   203,   204,   206,   208,   210,   215,   216,   220,
     222,   227,   229,   234,   235,   236,   240,   241,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274
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
  "\"end of file\"", "error", "\"invalid token\"", "IDENTIFIER",
  "INT_CONST", "FLOAT_CONST", "CHAR_CONST", "BIN_CONST", "COMPLEX_CONST",
  "STRING_LITERAL", "BIT_STRING", "HEX_STRING", "KEYWORD_DECLARE",
  "KEYWORD_PROCEDURE", "KEYWORD_OPTIONS", "KEYWORD_MAIN",
  "KEYWORD_RECURSIVE", "KEYWORD_RETURNS", "KEYWORD_RETURN", "KEYWORD_CALL",
  "KEYWORD_END", "KEYWORD_FIXED", "KEYWORD_FLOAT", "KEYWORD_BINARY",
  "KEYWORD_DECIMAL", "KEYWORD_BIT", "KEYWORD_CHARACTER", "KEYWORD_COMPLEX",
  "KEYWORD_POINTER", "KEYWORD_VARYING", "KEYWORD_INITIAL", "KEYWORD_IF",
  "KEYWORD_THEN", "KEYWORD_ELSE", "KEYWORD_DO", "KEYWORD_WHILE",
  "KEYWORD_UNTIL", "KEYWORD_TO", "KEYWORD_BY", "KEYWORD_LEAVE",
  "KEYWORD_ITERATE", "KEYWORD_SELECT", "KEYWORD_WHEN", "KEYWORD_OTHERWISE",
  "KEYWORD_GO", "KEYWORD_GOTO", "KEYWORD_PUT", "KEYWORD_GET",
  "KEYWORD_SKIP", "KEYWORD_LIST", "KEYWORD_EDIT", "OP_EXPONENT",
  "OP_CONCAT", "OP_NE", "OP_NLT", "OP_NGT", "OP_LE", "OP_GE", "ARROW",
  "OP_NOT", "LOWER_THAN_ELSE", "'|'", "'&'", "'='", "'<'", "'>'", "'+'",
  "'-'", "'*'", "'/'", "UMINUS", "':'", "';'", "'('", "')'", "','", "'.'",
  "$accept", "program", "stmts", "stmt", "labels", "simple", "do_group",
  "opt_by", "select_stmt", "whens", "opt_other", "opt_params", "proc_opts",
  "decl_list", "decl", "attrs", "attr", "io_opts", "opt_id", "id_list",
  "expr_list", "ref", "base", "expr", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-126)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-3)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -126,     9,    24,  -126,  -126,   189,   -48,    23,   -38,   118,
      40,   130,     1,    47,    47,     3,    17,    64,  -126,  -126,
    -126,  -126,  -126,  -126,   -30,  -126,  -126,   130,  -126,    -1,
      71,    29,  -126,    71,  -126,    30,  -126,  -126,  -126,  -126,
    -126,  -126,  -126,  -126,   130,   130,   130,  -126,   130,   -42,
     407,   -13,   215,    34,    38,  -126,    -7,  -126,    43,    58,
    -126,   130,   129,    82,   -31,   -28,    40,   130,    40,    31,
     451,   146,  -126,    71,  -126,    35,  -126,    23,    39,    -4,
      99,    99,    99,   287,   130,   130,   130,   130,   130,   130,
     130,   130,   130,   130,   130,   130,   130,   130,   130,   130,
    -126,  -126,  -126,   130,   130,   143,   130,  -126,  -126,   100,
     311,    92,  -126,   105,   106,   108,  -126,  -126,  -126,   429,
    -126,  -126,   130,  -126,  -126,  -126,  -126,  -126,  -126,  -126,
    -126,  -126,   109,   130,  -126,   146,    70,  -126,   162,  -126,
    -126,   113,  -126,   114,  -126,  -126,    99,    51,   -37,   -37,
     -37,   -37,   -37,   470,   489,   -37,   -37,   -37,     2,     2,
      99,    99,   160,   335,   359,    47,   248,   121,  -126,   175,
     126,  -126,   130,   130,   130,  -126,   451,   130,    72,  -126,
     146,  -126,   184,  -126,   180,  -126,   132,   133,   134,   130,
     130,  -126,   137,  -126,   383,    74,    78,    83,  -126,   146,
     136,   216,    47,  -126,  -126,  -126,  -126,   268,    85,  -126,
     100,  -126,  -126,   138,  -126,  -126,  -126,   144,   195,   197,
     130,   149,  -126,   198,   130,  -126,    47,    47,   451,  -126,
    -126,   150,    87,   152,   153,   207,  -126,  -126,  -126,  -126,
      47,   159,  -126
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     6,     1,     4,     0,    76,     0,    37,     0,
       0,     0,     0,    67,    67,     0,     0,     0,    62,    62,
      24,     5,    18,    19,     0,    73,     7,     0,    49,     0,
       0,     0,    43,     0,    39,    76,    99,   100,   101,   105,
     106,   102,   103,   104,     0,     0,     0,    10,     0,    98,
       0,     0,     0,     0,     0,     3,     0,    68,     0,     0,
      33,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      71,    45,    49,     0,    69,     0,    21,     0,     0,     0,
      96,    95,    94,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      11,     9,     6,     0,     0,     6,     0,    14,    15,    35,
       0,     0,    12,    63,     0,     0,    22,    23,    75,     0,
      74,    77,     0,    51,    52,    53,    54,    58,    59,    55,
      56,    57,     0,     0,    50,    47,     0,    49,     0,    44,
      38,     0,    41,     0,     3,    97,    82,    83,    87,    90,
      91,    88,    89,    93,    92,    84,    85,    86,    78,    79,
      80,    81,    16,     0,     0,    67,     0,     0,     6,     0,
       0,    13,     0,     0,     0,     8,    72,     0,     0,    49,
      46,    70,     0,    49,     6,     6,     0,     0,     0,     0,
       0,    36,     0,    33,     0,     0,     0,     0,    61,    48,
       0,     0,    67,    17,     3,     3,    25,    29,     0,    31,
      35,    64,    65,     0,    60,    40,    42,     0,     6,     6,
       0,     0,     6,     0,     0,    20,    67,    67,    30,     3,
      34,     0,     0,     0,     0,     6,    32,    66,    26,    27,
      67,     0,    28
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -126,  -126,   -49,   -91,  -126,  -126,  -126,  -126,  -126,    55,
      22,  -126,  -126,  -126,   172,   -71,  -126,   231,   -14,   -26,
    -125,    52,    -8,    -6
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,     4,     5,    21,    22,   221,    23,   109,
     169,    34,    79,    31,    32,    71,   134,    64,    58,    75,
      69,    49,    25,    70
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      59,   135,    72,    50,    35,    52,   105,    78,   178,     3,
     141,   162,   142,   143,    84,    85,    66,   113,   114,   115,
     113,   114,   115,    26,    -2,    27,    28,    29,    66,    96,
      97,    98,    99,    67,    68,    33,    53,    54,    80,    81,
      82,   116,    83,    35,   117,    66,    68,   136,   195,   196,
      57,    66,   197,    84,    62,   110,   106,    24,   118,   101,
     120,   119,    51,    68,    56,   208,   180,    63,   144,    68,
      98,    99,    73,    55,    74,    60,    61,   191,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   203,   184,    30,   163,   164,   232,
     166,    76,    84,    27,    77,   121,   122,   103,   199,   137,
     138,   104,   201,   140,   138,   107,   176,    96,    97,    98,
      99,    35,    36,    37,    38,    39,    40,    41,    42,    43,
     108,   230,   111,    35,    36,    37,    38,    39,    40,    41,
      42,    43,   167,   168,   179,   138,   198,   122,   212,   122,
      84,   188,   213,   122,   112,   218,   219,   214,   122,   222,
     122,   237,   122,   165,   171,   181,   194,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,    44,   172,   173,
     235,   174,   177,   207,    45,    46,   182,   183,   217,    44,
      47,    48,     6,   185,   190,   192,    45,    46,   193,   200,
     202,     7,     8,    48,   204,   205,   206,     9,    10,   209,
     215,   224,   233,   234,   228,   226,   225,   227,   231,   133,
      11,   229,   236,    12,   238,   239,   241,   240,    13,    14,
      15,   242,   223,    16,    17,    18,    19,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   102,   210,   139,
      65,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    20,     0,     0,     0,     0,    84,    85,    86,    87,
      88,    89,    90,     0,     0,     0,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   189,     0,     0,     0,   133,
     216,     0,     0,     0,     0,     0,     0,     0,     0,    84,
      85,    86,    87,    88,    89,    90,   220,     0,     0,    91,
      92,    93,    94,    95,    96,    97,    98,    99,     0,    84,
      85,    86,    87,    88,    89,    90,     0,     0,     0,    91,
      92,    93,    94,    95,    96,    97,    98,    99,    84,    85,
      86,    87,    88,    89,    90,     0,     0,     0,    91,    92,
      93,    94,    95,    96,    97,    98,    99,     0,     0,     0,
       0,   145,    84,    85,    86,    87,    88,    89,    90,     0,
       0,     0,    91,    92,    93,    94,    95,    96,    97,    98,
      99,     0,     0,     0,     0,   170,    84,    85,    86,    87,
      88,    89,    90,     0,     0,     0,    91,    92,    93,    94,
      95,    96,    97,    98,    99,     0,     0,     0,     0,   186,
      84,    85,    86,    87,    88,    89,    90,     0,     0,     0,
      91,    92,    93,    94,    95,    96,    97,    98,    99,     0,
       0,     0,     0,   187,    84,    85,    86,    87,    88,    89,
      90,     0,     0,     0,    91,    92,    93,    94,    95,    96,
      97,    98,    99,     0,     0,     0,     0,   211,    84,    85,
      86,    87,    88,    89,    90,     0,     0,     0,    91,    92,
      93,    94,    95,    96,    97,    98,    99,     0,     0,   100,
      84,    85,    86,    87,    88,    89,    90,     0,     0,     0,
      91,    92,    93,    94,    95,    96,    97,    98,    99,     0,
       0,   175,    84,    85,    86,    87,    88,    89,    90,     0,
       0,     0,    91,    92,    93,    94,    95,    96,    97,    98,
      99,    84,    85,    86,    87,    88,    89,    90,     0,     0,
       0,     0,    92,    93,    94,    95,    96,    97,    98,    99,
      84,    85,    86,    87,    88,    89,    90,     0,     0,     0,
       0,     0,    93,    94,    95,    96,    97,    98,    99
};

static const yytype_int16 yycheck[] =
{
      14,    72,     3,     9,     3,    11,    55,    33,   133,     0,
      14,   102,    16,    17,    51,    52,    58,    48,    49,    50,
      48,    49,    50,    71,     0,    73,     3,     4,    58,    66,
      67,    68,    69,    63,    76,    73,    35,    36,    44,    45,
      46,    72,    48,     3,    72,    58,    76,    73,   173,   174,
       3,    58,   177,    51,    37,    61,    63,     5,    66,    72,
      68,    67,    10,    76,    12,   190,   137,     3,    72,    76,
      68,    69,    73,    72,     3,    72,    73,   168,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   185,   144,    73,   103,   104,   224,
     106,    72,    51,    73,    75,    74,    75,    73,   179,    74,
      75,    73,   183,    74,    75,    72,   122,    66,    67,    68,
      69,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      72,   222,     3,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    42,    43,    74,    75,    74,    75,    74,    75,
      51,   165,    74,    75,    72,   204,   205,    74,    75,    74,
      75,    74,    75,    20,    72,     3,   172,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    59,    73,    73,
     229,    73,    73,   189,    66,    67,    73,    73,   202,    59,
      72,    73,     3,    33,    73,    20,    66,    67,    72,    15,
      20,    12,    13,    73,    72,    72,    72,    18,    19,    72,
      74,    73,   226,   227,   220,    20,    72,    20,    20,    73,
      31,    72,    72,    34,    72,    72,   240,    20,    39,    40,
      41,    72,   210,    44,    45,    46,    47,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    32,   193,    77,
      19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    72,    -1,    -1,    -1,    -1,    51,    52,    53,    54,
      55,    56,    57,    -1,    -1,    -1,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    37,    -1,    -1,    -1,    73,
      74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,
      52,    53,    54,    55,    56,    57,    38,    -1,    -1,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    -1,    51,
      52,    53,    54,    55,    56,    57,    -1,    -1,    -1,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    51,    52,
      53,    54,    55,    56,    57,    -1,    -1,    -1,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    -1,    -1,    -1,
      -1,    74,    51,    52,    53,    54,    55,    56,    57,    -1,
      -1,    -1,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    -1,    -1,    -1,    -1,    74,    51,    52,    53,    54,
      55,    56,    57,    -1,    -1,    -1,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    -1,    -1,    -1,    -1,    74,
      51,    52,    53,    54,    55,    56,    57,    -1,    -1,    -1,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    -1,
      -1,    -1,    -1,    74,    51,    52,    53,    54,    55,    56,
      57,    -1,    -1,    -1,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    -1,    -1,    -1,    -1,    74,    51,    52,
      53,    54,    55,    56,    57,    -1,    -1,    -1,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    -1,    -1,    72,
      51,    52,    53,    54,    55,    56,    57,    -1,    -1,    -1,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    -1,
      -1,    72,    51,    52,    53,    54,    55,    56,    57,    -1,
      -1,    -1,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    51,    52,    53,    54,    55,    56,    57,    -1,    -1,
      -1,    -1,    62,    63,    64,    65,    66,    67,    68,    69,
      51,    52,    53,    54,    55,    56,    57,    -1,    -1,    -1,
      -1,    -1,    63,    64,    65,    66,    67,    68,    69
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    78,    79,     0,    80,    81,     3,    12,    13,    18,
      19,    31,    34,    39,    40,    41,    44,    45,    46,    47,
      72,    82,    83,    85,    98,    99,    71,    73,     3,     4,
      73,    90,    91,    73,    88,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    59,    66,    67,    72,    73,    98,
     100,    98,   100,    35,    36,    72,    98,     3,    95,    95,
      72,    73,    37,     3,    94,    94,    58,    63,    76,    97,
     100,    92,     3,    73,     3,    96,    72,    75,    96,    89,
     100,   100,   100,   100,    51,    52,    53,    54,    55,    56,
      57,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      72,    72,    32,    73,    73,    79,    63,    72,    72,    86,
     100,     3,    72,    48,    49,    50,    72,    72,    99,   100,
      99,    74,    75,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    73,    93,    92,    96,    74,    75,    91,
      74,    14,    16,    17,    72,    74,   100,   100,   100,   100,
     100,   100,   100,   100,   100,   100,   100,   100,   100,   100,
     100,   100,    80,   100,   100,    20,   100,    42,    43,    87,
      74,    72,    73,    73,    73,    72,   100,    73,    97,    74,
      92,     3,    73,    73,    79,    33,    74,    74,    95,    37,
      73,    80,    20,    72,   100,    97,    97,    97,    74,    92,
      15,    92,    20,    80,    72,    72,    72,   100,    97,    72,
      86,    74,    74,    74,    74,    74,    74,    95,    79,    79,
      38,    84,    74,    87,    73,    72,    20,    20,   100,    72,
      80,    20,    97,    95,    95,    79,    72,    74,    72,    72,
      20,    95,    72
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    77,    78,    79,    79,    80,    81,    81,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    83,    83,    83,    83,    84,
      84,    85,    85,    86,    86,    87,    87,    88,    88,    89,
      89,    89,    89,    90,    90,    91,    91,    91,    91,    92,
      92,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    94,    94,    94,    94,    94,    95,    95,    96,
      96,    97,    97,    98,    98,    98,    99,    99,   100,   100,
     100,   100,   100,   100,   100,   100,   100,   100,   100,   100,
     100,   100,   100,   100,   100,   100,   100,   100,   100,   100,
     100,   100,   100,   100,   100,   100,   100
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     2,     2,     0,     3,     4,     3,
       2,     3,     3,     4,     3,     3,     4,     6,     1,     1,
       8,     3,     3,     3,     1,     6,    10,    10,    12,     0,
       2,     6,     9,     0,     6,     0,     2,     0,     3,     0,
       5,     2,     5,     1,     3,     2,     4,     3,     5,     0,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     3,     0,     2,     5,     5,     8,     0,     1,     1,
       3,     1,     3,     1,     3,     3,     1,     4,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     2,     2,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1
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
  switch (yykind)
    {
    case YYSYMBOL_IDENTIFIER: /* IDENTIFIER  */
#line 50 "parser.y"
            { free(((*yyvaluep).str)); }
#line 1149 "parser.tab.c"
        break;

    case YYSYMBOL_INT_CONST: /* INT_CONST  */
#line 50 "parser.y"
            { free(((*yyvaluep).str)); }
#line 1155 "parser.tab.c"
        break;

    case YYSYMBOL_FLOAT_CONST: /* FLOAT_CONST  */
#line 50 "parser.y"
            { free(((*yyvaluep).str)); }
#line 1161 "parser.tab.c"
        break;

    case YYSYMBOL_CHAR_CONST: /* CHAR_CONST  */
#line 50 "parser.y"
            { free(((*yyvaluep).str)); }
#line 1167 "parser.tab.c"
        break;

    case YYSYMBOL_BIN_CONST: /* BIN_CONST  */
#line 50 "parser.y"
            { free(((*yyvaluep).str)); }
#line 1173 "parser.tab.c"
        break;

    case YYSYMBOL_COMPLEX_CONST: /* COMPLEX_CONST  */
#line 50 "parser.y"
            { free(((*yyvaluep).str)); }
#line 1179 "parser.tab.c"
        break;

    case YYSYMBOL_STRING_LITERAL: /* STRING_LITERAL  */
#line 50 "parser.y"
            { free(((*yyvaluep).str)); }
#line 1185 "parser.tab.c"
        break;

    case YYSYMBOL_BIT_STRING: /* BIT_STRING  */
#line 50 "parser.y"
            { free(((*yyvaluep).str)); }
#line 1191 "parser.tab.c"
        break;

    case YYSYMBOL_HEX_STRING: /* HEX_STRING  */
#line 50 "parser.y"
            { free(((*yyvaluep).str)); }
#line 1197 "parser.tab.c"
        break;

    case YYSYMBOL_program: /* program  */
#line 52 "parser.y"
            { }
#line 1203 "parser.tab.c"
        break;

    case YYSYMBOL_stmts: /* stmts  */
#line 51 "parser.y"
            { free_ast(((*yyvaluep).node)); }
#line 1209 "parser.tab.c"
        break;

    case YYSYMBOL_stmt: /* stmt  */
#line 51 "parser.y"
            { free_ast(((*yyvaluep).node)); }
#line 1215 "parser.tab.c"
        break;

    case YYSYMBOL_labels: /* labels  */
#line 51 "parser.y"
            { free_ast(((*yyvaluep).node)); }
#line 1221 "parser.tab.c"
        break;

    case YYSYMBOL_simple: /* simple  */
#line 51 "parser.y"
            { free_ast(((*yyvaluep).node)); }
#line 1227 "parser.tab.c"
        break;

    case YYSYMBOL_do_group: /* do_group  */
#line 51 "parser.y"
            { free_ast(((*yyvaluep).node)); }
#line 1233 "parser.tab.c"
        break;

    case YYSYMBOL_opt_by: /* opt_by  */
#line 51 "parser.y"
            { free_ast(((*yyvaluep).node)); }
#line 1239 "parser.tab.c"
        break;

    case YYSYMBOL_select_stmt: /* select_stmt  */
#line 51 "parser.y"
            { free_ast(((*yyvaluep).node)); }
#line 1245 "parser.tab.c"
        break;

    case YYSYMBOL_whens: /* whens  */
#line 51 "parser.y"
            { free_ast(((*yyvaluep).node)); }
#line 1251 "parser.tab.c"
        break;

    case YYSYMBOL_opt_other: /* opt_other  */
#line 51 "parser.y"
            { free_ast(((*yyvaluep).node)); }
#line 1257 "parser.tab.c"
        break;

    case YYSYMBOL_opt_params: /* opt_params  */
#line 51 "parser.y"
            { free_ast(((*yyvaluep).node)); }
#line 1263 "parser.tab.c"
        break;

    case YYSYMBOL_proc_opts: /* proc_opts  */
#line 51 "parser.y"
            { free_ast(((*yyvaluep).node)); }
#line 1269 "parser.tab.c"
        break;

    case YYSYMBOL_decl_list: /* decl_list  */
#line 51 "parser.y"
            { free_ast(((*yyvaluep).node)); }
#line 1275 "parser.tab.c"
        break;

    case YYSYMBOL_decl: /* decl  */
#line 51 "parser.y"
            { free_ast(((*yyvaluep).node)); }
#line 1281 "parser.tab.c"
        break;

    case YYSYMBOL_attrs: /* attrs  */
#line 51 "parser.y"
            { free_ast(((*yyvaluep).node)); }
#line 1287 "parser.tab.c"
        break;

    case YYSYMBOL_attr: /* attr  */
#line 51 "parser.y"
            { free_ast(((*yyvaluep).node)); }
#line 1293 "parser.tab.c"
        break;

    case YYSYMBOL_io_opts: /* io_opts  */
#line 51 "parser.y"
            { free_ast(((*yyvaluep).node)); }
#line 1299 "parser.tab.c"
        break;

    case YYSYMBOL_opt_id: /* opt_id  */
#line 51 "parser.y"
            { free_ast(((*yyvaluep).node)); }
#line 1305 "parser.tab.c"
        break;

    case YYSYMBOL_id_list: /* id_list  */
#line 51 "parser.y"
            { free_ast(((*yyvaluep).node)); }
#line 1311 "parser.tab.c"
        break;

    case YYSYMBOL_expr_list: /* expr_list  */
#line 51 "parser.y"
            { free_ast(((*yyvaluep).node)); }
#line 1317 "parser.tab.c"
        break;

    case YYSYMBOL_ref: /* ref  */
#line 51 "parser.y"
            { free_ast(((*yyvaluep).node)); }
#line 1323 "parser.tab.c"
        break;

    case YYSYMBOL_base: /* base  */
#line 51 "parser.y"
            { free_ast(((*yyvaluep).node)); }
#line 1329 "parser.tab.c"
        break;

    case YYSYMBOL_expr: /* expr  */
#line 51 "parser.y"
            { free_ast(((*yyvaluep).node)); }
#line 1335 "parser.tab.c"
        break;

      default:
        break;
    }
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
  case 2: /* program: stmts  */
#line 72 "parser.y"
            {
        (yyval.node) = create_node("Program", NULL, 1, (yyvsp[0].node));
        ast_root = (yyval.node);
    }
#line 1608 "parser.tab.c"
    break;

  case 3: /* stmts: %empty  */
#line 78 "parser.y"
                  { (yyval.node) = create_node("StatementList", NULL, 0); }
#line 1614 "parser.tab.c"
    break;

  case 4: /* stmts: stmts stmt  */
#line 79 "parser.y"
                  { (yyval.node) = add_child((yyvsp[-1].node), (yyvsp[0].node)); }
#line 1620 "parser.tab.c"
    break;

  case 5: /* stmt: labels simple  */
#line 83 "parser.y"
                    { (yyval.node) = (yyvsp[-1].node) ? create_node("LabeledStatement", NULL, 2, (yyvsp[-1].node), (yyvsp[0].node)) : (yyvsp[0].node); }
#line 1626 "parser.tab.c"
    break;

  case 6: /* labels: %empty  */
#line 87 "parser.y"
                  { (yyval.node) = NULL; }
#line 1632 "parser.tab.c"
    break;

  case 7: /* labels: labels IDENTIFIER ':'  */
#line 88 "parser.y"
                            {
        if (!(yyvsp[-2].node)) (yyvsp[-2].node) = create_node("LabelList", NULL, 0);
        (yyval.node) = add_child((yyvsp[-2].node), create_node("Label", (yyvsp[-1].str), 0));
        free((yyvsp[-1].str));
      }
#line 1642 "parser.tab.c"
    break;

  case 8: /* simple: ref '=' expr ';'  */
#line 96 "parser.y"
                                    { (yyval.node) = create_node("Assignment", "=", 2, (yyvsp[-3].node), (yyvsp[-1].node)); }
#line 1648 "parser.tab.c"
    break;

  case 9: /* simple: KEYWORD_CALL ref ';'  */
#line 97 "parser.y"
                                         { (yyval.node) = create_node("CallStatement", NULL, 1, (yyvsp[-1].node)); }
#line 1654 "parser.tab.c"
    break;

  case 10: /* simple: KEYWORD_RETURN ';'  */
#line 98 "parser.y"
                                         { (yyval.node) = create_node("Return", NULL, 0); }
#line 1660 "parser.tab.c"
    break;

  case 11: /* simple: KEYWORD_RETURN expr ';'  */
#line 99 "parser.y"
                                         { (yyval.node) = create_node("Return", NULL, 1, (yyvsp[-1].node)); }
#line 1666 "parser.tab.c"
    break;

  case 12: /* simple: KEYWORD_GOTO IDENTIFIER ';'  */
#line 100 "parser.y"
                                         { (yyval.node) = create_node("GotoStatement", (yyvsp[-1].str), 0); free((yyvsp[-1].str)); }
#line 1672 "parser.tab.c"
    break;

  case 13: /* simple: KEYWORD_GO KEYWORD_TO IDENTIFIER ';'  */
#line 101 "parser.y"
                                              { (yyval.node) = create_node("GotoStatement", (yyvsp[-1].str), 0); free((yyvsp[-1].str)); }
#line 1678 "parser.tab.c"
    break;

  case 14: /* simple: KEYWORD_LEAVE opt_id ';'  */
#line 102 "parser.y"
                                         { (yyval.node) = create_node("LeaveStatement", NULL, 1, (yyvsp[-1].node)); }
#line 1684 "parser.tab.c"
    break;

  case 15: /* simple: KEYWORD_ITERATE opt_id ';'  */
#line 103 "parser.y"
                                         { (yyval.node) = create_node("IterateStatement", NULL, 1, (yyvsp[-1].node)); }
#line 1690 "parser.tab.c"
    break;

  case 16: /* simple: KEYWORD_IF expr KEYWORD_THEN stmt  */
#line 105 "parser.y"
                                    { (yyval.node) = create_node("IfStatement", NULL, 2, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1696 "parser.tab.c"
    break;

  case 17: /* simple: KEYWORD_IF expr KEYWORD_THEN stmt KEYWORD_ELSE stmt  */
#line 107 "parser.y"
                                    { (yyval.node) = create_node("IfElseStatement", NULL, 3, (yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1702 "parser.tab.c"
    break;

  case 18: /* simple: do_group  */
#line 108 "parser.y"
                                    { (yyval.node) = (yyvsp[0].node); }
#line 1708 "parser.tab.c"
    break;

  case 19: /* simple: select_stmt  */
#line 109 "parser.y"
                                    { (yyval.node) = (yyvsp[0].node); }
#line 1714 "parser.tab.c"
    break;

  case 20: /* simple: KEYWORD_PROCEDURE opt_params proc_opts ';' stmts KEYWORD_END opt_id ';'  */
#line 111 "parser.y"
                                    { (yyval.node) = create_node("Procedure", NULL, 4, (yyvsp[-6].node), (yyvsp[-5].node), (yyvsp[-3].node), (yyvsp[-1].node)); }
#line 1720 "parser.tab.c"
    break;

  case 21: /* simple: KEYWORD_DECLARE decl_list ';'  */
#line 112 "parser.y"
                                         { (yyval.node) = create_node("Declaration", NULL, 1, (yyvsp[-1].node)); }
#line 1726 "parser.tab.c"
    break;

  case 22: /* simple: KEYWORD_PUT io_opts ';'  */
#line 113 "parser.y"
                                         { (yyval.node) = create_node("PutStatement", NULL, 1, (yyvsp[-1].node)); }
#line 1732 "parser.tab.c"
    break;

  case 23: /* simple: KEYWORD_GET io_opts ';'  */
#line 114 "parser.y"
                                         { (yyval.node) = create_node("GetStatement", NULL, 1, (yyvsp[-1].node)); }
#line 1738 "parser.tab.c"
    break;

  case 24: /* simple: ';'  */
#line 115 "parser.y"
                                    { (yyval.node) = create_node("EmptyStatement", ";", 0); }
#line 1744 "parser.tab.c"
    break;

  case 25: /* do_group: KEYWORD_DO ';' stmts KEYWORD_END opt_id ';'  */
#line 120 "parser.y"
        { (yyval.node) = create_node("DoStatement", NULL, 1, (yyvsp[-3].node)); free_ast((yyvsp[-1].node)); }
#line 1750 "parser.tab.c"
    break;

  case 26: /* do_group: KEYWORD_DO KEYWORD_WHILE '(' expr ')' ';' stmts KEYWORD_END opt_id ';'  */
#line 122 "parser.y"
        { (yyval.node) = create_node("DoWhileStatement", NULL, 2, (yyvsp[-6].node), (yyvsp[-3].node)); free_ast((yyvsp[-1].node)); }
#line 1756 "parser.tab.c"
    break;

  case 27: /* do_group: KEYWORD_DO KEYWORD_UNTIL '(' expr ')' ';' stmts KEYWORD_END opt_id ';'  */
#line 124 "parser.y"
        { (yyval.node) = create_node("DoUntilStatement", NULL, 2, (yyvsp[-6].node), (yyvsp[-3].node)); free_ast((yyvsp[-1].node)); }
#line 1762 "parser.tab.c"
    break;

  case 28: /* do_group: KEYWORD_DO ref '=' expr KEYWORD_TO expr opt_by ';' stmts KEYWORD_END opt_id ';'  */
#line 126 "parser.y"
        { (yyval.node) = create_node("DoToStatement", NULL, 5, (yyvsp[-10].node), (yyvsp[-8].node), (yyvsp[-6].node), (yyvsp[-5].node), (yyvsp[-3].node)); free_ast((yyvsp[-1].node)); }
#line 1768 "parser.tab.c"
    break;

  case 29: /* opt_by: %empty  */
#line 130 "parser.y"
                  { (yyval.node) = NULL; }
#line 1774 "parser.tab.c"
    break;

  case 30: /* opt_by: KEYWORD_BY expr  */
#line 131 "parser.y"
                       { (yyval.node) = create_node("ByClause", NULL, 1, (yyvsp[0].node)); }
#line 1780 "parser.tab.c"
    break;

  case 31: /* select_stmt: KEYWORD_SELECT ';' whens opt_other KEYWORD_END ';'  */
#line 136 "parser.y"
        { (yyval.node) = create_node("SelectStatement", NULL, 3, NULL, (yyvsp[-3].node), (yyvsp[-2].node)); }
#line 1786 "parser.tab.c"
    break;

  case 32: /* select_stmt: KEYWORD_SELECT '(' expr ')' ';' whens opt_other KEYWORD_END ';'  */
#line 138 "parser.y"
        { (yyval.node) = create_node("SelectStatement", NULL, 3, (yyvsp[-6].node), (yyvsp[-3].node), (yyvsp[-2].node)); }
#line 1792 "parser.tab.c"
    break;

  case 33: /* whens: %empty  */
#line 142 "parser.y"
                  { (yyval.node) = create_node("WhenList", NULL, 0); }
#line 1798 "parser.tab.c"
    break;

  case 34: /* whens: whens KEYWORD_WHEN '(' expr_list ')' stmt  */
#line 144 "parser.y"
        { (yyval.node) = add_child((yyvsp[-5].node), create_node("WhenClause", NULL, 2, (yyvsp[-2].node), (yyvsp[0].node))); }
#line 1804 "parser.tab.c"
    break;

  case 35: /* opt_other: %empty  */
#line 148 "parser.y"
                          { (yyval.node) = NULL; }
#line 1810 "parser.tab.c"
    break;

  case 36: /* opt_other: KEYWORD_OTHERWISE stmt  */
#line 149 "parser.y"
                               { (yyval.node) = create_node("OtherwiseClause", NULL, 1, (yyvsp[0].node)); }
#line 1816 "parser.tab.c"
    break;

  case 37: /* opt_params: %empty  */
#line 153 "parser.y"
                          { (yyval.node) = NULL; }
#line 1822 "parser.tab.c"
    break;

  case 38: /* opt_params: '(' id_list ')'  */
#line 154 "parser.y"
                          { (yyval.node) = create_node("ParameterList", NULL, 1, (yyvsp[-1].node)); }
#line 1828 "parser.tab.c"
    break;

  case 39: /* proc_opts: %empty  */
#line 158 "parser.y"
                  { (yyval.node) = create_node("OptionList", NULL, 0); }
#line 1834 "parser.tab.c"
    break;

  case 40: /* proc_opts: proc_opts KEYWORD_OPTIONS '(' KEYWORD_MAIN ')'  */
#line 160 "parser.y"
        { (yyval.node) = add_child((yyvsp[-4].node), create_node("Option", "MAIN", 0)); }
#line 1840 "parser.tab.c"
    break;

  case 41: /* proc_opts: proc_opts KEYWORD_RECURSIVE  */
#line 162 "parser.y"
        { (yyval.node) = add_child((yyvsp[-1].node), create_node("Option", "RECURSIVE", 0)); }
#line 1846 "parser.tab.c"
    break;

  case 42: /* proc_opts: proc_opts KEYWORD_RETURNS '(' attrs ')'  */
#line 164 "parser.y"
        { (yyval.node) = add_child((yyvsp[-4].node), create_node("ReturnsClause", NULL, 1, (yyvsp[-1].node))); }
#line 1852 "parser.tab.c"
    break;

  case 43: /* decl_list: decl  */
#line 168 "parser.y"
                            { (yyval.node) = add_child(create_node("DeclaratorList", NULL, 0), (yyvsp[0].node)); }
#line 1858 "parser.tab.c"
    break;

  case 44: /* decl_list: decl_list ',' decl  */
#line 169 "parser.y"
                            { (yyval.node) = add_child((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1864 "parser.tab.c"
    break;

  case 45: /* decl: IDENTIFIER attrs  */
#line 174 "parser.y"
        { (yyval.node) = create_node("Declarator", (yyvsp[-1].str), 1, (yyvsp[0].node)); free((yyvsp[-1].str)); }
#line 1870 "parser.tab.c"
    break;

  case 46: /* decl: '(' id_list ')' attrs  */
#line 176 "parser.y"
        { (yyval.node) = create_node("DeclaratorGroup", NULL, 2, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1876 "parser.tab.c"
    break;

  case 47: /* decl: INT_CONST IDENTIFIER attrs  */
#line 178 "parser.y"
        { (yyval.node) = create_node("Declarator", (yyvsp[-1].str), 2, create_node("Level", (yyvsp[-2].str), 0), (yyvsp[0].node)); free((yyvsp[-1].str)); free((yyvsp[-2].str)); }
#line 1882 "parser.tab.c"
    break;

  case 48: /* decl: INT_CONST '(' id_list ')' attrs  */
#line 180 "parser.y"
        { (yyval.node) = create_node("DeclaratorGroup", NULL, 3, create_node("Level", (yyvsp[-4].str), 0), (yyvsp[-2].node), (yyvsp[0].node)); free((yyvsp[-4].str)); }
#line 1888 "parser.tab.c"
    break;

  case 49: /* attrs: %empty  */
#line 184 "parser.y"
                  { (yyval.node) = create_node("AttributeList", NULL, 0); }
#line 1894 "parser.tab.c"
    break;

  case 50: /* attrs: attrs attr  */
#line 185 "parser.y"
                  { (yyval.node) = add_child((yyvsp[-1].node), (yyvsp[0].node)); }
#line 1900 "parser.tab.c"
    break;

  case 51: /* attr: KEYWORD_FIXED  */
#line 189 "parser.y"
                         { (yyval.node) = create_node("Attribute", "FIXED", 0); }
#line 1906 "parser.tab.c"
    break;

  case 52: /* attr: KEYWORD_FLOAT  */
#line 190 "parser.y"
                         { (yyval.node) = create_node("Attribute", "FLOAT", 0); }
#line 1912 "parser.tab.c"
    break;

  case 53: /* attr: KEYWORD_BINARY  */
#line 191 "parser.y"
                         { (yyval.node) = create_node("Attribute", "BINARY", 0); }
#line 1918 "parser.tab.c"
    break;

  case 54: /* attr: KEYWORD_DECIMAL  */
#line 192 "parser.y"
                         { (yyval.node) = create_node("Attribute", "DECIMAL", 0); }
#line 1924 "parser.tab.c"
    break;

  case 55: /* attr: KEYWORD_COMPLEX  */
#line 193 "parser.y"
                         { (yyval.node) = create_node("Attribute", "COMPLEX", 0); }
#line 1930 "parser.tab.c"
    break;

  case 56: /* attr: KEYWORD_POINTER  */
#line 194 "parser.y"
                         { (yyval.node) = create_node("Attribute", "POINTER", 0); }
#line 1936 "parser.tab.c"
    break;

  case 57: /* attr: KEYWORD_VARYING  */
#line 195 "parser.y"
                         { (yyval.node) = create_node("Attribute", "VARYING", 0); }
#line 1942 "parser.tab.c"
    break;

  case 58: /* attr: KEYWORD_BIT  */
#line 196 "parser.y"
                         { (yyval.node) = create_node("Attribute", "BIT", 0); }
#line 1948 "parser.tab.c"
    break;

  case 59: /* attr: KEYWORD_CHARACTER  */
#line 197 "parser.y"
                         { (yyval.node) = create_node("Attribute", "CHARACTER", 0); }
#line 1954 "parser.tab.c"
    break;

  case 60: /* attr: KEYWORD_INITIAL '(' expr_list ')'  */
#line 198 "parser.y"
                                        { (yyval.node) = create_node("Initial", NULL, 1, (yyvsp[-1].node)); }
#line 1960 "parser.tab.c"
    break;

  case 61: /* attr: '(' expr_list ')'  */
#line 199 "parser.y"
                                   { (yyval.node) = create_node("SizeOrDimensions", NULL, 1, (yyvsp[-1].node)); }
#line 1966 "parser.tab.c"
    break;

  case 62: /* io_opts: %empty  */
#line 203 "parser.y"
                  { (yyval.node) = create_node("IoOptionList", NULL, 0); }
#line 1972 "parser.tab.c"
    break;

  case 63: /* io_opts: io_opts KEYWORD_SKIP  */
#line 205 "parser.y"
        { (yyval.node) = add_child((yyvsp[-1].node), create_node("Skip", NULL, 0)); }
#line 1978 "parser.tab.c"
    break;

  case 64: /* io_opts: io_opts KEYWORD_SKIP '(' expr ')'  */
#line 207 "parser.y"
        { (yyval.node) = add_child((yyvsp[-4].node), create_node("Skip", NULL, 1, (yyvsp[-1].node))); }
#line 1984 "parser.tab.c"
    break;

  case 65: /* io_opts: io_opts KEYWORD_LIST '(' expr_list ')'  */
#line 209 "parser.y"
        { (yyval.node) = add_child((yyvsp[-4].node), create_node("List", NULL, 1, (yyvsp[-1].node))); }
#line 1990 "parser.tab.c"
    break;

  case 66: /* io_opts: io_opts KEYWORD_EDIT '(' expr_list ')' '(' expr_list ')'  */
#line 211 "parser.y"
        { (yyval.node) = add_child((yyvsp[-7].node), create_node("Edit", NULL, 2, (yyvsp[-4].node), (yyvsp[-1].node))); }
#line 1996 "parser.tab.c"
    break;

  case 67: /* opt_id: %empty  */
#line 215 "parser.y"
                  { (yyval.node) = NULL; }
#line 2002 "parser.tab.c"
    break;

  case 68: /* opt_id: IDENTIFIER  */
#line 216 "parser.y"
                  { (yyval.node) = create_node("Identifier", (yyvsp[0].str), 0); free((yyvsp[0].str)); }
#line 2008 "parser.tab.c"
    break;

  case 69: /* id_list: IDENTIFIER  */
#line 221 "parser.y"
        { (yyval.node) = add_child(create_node("IdentifierList", NULL, 0), create_node("Identifier", (yyvsp[0].str), 0)); free((yyvsp[0].str)); }
#line 2014 "parser.tab.c"
    break;

  case 70: /* id_list: id_list ',' IDENTIFIER  */
#line 223 "parser.y"
        { (yyval.node) = add_child((yyvsp[-2].node), create_node("Identifier", (yyvsp[0].str), 0)); free((yyvsp[0].str)); }
#line 2020 "parser.tab.c"
    break;

  case 71: /* expr_list: expr  */
#line 228 "parser.y"
        { (yyval.node) = add_child(create_node("ExpressionList", NULL, 0), (yyvsp[0].node)); }
#line 2026 "parser.tab.c"
    break;

  case 72: /* expr_list: expr_list ',' expr  */
#line 230 "parser.y"
        { (yyval.node) = add_child((yyvsp[-2].node), (yyvsp[0].node)); }
#line 2032 "parser.tab.c"
    break;

  case 73: /* ref: base  */
#line 234 "parser.y"
                          { (yyval.node) = (yyvsp[0].node); }
#line 2038 "parser.tab.c"
    break;

  case 74: /* ref: ref '.' base  */
#line 235 "parser.y"
                          { (yyval.node) = create_node("MemberAccess", NULL, 2, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2044 "parser.tab.c"
    break;

  case 75: /* ref: ref ARROW base  */
#line 236 "parser.y"
                          { (yyval.node) = create_node("PointerAccess", NULL, 2, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2050 "parser.tab.c"
    break;

  case 76: /* base: IDENTIFIER  */
#line 240 "parser.y"
                          { (yyval.node) = create_node("Identifier", (yyvsp[0].str), 0); free((yyvsp[0].str)); }
#line 2056 "parser.tab.c"
    break;

  case 77: /* base: IDENTIFIER '(' expr_list ')'  */
#line 242 "parser.y"
        { (yyval.node) = create_node("CallOrSubscript", (yyvsp[-3].str), 1, (yyvsp[-1].node)); free((yyvsp[-3].str)); }
#line 2062 "parser.tab.c"
    break;

  case 78: /* expr: expr '+' expr  */
#line 246 "parser.y"
                          { (yyval.node) = create_node("BinaryOp", "+", 2, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2068 "parser.tab.c"
    break;

  case 79: /* expr: expr '-' expr  */
#line 247 "parser.y"
                          { (yyval.node) = create_node("BinaryOp", "-", 2, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2074 "parser.tab.c"
    break;

  case 80: /* expr: expr '*' expr  */
#line 248 "parser.y"
                          { (yyval.node) = create_node("BinaryOp", "*", 2, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2080 "parser.tab.c"
    break;

  case 81: /* expr: expr '/' expr  */
#line 249 "parser.y"
                          { (yyval.node) = create_node("BinaryOp", "/", 2, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2086 "parser.tab.c"
    break;

  case 82: /* expr: expr OP_EXPONENT expr  */
#line 250 "parser.y"
                                { (yyval.node) = create_node("BinaryOp", "**", 2, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2092 "parser.tab.c"
    break;

  case 83: /* expr: expr OP_CONCAT expr  */
#line 251 "parser.y"
                             { (yyval.node) = create_node("BinaryOp", "||", 2, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2098 "parser.tab.c"
    break;

  case 84: /* expr: expr '=' expr  */
#line 252 "parser.y"
                          { (yyval.node) = create_node("BinaryOp", "=", 2, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2104 "parser.tab.c"
    break;

  case 85: /* expr: expr '<' expr  */
#line 253 "parser.y"
                          { (yyval.node) = create_node("BinaryOp", "<", 2, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2110 "parser.tab.c"
    break;

  case 86: /* expr: expr '>' expr  */
#line 254 "parser.y"
                          { (yyval.node) = create_node("BinaryOp", ">", 2, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2116 "parser.tab.c"
    break;

  case 87: /* expr: expr OP_NE expr  */
#line 255 "parser.y"
                             { (yyval.node) = create_node("BinaryOp", "NE", 2, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2122 "parser.tab.c"
    break;

  case 88: /* expr: expr OP_LE expr  */
#line 256 "parser.y"
                             { (yyval.node) = create_node("BinaryOp", "<=", 2, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2128 "parser.tab.c"
    break;

  case 89: /* expr: expr OP_GE expr  */
#line 257 "parser.y"
                             { (yyval.node) = create_node("BinaryOp", ">=", 2, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2134 "parser.tab.c"
    break;

  case 90: /* expr: expr OP_NLT expr  */
#line 258 "parser.y"
                             { (yyval.node) = create_node("BinaryOp", "NLT", 2, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2140 "parser.tab.c"
    break;

  case 91: /* expr: expr OP_NGT expr  */
#line 259 "parser.y"
                             { (yyval.node) = create_node("BinaryOp", "NGT", 2, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2146 "parser.tab.c"
    break;

  case 92: /* expr: expr '&' expr  */
#line 260 "parser.y"
                          { (yyval.node) = create_node("BinaryOp", "&", 2, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2152 "parser.tab.c"
    break;

  case 93: /* expr: expr '|' expr  */
#line 261 "parser.y"
                          { (yyval.node) = create_node("BinaryOp", "|", 2, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2158 "parser.tab.c"
    break;

  case 94: /* expr: '-' expr  */
#line 262 "parser.y"
                            { (yyval.node) = create_node("UnaryOp", "-", 1, (yyvsp[0].node)); }
#line 2164 "parser.tab.c"
    break;

  case 95: /* expr: '+' expr  */
#line 263 "parser.y"
                            { (yyval.node) = create_node("UnaryOp", "+", 1, (yyvsp[0].node)); }
#line 2170 "parser.tab.c"
    break;

  case 96: /* expr: OP_NOT expr  */
#line 264 "parser.y"
                               { (yyval.node) = create_node("UnaryOp", "NOT", 1, (yyvsp[0].node)); }
#line 2176 "parser.tab.c"
    break;

  case 97: /* expr: '(' expr ')'  */
#line 265 "parser.y"
                          { (yyval.node) = (yyvsp[-1].node); }
#line 2182 "parser.tab.c"
    break;

  case 98: /* expr: ref  */
#line 266 "parser.y"
                          { (yyval.node) = (yyvsp[0].node); }
#line 2188 "parser.tab.c"
    break;

  case 99: /* expr: INT_CONST  */
#line 267 "parser.y"
                          { (yyval.node) = create_node("IntConstant", (yyvsp[0].str), 0); free((yyvsp[0].str)); }
#line 2194 "parser.tab.c"
    break;

  case 100: /* expr: FLOAT_CONST  */
#line 268 "parser.y"
                          { (yyval.node) = create_node("FloatConstant", (yyvsp[0].str), 0); free((yyvsp[0].str)); }
#line 2200 "parser.tab.c"
    break;

  case 101: /* expr: CHAR_CONST  */
#line 269 "parser.y"
                          { (yyval.node) = create_node("CharConstant", (yyvsp[0].str), 0); free((yyvsp[0].str)); }
#line 2206 "parser.tab.c"
    break;

  case 102: /* expr: STRING_LITERAL  */
#line 270 "parser.y"
                          { (yyval.node) = create_node("StringLiteral", (yyvsp[0].str), 0); free((yyvsp[0].str)); }
#line 2212 "parser.tab.c"
    break;

  case 103: /* expr: BIT_STRING  */
#line 271 "parser.y"
                          { (yyval.node) = create_node("BitString", (yyvsp[0].str), 0); free((yyvsp[0].str)); }
#line 2218 "parser.tab.c"
    break;

  case 104: /* expr: HEX_STRING  */
#line 272 "parser.y"
                          { (yyval.node) = create_node("HexString", (yyvsp[0].str), 0); free((yyvsp[0].str)); }
#line 2224 "parser.tab.c"
    break;

  case 105: /* expr: BIN_CONST  */
#line 273 "parser.y"
                          { (yyval.node) = create_node("BinaryConstant", (yyvsp[0].str), 0); free((yyvsp[0].str)); }
#line 2230 "parser.tab.c"
    break;

  case 106: /* expr: COMPLEX_CONST  */
#line 274 "parser.y"
                          { (yyval.node) = create_node("ComplexConstant", (yyvsp[0].str), 0); free((yyvsp[0].str)); }
#line 2236 "parser.tab.c"
    break;


#line 2240 "parser.tab.c"

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

#line 277 "parser.y"


/* C Code Section */










void yyerror(const char *s) {
    fprintf(stderr, "Parse error on line %d near '%s': %s\n", line_count, yytext, s);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <sourcefile.pli>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Cannot open input file");
        return 1;
    }

    yyin = file;
    int result = yyparse();
    fclose(file);

    if (result == 0 && ast_root) {
        printf("\n--- Abstract Syntax Tree ---\n");
        print_ast(ast_root, 0);
        printf("----------------------------\n");
        free_ast(ast_root);
    } else {
        printf("Parsing failed, no AST generated.\n");
    }
    print_symbol_table();
    free_symbol_table();

    printf("\n----------------------------------\n");
    printf("Total lines processed: %d\n", line_count);
    return result;
}
