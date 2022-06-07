/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

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
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     CHAR = 258,
     STR = 259,
     INT = 260,
     FLOAT = 261,
     ADDOP = 262,
     MULOP = 263,
     DIVOP = 264,
     INCR = 265,
     OROP = 266,
     ANDOP = 267,
     NOTOP = 268,
     EQUOP = 269,
     RELOP = 270,
     FIRST = 271,
     LAST = 272,
     IMAGE = 273,
     VALUE = 274,
     MIN = 275,
     MAX = 276,
     PRED = 277,
     SUCC = 278,
     PROC = 279,
     IS = 280,
     BEG = 281,
     END = 282,
     SEPARADOR = 283,
     ASSIGN = 284,
     INI = 285,
     LPAREN = 286,
     RPAREN = 287,
     LBRACK = 288,
     RBRACK = 289,
     LBRACE = 290,
     RBRACE = 291,
     SEMI = 292,
     DOT = 293,
     COMMA = 294,
     CHANGE = 295,
     TYPE = 296,
     RANGE = 297,
     OF = 298,
     ARRAY = 299,
     TWOPOINTS = 300,
     NEW = 301,
     RET = 302,
     IF = 303,
     THEN = 304,
     ELSE = 305,
     ELSIF = 306,
     FOR = 307,
     IN = 308,
     LOOP = 309,
     REVERSE = 310,
     PUT = 311,
     GET = 312,
     NEW_LINE = 313,
     IDENT = 314,
     INTCONST = 315,
     FLOATCONST = 316,
     STRING = 317,
     CHARCONST = 318
   };
#endif
/* Tokens.  */
#define CHAR 258
#define STR 259
#define INT 260
#define FLOAT 261
#define ADDOP 262
#define MULOP 263
#define DIVOP 264
#define INCR 265
#define OROP 266
#define ANDOP 267
#define NOTOP 268
#define EQUOP 269
#define RELOP 270
#define FIRST 271
#define LAST 272
#define IMAGE 273
#define VALUE 274
#define MIN 275
#define MAX 276
#define PRED 277
#define SUCC 278
#define PROC 279
#define IS 280
#define BEG 281
#define END 282
#define SEPARADOR 283
#define ASSIGN 284
#define INI 285
#define LPAREN 286
#define RPAREN 287
#define LBRACK 288
#define RBRACK 289
#define LBRACE 290
#define RBRACE 291
#define SEMI 292
#define DOT 293
#define COMMA 294
#define CHANGE 295
#define TYPE 296
#define RANGE 297
#define OF 298
#define ARRAY 299
#define TWOPOINTS 300
#define NEW 301
#define RET 302
#define IF 303
#define THEN 304
#define ELSE 305
#define ELSIF 306
#define FOR 307
#define IN 308
#define LOOP 309
#define REVERSE 310
#define PUT 311
#define GET 312
#define NEW_LINE 313
#define IDENT 314
#define INTCONST 315
#define FLOATCONST 316
#define STRING 317
#define CHARCONST 318




