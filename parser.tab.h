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

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
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
    IDENTIFIER = 258,              /* IDENTIFIER  */
    INT_CONST = 259,               /* INT_CONST  */
    FLOAT_CONST = 260,             /* FLOAT_CONST  */
    CHAR_CONST = 261,              /* CHAR_CONST  */
    BIN_CONST = 262,               /* BIN_CONST  */
    COMPLEX_CONST = 263,           /* COMPLEX_CONST  */
    STRING_LITERAL = 264,          /* STRING_LITERAL  */
    BIT_STRING = 265,              /* BIT_STRING  */
    HEX_STRING = 266,              /* HEX_STRING  */
    KEYWORD_DECLARE = 267,         /* KEYWORD_DECLARE  */
    KEYWORD_PROCEDURE = 268,       /* KEYWORD_PROCEDURE  */
    KEYWORD_OPTIONS = 269,         /* KEYWORD_OPTIONS  */
    KEYWORD_MAIN = 270,            /* KEYWORD_MAIN  */
    KEYWORD_RECURSIVE = 271,       /* KEYWORD_RECURSIVE  */
    KEYWORD_RETURNS = 272,         /* KEYWORD_RETURNS  */
    KEYWORD_RETURN = 273,          /* KEYWORD_RETURN  */
    KEYWORD_CALL = 274,            /* KEYWORD_CALL  */
    KEYWORD_END = 275,             /* KEYWORD_END  */
    KEYWORD_FIXED = 276,           /* KEYWORD_FIXED  */
    KEYWORD_FLOAT = 277,           /* KEYWORD_FLOAT  */
    KEYWORD_BINARY = 278,          /* KEYWORD_BINARY  */
    KEYWORD_DECIMAL = 279,         /* KEYWORD_DECIMAL  */
    KEYWORD_BIT = 280,             /* KEYWORD_BIT  */
    KEYWORD_CHARACTER = 281,       /* KEYWORD_CHARACTER  */
    KEYWORD_COMPLEX = 282,         /* KEYWORD_COMPLEX  */
    KEYWORD_POINTER = 283,         /* KEYWORD_POINTER  */
    KEYWORD_VARYING = 284,         /* KEYWORD_VARYING  */
    KEYWORD_INITIAL = 285,         /* KEYWORD_INITIAL  */
    KEYWORD_IF = 286,              /* KEYWORD_IF  */
    KEYWORD_THEN = 287,            /* KEYWORD_THEN  */
    KEYWORD_ELSE = 288,            /* KEYWORD_ELSE  */
    KEYWORD_DO = 289,              /* KEYWORD_DO  */
    KEYWORD_WHILE = 290,           /* KEYWORD_WHILE  */
    KEYWORD_UNTIL = 291,           /* KEYWORD_UNTIL  */
    KEYWORD_TO = 292,              /* KEYWORD_TO  */
    KEYWORD_BY = 293,              /* KEYWORD_BY  */
    KEYWORD_LEAVE = 294,           /* KEYWORD_LEAVE  */
    KEYWORD_ITERATE = 295,         /* KEYWORD_ITERATE  */
    KEYWORD_SELECT = 296,          /* KEYWORD_SELECT  */
    KEYWORD_WHEN = 297,            /* KEYWORD_WHEN  */
    KEYWORD_OTHERWISE = 298,       /* KEYWORD_OTHERWISE  */
    KEYWORD_GO = 299,              /* KEYWORD_GO  */
    KEYWORD_GOTO = 300,            /* KEYWORD_GOTO  */
    KEYWORD_PUT = 301,             /* KEYWORD_PUT  */
    KEYWORD_GET = 302,             /* KEYWORD_GET  */
    KEYWORD_SKIP = 303,            /* KEYWORD_SKIP  */
    KEYWORD_LIST = 304,            /* KEYWORD_LIST  */
    KEYWORD_EDIT = 305,            /* KEYWORD_EDIT  */
    OP_EXPONENT = 306,             /* OP_EXPONENT  */
    OP_CONCAT = 307,               /* OP_CONCAT  */
    OP_NE = 308,                   /* OP_NE  */
    OP_NLT = 309,                  /* OP_NLT  */
    OP_NGT = 310,                  /* OP_NGT  */
    OP_LE = 311,                   /* OP_LE  */
    OP_GE = 312,                   /* OP_GE  */
    ARROW = 313,                   /* ARROW  */
    OP_NOT = 314,                  /* OP_NOT  */
    LOWER_THAN_ELSE = 315,         /* LOWER_THAN_ELSE  */
    UMINUS = 316                   /* UMINUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 27 "parser.y"

    char *str;
    struct ASTNode *node;

#line 130 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
