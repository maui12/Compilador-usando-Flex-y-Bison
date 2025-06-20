#include "ast.h"
#include "parser.tab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Implementación de la tabla de símbolos */
Simbolo tabla_simbolos[MAX_VARS];
int num_simbolos = 0;

NodoAST* crear_nodo(int tipo, NodoAST* izq, NodoAST* der, TipoDato tipo_dato) {
    NodoAST* nodo = (NodoAST*)malloc(sizeof(NodoAST));
    if (!nodo) {
        fprintf(stderr, "Error: No se pudo asignar memoria para el nodo AST\n");
        exit(EXIT_FAILURE);
    }

    nodo->tipo_nodo = tipo;
    nodo->izquierda = izq;
    nodo->derecha = der;
    nodo->extra = NULL;
    nodo->tipo_dato = tipo_dato;
    nodo->nombre = NULL;
    return nodo;
}

NodoAST* crear_hoja(int tipo, char* valor, TipoDato tipo_dato) {
    NodoAST* nodo = crear_nodo(tipo, NULL, NULL, tipo_dato);
    if (valor) {
        nodo->nombre = strdup(valor);
        if (!nodo->nombre) {
            fprintf(stderr, "Error: No se pudo asignar memoria para el nombre\n");
            exit(EXIT_FAILURE);
        }
    }
    return nodo;
}

void liberar_ast(NodoAST* nodo) {
    if (!nodo) return;

    liberar_ast(nodo->izquierda);
    liberar_ast(nodo->derecha);
    liberar_ast(nodo->extra);

    if (nodo->nombre) free(nodo->nombre);
    if (nodo->valor.cadena) free(nodo->valor.cadena);
    
    free(nodo);
}

Simbolo* buscar_simbolo(const char* nombre) {
    for (int i = 0; i < num_simbolos; i++) {
        if (strcmp(tabla_simbolos[i].nombre, nombre) == 0) {
            return &tabla_simbolos[i];
        }
    }
    return NULL;
}

void agregar_simbolo(const char* nombre, TipoDato tipo) {
    Simbolo* existente = buscar_simbolo(nombre);
    if (existente) {
        // Variable ya existe, actualiza el tipo si es diferente
        if (existente->tipo != tipo) {
            existente->tipo = tipo;
            // Limpia el valor anterior si es necesario
            if (existente->tipo == TIPO_CADENA && existente->valor.cadena) {
                free(existente->valor.cadena);
                existente->valor.cadena = NULL;
            }
        }
        return;  // No es un error, solo retorna
    }
    
    if (num_simbolos >= MAX_VARS) {
        fprintf(stderr, "Error: Tabla de símbolos llena\n");
        exit(EXIT_FAILURE);
    }
    
    tabla_simbolos[num_simbolos].nombre = strdup(nombre);
    tabla_simbolos[num_simbolos].tipo = tipo;
    num_simbolos++;
}

float evaluar_expresion(NodoAST* expr) {
    if (!expr) return 0;
    
    switch (expr->tipo_nodo) {
        case '+': return evaluar_expresion(expr->izquierda) + evaluar_expresion(expr->derecha);
        case '-': return evaluar_expresion(expr->izquierda) - evaluar_expresion(expr->derecha);
        case '*': return evaluar_expresion(expr->izquierda) * evaluar_expresion(expr->derecha);
        case '/': {
            float divisor = evaluar_expresion(expr->derecha);
            if (divisor == 0) {
                fprintf(stderr, "Error: División por cero\n");
                exit(EXIT_FAILURE);
            }
            return evaluar_expresion(expr->izquierda) / divisor;
        }
        case POTENCIA: {
            int base = (int)evaluar_expresion(expr->izquierda);
            int exponente = (int)evaluar_expresion(expr->derecha);
            return (float)calcular_potencia(base, exponente);
        }
        case ENTERO_LIT: return (float)expr->valor.entero;
        case FLOTANTE_LIT: return expr->valor.flotante;
        case ID: {
            Simbolo* s = buscar_simbolo(expr->nombre);
            if (!s) {
                fprintf(stderr, "Error: Variable '%s' no declarada\n", expr->nombre);
                exit(EXIT_FAILURE);
            }
            if (s->tipo == TIPO_ENTERO) return (float)s->valor.entero;
            if (s->tipo == TIPO_FLOTANTE) return s->valor.flotante;
            return 0;
        }
        default: return 0;
    }
}

