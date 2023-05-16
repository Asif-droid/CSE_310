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
#line 1 "1805063.y"

#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<bits/stdc++.h>
#include "1805063_symbol_table.h"


using namespace std;

int yyparse(void);
int yylex(void);
extern FILE *yyin;
int line_count = 1;
int lastsemicolon;
int error = 0;

smbol_table *table=new smbol_table();
string type;



void line_log(int a){
    ofstream f2;
    f2.open("1805063_log.txt",ios::app);
    f2<<"line no: "<<a<<endl;
    
    f2.close();

}
void line_error(int a){
    ofstream f3;
    f3.open("1805063_error.txt",ios::app);
    f3<<"line no: "<<a<<endl;
    
    f3.close();

}
void logout(string s){
    ofstream f2;
    f2.open("1805063_log.txt",ios::app);
    f2<<s;
    
    f2.close();

}
void logout(string s,int a){
    ofstream f2;
    f2.open("1805063_log.txt",ios::app);
    f2<<"line_no: "<<a<<" "<<s<<endl;
    
    f2.close();
}
void errorout(string s){
    ofstream f2;
    f2.open("1805063_error.txt",ios::app);
    f2<<s<<endl;
    
    f2.close();

}
void errorout(string s,int a){
    ofstream f2;
    f2.open("1805063_error.txt",ios::app);
    f2<<"line_no: "<<a<<" "<<s<<endl;
    
    f2.close();

}
void yyerror(char *s)
{
	
}



#line 149 "y.tab.c"

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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    IF = 258,                      /* IF  */
    ELSE = 259,                    /* ELSE  */
    FOR = 260,                     /* FOR  */
    WHILE = 261,                   /* WHILE  */
    DO = 262,                      /* DO  */
    INT = 263,                     /* INT  */
    CHAR = 264,                    /* CHAR  */
    FLOAT = 265,                   /* FLOAT  */
    VOID = 266,                    /* VOID  */
    RETURN = 267,                  /* RETURN  */
    CONTINUE = 268,                /* CONTINUE  */
    NOT = 269,                     /* NOT  */
    LPAREN = 270,                  /* LPAREN  */
    RPAREN = 271,                  /* RPAREN  */
    LCURL = 272,                   /* LCURL  */
    RCURL = 273,                   /* RCURL  */
    LTHIRD = 274,                  /* LTHIRD  */
    RTHIRD = 275,                  /* RTHIRD  */
    PRINTLN = 276,                 /* PRINTLN  */
    COMMA = 277,                   /* COMMA  */
    SEMICOLON = 278,               /* SEMICOLON  */
    ADDOP = 279,                   /* ADDOP  */
    MULOP = 280,                   /* MULOP  */
    INCOP = 281,                   /* INCOP  */
    DECOP = 282,                   /* DECOP  */
    LOGICOP = 283,                 /* LOGICOP  */
    RELOP = 284,                   /* RELOP  */
    ASSIGNOP = 285,                /* ASSIGNOP  */
    UNRECOGNISED_OP = 286,         /* UNRECOGNISED_OP  */
    ID = 287,                      /* ID  */
    CONST_INT = 288,               /* CONST_INT  */
    CONST_FLOAT = 289,             /* CONST_FLOAT  */
    LOWER_THAN_ELSE = 290          /* LOWER_THAN_ELSE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define IF 258
#define ELSE 259
#define FOR 260
#define WHILE 261
#define DO 262
#define INT 263
#define CHAR 264
#define FLOAT 265
#define VOID 266
#define RETURN 267
#define CONTINUE 268
#define NOT 269
#define LPAREN 270
#define RPAREN 271
#define LCURL 272
#define RCURL 273
#define LTHIRD 274
#define RTHIRD 275
#define PRINTLN 276
#define COMMA 277
#define SEMICOLON 278
#define ADDOP 279
#define MULOP 280
#define INCOP 281
#define DECOP 282
#define LOGICOP 283
#define RELOP 284
#define ASSIGNOP 285
#define UNRECOGNISED_OP 286
#define ID 287
#define CONST_INT 288
#define CONST_FLOAT 289
#define LOWER_THAN_ELSE 290

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 81 "1805063.y"

     smbol_info *symbol;
     vector<smbol_info*>* vectorsymbol;

#line 277 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IF = 3,                         /* IF  */
  YYSYMBOL_ELSE = 4,                       /* ELSE  */
  YYSYMBOL_FOR = 5,                        /* FOR  */
  YYSYMBOL_WHILE = 6,                      /* WHILE  */
  YYSYMBOL_DO = 7,                         /* DO  */
  YYSYMBOL_INT = 8,                        /* INT  */
  YYSYMBOL_CHAR = 9,                       /* CHAR  */
  YYSYMBOL_FLOAT = 10,                     /* FLOAT  */
  YYSYMBOL_VOID = 11,                      /* VOID  */
  YYSYMBOL_RETURN = 12,                    /* RETURN  */
  YYSYMBOL_CONTINUE = 13,                  /* CONTINUE  */
  YYSYMBOL_NOT = 14,                       /* NOT  */
  YYSYMBOL_LPAREN = 15,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 16,                    /* RPAREN  */
  YYSYMBOL_LCURL = 17,                     /* LCURL  */
  YYSYMBOL_RCURL = 18,                     /* RCURL  */
  YYSYMBOL_LTHIRD = 19,                    /* LTHIRD  */
  YYSYMBOL_RTHIRD = 20,                    /* RTHIRD  */
  YYSYMBOL_PRINTLN = 21,                   /* PRINTLN  */
  YYSYMBOL_COMMA = 22,                     /* COMMA  */
  YYSYMBOL_SEMICOLON = 23,                 /* SEMICOLON  */
  YYSYMBOL_ADDOP = 24,                     /* ADDOP  */
  YYSYMBOL_MULOP = 25,                     /* MULOP  */
  YYSYMBOL_INCOP = 26,                     /* INCOP  */
  YYSYMBOL_DECOP = 27,                     /* DECOP  */
  YYSYMBOL_LOGICOP = 28,                   /* LOGICOP  */
  YYSYMBOL_RELOP = 29,                     /* RELOP  */
  YYSYMBOL_ASSIGNOP = 30,                  /* ASSIGNOP  */
  YYSYMBOL_UNRECOGNISED_OP = 31,           /* UNRECOGNISED_OP  */
  YYSYMBOL_ID = 32,                        /* ID  */
  YYSYMBOL_CONST_INT = 33,                 /* CONST_INT  */
  YYSYMBOL_CONST_FLOAT = 34,               /* CONST_FLOAT  */
  YYSYMBOL_LOWER_THAN_ELSE = 35,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_YYACCEPT = 36,                  /* $accept  */
  YYSYMBOL_start = 37,                     /* start  */
  YYSYMBOL_program = 38,                   /* program  */
  YYSYMBOL_unit = 39,                      /* unit  */
  YYSYMBOL_func_declaration = 40,          /* func_declaration  */
  YYSYMBOL_func_definition = 41,           /* func_definition  */
  YYSYMBOL_42_1 = 42,                      /* $@1  */
  YYSYMBOL_43_2 = 43,                      /* $@2  */
  YYSYMBOL_44_3 = 44,                      /* $@3  */
  YYSYMBOL_45_4 = 45,                      /* $@4  */
  YYSYMBOL_parameter_list = 46,            /* parameter_list  */
  YYSYMBOL_compound_statement = 47,        /* compound_statement  */
  YYSYMBOL_var_declaration = 48,           /* var_declaration  */
  YYSYMBOL_type_specifier = 49,            /* type_specifier  */
  YYSYMBOL_declaration_list = 50,          /* declaration_list  */
  YYSYMBOL_var_declaration_invalid_delimiters = 51, /* var_declaration_invalid_delimiters  */
  YYSYMBOL_statements = 52,                /* statements  */
  YYSYMBOL_statement = 53,                 /* statement  */
  YYSYMBOL_54_5 = 54,                      /* $@5  */
  YYSYMBOL_55_6 = 55,                      /* $@6  */
  YYSYMBOL_expression_statement = 56,      /* expression_statement  */
  YYSYMBOL_variable = 57,                  /* variable  */
  YYSYMBOL_expression = 58,                /* expression  */
  YYSYMBOL_logic_expression = 59,          /* logic_expression  */
  YYSYMBOL_rel_expression = 60,            /* rel_expression  */
  YYSYMBOL_simple_expression = 61,         /* simple_expression  */
  YYSYMBOL_term = 62,                      /* term  */
  YYSYMBOL_unary_expression = 63,          /* unary_expression  */
  YYSYMBOL_factor = 64,                    /* factor  */
  YYSYMBOL_argument_list = 65,             /* argument_list  */
  YYSYMBOL_arguments = 66                  /* arguments  */
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
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   188

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  84
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  142

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   290


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
      35
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   109,   109,   117,   143,   161,   174,   187,   206,   270,
     301,   397,   301,   435,   463,   435,   490,   505,   517,   525,
     532,   541,   556,   574,   584,   609,   616,   623,   635,   662,
     688,   706,   727,   738,   750,   750,   750,   750,   750,   750,
     750,   750,   753,   769,   792,   805,   815,   815,   815,   830,
     859,   881,   912,   933,   952,   967,   974,   985,   992,  1023,
    1057,  1068,  1113,  1124,  1140,  1152,  1163,  1180,  1191,  1208,
    1219,  1263,  1278,  1292,  1305,  1317,  1411,  1425,  1432,  1439,
    1452,  1464,  1475,  1481,  1501
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
  "\"end of file\"", "error", "\"invalid token\"", "IF", "ELSE", "FOR",
  "WHILE", "DO", "INT", "CHAR", "FLOAT", "VOID", "RETURN", "CONTINUE",
  "NOT", "LPAREN", "RPAREN", "LCURL", "RCURL", "LTHIRD", "RTHIRD",
  "PRINTLN", "COMMA", "SEMICOLON", "ADDOP", "MULOP", "INCOP", "DECOP",
  "LOGICOP", "RELOP", "ASSIGNOP", "UNRECOGNISED_OP", "ID", "CONST_INT",
  "CONST_FLOAT", "LOWER_THAN_ELSE", "$accept", "start", "program", "unit",
  "func_declaration", "func_definition", "$@1", "$@2", "$@3", "$@4",
  "parameter_list", "compound_statement", "var_declaration",
  "type_specifier", "declaration_list",
  "var_declaration_invalid_delimiters", "statements", "statement", "$@5",
  "$@6", "expression_statement", "variable", "expression",
  "logic_expression", "rel_expression", "simple_expression", "term",
  "unary_expression", "factor", "argument_list", "arguments", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-85)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-20)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      60,   -85,   -85,   -85,    23,    60,   -85,   -85,   -85,   -85,
      -2,   -85,   -85,    41,   158,    11,     7,   -85,    34,   -85,
     -85,   -85,   -85,   -85,   -85,   -85,   -85,    44,    55,    -4,
      10,    62,    24,    66,   -85,    70,    77,    60,   -85,   -85,
     -85,    58,    71,    78,   -85,   -85,    70,    12,    83,    85,
      91,    92,    93,   145,   145,   145,   -85,    94,   -85,   145,
      46,   -85,   -85,   -85,    82,   110,   -85,    70,   -85,    32,
      14,   -85,    17,     0,    98,   -85,   -85,   -85,   -85,   -85,
     -85,   -85,   -85,   145,    40,   145,    96,    68,   -85,   101,
      95,   -85,   145,   145,   107,   -85,   -85,   -85,   -85,   -85,
     145,   -85,   -85,   145,   145,   145,   145,   145,   -85,   113,
      40,   114,   -85,   -85,   116,   -85,   119,   115,   118,   -85,
     -85,   -85,   -85,    98,   112,   -85,   142,   145,   142,   117,
     -85,   145,   -85,   135,   125,   -85,   -85,   -85,   142,   142,
     -85,   -85
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    25,    26,    27,     0,     2,     4,     6,     7,     5,
       0,     1,     3,    30,     0,     0,     0,    41,     0,    24,
      34,    35,    37,    38,    36,    39,    40,     0,    13,     0,
       0,     0,    28,    32,     9,     0,    10,     0,    20,    18,
      31,     0,     0,    46,    14,     8,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    23,     0,    55,     0,
      58,    77,    78,    44,     0,    46,    42,     0,    45,    74,
       0,    60,    62,    65,    67,    69,    73,    15,    11,    21,
      16,    29,    33,     0,     0,     0,     0,    74,    72,     0,
       0,    71,    82,     0,    30,    22,    43,    47,    79,    80,
       0,    57,    56,     0,     0,     0,     0,     0,    12,     0,
       0,     0,    54,    76,     0,    84,     0,    81,     0,    48,
      61,    63,    64,    68,    66,    70,    46,     0,    46,     0,
      75,     0,    59,    50,     0,    52,    53,    83,    46,    46,
      51,    49
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -85,   -85,   -85,   141,   -85,   -85,   -85,   -85,   -85,   -85,
     -85,   -32,    20,     2,   -85,   -85,   -85,   -59,   -85,   -85,
     -74,   -54,   -52,   -84,    -6,    43,    50,   -50,   -85,   -85,
     -85
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     4,     5,     6,     7,     8,    46,   108,    35,    77,
      29,    44,    63,    64,    14,    27,    65,    66,    67,   119,
      68,    69,    70,    71,    72,    73,    74,    75,    76,   116,
     117
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      87,    86,    10,    89,    88,    87,    96,    10,   115,    91,
     110,    38,    36,    79,    78,   101,   120,    30,    37,     1,
       9,     2,     3,    11,   105,     9,   -19,    28,   -17,   106,
      13,   109,   -19,   111,   -17,    97,   127,   102,    87,    47,
      31,   118,    39,    41,    80,   103,    87,   137,   104,    87,
      87,    87,    87,    87,    54,    55,    15,   125,    98,    99,
      16,    92,   100,    58,    59,    93,    32,   133,     1,   135,
       2,     3,    60,    61,    62,   134,    33,    87,    34,   140,
     141,    50,    40,    51,    52,    42,     1,    43,     2,     3,
      53,    48,    54,    55,    98,    99,    56,   121,   122,    57,
      45,    58,    59,    81,    49,    82,    83,    84,    85,    90,
      60,    61,    62,    50,    94,    51,    52,   113,     1,   112,
       2,     3,    53,   107,    54,    55,    16,   114,    95,   126,
     128,    57,   129,    58,    59,   130,   105,   131,   132,   138,
     136,   139,    60,    61,    62,    50,    12,    51,    52,   124,
       1,     0,     2,     3,    53,   123,    54,    55,     0,    54,
      55,     0,     0,    57,     0,    58,    59,     0,     0,    59,
       0,     0,    17,     0,    60,    61,    62,    60,    61,    62,
      18,    19,    20,    21,    22,    23,    24,    25,    26
};

