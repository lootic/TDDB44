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

/* Written by Richard Stallman by simplifying the original so called
   ``semantic'' parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 1



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




/* Copy the first part of user declarations.  */
#line 1 "parser.y"

#include <iostream.h>
#include "semantic.hh"
#include "optimize.hh"
#include "codegen.hh"
    
extern char	      *yytext;           /* Defined in parser.cc */
extern int             error_count;      /* Nr of errors encountered so far.
					    Only generate quads & assembler if
					    error_count == 0. Defined in
					    error.cc. */
extern symbol_table   *sym_tab;          /* Defined in symtab.cc. */
extern semantic       *type_checker;     /* Defined in semantic.cc. */
extern code_generator *code_gen;         /* Defined in codegen.cc. */ 
extern int	       yylex();          /* From scanner.l output. */

extern void	       yyerror(char *);  /* Defined in error.hh. */

extern int             print_ast;        /* All these defined in main.cc. */
extern int             print_quads;      /* They represent some of the flags */
extern int             no_typecheck;     /* given to the 'diesel' script. */
extern int             no_optimize;
extern int             no_quads;
extern int             no_assembler;

#define YYDEBUG 1
/* #define YYERROR_VERBOSE */            /* Have this defined to give better
                                            error messages. Using it causes
					    some bison warnings at compiler
					    compile time, however. Use as you
					    wish. Not mandatory. */


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

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
/* Line 190 of yacc.c.  */
#line 223 "parser.cc"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

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


/* Copy the second part of user declarations.  */


/* Line 213 of yacc.c.  */
#line 247 "parser.cc"

#if ! defined (yyoverflow) || YYERROR_VERBOSE

# ifndef YYFREE
#  define YYFREE free
# endif
# ifndef YYMALLOC
#  define YYMALLOC malloc
# endif

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   else
#    define YYSTACK_ALLOC alloca
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning. */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
# else
#  if defined (__STDC__) || defined (__cplusplus)
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   define YYSIZE_T size_t
#  endif
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
# endif
#endif /* ! defined (yyoverflow) || YYERROR_VERBOSE */


#if (! defined (yyoverflow) \
     && (! defined (__cplusplus) \
	 || (defined (YYLTYPE_IS_TRIVIAL) && YYLTYPE_IS_TRIVIAL \
             && defined (YYSTYPE_IS_TRIVIAL) && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  short int yyss;
  YYSTYPE yyvs;
    YYLTYPE yyls;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short int) + sizeof (YYSTYPE) + sizeof (YYLTYPE))	\
      + 2 * YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined (__GNUC__) && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  register YYSIZE_T yyi;		\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (0)
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (0)

#endif

#if defined (__STDC__) || defined (__cplusplus)
   typedef signed char yysigned_char;
#else
   typedef short int yysigned_char;
#endif

/* YYFINAL -- State number of the termination state. */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   213

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  45
/* YYNRULES -- Number of rules. */
#define YYNRULES  94
/* YYNRULES -- Number of states. */
#define YYNSTATES  188

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   301

