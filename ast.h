#ifndef AST_H
#define AST_H

typedef struct ASTNode {
    char *node_type;
    char *value;
    int num_children;
    struct ASTNode **children;
} ASTNode;

ASTNode* create_node(const char *node_type, const char *value, int num_children, ...);
ASTNode* add_child(ASTNode *parent, ASTNode *child);
void print_ast(ASTNode *node, int level);
void free_ast(ASTNode *node);

#endif
