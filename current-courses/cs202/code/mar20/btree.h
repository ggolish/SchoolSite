#ifndef BTREE_H_
#define BTREE_H_

#include <stdbool.h>

typedef struct node {
    void *value;
    bool is_copied;
    struct node *left, *right;
} node_t;

typedef struct {
    node_t *root;
    int size;
    int (*cmp_func) (void *, void *); // User defined function
} btree_t;

btree_t *btree_new(int (*cmp_func) (void *, void*));
void btree_insert(btree_t *bt, void *value, bool copy, size_t size);
void btree_inorder(btree_t *bt, void (*node_visit)(node_t *n));
void btree_free(btree_t *bt);

#endif
