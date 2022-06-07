%option noyywrap

%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "symtab.h"
	#include "semantics.h"
	#include "ast.h"
	#include "parser.tab.h"
	extern FILE *yyin;
	extern FILE *yyout;
	
	int lineno = 1; // initialize to 1
	void ret_print(char *token_type);
	void yyerror();
%}

LETRA 			[a-zA-Z]
DIGITO 			[0-9]
PRINT			[ -~]
IDENT       	{LETRA}({LETRA}|{DIGITO})*(_({LETRA}|{DIGITO})*)*
INTCONST    	[+-]?{DIGITO}+
FLOATCONST  	[-+]?{DIGITO}+(.{DIGITO}+)?((E|e)[-+]?{DIGITO}+)?
STRING			\"{PRINT}*\"
CHARCONST		(\'{PRINT}\')|(\'\\[nftrbv]\')
%%

"--".*			{ printf("Comentario en linea %d\n", lineno); } 
"Character"     { return CHAR; }
"String"        { return STR; }
"Integer"       { return INT; }
"Float"         { return FLOAT; }

"First"         { return FIRST; }
"Last"          { return LAST; }
"Image"         { return IMAGE; }
"Value"         { return VALUE; }
"Min"           { return MIN; }
"Max"           { return MAX; }
"Pred"          { return PRED; }
"Succ"          { return SUCC; }

"procedure"     { return PROC; }
"is"            { return IS; }
"begin"         { return BEG; }
"end"           { return END; }

"+"				{ yylval.val.ival = ADD; return ADDOP; }
"-"				{ yylval.val.ival = SUB; return ADDOP; }
"*"				{ return MULOP; }
"/"				{ return DIVOP; }

"<"             { yylval.val.ival = LESS; return RELOP; }
">"             { yylval.val.ival = GREATER; return RELOP; }
"/="            { yylval.val.ival = NOT_EQUAL; return EQUOP; }
">="            { yylval.val.ival = GREATER_EQUAL; return RELOP; }
"<="            { yylval.val.ival = LESS_EQUAL; return RELOP; }
"="             { yylval.val.ival = EQUAL; return EQUOP; }

"&"             { return SEPARADOR; }
"and"           { return ANDOP; }
"or"            { return OROP; }
"not"			{ return NOTOP; }

":="            { return ASSIGN; }
":"             { return INI; }
"("				{ return LPAREN; }
")"				{ return RPAREN; }
"["				{ return LBRACK; }
"]"				{ return RBRACK; }
"{"				{ return LBRACE; }
"}"				{ return RBRACE; }
";"				{ return SEMI; }
"."				{ return DOT; }
","				{ return COMMA; }
".."			{ return TWOPOINTS; }
"\'"			{ return CHANGE; }


"type"          { return TYPE; }
"range"         { return RANGE; }
"array"			{ return ARRAY; }
"of" 			{ return OF; }
"new"			{ return NEW; }
"return"		{ return RET; }


"if"            { return IF; }
"then"          { return THEN; }
"else"          { return ELSE; }
"elsif"         { return ELSIF; }

"for"           { return FOR; }
"in"            { return IN; }
"loop"          { return LOOP; }
"reverse"          { return REVERSE; }

"Put_Line"		{ return PUT; }
"Get_Line"		{ return GET; }
"New_Line"		{ return NEW_LINE; }


{IDENT}         { 	insert(yytext, strlen(yytext), UNDEF, lineno);
        			yylval.symtab_item = lookup(yytext);
        			return IDENT;
				}
{INTCONST} 		{ yylval.val.ival = atoi(yytext); return INTCONST; }
{FLOATCONST} 	{ yylval.val.fval = atof(yytext); return FLOATCONST; }
{STRING} 		{ yylval.val.sval = malloc(yyleng * sizeof(char));
				   strcpy(yylval.val.sval, yytext);  return STRING;  
				}
{CHARCONST}		{ yylval.val.cval = yytext[1];    return CHARCONST; }


"\n"			{ lineno += 1; }

[ \t\r\f]+			/* eat up whitespace */

.				{ yyerror("No reconocido"); }

%%