/* Copy the first part of user declarations.  */
#line 2 "parser.y"

	#include "semantics.c"
	#include "symtab.c"
	#include "ast.h"
	#include "ast.c"
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	extern FILE *yyin;
	extern FILE *yyout;
	extern int lineno;
	extern int yylex();
	void yyerror();
	
	// for declarations
	void add_to_names(list_t *entry);
	list_t **names;
	int nc = 0;
	
	// for else ifs
	void add_elseif(AST_Node *elsif);
	AST_Node **elsifs;
	int elseif_count = 0;


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

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 28 "parser.y"
{
	// different types of values
	Value val;   
	
	// structures
	list_t* symtab_item;
	AST_Node* node;
	
	// for declarations
	int data_type;
	int const_type;
	
}
/* Line 193 of yacc.c.  */
#line 261 "parser.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 274 "parser.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
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
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   226

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  64
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  51
/* YYNRULES -- Number of states.  */
#define YYNSTATES  123

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   318

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,    15,    18,    20,    21,    26,    28,
      30,    32,    34,    38,    40,    42,    44,    46,    48,    51,
      53,    55,    57,    59,    61,    63,    65,    75,    84,    90,
      95,   100,   101,   113,   126,   132,   138,   141,   145,   149,
     153,   157,   161,   165,   169,   172,   176,   178,   181,   183,
     184,   189
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      65,     0,    -1,    66,    -1,    24,    59,    25,    67,    26,
      73,    27,    59,    37,    -1,    67,    68,    -1,    68,    -1,
      -1,    70,    30,    69,    37,    -1,     5,    -1,     3,    -1,
       6,    -1,    71,    -1,    70,    39,    71,    -1,    59,    -1,
      60,    -1,    61,    -1,    62,    -1,    63,    -1,    73,    74,
      -1,    74,    -1,    84,    -1,    75,    -1,    78,    -1,    79,
      -1,    80,    -1,    81,    -1,    48,    82,    49,    73,    76,
      77,    27,    48,    37,    -1,    48,    82,    49,    73,    77,
      27,    48,    37,    -1,    76,    51,    82,    49,    73,    -1,
      51,    82,    49,    73,    -1,    50,    82,    49,    73,    -1,
      -1,    52,    59,    53,    60,    45,    60,    54,    73,    27,
      54,    37,    -1,    52,    59,    53,    55,    60,    45,    60,
      54,    73,    27,    54,    37,    -1,    56,    31,    82,    32,
      37,    -1,    57,    31,    82,    32,    37,    -1,    58,    37,
      -1,    82,     7,    82,    -1,    82,     8,    82,    -1,    82,
       9,    82,    -1,    82,    12,    82,    -1,    82,    11,    82,
      -1,    82,    14,    82,    -1,    82,    15,    82,    -1,    13,
      82,    -1,    31,    82,    32,    -1,    85,    -1,    83,    72,
      -1,     7,    -1,    -1,    85,    29,    82,    37,    -1,    71,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    87,    87,    89,    92,    93,    94,    97,   116,   117,
     118,   121,   122,   126,   129,   130,   131,   132,   135,   140,
     146,   151,   156,   157,   158,   159,   163,   169,   175,   180,
     187,   193,   199,   211,   226,   229,   232,   235,   239,   243,
     247,   251,   255,   259,   263,   267,   271,   275,   305,   317,
     322,   329
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CHAR", "STR", "INT", "FLOAT", "ADDOP",
  "MULOP", "DIVOP", "INCR", "OROP", "ANDOP", "NOTOP", "EQUOP", "RELOP",
  "FIRST", "LAST", "IMAGE", "VALUE", "MIN", "MAX", "PRED", "SUCC", "PROC",
  "IS", "BEG", "END", "SEPARADOR", "ASSIGN", "INI", "LPAREN", "RPAREN",
  "LBRACK", "RBRACK", "LBRACE", "RBRACE", "SEMI", "DOT", "COMMA", "CHANGE",
  "TYPE", "RANGE", "OF", "ARRAY", "TWOPOINTS", "NEW", "RET", "IF", "THEN",
  "ELSE", "ELSIF", "FOR", "IN", "LOOP", "REVERSE", "PUT", "GET",
  "NEW_LINE", "IDENT", "INTCONST", "FLOATCONST", "STRING", "CHARCONST",
  "$accept", "program", "procedure", "declarations", "declaration", "type",
  "names", "name", "constant", "statements", "statement", "if_statement",
  "elsif_part", "else_part", "for_statement", "put_statement",
  "get_statement", "new_line_statement", "expression", "sign", "assigment",
  "var_ref", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    64,    65,    66,    67,    67,    67,    68,    69,    69,
      69,    70,    70,    71,    72,    72,    72,    72,    73,    73,
      74,    74,    74,    74,    74,    74,    75,    75,    76,    76,
      77,    77,    78,    78,    79,    80,    81,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    83,    83,
      84,    85
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     9,     2,     1,     0,     4,     1,     1,
       1,     1,     3,     1,     1,     1,     1,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     9,     8,     5,     4,
       4,     0,    11,    12,     5,     5,     2,     3,     3,     3,
       3,     3,     3,     3,     2,     3,     1,     2,     1,     0,
       4,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     0,     1,     6,    13,     0,     5,
       0,    11,     0,     4,     0,     0,    49,     0,     0,     0,
       0,    51,     0,    19,    21,    22,    23,    24,    25,    20,
       0,     9,     8,    10,     0,    12,    48,    49,    49,     0,
       0,    46,     0,    49,    49,    36,     0,    18,    49,     7,
      44,     0,    49,    49,    49,    49,    49,    49,    49,     0,
      14,    15,    16,    17,    47,     0,     0,     0,     0,     0,
      45,    37,    38,    39,    41,    40,    42,    43,    31,     0,
       0,     0,     0,     3,    50,    49,    49,    31,     0,     0,
       0,    34,    35,     0,     0,    49,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    30,    29,     0,
       0,    27,     0,     0,    28,    26,     0,     0,     0,     0,
       0,    32,    33
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,     8,     9,    34,    10,    21,    64,    22,
      23,    24,    87,    88,    25,    26,    27,    28,    39,    40,
      29,    41
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -57
static const yytype_int16 yypact[] =
{
     -23,   -20,    43,   -57,    24,   -57,    -7,   -57,   -24,   -57,
     -11,   -57,   149,   -57,   131,    -7,     1,    -1,    26,    31,
      28,   -57,    11,   -57,   -57,   -57,   -57,   -57,   -57,   -57,
      50,   -57,   -57,   -57,    35,   -57,   -57,     1,     1,    22,
     161,   -57,    45,     1,     1,   -57,    40,   -57,     1,   -57,
     -57,   145,     1,     1,     1,     1,     1,     1,     1,   149,
     -57,   -57,   -57,   -57,   -57,    -9,   154,   167,    70,   136,
     -57,    -4,   -57,   -57,   202,   211,    33,    76,   137,    27,
      58,    71,    72,   -57,   -57,     1,     1,   -35,    86,    74,
      62,   -57,   -57,    66,   109,     1,   101,    90,    89,    92,
     149,   149,   118,   107,   127,   116,   149,   149,   149,   149,
     134,   -57,   149,    34,   149,   -57,    83,   126,   129,   135,
     147,   -57,   -57
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -57,   -57,   -57,   -57,   182,   -57,   -57,     3,   -57,   -56,
      -2,   -57,   -57,   104,   -57,   -57,   -57,   -57,   -31,   -57,
     -57,   -12
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      30,     1,    12,    78,    53,    54,    50,    51,    36,    11,
      30,    11,    66,    67,    37,    85,    95,    69,    35,    14,
      47,    71,    72,    73,    74,    75,    76,    77,    15,    52,
      53,    54,    38,    55,    56,     7,    57,    58,    46,     4,
      52,    53,    54,     5,   107,   108,    79,    30,    58,     6,
     113,    80,     7,   114,    93,    94,   116,    43,    42,    16,
       7,   117,    44,    17,   102,    45,    30,    18,    19,    20,
       7,    59,    49,    52,    53,    54,    47,    55,    56,    48,
      57,    58,    16,    52,    53,    54,    17,    89,    30,    30,
      18,    19,    20,     7,    30,    30,    30,    30,    65,    68,
      30,    30,    30,    90,    30,    47,    47,    83,    91,    92,
     118,    47,    47,    97,    47,   100,    52,    53,    54,    98,
      55,    56,    99,    57,    58,    52,    53,    54,   103,    55,
      56,    16,    57,    58,    31,    17,    32,    33,   104,    18,
      19,    20,     7,    52,    53,    54,   106,    55,    56,   105,
      57,    58,    52,    53,    54,   110,    55,    56,   101,    57,
      58,    52,    53,    54,   111,    55,    56,   109,    57,    58,
     112,   115,   121,    84,    52,    53,    54,    70,    55,    56,
     119,    57,    58,   120,   122,    16,    81,    85,    86,    17,
      13,    96,     0,    18,    19,    20,     7,    16,     0,    82,
       0,    17,     0,     0,     0,    18,    19,    20,     7,    52,
      53,    54,     0,     0,    56,     0,    57,    58,    52,    53,
      54,    60,    61,    62,    63,    57,    58
};

