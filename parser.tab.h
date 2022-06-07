/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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
     WHILE = 311,
     PUT = 312,
     GET = 313,
     NEW_LINE = 314,
     IDENT = 315,
     INTCONST = 316,
     FLOATCONST = 317,
     STRING = 318,
     CHARCONST = 319
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
#define WHILE 311
#define PUT 312
#define GET 313
#define NEW_LINE 314
#define IDENT 315
#define INTCONST 316
#define FLOATCONST 317
#define STRING 318
#define CHARCONST 319




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
/* Line 1529 of yacc.c.  */
#line 191 "parser.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

