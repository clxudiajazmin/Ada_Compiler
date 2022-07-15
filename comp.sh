#!/bin/bash
bison -d parser.y
flex lexer.l
gcc parser.tab.c lex.yy.c
rm lex.yy.c parser.tab.c parser.tab.h
clear

echo '\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n----------RESULTADO----------\n'
./a.out ./pruebas/$1