#define YYTRANSLATE(YYX) 						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned char yytranslate[] =
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
      45,    46
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned short int yyprhs[] =
{
       0,     0,     3,     8,    13,    16,    19,    22,    23,    25,
      28,    33,    38,    43,    48,    51,    52,    54,    57,    62,
      72,    82,    84,    85,    87,    90,    95,   100,   106,   114,
     117,   120,   124,   128,   129,   131,   135,   139,   143,   145,
     149,   157,   163,   168,   172,   175,   177,   178,   180,   185,
     190,   192,   197,   200,   201,   206,   209,   210,   212,   213,
     215,   219,   221,   225,   229,   233,   237,   239,   242,   245,
     249,   253,   257,   259,   263,   267,   271,   275,   279,   281,
     283,   285,   287,   290,   294,   299,   301,   303,   305,   307,
     309,   311,   313,   315,   317
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const yysigned_char yyrhs[] =
{
      48,     0,    -1,    49,    57,    67,     5,    -1,    50,     6,
      51,    54,    -1,    43,    34,    -1,    35,    52,    -1,     1,
      52,    -1,    -1,    53,    -1,    52,    53,    -1,    34,     7,
      82,     6,    -1,    34,     7,    83,     6,    -1,    34,     7,
      42,     6,    -1,    34,     7,    85,     6,    -1,    26,    55,
      -1,    -1,    56,    -1,    55,    56,    -1,    34,     8,    84,
       6,    -1,    34,     8,    36,     9,    82,    10,    20,    84,
       6,    -1,    34,     8,    36,     9,    85,    10,    20,    84,
       6,    -1,    58,    -1,    -1,    59,    -1,    58,    59,    -1,
      60,    57,    67,     6,    -1,    61,    57,    67,     6,    -1,
      62,    64,     6,    51,    54,    -1,    63,    64,     8,    84,
       6,    51,    54,    -1,    44,    34,    -1,    45,    34,    -1,
      11,    65,    12,    -1,    11,     1,    12,    -1,    -1,    66,
      -1,    65,     6,    66,    -1,    34,     8,    84,    -1,    37,
      68,    27,    -1,    69,    -1,    68,     6,    69,    -1,    21,
      77,    32,    68,    72,    74,    27,    -1,    38,    77,    22,
      68,    27,    -1,    88,    11,    75,    12,    -1,    70,    23,
      77,    -1,    41,    77,    -1,    41,    -1,    -1,    86,    -1,
      90,     9,    77,    10,    -1,    90,     9,     1,    10,    -1,
      87,    -1,    90,     9,    77,    10,    -1,    72,    73,    -1,
      -1,    39,    77,    32,    68,    -1,    33,    68,    -1,    -1,
      76,    -1,    -1,    77,    -1,    76,    13,    77,    -1,    78,
      -1,    77,     7,    78,    -1,    77,    24,    78,    -1,    77,
      14,    78,    -1,    77,    15,    78,    -1,    79,    -1,    16,
      79,    -1,    17,    79,    -1,    78,    25,    79,    -1,    78,
      16,    79,    -1,    78,    17,    79,    -1,    80,    -1,    79,
      28,    80,    -1,    79,    18,    80,    -1,    79,    19,    80,
      -1,    79,    29,    80,    -1,    79,    30,    80,    -1,    71,
      -1,    81,    -1,    82,    -1,    83,    -1,    31,    80,    -1,
      11,    77,    12,    -1,    89,    11,    75,    12,    -1,    40,
      -1,    46,    -1,    91,    -1,    91,    -1,    91,    -1,    91,
      -1,    91,    -1,    91,    -1,    91,    -1,    34,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short int yyrline[] =
{
       0,   112,   112,   160,   167,   177,   178,   179,   183,   184,
     188,   193,   198,   202,   217,   218,   222,   223,   227,   232,
     237,   289,   290,   294,   295,   299,   346,   396,   403,   411,
     431,   453,   457,   462,   469,   474,   480,   498,   506,   511,
     519,   524,   529,   534,   539,   544,   551,   557,   561,   567,
     574,   579,   588,   594,   601,   609,   615,   622,   628,   635,
     640,   648,   653,   658,   663,   668,   676,   681,   686,   691,
     696,   701,   709,   714,   719,   724,   729,   734,   742,   746,
     750,   754,   758,   763,   772,   781,   794,   807,   820,   833,
     845,   861,   874,   887,   900
};
#endif

#if YYDEBUG || YYERROR_VERBOSE
/* YYTNME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_EOF", "T_ERROR", "T_DOT",
  "T_SEMICOLON", "T_EQ", "T_COLON", "T_LEFTBRACKET", "T_RIGHTBRACKET",
  "T_LEFTPAR", "T_RIGHTPAR", "T_COMMA", "T_LESSTHAN", "T_GREATERTHAN",
  "T_ADD", "T_SUB", "T_MUL", "T_RDIV", "T_OF", "T_IF", "T_DO", "T_ASSIGN",
  "T_NOTEQ", "T_OR", "T_VAR", "T_END", "T_AND", "T_IDIV", "T_MOD", "T_NOT",
  "T_THEN", "T_ELSE", "T_IDENT", "T_CONST", "T_ARRAY", "T_BEGIN",
  "T_WHILE", "T_ELSIF", "T_INTNUM", "T_RETURN", "T_STRINGCONST",
  "T_PROGRAM", "T_PROCEDURE", "T_FUNCTION", "T_REALNUM", "$accept",
  "program", "prog_decl", "prog_head", "const_part", "const_decls",
  "const_decl", "variable_part", "var_decls", "var_decl", "subprog_part",
  "subprog_decls", "subprog_decl", "proc_decl", "func_decl", "proc_head",
  "func_head", "opt_param_list", "param_list", "param", "comp_stmt",
  "stmt_list", "stmt", "lvariable", "rvariable", "elsif_list", "elsif",
  "else_part", "opt_expr_list", "expr_list", "expr", "simple_expr", "term",
  "factor", "func_call", "integer", "real", "type_id", "const_id",
  "lvar_id", "rvar_id", "proc_id", "func_id", "array_id", "id", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const unsigned short int yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned char yyr1[] =
{
       0,    47,    48,    49,    50,    51,    51,    51,    52,    52,
      53,    53,    53,    53,    54,    54,    55,    55,    56,    56,
      56,    57,    57,    58,    58,    59,    59,    60,    61,    62,
      63,    64,    64,    64,    65,    65,    66,    67,    68,    68,
      69,    69,    69,    69,    69,    69,    69,    70,    70,    70,
      71,    71,    72,    72,    73,    74,    74,    75,    75,    76,
      76,    77,    77,    77,    77,    77,    78,    78,    78,    78,
      78,    78,    79,    79,    79,    79,    79,    79,    80,    80,
      80,    80,    80,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     4,     4,     2,     2,     2,     0,     1,     2,
       4,     4,     4,     4,     2,     0,     1,     2,     4,     9,
       9,     1,     0,     1,     2,     4,     4,     5,     7,     2,
       2,     3,     3,     0,     1,     3,     3,     3,     1,     3,
       7,     5,     4,     3,     2,     1,     0,     1,     4,     4,
       1,     4,     2,     0,     4,     2,     0,     1,     0,     1,
       3,     1,     3,     3,     3,     3,     1,     2,     2,     3,
       3,     3,     1,     3,     3,     3,     3,     3,     1,     1,
       1,     1,     2,     3,     4,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned char yydefact[] =
{
       0,     0,     0,    22,     0,     4,     1,     0,     0,     0,
      21,    23,    22,    22,    33,    33,     0,    29,    30,    46,
       0,    24,     0,     0,     0,     0,     0,     0,     0,    15,
       0,    94,     0,    45,     0,    38,     0,    47,     0,     0,
      89,     2,     0,     0,     0,     0,     0,    34,     0,     0,
       0,     6,     8,     5,     0,     3,     0,     0,     0,     0,
      85,    86,    78,     0,    61,    66,    72,    79,    80,    81,
      50,     0,     0,    90,     0,    44,    46,    37,     0,    58,
       0,    25,    26,    32,     0,     0,    31,    15,     0,    87,
       0,     9,     0,    14,    16,     0,    67,    68,    82,     0,
       0,     0,     0,    46,     0,     0,     0,     0,     0,     0,
       0,     0,    58,     0,    46,    39,    43,     0,    57,    59,
       0,     0,    36,    35,    27,     0,     0,     0,     0,     0,
      88,     0,    17,    83,    62,    64,    65,    63,    53,    70,
      71,    69,    74,    75,    73,    76,    77,     0,     0,     0,
      42,     0,    49,    48,    15,    12,    10,    11,    13,     0,
       0,    56,    84,    51,    41,    60,    28,     0,    18,    46,
       0,    52,     0,     0,     0,    55,     0,    40,     0,     0,
      46,     0,     0,    54,     0,     0,    19,    20
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short int yydefgoto[] =
{
      -1,     2,     3,     4,    29,    51,    52,    55,    93,    94,
       9,    10,    11,    12,    13,    14,    15,    25,    46,    47,
      20,    34,    35,    36,    62,   161,   171,   172,   117,   118,
     119,    64,    65,    66,    67,    68,    69,    88,   129,    37,
      70,    38,    71,    72,    73
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -103
static const short int yypact[] =
{
     -35,   -10,    32,    36,    41,  -103,  -103,    22,    35,    57,
      36,  -103,    36,    36,    86,    86,    38,  -103,  -103,    80,
     101,  -103,    57,    57,    20,   133,   138,   124,   124,   134,
       2,  -103,     2,     2,    10,  -103,   128,  -103,   157,   160,
      18,  -103,   164,   170,   165,   171,   110,  -103,    38,   144,
     173,   124,  -103,   124,   147,  -103,     2,    65,    65,    65,
    -103,  -103,  -103,    93,     6,    16,  -103,  -103,  -103,  -103,
    -103,   172,   175,    61,    44,   121,    80,  -103,     2,     2,
       9,  -103,  -103,  -103,   144,   148,  -103,   134,   179,  -103,
     125,  -103,   178,   147,  -103,   117,    16,    16,  -103,     2,
       2,     2,     2,    80,    65,    65,    65,    65,    65,    65,
      65,    65,     2,     2,    80,  -103,   121,   176,   174,   121,
     180,   123,  -103,  -103,  -103,    38,   183,   185,   186,   187,
    -103,    43,  -103,  -103,     6,     6,     6,     6,   188,    16,
      16,    16,  -103,  -103,  -103,  -103,  -103,   184,   142,    11,
    -103,     2,  -103,  -103,   134,  -103,  -103,  -103,  -103,   189,
     191,    87,  -103,  -103,  -103,   121,  -103,   100,  -103,    80,
       2,  -103,   168,   190,   192,   188,    95,  -103,   181,   193,
      80,   144,   144,   188,   197,   198,  -103,  -103
};

/* YYPGOTO[NTERM-NUM].  */
static const short int yypgoto[] =
{
    -103,  -103,  -103,  -103,   -39,   177,    62,   -80,  -103,   106,
     131,  -103,   196,  -103,  -103,  -103,  -103,   194,  -103,   122,
     132,  -102,   135,  -103,  -103,  -103,  -103,  -103,    96,  -103,
     -28,    73,   -43,   -18,  -103,   -79,   120,   -78,    45,  -103,
    -103,  -103,  -103,   -16,   -19
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -94
static const short int yytable[] =
{
      40,   138,    63,    39,    74,    75,   122,   124,     1,    87,
     120,   127,   149,    56,    96,    97,    76,    76,    57,    58,
      56,    44,   104,   105,     5,    57,    58,   -93,    95,   -91,
      89,   106,     6,    59,   107,   108,    31,    77,   164,    27,
      59,    98,    60,    31,   109,   110,   111,    16,    61,    60,
     116,    99,   121,   160,    45,    61,    17,    40,   100,   101,
      39,   139,   140,   141,    -7,    89,   114,   175,   102,    18,
     -93,   130,   -92,    28,   166,    -7,    56,    31,   183,   159,
       7,     8,    -7,    -7,    40,   148,   154,    39,   173,   142,
     143,   144,   145,   146,    19,    40,    59,    24,    39,    31,
      99,    30,    99,   184,   185,    60,    41,   100,   101,   100,
     101,    61,    89,    91,    31,    91,    85,   102,    32,   102,
     169,    33,    86,   165,    99,   103,   170,   180,    99,   133,
      99,   100,   101,   153,    31,   100,   101,   100,   101,    48,
      60,   102,   176,    22,    23,   102,    49,   102,   130,    99,
      40,    78,   163,    39,    42,    43,   100,   101,    50,    31,
      54,    40,    89,    89,    39,    60,   102,   126,    79,    80,
      81,    61,   134,   135,   136,   137,    82,    83,    31,    84,
      90,    92,    45,   112,   113,   125,   131,   151,   150,   155,
     152,   156,   157,   158,    76,   177,   162,   168,   167,   132,
     178,   181,   179,   186,   187,    53,    21,   123,   147,    26,
     128,   115,   174,   182
};

static const unsigned char yycheck[] =
{
      19,   103,    30,    19,    32,    33,    84,    87,    43,    48,
       1,    90,   114,    11,    57,    58,     6,     6,    16,    17,
      11,     1,    16,    17,    34,    16,    17,     9,    56,    11,
      49,    25,     0,    31,    18,    19,    34,    27,    27,     1,
      31,    59,    40,    34,    28,    29,    30,     6,    46,    40,
      78,     7,    80,   131,    34,    46,    34,    76,    14,    15,
      76,   104,   105,   106,    26,    84,    22,   169,    24,    34,
       9,    90,    11,    35,   154,    37,    11,    34,   180,    36,
      44,    45,    44,    45,   103,   113,   125,   103,   167,   107,
     108,   109,   110,   111,    37,   114,    31,    11,   114,    34,
       7,    21,     7,   181,   182,    40,     5,    14,    15,    14,
      15,    46,   131,    51,    34,    53,     6,    24,    38,    24,
      33,    41,    12,   151,     7,    32,    39,    32,     7,    12,
       7,    14,    15,    10,    34,    14,    15,    14,    15,     6,
      40,    24,   170,    12,    13,    24,     8,    24,   167,     7,
     169,    23,    10,   169,    22,    23,    14,    15,    34,    34,
      26,   180,   181,   182,   180,    40,    24,    42,    11,     9,
       6,    46,    99,   100,   101,   102,     6,    12,    34,     8,
       7,    34,    34,    11,     9,     6,     8,    13,    12,     6,
      10,     6,     6,     6,     6,    27,    12,     6,     9,    93,
      10,    20,    10,     6,     6,    28,    10,    85,   112,    15,
      90,    76,   167,    20
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned char yystos[] =
{
       0,    43,    48,    49,    50,    34,     0,    44,    45,    57,
      58,    59,    60,    61,    62,    63,     6,    34,    34,    37,
      67,    59,    57,    57,    11,    64,    64,     1,    35,    51,
      21,    34,    38,    41,    68,    69,    70,    86,    88,    90,
      91,     5,    67,    67,     1,    34,    65,    66,     6,     8,
      34,    52,    53,    52,    26,    54,    11,    16,    17,    31,
      40,    46,    71,    77,    78,    79,    80,    81,    82,    83,
      87,    89,    90,    91,    77,    77,     6,    27,    23,    11,
       9,     6,     6,    12,     8,     6,    12,    51,    84,    91,
       7,    53,    34,    55,    56,    77,    79,    79,    80,     7,
      14,    15,    24,    32,    16,    17,    25,    18,    19,    28,
      29,    30,    11,     9,    22,    69,    77,    75,    76,    77,
       1,    77,    84,    66,    54,     6,    42,    82,    83,    85,
      91,     8,    56,    12,    78,    78,    78,    78,    68,    79,
      79,    79,    80,    80,    80,    80,    80,    75,    77,    68,
      12,    13,    10,    10,    51,     6,     6,     6,     6,    36,
      84,    72,    12,    10,    27,    77,    54,     9,     6,    33,
      39,    73,    74,    82,    85,    68,    77,    27,    10,    10,
      32,    20,    20,    68,    84,    84,     6,     6
};

#if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
# define YYSIZE_T __SIZE_TYPE__
#endif
#if ! defined (YYSIZE_T) && defined (size_t)
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T)
# if defined (__STDC__) || defined (__cplusplus)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# endif
#endif
#if ! defined (YYSIZE_T)
# define YYSIZE_T unsigned int
#endif

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { 								\
      yyerror ("syntax error: cannot back up");\
      YYERROR;							\
    }								\
while (0)


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (N)								\
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (0)
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
              (Loc).first_line, (Loc).first_column,	\
              (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
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
} while (0)

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)		\
do {								\
  if (yydebug)							\
    {								\
      YYFPRINTF (stderr, "%s ", Title);				\
      yysymprint (stderr, 					\
                  Type, Value, Location);	\
      YYFPRINTF (stderr, "\n");					\
    }								\
} while (0)

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_stack_print (short int *bottom, short int *top)
#else
static void
yy_stack_print (bottom, top)
    short int *bottom;
    short int *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (/* Nothing. */; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_reduce_print (int yyrule)
#else
static void
yy_reduce_print (yyrule)
    int yyrule;
#endif
{
  int yyi;
  unsigned int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %u), ",
             yyrule - 1, yylno);
  /* Print the symbols being reduced, and their result.  */
  for (yyi = yyprhs[yyrule]; 0 <= yyrhs[yyi]; yyi++)
    YYFPRINTF (stderr, "%s ", yytname [yyrhs[yyi]]);
  YYFPRINTF (stderr, "-> %s\n", yytname [yyr1[yyrule]]);
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (Rule);		\
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
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   SIZE_MAX < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined (__GLIBC__) && defined (_STRING_H)
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
#   if defined (__STDC__) || defined (__cplusplus)
yystrlen (const char *yystr)
#   else
yystrlen (yystr)
     const char *yystr;
#   endif
{
  register const char *yys = yystr;

  while (*yys++ != '\0')
    continue;

  return yys - yystr - 1;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined (__GLIBC__) && defined (_STRING_H) && defined (_GNU_SOURCE)
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
#   if defined (__STDC__) || defined (__cplusplus)
yystpcpy (char *yydest, const char *yysrc)
#   else
yystpcpy (yydest, yysrc)
     char *yydest;
     const char *yysrc;
#   endif
{
  register char *yyd = yydest;
  register const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

#endif /* !YYERROR_VERBOSE */



#if YYDEBUG
/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yysymprint (FILE *yyoutput, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yysymprint (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;
  (void) yylocationp;

  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  fprintf (yyoutput, ": ");

# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  switch (yytype)
    {
      default:
        break;
    }
  YYFPRINTF (yyoutput, ")");
}

#endif /* ! YYDEBUG */
/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;
  (void) yylocationp;

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
        break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM);
# else
int yyparse ();
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;
/* Location data for the look-ahead symbol.  */
YYLTYPE yylloc;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM)
# else
int yyparse (YYPARSE_PARAM)
  void *YYPARSE_PARAM;
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  register int yystate;
  register int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  short int yyssa[YYINITDEPTH];
  short int *yyss = yyssa;
  register short int *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  register YYSTYPE *yyvsp;

  /* The location stack.  */
  YYLTYPE yylsa[YYINITDEPTH];
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;
  /* The locations where the error started and ended. */
  YYLTYPE yyerror_range[2];

#define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* When reducing, the number of symbols on the RHS of the reduced
     rule.  */
  int yylen;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;
  yylsp = yyls;
#if YYLTYPE_IS_TRIVIAL
  /* Initialize the default location before parsing starts.  */
  yylloc.first_line   = yylloc.last_line   = 1;
  yylloc.first_column = yylloc.last_column = 0;
#endif


  yyvsp[0] = yylval;
    yylsp[0] = yylloc;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed. so pushing a state here evens the stacks.
     */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack. Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	short int *yyss1 = yyss;
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow ("parser stack overflow",
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);
	yyls = yyls1;
	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyoverflowlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyoverflowlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	short int *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyoverflowlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);
	YYSTACK_RELOCATE (yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

/* Do appropriate processing given the current state.  */
/* Read a look-ahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to look-ahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;
  *++yylsp = yylloc;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  yystate = yyn;
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

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, yylsp - yylen, yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 113 "parser.y"
    {
		    
		    symbol *env = sym_tab->get_symbol((yyvsp[-3].procedure_head)->sym_p);

		    // The status variables here depend on what flags were
		    // passed to the compiler. See the 'diesel' script for
		    // more information.
		    if(!no_typecheck)
			type_checker->do_typecheck(env, (yyvsp[-1].statement_list));
		    
		    if(print_ast) {
			cout << "\nUnoptimized AST for global level" << endl;
			cout << (ast_stmt_list *)(yyvsp[-1].statement_list) << endl;
		    }
			
		    if(!no_optimize) {
			optimizer->do_optimize((yyvsp[-1].statement_list));
			if(print_ast) {
			    cout << "\nOptimized AST for global level" << endl;
			    cout << (ast_stmt_list *)(yyvsp[-1].statement_list) << endl;
			}
		    }
		    if(error_count == 0) {
			if(!no_quads) {
			    quad_list *q = (yyvsp[-3].procedure_head)->do_quads((yyvsp[-1].statement_list));
			    if(print_quads) {
				cout << "\nQuad list for global level" << endl;
				cout << (quad_list *)q << endl;
			    }
			    
			    if(!no_assembler) {
				cout << "Generating assembler, global level"
				     << endl;
				code_gen->generate_assembler(q, env);
			    }
			}
		    } else {
			cout << "Found " << error_count << " errors. "
			     << "Compilation aborted.\n";
		    }
		    
		    // We close the global scope.		    
		    sym_tab->close_scope();
		;}
    break;

  case 3:
#line 161 "parser.y"
    {
		    (yyval.procedure_head) = (yyvsp[-3].procedure_head);
		;}
    break;

  case 4:
#line 168 "parser.y"
    {
		    /* Your code here. */
		    		    
		    sym_tab->open_scope();		    
		    
		;}
    break;

  case 10:
#line 189 "parser.y"
    {
		    /* Your code here. */
		    
		;}
    break;

  case 11:
#line 194 "parser.y"
    {
		    /* Your code here. */
		    
		;}
    break;

  case 12:
#line 199 "parser.y"
    {
		    // This isn't implemented in Diesel... Do nothing.
		;}
    break;

  case 13:
#line 203 "parser.y"
    {
		    // This part of code might get a bit ugly, but it's
		    // needed to allow constructions like this:
		    // constant foo = 5;
		    // constant bar = foo;
		    // ...now, why would anyone want to do that?


			/* Your code here */		    
		;}
    break;

  case 18:
#line 228 "parser.y"
    {
		    /* Your code here. */
		    
		;}
    break;

  case 19:
#line 233 "parser.y"
    {
		    /* Your code here. */
		    
		;}
    break;

  case 20:
#line 238 "parser.y"
    {
		    // We enter an array: pool_pointer, type pointer,
		    // the id type of the constant, and the value of the
		    // constant. 
		    position_information *pos =
			new position_information((yylsp[-8]).first_line,
			                         (yylsp[-8]).first_column);

		    // Ideally we should be able to just enter the array and
		    // defer index type checking to the semantic phase.
		    // However, since a constant can represent a real value,
		    // and the enter_array() method only accepts integer
		    // values for cardinality, we have to prevent entering an
		    // array with a float index here, or the compiler would
		    // crash.
		    // However, to make the compiler install the array,
		    // so we won't get a ton of complaints about this array
		    // being undeclared later on, we cheat and install it
		    // anyway with an illegal cardinality - which we _can_
		    // defer checking until the semantic phase.

		    // Find the const_id's symbol in the symbol table.
		    symbol *tmp =
			sym_tab->get_symbol((yyvsp[-4].id)->sym_p);

		    // Make sure it exists. This should belong in a later pass,
		    // but if we don't do it here and NULL is returned (which
		    // shouldn't happen if you've done everything right, but
		    // paranoia never hurts) the compiler would crash.
		    if(tmp == NULL || tmp->tag != SYM_CONST)
			type_error(pos) << "bad index in array declaration: "
				        << yytext << endl << flush;
		    else {
			constant_symbol *con = tmp->get_constant_symbol();
			if(con->type == integer_type) {
			    sym_tab->enter_array(pos,
						 (yyvsp[-8].pool_p),
						 (yyvsp[-1].id)->sym_p,
						 con->const_value.ival);
			} else {
			    sym_tab->enter_array(pos,
						 (yyvsp[-8].pool_p),
						 (yyvsp[-1].id)->sym_p,
						 ILLEGAL_ARRAY_CARD);
			}
		    }
		;}
    break;

  case 25:
#line 300 "parser.y"
    {
		    
		    symbol *env = sym_tab->get_symbol((yyvsp[-3].procedure_head)->sym_p);

		    if(!no_typecheck)
			type_checker->do_typecheck(env, (yyvsp[-1].statement_list));
		    
		    if(print_ast) {
			cout << "\nUnoptimized AST for \"" 
			     << sym_tab->pool_lookup(env->id)
			     << "\"" << endl;
			cout << (ast_stmt_list *)(yyvsp[-1].statement_list) << endl;
		    }

		    if(!no_optimize) {
			optimizer->do_optimize((yyvsp[-1].statement_list));
			if(print_ast) {
			    cout << "\nOptimized AST for \"" 
				 << sym_tab->pool_lookup(env->id)
				 << "\"" << endl;
			    cout << (ast_stmt_list*)(yyvsp[-1].statement_list) << endl;
			}
		    }
		    
                    if(error_count == 0) {
			if(!no_quads) {
			    quad_list *q = (yyvsp[-3].procedure_head)->do_quads((yyvsp[-1].statement_list));
			    if(print_quads) {
				cout << "\nQuad list for \""
				     << sym_tab->pool_lookup(env->id)
				     << "\"" << endl;
				cout << (quad_list *)q << endl;
			    }
			    
			    if(!no_assembler) {			
				cout << "Generating assembler for procedure \""
				     << sym_tab->pool_lookup(env->id)
				     << "\"" << endl;
				code_gen->generate_assembler(q, env);
			    }
			}
		    }
                    
		    // Close the current scope.
		    sym_tab->close_scope();
		;}
    break;

  case 26:
#line 347 "parser.y"
    {
		    
		    symbol *env = sym_tab->get_symbol((yyvsp[-3].function_head)->sym_p);

		    if(!no_typecheck)
			type_checker->do_typecheck(env, (yyvsp[-1].statement_list));
		    
		    if(print_ast) {
			cout << "\nUnoptimized AST for \"" 
			     << sym_tab->pool_lookup(env->id)
			     << "\"" << endl;
			cout << (ast_stmt_list *)(yyvsp[-1].statement_list) << endl;
		    }
		    
		    if(!no_optimize) {
			optimizer->do_optimize((yyvsp[-1].statement_list));
			if(print_ast) {			
			    cout << "\nOptimized AST for \"" 
				 << sym_tab->pool_lookup(env->id)
				 << "\"" << endl;
			    cout << (ast_stmt_list *)(yyvsp[-1].statement_list) << endl;
			}
		    }

		    if(error_count == 0) {
			if(!no_quads) {
			    quad_list *q = (yyvsp[-3].function_head)->do_quads((yyvsp[-1].statement_list));
			    if(print_quads) {
				cout << "\nQuad list for \""
				     << sym_tab->pool_lookup(env->id)
				     << "\"" << endl;
				cout << (quad_list *)q << endl;
			    }
			    
			    if(!no_assembler) {			
				cout << "Generating assembler for function \""
				     << sym_tab->pool_lookup(env->id) << "\""
				     << endl;
				code_gen->generate_assembler(q, env);
			    }
			}
		    }
                    
		    // Close the current scope.
		    sym_tab->close_scope();
		;}
    break;

  case 27:
#line 397 "parser.y"
    {
		    (yyval.procedure_head) = (yyvsp[-4].procedure_head);
		;}
    break;

  case 28:
#line 404 "parser.y"
    {
		    /* Your code here. */
		    
		;}
    break;

  case 29:
#line 412 "parser.y"
    {
		    position_information *pos =
			new position_information((yylsp[-1]).first_line,
			                         (yylsp[-1]).first_column);
		    // We add the function id to the symbol table.
		    sym_index proc_loc = sym_tab->enter_procedure(pos,
								  (yyvsp[0].pool_p));
		    // Open a new scope.
		    sym_tab->open_scope();
		    // This AST node is just a temporary node which we create
		    // here in order to be able to provide the symbol table
		    // index for the procedure to the proc_decl production
		    // above. It's needed for code generation.
		    (yyval.procedure_head) = new ast_procedurehead(pos,
					       proc_loc);
		;}
    break;

  case 30:
#line 432 "parser.y"
    {
		    position_information *pos =
			new position_information((yylsp[-1]).first_line,
			                         (yylsp[-1]).first_column);
		    // We add the function id to the symbol table.
		    sym_index func_loc = sym_tab->enter_function(pos,
								 (yyvsp[0].pool_p));
		    // Open a new scope.
		    sym_tab->open_scope();

		    // This AST node is just a temporary node which we create
		    // here in order to be able to provide the symbol table
		    // index for the function to the func_decl production
		    // above. We need it to be able to set the return type
		    // and also later on for code generation.
		    (yyval.function_head) = new ast_functionhead(pos,
					      func_loc);
		;}
    break;

  case 31:
#line 454 "parser.y"
    {
		    /* Your code here. */
		;}
    break;

  case 32:
#line 458 "parser.y"
    {
		    (yyval.expression_list) = NULL;
		;}
    break;

  case 33:
#line 462 "parser.y"
    {
		    /* Your code here. */
		    
		;}
    break;

  case 34:
#line 470 "parser.y"
    {
		    /* Note that we use expr_lists for parameters. This
		       is thus simply a place-holder in the grammar. */
		;}
    break;

  case 35:
#line 475 "parser.y"
    {
		;}
    break;

  case 36:
#line 481 "parser.y"
    {
		    position_information *pos =
			new position_information((yylsp[-2]).first_line,
			                         (yylsp[-2]).first_column);

		    // Enter parameter into the symbol table. The linking of
		    // parameters and things is taken care of in the
		    // enter_parameter function, which is worth taking a
		    // second look at.
		    sym_index param_loc =
			sym_tab->enter_parameter(pos,
						 (yyvsp[-2].pool_p),
						 (yyvsp[0].id)->sym_p);
		;}
    break;

  case 37:
#line 499 "parser.y"
    {
		    /* Your code here. */
		    
		;}
    break;

  case 38:
#line 507 "parser.y"
    {
		    /* Your code here. */
		    
		;}
    break;

  case 39:
#line 512 "parser.y"
    {
		    /* Your code here. */
		    
		;}
    break;

  case 40:
#line 520 "parser.y"
    {
		    /* Your code here. */
		    
		;}
    break;

  case 41:
#line 525 "parser.y"
    {
		    /* Your code here. */
		    
		;}
    break;

  case 42:
#line 530 "parser.y"
    {
		    /* Your code here. */
		    
		;}
    break;

  case 43:
#line 535 "parser.y"
    {
		    /* Your code here. */
		    
		;}
    break;

  case 44:
#line 540 "parser.y"
    {
		    /* Your code here. */
		    
		;}
    break;

  case 45:
#line 545 "parser.y"
    {
		    /* Your code here. */
		    
		;}
    break;

  case 46:
#line 551 "parser.y"
    {
		    /* Your code here. */
		    
		;}
    break;

  case 47:
#line 558 "parser.y"
    {
		    (yyval.lvalue) = (yyvsp[0].id);
		;}
    break;

  case 48:
#line 562 "parser.y"
    {
		    (yyval.lvalue) = new ast_indexed((yyvsp[-3].id)->pos,
					 (yyvsp[-3].id),
					 (yyvsp[-1].expression));
		;}
    break;

  case 49:
#line 568 "parser.y"
    {
		    (yyval.lvalue) = NULL;
		;}
    break;

  case 50:
#line 575 "parser.y"
    {
		    /* Your code here. */
		    
		;}
    break;

  case 51:
#line 580 "parser.y"
    {
		    /* Your code here. */
		    
		;}
    break;

  case 52:
#line 589 "parser.y"
    {
		    /* Your code here. */
		    
		;}
    break;

  case 53:
#line 594 "parser.y"
    {
		    /* Your code here. */
		    
		;}
    break;

  case 54:
#line 602 "parser.y"
    {
		    /* Your code here. */
		    
		;}
    break;

  case 55:
#line 610 "parser.y"
    {
		    /* Your code here. */
		    
		;}
    break;

  case 56:
#line 615 "parser.y"
    {
		    /* Your code here. */
		    
		;}
    break;

  case 57:
#line 623 "parser.y"
    {
		    /* Your code here. */
		    
		;}
    break;

  case 58:
#line 628 "parser.y"
    {
		    /* Your code here. */
		    
		;}
    break;

  case 59:
#line 636 "parser.y"
    {
		    /* Your code here. */
		    
		;}
    break;

  case 60:
#line 641 "parser.y"
    {
		    /* Your code here. */
		    
		;}
    break;

  case 61:
#line 649 "parser.y"
    {
		    /* Your code here. */
		    
		;}
    break;

  case 62:
#line 654 "parser.y"
    {
		    /* Your code here. */
		    		    
		;}
    break;

  case 63:
#line 659 "parser.y"
    {
		    /* Your code here. */
		    		    
		;}
    break;

  case 64:
#line 664 "parser.y"
    {
		    /* Your code here. */
		    		    
		;}
    break;

  case 65:
#line 669 "parser.y"
    {
		    /* Your code here. */
		    		    
		;}
    break;

  case 66:
#line 677 "parser.y"
    {
		    /* Your code here. */
		    		    
		;}
    break;

  case 67:
#line 682 "parser.y"
    {
		    /* Your code here. */
		    
		;}
    break;

  case 68:
#line 687 "parser.y"
    {
		    /* Your code here. */
		    
		;}
    break;

  case 69:
#line 692 "parser.y"
    {
		    /* Your code here. */
		    
		;}
    break;

  case 70:
#line 697 "parser.y"
    {
		    /* Your code here. */
		    
		;}
    break;

  case 71:
#line 702 "parser.y"
    {
		    /* Your code here. */
		    
		;}
    break;

  case 72:
#line 710 "parser.y"
    {
		    /* Your code here. */
		    
		;}
    break;

  case 73:
#line 715 "parser.y"
    {
		    /* Your code here. */
		    
		;}
    break;

  case 74:
#line 720 "parser.y"
    {
		    /* Your code here. */
		    
		;}
    break;

  case 75:
#line 725 "parser.y"
    {
		    /* Your code here. */
		    
		;}
    break;

  case 76:
#line 730 "parser.y"
    {
		    /* Your code here. */
		    
		;}
    break;

  case 77:
#line 735 "parser.y"
    {
		    /* Your code here. */
		    
		;}
    break;

  case 78:
#line 743 "parser.y"
    {
		    (yyval.expression) = (yyvsp[0].expression);
		;}
    break;

  case 79:
#line 747 "parser.y"
    {
		    (yyval.expression) = (yyvsp[0].function_call);
		;}
    break;

  case 80:
#line 751 "parser.y"
    {
		    (yyval.expression) = (yyvsp[0].integer);
		;}
    break;

  case 81:
#line 755 "parser.y"
    {
		    (yyval.expression) = (yyvsp[0].real);
		;}
    break;

  case 82:
#line 759 "parser.y"
    {
		    /* Your code here. */
		    
		;}
    break;

  case 83:
#line 764 "parser.y"
    {
		    /* Your code here. */
		    
		;}
    break;

  case 84:
#line 773 "parser.y"
    {
		    /* Your code here. */
		    
		;}
    break;

  case 85:
#line 782 "parser.y"
    {
		    position_information *pos =
			new position_information((yylsp[0]).first_line,
			                         (yylsp[0]).first_column);

		    // We need to pass on the value AND the position here.
		    (yyval.integer) = new ast_integer(pos,
					 (yyvsp[0].ival));
		;}
    break;

  case 86:
#line 795 "parser.y"
    {
		    position_information *pos =
			new position_information((yylsp[0]).first_line,
			                         (yylsp[0]).first_column);
		    
		    // We create a new real constant.
		    (yyval.real) = new ast_real(pos,
				      (yyvsp[0].rval));
		;}
    break;

  case 87:
#line 808 "parser.y"
    {
		    // Make sure this id is really declared as a type.
                    
		    if(sym_tab->get_symbol_tag((yyvsp[0].id)->sym_p) != SYM_NAMETYPE)
			type_error((yyvsp[0].id)->pos) << "not declared "
					    << "as type: "
					    << yytext << endl << flush;
		    (yyval.id) = (yyvsp[0].id);
		;}
    break;

  case 88:
#line 821 "parser.y"
    {
		    // Make sure this id is really declared as a constant.
		    
		    if(sym_tab->get_symbol_tag((yyvsp[0].id)->sym_p) != SYM_CONST)
			type_error((yyvsp[0].id)->pos) << "not declared "
					    << "as constant: "
					    << yytext << flush;
		    (yyval.id) = (yyvsp[0].id);
		;}
    break;

  case 89:
#line 834 "parser.y"
    {
		    // Make sure this id is really declared as an lvariable.
		    
		    if(sym_tab->get_symbol_tag((yyvsp[0].id)->sym_p) != SYM_VAR &&
		       sym_tab->get_symbol_tag((yyvsp[0].id)->sym_p) != SYM_PARAM)
			type_error((yyvsp[0].id)->pos) << "not declared "
					    << "as variable or parameter: "
					    << yytext << endl << flush;
		    (yyval.id) = (yyvsp[0].id);
		;}
    break;

  case 90:
#line 846 "parser.y"
    {
		    // Make sure this id is really declared as an rvariable.
		    
		    if(sym_tab->get_symbol_tag((yyvsp[0].id)->sym_p) != SYM_VAR &&
		       sym_tab->get_symbol_tag((yyvsp[0].id)->sym_p) != SYM_PARAM &&
		       sym_tab->get_symbol_tag((yyvsp[0].id)->sym_p) != SYM_CONST)
			type_error((yyvsp[0].id)->pos) << "not declared "
					    << "as variable, parameter or "
					    << "constant: "
					    << yytext << endl << flush;
		    (yyval.id) = (yyvsp[0].id);
		;}
    break;

  case 91:
#line 862 "parser.y"
    {
		    // Make sure this id is really declared as a procedure.
		    
		    if(sym_tab->get_symbol_tag((yyvsp[0].id)->sym_p) != SYM_PROC)
			type_error((yyvsp[0].id)->pos) << "not declared "
					    << "as procedure: "
					    << yytext << endl << flush;
		    (yyval.id) = (yyvsp[0].id);
		;}
    break;

  case 92:
#line 875 "parser.y"
    {
		    // Make sure this id is really declared as a function.
		    
		    if(sym_tab->get_symbol_tag((yyvsp[0].id)->sym_p) != SYM_FUNC)
			type_error((yyvsp[0].id)->pos) << "not declared "
					    << "as function: "
					    << yytext << endl << flush;
		    (yyval.id) = (yyvsp[0].id);
		;}
    break;

  case 93:
#line 888 "parser.y"
    {
		    // Make sure this id is really declared as an array.
		    
		    if(sym_tab->get_symbol_tag((yyvsp[0].id)->sym_p) != SYM_ARRAY)
			type_error((yyvsp[0].id)->pos) << "not declared "
					    << "as array: "
					    << yytext << endl << flush;
		    (yyval.id) = (yyvsp[0].id);
		;}
    break;

  case 94:
#line 901 "parser.y"
    {
		    sym_index sym_p;    // Used to find previous use of symbol.
		    position_information *pos =
			new position_information((yylsp[0]).first_line,
			                         (yylsp[0]).first_column);

		    // Make sure the symbol was declared before it is used.
		    sym_p = sym_tab->lookup_symbol((yyvsp[0].pool_p));
		    
		    if(sym_p == NULL_SYM)
			type_error(pos) << "not declared: "
				        << yytext << endl << flush;
		    // Create a new ast_id node with pos, symptr.
		    (yyval.id) = new ast_id(pos,
				    sym_p);
		    (yyval.id)->type = sym_tab->get_symbol_type(sym_p);
		;}
    break;


    }

/* Line 1037 of yacc.c.  */
#line 2259 "parser.cc"

  yyvsp -= yylen;
  yyssp -= yylen;
  yylsp -= yylen;

  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

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
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (YYPACT_NINF < yyn && yyn < YYLAST)
	{
	  YYSIZE_T yysize = 0;
	  int yytype = YYTRANSLATE (yychar);
	  const char* yyprefix;
	  char *yymsg;
	  int yyx;

	  /* Start YYX at -YYN if negative to avoid negative indexes in
	     YYCHECK.  */
	  int yyxbegin = yyn < 0 ? -yyn : 0;

	  /* Stay within bounds of both yycheck and yytname.  */
	  int yychecklim = YYLAST - yyn;
	  int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
	  int yycount = 0;

	  yyprefix = ", expecting ";
	  for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	      {
		yysize += yystrlen (yyprefix) + yystrlen (yytname [yyx]);
		yycount += 1;
		if (yycount == 5)
		  {
		    yysize = 0;
		    break;
		  }
	      }
	  yysize += (sizeof ("syntax error, unexpected ")
		     + yystrlen (yytname[yytype]));
	  yymsg = (char *) YYSTACK_ALLOC (yysize);
	  if (yymsg != 0)
	    {
	      char *yyp = yystpcpy (yymsg, "syntax error, unexpected ");
	      yyp = yystpcpy (yyp, yytname[yytype]);

	      if (yycount < 5)
		{
		  yyprefix = ", expecting ";
		  for (yyx = yyxbegin; yyx < yyxend; ++yyx)
		    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
		      {
			yyp = yystpcpy (yyp, yyprefix);
			yyp = yystpcpy (yyp, yytname[yyx]);
			yyprefix = " or ";
		      }
		}
	      yyerror (yymsg);
	      YYSTACK_FREE (yymsg);
	    }
	  else
	    yyerror ("syntax error; also virtual memory exhausted");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror ("syntax error");
    }

  yyerror_range[0] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* If at end of input, pop the error token,
	     then the rest of the stack, then return failure.  */
	  if (yychar == YYEOF)
	     for (;;)
	       {
                 yyerror_range[0] = *yylsp;
		 YYPOPSTACK;
		 if (yyssp == yyss)
		   YYABORT;
		 yydestruct ("Error: popping",
                             yystos[*yyssp], yyvsp, yylsp);
	       }
        }
      else
	{
	  yydestruct ("Error: discarding", yytoken, &yylval, &yylloc);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

#ifdef __GNUC__
  /* Pacify GCC when the user code never invokes YYERROR and the label
     yyerrorlab therefore never appears in user code.  */
  if (0)
     goto yyerrorlab;
#endif

  yyerror_range[0] = yylsp[1-yylen];
  yylsp -= yylen;
  yyvsp -= yylen;
  yyssp -= yylen;
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
      if (yyn != YYPACT_NINF)
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

      yyerror_range[0] = *yylsp;
      yydestruct ("Error: popping", yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK;
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;

  yyerror_range[1] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the look-ahead.  YYLOC is available though. */
  YYLLOC_DEFAULT (yyloc, yyerror_range - 1, 2);
  *++yylsp = yyloc;

  /* Shift the error token. */
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
  yydestruct ("Error: discarding lookahead",
              yytoken, &yylval, &yylloc);
  yychar = YYEMPTY;
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*----------------------------------------------.
| yyoverflowlab -- parser overflow comes here.  |
`----------------------------------------------*/
yyoverflowlab:
  yyerror ("parser stack overflow");
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  return yyresult;
}


#line 921 "parser.y"


