/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

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
#line 178 "1805063.y"

     smbol_info *symbol;
     vector<smbol_info*>* vectorsymbol;

#line 142 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
