%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"    

extern FILE *yyin;
void yyerror(const char *s);
int yylex(void);
%}

%union {
    int ival;
    float fval;
    char *sval;
    struct ASTNode *node;
}

%token INT FLOAT STRING READ
%token IF ELSE WHILE PRINT
%token IGUAL DIFERENTE MENOR_IGUAL MAYOR_IGUAL MENOR MAYOR
%token <ival> NUMBER
%token <sval> STRING_LITERAL
%token <sval> ID

%type <node> expression line block statement_list program

%left IGUAL DIFERENTE MENOR MAYOR MENOR_IGUAL MAYOR_IGUAL
%left '+' '-'
%left '*' '/'

%start program

%%

program:
    /* vacío */ { }
    | program line {
        execute_ast($2);
        free_ast($2);
    }
;

line:
      INT ID '=' expression ';'     { $$ = create_assignment_node($2, $4); }
    | FLOAT ID '=' expression ';'   { $$ = create_assignment_node($2, $4); }
    | STRING ID '=' expression ';'  { $$ = create_assignment_node($2, $4); }
    | ID '=' expression ';'         { $$ = create_assignment_node($1, $3); }
    | IF '(' expression ')' block ELSE block   { $$ = create_if_node($3, $5, $7); }
    | IF '(' expression ')' block              { $$ = create_if_node($3, $5, NULL); }
    | WHILE '(' expression ')' block           { $$ = create_while_node($3, $5); }
    | PRINT '(' expression ')' ';'             { $$ = create_print_node($3); }
;

block:
    '{' statement_list '}' { $$ = create_block_node($2->block.statements, $2->block.statement_count); }
;

statement_list:
      line {
        $$ = (ASTNode *)malloc(sizeof(ASTNode));
        $$->type = NODE_TYPE_BLOCK;
        $$->block.statements = (ASTNode **)malloc(sizeof(ASTNode *));
        $$->block.statements[0] = $1;
        $$->block.statement_count = 1;
    }
    | statement_list line {
        int count = $1->block.statement_count;
        $1->block.statements = (ASTNode **)realloc($1->block.statements, sizeof(ASTNode *) * (count + 1));
        $1->block.statements[count] = $2;
        $1->block.statement_count++;
        $$ = $1;
    }
;

expression:
      NUMBER                          { $$ = create_number_node($1); }
    | STRING_LITERAL                  { $$ = create_string_node($1); }
    | ID                              { $$ = create_identifier_node($1); }
    | expression '+' expression       { $$ = create_binary_op_node('+', $1, $3); }
    | expression '-' expression       { $$ = create_binary_op_node('-', $1, $3); }
    | expression '*' expression       { $$ = create_binary_op_node('*', $1, $3); }
    | expression '/' expression       { $$ = create_binary_op_node('/', $1, $3); }
    | expression IGUAL expression     { $$ = create_binary_op_node('=', $1, $3); }
    | expression DIFERENTE expression { $$ = create_binary_op_node('!', $1, $3); }
    | expression MENOR expression     { $$ = create_binary_op_node('<', $1, $3); }
    | expression MAYOR expression     { $$ = create_binary_op_node('>', $1, $3); }
    | expression MENOR_IGUAL expression { $$ = create_binary_op_node('l', $1, $3); }
    | expression MAYOR_IGUAL expression { $$ = create_binary_op_node('g', $1, $3); }
    | '(' expression ')'              { $$ = $2; }
;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}

int main(int argc, char *argv[]) {
    if (argc > 1) {
        yyin = fopen(argv[1], "r");
    } else {
        yyin = stdin;
    }

    yyparse();
    return 0;
}
