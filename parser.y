%{
#include <stdio.h>
#include <stdlib.h>

int yylex(void);
void yyerror(const char *s);
%}

%token NUMBER

%%
/*
Reglas gramaticales
*/
input:
    /* vacío */
    | input line
    ;

line:
    expr '\n'   { printf("Resultado valido\n"); }
    ;

expr:
    expr '+' expr   { }
  | expr '-' expr   { }
  | expr '*' expr   { }
  | expr '/' expr   { }
  | NUMBER
  ;

%%

//Cuando Bison detecta una entrada que no cumple las reglas gramaticales, se llama a yyerror()
void yyerror(const char *s) {
    fprintf(stderr, "Error sintactico: %s\n", s);
}

//Inicia el parser
int main() {
    printf("Ingrese expresiones:\n");
    yyparse();
    return 0;
}
