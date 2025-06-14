#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"

typedef struct {
    char *name;
    int value;
} Variable;

Variable variables[100];
int var_count = 0;

ASTNode *create_number_node(int value) {
    ASTNode *node = malloc(sizeof(ASTNode));
    node->type = NODE_TYPE_NUMBER;
    node->value = value;
    return node;
}

ASTNode *create_identifier_node(char *name) {
    ASTNode *node = malloc(sizeof(ASTNode));
    node->type = NODE_TYPE_IDENTIFIER;
    node->name = strdup(name);
    return node;
}

ASTNode *create_binary_op_node(char op, ASTNode *left, ASTNode *right) {
    ASTNode *node = malloc(sizeof(ASTNode));
    node->type = NODE_TYPE_BINARY_OP;
    node->binary_op.op = op;
    node->binary_op.left = left;
    node->binary_op.right = right;
    return node;
}

ASTNode *create_assignment_node(char *name, ASTNode *value) {
    ASTNode *node = malloc(sizeof(ASTNode));
    node->type = NODE_TYPE_ASSIGNMENT;
    node->assignment.name = strdup(name);
    node->assignment.value = value;
    return node;
}

ASTNode *create_if_node(ASTNode *condition, ASTNode *true_block, ASTNode *false_block) {
    ASTNode *node = malloc(sizeof(ASTNode));
    node->type = NODE_TYPE_IF;
    node->if_stmt.condition = condition;
    node->if_stmt.true_block = true_block;
    node->if_stmt.false_block = false_block;
    return node;
}

ASTNode *create_print_node(ASTNode *expression) {
    ASTNode *node = malloc(sizeof(ASTNode));
    node->type = NODE_TYPE_PRINT;
    node->expression = expression;
    return node;
}

ASTNode *create_block_node(ASTNode **statements, int count) {
    ASTNode *node = malloc(sizeof(ASTNode));
    node->type = NODE_TYPE_BLOCK;
    node->block.statements = statements;
    node->block.statement_count = count;
    return node;
}

ASTNode *create_while_node(ASTNode *condition, ASTNode *block) {
    ASTNode *node = malloc(sizeof(ASTNode));
    node->type = NODE_TYPE_WHILE;
    node->while_stmt.condition = condition;
    node->while_stmt.block = block;
    return node;
}

void free_ast(ASTNode *node) {
    if (!node) return;
    switch (node->type) {
        case NODE_TYPE_BINARY_OP:
            free_ast(node->binary_op.left);
            free_ast(node->binary_op.right);
            break;
        case NODE_TYPE_ASSIGNMENT:
            free(node->assignment.name);
            free_ast(node->assignment.value);
            break;
        case NODE_TYPE_IF:
            free_ast(node->if_stmt.condition);
            free_ast(node->if_stmt.true_block);
            free_ast(node->if_stmt.false_block);
            break;
        case NODE_TYPE_PRINT:
            free_ast(node->expression);
            break;
        case NODE_TYPE_IDENTIFIER:
            free(node->name);
            break;
        case NODE_TYPE_WHILE:
            free_ast(node->while_stmt.condition);
            free_ast(node->while_stmt.block);
            break;
        case NODE_TYPE_BLOCK:
            for (int i = 0; i < node->block.statement_count; i++) {
                free_ast(node->block.statements[i]);
            }
            free(node->block.statements);
            break;
        default:
            break;
    }
    free(node);
}

int get_variable_value(char *name) {
    for (int i = 0; i < var_count; i++) {
        if (strcmp(variables[i].name, name) == 0) {
            return variables[i].value;
        }
    }
    return 0;
}

void set_variable_value(char *name, int value) {
    for (int i = 0; i < var_count; i++) {
        if (strcmp(variables[i].name, name) == 0) {
            variables[i].value = value;
            return;
        }
    }
    variables[var_count].name = strdup(name);
    variables[var_count].value = value;
    var_count++;
}

int evaluate_ast(ASTNode *node) {
    if (!node) return 0;

    switch (node->type) {
        case NODE_TYPE_NUMBER:
            return node->value;
        case NODE_TYPE_IDENTIFIER:
            return get_variable_value(node->name);
        case NODE_TYPE_BINARY_OP: {
            int left = evaluate_ast(node->binary_op.left);
            int right = evaluate_ast(node->binary_op.right);
            switch (node->binary_op.op) {
                case '+': return left + right;
                case '-': return left - right;
                case '*': return left * right;
                case '/': return right != 0 ? left / right : 0;
                case '=': return left == right;
                case '!': return left != right;
                case '<': return left < right;
                case '>': return left > right;
                case 'l': return left <= right;
                case 'g': return left >= right;
                default: return 0;
            }
        }
        default:
            return 0;
    }
}

void execute_ast(ASTNode *node) {
    if (!node) return;

    switch (node->type) {
        case NODE_TYPE_ASSIGNMENT:
            set_variable_value(node->assignment.name, evaluate_ast(node->assignment.value));
            break;
        case NODE_TYPE_IF:
            if (evaluate_ast(node->if_stmt.condition)) {
                execute_ast(node->if_stmt.true_block);
            } else if (node->if_stmt.false_block) {
                execute_ast(node->if_stmt.false_block);
            }
            break;
        case NODE_TYPE_PRINT:
            printf("%d\n", evaluate_ast(node->expression));
            break;
        case NODE_TYPE_BLOCK:
            for (int i = 0; i < node->block.statement_count; i++) {
                execute_ast(node->block.statements[i]);
            }
            break;
        case NODE_TYPE_WHILE:
            while (evaluate_ast(node->while_stmt.condition)) {
                execute_ast(node->while_stmt.block);
            }
            break;
        default:
            break;
    }
}