int evaluar_condicion(NodoAST* cond) {
    if (!cond) return 0;
    
    float izq = evaluar_expresion(cond->izquierda);
    float der = evaluar_expresion(cond->derecha);
    
    switch (cond->tipo_nodo) {
        case IGUAL: return izq == der;
        case NO_IGUAL: return izq != der;
        case MENOR: return izq < der;
        case MAYOR: return izq > der;
        case MENOR_IGUAL: return izq <= der;
        case MAYOR_IGUAL: return izq >= der;
        case AND: return evaluar_condicion(cond->izquierda) && evaluar_condicion(cond->derecha);
        case OR: return evaluar_condicion(cond->izquierda) || evaluar_condicion(cond->derecha);
        case NOT: return !evaluar_condicion(cond->izquierda);
        case POTENCIA: {
            int base = (int)evaluar_expresion(cond->izquierda);
            int exponente = (int)evaluar_expresion(cond->derecha);
            return (float)calcular_potencia(base, exponente);
        }
        default: return evaluar_expresion(cond) != 0;
    }
}

void ejecutar_ast(NodoAST* nodo) {
    if (!nodo) return;

    switch (nodo->tipo_nodo) {
        case ';': // Secuencia
            ejecutar_ast(nodo->izquierda);
            ejecutar_ast(nodo->derecha);
            break;
            
        case 'D': // Declaración
            agregar_simbolo(nodo->izquierda->nombre, nodo->tipo_dato);
            break;
            
        case '=': {
            Simbolo* s = buscar_simbolo(nodo->izquierda->nombre);
            if (!s) {
                fprintf(stderr, "Error: Variable '%s' no declarada\n", nodo->izquierda->nombre);
                exit(EXIT_FAILURE);
            }
            
            float resultado = evaluar_expresion(nodo->derecha);
            
            if (s->tipo == TIPO_ENTERO) {
                s->valor.entero = (int)resultado;
            } else if (s->tipo == TIPO_FLOTANTE) {
                s->valor.flotante = resultado;
            }
            break;
        }
            
        case IMPRIMIR:
            if (nodo->izquierda) {
                if (nodo->izquierda->tipo_nodo == ID) {
                    Simbolo* s = buscar_simbolo(nodo->izquierda->nombre);
                    if (s) {
                        if (s->tipo == TIPO_ENTERO) {
                            printf("%d\n", s->valor.entero);
                        } else if (s->tipo == TIPO_FLOTANTE) {
                            printf("%f\n", s->valor.flotante);
                        } else if (s->tipo == TIPO_CADENA) {
                            printf("%s\n", s->valor.cadena);
                        }
                    }
                }
                else if (nodo->izquierda->tipo_nodo == ENTERO_LIT) {
                    printf("%d\n", nodo->izquierda->valor.entero);
                }
                else if (nodo->izquierda->tipo_nodo == FLOTANTE_LIT) {
                    printf("%f\n", nodo->izquierda->valor.flotante);
                }
                else if (nodo->izquierda->tipo_nodo == CADENA_LIT) {
                    printf("%s\n", nodo->izquierda->valor.cadena);
                }
            }
            break;
            
        case SI:
            if (evaluar_condicion(nodo->izquierda)) {
                ejecutar_ast(nodo->derecha);
            } else if (nodo->extra) {
                ejecutar_ast(nodo->extra);
            }
            break;
            
        case MIENTRAS:
            while (evaluar_condicion(nodo->izquierda)) {
                ejecutar_ast(nodo->derecha);
            }
            break;
            
        case LEER: {
            Simbolo* s = buscar_simbolo(nodo->izquierda->nombre);
            if (!s) {
                fprintf(stderr, "Error: Variable '%s' no declarada\n", nodo->izquierda->nombre);
                exit(EXIT_FAILURE);
            }
            
            printf("Ingrese valor para %s: ", nodo->izquierda->nombre);
            fflush(stdout);
            
            if (s->tipo == TIPO_ENTERO) {
                while (scanf("%d", &s->valor.entero) != 1) {
                    printf("Entrada inválida. Ingrese un número entero: ");
                    while (getchar() != '\n');
                }
            } 
            else if (s->tipo == TIPO_FLOTANTE) {
                while (scanf("%f", &s->valor.flotante) != 1) {
                    printf("Entrada inválida. Ingrese un número flotante: ");
                    while (getchar() != '\n');
                }
            } 
            else if (s->tipo == TIPO_CADENA) {
                char buffer[256];
                scanf("%255s", buffer);
                if (s->valor.cadena) free(s->valor.cadena);
                s->valor.cadena = strdup(buffer);
            }
            
            while (getchar() != '\n');  // Limpiar buffer de entrada
            break;
        }
            
        default:
            ejecutar_ast(nodo->izquierda);
            ejecutar_ast(nodo->derecha);
            break;
    }
}

/* Implementación de funciones matemáticas */
int calcular_suma(int a, int b) {
    return a + b;
}

int calcular_resta(int a, int b) {
    return a - b;
}

int calcular_multiplicacion(int a, int b) {
    return a * b;
}

int calcular_division(int a, int b) {
    if (b == 0) {
        fprintf(stderr, "Error: División por cero\n");
        exit(1);
    }
    return a / b;
}

//while potencia
int calcular_potencia(int base, int exponente) {
    int resultado = 1;
    while (exponente > 0) {
        resultado *= base;
        exponente--;
    }
    return resultado;
}