static const yytype_int8 yycheck[] =
{
      12,    24,    26,    59,     8,     9,    37,    38,     7,     6,
      22,     8,    43,    44,    13,    50,    51,    48,    15,    30,
      22,    52,    53,    54,    55,    56,    57,    58,    39,     7,
       8,     9,    31,    11,    12,    59,    14,    15,    27,    59,
       7,     8,     9,     0,   100,   101,    55,    59,    15,    25,
     106,    60,    59,   109,    85,    86,   112,    31,    59,    48,
      59,    27,    31,    52,    95,    37,    78,    56,    57,    58,
      59,    49,    37,     7,     8,     9,    78,    11,    12,    29,
      14,    15,    48,     7,     8,     9,    52,    60,   100,   101,
      56,    57,    58,    59,   106,   107,   108,   109,    53,    59,
     112,   113,   114,    45,   116,   107,   108,    37,    37,    37,
      27,   113,   114,    27,   116,    49,     7,     8,     9,    45,
      11,    12,    60,    14,    15,     7,     8,     9,    27,    11,
      12,    48,    14,    15,     3,    52,     5,     6,    48,    56,
      57,    58,    59,     7,     8,     9,    54,    11,    12,    60,
      14,    15,     7,     8,     9,    48,    11,    12,    49,    14,
      15,     7,     8,     9,    37,    11,    12,    49,    14,    15,
      54,    37,    37,    37,     7,     8,     9,    32,    11,    12,
      54,    14,    15,    54,    37,    48,    32,    50,    51,    52,
       8,    87,    -1,    56,    57,    58,    59,    48,    -1,    32,
      -1,    52,    -1,    -1,    -1,    56,    57,    58,    59,     7,
       8,     9,    -1,    -1,    12,    -1,    14,    15,     7,     8,
       9,    60,    61,    62,    63,    14,    15
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    24,    65,    66,    59,     0,    25,    59,    67,    68,
      70,    71,    26,    68,    30,    39,    48,    52,    56,    57,
      58,    71,    73,    74,    75,    78,    79,    80,    81,    84,
      85,     3,     5,     6,    69,    71,     7,    13,    31,    82,
      83,    85,    59,    31,    31,    37,    27,    74,    29,    37,
      82,    82,     7,     8,     9,    11,    12,    14,    15,    49,
      60,    61,    62,    63,    72,    53,    82,    82,    59,    82,
      32,    82,    82,    82,    82,    82,    82,    82,    73,    55,
      60,    32,    32,    37,    37,    50,    51,    76,    77,    60,
      45,    37,    37,    82,    82,    51,    77,    27,    45,    60,
      49,    49,    82,    27,    48,    60,    54,    73,    73,    49,
      48,    37,    54,    73,    73,    37,    73,    27,    27,    54,
      54,    37,    37
};

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
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
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
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
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
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
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
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
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
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

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
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
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



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

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

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
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
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


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

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

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

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 7:
#line 98 "parser.y"
    {
		int i;
		(yyval.node) = new_ast_decl_node((yyvsp[(3) - (4)].data_type), names, nc);
		nc = 0;
		
		AST_Node_Decl *temp = (AST_Node_Decl*) (yyval.node);
		
		// declare types of the names
		for(i=0; i < temp->names_count; i++){
			// variable
			if(temp->names[i]->st_type == UNDEF){
				set_type(temp->names[i]->st_name, temp->data_type, UNDEF);
			}
		}
	;}
    break;

  case 8:
