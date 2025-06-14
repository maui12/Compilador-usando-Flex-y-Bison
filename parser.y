%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum { TIPO_ENTERO, TIPO_DECIMAL, TIPO_STRING } TipoVariable;

typedef struct {
    char nombre[32];
    TipoVariable tipo;
    union {
        int entero;
        float decimal;
        char string[128];
    };
} Variable;

Variable tablaSimbolos[100];
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
%token IF ELSE WHILE
%token IGUAL DIFERENTE MENOR MAYOR MENOR_IGUAL MAYOR_IGUAL
%token PRINT READ

%type <valorEntero> expr condicion

%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

%%

entrada:
    /* vacío */
  | entrada linea
;

linea:
    expr ';' { printf("Resultado válido\n"); }
  | declaracion ';'
  | asignacion ';'
  | funcion_io ';'
  | sentencia_control
  | sentencia_control ';'
;

asignacion:
    ID '=' expr {
        Variable* v = buscarVariable($1);
        if (v) {
            if (v->tipo == TIPO_ENTERO)
                v->entero = $3;
            else
                yyerror("Tipo no compatible para asignación");
        } else {
            yyerror("Variable no declarada");
        }
    }
;

declaracion:
    INT ID '=' NUMBER {
        agregarVariable($2, TIPO_ENTERO);
        Variable* v = buscarVariable($2);
        if (v) v->entero = $4;
        printf("Declarada variable int %s = %d\n", $2, $4);
    }
  | FLOAT ID '=' NUMBER {
        agregarVariable($2, TIPO_DECIMAL);
        Variable* v = buscarVariable($2);
        if (v) v->decimal = $4;
        printf("Declarada variable float %s = %d\n", $2, $4);
    }
  | STRING ID '=' STRING_LITERAL {
        agregarVariable($2, TIPO_STRING);
        Variable* v = buscarVariable($2);
        if (v) strcpy(v->string, $4);
        printf("Declarada variable string %s = %s\n", $2, $4);
    }
;

sentencia_control:
    IF '(' condicion ')' bloque %prec LOWER_THAN_ELSE
  | IF '(' condicion ')' bloque ELSE bloque
  | WHILE '(' condicion ')' bloque
;

bloque:
    '{' entrada '}'
;

funcion_io:
    PRINT '(' expr ')' {
        printf("Salida: %d\n", $3);
    }
  | READ '(' ID ')' {
        printf("Ingrese valor para %s: ", $3);
        int valor;
        scanf("%d", &valor);
        Variable* v = buscarVariable($3);
        if (v) v->entero = valor;
        else printf("Variable no declarada\n");
    }
;

condicion:
    expr IGUAL expr           { $$ = ($1 == $3); }
  | expr DIFERENTE expr       { $$ = ($1 != $3); }
  | expr MENOR expr           { $$ = ($1 < $3); }
  | expr MAYOR expr           { $$ = ($1 > $3); }
  | expr MENOR_IGUAL expr     { $$ = ($1 <= $3); }
  | expr MAYOR_IGUAL expr     { $$ = ($1 >= $3); }
;

expr:
    expr '+' expr   { $$ = $1 + $3; }
  | expr '-' expr   { $$ = $1 - $3; }
  | expr '*' expr   { $$ = $1 * $3; }
  | expr '/' expr   {
        if ($3 == 0) {
            yyerror("División por cero");
            $$ = 0;
        } else {
            $$ = $1 / $3;
        }
    }
  | NUMBER          { $$ = $1; }
  | ID {
        Variable* v = buscarVariable($1);
        if (v) {
            if (v->tipo == TIPO_ENTERO)
                $$ = v->entero;
            else {
                yyerror("Tipo no compatible en expresión (solo int)");
                $$ = 0;
            }
        } else {
            yyerror("Variable no declarada");
            $$ = 0;
        }
    }
;

%%

// Funciones auxiliares

void yyerror(const char *s) {
    fprintf(stderr, "Error sintactico: %s\n", s);
}

int main() {
    printf("Ingrese expresiones:\n");
    yyparse();
    return 0;
}

Variable* buscarVariable(const char* nombre) {
    for (int i = 0; i < cantidadVariables; i++) {
        if (strcmp(tablaSimbolos[i].nombre, nombre) == 0)
            return &tablaSimbolos[i];
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
