%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructura y tabla de símbolos
typedef enum { TIPO_ENTERO, TIPO_DECIMAL, TIPO_STRING} TipoVariable;

typedef struct {
    char nombre[32];
    TipoVariable tipo;
    union {
        int entero;
        float decimal;
        char string[128];
    };
} Variable;

Variable tablaSimbolos[100]; //lista que guarda todas las variables creadas
int cantidadVariables = 0;

int yylex(void);
void yyerror(const char *s);

Variable* buscarVariable(const char* nombre);
void agregarVariable(const char* nombre, TipoVariable tipo);
%}

%union {
    int valorEntero;
    float valorDecimal;
    char* valorString;
    char* identificador;
}

%token <valorEntero> NUMBER
%token <identificador> ID
%token <valorString> STRING_LITERAL
%token INT FLOAT STRING

%type <valorEntero> expr

%%



/*
Reglas gramaticales
*/
entrada:
    /* vacio */
    | entrada linea
    ;

linea:
    expr '\n'   { printf("Resultado valido\n"); }
  | declaracion '\n'
    ;

declaracion:
    INT ID '=' NUMBER {
        agregarVariable($2, TIPO_ENTERO);
        printf("Declarada variable int %s = %d\n", $2, $4);
    }
  | FLOAT ID '=' NUMBER {
        agregarVariable($2, TIPO_DECIMAL);
        printf("Declarada variable float %s = %d\n", $2, $4); //simplificado por ahora
    }
  | STRING ID '=' STRING_LITERAL {
        agregarVariable($2, TIPO_STRING);
        printf("Declarada variable string %s = %s\n", $2, $4);
    }
    ;

expr:
    expr '+' expr   { $$ = $1 + $3; }
  | expr '-' expr   { $$ = $1 - $3; }
  | expr '*' expr   { $$ = $1 * $3; }
  | expr '/' expr   { 
        if ($3 == 0) {
            yyerror("Division por cero");
            $$ = 0;
        } else {
            $$ = $1 / $3;
        }
    }
  | NUMBER          { $$ = $1; }
  ;

%%




//Funciones

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

// Tabla de símbolos

Variable* buscarVariable(const char* nombre) {
    for (int i = 0; i < cantidadVariables; i++) {
        if (strcmp(tablaSimbolos[i].nombre, nombre) == 0) {
            return &tablaSimbolos[i];
        }
    }
    return NULL;
}

void agregarVariable(const char* nombre, TipoVariable tipo) {
    if (buscarVariable(nombre)) {
        printf("Error: la variable '%s' ya fue declarada\n", nombre);
        return;
    }
    strcpy(tablaSimbolos[cantidadVariables].nombre, nombre);
    tablaSimbolos[cantidadVariables].tipo = tipo;
    cantidadVariables++;
}
