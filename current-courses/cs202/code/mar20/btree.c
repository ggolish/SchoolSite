#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "btree.h"

static node_t *node_new(void *value, bool copy, size_t size);
static void node_inorder(node_t *n, void (*node_visit)(node_t *));
static void node_free(node_t *n, bool recurse);

btree_t *btree_new(int (*cmp_func) (void *, void*))
{
    btree_t *bt = (btree_t *)malloc(sizeof(btree_t));
    if(!bt)
        return NULL;

    bt->root = NULL;
    bt->size = 0;
    bt->cmp_func = cmp_func;
    return bt;
}

void btree_free(btree_t *bt)
{
    if(!bt) return;
    if(bt->root) node_free(bt->root, true);
    free(bt);
}

void btree_insert(btree_t *bt, void *value, bool copy, size_t size)
{
    node_t *n = node_new(value, copy, size);

    if(!bt->root) {
        bt->root = n;
        return;
    }

    node_t *curr = bt->root;
    for(;;) {
        int cmp = bt->cmp_func(n->value, curr->value);
        if(cmp < 0) {
            if(curr->left) {
                curr = curr->left;
            } else {
                curr->left = n;
                return;
            }
        } else if(cmp == 0) {
            node_free(n, false);
            return;
        } else {
            if(curr->right) {
                curr = curr->right;
            } else {
                curr->right = n;
                return;
            }
        }
    }
}

void btree_inorder(btree_t *bt, void (*node_visit)(node_t *n))
{
    if(!bt) return;
    node_inorder(bt->root, node_visit);
}

static node_t *node_new(void *value, bool copy, size_t size)
{
    node_t *n = (node_t *)malloc(sizeof(node_t));
    if(!n) {
        return NULL;
    }

    if(copy) {
        n->value = malloc(size);
        memcpy(n->value, value, size);
    } else {
        n->value = value;
    }

    n->is_copied = copy;
    n->left = n->right = NULL;
    return n;
}

static void node_free(node_t *n, bool recurse)
{
    if(!n) return;
    if(n->value && n->is_copied) free(n->value);
    if(recurse) {
        if(n->left) node_free(n->left, recurse);
        if(n->right) node_free(n->right, recurse);
    }
    free(n);
}

static void node_inorder(node_t *n, void (*node_visit)(node_t *))
{
    if(!n) return;
    if(n->left) node_inorder(n->left, node_visit);
    node_visit(n);
    if(n->right) node_inorder(n->right, node_visit);
}
