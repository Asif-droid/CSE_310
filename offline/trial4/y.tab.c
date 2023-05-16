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
#line 1 "170000.y"

#include<bits/stdc++.h>
#include"SymbolTable.cpp"

using namespace std;

int yyparse(void);
int yylex(void);

extern FILE *yyin;
ofstream errorout;
ofstream logout;
ofstream code;
ofstream optimized_code;
ifstream read_code;

int line_count = 1;
int error_count = 0;
int temp_variable_count = 0;
int label_count = 0;

SymbolTable symboltable(logout, 30); 
string type;
string initial_code = "";
vector<pair<string, string>> data_list;

void yyerror(char *s){
	logout << "Error at line " << line_count << ": Syntax Error\n";
	errorout << "Error at line " << line_count << ": Syntax Error\n";
	error_count++;
}

string makeScopeID(string id){
	string x = ".";
	string y = "_";
	size_t pos;
	while ((pos = id.find(x)) != std::string::npos) {
        id.replace(pos, 1, y);
    }
	return id;
}

string newTemp(){
	string temp_variable  = "t" + to_string(temp_variable_count);
	temp_variable_count++;
	data_list.push_back({temp_variable,"0"});
	return temp_variable;
}

string newLabel(){
	string label  = "l" + to_string(label_count);
	label_count++;
	return label;
}

void Optimized_Code(string filename){
	read_code.open(filename);
	optimized_code.open("optimized_code.asm");
	string first_line;
	string second_line;
	string first_words;
	string final_first_words;
	string second_words;
	string final_second_words;

	while(getline(read_code,first_line)){
		optimized_code << first_line << "\n";
		vector <string> first_tokens;
		vector <string> second_tokens;
		stringstream check_first(first_line);
      
		// Tokenizing w.r.t. space ' '
		while(getline(check_first, first_words, ' ')){	
			stringstream check_first_word(first_words);
			while(getline(check_first_word, final_first_words, ',')){
				first_tokens.push_back(final_first_words);
			}
		}
		
		if(first_tokens.size() == 3 && first_tokens.at(0) == "\tmov"){
			getline(read_code,second_line);
			
			stringstream check_second(second_line);

			while(getline(check_second, second_words, ' ')){
				stringstream check_second_word(second_words);
				while(getline(check_second_word, final_second_words, ',')){
					second_tokens.push_back(final_second_words);
				}
			}
			if(second_tokens.size() == 3 && second_tokens.at(0) == "\tmov"){
				int match = first_tokens.at(1).compare(second_tokens.at(2));
				int match2 = first_tokens.at(2).compare(second_tokens.at(1));

				if(match == 0 && match2 == 0){}
				else{
					optimized_code << second_line << "\n";
				}	
			}
			else
				optimized_code << second_line << "\n";	
		}		
	}
	optimized_code.close();
}


#line 179 "y.tab.c"

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
    ID = 286,                      /* ID  */
    CONST_INT = 287,               /* CONST_INT  */
    CONST_FLOAT = 288,             /* CONST_FLOAT  */
    LOWER_THAN_ELSE = 289          /* LOWER_THAN_ELSE  */
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
#define ID 286
#define CONST_INT 287
#define CONST_FLOAT 288
#define LOWER_THAN_ELSE 289

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 109 "170000.y"

	vector<SymbolInfo*>* vectorsymbol;
	SymbolInfo *symbol;

#line 305 "y.tab.c"

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
  YYSYMBOL_ID = 31,                        /* ID  */
  YYSYMBOL_CONST_INT = 32,                 /* CONST_INT  */
  YYSYMBOL_CONST_FLOAT = 33,               /* CONST_FLOAT  */
  YYSYMBOL_LOWER_THAN_ELSE = 34,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_YYACCEPT = 35,                  /* $accept  */
  YYSYMBOL_start = 36,                     /* start  */
  YYSYMBOL_program = 37,                   /* program  */
  YYSYMBOL_unit = 38,                      /* unit  */
  YYSYMBOL_func_declaration = 39,          /* func_declaration  */
  YYSYMBOL_func_definition = 40,           /* func_definition  */
  YYSYMBOL_41_1 = 41,                      /* $@1  */
  YYSYMBOL_42_2 = 42,                      /* $@2  */
  YYSYMBOL_43_3 = 43,                      /* $@3  */
  YYSYMBOL_44_4 = 44,                      /* $@4  */
  YYSYMBOL_parameter_list = 45,            /* parameter_list  */
  YYSYMBOL_compound_statement = 46,        /* compound_statement  */
  YYSYMBOL_var_declaration = 47,           /* var_declaration  */
  YYSYMBOL_type_specifier = 48,            /* type_specifier  */
  YYSYMBOL_declaration_list = 49,          /* declaration_list  */
  YYSYMBOL_statements = 50,                /* statements  */
  YYSYMBOL_statement = 51,                 /* statement  */
  YYSYMBOL_52_5 = 52,                      /* $@5  */
  YYSYMBOL_53_6 = 53,                      /* $@6  */
  YYSYMBOL_expression_statement = 54,      /* expression_statement  */
  YYSYMBOL_variable = 55,                  /* variable  */
  YYSYMBOL_expression = 56,                /* expression  */
  YYSYMBOL_logic_expression = 57,          /* logic_expression  */
  YYSYMBOL_rel_expression = 58,            /* rel_expression  */
  YYSYMBOL_simple_expression = 59,         /* simple_expression  */
  YYSYMBOL_term = 60,                      /* term  */
  YYSYMBOL_unary_expression = 61,          /* unary_expression  */
  YYSYMBOL_factor = 62,                    /* factor  */
  YYSYMBOL_argument_list = 63,             /* argument_list  */
  YYSYMBOL_arguments = 64                  /* arguments  */
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
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   158

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  35
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  70
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  124

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   289


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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   127,   127,   193,   217,   233,   245,   257,   273,   328,
     354,   448,   354,   493,   537,   493,   579,   594,   606,   616,
     626,   646,   656,   680,   688,   695,   704,   733,   766,   789,
     817,   832,   858,   870,   880,   880,   880,   894,   943,   975,
    1023,  1061,  1086,  1110,  1117,  1133,  1167,  1210,  1221,  1301,
    1311,  1360,  1370,  1419,  1429,  1462,  1472,  1536,  1557,  1570,
    1582,  1593,  1716,  1733,  1743,  1753,  1786,  1819,  1830,  1837,
    1853
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
  "LOGICOP", "RELOP", "ASSIGNOP", "ID", "CONST_INT", "CONST_FLOAT",
  "LOWER_THAN_ELSE", "$accept", "start", "program", "unit",
  "func_declaration", "func_definition", "$@1", "$@2", "$@3", "$@4",
  "parameter_list", "compound_statement", "var_declaration",
  "type_specifier", "declaration_list", "statements", "statement", "$@5",
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

#define YYPACT_NINF (-76)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      58,   -76,   -76,   -76,    16,    58,   -76,   -76,   -76,   -76,
       6,   -76,   -76,     3,    77,    82,     2,    12,   -76,    22,
      -9,    30,    47,    54,   -76,    63,    48,    58,   -76,   -76,
      57,     9,   -76,   -76,    63,    51,    66,    80,    86,    87,
     118,   118,   118,   -76,    88,   -76,   118,    39,   -76,   -76,
     -76,    89,    73,   -76,    63,   -76,    33,    85,   -76,    83,
      27,    92,   -76,   -76,   -76,   -76,   -76,   -76,   118,   107,
     118,    90,    -1,   -76,   108,    95,   -76,   118,   118,   110,
     -76,   -76,   -76,   -76,   -76,   118,   -76,   118,   118,   118,
     118,   -76,   125,   107,   127,   -76,   -76,   128,   -76,   129,
     101,   114,   -76,   -76,   -76,    92,   122,   -76,   104,   118,
     104,   124,   -76,   118,   -76,   144,   136,   -76,   -76,   -76,
     104,   104,   -76,   -76
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    23,    24,    25,     0,     2,     4,     6,     7,     5,
       0,     1,     3,    28,     0,     0,     0,     0,    22,    13,
       0,    19,     0,    26,     9,     0,    10,     0,    18,    29,
       0,    34,    14,     8,     0,    17,     0,     0,     0,     0,
       0,     0,     0,    21,     0,    43,     0,    45,    63,    64,
      32,     0,    34,    30,     0,    33,    60,     0,    47,    49,
      51,    53,    55,    59,    15,    11,    16,    27,     0,     0,
       0,     0,    60,    58,     0,     0,    57,    68,     0,    28,
      20,    31,    35,    65,    66,     0,    44,     0,     0,     0,
       0,    12,     0,     0,     0,    42,    62,     0,    70,     0,
      67,     0,    36,    48,    50,    54,    52,    56,    34,     0,
      34,     0,    61,     0,    46,    38,     0,    40,    41,    69,
      34,    34,    39,    37
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -76,   -76,   -76,   148,   -76,   -76,   -76,   -76,   -76,   -76,
     -76,   -26,    52,    50,   -76,   -76,   -46,   -76,   -76,   -58,
     -41,   -39,   -75,    67,    68,    70,   -37,   -76,   -76,   -76
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     4,     5,     6,     7,     8,    34,    91,    25,    64,
      20,    32,    50,    51,    14,    52,    53,    54,   102,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    99,   100
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      72,    71,    98,    74,    73,    72,    81,    26,    65,    76,
     103,    93,    37,    27,    38,    39,    11,     1,    15,     2,
       3,    40,    16,    41,    42,    83,    84,    43,    82,    92,
      44,    94,    45,    46,    22,   109,    72,    13,   119,   101,
      47,    48,    49,    23,    72,    24,    72,    72,    72,    72,
      10,    88,     9,   107,    77,    10,    89,     9,    78,    83,
      84,    28,   115,    85,   117,    21,     1,    29,     2,     3,
     116,    33,    72,    30,   122,   123,    37,    35,    38,    39,
      31,     1,    66,     2,     3,    40,    67,    41,    42,    36,
       1,    80,     2,     3,    44,    68,    45,    46,    19,    17,
      18,    69,    70,    75,    47,    48,    49,    37,    86,    38,
      39,    87,     1,    95,     2,     3,    40,    90,    41,    42,
      79,    41,    42,   113,    96,    44,    97,    45,    46,    16,
      45,    46,    41,    42,   114,    47,    48,    49,    47,    48,
      49,   108,    46,   110,   111,   112,    88,   118,   120,    47,
      48,    49,   121,    12,   104,     0,     0,   106,   105
};

