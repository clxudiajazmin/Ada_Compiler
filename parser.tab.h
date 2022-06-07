
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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
     PUT = 310,
     GET = 311,
     NEW_LINE = 312,
     IDENT = 313,
     INTCONST = 314,
     FLOATCONST = 315,
     STRING = 316,
     CHARCONST = 317
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 28 "parser.y"

	// different types of values
	Value val;   
	
	// structures
	list_t* symtab_item;
	AST_Node* node;
	
	// for declarations
	int data_type;
	int const_type;
	



/* Line 1676 of yacc.c  */
#line 130 "parser.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


