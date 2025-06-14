%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.tab.h"
%}

digit   [0-9]
letter  [a-zA-Z_]
id      {letter}({letter}|{digit})*

%%

[ \t\r]+               ; // ignorar espacios
\n ;  //Ignora los saltos de línea

"int"                  return INT;
"float"                return FLOAT;
"string"               return STRING;

"if"                   return IF;
"else"                 return ELSE;
"while"                return WHILE;
"print"                return PRINT;
"input"                return READ;

"=="                   return IGUAL;
"!="                   return DIFERENTE;
"<="                   return MENOR_IGUAL;
">="                   return MAYOR_IGUAL;
"<"                    return MENOR;
">"                    return MAYOR;

[0-9]+\.[0-9]+         { yylval.valorDecimal = atof(yytext); return NUMBER; }
[0-9]+                 { yylval.valorEntero = atoi(yytext); return NUMBER; }
\"[^\"]*\"             { yylval.valorString = strdup(yytext); return STRING_LITERAL; }
[a-zA-Z_][a-zA-Z0-9_]* { yylval.identificador = strdup(yytext); return ID; }

"="                    return '=';
"+"                    return '+';
"-"                    return '-';
"*"                    return '*';
"/"                    return '/';
"("                    return '(';
")"                    return ')';
"{"                    return '{';
"}"                    return '}';
";"                    return ';';

.                      return yytext[0];

%%

int yywrap(void) {
    return 1;
}