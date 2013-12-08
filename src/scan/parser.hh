/* A Bison parser, made by GNU Bison 2.0.  */

/* Skeleton parser for Yacc-like parsing with Bison,
   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     T_EOF = 258,
     T_ERROR = 259,
     T_DOT = 260,
     T_SEMICOLON = 261,
     T_EQ = 262,
     T_COLON = 263,
     T_LEFTBRACKET = 264,
     T_RIGHTBRACKET = 265,
     T_LEFTPAR = 266,
     T_RIGHTPAR = 267,
     T_COMMA = 268,
     T_LESSTHAN = 269,
     T_GREATERTHAN = 270,
     T_ADD = 271,
     T_SUB = 272,
     T_MUL = 273,
     T_RDIV = 274,
     T_OF = 275,
     T_IF = 276,
     T_DO = 277,
     T_ASSIGN = 278,
     T_NOTEQ = 279,
     T_OR = 280,
     T_VAR = 281,
     T_END = 282,
     T_AND = 283,
     T_IDIV = 284,
     T_MOD = 285,
     T_NOT = 286,
     T_THEN = 287,
     T_ELSE = 288,
     T_IDENT = 289,
     T_CONST = 290,
     T_ARRAY = 291,
     T_BEGIN = 292,
     T_WHILE = 293,
     T_ELSIF = 294,
     T_INTNUM = 295,
     T_RETURN = 296,
     T_STRINGCONST = 297,
     T_PROGRAM = 298,
     T_PROCEDURE = 299,
     T_FUNCTION = 300,
     T_REALNUM = 301
   };
#endif
#define T_EOF 258
#define T_ERROR 259
#define T_DOT 260
#define T_SEMICOLON 261
#define T_EQ 262
#define T_COLON 263
#define T_LEFTBRACKET 264
#define T_RIGHTBRACKET 265
#define T_LEFTPAR 266
#define T_RIGHTPAR 267
#define T_COMMA 268
#define T_LESSTHAN 269
#define T_GREATERTHAN 270
#define T_ADD 271
#define T_SUB 272
#define T_MUL 273
#define T_RDIV 274
#define T_OF 275
#define T_IF 276
#define T_DO 277
#define T_ASSIGN 278
#define T_NOTEQ 279
#define T_OR 280
#define T_VAR 281
#define T_END 282
#define T_AND 283
#define T_IDIV 284
#define T_MOD 285
#define T_NOT 286
#define T_THEN 287
#define T_ELSE 288
#define T_IDENT 289
#define T_CONST 290
#define T_ARRAY 291
#define T_BEGIN 292
#define T_WHILE 293
#define T_ELSIF 294
#define T_INTNUM 295
#define T_RETURN 296
#define T_STRINGCONST 297
#define T_PROGRAM 298
#define T_PROCEDURE 299
#define T_FUNCTION 300
#define T_REALNUM 301




#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
#line 42 "parser.y"
typedef union YYSTYPE {
    ast_node             *ast;
    ast_id               *id;
    ast_stmt_list        *statement_list;
    ast_statement        *statement;
    ast_expr_list        *expression_list;
    ast_expression       *expression;
    ast_elsif_list       *elsif_list;
    ast_elsif            *elsif;
    ast_lvalue           *lvalue;
    ast_functioncall     *function_call;
    ast_functionhead     *function_head;
    ast_procedurehead    *procedure_head;
    ast_integer          *integer;
    ast_real             *real;
    
    int                   ival;
    float                 rval;
    pool_index            str;
    pool_index            pool_p;
} YYSTYPE;
/* Line 1318 of yacc.c.  */
#line 151 "parser.hh"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

#if ! defined (YYLTYPE) && ! defined (YYLTYPE_IS_DECLARED)
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif

extern YYLTYPE yylloc;


