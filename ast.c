#include "ast.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

extern void yyerror(const char *s);

ASTNode* create_node(const char *node_type, const char *value, int num_children, ...) {
    ASTNode *node = (ASTNode*) malloc(sizeof(ASTNode));
    if (!node) {
        yyerror("Out of memory");
        exit(1);
    }
    node->node_type = strdup(node_type);
    node->value = value ? strdup(value) : NULL;
    node->num_children = num_children;
    if (num_children > 0) {
        node->children = (ASTNode**) malloc(num_children * sizeof(ASTNode*));
        va_list ap;
        va_start(ap, num_children);
        for (int i = 0; i < num_children; i++) {
            node->children[i] = va_arg(ap, ASTNode*);
        }
        va_end(ap);
    } else {
        node->children = NULL;
    }
    return node;
}

ASTNode* add_child(ASTNode *parent, ASTNode *child) {
    if (!child) return parent;
    parent->children = (ASTNode**) realloc(parent->children,
                                           (parent->num_children + 1) * sizeof(ASTNode*));
    parent->children[parent->num_children++] = child;
    return parent;
}

void print_ast(ASTNode *node, int level) {
    if (!node) return;
    for (int i = 0; i < level; i++) printf("  ");
    printf("%s", node->node_type);
    if (node->value) {
        printf(" (%s)", node->value);
    }
    printf("\n");

    for (int i = 0; i < node->num_children; i++) {
        print_ast(node->children[i], level + 1);
    }
}

void free_ast(ASTNode *node) {
    if (!node) return;
    for (int i = 0; i < node->num_children; i++) {
        free_ast(node->children[i]);
    }
    free(node->node_type);
    if (node->value) free(node->value);
    if (node->children) free(node->children);
    free(node);
}