#line 116 "parser.y"
    { (yyval.data_type) = INT_TYPE;   ;}
    break;

  case 9:
#line 117 "parser.y"
    { (yyval.data_type) = CHAR_TYPE;   ;}
    break;

  case 10:
#line 118 "parser.y"
    { (yyval.data_type) = REAL_TYPE;   ;}
    break;

  case 11:
#line 121 "parser.y"
    { add_to_names((yyvsp[(1) - (1)].symtab_item)); ;}
    break;

  case 12:
#line 122 "parser.y"
    { add_to_names((yyvsp[(3) - (3)].symtab_item)); ;}
    break;

  case 13:
#line 126 "parser.y"
    { (yyval.symtab_item) = (yyvsp[(1) - (1)].symtab_item); ;}
    break;

  case 14:
#line 129 "parser.y"
    { (yyval.node) = new_ast_const_node(INT_TYPE, (yyvsp[(1) - (1)].val));  ;}
    break;

  case 15:
#line 130 "parser.y"
    { (yyval.node) = new_ast_const_node(REAL_TYPE, (yyvsp[(1) - (1)].val));  ;}
    break;

  case 16:
#line 131 "parser.y"
    { (yyval.node) = new_ast_const_node(CHAR_TYPE, (yyvsp[(1) - (1)].val));  ;}
    break;

  case 17:
#line 132 "parser.y"
    { (yyval.node) = new_ast_const_node(CHAR_TYPE, (yyvsp[(1) - (1)].val));  ;}
    break;

  case 18:
#line 136 "parser.y"
    {
		AST_Node_Statements *temp = (AST_Node_Statements*) (yyvsp[(1) - (2)].node);
		(yyval.node) = new_statements_node(temp->statements, temp->statement_count, (yyvsp[(2) - (2)].node));
	;}
    break;

  case 19:
#line 141 "parser.y"
    {
		(yyval.node) = new_statements_node(NULL, 0, (yyvsp[(1) - (1)].node));
	;}
    break;

  case 20:
