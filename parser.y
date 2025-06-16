%{
#include "ast.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void yyerror(const char *s);
extern int yylex();

NodoAST* raiz_ast = NULL;

void imprimir_valor(Simbolo* s) {
    if (s->tipo == TIPO_ENTERO) {
        printf("%d\n", s->valor.entero);
    } else if (s->tipo == TIPO_FLOTANTE) {
        printf("%f\n", s->valor.flotante);
    } else if (s->tipo == TIPO_CADENA) {
        printf("%s\n", s->valor.cadena);
    }
}

int ejecutar = 1;
int ultima_condicion = 0;
%}

%union {
    int entero;
    float flotante;
    char* cadena;
    struct NodoAST* nodo;
}

%token <cadena> ENTERO FLOTANTE CADENA SI SINO MIENTRAS IMPRIMIR LEER ID POTENCIA
%token <entero> ENTERO_LIT
%token <flotante> FLOTANTE_LIT
%token <cadena> CADENA_LIT
%token AND OR NOT
%token IGUAL NO_IGUAL MENOR MAYOR MENOR_IGUAL MAYOR_IGUAL
%token '=' ','

%left OR
%left AND
%right NOT
%left '+' '-'
%left '*' '/'
%left IGUAL NO_IGUAL MENOR MAYOR MENOR_IGUAL MAYOR_IGUAL

%type <nodo> programa lista_declaraciones declaracion expresion condicion
%type <nodo> declaracion_entero declaracion_flotante declaracion_cadena
%type <nodo> asignacion si mientras imprimir leer bloque
%type <nodo> termino factor potencia_expr

%%

programa: lista_declaraciones { raiz_ast = $1; };

lista_declaraciones: 
    declaracion 
    | lista_declaraciones declaracion { $$ = crear_nodo(';', $1, $2, TIPO_DESCONOCIDO); };

declaracion: 
    declaracion_entero ';' { $$ = $1; }
    | declaracion_flotante ';' { $$ = $1; }
    | declaracion_cadena ';' { $$ = $1; }
    | asignacion ';' { $$ = $1; }
    | si
    | mientras
    | imprimir ';' { $$ = $1; }
    | leer ';' { $$ = $1; }
    | bloque;

declaracion_entero: ENTERO ID {
    Simbolo* existente = buscar_simbolo($2);
    if (!existente) {
        $$ = crear_nodo('D', crear_hoja(ID, $2, TIPO_ENTERO), NULL, TIPO_ENTERO);
        agregar_simbolo($2, TIPO_ENTERO);
    } else {
        $$ = NULL; // Variable ya existe, no crear nuevo nodo
    }
};

declaracion_flotante: FLOTANTE ID { 
    $$ = crear_nodo('D', crear_hoja(ID, $2, TIPO_FLOTANTE), NULL, TIPO_FLOTANTE);
    agregar_simbolo($2, TIPO_FLOTANTE);
};

declaracion_cadena: CADENA ID { 
    $$ = crear_nodo('D', crear_hoja(ID, $2, TIPO_CADENA), NULL, TIPO_CADENA);
    agregar_simbolo($2, TIPO_CADENA);
};

asignacion: ID '=' expresion { 
    $$ = crear_nodo('=', crear_hoja(ID, $1, TIPO_DESCONOCIDO), $3, TIPO_DESCONOCIDO);
    /* Verificar que la variable existe */
    Simbolo* s = buscar_simbolo($1);
    if (!s) {
        fprintf(stderr, "Error: Variable '%s' no declarada\n", $1);
        exit(EXIT_FAILURE);
    }
};

si: SI '(' condicion ')' bloque { 
    $$ = crear_nodo(SI, $3, $5, TIPO_DESCONOCIDO); 
    ultima_condicion = evaluar_condicion($3);
    ejecutar = ultima_condicion;
}
 | SI '(' condicion ')' bloque SINO bloque { 
    $$ = crear_nodo(SI, $3, $5, TIPO_DESCONOCIDO);
    $$->extra = $7;
    ultima_condicion = evaluar_condicion($3);
    ejecutar = ultima_condicion;
};

mientras: MIENTRAS '(' condicion ')' bloque { 
    $$ = crear_nodo(MIENTRAS, $3, $5, TIPO_DESCONOCIDO); 
};

bloque: '{' lista_declaraciones '}' { $$ = $2; }
      | '{' '}' { $$ = NULL; };

