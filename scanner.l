%{
#include <stdio.h>      //para funciones como atoi
#include "parser.tab.h" //conecta los tokens con el parser
%}

%%

[0-9]+    { yylval = atoi(yytext); return NUMBER; }
[ \t]+    ; // Ignorar espacios
\n        { return '\n'; }
.         { return yytext[0]; }

%%

int yywrap(void) {
    return 1;
}