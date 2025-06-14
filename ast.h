#ifndef AST_H
#define AST_H

typedef enum { 
    NODE_TYPE_NUMBER,
    NODE_TYPE_IDENTIFIER,
    NODE_TYPE_BINARY_OP,
    NODE_TYPE_ASSIGNMENT,
    NODE_TYPE_IF,
    NODE_TYPE_ELSE,
    NODE_TYPE_PRINT,
    NODE_TYPE_BLOCK,
    NODE_TYPE_WHILE
} NodeType;

typedef struct ASTNode {
    NodeType type;
    union {
        int value;
        char *name;
        struct {
            struct ASTNode *left;
            struct ASTNode *right;
            char op;
        } binary_op;
        struct {
            char *name;
            struct ASTNode *value;
        } assignment;
        struct {
            struct ASTNode *condition;
            struct ASTNode *true_block;
            struct ASTNode *false_block;
        } if_stmt;
        struct ASTNode *expression;
        struct {
            struct ASTNode **statements;
            int statement_count;
        } block;
        struct {
            struct ASTNode *condition;
            struct ASTNode *block;
        } while_stmt;
    };
} ASTNode;

ASTNode *create_number_node(int value);
ASTNode *create_identifier_node(char *name);
ASTNode *create_binary_op_node(char op, ASTNode *left, ASTNode *right);
ASTNode *create_assignment_node(char *name, ASTNode *value);
ASTNode *create_if_node(ASTNode *condition, ASTNode *true_block, ASTNode *false_block);
ASTNode *create_print_node(ASTNode *expression);
ASTNode *create_block_node(ASTNode **statements, int count);
ASTNode *create_while_node(ASTNode *condition, ASTNode *block);

void free_ast(ASTNode *node);

int evaluate_ast(ASTNode *node);
void execute_ast(ASTNode *node);

#endif