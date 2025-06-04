%{
#include <stdio.h>
%}

%%

[0-9]+      { printf("Numero: %s\n", yytext); }
[a-zA-Z_][a-zA-Z0-9_]*   { printf("Identificador: %s\n", yytext); }
[ \t\n]+    ; // Ignorar espacios y saltos de línea
.           { printf("Caracter desconocido: %s\n", yytext); }

%%

int main(void) {
    yylex();
    return 0;
}

int yywrap(void) {
    return 1;
}