imprimir: IMPRIMIR '(' expresion ')' {
    if (ejecutar) {
        if ($3->tipo_nodo == ID) {
            Simbolo* s = buscar_simbolo($3->nombre);
            if (s) imprimir_valor(s);
        } else if ($3->tipo_nodo == ENTERO_LIT) {
            printf("%d\n", $3->valor.entero);
        } else if ($3->tipo_nodo == FLOTANTE_LIT) {
            printf("%f\n", $3->valor.flotante);
        } else if ($3->tipo_nodo == CADENA_LIT) {
            printf("%s\n", $3->valor.cadena);
        } else if ($3->tipo_nodo == POTENCIA) {
            int base = evaluar_expresion($3->izquierda);
            int exponente = evaluar_expresion($3->derecha);
            printf("%d\n", calcular_potencia(base, exponente));
        }
    }
    $$ = crear_nodo(IMPRIMIR, $3, NULL, TIPO_DESCONOCIDO);
};

leer: LEER ID { 
    $$ = crear_nodo(LEER, crear_hoja(ID, $2, TIPO_DESCONOCIDO), NULL, TIPO_DESCONOCIDO); 
    Simbolo* s = buscar_simbolo($2);
    if (!s) {
        fprintf(stderr, "Error: Variable '%s' no declarada\n", $2);
        exit(EXIT_FAILURE);
    }
    if (ejecutar) {
        if (s->tipo == TIPO_ENTERO) {
            scanf("%d", &s->valor.entero);
        } else if (s->tipo == TIPO_FLOTANTE) {
            scanf("%f", &s->valor.flotante);
        } else if (s->tipo == TIPO_CADENA) {
            char buffer[256];
            scanf("%255s", buffer);
            if (s->valor.cadena) free(s->valor.cadena);
            s->valor.cadena = strdup(buffer);
        }
    }
};

condicion: expresion IGUAL expresion { $$ = crear_nodo(IGUAL, $1, $3, TIPO_DESCONOCIDO); }
         | expresion NO_IGUAL expresion { $$ = crear_nodo(NO_IGUAL, $1, $3, TIPO_DESCONOCIDO); }
         | expresion MENOR expresion { $$ = crear_nodo(MENOR, $1, $3, TIPO_DESCONOCIDO); }
         | expresion MAYOR expresion { $$ = crear_nodo(MAYOR, $1, $3, TIPO_DESCONOCIDO); }
         | expresion MENOR_IGUAL expresion { $$ = crear_nodo(MENOR_IGUAL, $1, $3, TIPO_DESCONOCIDO); }
         | expresion MAYOR_IGUAL expresion { $$ = crear_nodo(MAYOR_IGUAL, $1, $3, TIPO_DESCONOCIDO); }
         | expresion AND expresion { $$ = crear_nodo(AND, $1, $3, TIPO_DESCONOCIDO); }
         | expresion OR expresion { $$ = crear_nodo(OR, $1, $3, TIPO_DESCONOCIDO); }
         | NOT expresion { $$ = crear_nodo(NOT, $2, NULL, TIPO_DESCONOCIDO); }
         | expresion { $$ = $1; };

expresion: expresion '+' termino { $$ = crear_nodo('+', $1, $3, TIPO_ENTERO); }
         | expresion '-' termino { $$ = crear_nodo('-', $1, $3, TIPO_ENTERO); }
         | termino { $$ = $1; };

termino: termino '*' factor { $$ = crear_nodo('*', $1, $3, TIPO_ENTERO); }
       | termino '/' factor { $$ = crear_nodo('/', $1, $3, TIPO_ENTERO); }
       | factor { $$ = $1; };

factor: '(' expresion ')' { $$ = $2; }
      | ENTERO_LIT { 
          $$ = crear_hoja(ENTERO_LIT, NULL, TIPO_ENTERO);
          $$->valor.entero = $1;
        }
      | FLOTANTE_LIT { 
          $$ = crear_hoja(FLOTANTE_LIT, NULL, TIPO_FLOTANTE);
          $$->valor.flotante = $1;
        }
      | CADENA_LIT { $$ = crear_hoja(CADENA_LIT, $1, TIPO_CADENA); }
      | ID { $$ = crear_hoja(ID, $1, TIPO_DESCONOCIDO); }
      | potencia_expr { $$ = $1; };

potencia_expr: POTENCIA '(' expresion ',' expresion ')' {
    $$ = crear_nodo(POTENCIA, $3, $5, TIPO_ENTERO);
};

%%

void yyerror(const char *s) {
    extern char *yytext;
    fprintf(stderr, "Error sintáctico en '%s': %s\n", yytext, s);
}

int main() {
    raiz_ast = NULL;
    yyparse();
    
    if (raiz_ast) {
        ejecutar_ast(raiz_ast);
        liberar_ast(raiz_ast);
    }
    
    return 0;
}