#line 147 "parser.y"
    {
		(yyval.node) = (yyvsp[(1) - (1)].node); /* just pass information */
		ast_traversal((yyval.node)); /* just for testing */
	;}
    break;

  case 21:
#line 152 "parser.y"
    { 
		(yyval.node) = (yyvsp[(1) - (1)].node); /* just pass information */
		ast_traversal((yyval.node)); /* just for testing */
	;}
    break;

  case 22:
#line 156 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); /* just pass information */ ;}
    break;

  case 23:
#line 157 "parser.y"
    { (yyval.node) = NULL; /* will do it later ! */ ;}
    break;

  case 24:
#line 158 "parser.y"
    { (yyval.node) = NULL; /* will do it later ! */ ;}
    break;

  case 25:
#line 159 "parser.y"
    { (yyval.node) = NULL; /* will do it later ! */ ;}
    break;

  case 26:
#line 164 "parser.y"
    {
		(yyval.node) = new_ast_if_node((yyvsp[(2) - (9)].node), (yyvsp[(4) - (9)].node), elsifs, elseif_count, (yyvsp[(6) - (9)].node));
		elseif_count = 0;
		elsifs = NULL;
	;}
    break;

  case 27:
#line 170 "parser.y"
    {
		(yyval.node) = new_ast_if_node((yyvsp[(2) - (8)].node), (yyvsp[(4) - (8)].node), NULL, 0, (yyvsp[(5) - (8)].node));
	;}
    break;

  case 28:
#line 176 "parser.y"
    {
		AST_Node *temp = new_ast_elsif_node((yyvsp[(3) - (5)].node), (yyvsp[(5) - (5)].node));
		add_elseif(temp);
	;}
    break;

  case 29:
#line 181 "parser.y"
    {
		AST_Node *temp = new_ast_elsif_node((yyvsp[(2) - (4)].node), (yyvsp[(4) - (4)].node));
		add_elseif(temp);
	;}
    break;

  case 30:
#line 188 "parser.y"
    {
		/* else exists */
		(yyval.node) = (yyvsp[(2) - (4)].node);
	;}
    break;

  case 31:
#line 193 "parser.y"
    {
		/* no else */
		(yyval.node) = NULL;
	;}
    break;

  case 32:
#line 199 "parser.y"
    {
    /* create increment node*/
    AST_Node *incr_node;
    incr_node = new_ast_incr_node((yyvsp[(2) - (11)].symtab_item), 0, 0);
    AST_Node_Ref *temp = (AST_Node_Ref*) (yyvsp[(2) - (11)].symtab_item);
    assigment = new_ast_assign_node(temp->entry, temp->ref,(yyvsp[(4) - (11)].val));
    expresion =  new_ast_rel_node(1, (yyvsp[(2) - (11)].symtab_item), (yyvsp[(6) - (11)].val));


    (yyval.node) = new_ast_for_node(assigment, expresion, incr_node, (yyvsp[(8) - (11)].node));
    set_loop_counter((yyval.node));
;}
    break;

  case 33:
#line 211 "parser.y"
    {
    /* create increment node*/
    AST_Node *incr_node;
    incr_node = new_ast_incr_node((yyvsp[(2) - (12)].symtab_item), 1, 0);

    AST_Node_Ref *temp = (AST_Node_Ref*) (yyvsp[(2) - (12)].symtab_item);
    assigment = new_ast_assign_node(temp->entry, temp->ref,(yyvsp[(7) - (12)].val));
    expresion =  new_ast_rel_node(0, (yyvsp[(2) - (12)].symtab_item), (yyvsp[(5) - (12)].val));


    (yyval.node) = new_ast_for_node(assigment, expresion, incr_node, (yyvsp[(9) - (12)].node));
    set_loop_counter((yyval.node));
;}
    break;

  case 37:
