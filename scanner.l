%{
#include <stdio.h>      //para funciones como atoi
#include "parser.tab.h" //conecta los tokens con el parser
%}

digit   [0-9]
letter  [a-zA-Z_]
id      {letter}({letter}|{digit})*

%%

[ \t\r]+               ; // Ignorar espacios
\n                     return '\n';
"int"                  return INT;
"float"                return FLOAT;
"string"               return STRING;
[0-9]+\.[0-9]+         { yylval.valorDecimal = atof(yytext); return NUMBER; }
[0-9]+                 { yylval.valorEntero = atoi(yytext); return NUMBER; }
\"[^\"]*\"             { yylval.valorString = strdup(yytext); return STRING_LITERAL; }
[a-zA-Z_][a-zA-Z0-9_]* { yylval.identificador = strdup(yytext); return ID; }
"+"                    return '+';
"-"                    return '-';
"*"                    return '*';
"/"                    return '/';
"="                    return '=';

.                      return yytext[0];

%%

int yywrap(void) {
    return 1;
}