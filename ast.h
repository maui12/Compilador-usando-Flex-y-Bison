#ifndef AST_H
#define AST_H

typedef enum {
    TIPO_ENTERO,
    TIPO_FLOTANTE,
    TIPO_CADENA,
    TIPO_DESCONOCIDO
} TipoDato;

typedef struct Simbolo {
    char* nombre;
    TipoDato tipo;
    union {
        int entero;
        float flotante;
        char* cadena;
    } valor;
} Simbolo;

typedef struct NodoAST {
    int tipo_nodo;
    char* nombre;
    TipoDato tipo_dato;
    union {
        int entero;
        float flotante;
        char* cadena;
    } valor;
    struct NodoAST* izquierda;
    struct NodoAST* derecha;
    struct NodoAST* extra;
} NodoAST;

/* Funciones del AST */
NodoAST* crear_nodo(int tipo, NodoAST* izq, NodoAST* der, TipoDato tipo_dato);
NodoAST* crear_hoja(int tipo, char* valor, TipoDato tipo_dato);
void liberar_ast(NodoAST* nodo);
void ejecutar_ast(NodoAST* nodo);
int evaluar_condicion(NodoAST* cond);
float evaluar_expresion(NodoAST* expr);

#endif