static const yytype_int8 yycheck[] =
{
      41,    40,    77,    42,    41,    46,    52,    16,    34,    46,
      85,    69,     3,    22,     5,     6,     0,     8,    15,    10,
      11,    12,    19,    14,    15,    26,    27,    18,    54,    68,
      21,    70,    23,    24,    32,    93,    77,    31,   113,    78,
      31,    32,    33,    31,    85,    23,    87,    88,    89,    90,
       0,    24,     0,    90,    15,     5,    29,     5,    19,    26,
      27,    31,   108,    30,   110,    15,     8,    20,    10,    11,
     109,    23,   113,    19,   120,   121,     3,    27,     5,     6,
      17,     8,    31,    10,    11,    12,    20,    14,    15,    32,
       8,    18,    10,    11,    21,    15,    23,    24,    16,    22,
      23,    15,    15,    15,    31,    32,    33,     3,    23,     5,
       6,    28,     8,    23,    10,    11,    12,    25,    14,    15,
      31,    14,    15,    22,    16,    21,    31,    23,    24,    19,
      23,    24,    14,    15,    20,    31,    32,    33,    31,    32,
      33,    16,    24,    16,    16,    16,    24,    23,     4,    31,
      32,    33,    16,     5,    87,    -1,    -1,    89,    88
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     8,    10,    11,    36,    37,    38,    39,    40,    47,
      48,     0,    38,    31,    49,    15,    19,    22,    23,    16,
      45,    48,    32,    31,    23,    43,    16,    22,    31,    20,
      19,    17,    46,    23,    41,    48,    32,     3,     5,     6,
      12,    14,    15,    18,    21,    23,    24,    31,    32,    33,
      47,    48,    50,    51,    52,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    44,    46,    31,    20,    15,    15,
      15,    56,    55,    61,    56,    15,    61,    15,    19,    31,
      18,    51,    46,    26,    27,    30,    23,    28,    24,    29,
      25,    42,    56,    54,    56,    23,    16,    31,    57,    63,
      64,    56,    53,    57,    58,    60,    59,    61,    16,    54,
      16,    16,    16,    22,    20,    51,    56,    51,    23,    57,
       4,    16,    51,    51
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    35,    36,    37,    37,    38,    38,    38,    39,    39,
      41,    42,    40,    43,    44,    40,    45,    45,    45,    45,
      46,    46,    47,    48,    48,    48,    49,    49,    49,    49,
      50,    50,    51,    51,    52,    53,    51,    51,    51,    51,
      51,    51,    51,    54,    54,    55,    55,    56,    56,    57,
      57,    58,    58,    59,    59,    60,    60,    61,    61,    61,
      62,    62,    62,    62,    62,    62,    62,    63,    63,    64,
      64
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     6,     5,
       0,     0,     8,     0,     0,     7,     4,     3,     2,     1,
       3,     2,     3,     1,     1,     1,     3,     6,     1,     4,
       1,     2,     1,     1,     0,     0,     3,     7,     5,     7,
       5,     5,     3,     1,     2,     1,     4,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     2,     2,     1,
       1,     4,     3,     1,     1,     2,     2,     1,     0,     3,
       1
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
#line 127 "170000.y"
               {
			(yyval.vectorsymbol) = new vector<SymbolInfo*>();
			for(int i = 0; i < (yyvsp[0].vectorsymbol)->size(); i++)
				(yyval.vectorsymbol)->push_back((yyvsp[0].vectorsymbol)->at(i));

			logout << "Line " << line_count-1 << ": start : program\n\n";

			//assembly code
			if(error_count == 0){
				initial_code += ".MODEL small\n.STACK 100h\n.DATA\n\tprint_var dw ?\n\tret_temp dw ?\n";

				//$$->setCode(initial_code);
				for(int i = 0; i < data_list.size(); i++){
					if(data_list.at(i).second == "0")
						initial_code += "\t" + data_list.at(i).first + " dw ?\n";	
					else
						initial_code += "\t" + data_list.at(i).first + " dw " + data_list.at(i).second + " dup(?)\n";
				}
				initial_code += ".CODE\n";
				
				//print function
				initial_code += "print PROC\n";
				initial_code +=	"\tpush ax\n";
				initial_code += "\tpush bx\n"; 
				initial_code += "\tpush cx\n";
				initial_code += "\tpush dx\n";
				initial_code += "\tmov ax, print_var\n";
				initial_code += "\tmov bx, 10\n";
				initial_code += "\tmov cx, 0\n";

				initial_code += "printLabel1:\n";
				initial_code += "\tmov dx, 0\n";
				initial_code += "\tdiv bx\n";
				initial_code += "\tpush dx\n";
				initial_code += "\tinc cx\n";
				initial_code += "\tcmp ax, 0\n";
				initial_code += "\tjne printLabel1\n";

				initial_code += "printLabel2:\n";
				initial_code += "\tmov ah, 2\n";
				initial_code += "\tpop dx\n";
				initial_code += "\tadd dl, '0'\n";
				initial_code += "\tint 21h\n";
				initial_code += "\tdec cx\n";
				initial_code += "\tcmp cx, 0\n";
				initial_code += "\tjne printLabel2\n";
				initial_code += "\tmov dl, 0Ah\n";
				initial_code += "\tint 21h\n";
				initial_code += "\tmov dl, 0Dh\n";
				initial_code += "\tint 21h\n";
				initial_code += "\tpop dx\n";
				initial_code += "\tpop cx\n";
				initial_code += "\tpop bx\n";
				initial_code += "\tpop ax\n";
				initial_code += "\tret\n";
				initial_code += "print endp\n";


				code << initial_code;
				code << (yyval.vectorsymbol)->at(0)->getCode();
				code << "END main\n";
			}	

		}
#line 1501 "y.tab.c"
    break;

  case 3: /* program: program unit  */
#line 194 "170000.y"
        {	(yyval.vectorsymbol) = new vector<SymbolInfo*>();
		logout << "line no " << line_count <<  ": program : program unit\n\n";
		for(int i = 0; i < (yyvsp[-1].vectorsymbol)->size(); i++){
			logout << (yyvsp[-1].vectorsymbol)->at(i)->getName();
			(yyval.vectorsymbol)->push_back((yyvsp[-1].vectorsymbol)->at(i));
			if((yyvsp[-1].vectorsymbol)->at(i)->getName() == "int" || (yyvsp[-1].vectorsymbol)->at(i)->getName() == "float" || (yyvsp[-1].vectorsymbol)->at(i)->getName() == "void" || (yyvsp[-1].vectorsymbol)->at(i)->getName() == "return")
				logout << " ";
			if((yyvsp[-1].vectorsymbol)->at(i)->getName() == ";" || (yyvsp[-1].vectorsymbol)->at(i)->getName() == "{" || (yyvsp[-1].vectorsymbol)->at(i)->getName() == "}")
				logout << "\n";
		}
		for(int i = 0; i < (yyvsp[0].vectorsymbol)->size(); i++){
			logout << (yyvsp[0].vectorsymbol)->at(i)->getName();
			(yyval.vectorsymbol)->push_back((yyvsp[0].vectorsymbol)->at(i));
			if((yyvsp[0].vectorsymbol)->at(i)->getName() == "int" || (yyvsp[0].vectorsymbol)->at(i)->getName() == "float" || (yyvsp[0].vectorsymbol)->at(i)->getName() == "void" || (yyvsp[0].vectorsymbol)->at(i)->getName() == "return")
				logout << " ";
			if((yyvsp[0].vectorsymbol)->at(i)->getName() == ";" || (yyvsp[0].vectorsymbol)->at(i)->getName() == "{" || (yyvsp[0].vectorsymbol)->at(i)->getName() == "}")
				logout << "\n";
		}
		logout << "\n\n";

		//assembly code
		(yyval.vectorsymbol)->at(0)->setCode((yyvsp[-1].vectorsymbol)->at(0)->getCode() + (yyvsp[0].vectorsymbol)->at(0)->getCode());
	}
#line 1529 "y.tab.c"
    break;

  case 4: /* program: unit  */
#line 218 "170000.y"
        {
		(yyval.vectorsymbol) = new vector<SymbolInfo*>();
		logout << "line no " << line_count <<  ": program : unit \n\n";
		for(int i = 0; i < (yyvsp[0].vectorsymbol)->size(); i++){
			logout << (yyvsp[0].vectorsymbol)->at(i)->getName();
			(yyval.vectorsymbol)->push_back((yyvsp[0].vectorsymbol)->at(i));
			if((yyvsp[0].vectorsymbol)->at(i)->getName() == "int" || (yyvsp[0].vectorsymbol)->at(i)->getName() == "float" || (yyvsp[0].vectorsymbol)->at(i)->getName() == "void" || (yyvsp[0].vectorsymbol)->at(i)->getName() == "return")
				logout << " ";
			if((yyvsp[0].vectorsymbol)->at(i)->getName() == ";" || (yyvsp[0].vectorsymbol)->at(i)->getName() == "{" || (yyvsp[0].vectorsymbol)->at(i)->getName() == "}")
				logout << "\n";
		}
		logout << "\n\n";
	}
#line 1547 "y.tab.c"
    break;

  case 5: /* unit: var_declaration  */
#line 234 "170000.y"
        {
		(yyval.vectorsymbol) = new vector<SymbolInfo*>();
		logout << "line no " << line_count <<  ": unit : var_declaration\n\n";
		for(int i = 0; i < (yyvsp[0].vectorsymbol)->size(); i++){
			logout << (yyvsp[0].vectorsymbol)->at(i)->getName();
			(yyval.vectorsymbol)->push_back((yyvsp[0].vectorsymbol)->at(i));
			if((yyvsp[0].vectorsymbol)->at(i)->getName() == "int" || (yyvsp[0].vectorsymbol)->at(i)->getName() == "float" || (yyvsp[0].vectorsymbol)->at(i)->getName() == "void")
				logout << " ";
		}
		logout << "\n\n";
	}
#line 1563 "y.tab.c"
    break;

  case 6: /* unit: func_declaration  */
#line 246 "170000.y"
     {
     		(yyval.vectorsymbol) = new vector<SymbolInfo*>();
     		logout << "line no " << line_count <<  ": unit : func_declaration\n\n";
     		for(int i = 0; i < (yyvsp[0].vectorsymbol)->size(); i++){
				logout << (yyvsp[0].vectorsymbol)->at(i)->getName();
				(yyval.vectorsymbol)->push_back((yyvsp[0].vectorsymbol)->at(i));
				if((yyvsp[0].vectorsymbol)->at(i)->getName() == "int" || (yyvsp[0].vectorsymbol)->at(i)->getName() == "float" || (yyvsp[0].vectorsymbol)->at(i)->getName() == "void")
					logout << " ";
			}
		logout << "\n\n"; 
     }
#line 1579 "y.tab.c"
    break;

  case 7: /* unit: func_definition  */
#line 258 "170000.y"
     {
     		(yyval.vectorsymbol) = new vector<SymbolInfo*>();
     		logout << "line no " << line_count <<  ": unit : func_definition\n\n";
     		for(int i = 0; i < (yyvsp[0].vectorsymbol)->size(); i++){
				logout << (yyvsp[0].vectorsymbol)->at(i)->getName();
				(yyval.vectorsymbol)->push_back((yyvsp[0].vectorsymbol)->at(i));
				if((yyvsp[0].vectorsymbol)->at(i)->getName() == "int" || (yyvsp[0].vectorsymbol)->at(i)->getName() == "float" || (yyvsp[0].vectorsymbol)->at(i)->getName() == "void" || (yyvsp[0].vectorsymbol)->at(i)->getName() == "return")
					logout << " ";
				if((yyvsp[0].vectorsymbol)->at(i)->getName() == ";" || (yyvsp[0].vectorsymbol)->at(i)->getName() == "{" || (yyvsp[0].vectorsymbol)->at(i)->getName() == "}")
					logout << "\n";
			}
		logout << "\n\n"; 
     }
#line 1597 "y.tab.c"
    break;

  case 8: /* func_declaration: type_specifier ID LPAREN parameter_list RPAREN SEMICOLON  */
#line 274 "170000.y"
                {
			(yyval.vectorsymbol) = new vector<SymbolInfo*>();
			logout << "line no " << line_count <<  ": func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON\n\n";
			
			// semantic error----------//
			if(symboltable.LookUp(logout, (yyvsp[-4].symbol)->getName()) != nullptr){   // Multiple declaration of function
				logout << "Error at line " << line_count << ": Multiple declaration of " << (yyvsp[-4].symbol)->getName() << "\n\n";
				errorout << "Error at line " << line_count << ": Multiple declaration of " << (yyvsp[-4].symbol)->getName() << "\n\n";
				error_count++;
			}
			vector<string> param_name;       // Multiple declaration of parameter
			for(int i = 0; i < (yyvsp[-2].vectorsymbol)->size(); i++){  
				if((yyvsp[-2].vectorsymbol)->at(i)->getType() == "ID"){
					param_name.push_back((yyvsp[-2].vectorsymbol)->at(i)->getName());
					for(int j = 0; j < param_name.size()-1; j++){
						if((yyvsp[-2].vectorsymbol)->at(i)->getName() == param_name.at(j)){
							param_name.pop_back();
							logout << "Error at line " << line_count << ": Multiple declaration of " << (yyvsp[-2].vectorsymbol)->at(i)->getName() << " in parameter\n\n";
							errorout << "Error at line " << line_count << ": Multiple declaration of " << (yyvsp[-2].vectorsymbol)->at(i)->getName() << " in parameter\n\n";
							error_count++;
						}
					}
				}
			}
			//Insert func declaration Into SymbolTable------------------//
			bool inserted = symboltable.Insert(logout, (yyvsp[-4].symbol)->getName(),"ID",(yyvsp[-5].symbol)->getType(), "func");
			cout << __LINE__ << (yyvsp[-4].symbol)->getName() << endl;
			//---------------//

			// store parameter type sequentially
			if(inserted){   
				SymbolInfo* temp = symboltable.LookUp(logout, (yyvsp[-4].symbol)->getName());
				for(int i = 0; i < (yyvsp[-2].vectorsymbol)->size(); i++){
					if((yyvsp[-2].vectorsymbol)->at(i)->getType() == "INT" || (yyvsp[-2].vectorsymbol)->at(i)->getType() == "FLOAT" || (yyvsp[-2].vectorsymbol)->at(i)->getType() == "VOID")
						temp->setParamType((yyvsp[-2].vectorsymbol)->at(i)->getType());
				}
			}
			//----------//

			logout << (yyvsp[-5].symbol)->getName() << " " << (yyvsp[-4].symbol)->getName() << (yyvsp[-3].symbol)->getName();
			(yyval.vectorsymbol)->push_back((yyvsp[-5].symbol));
			(yyval.vectorsymbol)->push_back((yyvsp[-4].symbol));
			(yyval.vectorsymbol)->push_back((yyvsp[-3].symbol));

			for(int i = 0; i < (yyvsp[-2].vectorsymbol)->size(); i++){
				logout << (yyvsp[-2].vectorsymbol)->at(i)->getName();
				(yyval.vectorsymbol)->push_back((yyvsp[-2].vectorsymbol)->at(i));
				if((yyvsp[-2].vectorsymbol)->at(i)->getName() == "int" || (yyvsp[-2].vectorsymbol)->at(i)->getName() == "float" || (yyvsp[-2].vectorsymbol)->at(i)->getName() == "void")
					logout << " ";
			}
			logout << (yyvsp[-1].symbol)->getName() << (yyvsp[0].symbol)->getName() << "\n\n";
			(yyval.vectorsymbol)->push_back((yyvsp[-1].symbol));
			(yyval.vectorsymbol)->push_back((yyvsp[0].symbol));
		}
#line 1656 "y.tab.c"
    break;

  case 9: /* func_declaration: type_specifier ID LPAREN RPAREN SEMICOLON  */
#line 328 "170000.y"
                                                           {
			logout << "line no " << line_count <<  ": func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON\n\n";
			
			// semantic error----------//
			if(symboltable.LookUp(logout, (yyvsp[-3].symbol)->getName()) != nullptr){   // Multiple declaration of function
				logout << "Error at line " << line_count << ": Multiple declaration of " << (yyvsp[-3].symbol)->getName() << "\n\n";
				errorout << "Error at line " << line_count << ": Multiple declaration of " << (yyvsp[-3].symbol)->getName() << "\n\n";
				error_count++;
			}
			//----------//

			logout << (yyvsp[-4].symbol)->getName() << " " << (yyvsp[-3].symbol)->getName() << (yyvsp[-2].symbol)->getName() << (yyvsp[-1].symbol)->getName() << (yyvsp[0].symbol)->getName() << "\n\n";
			(yyval.vectorsymbol) = new vector<SymbolInfo*>();
			(yyval.vectorsymbol)->push_back((yyvsp[-4].symbol));
			(yyval.vectorsymbol)->push_back((yyvsp[-3].symbol));
			(yyval.vectorsymbol)->push_back((yyvsp[-2].symbol));
			(yyval.vectorsymbol)->push_back((yyvsp[-1].symbol));
			(yyval.vectorsymbol)->push_back((yyvsp[0].symbol));

			//Insert func declaration Into SymbolTable------------------//
			bool inserted = symboltable.Insert(logout, (yyvsp[-3].symbol)->getName(),"ID",(yyvsp[-4].symbol)->getType(), "func");
			cout << __LINE__ << (yyvsp[-3].symbol)->getName() << endl;
			//---------------//
		}
#line 1685 "y.tab.c"
    break;

  case 10: /* $@1: %empty  */
#line 354 "170000.y"
                                                                 {
				if(symboltable.LookUp(logout, (yyvsp[-3].symbol)->getName()) == nullptr) {
					bool inserted = symboltable.Insert(logout, (yyvsp[-3].symbol)->getName(),"ID",(yyvsp[-4].symbol)->getType(), "func");
				}
				//semantic error-----------//
				else if((symboltable.LookUp(logout, (yyvsp[-3].symbol)->getName()))->getWhichVariable() != "func"){
					logout << "Error at line " << line_count << ": Multiple declaration of " << (yyvsp[-3].symbol)->getName() << "\n\n";
					errorout << "Error at line " << line_count << ": Multiple declaration of " << (yyvsp[-3].symbol)->getName() << "\n\n";
					error_count++;
				}
				else if((symboltable.LookUp(logout, (yyvsp[-3].symbol)->getName()))->getDefined()){     // Function Already Defined
					logout << "Error at line " << line_count << ": Multiple Definition of " << (yyvsp[-3].symbol)->getName() <<"\n\n";
					errorout << "Error at line " << line_count << ": Multiple Definition of " << (yyvsp[-3].symbol)->getName() <<"\n\n";
					error_count++;
				}
				else if(!(symboltable.LookUp(logout, (yyvsp[-3].symbol)->getName()))->getDefined()){        // Return type doesn't match with declaration
					(symboltable.LookUp(logout, (yyvsp[-3].symbol)->getName()))->setDefined(true);
					if((symboltable.LookUp(logout, (yyvsp[-3].symbol)->getName()))->getVariableType() != (yyvsp[-4].symbol)->getType()){
						logout << "Error at line " << line_count << ": Return type mismatch with function declaration in function " << (yyvsp[-3].symbol)->getName() << "\n\n";
						errorout << "Error at line " << line_count << ": Return type mismatch with function declaration in function " << (yyvsp[-3].symbol)->getName() << "\n\n";
						error_count++;
					}
				}
				
				vector<string> param_name;       // Multiple declaration of parameter
				for(int i = 0; i < (yyvsp[-1].vectorsymbol)->size(); i++){  
					if((yyvsp[-1].vectorsymbol)->at(i)->getType() == "ID"){
						param_name.push_back((yyvsp[-1].vectorsymbol)->at(i)->getName());
						for(int j = 0; j < param_name.size()-1; j++){
							if((yyvsp[-1].vectorsymbol)->at(i)->getName() == param_name.at(j)){
								param_name.pop_back();
								logout << "Error at line " << line_count << ": Multiple declaration of " << (yyvsp[-1].vectorsymbol)->at(i)->getName() << " in parameter\n\n";
								errorout << "Error at line " << line_count << ": Multiple declaration of " << (yyvsp[-1].vectorsymbol)->at(i)->getName() << " in parameter\n\n";
								error_count++;
							}
						}
					}
				}
				//------------//

				symboltable.EnterScope(logout);
				
				for (int i = 0; i < (yyvsp[-1].vectorsymbol)->size(); i++){      // Insert parameter into symboltable
					if((yyvsp[-1].vectorsymbol)->at(i)->getType() == "ID"){
						if((yyvsp[-1].vectorsymbol)->at(i-1)->getType() == "INT")
							bool inserted = symboltable.Insert(logout, (yyvsp[-1].vectorsymbol)->at(i)->getName(),"ID", "INT","var");
						else if((yyvsp[-1].vectorsymbol)->at(i-1)->getType() == "FLOAT")
							bool inserted = symboltable.Insert(logout, (yyvsp[-1].vectorsymbol)->at(i)->getName(),"ID", "FLOAT", "var");
						else if((yyvsp[-1].vectorsymbol)->at(i-1)->getType() == "VOID")
							bool inserted = symboltable.Insert(logout, (yyvsp[-1].vectorsymbol)->at(i)->getName(),"ID", "VOID", "var");

						//assembly code
						string symbol = (yyvsp[-1].vectorsymbol)->at(i)->getName() + "_" + symboltable.getCurrentID();
						(symboltable.LookUp(logout, (yyvsp[-1].vectorsymbol)->at(i)->getName()))->setSymbol(makeScopeID(symbol));
						// data_list.push_back({makeScopeID(symbol),"0"});
					}
				}
				SymbolInfo* temp = symboltable.LookUp(logout, (yyvsp[-3].symbol)->getName());       // store parameter type and parameter name sequentially
				if(temp->getParamSize() == 0){       
					for(int i = 0; i < (yyvsp[-1].vectorsymbol)->size(); i++){
						if((yyvsp[-1].vectorsymbol)->at(i)->getType() == "INT" || (yyvsp[-1].vectorsymbol)->at(i)->getType() == "FLOAT" || (yyvsp[-1].vectorsymbol)->at(i)->getType() == "VOID")
							temp->setParamType((yyvsp[-1].vectorsymbol)->at(i)->getType());
						else if((yyvsp[-1].vectorsymbol)->at(i)->getType() == "ID"){
							
							//assembly code
							string symbol = (yyvsp[-1].vectorsymbol)->at(i)->getName() + "_" + symboltable.getCurrentID();
							(symboltable.LookUp(logout, (yyvsp[-1].vectorsymbol)->at(i)->getName()))->setSymbol(makeScopeID(symbol));
							data_list.push_back({makeScopeID(symbol),"0"});
							temp->setParamName(makeScopeID(symbol));
						}
					}
				}
				else{          // function argument check with declaration
					vector<string> parameter_type;
					for(int i = 0; i < (yyvsp[-1].vectorsymbol)->size(); i++){
						if((yyvsp[-1].vectorsymbol)->at(i)->getType() == "INT" || (yyvsp[-1].vectorsymbol)->at(i)->getType() == "FLOAT" || (yyvsp[-1].vectorsymbol)->at(i)->getType() == "VOID"){
							parameter_type.push_back((yyvsp[-1].vectorsymbol)->at(i)->getType());
						}
					}
					if(parameter_type.size() != temp->getParamSize()){
						logout << "Error at line " << line_count << ": Total number of arguments mismatch with declaration in function " << (yyvsp[-3].symbol)->getName() << "\n\n";
						errorout << "Error at line " << line_count << ": Total number of arguments mismatch with declaration in function " << (yyvsp[-3].symbol)->getName() << "\n\n";
						error_count++;
					} 
					else{
						for(int i = 0; i < temp->getParamSize(); i++){
							if(parameter_type.at(i) != temp->getParamType(i)){
								logout << "Error at line " << line_count << ": " << i+1 << "th argument mismatch in function " << (yyvsp[-3].symbol)->getName() <<"\n\n";
								errorout << "Error at line " << line_count << ": " << i+1 << "th argument mismatch in function " << (yyvsp[-3].symbol)->getName() <<"\n\n";
								error_count++;
							}
						}
					}
				}
			}
#line 1785 "y.tab.c"
    break;

  case 11: /* $@2: %empty  */
#line 448 "170000.y"
                                             { 
				symboltable.printAllScopeTable(logout);
				symboltable.ExitScope(logout);
			}
#line 1794 "y.tab.c"
    break;

  case 12: /* func_definition: type_specifier ID LPAREN parameter_list RPAREN $@1 compound_statement $@2  */
#line 452 "170000.y"
                {
 			(yyval.vectorsymbol) = new vector<SymbolInfo*>();
			logout << "line no " << line_count <<  ": func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement\n\n";
			logout << (yyvsp[-7].symbol)->getName() << " " << (yyvsp[-6].symbol)->getName() << (yyvsp[-5].symbol)->getName();
			(yyval.vectorsymbol)->push_back((yyvsp[-7].symbol));
			(yyval.vectorsymbol)->push_back((yyvsp[-6].symbol));
			(yyval.vectorsymbol)->push_back((yyvsp[-5].symbol));
			for (int i = 0; i < (yyvsp[-4].vectorsymbol)->size(); i++){
				logout << (yyvsp[-4].vectorsymbol)->at(i)->getName();
				(yyval.vectorsymbol)->push_back((yyvsp[-4].vectorsymbol)->at(i));
				if((yyvsp[-4].vectorsymbol)->at(i)->getName() == "int" || (yyvsp[-4].vectorsymbol)->at(i)->getName() == "float" || (yyvsp[-4].vectorsymbol)->at(i)->getName() == "void")
					logout << " ";
			}
			logout << (yyvsp[-3].symbol)->getName();
			(yyval.vectorsymbol)->push_back((yyvsp[-3].symbol));
			for (int i = 0; i < (yyvsp[-1].vectorsymbol)->size(); i++){
				logout << (yyvsp[-1].vectorsymbol)->at(i)->getName();
				(yyval.vectorsymbol)->push_back((yyvsp[-1].vectorsymbol)->at(i));
				if((yyvsp[-1].vectorsymbol)->at(i)->getName() == "int" || (yyvsp[-1].vectorsymbol)->at(i)->getName() == "float" || (yyvsp[-1].vectorsymbol)->at(i)->getName() == "void" || (yyvsp[-1].vectorsymbol)->at(i)->getName() == "return")
					logout << " ";
				if((yyvsp[-1].vectorsymbol)->at(i)->getName() == ";" || (yyvsp[-1].vectorsymbol)->at(i)->getName() == "{" || (yyvsp[-1].vectorsymbol)->at(i)->getName() == "}")
					logout << "\n";
			}
			logout << "\n\n";

			//assembly code
			string segment_code = "";
			segment_code += (yyvsp[-6].symbol)->getName() + " PROC\n";
			if((yyvsp[-6].symbol)->getName() == "main")
				segment_code += "\tmov ax, @data\n\tmov ds, ax\n";
			else 
				segment_code += "\tpush ax\n\tpush bx\n\tpush cx\n\tpush dx\n";

			segment_code += (yyvsp[-1].vectorsymbol)->at(0)->getCode();
			if((yyvsp[-6].symbol)->getName() != "main")
				segment_code += "\tpop dx\n\tpop cx\n\tpop bx\n\tpop ax\n\tret\n";

			segment_code += (yyvsp[-6].symbol)->getName() + " ENDP\n";
			
			(yyval.vectorsymbol)->at(0)->setCode((yyval.vectorsymbol)->at(0)->getCode() + segment_code);
 		}
#line 1840 "y.tab.c"
    break;

  case 13: /* $@3: %empty  */
#line 493 "170000.y"
                                                  {

			if(symboltable.LookUp(logout, (yyvsp[-2].symbol)->getName()) == nullptr)
			{
				bool inserted = symboltable.Insert(logout, (yyvsp[-2].symbol)->getName(),"ID", (yyvsp[-3].symbol)->getType(), "func");
				// Ekhane main wala symbolinfo ke defined set kore felse

				SymbolInfo* temp = symboltable.LookUp(logout, (yyvsp[-2].symbol)->getName());  // Function Already Defined
				temp->setDefined(false);

				// if(temp->getDefined()) {
				// 	cout << $2->getName() << " defined" << endl;
				// }
				// else {
				// 	cout << $2->getName() << " not defined" << endl;
				// }

			}
			else
			{        // Return type doesn't match with declaration
				SymbolInfo* temp = symboltable.LookUp(logout, (yyvsp[-2].symbol)->getName());
				if(temp->getVariableType() != (yyvsp[-3].symbol)->getType())
				{
					logout << "Error at line " << line_count << ": Return type mismatch with function declaration in function " << (yyvsp[-2].symbol)->getName() << "\n\n";
					errorout << "Error at line " << line_count << ": Return type mismatch with function declaration in function " << (yyvsp[-2].symbol)->getName() << "\n\n";
					error_count++;
				}
			}

			SymbolInfo* temp = symboltable.LookUp(logout, (yyvsp[-2].symbol)->getName());  // Function Already Defined
			if(temp->getDefined())
			{
				logout << "Error at line " << line_count << ": Multiple Definition of " << (yyvsp[-2].symbol)->getName() <<"\n\n";
				errorout << "Error at line " << line_count << ": Multiple Definition of " << (yyvsp[-2].symbol)->getName() <<"\n\n";
				error_count++;
			}
			else
			{
				temp->setDefined(true);
			}
			//------------//

			symboltable.EnterScope(logout);
		}
#line 1889 "y.tab.c"
    break;

  case 14: /* $@4: %empty  */
#line 537 "170000.y"
                                   {
			symboltable.printAllScopeTable(logout);
			symboltable.ExitScope(logout);
		}
#line 1898 "y.tab.c"
    break;

  case 15: /* func_definition: type_specifier ID LPAREN RPAREN $@3 compound_statement $@4  */
#line 541 "170000.y"
                {
			(yyval.vectorsymbol) = new vector<SymbolInfo*>();
			logout << "line no " << line_count <<  ": func_definition : type_specifier ID LPAREN RPAREN compound_statement\n\n";
			logout << (yyvsp[-6].symbol)->getName() << " " << (yyvsp[-5].symbol)->getName() << (yyvsp[-4].symbol)->getName() << (yyvsp[-3].symbol)->getName();
			(yyval.vectorsymbol)->push_back((yyvsp[-6].symbol));
			(yyval.vectorsymbol)->push_back((yyvsp[-5].symbol));
			(yyval.vectorsymbol)->push_back((yyvsp[-4].symbol));
			(yyval.vectorsymbol)->push_back((yyvsp[-3].symbol));
			for (int i = 0; i < (yyvsp[-1].vectorsymbol)->size(); i++){
				logout << (yyvsp[-1].vectorsymbol)->at(i)->getName();
				(yyval.vectorsymbol)->push_back((yyvsp[-1].vectorsymbol)->at(i));
				if((yyvsp[-1].vectorsymbol)->at(i)->getName() == "int" || (yyvsp[-1].vectorsymbol)->at(i)->getName() == "float" || (yyvsp[-1].vectorsymbol)->at(i)->getName() == "void" || (yyvsp[-1].vectorsymbol)->at(i)->getName() == "return")
					logout << " ";
				if((yyvsp[-1].vectorsymbol)->at(i)->getName() == ";" || (yyvsp[-1].vectorsymbol)->at(i)->getName() == "{" || (yyvsp[-1].vectorsymbol)->at(i)->getName() == "}")
					logout << "\n";
			}
			logout << "\n\n";

			//assembly code
			string segment_code = "";
			segment_code += (yyvsp[-5].symbol)->getName() + " PROC\n";
			if((yyvsp[-5].symbol)->getName() == "main")
				segment_code += "\tmov ax, @data\n\tmov ds, ax\n";
			else 
				segment_code += "\tpush ax\n\tpush bx\n\tpush cx\n\tpush dx\n";

			segment_code += (yyvsp[-1].vectorsymbol)->at(0)->getCode();
			if((yyvsp[-5].symbol)->getName() != "main")
				segment_code += "\tpop dx\n\tpop cx\n\tpop bx\n\tpop ax\n\tret\n";

			segment_code += (yyvsp[-5].symbol)->getName() + " ENDP\n";
			
			(yyval.vectorsymbol)->at(0)->setCode((yyval.vectorsymbol)->at(0)->getCode() + segment_code);
			
		}
#line 1938 "y.tab.c"
    break;

  case 16: /* parameter_list: parameter_list COMMA type_specifier ID  */
#line 580 "170000.y"
                {
			(yyval.vectorsymbol) = new vector<SymbolInfo*>();
			logout << "line no " << line_count <<  ": parameter_list : parameter_list COMMA type_specifier ID\n\n";
			for(int i = 0; i < (yyvsp[-3].vectorsymbol)->size(); i++){
				logout << (yyvsp[-3].vectorsymbol)->at(i)->getName();
				(yyval.vectorsymbol)->push_back((yyvsp[-3].vectorsymbol)->at(i));
				if((yyvsp[-3].vectorsymbol)->at(i)->getName() == "int" || (yyvsp[-3].vectorsymbol)->at(i)->getName() == "float" || (yyvsp[-3].vectorsymbol)->at(i)->getName() == "void")
					logout << " ";
			}
			logout << (yyvsp[-2].symbol)->getName() << (yyvsp[-1].symbol)->getName() << " " << (yyvsp[0].symbol)->getName() << "\n\n"; 
			(yyval.vectorsymbol)->push_back((yyvsp[-2].symbol));
			(yyval.vectorsymbol)->push_back((yyvsp[-1].symbol));
			(yyval.vectorsymbol)->push_back((yyvsp[0].symbol));
		}
#line 1957 "y.tab.c"
    break;

  case 17: /* parameter_list: parameter_list COMMA type_specifier  */
#line 595 "170000.y"
                {
			(yyval.vectorsymbol) = new vector<SymbolInfo*>();
			logout << "line no " << line_count <<  ": parameter_list : parameter_list COMMA type_specifier\n\n";
			for(int i = 0; i < (yyvsp[-2].vectorsymbol)->size(); i++){
				logout << (yyvsp[-2].vectorsymbol)->at(i)->getName();
				(yyval.vectorsymbol)->push_back((yyvsp[-2].vectorsymbol)->at(i));
			}
			logout << (yyvsp[-1].symbol)->getName() << (yyvsp[0].symbol)->getName() << "\n\n";
			(yyval.vectorsymbol)->push_back((yyvsp[-1].symbol));
			(yyval.vectorsymbol)->push_back((yyvsp[0].symbol));
		}
#line 1973 "y.tab.c"
    break;

  case 18: /* parameter_list: type_specifier ID  */
#line 607 "170000.y"
                {
 			logout << "line no " << line_count <<  ": parameter_list : type_specifier ID\n\n";
 			logout << (yyvsp[-1].symbol)->getName() << " " << (yyvsp[0].symbol)->getName() << "\n\n";
 			(yyval.vectorsymbol) = new vector<SymbolInfo*>();
 			(yyval.vectorsymbol)->push_back((yyvsp[-1].symbol));
 			(yyval.vectorsymbol)->push_back((yyvsp[0].symbol));

			//assembly code
 		}
#line 1987 "y.tab.c"
    break;

  case 19: /* parameter_list: type_specifier  */
#line 617 "170000.y"
                {
			logout << "line no " << line_count <<  ": parameter_list : type_specifier\n\n";
			logout << (yyvsp[0].symbol)->getName() << "\n\n";
			(yyval.vectorsymbol) = new vector<SymbolInfo*>();
			(yyval.vectorsymbol)->push_back((yyvsp[0].symbol));
		}
#line 1998 "y.tab.c"
    break;

  case 20: /* compound_statement: LCURL statements RCURL  */
#line 626 "170000.y"
                                           {
				(yyval.vectorsymbol) = new vector<SymbolInfo*>();
				logout << "line no " << line_count <<  ": compound_statement : LCURL statements RCURL\n\n";
				logout << (yyvsp[-2].symbol)->getName() << "\n";
				(yyval.vectorsymbol)->push_back((yyvsp[-2].symbol));
				for(int i = 0; i < (yyvsp[-1].vectorsymbol)->size(); i++){
					(yyval.vectorsymbol)->push_back((yyvsp[-1].vectorsymbol)->at(i));
					logout << (yyvsp[-1].vectorsymbol)->at(i)->getName();
					if((yyvsp[-1].vectorsymbol)->at(i)->getName() == "int" || (yyvsp[-1].vectorsymbol)->at(i)->getName() == "float" || (yyvsp[-1].vectorsymbol)->at(i)->getName() == "void" || (yyvsp[-1].vectorsymbol)->at(i)->getName() == "return")
						logout << " ";
					if((yyvsp[-1].vectorsymbol)->at(i)->getName() == ";" || (yyvsp[-1].vectorsymbol)->at(i)->getName() == "{" || (yyvsp[-1].vectorsymbol)->at(i)->getName() == "}")
						logout << "\n";
				}
				logout << (yyvsp[0].symbol)->getName() << "\n\n";
				(yyval.vectorsymbol)->push_back((yyvsp[0].symbol));


				//assembly code
				(yyval.vectorsymbol)->at(0)->setCode((yyval.vectorsymbol)->at(0)->getCode() + (yyvsp[-1].vectorsymbol)->at(0)->getCode());
		    }
#line 2023 "y.tab.c"
    break;

  case 21: /* compound_statement: LCURL RCURL  */
#line 647 "170000.y"
                    {
 		    	(yyval.vectorsymbol) = new vector<SymbolInfo*>();
 		    	logout << "line no " << line_count <<  ": compound_statement : LCURL RCURL\n\n";
				logout << (yyvsp[-1].symbol)->getName() << (yyvsp[0].symbol)->getName() << "\n\n";
				(yyval.vectorsymbol)->push_back((yyvsp[-1].symbol));
				(yyval.vectorsymbol)->push_back((yyvsp[0].symbol));
 		    }
#line 2035 "y.tab.c"
    break;

  case 22: /* var_declaration: type_specifier declaration_list SEMICOLON  */
#line 657 "170000.y"
                 {
		 	(yyval.vectorsymbol) = new vector<SymbolInfo*>();
		 	logout << "line no " << line_count <<  ": var_declaration : type_specifier declaration_list SEMICOLON\n\n";
			
			// semantic error-----------//
			if((yyvsp[-2].symbol)->getType() == "VOID"){
				logout << "Error at line " << line_count << ": Variable type cannot be void\n\n";
				errorout << "Error at line " << line_count << ": Variable type cannot be void\n\n";
				error_count++;
			}
			//---------------//
		 	logout << (yyvsp[-2].symbol)->getName() << " ";
		 	(yyval.vectorsymbol)->push_back((yyvsp[-2].symbol));
		  	for(int i = 0; i < (yyvsp[-1].vectorsymbol)->size(); i++){
		  		(yyval.vectorsymbol)->push_back((yyvsp[-1].vectorsymbol)->at(i));
		  		logout << (yyvsp[-1].vectorsymbol)->at(i)->getName();
		  	}
			
			logout << (yyvsp[0].symbol)->getName() << "\n\n";
			(yyval.vectorsymbol)->push_back((yyvsp[0].symbol));
		 }
#line 2061 "y.tab.c"
    break;

  case 23: /* type_specifier: INT  */
#line 681 "170000.y"
                {
			logout << "line no " << line_count <<  ": type_specifier :  INT\n\n";
			logout << (yyvsp[0].symbol)->getName() << "\n\n";
			(yyval.symbol) = (yyvsp[0].symbol);
			type = "INT";
		}
#line 2072 "y.tab.c"
    break;

  case 24: /* type_specifier: FLOAT  */
#line 689 "170000.y"
                {
 			logout << "line no " << line_count <<  ": type_specifier :  FLOAT\n\n";
			logout << (yyvsp[0].symbol)->getName() << "\n\n";
			(yyval.symbol) = (yyvsp[0].symbol);
			type = "FLOAT";
 		}
#line 2083 "y.tab.c"
    break;

  case 25: /* type_specifier: VOID  */
#line 696 "170000.y"
                {
 			logout << "line no " << line_count <<  ": type_specifier :  VOID\n\n";
			logout << (yyvsp[0].symbol)->getName() << "\n\n";
			(yyval.symbol) = (yyvsp[0].symbol);
			type = "VOID";
 		}
#line 2094 "y.tab.c"
    break;

  case 26: /* declaration_list: declaration_list COMMA ID  */
#line 705 "170000.y"
                  { 
			//semantic error------//
			bool inserted;
			if(type != "VOID")      // don't insert void variable in symboltable
				inserted = symboltable.Insert(logout, (yyvsp[0].symbol)->getName(),"ID",type,"var");
			if(!inserted){
				logout << "Error at line " << line_count << ": Multiple declaration of " << (yyvsp[0].symbol)->getName() << "\n\n";
				errorout << "Error at line " << line_count << ": Multiple declaration of " << (yyvsp[0].symbol)->getName() << "\n\n";
				error_count++;
			}
			//--------//

		  	(yyval.vectorsymbol) = new vector<SymbolInfo*>();
		  	logout << "line no " << line_count <<  ": declaration_list : declaration_list COMMA ID\n\n";
		  	for(int i = 0; i < (yyvsp[-2].vectorsymbol)->size(); i++){
		  		(yyval.vectorsymbol)->push_back((yyvsp[-2].vectorsymbol)->at(i));
		  		logout << (yyvsp[-2].vectorsymbol)->at(i)->getName();
		  	}
			logout << (yyvsp[-1].symbol)->getName() << (yyvsp[0].symbol)->getName() << "\n\n";
			(yyval.vectorsymbol)->push_back((yyvsp[-1].symbol));
			(yyval.vectorsymbol)->push_back((yyvsp[0].symbol));

			
			//assembly code
			string symbol = (yyvsp[0].symbol)->getName() + "_" + symboltable.getCurrentID();
			(symboltable.LookUp(logout, (yyvsp[0].symbol)->getName()))->setSymbol(makeScopeID(symbol));
			data_list.push_back({makeScopeID(symbol),"0"});
		  }
#line 2127 "y.tab.c"
    break;

  case 27: /* declaration_list: declaration_list COMMA ID LTHIRD CONST_INT RTHIRD  */
#line 734 "170000.y"
                  {
			//semantic error------//
			bool inserted;
			if(type != "VOID")      // don't insert void variable in symboltable
				inserted = symboltable.Insert(logout, (yyvsp[-3].symbol)->getName(),"ID",type,"array");
			if(!inserted){
				logout << "Error at line " << line_count << ": Multiple declaration of " << (yyvsp[-3].symbol)->getName() << "\n\n";
				errorout << "Error at line " << line_count << ": Multiple declaration of " << (yyvsp[-3].symbol)->getName() << "\n\n";
				error_count++;
			}
			//--------//

		  	(yyval.vectorsymbol) = new vector<SymbolInfo*>();
		  	logout << "line no " << line_count <<  ": declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD\n\n";
		  	for(int i = 0; i < (yyvsp[-5].vectorsymbol)->size(); i++){
		  		(yyval.vectorsymbol)->push_back((yyvsp[-5].vectorsymbol)->at(i));
		  		logout << (yyvsp[-5].vectorsymbol)->at(i)->getName();
		  	}
			logout << (yyvsp[-4].symbol)->getName() << (yyvsp[-3].symbol)->getName() <<  (yyvsp[-2].symbol)->getName() << (yyvsp[-1].symbol)->getName() << (yyvsp[0].symbol)->getName() << "\n\n";
			(yyval.vectorsymbol)->push_back((yyvsp[-4].symbol));
			(yyval.vectorsymbol)->push_back((yyvsp[-3].symbol));
			(yyval.vectorsymbol)->push_back((yyvsp[-2].symbol));
			(yyval.vectorsymbol)->push_back((yyvsp[-1].symbol));
			(yyval.vectorsymbol)->push_back((yyvsp[0].symbol));

			//assembly code
			string symbol = (yyvsp[-3].symbol)->getName() + "_" + symboltable.getCurrentID();
			(symboltable.LookUp(logout, (yyvsp[-3].symbol)->getName()))->setSymbol(makeScopeID(symbol));
			data_list.push_back({makeScopeID(symbol),(yyvsp[-1].symbol)->getName()});

			//done
		  }
#line 2164 "y.tab.c"
    break;

  case 28: /* declaration_list: ID  */
#line 767 "170000.y"
                  {
			//semantic error------//
			bool inserted;
			if(type != "VOID")     // don't insert void variable in symboltable
				inserted = symboltable.Insert(logout, (yyvsp[0].symbol)->getName(),"ID",type, "var");
			if(!inserted){
				logout << "Error at line " << line_count << ": Multiple declaration of " << (yyvsp[0].symbol)->getName() << "\n\n";
				errorout << "Error at line " << line_count << ": Multiple declaration of " << (yyvsp[0].symbol)->getName() << "\n\n";
				error_count++;
			}
			//--------//

			(yyval.vectorsymbol) = new vector<SymbolInfo*>();
 		  	logout << "line no " << line_count <<  ": declaration_list : ID\n\n";
			logout << (yyvsp[0].symbol)->getName() << "\n\n";
			(yyval.vectorsymbol)->push_back((yyvsp[0].symbol));

			//assembly code
			string symbol = (yyvsp[0].symbol)->getName() + "_" + symboltable.getCurrentID();
			(symboltable.LookUp(logout, (yyvsp[0].symbol)->getName()))->setSymbol(makeScopeID(symbol));
			data_list.push_back({makeScopeID(symbol),"0"});
 		  }
#line 2191 "y.tab.c"
    break;

  case 29: /* declaration_list: ID LTHIRD CONST_INT RTHIRD  */
#line 790 "170000.y"
                  {
			//semantic error------//
			bool inserted;
			if(type != "VOID")      // don't insert void variable in symboltable
				inserted = symboltable.Insert(logout, (yyvsp[-3].symbol)->getName(),"ID",type, "array");
			if(!inserted){
				logout << "Error at line " << line_count << ": Multiple declaration of " << (yyvsp[-3].symbol)->getName() << "\n\n";
				errorout << "Error at line " << line_count << ": Multiple declaration of " << (yyvsp[-3].symbol)->getName() << "\n\n";
				error_count++;
			}
			//--------//

 		  	(yyval.vectorsymbol) = new vector<SymbolInfo*>();
 		  	logout << "line no " << line_count <<  ": declaration_list : ID LTHIRD CONST_INT RTHIRD\n\n";
 		  	logout << (yyvsp[-3].symbol)->getName() << (yyvsp[-2].symbol)->getName() << (yyvsp[-1].symbol)->getName() << (yyvsp[0].symbol)->getName() << "\n\n";
 		  	(yyval.vectorsymbol)->push_back((yyvsp[-3].symbol));
 		  	(yyval.vectorsymbol)->push_back((yyvsp[-2].symbol));
 		  	(yyval.vectorsymbol)->push_back((yyvsp[-1].symbol));
 		  	(yyval.vectorsymbol)->push_back((yyvsp[0].symbol));

			//assembly code
			string symbol = (yyvsp[-3].symbol)->getName() + "_" + symboltable.getCurrentID();
			(symboltable.LookUp(logout, (yyvsp[-3].symbol)->getName()))->setSymbol(makeScopeID(symbol));
			data_list.push_back({makeScopeID(symbol),(yyvsp[-1].symbol)->getName()});
 		  }
#line 2221 "y.tab.c"
    break;

  case 30: /* statements: statement  */
#line 818 "170000.y"
           {
		(yyval.vectorsymbol) = new vector<SymbolInfo*>();
	  	logout << "line no " << line_count <<  ": statements : statement\n\n";
		for(int i = 0; i < (yyvsp[0].vectorsymbol)->size(); i++){
			logout << (yyvsp[0].vectorsymbol)->at(i)->getName();
			(yyval.vectorsymbol)->push_back((yyvsp[0].vectorsymbol)->at(i));
			if((yyvsp[0].vectorsymbol)->at(i)->getName() == "int" || (yyvsp[0].vectorsymbol)->at(i)->getName() == "float" || (yyvsp[0].vectorsymbol)->at(i)->getName() == "void" || (yyvsp[0].vectorsymbol)->at(i)->getName() == "return")
				logout << " ";
			if((yyvsp[0].vectorsymbol)->at(i)->getName() == ";" || (yyvsp[0].vectorsymbol)->at(i)->getName() == "{" || (yyvsp[0].vectorsymbol)->at(i)->getName() == "}")
					logout << "\n";
		}
		logout << "\n\n";
		(yyval.vectorsymbol)->at(0)->setCode((yyval.vectorsymbol)->at(0)->getCode() + (yyvsp[0].vectorsymbol)->at(0)->getCode());
	   }
#line 2240 "y.tab.c"
    break;

  case 31: /* statements: statements statement  */
#line 833 "170000.y"
           {
	   	(yyval.vectorsymbol) = new vector<SymbolInfo*>();
	  	logout << "line no " << line_count <<  ": statements : statements statement\n\n";
		for(int i = 0; i < (yyvsp[-1].vectorsymbol)->size(); i++){
			logout << (yyvsp[-1].vectorsymbol)->at(i)->getName();
			(yyval.vectorsymbol)->push_back((yyvsp[-1].vectorsymbol)->at(i));
			if((yyvsp[-1].vectorsymbol)->at(i)->getName() == "int" || (yyvsp[-1].vectorsymbol)->at(i)->getName() == "float" || (yyvsp[-1].vectorsymbol)->at(i)->getName() == "void" || (yyvsp[-1].vectorsymbol)->at(i)->getName() == "return")
				logout << " ";
			if((yyvsp[-1].vectorsymbol)->at(i)->getName() == ";" || (yyvsp[-1].vectorsymbol)->at(i)->getName() == "{" || (yyvsp[-1].vectorsymbol)->at(i)->getName() == "}")
				logout << "\n";
		}
		for(int i = 0; i < (yyvsp[0].vectorsymbol)->size(); i++){
			logout << (yyvsp[0].vectorsymbol)->at(i)->getName();
			(yyval.vectorsymbol)->push_back((yyvsp[0].vectorsymbol)->at(i));
			if((yyvsp[0].vectorsymbol)->at(i)->getName() == "int" || (yyvsp[0].vectorsymbol)->at(i)->getName() == "float" || (yyvsp[0].vectorsymbol)->at(i)->getName() == "void" || (yyvsp[0].vectorsymbol)->at(i)->getName() == "return")
				logout << " ";
			if((yyvsp[0].vectorsymbol)->at(i)->getName() == ";" || (yyvsp[0].vectorsymbol)->at(i)->getName() == "{" || (yyvsp[0].vectorsymbol)->at(i)->getName() == "}")
				logout << "\n";
		}
		logout << "\n\n";

		//assembly code
		(yyval.vectorsymbol)->at(0)->setCode((yyval.vectorsymbol)->at(0)->getCode() + (yyvsp[0].vectorsymbol)->at(0)->getCode());
	   }
#line 2269 "y.tab.c"
    break;

  case 32: /* statement: var_declaration  */
#line 859 "170000.y"
          {
	  	(yyval.vectorsymbol) = new vector<SymbolInfo*>();
	  	logout << "line no " << line_count <<  ": statement : var_declaration\n\n";
		for(int i = 0; i < (yyvsp[0].vectorsymbol)->size(); i++){
			logout << (yyvsp[0].vectorsymbol)->at(i)->getName();
			(yyval.vectorsymbol)->push_back((yyvsp[0].vectorsymbol)->at(i));
			if((yyvsp[0].vectorsymbol)->at(i)->getName() == "int" || (yyvsp[0].vectorsymbol)->at(i)->getName() == "float" || (yyvsp[0].vectorsymbol)->at(i)->getName() == "void")
				logout << " ";
		}
		logout << "\n\n";
	  }
#line 2285 "y.tab.c"
    break;

  case 33: /* statement: expression_statement  */
#line 871 "170000.y"
          {
	  	(yyval.vectorsymbol) = new vector<SymbolInfo*>();
	  	logout << "line no " << line_count <<  ": statement : expression_statement\n\n";
	  	for(int i = 0; i < (yyvsp[0].vectorsymbol)->size(); i++){
			logout << (yyvsp[0].vectorsymbol)->at(i)->getName();
			(yyval.vectorsymbol)->push_back((yyvsp[0].vectorsymbol)->at(i));
		}
		logout << "\n\n";
	  }
#line 2299 "y.tab.c"
    break;

  case 34: /* $@5: %empty  */
#line 880 "170000.y"
             {symboltable.EnterScope(logout);}
#line 2305 "y.tab.c"
    break;

  case 35: /* $@6: %empty  */
#line 880 "170000.y"
                                                                  {symboltable.printAllScopeTable(logout); symboltable.ExitScope(logout);}
#line 2311 "y.tab.c"
    break;

  case 36: /* statement: $@5 compound_statement $@6  */
#line 881 "170000.y"
          {
	  	(yyval.vectorsymbol) = new vector<SymbolInfo*>();
	  	logout << "line no " << line_count <<  ": statement : compound_statement\n\n";
	  	for(int i = 0; i < (yyvsp[-1].vectorsymbol)->size(); i++){
			logout << (yyvsp[-1].vectorsymbol)->at(i)->getName();
			(yyval.vectorsymbol)->push_back((yyvsp[-1].vectorsymbol)->at(i));
			if((yyvsp[-1].vectorsymbol)->at(i)->getName() == "int" || (yyvsp[-1].vectorsymbol)->at(i)->getName() == "float" || (yyvsp[-1].vectorsymbol)->at(i)->getName() == "void" || (yyvsp[-1].vectorsymbol)->at(i)->getName() == "return")
				logout << " ";
			if((yyvsp[-1].vectorsymbol)->at(i)->getName() == ";" || (yyvsp[-1].vectorsymbol)->at(i)->getName() == "{" || (yyvsp[-1].vectorsymbol)->at(i)->getName() == "}")
					logout << "\n";
		}
		logout << "\n\n";
	  }
#line 2329 "y.tab.c"
    break;

  case 37: /* statement: FOR LPAREN expression_statement expression_statement expression RPAREN statement  */
#line 895 "170000.y"
          {
  	  	(yyval.vectorsymbol) = new vector<SymbolInfo*>();
	  	logout << "line no " << line_count <<  ":statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement\n\n";
	  	logout << (yyvsp[-6].symbol)->getName() << (yyvsp[-5].symbol)->getName();
	  	for(int i = 0; i < (yyvsp[-4].vectorsymbol)->size(); i++){
			logout << (yyvsp[-4].vectorsymbol)->at(i)->getName();
			(yyval.vectorsymbol)->push_back((yyvsp[-4].vectorsymbol)->at(i));
		}
		for(int i = 0; i < (yyvsp[-3].vectorsymbol)->size(); i++){
			logout << (yyvsp[-3].vectorsymbol)->at(i)->getName();
			(yyval.vectorsymbol)->push_back((yyvsp[-3].vectorsymbol)->at(i));
		}
		for(int i = 0; i < (yyvsp[-2].vectorsymbol)->size(); i++){
			logout << (yyvsp[-2].vectorsymbol)->at(i)->getName();
			(yyval.vectorsymbol)->push_back((yyvsp[-2].vectorsymbol)->at(i));
		}
		logout << (yyvsp[-1].symbol)->getName();
		(yyval.vectorsymbol)->push_back((yyvsp[-1].symbol));
		for(int i = 0; i < (yyvsp[0].vectorsymbol)->size(); i++){
			logout << (yyvsp[0].vectorsymbol)->at(i)->getName();
			(yyval.vectorsymbol)->push_back((yyvsp[0].vectorsymbol)->at(i));
			if((yyvsp[0].vectorsymbol)->at(i)->getName() == "int" || (yyvsp[0].vectorsymbol)->at(i)->getName() == "float" || (yyvsp[0].vectorsymbol)->at(i)->getName() == "void" || (yyvsp[0].vectorsymbol)->at(i)->getName() == "return")
				logout << " ";
			if((yyvsp[0].vectorsymbol)->at(i)->getName() == ";" || (yyvsp[0].vectorsymbol)->at(i)->getName() == "{" || (yyvsp[0].vectorsymbol)->at(i)->getName() == "}")
				logout << "\n";
		}
		logout << "\n\n";

		//assembly code
		string label1 = newLabel();
		string label2 = newLabel();
		
		string segment_code = "";
		segment_code += (yyvsp[-4].vectorsymbol)->at(0)->getCode();
		segment_code += label1 + ":\n";
		segment_code += (yyvsp[-3].vectorsymbol)->at(0)->getCode();
		segment_code += "\tmov ax, " + (yyvsp[-3].vectorsymbol)->at(0)->getSymbol() + "\n";
		segment_code += "\tcmp ax, 0\n";
		segment_code += "\tje " + label2 + "\n";
		segment_code += (yyvsp[0].vectorsymbol)->at(0)->getCode();
		segment_code += (yyvsp[-2].vectorsymbol)->at(0)->getCode();
		segment_code += "\tjmp " + label1 + "\n";
		segment_code += label2 + ":\n";

		(yyval.vectorsymbol)->at(0)->setCode(segment_code);


  	  }
#line 2382 "y.tab.c"
    break;

  case 38: /* statement: IF LPAREN expression RPAREN statement  */
#line 944 "170000.y"
          {
	  	(yyval.vectorsymbol) = new vector<SymbolInfo*>();
	  	logout << "line no " << line_count <<  ": statement : IF LPAREN expression RPAREN statement\n\n";
	  	logout << (yyvsp[-4].symbol)->getName() << (yyvsp[-3].symbol)->getName();
	  	for(int i = 0; i < (yyvsp[-2].vectorsymbol)->size(); i++){
			logout << (yyvsp[-2].vectorsymbol)->at(i)->getName();
			(yyval.vectorsymbol)->push_back((yyvsp[-2].vectorsymbol)->at(i));
		}
		logout << (yyvsp[-1].symbol)->getName();
		(yyval.vectorsymbol)->push_back((yyvsp[-1].symbol));
		for(int i = 0; i < (yyvsp[0].vectorsymbol)->size(); i++){
			logout << (yyvsp[0].vectorsymbol)->at(i)->getName();
			(yyval.vectorsymbol)->push_back((yyvsp[0].vectorsymbol)->at(i));
			if((yyvsp[0].vectorsymbol)->at(i)->getName() == "int" || (yyvsp[0].vectorsymbol)->at(i)->getName() == "float" || (yyvsp[0].vectorsymbol)->at(i)->getName() == "void" || (yyvsp[0].vectorsymbol)->at(i)->getName() == "return")
				logout << " ";
			if((yyvsp[0].vectorsymbol)->at(i)->getName() == ";" || (yyvsp[0].vectorsymbol)->at(i)->getName() == "{" || (yyvsp[0].vectorsymbol)->at(i)->getName() == "}")
				logout << "\n";
		}
		logout << "\n\n";

		//assembly code
		string label = newLabel();
		string segment_code = "";
		segment_code += "\tmov ax, " + (yyvsp[-2].vectorsymbol)->at(0)->getSymbol() + "\n";
		segment_code += "\tcmp ax, 0\n";
		segment_code += "\tje " + label + "\n";
		segment_code += (yyvsp[0].vectorsymbol)->at(0)->getCode();
		segment_code += label + ":\n";

		(yyval.vectorsymbol)->at(0)->setCode((yyval.vectorsymbol)->at(0)->getCode() + segment_code);
	  }
#line 2418 "y.tab.c"
    break;

  case 39: /* statement: IF LPAREN expression RPAREN statement ELSE statement  */
#line 976 "170000.y"
          {
	  	(yyval.vectorsymbol) = new vector<SymbolInfo*>();
	  	logout << "line no " << line_count <<  ": statement : IF LPAREN expression RPAREN statement ELSE statement\n\n";
	  	logout << (yyvsp[-6].symbol)->getName() << (yyvsp[-5].symbol)->getName();
	  	for(int i = 0; i < (yyvsp[-4].vectorsymbol)->size(); i++){
			logout << (yyvsp[-4].vectorsymbol)->at(i)->getName();
			(yyval.vectorsymbol)->push_back((yyvsp[-4].vectorsymbol)->at(i));
		}
		logout << (yyvsp[-3].symbol)->getName();
		(yyval.vectorsymbol)->push_back((yyvsp[-3].symbol));
		for(int i = 0; i < (yyvsp[-2].vectorsymbol)->size(); i++){
			logout << (yyvsp[-2].vectorsymbol)->at(i)->getName();
			(yyval.vectorsymbol)->push_back((yyvsp[-2].vectorsymbol)->at(i));
			if((yyvsp[-2].vectorsymbol)->at(i)->getName() == "int" || (yyvsp[-2].vectorsymbol)->at(i)->getName() == "float" || (yyvsp[-2].vectorsymbol)->at(i)->getName() == "void" || (yyvsp[-2].vectorsymbol)->at(i)->getName() == "return")
				logout << " ";
			if((yyvsp[-2].vectorsymbol)->at(i)->getName() == ";" || (yyvsp[-2].vectorsymbol)->at(i)->getName() == "{" || (yyvsp[-2].vectorsymbol)->at(i)->getName() == "}")
				logout << "\n";
		}
		logout << (yyvsp[-1].symbol)->getName();
		(yyval.vectorsymbol)->push_back((yyvsp[-1].symbol));
		for(int i = 0; i < (yyvsp[0].vectorsymbol)->size(); i++){
			logout << (yyvsp[0].vectorsymbol)->at(i)->getName();
			(yyval.vectorsymbol)->push_back((yyvsp[0].vectorsymbol)->at(i));
			if((yyvsp[0].vectorsymbol)->at(i)->getName() == "int" || (yyvsp[0].vectorsymbol)->at(i)->getName() == "float" || (yyvsp[0].vectorsymbol)->at(i)->getName() == "void" || (yyvsp[0].vectorsymbol)->at(i)->getName() == "return")
				logout << " ";
			if((yyvsp[0].vectorsymbol)->at(i)->getName() == ";" || (yyvsp[0].vectorsymbol)->at(i)->getName() == "{" || (yyvsp[0].vectorsymbol)->at(i)->getName() == "}")
				logout << "\n";
		}
		logout << "\n\n";

		//assembly code
		string label1 = newLabel();
		string label2 = newLabel();
		string segment_code = "";

		segment_code += "\tmov ax, " + (yyvsp[-4].vectorsymbol)->at(0)->getSymbol() + "\n";
		segment_code += "\tcmp ax, 0\n";
		segment_code += "\tje " + label1 + "\n";
		segment_code += (yyvsp[-2].vectorsymbol)->at(0)->getCode();
		segment_code += "\tjmp " + label2 + "\n";
		segment_code += label1 + ":\n";
		segment_code += (yyvsp[0].vectorsymbol)->at(0)->getCode();
		segment_code += label2 + ":\n";

		(yyval.vectorsymbol)->at(0)->setCode((yyval.vectorsymbol)->at(0)->getCode() + segment_code);

	  }
#line 2470 "y.tab.c"
    break;

  case 40: /* statement: WHILE LPAREN expression RPAREN statement  */
#line 1024 "170000.y"
          {
	  	(yyval.vectorsymbol) = new vector<SymbolInfo*>();
	  	logout << "line no " << line_count <<  ": statement : WHILE LPAREN expression RPAREN statement\n\n";
	  	logout << (yyvsp[-4].symbol)->getName() << (yyvsp[-3].symbol)->getName();
	  	for(int i = 0; i < (yyvsp[-2].vectorsymbol)->size(); i++){
			logout << (yyvsp[-2].vectorsymbol)->at(i)->getName();
			(yyval.vectorsymbol)->push_back((yyvsp[-2].vectorsymbol)->at(i));
		}
		logout << (yyvsp[-1].symbol)->getName();
		(yyval.vectorsymbol)->push_back((yyvsp[-1].symbol));
		for(int i = 0; i < (yyvsp[0].vectorsymbol)->size(); i++){
			logout << (yyvsp[0].vectorsymbol)->at(i)->getName();
			(yyval.vectorsymbol)->push_back((yyvsp[0].vectorsymbol)->at(i));
			if((yyvsp[0].vectorsymbol)->at(i)->getName() == "int" || (yyvsp[0].vectorsymbol)->at(i)->getName() == "float" || (yyvsp[0].vectorsymbol)->at(i)->getName() == "void" || (yyvsp[0].vectorsymbol)->at(i)->getName() == "return")
				logout << " ";
			if((yyvsp[0].vectorsymbol)->at(i)->getName() == ";" || (yyvsp[0].vectorsymbol)->at(i)->getName() == "{" || (yyvsp[0].vectorsymbol)->at(i)->getName() == "}")
				logout << "\n";
		}
		logout << "\n\n";

		//assembly code
		string label1 = newLabel();
		string label2 = newLabel();
		
		string segment_code = "";
		segment_code += label1 + ":\n";
		segment_code += (yyvsp[-2].vectorsymbol)->at(0)->getCode();
		segment_code += "\tmov ax, " + (yyvsp[-2].vectorsymbol)->at(0)->getSymbol() + "\n";
		segment_code += "\tcmp ax, 0\n";
		segment_code += "\tje " + label2 + "\n";
		segment_code += (yyvsp[0].vectorsymbol)->at(0)->getCode();
		segment_code += "\tjmp " + label1 + "\n";
		segment_code += label2 + ":\n";

		(yyval.vectorsymbol)->at(0)->setCode(segment_code);

	  }
#line 2512 "y.tab.c"
    break;

  case 41: /* statement: PRINTLN LPAREN ID RPAREN SEMICOLON  */
#line 1062 "170000.y"
          {
	  	(yyval.vectorsymbol) = new vector<SymbolInfo*>();
	  	logout << "line no " << line_count <<  ": statement : PRINTLN LPAREN ID RPAREN SEMICOLON\n\n";
		if(symboltable.LookUp(logout, (yyvsp[-2].symbol)->getName()) == nullptr){  // Undeclared error
			logout << "Error at line " << line_count << ": Undeclared variable " << (yyvsp[-2].symbol)->getName() << "\n\n";
			errorout << "Error at line " << line_count << ": Undeclared variable " << (yyvsp[-2].symbol)->getName() << "\n\n";
			error_count++;
		}
	  	logout << (yyvsp[-4].symbol)->getName() << (yyvsp[-3].symbol)->getName() << (yyvsp[-2].symbol)->getName() << (yyvsp[-1].symbol)->getName() << (yyvsp[0].symbol)->getName() << "\n\n";
	  	(yyval.vectorsymbol)->push_back((yyvsp[-4].symbol));
	  	(yyval.vectorsymbol)->push_back((yyvsp[-3].symbol));
	  	(yyval.vectorsymbol)->push_back((yyvsp[-2].symbol));
	  	(yyval.vectorsymbol)->push_back((yyvsp[-1].symbol));
	  	(yyval.vectorsymbol)->push_back((yyvsp[0].symbol));

		//assembly code
		string segment_code = "";
		segment_code += "\tmov ax, " + (symboltable.LookUp(logout, (yyvsp[-2].symbol)->getName()))->getSymbol() + "\n";
		
		segment_code += "\tmov print_var, ax\n";
		segment_code +=	"\tcall print\n";

		(yyval.vectorsymbol)->at(0)->setCode((yyval.vectorsymbol)->at(0)->getCode() + segment_code);
	  }
#line 2541 "y.tab.c"
    break;

  case 42: /* statement: RETURN expression SEMICOLON  */
#line 1087 "170000.y"
          {
	  	(yyval.vectorsymbol) = new vector<SymbolInfo*>();
	  	logout << "line no " << line_count <<  ": statement : RETURN expression SEMICOLON\n\n";
	  	logout << (yyvsp[-2].symbol)->getName() << " ";
	  	(yyval.vectorsymbol)->push_back((yyvsp[-2].symbol));
	  	for(int i = 0; i < (yyvsp[-1].vectorsymbol)->size(); i++){
			logout << (yyvsp[-1].vectorsymbol)->at(i)->getName();
			(yyval.vectorsymbol)->push_back((yyvsp[-1].vectorsymbol)->at(i));
		}
		logout << (yyvsp[0].symbol)->getName() << "\n\n";
		(yyval.vectorsymbol)->push_back((yyvsp[0].symbol));

		//assembly code
		string segment_code = "";
		segment_code += (yyvsp[-1].vectorsymbol)->at(0)->getCode();
		segment_code += "\tmov ax, " + (yyvsp[-1].vectorsymbol)->at(0)->getSymbol() + "\n";
		segment_code += "\tmov ret_temp, ax\n";

		(yyval.vectorsymbol)->at(0)->setCode((yyval.vectorsymbol)->at(0)->getCode() + segment_code);

	  }
#line 2567 "y.tab.c"
    break;

  case 43: /* expression_statement: SEMICOLON  */
#line 1111 "170000.y"
                        {
				logout << "line no: " << line_count <<  " expression_statement 	: SEMICOLON\n\n";
				logout << (yyvsp[0].symbol)->getName() << "\n\n";
				(yyval.vectorsymbol) = new vector<SymbolInfo*>();
				(yyval.vectorsymbol)->push_back((yyvsp[0].symbol));
			}
#line 2578 "y.tab.c"
    break;

  case 44: /* expression_statement: expression SEMICOLON  */
#line 1118 "170000.y"
                        {
				(yyval.vectorsymbol) = new vector<SymbolInfo*>();
				logout << "line no: " << line_count <<  " expression_statement : expression SEMICOLON \n\n";
				for(int i = 0; i < (yyvsp[-1].vectorsymbol)->size(); i++){
					logout << (yyvsp[-1].vectorsymbol)->at(i)->getName();
					(yyval.vectorsymbol)->push_back((yyvsp[-1].vectorsymbol)->at(i));
				}
				logout << (yyvsp[0].symbol)->getName() << "\n\n";
				(yyval.vectorsymbol)->push_back((yyvsp[0].symbol));

				//assembly code
				(yyval.vectorsymbol)->at(0)->setCode((yyvsp[-1].vectorsymbol)->at(0)->getCode());
			}
#line 2596 "y.tab.c"
    break;

  case 45: /* variable: ID  */
#line 1134 "170000.y"
        {
		(yyval.vectorsymbol) = new vector<SymbolInfo*>();
		logout << "line no: " << line_count <<  " variable : ID\n\n";

		// semantic error-------//
		if(symboltable.LookUp(logout, (yyvsp[0].symbol)->getName()) == nullptr){  // Undeclared error
			logout << "Error at line " << line_count << ": Undeclared variable " << (yyvsp[0].symbol)->getName() << "\n\n";
			errorout << "Error at line " << line_count << ": Undeclared variable " << (yyvsp[0].symbol)->getName() << "\n\n";
			error_count++;
		}
		else{    // type mismatch error
			SymbolInfo *temp = symboltable.LookUp(logout, (yyvsp[0].symbol)->getName());
			if(temp->getWhichVariable() == "array"){
				logout << "Error at line " << line_count << ": Type mismatch, " << (yyvsp[0].symbol)->getName() << " is an array\n\n";
				errorout << "Error at line " << line_count << ": Type mismatch, " << (yyvsp[0].symbol)->getName() << " is an array\n\n";
				error_count++;
			}
			else if(temp->getWhichVariable() == "func"){
				logout << "Error at line " << line_count << ": Type mismatch, " << (yyvsp[0].symbol)->getName() << " is a function\n\n";
				errorout << "Error at line " << line_count << ": Type mismatch, " << (yyvsp[0].symbol)->getName() << " is a function\n\n";
				error_count++;
			}
		}
		//-----------//
		logout << (yyvsp[0].symbol)->getName() << "\n\n";
		(yyval.vectorsymbol)->push_back((yyvsp[0].symbol));

		//assembly code
		(yyval.vectorsymbol)->at(0)->setSymbol((symboltable.LookUp(logout, (yyvsp[0].symbol)->getName()))->getSymbol());
		
		(yyval.vectorsymbol)->at(0)->setCode("");
		
	}
#line 2634 "y.tab.c"
    break;

  case 46: /* variable: ID LTHIRD expression RTHIRD  */
#line 1168 "170000.y"
         { 
	 	(yyval.vectorsymbol) = new vector<SymbolInfo*>();
	 	logout << "line no: " << line_count <<  " variable : ID LTHIRD expression RTHIRD\n\n";
		// semantic error-------//
		if(symboltable.LookUp(logout, (yyvsp[-3].symbol)->getName()) == nullptr){    // Undeclared error
			logout << "Error at line " << line_count << ": Undeclared variable " << (yyvsp[-3].symbol)->getName() << "\n\n";
			errorout << "Error at line " << line_count << ": Undeclared variable " << (yyvsp[-3].symbol)->getName() << "\n\n";
			error_count++;
		}
		else{               // not an array
			SymbolInfo* temp = symboltable.LookUp(logout, (yyvsp[-3].symbol)->getName());
			if(temp->getWhichVariable() != "array"){      
				logout << "Error at line " << line_count << ": " << (yyvsp[-3].symbol)->getName() << " not an array\n\n";
				errorout << "Error at line " << line_count << ": " << (yyvsp[-3].symbol)->getName() << " not an array\n\n";
				error_count++;
				(yyval.vectorsymbol)->at(0)->setSymbol("");
			}
		}
		if((yyvsp[-1].vectorsymbol)->at(0)->getType() != "CONST_INT"){  // array index not integer
			logout << "Error at line " << line_count << ": Expression inside third brackets not an integer\n\n";
			errorout << "Error at line " << line_count << ": Expression inside third brackets not an integer\n\n";
			error_count++;
		}
		
		//-----------//
	 	logout << (yyvsp[-3].symbol)->getName() << (yyvsp[-2].symbol)->getName() << (yyvsp[-1].vectorsymbol)->at(0)->getName() << (yyvsp[0].symbol)->getName() << "\n\n";
	 	(yyval.vectorsymbol)->push_back((yyvsp[-3].symbol));
	 	(yyval.vectorsymbol)->push_back((yyvsp[-2].symbol));
		(yyval.vectorsymbol)->push_back((yyvsp[-1].vectorsymbol)->at(0));
		(yyval.vectorsymbol)->push_back((yyvsp[0].symbol));

		//assembly code
		(yyval.vectorsymbol)->at(0)->setSymbol((symboltable.LookUp(logout, (yyvsp[-3].symbol)->getName()))->getSymbol());

		string segment_code = "";
		segment_code += "\tmov di, " + (yyvsp[-1].vectorsymbol)->at(0)->getSymbol() + "\n";
		segment_code += "\tadd di, di\n";
		(yyval.vectorsymbol)->at(0)->setCode(segment_code);
	 }
#line 2678 "y.tab.c"
    break;

  case 47: /* expression: logic_expression  */
#line 1211 "170000.y"
          {
 	  	(yyval.vectorsymbol) = new vector<SymbolInfo*>();
			logout << "line no: " << line_count <<  " expression : logic_expression\n\n";

			for(int i = 0; i < (yyvsp[0].vectorsymbol)->size(); i++){
				logout << (yyvsp[0].vectorsymbol)->at(i)->getName();
				(yyval.vectorsymbol)->push_back((yyvsp[0].vectorsymbol)->at(i));
			}
			logout << "\n\n";
 	  }
#line 2693 "y.tab.c"
    break;

  case 48: /* expression: variable ASSIGNOP logic_expression  */
#line 1222 "170000.y"
           {
	   	(yyval.vectorsymbol) = new vector<SymbolInfo*>();
			logout << "line no: " << line_count <<  " expression : variable ASSIGNOP logic_expression\n\n";
			
			//semantic error----------//
			for(int i = 0; i < (yyvsp[0].vectorsymbol)->size(); i++){     //  void function in expression
				if((yyvsp[0].vectorsymbol)->at(i)->getType() == "ID" && symboltable.LookUp(logout, (yyvsp[0].vectorsymbol)->at(i)->getName()) != nullptr){
					SymbolInfo* temp = symboltable.LookUp(logout, (yyvsp[0].vectorsymbol)->at(i)->getName());
					if(temp->getWhichVariable() == "func" && temp->getVariableType() == "VOID"){
						logout << "Error at line " << line_count << ": Void function used in expression\n\n";
						errorout << "Error at line " << line_count << ": Void function used in expression\n\n";
						error_count++;
					}
				}
			}
			      
			if(symboltable.LookUp(logout, (yyvsp[-2].vectorsymbol)->at(0)->getName()) != nullptr){     // float assignment in integer error
				SymbolInfo *temp = symboltable.LookUp(logout, (yyvsp[-2].vectorsymbol)->at(0)->getName());
				if(temp->getVariableType() == "INT"){
					
					for(int i = 0; i < (yyvsp[0].vectorsymbol)->size(); i++){
						if((yyvsp[0].vectorsymbol)->at(i)->getType() == "CONST_FLOAT"){
							logout << "Error at line " << line_count << ": Type Mismatch\n\n";
							errorout << "Error at line " << line_count << ": Type Mismatch\n\n";
							error_count++;
							break;
						}
						
					}
				}
			}
			//------------//

			for(int i = 0; i < (yyvsp[-2].vectorsymbol)->size(); i++){
				logout << (yyvsp[-2].vectorsymbol)->at(i)->getName();
				(yyval.vectorsymbol)->push_back((yyvsp[-2].vectorsymbol)->at(i));
			}
			logout << (yyvsp[-1].symbol)->getName();
			(yyval.vectorsymbol)->push_back((yyvsp[-1].symbol));
			for(int i = 0; i < (yyvsp[0].vectorsymbol)->size(); i++){
				logout << (yyvsp[0].vectorsymbol)->at(i)->getName();
				(yyval.vectorsymbol)->push_back((yyvsp[0].vectorsymbol)->at(i));
			}
			logout << "\n\n";

			//assembly code
			string whichvariable = (symboltable.LookUp(logout, (yyvsp[-2].vectorsymbol)->at(0)->getName()))->getWhichVariable();
			string segment_code = "";
			string temp;
			
			if((yyvsp[0].vectorsymbol)->size() == 4){
				temp = newTemp();
				segment_code += (yyvsp[0].vectorsymbol)->at(0)->getCode();
				segment_code += "\tmov ax, " + (yyvsp[0].vectorsymbol)->at(0)->getSymbol() + "[di]\n";
				segment_code += "\tmov " + temp + ", ax\n";
				segment_code += (yyvsp[-2].vectorsymbol)->at(0)->getCode();
				if(whichvariable != "array")
					segment_code += "\tmov " + (yyvsp[-2].vectorsymbol)->at(0)->getSymbol() + ", ax\n";
				else{
					segment_code += "\tmov ax, " + temp + "\n"; 
					segment_code += "\tmov " + (yyvsp[-2].vectorsymbol)->at(0)->getSymbol() + "[di], ax\n";
				}
			}

			else{
				segment_code += (yyvsp[0].vectorsymbol)->at(0)->getCode();
				segment_code += (yyvsp[-2].vectorsymbol)->at(0)->getCode();
				segment_code += "\tmov ax, " + (yyvsp[0].vectorsymbol)->at(0)->getSymbol() + "\n";
				//find set symbol-------
				if(whichvariable != "array")
					segment_code += "\tmov " + (yyvsp[-2].vectorsymbol)->at(0)->getSymbol() + ", ax\n";
				else
					segment_code += "\tmov " + (yyvsp[-2].vectorsymbol)->at(0)->getSymbol() + "[di], ax\n";
				
			}
			(yyval.vectorsymbol)->at(0)->setCode(segment_code);
	   }
#line 2775 "y.tab.c"
    break;

  case 49: /* logic_expression: rel_expression  */
#line 1302 "170000.y"
                {
			(yyval.vectorsymbol) = new vector<SymbolInfo*>();
			logout << "line no: " << line_count <<  " logic_expression : rel_expression\n\n";
			for(int i = 0; i < (yyvsp[0].vectorsymbol)->size(); i++){
				logout << (yyvsp[0].vectorsymbol)->at(i)->getName();
				(yyval.vectorsymbol)->push_back((yyvsp[0].vectorsymbol)->at(i));
			}
			logout << "\n\n";
		}
#line 2789 "y.tab.c"
    break;

  case 50: /* logic_expression: rel_expression LOGICOP rel_expression  */
#line 1312 "170000.y"
                 {
		 	(yyval.vectorsymbol) = new vector<SymbolInfo*>();
			logout << "line no: " << line_count <<  " logic_expression : rel_expression LOGICOP rel_expression\n\n";
			for(int i = 0; i < (yyvsp[-2].vectorsymbol)->size(); i++){
				logout << (yyvsp[-2].vectorsymbol)->at(i)->getName();
				(yyval.vectorsymbol)->push_back((yyvsp[-2].vectorsymbol)->at(i));
			}
			logout << (yyvsp[-1].symbol)->getName();
			(yyval.vectorsymbol)->push_back((yyvsp[-1].symbol));
			for(int i = 0; i < (yyvsp[0].vectorsymbol)->size(); i++){
				logout << (yyvsp[0].vectorsymbol)->at(i)->getName();
				(yyval.vectorsymbol)->push_back((yyvsp[0].vectorsymbol)->at(i));
			}
			logout << "\n\n";

			//assembly code
			string label1 = newLabel();
			string label2 = newLabel();
			string temp = newTemp();

			string segment_code = "";
			if((yyvsp[-1].symbol)->getName() == "&&"){
				segment_code += "\tcmp " + (yyvsp[-2].vectorsymbol)->at(0)->getSymbol() + ", 0\n";
				segment_code += "\tje " + label1 + "\n";
				segment_code += "\tcmp " +  (yyvsp[0].vectorsymbol)->at(0)->getSymbol() + ", 0\n";
				segment_code += "\tje " + label1 + "\n";
				segment_code += "\tmov " + temp + ", 1\n";
				segment_code += "\tjmp " + label2 + "\n";
				segment_code += label1 + ":\n";
				segment_code += "\tmov " + temp + ", 0\n";
				segment_code += label2 + ":\n";
			}
			else if((yyvsp[-1].symbol)->getName() == "||"){
				segment_code += "\tcmp " + (yyvsp[-2].vectorsymbol)->at(0)->getSymbol() + ", 0\n";
				segment_code += "\tjne " + label1 + "\n";
				segment_code += "\tcmp " +  (yyvsp[0].vectorsymbol)->at(0)->getSymbol() + ", 0\n";
				segment_code += "\tjne " + label1 + "\n";
				segment_code += "\tmov " + temp + ", 0\n";
				segment_code += "\tjmp " + label2 + "\n";
				segment_code += label1 + ":\n";
				segment_code += "\tmov " + temp + ", 1\n";
				segment_code += label2 + ":\n";
			}
			(yyval.vectorsymbol)->at(0)->setCode((yyval.vectorsymbol)->at(0)->getCode() + segment_code);
			(yyval.vectorsymbol)->at(0)->setSymbol(temp);
		 }
#line 2840 "y.tab.c"
    break;

  case 51: /* rel_expression: simple_expression  */
#line 1361 "170000.y"
                {
			(yyval.vectorsymbol) = new vector<SymbolInfo*>();
			logout << "line no: " << line_count <<  " rel_expression : simple_expression\n\n";
			for(int i = 0; i < (yyvsp[0].vectorsymbol)->size(); i++){
				logout << (yyvsp[0].vectorsymbol)->at(i)->getName();
				(yyval.vectorsymbol)->push_back((yyvsp[0].vectorsymbol)->at(i));
			}
			logout << "\n\n";
		}
#line 2854 "y.tab.c"
    break;

  case 52: /* rel_expression: simple_expression RELOP simple_expression  */
#line 1371 "170000.y"
                {
			(yyval.vectorsymbol) = new vector<SymbolInfo*>();
			logout << "line no: " << line_count <<  " rel_expression : simple_expression RELOP simple_expression\n\n";
			for(int i = 0; i < (yyvsp[-2].vectorsymbol)->size(); i++){
				logout << (yyvsp[-2].vectorsymbol)->at(i)->getName();
				(yyval.vectorsymbol)->push_back((yyvsp[-2].vectorsymbol)->at(i));
			}
			logout << (yyvsp[-1].symbol)->getName();
			(yyval.vectorsymbol)->push_back((yyvsp[-1].symbol));
			for(int i = 0; i < (yyvsp[0].vectorsymbol)->size(); i++){
				logout << (yyvsp[0].vectorsymbol)->at(i)->getName();
				(yyval.vectorsymbol)->push_back((yyvsp[0].vectorsymbol)->at(i));
			}
			logout << "\n\n";

			//assembly code
			string label1 = newLabel();
			string label2 = newLabel();
			string temp = newTemp();
			string segment_code = "";

			segment_code += (yyvsp[0].vectorsymbol)->at(0)->getCode();
			segment_code += "\tmov ax, " + (yyvsp[-2].vectorsymbol)->at(0)->getSymbol() + "\n";
			segment_code += "\tcmp ax, " + (yyvsp[0].vectorsymbol)->at(0)->getSymbol() + "\n";

			if((yyvsp[-1].symbol)->getName() == ">")
				segment_code += "\tjg " + label1 + "\n";
			else if((yyvsp[-1].symbol)->getName() == ">=")
				segment_code += "\tjge " + label1 + "\n";
			else if((yyvsp[-1].symbol)->getName() == "<")
				segment_code += "\tjl " + label1 + "\n";
			else if((yyvsp[-1].symbol)->getName() == "<=")
				segment_code += "\tjle " + label1 + "\n";
			else if((yyvsp[-1].symbol)->getName() == "==")
				segment_code += "\tje " + label1 + "\n";
			else if((yyvsp[-1].symbol)->getName() == "!=")
				segment_code += "\tjne " + label1 + "\n";

			segment_code += "\tmov " + temp + ", 0\n";
			segment_code += "\tjmp " + label2 + "\n";
			segment_code += label1 + ":\n";
			segment_code += "\tmov " + temp + ", 1\n";
			segment_code += label2 + ":\n";

			(yyval.vectorsymbol)->at(0)->setCode((yyval.vectorsymbol)->at(0)->getCode() + segment_code);
			(yyval.vectorsymbol)->at(0)->setSymbol(temp);
		}
#line 2906 "y.tab.c"
    break;

  case 53: /* simple_expression: term  */
#line 1420 "170000.y"
                {	
			(yyval.vectorsymbol) = new vector<SymbolInfo*>();
			logout << "line no: " << line_count <<  " simple_expression : term\n\n";
			for(int i = 0; i < (yyvsp[0].vectorsymbol)->size(); i++){
				logout << (yyvsp[0].vectorsymbol)->at(i)->getName();
				(yyval.vectorsymbol)->push_back((yyvsp[0].vectorsymbol)->at(i));
			}
			logout << "\n\n";
		}
#line 2920 "y.tab.c"
    break;

  case 54: /* simple_expression: simple_expression ADDOP term  */
#line 1430 "170000.y"
                  {
		  	(yyval.vectorsymbol) = new vector<SymbolInfo*>();
			logout << "line no: " << line_count <<  " simple_expression : simple_expression ADDOP term\n\n";
			for(int i = 0; i < (yyvsp[-2].vectorsymbol)->size(); i++){
				logout << (yyvsp[-2].vectorsymbol)->at(i)->getName();
				(yyval.vectorsymbol)->push_back((yyvsp[-2].vectorsymbol)->at(i));
			}
			logout << (yyvsp[-1].symbol)->getName();
			(yyval.vectorsymbol)->push_back((yyvsp[-1].symbol));
			for(int i = 0; i < (yyvsp[0].vectorsymbol)->size(); i++){
				logout << (yyvsp[0].vectorsymbol)->at(i)->getName();
				(yyval.vectorsymbol)->push_back((yyvsp[0].vectorsymbol)->at(i));
			}
			logout << "\n\n";

			//assembly code

			string temp = newTemp();

			string segment_code = "";
			segment_code += (yyvsp[0].vectorsymbol)->at(0)->getCode();
			segment_code += "\tmov ax, " + (yyvsp[-2].vectorsymbol)->at(0)->getSymbol() + "\n";
			if((yyvsp[-1].symbol)->getName() == "+")
				segment_code += "\tadd ax, " + (yyvsp[0].vectorsymbol)->at(0)->getSymbol() + "\n";
			else
				segment_code += "\tsub ax, " + (yyvsp[0].vectorsymbol)->at(0)->getSymbol() + "\n";
			segment_code += "\tmov " + temp + ", ax\n";
			(yyval.vectorsymbol)->at(0)->setCode((yyval.vectorsymbol)->at(0)->getCode() + segment_code);
			(yyval.vectorsymbol)->at(0)->setSymbol(temp);
		  }
#line 2955 "y.tab.c"
    break;

  case 55: /* term: unary_expression  */
#line 1463 "170000.y"
        {
		(yyval.vectorsymbol) = new vector<SymbolInfo*>();
		logout << "line no: " << line_count <<  " term :	unary_expression\n\n";
		for(int i = 0; i < (yyvsp[0].vectorsymbol)->size(); i++){
	 		logout << (yyvsp[0].vectorsymbol)->at(i)->getName();
	 		(yyval.vectorsymbol)->push_back((yyvsp[0].vectorsymbol)->at(i));
	 	}
	 	logout << "\n\n";
	}
#line 2969 "y.tab.c"
    break;

  case 56: /* term: term MULOP unary_expression  */
#line 1473 "170000.y"
        {
     		(yyval.vectorsymbol) = new vector<SymbolInfo*>();
     		logout << "line no: " << line_count <<  " term :  term MULOP unary_expression\n\n";

			// semantic error-----------//
			if((yyvsp[-1].symbol)->getName() == "%"){    // mod operand not integer
				if((yyvsp[-2].vectorsymbol)->size() == 1 && (yyvsp[0].vectorsymbol)->size() == 1){
					if((yyvsp[0].vectorsymbol)->at(0)->getType() != "CONST_INT"){
						logout << "Error at line " << line_count << ": Non-Integer operand on modulus operator\n\n";
						errorout << "Error at line " << line_count << ": Non-Integer operand on modulus operator\n\n";
						error_count++;
					}
					else if((yyvsp[0].vectorsymbol)->at(0)->getName() == "0"){
						logout << "Error at line " << line_count << ": Modulus by Zero\n\n";
						errorout << "Error at line " << line_count << ": Modulus by Zero\n\n";
						error_count++;
					}
				}
			}
				
			for(int i = 0; i < (yyvsp[-2].vectorsymbol)->size(); i++){
				logout << (yyvsp[-2].vectorsymbol)->at(i)->getName();
				(yyval.vectorsymbol)->push_back((yyvsp[-2].vectorsymbol)->at(i));
			}
			logout << (yyvsp[-1].symbol)->getName();
			(yyval.vectorsymbol)->push_back((yyvsp[-1].symbol));
			for(int i = 0; i < (yyvsp[0].vectorsymbol)->size(); i++){
				logout << (yyvsp[0].vectorsymbol)->at(i)->getName();
				(yyval.vectorsymbol)->push_back((yyvsp[0].vectorsymbol)->at(i));
			}
			logout << "\n\n";

			//assembly code

			string temp = newTemp();

			string segment_code = "";
			segment_code += (yyvsp[0].vectorsymbol)->at(0)->getCode();
			segment_code += "\tmov ax, " + (yyvsp[-2].vectorsymbol)->at(0)->getSymbol() + "\n";
			segment_code += "\tmov bx, " + (yyvsp[0].vectorsymbol)->at(0)->getSymbol() + "\n";

			if((yyvsp[-1].symbol)->getName() == "*"){
				segment_code += "\tmul bx\n";
				segment_code += "\tmov " + temp + ", ax\n";
			}
				
			else if((yyvsp[-1].symbol)->getName() == "/"){
				segment_code += "\txor dx, dx\n";
				segment_code += "\tdiv bx\n";
				segment_code += "\tmov " + temp + ", ax\n";
			}
			else{   //operator % 
				segment_code += "\txor dx, dx\n";
				segment_code += "\tdiv bx\n";
				segment_code += "\tmov " + temp + ", dx\n";
			}
			
			(yyval.vectorsymbol)->at(0)->setCode((yyval.vectorsymbol)->at(0)->getCode() + segment_code);
			(yyval.vectorsymbol)->at(0)->setSymbol(temp);

        }
#line 3035 "y.tab.c"
    break;

  case 57: /* unary_expression: ADDOP unary_expression  */
#line 1537 "170000.y"
                 {
		 	(yyval.vectorsymbol) = new vector<SymbolInfo*>();
		 	logout << "line no: " << line_count <<  " unary_expression : ADDOP unary_expression \n\n";
		 	logout << (yyvsp[-1].symbol)->getName();
		 	(yyval.vectorsymbol)->push_back((yyvsp[-1].symbol));
		 	for(int i = 0; i < (yyvsp[0].vectorsymbol)->size(); i++){
		 		logout << (yyvsp[0].vectorsymbol)->at(i)->getName();
		 		(yyval.vectorsymbol)->push_back((yyvsp[0].vectorsymbol)->at(i));
		 	}
		 	logout << "\n\n";
			string segment_code="";
			if((yyvsp[-1].symbol)->getName()=="-"){
				segment_code="\tneg "+(yyvsp[0].vectorsymbol)->at(0)->getSymbol()+"\n";
				

			}
			
			(yyval.vectorsymbol)->at(0)->setCode(segment_code);
			(yyval.vectorsymbol)->at(0)->setSymbol((yyvsp[0].vectorsymbol)->at(0)->getSymbol());
		 }
#line 3060 "y.tab.c"
    break;

  case 58: /* unary_expression: NOT unary_expression  */
#line 1558 "170000.y"
                 {
		 	(yyval.vectorsymbol) = new vector<SymbolInfo*>();
		 	logout << "line no: " << line_count <<  " unary_expression : NOT unary_expression \n\n";
		 	logout << (yyvsp[-1].symbol)->getName();
		 	(yyval.vectorsymbol)->push_back((yyvsp[-1].symbol));
		 	for(int i = 0; i < (yyvsp[0].vectorsymbol)->size(); i++){
		 		logout << (yyvsp[0].vectorsymbol)->at(i)->getName();
		 		(yyval.vectorsymbol)->push_back((yyvsp[0].vectorsymbol)->at(i));
		 	}
		 	logout << "\n\n";
		 	
		 }
#line 3077 "y.tab.c"
    break;

  case 59: /* unary_expression: factor  */
#line 1571 "170000.y"
                 {
  		 	(yyval.vectorsymbol) = new vector<SymbolInfo*>();
  		 	logout << "line no: " << line_count <<  " unary_expression : factor \n\n";
  		 	for (int i = 0; i < (yyvsp[0].vectorsymbol)->size(); i++){
  		 		logout << (yyvsp[0].vectorsymbol)->at(i)->getName();
  		 		(yyval.vectorsymbol)->push_back((yyvsp[0].vectorsymbol)->at(i));
  		 	}
		 	logout << "\n\n";
  		 }
#line 3091 "y.tab.c"
    break;

  case 60: /* factor: variable  */
#line 1583 "170000.y"
        {
		(yyval.vectorsymbol) = new vector<SymbolInfo*>();
		logout << "line no: " << line_count <<  " factor  : variable \n\n";
		for (int i = 0; i < (yyvsp[0].vectorsymbol)->size(); i++){
	 		logout << (yyvsp[0].vectorsymbol)->at(i)->getName();
	 		(yyval.vectorsymbol)->push_back((yyvsp[0].vectorsymbol)->at(i));
  		 }
  		 logout << "\n\n";
		
	}
#line 3106 "y.tab.c"
    break;

  case 61: /* factor: ID LPAREN argument_list RPAREN  */
#line 1594 "170000.y"
        {
		(yyval.vectorsymbol) = new vector<SymbolInfo*>();
		logout << "line no: " << line_count <<  " factor  : ID LPAREN argument_list RPAREN\n\n";

		//assembly code
		string temp_var = newTemp();
		string segment_code = "";  
		vector<string> pushed_var;     

		//semantic error--------//
		if(symboltable.LookUp(logout,(yyvsp[-3].symbol)->getName()) == nullptr){
			logout << "Error at line " << line_count << ": Undeclared function " << (yyvsp[-3].symbol)->getName() << "\n\n";
			errorout << "Error at line " << line_count << ": Undeclared function " << (yyvsp[-3].symbol)->getName() << "\n\n";
			error_count++;
		}

		
		else{          // function argument check with declaration
			SymbolInfo* temp = symboltable.LookUp(logout, (yyvsp[-3].symbol)->getName());
			if(temp->getWhichVariable() != "func"){
				logout << "Error at line " << line_count << ": " << (yyvsp[-3].symbol)->getName() << " not a function" << "\n\n";
				errorout << "Error at line " << line_count << ": " << (yyvsp[-3].symbol)->getName() << " not a function"<< "\n\n";
				error_count++;
			}
			vector<string> parameter_type;
			int param_count = 0;
			for(int i = 0; i < (yyvsp[-1].vectorsymbol)->size(); i++){
				if((yyvsp[-1].vectorsymbol)->at(i)->getType() == "ID"){
					if(i != (yyvsp[-1].vectorsymbol)->size()-1){
						if((yyvsp[-1].vectorsymbol)->at(i+1)->getName() != "["){      // variable
							SymbolInfo* temp1 = symboltable.LookUp(logout, (yyvsp[-1].vectorsymbol)->at(i)->getName());
							if(temp1 != nullptr)
								parameter_type.push_back(temp1->getVariableType());
						}
						else if((yyvsp[-1].vectorsymbol)->at(i+2)->getType() == "CONST_INT" && (yyvsp[-1].vectorsymbol)->at(i+3)->getName() == "]"){   //array
							SymbolInfo* temp1 = symboltable.LookUp(logout, (yyvsp[-1].vectorsymbol)->at(i)->getName());
							if(temp1 != nullptr)
								parameter_type.push_back(temp1->getVariableType());
						}
					}
					else{       // variable
						SymbolInfo* temp1 = symboltable.LookUp(logout, (yyvsp[-1].vectorsymbol)->at(i)->getName());
						if(temp1 != nullptr)
							parameter_type.push_back(temp1->getVariableType());
					}
					//assembly code
					pushed_var.push_back((symboltable.LookUp(logout, (yyvsp[-1].vectorsymbol)->at(i)->getName()))->getSymbol());
					segment_code += "\tpush " + (symboltable.LookUp(logout, (yyvsp[-1].vectorsymbol)->at(i)->getName()))->getSymbol() + "\n";
					
				}
				
				else if((yyvsp[-1].vectorsymbol)->at(i)->getType() == "CONST_INT"){
					if(i != 0){
						if((yyvsp[-1].vectorsymbol)->at(i-1)->getName() != "["){
							if((yyvsp[-1].vectorsymbol)->at(i-1)->getName() == ",")
								parameter_type.push_back("INT");
						}
					}
					else{
						parameter_type.push_back("INT");
					}
				}
				else if((yyvsp[-1].vectorsymbol)->at(i)->getType() == "CONST_FLOAT"){
					if(i != 0){
						if((yyvsp[-1].vectorsymbol)->at(i-1)->getName() != "["){
							if((yyvsp[-1].vectorsymbol)->at(i-1)->getName() == ",")
								parameter_type.push_back("FLOAT");
						}
					}
					else{
						parameter_type.push_back("FLOAT");
					}
				}

			}

			if(parameter_type.size() != temp->getParamSize()){
				logout << "Error at line " << line_count << ": Total number of arguments mismatch in function " << (yyvsp[-3].symbol)->getName() << "\n\n";
				errorout << "Error at line " << line_count << ": Total number of arguments mismatch in function " << (yyvsp[-3].symbol)->getName() << "\n\n";
				error_count++;
			} 
			else{
				for(int i = 0; i < temp->getParamSize(); i++){
					if(parameter_type.at(i) != temp->getParamType(i)){
						logout << "Error at line " << line_count << ": " << i+1 << "th argument mismatch in function " << (yyvsp[-3].symbol)->getName() <<"\n\n";
						errorout << "Error at line " << line_count << ": " << i+1 << "th argument mismatch in function " << (yyvsp[-3].symbol)->getName() <<"\n\n";
						error_count++;
						break;
					}
				}
			}

			//assembly code
			for(int i = 0; i < (yyvsp[-1].vectorsymbol)->size(); i++){
				if((yyvsp[-1].vectorsymbol)->at(i)->getType() == "ID"){
					segment_code += "\tmov ax, " + (symboltable.LookUp(logout, (yyvsp[-1].vectorsymbol)->at(i)->getName()))->getSymbol() + "\n";
					segment_code += "\tmov " + temp->getParamName(param_count) + ", ax\n";
					param_count++;
				}
			}
			segment_code += "\tcall " + (yyvsp[-3].symbol)->getName() + "\n";
			segment_code += "\tmov ax, ret_temp\n";
			segment_code += "\tmov " + temp_var + ", ax\n";
			for(int i = pushed_var.size()-1; i >= 0; i--)
				segment_code += "\tpop " + pushed_var.at(i) + "\n";
		}
		//---------------//
		logout << (yyvsp[-3].symbol)->getName() << (yyvsp[-2].symbol)->getName();
		(yyval.vectorsymbol)->push_back((yyvsp[-3].symbol));
		(yyval.vectorsymbol)->push_back((yyvsp[-2].symbol));
		for (int i = 0; i < (yyvsp[-1].vectorsymbol)->size(); i++){
	 		logout << (yyvsp[-1].vectorsymbol)->at(i)->getName();
	 		(yyval.vectorsymbol)->push_back((yyvsp[-1].vectorsymbol)->at(i));
  		 }
  		 logout << (yyvsp[0].symbol)->getName() << "\n\n";
		(yyval.vectorsymbol)->push_back((yyvsp[0].symbol));

		//assembly code
		(yyval.vectorsymbol)->at(0)->setCode((yyval.vectorsymbol)->at(0)->getCode() + segment_code);
		(yyval.vectorsymbol)->at(0)->setSymbol(temp_var);

	}
#line 3233 "y.tab.c"
    break;

  case 62: /* factor: LPAREN expression RPAREN  */
#line 1717 "170000.y"
        {
		(yyval.vectorsymbol) = new vector<SymbolInfo*>();
		logout << "line no: " << line_count <<  " factor  : LPAREN expression RPAREN\n\n";
		logout << (yyvsp[-2].symbol)->getName();
		(yyval.vectorsymbol)->push_back((yyvsp[-2].symbol));
		for (int i = 0; i < (yyvsp[-1].vectorsymbol)->size(); i++){
	 		logout << (yyvsp[-1].vectorsymbol)->at(i)->getName();
	 		(yyval.vectorsymbol)->push_back((yyvsp[-1].vectorsymbol)->at(i));
  		 }
  		 logout << (yyvsp[0].symbol)->getName() << "\n\n";
		(yyval.vectorsymbol)->push_back((yyvsp[0].symbol));

		//assembly code
		(yyval.vectorsymbol)->at(0)->setSymbol((yyvsp[-1].vectorsymbol)->at(0)->getSymbol());
		(yyval.vectorsymbol)->at(0)->setCode((yyval.vectorsymbol)->at(0)->getCode() + (yyvsp[-1].vectorsymbol)->at(0)->getCode());
	}
#line 3254 "y.tab.c"
    break;

  case 63: /* factor: CONST_INT  */
#line 1734 "170000.y"
        {
		(yyval.vectorsymbol) = new vector<SymbolInfo*>();
		logout << "line no: " << line_count <<  " factor : CONST_INT\n\n";
		logout << (yyvsp[0].symbol)->getName() << "\n\n";
		(yyval.vectorsymbol)->push_back((yyvsp[0].symbol));

		//assembly code
		(yyvsp[0].symbol)->setSymbol((yyvsp[0].symbol)->getName());
	}
#line 3268 "y.tab.c"
    break;

  case 64: /* factor: CONST_FLOAT  */
#line 1744 "170000.y"
        {
		(yyval.vectorsymbol) = new vector<SymbolInfo*>();
		logout << "line no: " << line_count <<  " factor : CONST_FLOAT\n\n";
		logout << (yyvsp[0].symbol)->getName() << "\n\n";
		(yyval.vectorsymbol)->push_back((yyvsp[0].symbol));

		//assembly code
		(yyvsp[0].symbol)->setSymbol((yyvsp[0].symbol)->getName());
	}
#line 3282 "y.tab.c"
    break;

  case 65: /* factor: variable INCOP  */
#line 1754 "170000.y"
        {
		(yyval.vectorsymbol) = new vector<SymbolInfo*>();
		logout << "line no: " << line_count <<  " factor  : variable INCOP\n\n";
		for (int i = 0; i < (yyvsp[-1].vectorsymbol)->size(); i++){
	 		logout << (yyvsp[-1].vectorsymbol)->at(i)->getName();
	 		(yyval.vectorsymbol)->push_back((yyvsp[-1].vectorsymbol)->at(i));
  		 }
  		 logout << (yyvsp[0].symbol)->getName() << "\n\n";
  		 (yyval.vectorsymbol)->push_back((yyvsp[0].symbol));

		//assembly code
		string temp = newTemp();
		string segment_code = "";

		string whichvariable = (symboltable.LookUp(logout, (yyvsp[-1].vectorsymbol)->at(0)->getName()))->getWhichVariable();

		if(whichvariable != "array"){
			segment_code += "\tmov ax, " + (yyvsp[-1].vectorsymbol)->at(0)->getSymbol() + "\n";
			segment_code += "\tmov " + temp + ", ax\n";
			segment_code += "\tinc " + (yyvsp[-1].vectorsymbol)->at(0)->getSymbol()  + "\n";
		}

		else if(whichvariable == "array"){
			segment_code += "\tmov ax, " + (yyvsp[-1].vectorsymbol)->at(0)->getSymbol() + "[di]\n";
			segment_code += "\tmov " + temp + ", ax\n";
			segment_code += "\tinc " + (yyvsp[-1].vectorsymbol)->at(0)->getSymbol()  + "[di]\n";
		}

		(yyval.vectorsymbol)->at(0)->setSymbol(temp);
		(yyval.vectorsymbol)->at(0)->setCode((yyval.vectorsymbol)->at(0)->getCode() + segment_code);
	
	}
#line 3319 "y.tab.c"
    break;

  case 66: /* factor: variable DECOP  */
#line 1787 "170000.y"
        {
		(yyval.vectorsymbol) = new vector<SymbolInfo*>();
		logout << "line no: " << line_count <<  " factor  : variable DECOP\n\n";
		for (int i = 0; i < (yyvsp[-1].vectorsymbol)->size(); i++){
	 		logout << (yyvsp[-1].vectorsymbol)->at(i)->getName();
	 		(yyval.vectorsymbol)->push_back((yyvsp[-1].vectorsymbol)->at(i));
  		 }
  		 logout << (yyvsp[0].symbol)->getName() << "\n\n";
  		 (yyval.vectorsymbol)->push_back((yyvsp[0].symbol));

		//assembly code
		string temp = newTemp();
		string segment_code = "";

		string whichvariable = (symboltable.LookUp(logout, (yyvsp[-1].vectorsymbol)->at(0)->getName()))->getWhichVariable();

		if(whichvariable != "array"){
			segment_code += "\tmov ax, " + (yyvsp[-1].vectorsymbol)->at(0)->getSymbol() + "\n";
			segment_code += "\tmov " + temp + ", ax\n";
			segment_code += "\tdec " + (yyvsp[-1].vectorsymbol)->at(0)->getSymbol()  + "\n";
		}

		else if(whichvariable == "array"){
			segment_code += "\tmov ax, " + (yyvsp[-1].vectorsymbol)->at(0)->getSymbol() + "[di]\n";
			segment_code += "\tmov " + temp + ", ax\n";
			segment_code += "\tdec " + (yyvsp[-1].vectorsymbol)->at(0)->getSymbol()  + "[di]\n";
		}

		(yyval.vectorsymbol)->at(0)->setSymbol(temp);
		(yyval.vectorsymbol)->at(0)->setCode((yyval.vectorsymbol)->at(0)->getCode() + segment_code);
	}
#line 3355 "y.tab.c"
    break;

  case 67: /* argument_list: arguments  */
#line 1820 "170000.y"
                  {
			(yyval.vectorsymbol) = new vector<SymbolInfo*>();
		  	logout << "line no: " << line_count <<  " argument_list : arguments\n\n";
			for (int i = 0; i < (yyvsp[0].vectorsymbol)->size(); i++){
		 		logout << (yyvsp[0].vectorsymbol)->at(i)->getName();
		 		(yyval.vectorsymbol)->push_back((yyvsp[0].vectorsymbol)->at(i));
	  		 }
	  		 logout << "\n\n";
		  }
#line 3369 "y.tab.c"
    break;

  case 68: /* argument_list: %empty  */
#line 1830 "170000.y"
                  {
			(yyval.vectorsymbol) = new vector<SymbolInfo*>();
		  	logout << "line no: " << line_count <<  " argument_list : \n\n";
	  		logout << "\n\n";
		  }
#line 3379 "y.tab.c"
    break;

  case 69: /* arguments: arguments COMMA logic_expression  */
#line 1838 "170000.y"
                {
			(yyval.vectorsymbol) = new vector<SymbolInfo*>();
			logout << "line no: " << line_count <<  " arguments : arguments COMMA logic_expressionn\n";
			for (int i = 0; i < (yyvsp[-2].vectorsymbol)->size(); i++){
		 		logout << (yyvsp[-2].vectorsymbol)->at(i)->getName();
		 		(yyval.vectorsymbol)->push_back((yyvsp[-2].vectorsymbol)->at(i));
	  		 }
	  		 logout << (yyvsp[-1].symbol)->getName();
	  		 (yyval.vectorsymbol)->push_back((yyvsp[-1].symbol));
	  		 for (int i = 0; i < (yyvsp[0].vectorsymbol)->size(); i++){
		 		logout << (yyvsp[0].vectorsymbol)->at(i)->getName();
		 		(yyval.vectorsymbol)->push_back((yyvsp[0].vectorsymbol)->at(i));
	  		 }
	  		 logout << "\n\n";
		}
#line 3399 "y.tab.c"
    break;

  case 70: /* arguments: logic_expression  */
#line 1854 "170000.y"
                {
			(yyval.vectorsymbol) = new vector<SymbolInfo*>();
	      		logout << "line no: " << line_count <<  " arguments  : logic_expression\n\n";
			for (int i = 0; i < (yyvsp[0].vectorsymbol)->size(); i++){
		 		logout << (yyvsp[0].vectorsymbol)->at(i)->getName();
		 		(yyval.vectorsymbol)->push_back((yyvsp[0].vectorsymbol)->at(i));
	  		}
	  		logout << "\n\n";
		}
#line 3413 "y.tab.c"
    break;


#line 3417 "y.tab.c"

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

#line 1865 "170000.y"


int main(int argc,char *argv[])
{

	if(argc!=2){
		cout << "Please provide input file name and try again\n";
		return 0;
	}
	
	FILE *infile=fopen(argv[1],"r");
	if(infile==NULL){
		cout << "Cannot open specified file\n";
		return 0;
	}
	
	logout.open("log.txt");
	errorout.open("error.txt");
	code.open("code.asm");
	
	yyin=infile;
	yyparse();

	symboltable.printAllScopeTable(logout);
	logout << "Total lines: " << line_count-1 << endl;
    logout << "Total errors: " << error_count << endl;
	fclose(yyin);
	logout.close();
	errorout.close();
	code.close();
	Optimized_Code("code.asm");

	
	return 0;
}