#line 236 "parser.y"
    { 
	    (yyval.node) = new_ast_arithm_node((yyvsp[(2) - (3)].val).ival, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
	;}
    break;

  case 38:
#line 240 "parser.y"
    {
	    (yyval.node) = new_ast_arithm_node(MUL, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
	;}
    break;

  case 39:
#line 244 "parser.y"
    {
		(yyval.node) = new_ast_arithm_node(DIV, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
	;}
    break;

  case 40:
#line 248 "parser.y"
    {
		(yyval.node) = new_ast_bool_node(AND, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
	;}
    break;

  case 41:
#line 252 "parser.y"
    {
		(yyval.node) = new_ast_bool_node(OR, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
	;}
    break;

  case 42:
#line 256 "parser.y"
    {
		(yyval.node) = new_ast_equ_node((yyvsp[(2) - (3)].val).ival, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
	;}
    break;

  case 43:
#line 260 "parser.y"
    {
		(yyval.node) = new_ast_rel_node((yyvsp[(2) - (3)].val).ival, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
	;}
    break;

  case 44:
#line 264 "parser.y"
    {
	    (yyval.node) = new_ast_bool_node(NOT, (yyvsp[(2) - (2)].node), NULL);
	;}
    break;

  case 45:
#line 268 "parser.y"
    { 
		(yyval.node) = (yyvsp[(2) - (3)].node); /* just pass information */
	;}
    break;

  case 46:
#line 272 "parser.y"
    { 
		(yyval.node) = (yyvsp[(1) - (1)].node); /* just pass information */
	;}
    break;

  case 47:
#line 276 "parser.y"
    {
		/* sign */
		if((yyvsp[(1) - (2)].val).ival == 1){
			AST_Node_Const *temp = (AST_Node_Const*) (yyvsp[(2) - (2)].node);
		
			/* inverse value depending on the constant type */
			switch(temp->const_type){
				case INT_TYPE:
					temp->val.ival *= -1;
					break;
				case REAL_TYPE:
					temp->val.fval *= -1;
					break;
				case CHAR_TYPE:
					/* sign before char error */
					fprintf(stderr, "Error having sign before character constant!\n");
					exit(1);
					break;
			}
			
			(yyval.node) = (AST_Node*) temp;
		}
		/* no sign */
		else{
			(yyval.node) = (yyvsp[(2) - (2)].node);
		}
	;}
    break;

  case 48:
#line 306 "parser.y"
    { 
		/* plus sign error */
		if((yyvsp[(1) - (1)].val).ival == ADD){
			fprintf(stderr, "Error having plus as a sign!\n");
			exit(1);
		}
		else{
			(yyval.val).ival = 1; /* sign */
		}
	;}
    break;

  case 49:
#line 317 "parser.y"
    { 
		(yyval.val).ival = 0; /* no sign */
	;}
    break;

  case 50:
#line 323 "parser.y"
    {
	AST_Node_Ref *temp = (AST_Node_Ref*) (yyvsp[(1) - (4)].node);
	(yyval.node) = new_ast_assign_node(temp->entry, temp->ref, (yyvsp[(3) - (4)].node));
;}
    break;

  case 51:
#line 330 "parser.y"
    {
		(yyval.node) = new_ast_ref_node((yyvsp[(1) - (1)].symtab_item), 0); /* no reference */
	;}
    break;


/* Line 1267 of yacc.c.  */
#line 1937 "parser.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


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
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
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
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 334 "parser.y"


void add_to_names(list_t *entry){
	// first entry
	if(nc == 0){
		nc = 1;
		names = (list_t **) malloc( 1 * sizeof(list_t *));
		names[0] = entry;
	}
	// general case
	else{
		nc++;
		names = (list_t **) realloc(names, nc * sizeof(list_t *));
		names[nc - 1] = entry;		
	}
}

void add_elseif(AST_Node *elsif){
	// first entry
	if(elseif_count == 0){
		elseif_count = 1;
		elsifs = (AST_Node **) malloc(1 * sizeof(AST_Node));
		elsifs[0] = elsif;
	}
	// general case
	else{
		elseif_count++;
		elsifs = (AST_Node **) realloc(elsifs, elseif_count * sizeof(AST_Node));
		elsifs[elseif_count - 1] = elsif;
	}
}

void yyerror ()
{
  fprintf(stderr, "Error de sintaxis en linea %d\n", lineno);
  yylex();
  exit(1);
}

int main (int argc, char *argv[]){
	
	// initialize symbol table
	init_hash_table();
	
	// initialize revisit queue
	queue = NULL;
	
	// parsing
	int flag;
	yyin = fopen(argv[1], "r");
	flag = yyparse();
	fclose(yyin);
	
	printf("Parsing finished!\n");
	
	if(queue != NULL){
		printf("Warning: Something has not been checked in the revisit queue!\n");
	}
	
	// symbol table dump
	yyout = fopen("symtab_dump.out", "w");
	symtab_dump(yyout);
	fclose(yyout);
	
	// revisit queue dump
	yyout = fopen("revisit_dump.out", "w");
	revisit_dump(yyout);
	fclose(yyout);
	
	return flag;
}
