#!/bin/bash
bison -d parser.y
flex lexer.l
gcc parser.tab.c lex.yy.c
rm lex.yy.c parser.tab.c
./a.out ./TESTS/MAL/$1