static const yytype_int16 yycheck[] =
{
      54,    53,     0,    55,    54,    59,    65,     5,    92,    59,
      84,     1,    16,     1,    46,     1,   100,    15,    22,     8,
       0,    10,    11,     0,    24,     5,    16,    16,    16,    29,
      32,    83,    22,    85,    22,    67,   110,    23,    92,    37,
      33,    93,    32,    19,    32,    28,   100,   131,    31,   103,
     104,   105,   106,   107,    14,    15,    15,   107,    26,    27,
      19,    15,    30,    23,    24,    19,    32,   126,     8,   128,
      10,    11,    32,    33,    34,   127,    32,   131,    23,   138,
     139,     3,    20,     5,     6,    19,     8,    17,    10,    11,
      12,    33,    14,    15,    26,    27,    18,   103,   104,    21,
      23,    23,    24,    20,    33,    20,    15,    15,    15,    15,
      32,    33,    34,     3,    32,     5,     6,    16,     8,    23,
      10,    11,    12,    25,    14,    15,    19,    32,    18,    16,
      16,    21,    16,    23,    24,    16,    24,    22,    20,     4,
      23,    16,    32,    33,    34,     3,     5,     5,     6,   106,
       8,    -1,    10,    11,    12,   105,    14,    15,    -1,    14,
      15,    -1,    -1,    21,    -1,    23,    24,    -1,    -1,    24,
      -1,    -1,    14,    -1,    32,    33,    34,    32,    33,    34,
      22,    23,    24,    25,    26,    27,    28,    29,    30
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     8,    10,    11,    37,    38,    39,    40,    41,    48,
      49,     0,    39,    32,    50,    15,    19,    14,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    51,    16,    46,
      49,    33,    32,    32,    23,    44,    16,    22,     1,    32,
      20,    19,    19,    17,    47,    23,    42,    49,    33,    33,
       3,     5,     6,    12,    14,    15,    18,    21,    23,    24,
      32,    33,    34,    48,    49,    52,    53,    54,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    45,    47,     1,
      32,    20,    20,    15,    15,    15,    58,    57,    63,    58,
      15,    63,    15,    19,    32,    18,    53,    47,    26,    27,
      30,     1,    23,    28,    31,    24,    29,    25,    43,    58,
      56,    58,    23,    16,    32,    59,    65,    66,    58,    55,
      59,    60,    60,    62,    61,    63,    16,    56,    16,    16,
      16,    22,    20,    53,    58,    53,    23,    59,     4,    16,
      53,    53
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    36,    37,    38,    38,    39,    39,    39,    40,    40,
      42,    43,    41,    44,    45,    41,    46,    46,    46,    46,
      46,    46,    47,    47,    48,    49,    49,    49,    50,    50,
      50,    50,    50,    50,    51,    51,    51,    51,    51,    51,
      51,    51,    52,    52,    53,    53,    54,    55,    53,    53,
      53,    53,    53,    53,    53,    56,    56,    56,    57,    57,
      58,    58,    59,    59,    59,    60,    60,    61,    61,    62,
      62,    63,    63,    63,    64,    64,    64,    64,    64,    64,
      64,    65,    65,    66,    66
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     6,     5,
       0,     0,     8,     0,     0,     7,     4,     3,     2,     1,
       2,     4,     3,     2,     3,     1,     1,     1,     3,     6,
       1,     4,     3,     6,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     1,     0,     0,     3,     7,
       5,     7,     5,     5,     3,     1,     2,     2,     1,     4,
       1,     3,     1,     3,     3,     1,     3,     1,     3,     1,
       3,     2,     2,     1,     1,     4,     3,     1,     1,     2,
       2,     1,     0,     3,     1
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
  case 2: /* start: program  */
#line 110 "1805063.y"
        {
		//write your code in this block in all the similar blocks below

       logout("start programme",line_count-1);
	}
#line 1435 "y.tab.c"
    break;

  case 3: /* program: program unit  */
#line 117 "1805063.y"
                       {
        
        logout(" program : program unit",line_count);
        (yyval.vectorsymbol) = new vector<smbol_info*>;
		for(int i = 0; i < (yyvsp[-1].vectorsymbol)->size(); i++){
            (yyval.vectorsymbol)->push_back((yyvsp[-1].vectorsymbol)->at(i));
            logout( (yyvsp[-1].vectorsymbol)->at(i)->getname());
			
			if((yyvsp[-1].vectorsymbol)->at(i)->getname() == "int" || (yyvsp[-1].vectorsymbol)->at(i)->getname() == "float" || (yyvsp[-1].vectorsymbol)->at(i)->getname() == "void" || (yyvsp[-1].vectorsymbol)->at(i)->getname() == "return")
				logout(" ");
			if((yyvsp[-1].vectorsymbol)->at(i)->getname() == ";" || (yyvsp[-1].vectorsymbol)->at(i)->getname() == "{" || (yyvsp[-1].vectorsymbol)->at(i)->getname() == "}")
				logout("\n");
		}
		for(int i = 0; i < (yyvsp[0].vectorsymbol)->size(); i++){
            (yyval.vectorsymbol)->push_back((yyvsp[0].vectorsymbol)->at(i));
            logout( (yyvsp[0].vectorsymbol)->at(i)->getname());

			if((yyvsp[0].vectorsymbol)->at(i)->getname() == "int" || (yyvsp[0].vectorsymbol)->at(i)->getname() == "float" || (yyvsp[0].vectorsymbol)->at(i)->getname() == "void" || (yyvsp[0].vectorsymbol)->at(i)->getname() == "return")
				logout(" ");

			if((yyvsp[0].vectorsymbol)->at(i)->getname() == ";" || (yyvsp[0].vectorsymbol)->at(i)->getname() == "{" || (yyvsp[0].vectorsymbol)->at(i)->getname() == "}")
				logout("\n");
		}
		logout("\n\n");

    }
#line 1466 "y.tab.c"
    break;

  case 4: /* program: unit  */
#line 143 "1805063.y"
               {
       
        logout(" program : unit \n",line_count);
        (yyval.vectorsymbol) = new vector<smbol_info*>();
		for(int i = 0; i < (yyvsp[0].vectorsymbol)->size(); i++){
            (yyval.vectorsymbol)->push_back((yyvsp[0].vectorsymbol)->at(i));
            logout((yyvsp[0].vectorsymbol)->at(i)->getname());
            
			
			if((yyvsp[0].vectorsymbol)->at(i)->getname() == "int" || (yyvsp[0].vectorsymbol)->at(i)->getname() == "float" || (yyvsp[0].vectorsymbol)->at(i)->getname() == "void" || (yyvsp[0].vectorsymbol)->at(i)->getname() == "return")
    			logout(" ");
			if((yyvsp[0].vectorsymbol)->at(i)->getname() == ";" || (yyvsp[0].vectorsymbol)->at(i)->getname() == "{" || (yyvsp[0].vectorsymbol)->at(i)->getname() == "}")
				logout("\n");
		}
		logout("\n\n");
    }
#line 1487 "y.tab.c"
    break;

  case 5: /* unit: var_declaration  */
#line 161 "1805063.y"
                       {
        
        logout(" unit : var_declaration\n",line_count);
        (yyval.vectorsymbol) = new vector<smbol_info*>();
        for(int i = 0; i < (yyvsp[0].vectorsymbol)->size(); i++){
            (yyval.vectorsymbol)->push_back((yyvsp[0].vectorsymbol)->at(i));
            logout((yyvsp[0].vectorsymbol)->at(i)->getname());
            
            if((yyvsp[0].vectorsymbol)->at(i)->getname() == "int" || (yyvsp[0].vectorsymbol)->at(i)->getname() == "float" || (yyvsp[0].vectorsymbol)->at(i)->getname() == "void")
                logout(" ");
        }
        logout("\n\n");
    }
#line 1505 "y.tab.c"
    break;

  case 6: /* unit: func_declaration  */
#line 174 "1805063.y"
                       {
        
     	logout(" unit : func_declaration\n",line_count);
        (yyval.vectorsymbol) = new vector<smbol_info*>();
     		for(int i = 0; i < (yyvsp[0].vectorsymbol)->size(); i++){
                (yyval.vectorsymbol)->push_back((yyvsp[0].vectorsymbol)->at(i));
				logout((yyvsp[0].vectorsymbol)->at(i)->getname());
				
				if((yyvsp[0].vectorsymbol)->at(i)->getname() == "int" || (yyvsp[0].vectorsymbol)->at(i)->getname() == "float" || (yyvsp[0].vectorsymbol)->at(i)->getname() == "void")
					logout(" ");
			}
		logout("\n\n"); 
    }
#line 1523 "y.tab.c"
    break;

  case 7: /* unit: func_definition  */
#line 187 "1805063.y"
                      {
        
            logout(" unit : func_definition\n",line_count);
            (yyval.vectorsymbol) = new vector<smbol_info*>();
     		for(int i = 0; i < (yyvsp[0].vectorsymbol)->size(); i++){
				logout((yyvsp[0].vectorsymbol)->at(i)->getname());
				(yyval.vectorsymbol)->push_back((yyvsp[0].vectorsymbol)->at(i));
				if((yyvsp[0].vectorsymbol)->at(i)->getname() == "int" || (yyvsp[0].vectorsymbol)->at(i)->getname() == "float" || (yyvsp[0].vectorsymbol)->at(i)->getname() == "void" || (yyvsp[0].vectorsymbol)->at(i)->getname() == "return")
					logout (" ");
				if((yyvsp[0].vectorsymbol)->at(i)->getname() == ";" || (yyvsp[0].vectorsymbol)->at(i)->getname() == "{" || (yyvsp[0].vectorsymbol)->at(i)->getname() == "}")
					logout("\n");
			}
		logout("\n\n"); 
    }
#line 1542 "y.tab.c"
    break;

  case 8: /* func_declaration: type_specifier ID LPAREN parameter_list RPAREN SEMICOLON  */
#line 206 "1805063.y"
                                                                            {
        
        logout("func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON\n",line_count);
        lastsemicolon=line_count;
        (yyval.vectorsymbol) = new vector<smbol_info*>();
        // semantic error----------//
        if(table->lookup((yyvsp[-4].symbol)->getname()) != NULL){   // Multiple declaration of function
           
            
            logout("Error: Multiple declaration of "+ (yyvsp[-4].symbol)->getname(),line_count );
            
            errorout("Multiple declaration of "+ (yyvsp[-4].symbol)->getname(),line_count );
            error++;
        }
        vector<string> param_name;       // Multiple declaration of parameter
        for(int i = 0; i < (yyvsp[-2].vectorsymbol)->size(); i++){  
            if((yyvsp[-2].vectorsymbol)->at(i)->gettype() == "ID"){
                param_name.push_back((yyvsp[-2].vectorsymbol)->at(i)->getname());
                for(int j = 0; j < param_name.size()-1; j++){
                    if((yyvsp[-2].vectorsymbol)->at(i)->getname() == param_name.at(j)){
                        param_name.pop_back();
                       
                        logout("Error: Multiple declaration of "+ (yyvsp[-2].vectorsymbol)->at(i)->getname()+" in parameter\n",line_count);
                        
                        errorout(" Multiple declaration of "+ (yyvsp[-2].vectorsymbol)->at(i)->getname() +" in parameter\n",line_count);
                        error++;
                    }
                }
            }
        }
        //Insert func declaration Into Table------------------//
        bool inserted =table->insert((yyvsp[-4].symbol)->getname(),"ID",(yyvsp[-5].symbol)->gettype(), "func");
        //---------------//
        // store parameter type sequentially
        if(inserted){   
            smbol_info* temp = table->lookup((yyvsp[-4].symbol)->getname());
            for(int i = 0; i < (yyvsp[-2].vectorsymbol)->size(); i++){
                if((yyvsp[-2].vectorsymbol)->at(i)->gettype() == "INT" || (yyvsp[-2].vectorsymbol)->at(i)->gettype() == "FLOAT" || (yyvsp[-2].vectorsymbol)->at(i)->gettype() == "VOID")
                    temp->set_param_type((yyvsp[-2].vectorsymbol)->at(i)->gettype());
            }
        }
        //----------//
       
        logout( (yyvsp[-5].symbol)->getname());
        logout( (yyvsp[-4].symbol)->getname());
        logout( (yyvsp[-3].symbol)->getname());
        (yyval.vectorsymbol)->push_back((yyvsp[-5].symbol));
        (yyval.vectorsymbol)->push_back((yyvsp[-4].symbol));
        (yyval.vectorsymbol)->push_back((yyvsp[-3].symbol));
        for(int i = 0; i < (yyvsp[-2].vectorsymbol)->size(); i++){
            logout( (yyvsp[-2].vectorsymbol)->at(i)->getname());
        
            (yyval.vectorsymbol)->push_back((yyvsp[-2].vectorsymbol)->at(i));
            if((yyvsp[-2].vectorsymbol)->at(i)->getname() == "int" || (yyvsp[-2].vectorsymbol)->at(i)->getname() == "float" || (yyvsp[-2].vectorsymbol)->at(i)->getname() == "void")
                logout(" ");
        }
        
        logout((yyvsp[-1].symbol)->getname());
        logout((yyvsp[0].symbol)->getname()+"\n\n");
       
        (yyval.vectorsymbol)->push_back((yyvsp[-1].symbol));
        (yyval.vectorsymbol)->push_back((yyvsp[0].symbol));

    }
#line 1611 "y.tab.c"
    break;

  case 9: /* func_declaration: type_specifier ID LPAREN RPAREN SEMICOLON  */
#line 270 "1805063.y"
                                                {
        (yyval.vectorsymbol) = new vector<smbol_info*>();
        logout("func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON\n",line_count);
        lastsemicolon=line_count;

        // semantic error----------//
        if(table->lookup((yyvsp[-3].symbol)->getname()) != NULL){   // Multiple declaration of function
            
            logout("Error: Multiple declaration of "+(yyvsp[-3].symbol)->getname()+"\n ",line_count);
            
            errorout("Error: Multiple declaration of "+(yyvsp[-3].symbol)->getname()+"\n ",line_count);
            error++;
        }
        //----------//
        
        logout( (yyvsp[-4].symbol)->getname()+" ");
        logout( (yyvsp[-3].symbol)->getname()+" ");
        logout( (yyvsp[-2].symbol)->getname()+" ");
        logout( (yyvsp[-1].symbol)->getname()+" ");
        logout( (yyvsp[0].symbol)->getname()+"\n\n");
        
        (yyval.vectorsymbol)->push_back((yyvsp[-4].symbol));
        (yyval.vectorsymbol)->push_back((yyvsp[-3].symbol));
        (yyval.vectorsymbol)->push_back((yyvsp[-2].symbol));
        (yyval.vectorsymbol)->push_back((yyvsp[-1].symbol));
        (yyval.vectorsymbol)->push_back((yyvsp[0].symbol));
        //Insert func declaration Into Table------------------//
        bool inserted = table->insert((yyvsp[-3].symbol)->getname(),"ID",(yyvsp[-4].symbol)->gettype(), "func");
        //---------------//
    }
#line 1646 "y.tab.c"
    break;

  case 10: /* $@1: %empty  */
#line 301 "1805063.y"
                                                                 {
        if(table->lookup((yyvsp[-3].symbol)->getname()) == NULL)
            bool inserted = table->insert((yyvsp[-3].symbol)->getname(),"ID",(yyvsp[-4].symbol)->gettype(), "func");
            
        //semantic error-----------//
        else if((table->lookup((yyvsp[-3].symbol)->getname()))->getwhichvar() != "func"){
            
            logout("Error:  Multiple declaration of "+ (yyvsp[-3].symbol)->getname() + "\n",line_count);
            
            
            errorout("Error:  Multiple declaration of "+ (yyvsp[-3].symbol)->getname() + "\n",line_count);
            error++;
        }
        else if((table->lookup((yyvsp[-3].symbol)->getname()))->getdefined()){     // Function Already Defined
           logout("Error:  Multiple declaration of "+ (yyvsp[-3].symbol)->getname() + "\n",line_count);
            
            
            errorout("Error:  Multiple declaration of "+ (yyvsp[-3].symbol)->getname() + "\n",line_count);
            error++;
        }
        else if(!(table->lookup( (yyvsp[-3].symbol)->getname()))->getdefined()){        // Return type doesn't match with declaration
            (table->lookup( (yyvsp[-3].symbol)->getname()))->setdefined();
            if((table->lookup((yyvsp[-3].symbol)->getname()))->get_var_type() != (yyvsp[-4].symbol)->gettype()){
                
                logout("Error: Return type mismatch with function declaration in function "+ (yyvsp[-3].symbol)->getname()+"\n",line_count);
                errorout("Error: Return type mismatch with function declaration in function "+ (yyvsp[-3].symbol)->getname()+"\n",line_count);
                error++;
            }
        }
        smbol_info* temp = table->lookup( (yyvsp[-3].symbol)->getname());
        temp->setdefined();
        
        
        vector<string> param_name;       // Multiple declaration of parameter
        for(int i = 0; i < (yyvsp[-1].vectorsymbol)->size(); i++){  
            if((yyvsp[-1].vectorsymbol)->at(i)->gettype() == "ID"){
                param_name.push_back((yyvsp[-1].vectorsymbol)->at(i)->getname());
                for(int j = 0; j < param_name.size()-1; j++){
                    if((yyvsp[-1].vectorsymbol)->at(i)->getname() == param_name.at(j)){
                        param_name.pop_back();
                        
                        logout("Error: Multiple declaration of "+(yyvsp[-1].vectorsymbol)->at(i)->getname()+" in parameter\n",line_count);
                        
                       
                        errorout("Error: Multiple declaration of "+(yyvsp[-1].vectorsymbol)->at(i)->getname()+" in parameter\n",line_count);
                        error++;
                    }
                }
            }
        }
        //------------//
        table->enterscope("x",7);
        
        for (int i = 0; i < (yyvsp[-1].vectorsymbol)->size(); i++){      // Insert parameter into table
            if((yyvsp[-1].vectorsymbol)->at(i)->gettype() == "ID"){
                if((yyvsp[-1].vectorsymbol)->at(i-1)->gettype() == "INT")
                    bool inserted = table->insert( (yyvsp[-1].vectorsymbol)->at(i)->getname(),"ID", "INT","var");
                else if((yyvsp[-1].vectorsymbol)->at(i-1)->gettype() == "FLOAT")
                    bool inserted = table->insert( (yyvsp[-1].vectorsymbol)->at(i)->getname(),"ID", "FLOAT", "var");
                else if((yyvsp[-1].vectorsymbol)->at(i-1)->gettype() == "VOID")
                    bool inserted = table->insert( (yyvsp[-1].vectorsymbol)->at(i)->getname(),"ID", "VOID", "var");
            }
        }
            
            if(temp->getparamsize() == 0){       // store parameter type sequentially
                for(int i = 0; i < (yyvsp[-1].vectorsymbol)->size(); i++){
                if((yyvsp[-1].vectorsymbol)->at(i)->gettype() == "INT" || (yyvsp[-1].vectorsymbol)->at(i)->gettype() == "FLOAT" || (yyvsp[-1].vectorsymbol)->at(i)->gettype() == "VOID")
                    temp->set_param_type((yyvsp[-1].vectorsymbol)->at(i)->gettype());
                }
            }
            else{          // function argument check with declaration
                vector<string> parameter_type;
                for(int i = 0; i < (yyvsp[-1].vectorsymbol)->size(); i++){
                    if((yyvsp[-1].vectorsymbol)->at(i)->gettype() == "INT" || (yyvsp[-1].vectorsymbol)->at(i)->gettype() == "FLOAT" || (yyvsp[-1].vectorsymbol)->at(i)->gettype() == "VOID"){
                        parameter_type.push_back((yyvsp[-1].vectorsymbol)->at(i)->gettype());
                    }
                }
                if(parameter_type.size() != temp->getparamsize()){
                    
                    logout("Error:Total number of arguments mismatch with declaration in function "+ (yyvsp[-3].symbol)->getname() + "\n",line_count);
                    
                    errorout("Error:Total number of arguments mismatch with declaration in function "+ (yyvsp[-3].symbol)->getname() + "\n",line_count);
                    error++;
                } 
                else{
                    for(int i = 0; i < temp->getparamsize(); i++){
                        if(parameter_type.at(i) != temp->get_param_at(i)){
                            
                            string s=to_string(i+1);
                            logout("Error: "+s+ "th argument mismatch in function "+ (yyvsp[-3].symbol)->getname() +"\n");
                            errorout("Error: "+s+ "th argument mismatch in function "+ (yyvsp[-3].symbol)->getname() +"\n");
                            error++;
                        }
                    }
                }
            }
    }
#line 1748 "y.tab.c"
    break;

  case 11: /* $@2: %empty  */
#line 397 "1805063.y"
                         { 
        table->printall();
        cout<<"printall"<<endl;
        table->exitscope();
    }
#line 1758 "y.tab.c"
    break;

  case 12: /* func_definition: type_specifier ID LPAREN parameter_list RPAREN $@1 compound_statement $@2  */
#line 402 "1805063.y"
    {
        (yyval.vectorsymbol) = new vector<smbol_info*>();
        
       
        logout("func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement\n",line_count);
        
        logout( (yyvsp[-7].symbol)->getname()+" ");
        logout( (yyvsp[-6].symbol)->getname()+" ");
        logout( (yyvsp[-5].symbol)->getname()+" ");
        (yyval.vectorsymbol)->push_back((yyvsp[-7].symbol));
        (yyval.vectorsymbol)->push_back((yyvsp[-6].symbol));
        (yyval.vectorsymbol)->push_back((yyvsp[-5].symbol));
        for (int i = 0; i < (yyvsp[-4].vectorsymbol)->size(); i++){
            
            logout((yyvsp[-4].vectorsymbol)->at(i)->getname()+" ");
            (yyval.vectorsymbol)->push_back((yyvsp[-4].vectorsymbol)->at(i));
            if((yyvsp[-4].vectorsymbol)->at(i)->getname() == "int" || (yyvsp[-4].vectorsymbol)->at(i)->getname() == "float" || (yyvsp[-4].vectorsymbol)->at(i)->getname() == "void")
                logout ( " ");
        }
        logout ((yyvsp[-3].symbol)->getname()+" ");
        (yyval.vectorsymbol)->push_back((yyvsp[-3].symbol));
        for (int i = 0; i < (yyvsp[-1].vectorsymbol)->size(); i++){
            logout ((yyvsp[-1].vectorsymbol)->at(i)->getname()+" ");
            (yyval.vectorsymbol)->push_back((yyvsp[-1].vectorsymbol)->at(i));
            if((yyvsp[-1].vectorsymbol)->at(i)->getname() == "int" || (yyvsp[-1].vectorsymbol)->at(i)->getname() == "float" || (yyvsp[-1].vectorsymbol)->at(i)->getname() == "void" || (yyvsp[-1].vectorsymbol)->at(i)->getname() == "return")
                logout ( " ");
            if((yyvsp[-1].vectorsymbol)->at(i)->getname() == ";" || (yyvsp[-1].vectorsymbol)->at(i)->getname() == "{" || (yyvsp[-1].vectorsymbol)->at(i)->getname() == "}")
                logout ("\n");
        }
        logout ( "\n\n");

    }
#line 1795 "y.tab.c"
    break;

  case 13: /* $@3: %empty  */
#line 435 "1805063.y"
                                      {
        if(table->lookup( (yyvsp[-2].symbol)->getname()) == NULL)
            bool inserted = table->insert( (yyvsp[-2].symbol)->getname(),"ID", (yyvsp[-3].symbol)->gettype(), "func");
            
            //semantic error-----------//
        else{        // Return type doesn't match with declaration
            smbol_info* temp = table->lookup( (yyvsp[-2].symbol)->getname());
            if(temp->get_var_type() != (yyvsp[-3].symbol)->gettype()){
                
                logout("Error: Return type mismatch with function declaration in function " + (yyvsp[-2].symbol)->getname() + "\n",line_count);
                errorout("Error: Return type mismatch with function declaration in function " + (yyvsp[-2].symbol)->getname() + "\n",line_count);
                error++;
            }
        }
        smbol_info* temp = table->lookup((yyvsp[-2].symbol)->getname());  // Function Already Defined
        if(temp->getdefined()){
            
            logout("Error: Multiple Definition of " + (yyvsp[-2].symbol)->getname()+"\n ",line_count);
            errorout("Error: Multiple Definition of " + (yyvsp[-2].symbol)->getname()+"\n ",line_count);
            error++;
        }
        else
            temp->setdefined();
        
            
        //------------//
        table->enterscope("x",7);
    }
#line 1828 "y.tab.c"
    break;

  case 14: /* $@4: %empty  */
#line 463 "1805063.y"
                       {
        table->printall();
        cout<<"printall"<<endl;
        table->exitscope();
    }
#line 1838 "y.tab.c"
    break;

  case 15: /* func_definition: type_specifier ID LPAREN RPAREN $@3 compound_statement $@4  */
#line 468 "1805063.y"
    {
        (yyval.vectorsymbol) = new vector<smbol_info*>();
        
        
        logout("func_definition : type_specifier ID LPAREN RPAREN compound_statement\n",line_count);
        logout ((yyvsp[-6].symbol)->getname()+" "+ (yyvsp[-5].symbol)->getname()+ (yyvsp[-4].symbol)->getname()+(yyvsp[-3].symbol)->getname());
        (yyval.vectorsymbol)->push_back((yyvsp[-6].symbol));
        (yyval.vectorsymbol)->push_back((yyvsp[-5].symbol));
        (yyval.vectorsymbol)->push_back((yyvsp[-4].symbol));
        (yyval.vectorsymbol)->push_back((yyvsp[-3].symbol));
        for (int i = 0; i < (yyvsp[-1].vectorsymbol)->size(); i++){
            logout ((yyvsp[-1].vectorsymbol)->at(i)->getname());
            (yyval.vectorsymbol)->push_back((yyvsp[-1].vectorsymbol)->at(i));
            if((yyvsp[-1].vectorsymbol)->at(i)->getname() == "int" || (yyvsp[-1].vectorsymbol)->at(i)->getname() == "float" || (yyvsp[-1].vectorsymbol)->at(i)->getname() == "void" || (yyvsp[-1].vectorsymbol)->at(i)->getname() == "return")
                logout (" ");
            if((yyvsp[-1].vectorsymbol)->at(i)->getname() == ";" || (yyvsp[-1].vectorsymbol)->at(i)->getname() == "{" || (yyvsp[-1].vectorsymbol)->at(i)->getname() == "}")
                logout ("\n");
        }
        logout ("\n\n");
    }
#line 1863 "y.tab.c"
    break;

  case 16: /* parameter_list: parameter_list COMMA type_specifier ID  */
#line 490 "1805063.y"
                                                         {
        (yyval.vectorsymbol) = new vector<smbol_info*>();
        logout("parameter_list : parameter_list COMMA type_specifier ID\n",line_count);
       
        for(int i = 0; i < (yyvsp[-3].vectorsymbol)->size(); i++){
            logout ((yyvsp[-3].vectorsymbol)->at(i)->getname());
            (yyval.vectorsymbol)->push_back((yyvsp[-3].vectorsymbol)->at(i));
            if((yyvsp[-3].vectorsymbol)->at(i)->getname() == "int" || (yyvsp[-3].vectorsymbol)->at(i)->getname() == "float" || (yyvsp[-3].vectorsymbol)->at(i)->getname() == "void")
                logout ( " ");
        }
        logout ( (yyvsp[-2].symbol)->getname()+" "+ (yyvsp[-1].symbol)->getname()+ " " +(yyvsp[0].symbol)->getname() + "\n\n"); 
        (yyval.vectorsymbol)->push_back((yyvsp[-2].symbol));
        (yyval.vectorsymbol)->push_back((yyvsp[-1].symbol));
        (yyval.vectorsymbol)->push_back((yyvsp[0].symbol));
    }
#line 1883 "y.tab.c"
    break;

  case 17: /* parameter_list: parameter_list COMMA type_specifier  */
#line 505 "1805063.y"
                                         {
        (yyval.vectorsymbol) = new vector<smbol_info*>();
        logout("parameter_list : parameter_list COMMA type_specifier\n",line_count);
        
        for(int i = 0; i < (yyvsp[-2].vectorsymbol)->size(); i++){
            logout ((yyvsp[-2].vectorsymbol)->at(i)->getname());
            (yyval.vectorsymbol)->push_back((yyvsp[-2].vectorsymbol)->at(i));
        }
        logout ( (yyvsp[-1].symbol)->getname()+" " +(yyvsp[0].symbol)->getname() + "\n\n");
        (yyval.vectorsymbol)->push_back((yyvsp[-1].symbol));
        (yyval.vectorsymbol)->push_back((yyvsp[0].symbol));
    }
#line 1900 "y.tab.c"
    break;

  case 18: /* parameter_list: type_specifier ID  */
#line 517 "1805063.y"
                       {
        (yyval.vectorsymbol) = new vector<smbol_info*>();
        logout("parameter_list : type_specifier ID\n",line_count);
        logout ( (yyvsp[-1].symbol)->getname()+" " +(yyvsp[0].symbol)->getname() + "\n\n");
       
        (yyval.vectorsymbol)->push_back((yyvsp[-1].symbol));
        (yyval.vectorsymbol)->push_back((yyvsp[0].symbol));
    }
#line 1913 "y.tab.c"
    break;

  case 19: /* parameter_list: type_specifier  */
#line 525 "1805063.y"
                    {
        (yyval.vectorsymbol) = new vector<smbol_info*>();
        logout("parameter_list : type_specifier\n",line_count);
        logout ((yyvsp[0].symbol)->getname()+ "\n\n");
       
        (yyval.vectorsymbol)->push_back((yyvsp[0].symbol));
    }
#line 1925 "y.tab.c"
    break;

  case 20: /* parameter_list: type_specifier error  */
#line 532 "1805063.y"
                           {
        (yyval.vectorsymbol) = new vector<smbol_info*>();
        logout("Syntax error\n",line_count);
        logout ((yyvsp[-1].symbol)->getname()+ "\n\n");
        errorout("Syntax error\n",line_count);
        error++;
        (yyval.vectorsymbol)->push_back((yyvsp[-1].symbol));
        yyclearin;
    }
#line 1939 "y.tab.c"
    break;

  case 21: /* parameter_list: parameter_list COMMA type_specifier error  */
#line 541 "1805063.y"
                                                {
        (yyval.vectorsymbol) = new vector<smbol_info*>();
        logout("Syntax error\n",line_count);
        
        for(int i = 0; i < (yyvsp[-3].vectorsymbol)->size(); i++){
            logout ((yyvsp[-3].vectorsymbol)->at(i)->getname());
            (yyval.vectorsymbol)->push_back((yyvsp[-3].vectorsymbol)->at(i));
        }
        errorout("Syntax error\n",line_count);
        error++;
        yyclearin;

    }
#line 1957 "y.tab.c"
    break;

  case 22: /* compound_statement: LCURL statements RCURL  */
#line 556 "1805063.y"
                                           {
        
		 	
        logout("compound_statement : LCURL statements RCURL\n",line_count);
        logout ((yyvsp[-2].symbol)->getname() + "\n");
        (yyval.vectorsymbol) = new vector<smbol_info*>();
		 	(yyval.vectorsymbol)->push_back((yyvsp[-2].symbol));
		  	for(int i = 0; i < (yyvsp[-1].vectorsymbol)->size(); i++){
		  		(yyval.vectorsymbol)->push_back((yyvsp[-1].vectorsymbol)->at(i));
		  		logout ((yyvsp[-1].vectorsymbol)->at(i)->getname());
				if((yyvsp[-1].vectorsymbol)->at(i)->getname() == "int" || (yyvsp[-1].vectorsymbol)->at(i)->getname() == "float" || (yyvsp[-1].vectorsymbol)->at(i)->getname() == "void" || (yyvsp[-1].vectorsymbol)->at(i)->getname() == "return")
					logout ( " ");
				if((yyvsp[-1].vectorsymbol)->at(i)->getname() == ";" || (yyvsp[-1].vectorsymbol)->at(i)->getname() == "{" || (yyvsp[-1].vectorsymbol)->at(i)->getname() == "}")
					logout ( "\n");
		  	}
			logout ((yyvsp[0].symbol)->getname() +"\n\n");
			(yyval.vectorsymbol)->push_back((yyvsp[0].symbol));
    }
#line 1980 "y.tab.c"
    break;

  case 23: /* compound_statement: LCURL RCURL  */
#line 574 "1805063.y"
                 {
        (yyval.vectorsymbol) = new vector<smbol_info*>();
       
        logout("compound_statement : LCURL RCURL\n",line_count);
        logout ( (yyvsp[-1].symbol)->getname()+" " +(yyvsp[0].symbol)->getname()+ "\n\n");
        (yyval.vectorsymbol)->push_back((yyvsp[-1].symbol));
        (yyval.vectorsymbol)->push_back((yyvsp[0].symbol));
    }
#line 1993 "y.tab.c"
    break;

  case 24: /* var_declaration: type_specifier declaration_list SEMICOLON  */
#line 584 "1805063.y"
                                                           {
        (yyval.vectorsymbol) = new vector<smbol_info*>();
        lastsemicolon=line_count;
			logout("var_declaration : type_specifier declaration_list SEMICOLON\n",line_count);
			// semantic error-----------//
			if((yyvsp[-2].symbol)->gettype() == "VOID"){
				
                logout("Error: Variable type cannot be void\n",line_count);
				
                errorout("Error: Variable type cannot be void\n",line_count);
				error++;
			}
			//---------------//
		 	logout ( (yyvsp[-2].symbol)->getname() + " ");
		 	(yyval.vectorsymbol)->push_back((yyvsp[-2].symbol));
		  	for(int i = 0; i < (yyvsp[-1].vectorsymbol)->size(); i++){
		  		(yyval.vectorsymbol)->push_back((yyvsp[-1].vectorsymbol)->at(i));
		  		logout ( (yyvsp[-1].vectorsymbol)->at(i)->getname());
		  	}
			
			logout ((yyvsp[0].symbol)->getname() + "\n\n");
			(yyval.vectorsymbol)->push_back((yyvsp[0].symbol));
    }
#line 2021 "y.tab.c"
    break;

  case 25: /* type_specifier: INT  */
#line 609 "1805063.y"
                     {
       
        logout("type_specifier :  INT\n",line_count);
        logout ((yyvsp[0].symbol)->getname() + "\n\n");
        (yyval.symbol) = (yyvsp[0].symbol);
        type = "INT";
    }
#line 2033 "y.tab.c"
    break;

  case 26: /* type_specifier: FLOAT  */
#line 616 "1805063.y"
            {
        
        logout("type_specifier :  FLOAT\n",line_count);
        logout ((yyvsp[0].symbol)->getname() +"\n\n");
        (yyval.symbol) = (yyvsp[0].symbol);
        type = "FLOAT";
    }
#line 2045 "y.tab.c"
    break;

  case 27: /* type_specifier: VOID  */
#line 623 "1805063.y"
           {
        
        logout("type_specifier :  VOID\n",line_count);
        logout ((yyvsp[0].symbol)->getname() + "\n\n");
        (yyval.symbol) = (yyvsp[0].symbol);
        type = "VOID";
    }
#line 2057 "y.tab.c"
    break;

  case 28: /* declaration_list: declaration_list COMMA ID  */
#line 635 "1805063.y"
                                            {
        (yyval.vectorsymbol) = new vector<smbol_info*>();
        //semantic error------//
        bool inserted=false;
        if(type != "VOID"){
                inserted = table->insert( (yyvsp[0].symbol)->getname(),"ID",type,"var");
        }
        
            
        if ( inserted != true){
            
            logout("Error: Multiple declaration of " + (yyvsp[0].symbol)->getname() + "\n",line_count);
            errorout("Error: Multiple declaration of " + (yyvsp[0].symbol)->getname() + "\n",line_count);
            error++;
        }
        //--------//
        
        
        logout(" declaration_list : declaration_list COMMA ID\n",line_count);
        for(int i = 0; i < (yyvsp[-2].vectorsymbol)->size(); i++){
            (yyval.vectorsymbol)->push_back((yyvsp[-2].vectorsymbol)->at(i));
            logout ((yyvsp[-2].vectorsymbol)->at(i)->getname());
        }
        logout ( (yyvsp[-1].symbol)->getname()+" "+ (yyvsp[0].symbol)->getname()+ "\n\n");
        (yyval.vectorsymbol)->push_back((yyvsp[-1].symbol));
        (yyval.vectorsymbol)->push_back((yyvsp[0].symbol));
    }
#line 2089 "y.tab.c"
    break;

  case 29: /* declaration_list: declaration_list COMMA ID LTHIRD CONST_INT RTHIRD  */
#line 662 "1805063.y"
                                                        {
        (yyval.vectorsymbol) = new vector<smbol_info*>();
        //semantic error------//
			bool inserted=false;
			if(type != "VOID")      // don't insert void variable in symboltable
				inserted = table->insert( (yyvsp[-3].symbol)->getname(),"ID",type,"array");
			if(inserted != true){
				logout("Error: Multiple declaration of " + (yyvsp[-3].symbol)->getname() + "\n",line_count);
                errorout("Error: Multiple declaration of " + (yyvsp[-3].symbol)->getname() + "\n",line_count);
                error++;
			}
			//--------//
		  	
		  	
		  	logout("declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD\n",line_count);
            for(int i = 0; i < (yyvsp[-5].vectorsymbol)->size(); i++){
		  		(yyval.vectorsymbol)->push_back((yyvsp[-5].vectorsymbol)->at(i));
		  		logout ((yyvsp[-5].vectorsymbol)->at(i)->getname());
		  	}
			logout((yyvsp[-4].symbol)->getname()+" "+ (yyvsp[-3].symbol)->getname() +" "+  (yyvsp[-2].symbol)->getname()+" "+ (yyvsp[-1].symbol)->getname()+" "+(yyvsp[0].symbol)->getname()+ "\n\n");
			(yyval.vectorsymbol)->push_back((yyvsp[-4].symbol));
			(yyval.vectorsymbol)->push_back((yyvsp[-3].symbol));
			(yyval.vectorsymbol)->push_back((yyvsp[-2].symbol));
			(yyval.vectorsymbol)->push_back((yyvsp[-1].symbol));
			(yyval.vectorsymbol)->push_back((yyvsp[0].symbol));
    }
#line 2120 "y.tab.c"
    break;

  case 30: /* declaration_list: ID  */
#line 688 "1805063.y"
         {
        cout<<"id from y hsjdahdjasdhjshdbajbd"<<endl;
        //semantic error------//
        bool inserted=false;
        if(type != "VOID")     // don't insert void variable in symboltable
            inserted = table->insert( (yyvsp[0].symbol)->getname(),"ID",type, "var");
        if(inserted != true){
            logout("Error: Multiple declaration of " + (yyvsp[0].symbol)->getname() + "\n",line_count);
            errorout("Error: Multiple declaration of " + (yyvsp[0].symbol)->getname() + "\n",line_count);
            error++;
        }
        //--------//
        (yyval.vectorsymbol) = new vector<smbol_info*>();
        
        logout(" declaration_list : ID\n",line_count);
        logout ( (yyvsp[0].symbol)->getname() + "\n\n");
        (yyval.vectorsymbol)->push_back((yyvsp[0].symbol));
    }
#line 2143 "y.tab.c"
    break;

  case 31: /* declaration_list: ID LTHIRD CONST_INT RTHIRD  */
#line 706 "1805063.y"
                                {
        (yyval.vectorsymbol) = new vector<smbol_info*>();
        //semantic error------//
        bool inserted =false;
        if(type != "VOID")      // don't insert void variable in symboltable
            inserted = table->insert( (yyvsp[-3].symbol)->getname(),"ID",type, "array");
        if(inserted != true){
            logout("Error: Multiple declaration of " + (yyvsp[-3].symbol)->getname() + "\n",line_count);
            errorout("Error: Multiple declaration of " + (yyvsp[-3].symbol)->getname() + "\n",line_count);
            error++;
        }
        //--------//
        
       
        logout("declaration_list : ID LTHIRD CONST_INT RTHIRD\n",line_count);
        logout ( (yyvsp[-3].symbol)->getname() +" "+ (yyvsp[-2].symbol)->getname() +" "+ (yyvsp[-1].symbol)->getname()+" "+ (yyvsp[0].symbol)->getname() + "\n\n");
        (yyval.vectorsymbol)->push_back((yyvsp[-3].symbol));
        (yyval.vectorsymbol)->push_back((yyvsp[-2].symbol));
        (yyval.vectorsymbol)->push_back((yyvsp[-1].symbol));
        (yyval.vectorsymbol)->push_back((yyvsp[0].symbol));
    }
#line 2169 "y.tab.c"
    break;

  case 32: /* declaration_list: declaration_list var_declaration_invalid_delimiters ID  */
#line 727 "1805063.y"
                                                             {
        cout<<"here"<<endl;
        (yyval.vectorsymbol) = new vector<smbol_info*>();
        for(int i = 0; i < (yyvsp[-2].vectorsymbol)->size(); i++){
            (yyval.vectorsymbol)->push_back((yyvsp[-2].vectorsymbol)->at(i));
            logout ((yyvsp[-2].vectorsymbol)->at(i)->getname());
		}
        logout("Syntax error",line_count);
        errorout("Syntax error",line_count);
        error++;
    }
#line 2185 "y.tab.c"
    break;

  case 33: /* declaration_list: declaration_list var_declaration_invalid_delimiters ID LTHIRD CONST_INT RTHIRD  */
#line 738 "1805063.y"
                                                                                     {
        (yyval.vectorsymbol) = new vector<smbol_info*>();
        for(int i = 0; i < (yyvsp[-5].vectorsymbol)->size(); i++){
            (yyval.vectorsymbol)->push_back((yyvsp[-5].vectorsymbol)->at(i));
            logout ((yyvsp[-5].vectorsymbol)->at(i)->getname());
		}
        logout("Syntax error",line_count);
        errorout("Syntax error",line_count);
        error++;
    }
#line 2200 "y.tab.c"
    break;

  case 42: /* statements: statement  */
#line 753 "1805063.y"
                      {
        (yyval.vectorsymbol) = new vector<smbol_info*>();
	  	
        logout("statements : statement\n",line_count);
		for(int i = 0; i < (yyvsp[0].vectorsymbol)->size(); i++){
			logout ((yyvsp[0].vectorsymbol)->at(i)->getname());
			(yyval.vectorsymbol)->push_back((yyvsp[0].vectorsymbol)->at(i));
			if((yyvsp[0].vectorsymbol)->at(i)->getname() == "int" || (yyvsp[0].vectorsymbol)->at(i)->getname() == "float" || (yyvsp[0].vectorsymbol)->at(i)->getname() == "void" || (yyvsp[0].vectorsymbol)->at(i)->getname() == "return")
				logout (" ");
			if((yyvsp[0].vectorsymbol)->at(i)->getname() == ";" || (yyvsp[0].vectorsymbol)->at(i)->getname() == "{" || (yyvsp[0].vectorsymbol)->at(i)->getname() == "}")
					logout ("\n");
		}
		logout ("\n\n");
    

    }
#line 2221 "y.tab.c"
    break;

  case 43: /* statements: statements statement  */
#line 769 "1805063.y"
                          {
        (yyval.vectorsymbol) = new vector<smbol_info*>();
	  	
        logout("statements : statements statement\n",line_count);
		for(int i = 0; i < (yyvsp[-1].vectorsymbol)->size(); i++){
			logout ((yyvsp[-1].vectorsymbol)->at(i)->getname());
			(yyval.vectorsymbol)->push_back((yyvsp[-1].vectorsymbol)->at(i));
			if((yyvsp[-1].vectorsymbol)->at(i)->getname() == "int" || (yyvsp[-1].vectorsymbol)->at(i)->getname() == "float" || (yyvsp[-1].vectorsymbol)->at(i)->getname() == "void" || (yyvsp[-1].vectorsymbol)->at(i)->getname() == "return")
				logout (" ");
			if((yyvsp[-1].vectorsymbol)->at(i)->getname() == ";" || (yyvsp[-1].vectorsymbol)->at(i)->getname() == "{" || (yyvsp[-1].vectorsymbol)->at(i)->getname() == "}")
					logout ("\n");
		}
		for(int i = 0; i < (yyvsp[0].vectorsymbol)->size(); i++){
			logout ((yyvsp[0].vectorsymbol)->at(i)->getname());
			(yyval.vectorsymbol)->push_back((yyvsp[0].vectorsymbol)->at(i));
			if((yyvsp[0].vectorsymbol)->at(i)->getname() == "int" || (yyvsp[0].vectorsymbol)->at(i)->getname() == "float" || (yyvsp[0].vectorsymbol)->at(i)->getname() == "void" || (yyvsp[0].vectorsymbol)->at(i)->getname() == "return")
				logout (" ");
			if((yyvsp[0].vectorsymbol)->at(i)->getname() == ";" || (yyvsp[0].vectorsymbol)->at(i)->getname() == "{" || (yyvsp[0].vectorsymbol)->at(i)->getname() == "}")
					logout ("\n");
		}
		logout ("\n\n");
    }
#line 2248 "y.tab.c"
    break;

  case 44: /* statement: var_declaration  */
#line 793 "1805063.y"
          {
	  	(yyval.vectorsymbol) = new vector<smbol_info*>();
	  
        logout("statement : var_declaration\n",line_count);
		for(int i = 0; i < (yyvsp[0].vectorsymbol)->size(); i++){
			logout ((yyvsp[0].vectorsymbol)->at(i)->getname());
			(yyval.vectorsymbol)->push_back((yyvsp[0].vectorsymbol)->at(i));
			if((yyvsp[0].vectorsymbol)->at(i)->getname() == "int" || (yyvsp[0].vectorsymbol)->at(i)->getname() == "float" || (yyvsp[0].vectorsymbol)->at(i)->getname() == "void")
				logout (" ");
		}
		logout ("\n\n");
	  }
#line 2265 "y.tab.c"
    break;

  case 45: /* statement: expression_statement  */
#line 805 "1805063.y"
                          {
        (yyval.vectorsymbol) = new vector<smbol_info*>();
	  	
        logout("statement : expression_statement\n",line_count);
	  	for(int i = 0; i < (yyvsp[0].vectorsymbol)->size(); i++){
			logout ((yyvsp[0].vectorsymbol)->at(i)->getname());
			(yyval.vectorsymbol)->push_back((yyvsp[0].vectorsymbol)->at(i));
		}
		logout ("\n\n");
    }
#line 2280 "y.tab.c"
    break;

  case 46: /* $@5: %empty  */
#line 815 "1805063.y"
     {table->enterscope("x",7);}
#line 2286 "y.tab.c"
    break;

  case 47: /* $@6: %empty  */
#line 815 "1805063.y"
                                                    {table->printall(); table->exitscope();}
#line 2292 "y.tab.c"
    break;

  case 48: /* statement: $@5 compound_statement $@6  */
#line 816 "1805063.y"
    {
        (yyval.vectorsymbol) = new vector<smbol_info*>();
	  	
        logout("statement : compound_statement\n",line_count);
	  	for(int i = 0; i < (yyvsp[-1].vectorsymbol)->size(); i++){
			logout ((yyvsp[-1].vectorsymbol)->at(i)->getname());
			(yyval.vectorsymbol)->push_back((yyvsp[-1].vectorsymbol)->at(i));
			if((yyvsp[-1].vectorsymbol)->at(i)->getname() == "int" || (yyvsp[-1].vectorsymbol)->at(i)->getname() == "float" || (yyvsp[-1].vectorsymbol)->at(i)->getname() == "void" || (yyvsp[-1].vectorsymbol)->at(i)->getname() == "return")
				logout (" ");
			if((yyvsp[-1].vectorsymbol)->at(i)->getname() == ";" || (yyvsp[-1].vectorsymbol)->at(i)->getname() == "{" || (yyvsp[-1].vectorsymbol)->at(i)->getname() == "}")
					logout ("\n");
		}
		logout ("\n\n");
    }
#line 2311 "y.tab.c"
    break;

  case 49: /* statement: FOR LPAREN expression_statement expression_statement expression RPAREN statement  */
#line 830 "1805063.y"
                                                                                      {
        (yyval.vectorsymbol) = new vector<smbol_info*>();
	  	logout("statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement\n",line_count);
        
	  	logout ((yyvsp[-6].symbol)->getname()+" "+(yyvsp[-5].symbol)->getname());
	  	for(int i = 0; i < (yyvsp[-4].vectorsymbol)->size(); i++){
			logout ((yyvsp[-4].vectorsymbol)->at(i)->getname());
			(yyval.vectorsymbol)->push_back((yyvsp[-4].vectorsymbol)->at(i));
		}
		for(int i = 0; i < (yyvsp[-3].vectorsymbol)->size(); i++){
			logout ((yyvsp[-3].vectorsymbol)->at(i)->getname());
			(yyval.vectorsymbol)->push_back((yyvsp[-3].vectorsymbol)->at(i));
		}
		for(int i = 0; i < (yyvsp[-2].vectorsymbol)->size(); i++){
			logout ((yyvsp[-2].vectorsymbol)->at(i)->getname());
			(yyval.vectorsymbol)->push_back((yyvsp[-2].vectorsymbol)->at(i));
		}
		logout ((yyvsp[-1].symbol)->getname());
		(yyval.vectorsymbol)->push_back((yyvsp[-1].symbol));
		for(int i = 0; i < (yyvsp[0].vectorsymbol)->size(); i++){
			logout ((yyvsp[0].vectorsymbol)->at(i)->getname());
			(yyval.vectorsymbol)->push_back((yyvsp[0].vectorsymbol)->at(i));
			if((yyvsp[0].vectorsymbol)->at(i)->getname() == "int" || (yyvsp[0].vectorsymbol)->at(i)->getname() == "float" || (yyvsp[0].vectorsymbol)->at(i)->getname() == "void" || (yyvsp[0].vectorsymbol)->at(i)->getname() == "return")
				logout (" ");
			if((yyvsp[0].vectorsymbol)->at(i)->getname() == ";" || (yyvsp[0].vectorsymbol)->at(i)->getname() == "{" || (yyvsp[0].vectorsymbol)->at(i)->getname() == "}")
				logout ("\n");
		}
		logout ("\n\n");
    }
#line 2345 "y.tab.c"
    break;

  case 50: /* statement: IF LPAREN expression RPAREN statement  */
#line 859 "1805063.y"
                                                                 {
        (yyval.vectorsymbol) = new vector<smbol_info*>();
	  	
        logout("statement : IF LPAREN expression RPAREN statement\n",line_count);
	  	logout ((yyvsp[-4].symbol)->getname()+" "+ (yyvsp[-3].symbol)->getname());
	  	for(int i = 0; i < (yyvsp[-2].vectorsymbol)->size(); i++){
			logout ((yyvsp[-2].vectorsymbol)->at(i)->getname());
			(yyval.vectorsymbol)->push_back((yyvsp[-2].vectorsymbol)->at(i));
		}
		logout ((yyvsp[-1].symbol)->getname());
		(yyval.vectorsymbol)->push_back((yyvsp[-1].symbol));
		for(int i = 0; i < (yyvsp[0].vectorsymbol)->size(); i++){
			logout ((yyvsp[0].vectorsymbol)->at(i)->getname());
			(yyval.vectorsymbol)->push_back((yyvsp[0].vectorsymbol)->at(i));
			if((yyvsp[0].vectorsymbol)->at(i)->getname() == "int" || (yyvsp[0].vectorsymbol)->at(i)->getname() == "float" || (yyvsp[0].vectorsymbol)->at(i)->getname() == "void" || (yyvsp[0].vectorsymbol)->at(i)->getname() == "return")
				logout (" ");
			if((yyvsp[0].vectorsymbol)->at(i)->getname() == ";" || (yyvsp[0].vectorsymbol)->at(i)->getname() == "{" || (yyvsp[0].vectorsymbol)->at(i)->getname() == "}")
				logout ("\n");
		}
		logout ("\n\n");

    }
#line 2372 "y.tab.c"
    break;

  case 51: /* statement: IF LPAREN expression RPAREN statement ELSE statement  */
#line 881 "1805063.y"
                                                          {
        (yyval.vectorsymbol) = new vector<smbol_info*>();
	  	
	  	logout("statement : IF LPAREN expression RPAREN statement ELSE statement\n",line_count);
        logout ((yyvsp[-6].symbol)->getname()+" "+ (yyvsp[-5].symbol)->getname());
	  	for(int i = 0; i < (yyvsp[-4].vectorsymbol)->size(); i++){
			logout ((yyvsp[-4].vectorsymbol)->at(i)->getname());
			(yyval.vectorsymbol)->push_back((yyvsp[-4].vectorsymbol)->at(i));
		}
		logout ((yyvsp[-3].symbol)->getname());
		(yyval.vectorsymbol)->push_back((yyvsp[-3].symbol));
		for(int i = 0; i < (yyvsp[-2].vectorsymbol)->size(); i++){
			logout ((yyvsp[-2].vectorsymbol)->at(i)->getname());
			(yyval.vectorsymbol)->push_back((yyvsp[-2].vectorsymbol)->at(i));
			if((yyvsp[-2].vectorsymbol)->at(i)->getname() == "int" || (yyvsp[-2].vectorsymbol)->at(i)->getname() == "float" || (yyvsp[-2].vectorsymbol)->at(i)->getname() == "void" || (yyvsp[-2].vectorsymbol)->at(i)->getname() == "return")
				logout (" ");
			if((yyvsp[-2].vectorsymbol)->at(i)->getname() == ";" || (yyvsp[-2].vectorsymbol)->at(i)->getname() == "{" || (yyvsp[-2].vectorsymbol)->at(i)->getname() == "}")
				logout ("\n");
		}
		logout ((yyvsp[-1].symbol)->getname());
		(yyval.vectorsymbol)->push_back((yyvsp[-1].symbol));
		for(int i = 0; i < (yyvsp[0].vectorsymbol)->size(); i++){
			logout ( (yyvsp[0].vectorsymbol)->at(i)->getname());
			(yyval.vectorsymbol)->push_back((yyvsp[0].vectorsymbol)->at(i));
			if((yyvsp[0].vectorsymbol)->at(i)->getname() == "int" || (yyvsp[0].vectorsymbol)->at(i)->getname() == "float" || (yyvsp[0].vectorsymbol)->at(i)->getname() == "void" || (yyvsp[0].vectorsymbol)->at(i)->getname() == "return")
				logout (" ");
			if((yyvsp[0].vectorsymbol)->at(i)->getname() == ";" || (yyvsp[0].vectorsymbol)->at(i)->getname() == "{" || (yyvsp[0].vectorsymbol)->at(i)->getname() == "}")
				logout ("\n");
		}
		logout ("\n\n");
    }
#line 2408 "y.tab.c"
    break;

  case 52: /* statement: WHILE LPAREN expression RPAREN statement  */
#line 912 "1805063.y"
                                              {
        (yyval.vectorsymbol) = new vector<smbol_info*>();
	  	
	  	logout("statement : WHILE LPAREN expression RPAREN statement\n",line_count);
        logout ((yyvsp[-4].symbol)->getname()+" "+(yyvsp[-3].symbol)->getname());
	  	for(int i = 0; i < (yyvsp[-2].vectorsymbol)->size(); i++){
			logout ((yyvsp[-2].vectorsymbol)->at(i)->getname());
			(yyval.vectorsymbol)->push_back((yyvsp[-2].vectorsymbol)->at(i));
		}
		logout ((yyvsp[-1].symbol)->getname());
		(yyval.vectorsymbol)->push_back((yyvsp[-1].symbol));
		for(int i = 0; i < (yyvsp[0].vectorsymbol)->size(); i++){
			logout ((yyvsp[0].vectorsymbol)->at(i)->getname());
			(yyval.vectorsymbol)->push_back((yyvsp[0].vectorsymbol)->at(i));
			if((yyvsp[0].vectorsymbol)->at(i)->getname() == "int" || (yyvsp[0].vectorsymbol)->at(i)->getname() == "float" || (yyvsp[0].vectorsymbol)->at(i)->getname() == "void" || (yyvsp[0].vectorsymbol)->at(i)->getname() == "return")
				logout (" ");
			if((yyvsp[0].vectorsymbol)->at(i)->getname() == ";" || (yyvsp[0].vectorsymbol)->at(i)->getname() == "{" || (yyvsp[0].vectorsymbol)->at(i)->getname() == "}")
				logout ("\n");
		}
		logout ("\n\n");
    }
#line 2434 "y.tab.c"
    break;

  case 53: /* statement: PRINTLN LPAREN ID RPAREN SEMICOLON  */
#line 933 "1805063.y"
                                        {
        (yyval.vectorsymbol) = new vector<smbol_info*>();
        logout("statement : PRINTLN LPAREN ID RPAREN SEMICOLON\n",line_count);
        lastsemicolon=line_count;
	  	
		if(table->lookup((yyvsp[-2].symbol)->getname()) == NULL){  // Undeclared error
			
			logout("Error:Undeclared variable " + (yyvsp[-2].symbol)->getname() +"\n",line_count);
            errorout("Error:Undeclared variable " + (yyvsp[-2].symbol)->getname() +"\n",line_count);
            error++;
		}
	  	
        logout ((yyvsp[-4].symbol)->getname()+" "+(yyvsp[-3].symbol)->getname() +" "+ (yyvsp[-2].symbol)->getname() +" "+ (yyvsp[-1].symbol)->getname()+" "+(yyvsp[0].symbol)->getname()+"\n\n");
	  	(yyval.vectorsymbol)->push_back((yyvsp[-4].symbol));
	  	(yyval.vectorsymbol)->push_back((yyvsp[-3].symbol));
	  	(yyval.vectorsymbol)->push_back((yyvsp[-2].symbol));
	  	(yyval.vectorsymbol)->push_back((yyvsp[-1].symbol));
	  	(yyval.vectorsymbol)->push_back((yyvsp[0].symbol));
    }
#line 2458 "y.tab.c"
    break;

  case 54: /* statement: RETURN expression SEMICOLON  */
#line 952 "1805063.y"
                                 {
        (yyval.vectorsymbol) = new vector<smbol_info*>();
        lastsemicolon=line_count;
	  	
        logout("statement : RETURN expression SEMICOLON\n",line_count);
	  	logout ((yyvsp[-2].symbol)->getname() + " ");
	  	(yyval.vectorsymbol)->push_back((yyvsp[-2].symbol));
	  	for(int i = 0; i < (yyvsp[-1].vectorsymbol)->size(); i++){
			logout((yyvsp[-1].vectorsymbol)->at(i)->getname());
			(yyval.vectorsymbol)->push_back((yyvsp[-1].vectorsymbol)->at(i));
		}
		logout((yyvsp[0].symbol)->getname() + "\n\n");
		(yyval.vectorsymbol)->push_back((yyvsp[0].symbol));
    }
#line 2477 "y.tab.c"
    break;

  case 55: /* expression_statement: SEMICOLON  */
#line 967 "1805063.y"
                                 {
        lastsemicolon=line_count;
        logout("expression_statement 	: SEMICOLON\n",line_count);
        logout ((yyvsp[0].symbol)->getname() + "\n\n");
        (yyval.vectorsymbol) = new vector<smbol_info*>();
        (yyval.vectorsymbol)->push_back((yyvsp[0].symbol));
    }
#line 2489 "y.tab.c"
    break;

  case 56: /* expression_statement: expression SEMICOLON  */
#line 974 "1805063.y"
                           {
        (yyval.vectorsymbol) = new vector<smbol_info*>();
       lastsemicolon=line_count;
        logout("expression_statement : expression SEMICOLON \n",line_count);
        for(int i = 0; i < (yyvsp[-1].vectorsymbol)->size(); i++){
            logout ((yyvsp[-1].vectorsymbol)->at(i)->getname());
            (yyval.vectorsymbol)->push_back((yyvsp[-1].vectorsymbol)->at(i));
        }
        logout ((yyvsp[0].symbol)->getname() + "\n\n");
        (yyval.vectorsymbol)->push_back((yyvsp[0].symbol));
    }
#line 2505 "y.tab.c"
    break;

  case 57: /* expression_statement: expression error  */
#line 985 "1805063.y"
                     {
        /*logout("Synnatx error",lastsemicolon+1);
       
        errorout("Syntax error",lastsemicolon+1);*/
        // error++;
    }
#line 2516 "y.tab.c"
    break;

  case 58: /* variable: ID  */
#line 992 "1805063.y"
              {
        (yyval.vectorsymbol) = new vector<smbol_info*>();
		
        logout("variable : ID\n",line_count);
		// semantic error-------//
		if(table->lookup( (yyvsp[0].symbol)->getname()) ==NULL){  // Undeclared error
			
			logout("Error:  Undeclared variable "+(yyvsp[0].symbol)->getname()+ "\n ",line_count);
            errorout("Error:  Undeclared variable "+(yyvsp[0].symbol)->getname()+ "\n ",line_count);
            error++;
		}
		else{    // type mismatch error
			smbol_info *temp = table->lookup((yyvsp[0].symbol)->getname());
			if(temp->getwhichvar() == "array"){
                logout("Error: Type mismatch, "+(yyvsp[0].symbol)->getname()+ " is an array\n",line_count);
                errorout("Error: Type mismatch, "+(yyvsp[0].symbol)->getname()+ " is an array\n",line_count);
				
                error++;
			}
			else if(temp->getwhichvar() == "func"){
				logout("Error: Type mismatch, "+(yyvsp[0].symbol)->getname()+ " is a function\n",line_count);
                errorout("Error: Type mismatch, "+(yyvsp[0].symbol)->getname()+ " is a function\n",line_count);
				
                error++;
			}
		}
		//-----------//
		logout ((yyvsp[0].symbol)->getname() +"\n\n");
		(yyval.vectorsymbol)->push_back((yyvsp[0].symbol));

    }
#line 2552 "y.tab.c"
    break;

  case 59: /* variable: ID LTHIRD expression RTHIRD  */
#line 1023 "1805063.y"
                                  {
        (yyval.vectorsymbol) = new vector<smbol_info*>();
	 	
        logout("variable : ID LTHIRD expression RTHIRD\n",line_count);
		// semantic error-------//
		if(table->lookup((yyvsp[-3].symbol)->getname()) == NULL){    // Undeclared error
            logout("Error: Undeclared variable " + (yyvsp[-3].symbol)->getname() +"\n",line_count);
            errorout("Error: Undeclared variable " + (yyvsp[-3].symbol)->getname() +"\n",line_count);
			error++;
		}
		else{               // not an array
			smbol_info* temp = table->lookup( (yyvsp[-3].symbol)->getname());
			if(temp->getwhichvar()!= "array"){   
                logout("Error: " + (yyvsp[-3].symbol)->getname() +"not an array \n",line_count);
                errorout("Error: " + (yyvsp[-3].symbol)->getname() +"not an array\n",line_count);
                error++;   
				
			}
		}
		if((yyvsp[-1].vectorsymbol)->at(0)->gettype() != "CONST_INT"){  // array index not integer
            logout("Error: " + (yyvsp[-3].symbol)->getname() +"Index not integer \n",line_count);
            errorout("Error:" + (yyvsp[-3].symbol)->getname() +"Index not integer \n",line_count);
			error++;
			
		}
		
		//-----------//
	 	logout ((yyvsp[-3].symbol)->getname() +" "+ (yyvsp[-2].symbol)->getname()+" "+(yyvsp[-1].vectorsymbol)->at(0)->getname()+" "+(yyvsp[0].symbol)->getname() + "\n\n");
	 	(yyval.vectorsymbol)->push_back((yyvsp[-3].symbol));
	 	(yyval.vectorsymbol)->push_back((yyvsp[-2].symbol));
		(yyval.vectorsymbol)->push_back((yyvsp[-1].vectorsymbol)->at(0));
		(yyval.vectorsymbol)->push_back((yyvsp[0].symbol));
    }
#line 2590 "y.tab.c"
    break;

  case 60: /* expression: logic_expression  */
#line 1057 "1805063.y"
                              {
        (yyval.vectorsymbol) = new vector<smbol_info*>();
      
        logout("expression : logic_expression\n",line_count);
        for(int i = 0; i < (yyvsp[0].vectorsymbol)->size(); i++){
            logout ( (yyvsp[0].vectorsymbol)->at(i)->getname());
            (yyval.vectorsymbol)->push_back((yyvsp[0].vectorsymbol)->at(i));
        }
        logout("\n\n");

    }
#line 2606 "y.tab.c"
    break;

  case 61: /* expression: variable ASSIGNOP logic_expression  */
#line 1068 "1805063.y"
                                         {
        (yyval.vectorsymbol) = new vector<smbol_info*>();
        
        logout(" expression : variable ASSIGNOP logic_expression\n",line_count);
        //semantic error----------//
        for(int i = 0; i < (yyvsp[0].vectorsymbol)->size(); i++){     //  void function in expression
            if((yyvsp[0].vectorsymbol)->at(i)->gettype() == "ID" && table->lookup((yyvsp[0].vectorsymbol)->at(i)->getname()) != NULL){
                smbol_info* temp = table->lookup( (yyvsp[0].vectorsymbol)->at(i)->getname());
                if(temp->getwhichvar() == "func" && temp->get_var_type() == "VOID"){
                    logout("Error:Void function used in expression\n ",line_count);
                    errorout("Error:Void function used in expression\n ",line_count);
                    error++;
                }
            }
        }
                
        if(table->lookup((yyvsp[-2].vectorsymbol)->at(0)->getname()) != NULL){     // float assignment in integer error
            smbol_info *temp = table->lookup((yyvsp[-2].vectorsymbol)->at(0)->getname());
            if(temp->get_var_type() == "INT"){
                
                for(int i = 0; i < (yyvsp[0].vectorsymbol)->size(); i++){
                    if((yyvsp[0].vectorsymbol)->at(i)->gettype() == "CONST_FLOAT"){
                        logout("Error: type mismatch\n",line_count);
                        errorout("Error: type mismatch\n",line_count);
                        error++;
                        break;
                    }
                    
                }
            }
        }
        //------------//
        for(int i = 0; i < (yyvsp[-2].vectorsymbol)->size(); i++){
            logout ( (yyvsp[-2].vectorsymbol)->at(i)->getname());
            (yyval.vectorsymbol)->push_back((yyvsp[-2].vectorsymbol)->at(i));
        }
        logout ((yyvsp[-1].symbol)->getname());
        (yyval.vectorsymbol)->push_back((yyvsp[-1].symbol));
        for(int i = 0; i < (yyvsp[0].vectorsymbol)->size(); i++){
            logout ((yyvsp[0].vectorsymbol)->at(i)->getname());
            (yyval.vectorsymbol)->push_back((yyvsp[0].vectorsymbol)->at(i));
        }
        logout ("\n\n");
    }
#line 2655 "y.tab.c"
    break;

  case 62: /* logic_expression: rel_expression  */
#line 1113 "1805063.y"
                                  {
        (yyval.vectorsymbol) = new vector<smbol_info*>();
       
        logout("logic_expression : rel_expression\n",line_count);
        for(int i = 0; i < (yyvsp[0].vectorsymbol)->size(); i++){
            logout ((yyvsp[0].vectorsymbol)->at(i)->getname());
            (yyval.vectorsymbol)->push_back((yyvsp[0].vectorsymbol)->at(i));
        }
        logout ("\n\n");

    }
#line 2671 "y.tab.c"
    break;

  case 63: /* logic_expression: rel_expression LOGICOP rel_expression  */
#line 1124 "1805063.y"
                                            {
        (yyval.vectorsymbol) = new vector<smbol_info*>();
        logout("logic_expression : rel_expression LOGICOP rel_expression\n",line_count);

        for(int i = 0; i < (yyvsp[-2].vectorsymbol)->size(); i++){
            logout ((yyvsp[-2].vectorsymbol)->at(i)->getname());
            (yyval.vectorsymbol)->push_back((yyvsp[-2].vectorsymbol)->at(i));
        }
        logout ((yyvsp[-1].symbol)->getname());
        (yyval.vectorsymbol)->push_back((yyvsp[-1].symbol));
        for(int i = 0; i < (yyvsp[0].vectorsymbol)->size(); i++){
            logout((yyvsp[0].vectorsymbol)->at(i)->getname());
            (yyval.vectorsymbol)->push_back((yyvsp[0].vectorsymbol)->at(i));
        }
        logout ("\n\n");
    }
#line 2692 "y.tab.c"
    break;

  case 64: /* logic_expression: rel_expression UNRECOGNISED_OP rel_expression  */
#line 1140 "1805063.y"
                                                   {
        (yyval.vectorsymbol) = new vector<smbol_info*>();
       
        //logout("logic_expression : rel_expression\n",line_count);
        for(int i = 0; i < (yyvsp[-2].vectorsymbol)->size(); i++){
            //logout ($1->at(i)->getname());
            (yyval.vectorsymbol)->push_back((yyvsp[-2].vectorsymbol)->at(i));
        }
        error++;
        //logout ("\n\n");
    }
#line 2708 "y.tab.c"
    break;

  case 65: /* rel_expression: simple_expression  */
#line 1152 "1805063.y"
                                    {
        (yyval.vectorsymbol) = new vector<smbol_info*>();
        
        logout("rel_expression : simple_expression\n",line_count);
        for(int i = 0; i < (yyvsp[0].vectorsymbol)->size(); i++){
            logout ((yyvsp[0].vectorsymbol)->at(i)->getname());
            (yyval.vectorsymbol)->push_back((yyvsp[0].vectorsymbol)->at(i));
        }
        logout ("\n\n");

    }
#line 2724 "y.tab.c"
    break;

  case 66: /* rel_expression: simple_expression RELOP simple_expression  */
#line 1163 "1805063.y"
                                                {
        (yyval.vectorsymbol) = new vector<smbol_info*>();
        logout(" rel_expression : simple_expression RELOP simple_expression\n",line_count);
 
        for(int i = 0; i < (yyvsp[-2].vectorsymbol)->size(); i++){
            logout ((yyvsp[-2].vectorsymbol)->at(i)->getname());
            (yyval.vectorsymbol)->push_back((yyvsp[-2].vectorsymbol)->at(i));
        }
        logout ((yyvsp[-1].symbol)->getname());
        (yyval.vectorsymbol)->push_back((yyvsp[-1].symbol));
        for(int i = 0; i < (yyvsp[0].vectorsymbol)->size(); i++){
            logout((yyvsp[0].vectorsymbol)->at(i)->getname());
            (yyval.vectorsymbol)->push_back((yyvsp[0].vectorsymbol)->at(i));
        }
        logout ("\n\n");
    }
#line 2745 "y.tab.c"
    break;

  case 67: /* simple_expression: term  */
#line 1180 "1805063.y"
                         {
        (yyval.vectorsymbol) = new vector<smbol_info*>();
       
        logout("simple_expression : term\n",line_count);
        for(int i = 0; i < (yyvsp[0].vectorsymbol)->size(); i++){
            logout ((yyvsp[0].vectorsymbol)->at(i)->getname());
            (yyval.vectorsymbol)->push_back((yyvsp[0].vectorsymbol)->at(i));
        }
        logout ("\n\n");

    }
#line 2761 "y.tab.c"
    break;

  case 68: /* simple_expression: simple_expression ADDOP term  */
#line 1191 "1805063.y"
                                   {
        (yyval.vectorsymbol) = new vector<smbol_info*>();
        logout("simple_expression : simple_expression ADDOP term\n",line_count);
        
        for(int i = 0; i < (yyvsp[-2].vectorsymbol)->size(); i++){
            logout ((yyvsp[-2].vectorsymbol)->at(i)->getname());
            (yyval.vectorsymbol)->push_back((yyvsp[-2].vectorsymbol)->at(i));
        }
        logout ((yyvsp[-1].symbol)->getname());
        (yyval.vectorsymbol)->push_back((yyvsp[-1].symbol));
        for(int i = 0; i < (yyvsp[0].vectorsymbol)->size(); i++){
            logout ((yyvsp[0].vectorsymbol)->at(i)->getname());
            (yyval.vectorsymbol)->push_back((yyvsp[0].vectorsymbol)->at(i));
        }
        logout ("\n\n");
    }
#line 2782 "y.tab.c"
    break;

  case 69: /* term: unary_expression  */
#line 1208 "1805063.y"
                         {
        (yyval.vectorsymbol) = new vector<smbol_info*>();
		
        logout("term :	unary_expression\n",line_count);
		for(int i = 0; i < (yyvsp[0].vectorsymbol)->size(); i++){
	 		logout ((yyvsp[0].vectorsymbol)->at(i)->getname());
	 		(yyval.vectorsymbol)->push_back((yyvsp[0].vectorsymbol)->at(i));
	 	}
	 	logout("\n\n");

    }
#line 2798 "y.tab.c"
    break;

  case 70: /* term: term MULOP unary_expression  */
#line 1219 "1805063.y"
                                  {
        (yyval.vectorsymbol) = new vector<smbol_info*>();
     		
            logout("term :  term MULOP unary_expression\n",line_count);
		// semantic error-----------//
		if((yyvsp[-1].symbol)->getname() == "%"){    // mod operand not integer
			if((yyvsp[-2].vectorsymbol)->size() == 1 && (yyvsp[0].vectorsymbol)->size() == 1){
				if((yyvsp[-2].vectorsymbol)->at(0)->gettype() != "CONST_INT" || (yyvsp[0].vectorsymbol)->at(0)->gettype() != "CONST_INT"){
                    logout("Error:Non-Integer operand on modulus operator\n",line_count);
                    errorout("Error:Non-Integer operand on modulus operator\n",line_count);
					error++;
				}
				else if((yyvsp[0].vectorsymbol)->at(0)->getname() == "0"){
                    logout("Error:Modulus by Zero\n",line_count);
                    errorout("Error:Modulus by Zero\n",line_count);
					error++;
				}
			}
		}
        if((yyvsp[-1].symbol)->getname()=="/"){
            if((yyvsp[0].vectorsymbol)->at(0)->getname()=="0"){
                logout("Eroor: division by 0 \n",line_count);
                errorout("Eroor: division by 0 \n",line_count);
                error++;
            }
        }
			
		for(int i = 0; i < (yyvsp[-2].vectorsymbol)->size(); i++){
            (yyval.vectorsymbol)->push_back((yyvsp[-2].vectorsymbol)->at(i));
	 		logout ((yyvsp[-2].vectorsymbol)->at(i)->getname());
	 		
	 	}
        (yyval.vectorsymbol)->push_back((yyvsp[-1].symbol));
	 	logout ((yyvsp[-1].symbol)->getname());
	 	
	 	for(int i = 0; i < (yyvsp[0].vectorsymbol)->size(); i++){
            (yyval.vectorsymbol)->push_back((yyvsp[0].vectorsymbol)->at(i));
	 		logout ((yyvsp[0].vectorsymbol)->at(i)->getname());
	 		
	 	}
	 	logout("\n\n");
    }
#line 2845 "y.tab.c"
    break;

  case 71: /* unary_expression: ADDOP unary_expression  */
#line 1263 "1805063.y"
                                           {
        (yyval.vectorsymbol) = new vector<smbol_info*>();
        
        logout("unary_expression : ADDOP unary_expression \n",line_count);
        (yyval.vectorsymbol)->push_back((yyvsp[-1].symbol));
        logout ( (yyvsp[-1].symbol)->getname());
        
        for(int i = 0; i < (yyvsp[0].vectorsymbol)->size(); i++){
            (yyval.vectorsymbol)->push_back((yyvsp[0].vectorsymbol)->at(i));
            logout ((yyvsp[0].vectorsymbol)->at(i)->getname());
            
        }
        logout ("\n\n");

    }
#line 2865 "y.tab.c"
    break;

  case 72: /* unary_expression: NOT unary_expression  */
#line 1278 "1805063.y"
                           {
        (yyval.vectorsymbol) = new vector<smbol_info*>();
        
        logout("unary_expression : NOT unary_expression \n",line_count);
        (yyval.vectorsymbol)->push_back((yyvsp[-1].symbol));
        logout ((yyvsp[-1].symbol)->getname());
        
        for(int i = 0; i < (yyvsp[0].vectorsymbol)->size(); i++){
            (yyval.vectorsymbol)->push_back((yyvsp[0].vectorsymbol)->at(i));
            logout ((yyvsp[0].vectorsymbol)->at(i)->getname());
            
        }
        logout ("\n\n");
    }
#line 2884 "y.tab.c"
    break;

  case 73: /* unary_expression: factor  */
#line 1292 "1805063.y"
             {
        (yyval.vectorsymbol) = new vector<smbol_info*>();
        logout("unary_expression : factor \n",line_count);
        
        for (int i = 0; i < (yyvsp[0].vectorsymbol)->size(); i++){
            (yyval.vectorsymbol)->push_back((yyvsp[0].vectorsymbol)->at(i));
            logout ((yyvsp[0].vectorsymbol)->at(i)->getname());
           
        }
        logout ("\n\n");
    }
#line 2900 "y.tab.c"
    break;

  case 74: /* factor: variable  */
#line 1305 "1805063.y"
                   {
        (yyval.vectorsymbol) = new vector<smbol_info*>();
		
        logout("factor  : variable \n",line_count);
		for (int i = 0; i < (yyvsp[0].vectorsymbol)->size(); i++){
            (yyval.vectorsymbol)->push_back((yyvsp[0].vectorsymbol)->at(i));
	 		logout ((yyvsp[0].vectorsymbol)->at(i)->getname());
	 		
        }
        logout("\n\n");

    }
#line 2917 "y.tab.c"
    break;

  case 75: /* factor: ID LPAREN argument_list RPAREN  */
#line 1317 "1805063.y"
                                         {
        (yyval.vectorsymbol) = new vector<smbol_info*>();
        logout("factor  : ID LPAREN argument_list RPAREN\n",line_count);
		
		//semantic error--------//
		if(table->lookup((yyvsp[-3].symbol)->getname()) == NULL){
            logout("Error: Undeclared function "+ (yyvsp[-3].symbol)->getname() + "\n",line_count);
            errorout("Error: Undeclared function "+ (yyvsp[-3].symbol)->getname() + "\n",line_count);
			error++;
		}
		else{          // function argument check with declaration
			smbol_info* temp = table->lookup( (yyvsp[-3].symbol)->getname());
			if(temp->getwhichvar() != "func"){
                logout("Error:"+(yyvsp[-3].symbol)->getname() +" not a function\n",line_count);
                errorout("Error:"+(yyvsp[-3].symbol)->getname() +" not a function\n",line_count);
				
				error++;
			}
			vector<string> parameter_type;
			for(int i = 0; i < (yyvsp[-1].vectorsymbol)->size(); i++){
				if((yyvsp[-1].vectorsymbol)->at(i)->gettype() == "ID"){
					if(i != (yyvsp[-1].vectorsymbol)->size()-1){
						if((yyvsp[-1].vectorsymbol)->at(i+1)->getname() != "["){      // variable
							smbol_info* temp1 = table->lookup( (yyvsp[-1].vectorsymbol)->at(i)->getname());
							if(temp1 != NULL)
								parameter_type.push_back(temp1->get_var_type());
						}
						else if((yyvsp[-1].vectorsymbol)->at(i+2)->gettype() == "CONST_INT" && (yyvsp[-1].vectorsymbol)->at(i+3)->getname() == "]"){   //array
							smbol_info* temp1 = table->lookup( (yyvsp[-1].vectorsymbol)->at(i)->getname());
							if(temp1 != NULL)
								parameter_type.push_back(temp1->get_var_type());
						}
					}
					else{       // variable
						smbol_info* temp1 = table->lookup((yyvsp[-1].vectorsymbol)->at(i)->getname());
						if(temp1 != NULL)
							parameter_type.push_back(temp1->get_var_type());
					}
				}
				
				else if((yyvsp[-1].vectorsymbol)->at(i)->gettype() == "CONST_INT"){
					if(i != 0){
						if((yyvsp[-1].vectorsymbol)->at(i-1)->getname() != "["){
							if((yyvsp[-1].vectorsymbol)->at(i-1)->getname() == ",")
								parameter_type.push_back("INT");
						}
					}
					else{
						parameter_type.push_back("INT");
					}
				}
				else if((yyvsp[-1].vectorsymbol)->at(i)->gettype() == "CONST_FLOAT"){
					if(i != 0){
						if((yyvsp[-1].vectorsymbol)->at(i-1)->getname() != "["){
							if((yyvsp[-1].vectorsymbol)->at(i-1)->getname() == ",")
								parameter_type.push_back("FLOAT");
						}
					}
					else{
						parameter_type.push_back("FLOAT");
					}
				}
			}
			if(parameter_type.size() != temp->getparamsize()){
                logout("Error: Total number of arguments mismatch in function " + (yyvsp[-3].symbol)->getname() + "\n ",line_count);
				errorout("Error: Total number of arguments mismatch in function " + (yyvsp[-3].symbol)->getname() + "\n ",line_count);
				error++;
			} 
			else{
				for(int i = 0; i < temp->getparamsize(); i++){
					if(parameter_type.at(i) != temp->get_param_at(i)){
                        string s=to_string(i+1);
                        logout("Error: "+s+ "th argument mismatch in function " +(yyvsp[-3].symbol)->getname() +"\n",line_count);
						errorout("Error: "+s+ "th argument mismatch in function " +(yyvsp[-3].symbol)->getname() +"\n",line_count);
						error++;
						break;
					}
				}
			}
		}
		//---------------//
        (yyval.vectorsymbol)->push_back((yyvsp[-3].symbol));
		(yyval.vectorsymbol)->push_back((yyvsp[-2].symbol));
		logout( (yyvsp[-3].symbol)->getname()+" "+ (yyvsp[-2].symbol)->getname());
		
		for (int i = 0; i < (yyvsp[-1].vectorsymbol)->size(); i++){
            (yyval.vectorsymbol)->push_back((yyvsp[-1].vectorsymbol)->at(i));
	 		logout ((yyvsp[-1].vectorsymbol)->at(i)->getname());
	 		
  		 }
        (yyval.vectorsymbol)->push_back((yyvsp[0].symbol));
  		logout  ((yyvsp[0].symbol)->getname() +"\n\n");
		
    }
#line 3016 "y.tab.c"
    break;

  case 76: /* factor: LPAREN expression RPAREN  */
#line 1411 "1805063.y"
                                   {
        logout("factor  : LPAREN expression RPAREN\n",line_count);
        (yyval.vectorsymbol) = new vector<smbol_info*>();
		(yyval.vectorsymbol)->push_back((yyvsp[-2].symbol));
		logout ( (yyvsp[-2].symbol)->getname());
		
		for (int i = 0; i < (yyvsp[-1].vectorsymbol)->size(); i++){
            (yyval.vectorsymbol)->push_back((yyvsp[-1].vectorsymbol)->at(i));
	 		logout ( (yyvsp[-1].vectorsymbol)->at(i)->getname());
	 		
  		 }
        logout ((yyvsp[0].symbol)->getname() + "\n\n");
        (yyval.vectorsymbol)->push_back((yyvsp[0].symbol));
    }
#line 3035 "y.tab.c"
    break;

  case 77: /* factor: CONST_INT  */
#line 1425 "1805063.y"
                    {
        logout("factor : CONST_INT\n",line_count);
        (yyval.vectorsymbol) = new vector<smbol_info*>();
		(yyval.vectorsymbol)->push_back((yyvsp[0].symbol));
		logout ((yyvsp[0].symbol)->getname() + "\n\n");
		
    }
#line 3047 "y.tab.c"
    break;

  case 78: /* factor: CONST_FLOAT  */
#line 1432 "1805063.y"
                      {
        logout("factor : CONST_FLOAT\n",line_count);
        (yyval.vectorsymbol) = new vector<smbol_info*>();
		(yyval.vectorsymbol)->push_back((yyvsp[0].symbol));
		logout ((yyvsp[0].symbol)->getname() + "\n\n");
        
    }
#line 3059 "y.tab.c"
    break;

  case 79: /* factor: variable INCOP  */
#line 1439 "1805063.y"
                         {
        (yyval.vectorsymbol) = new vector<smbol_info*>();
		
        logout("factor  : variable INCOP\n",line_count);
		for (int i = 0; i < (yyvsp[-1].vectorsymbol)->size(); i++){
            (yyval.vectorsymbol)->push_back((yyvsp[-1].vectorsymbol)->at(i));
	 		logout( (yyvsp[-1].vectorsymbol)->at(i)->getname());
	 		
  		 }
        (yyval.vectorsymbol)->push_back((yyvsp[0].symbol));
        logout((yyvsp[0].symbol)->getname()+"\n\n");
        
    }
#line 3077 "y.tab.c"
    break;

  case 80: /* factor: variable DECOP  */
#line 1452 "1805063.y"
                        {
        (yyval.vectorsymbol) = new vector<smbol_info*>();
		
        logout("factor  : variable DECOP\n",line_count);
		for (int i = 0; i < (yyvsp[-1].vectorsymbol)->size(); i++){
	 		logout ( (yyvsp[-1].vectorsymbol)->at(i)->getname());
	 		(yyval.vectorsymbol)->push_back((yyvsp[-1].vectorsymbol)->at(i));
  		 }
        logout ((yyvsp[0].symbol)->getname() +"\n\n");
        (yyval.vectorsymbol)->push_back((yyvsp[0].symbol));
    }
#line 3093 "y.tab.c"
    break;

  case 81: /* argument_list: arguments  */
#line 1464 "1805063.y"
                         {
        logout("argument_list : arguments\n",line_count);
        (yyval.vectorsymbol) = new vector<smbol_info*>();
        
        for (int i = 0; i < (yyvsp[0].vectorsymbol)->size(); i++){
            logout ((yyvsp[0].vectorsymbol)->at(i)->getname());
            (yyval.vectorsymbol)->push_back((yyvsp[0].vectorsymbol)->at(i));
            }
            logout ("\n\n");

    }
#line 3109 "y.tab.c"
    break;

  case 82: /* argument_list: %empty  */
#line 1475 "1805063.y"
      {
        (yyval.vectorsymbol) = new vector<smbol_info*>();
        logout("argument_list : \n\n",line_count);
        
    }
#line 3119 "y.tab.c"
    break;

  case 83: /* arguments: arguments COMMA logic_expression  */
#line 1481 "1805063.y"
                                             {
        logout("arguments : arguments COMMA logic_expressionn\n",line_count);
        (yyval.vectorsymbol) = new vector<smbol_info*>();
        
        for (int i = 0; i < (yyvsp[-2].vectorsymbol)->size(); i++){
            (yyval.vectorsymbol)->push_back((yyvsp[-2].vectorsymbol)->at(i));
            logout ((yyvsp[-2].vectorsymbol)->at(i)->getname());
            
        }
        (yyval.vectorsymbol)->push_back((yyvsp[-1].symbol));
        logout ((yyvsp[-1].symbol)->getname());
       
        for (int i = 0; i < (yyvsp[0].vectorsymbol)->size(); i++){
            (yyval.vectorsymbol)->push_back((yyvsp[0].vectorsymbol)->at(i));
            logout ((yyvsp[0].vectorsymbol)->at(i)->getname());
        
        }
        logout ("\n\n");

    }
#line 3144 "y.tab.c"
    break;

  case 84: /* arguments: logic_expression  */
#line 1501 "1805063.y"
                       {
        logout("arguments  : logic_expression\n",line_count);
        (yyval.vectorsymbol) = new vector<smbol_info*>();
            
        for (int i = 0; i < (yyvsp[0].vectorsymbol)->size(); i++){
            (yyval.vectorsymbol)->push_back((yyvsp[0].vectorsymbol)->at(i));
            logout ((yyvsp[0].vectorsymbol)->at(i)->getname());
            
        }
        logout ("\n\n");
    }
#line 3160 "y.tab.c"
    break;


#line 3164 "y.tab.c"

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

#line 1517 "1805063.y"

int main(int argc,char *argv[])
{
    ofstream file2("1805063_log.txt");
    file2.close();
    ofstream file3("1805063_error.txt");
    file3.close();
    table->enterscope("1",7);

	if(argc!=2){
		printf("Please provide input file name and try again\n");
		return 0;
	}
	
	FILE *fin=fopen(argv[1],"r");
	if(fin==NULL){
		printf("Cannot open specified file\n");
		return 0;
	}
	

	yyin= fin;
	//yylineno=1;
	//yylex();
    yyparse();
    table->printall();

    ofstream f2;
    f2.open("1805063_log.txt",ios::app);
    f2<<"Total Line: "<<line_count-1<<endl;
    f2<<"Total Error: "<<error<<endl;
    
    f2.close();

    

	fclose(yyin);
   
	return 0;



    
}

