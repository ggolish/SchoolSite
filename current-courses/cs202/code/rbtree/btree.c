#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "btree.h"

static node_t *NIL_NODE = (node_t *)(-1);

static node_t *node_new(void *value, bool copy, size_t size, node_t *parent);
static void node_inorder(node_t *n, void (*node_visit)(node_t *));
static void node_free(node_t *n, bool recurse);
static int node_depth(node_t *tree);
static void fix_violations(node_t *n);
static void node_leftrotate(node_t *n);
static void node_rightrotate(node_t *n);
static color_t node_getcolor(node_t *n);
static node_t *node_getuncle(node_t *n);

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
    node_t *n = node_new(value, copy, size, NULL);

    if(!bt->root) {
        bt->root = n;
        bt->root->color = COLOR_BLACK;
        return;
    }

    node_t *curr = bt->root;
    for(;;) {
        int cmp = bt->cmp_func(n->value, curr->value);
        if(cmp < 0) {
            if(curr->left != NIL_NODE) {
                curr = curr->left;
            } else {
                curr->left = n;
                n->parent = curr;
                break;
            }
        } else if(cmp == 0) {
            node_free(n, false);
            return;
        } else {
            if(curr->right != NIL_NODE) {
                curr = curr->right;
            } else {
                curr->right = n;
                n->parent = curr;
                break;
            }
        }
    }

    fix_violations(n);
}

void btree_inorder(btree_t *bt, void (*node_visit)(node_t *n))
{
    if(!bt) return;
    node_inorder(bt->root, node_visit);
}

int btree_depth(btree_t *bt)
{
    if(!bt) return 0;
    return node_depth(bt->root);
}

static int node_depth(node_t *tree)
{
    if(!tree) return 0;
    int left_depth = 0, right_depth = 0;
    if(tree->left != NIL_NODE) left_depth = node_depth(tree->left);
    if(tree->right != NIL_NODE) right_depth = node_depth(tree->right);
    int max = (left_depth > right_depth) ? left_depth : right_depth;
    return max + 1;
}

static node_t *node_new(void *value, bool copy, size_t size, node_t *parent)
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
    n->color = COLOR_RED;
    n->left = n->right = NIL_NODE;
    n->parent = parent;
    return n;
}

static void node_free(node_t *n, bool recurse)
{
    if(!n) return;
    if(n->value && n->is_copied) free(n->value);
    if(recurse) {
        if(n->left != NIL_NODE) node_free(n->left, recurse);
        if(n->right != NIL_NODE) node_free(n->right, recurse);
    }
    free(n);
}

static void node_inorder(node_t *n, void (*node_visit)(node_t *))
{
    if(!n) return;
    if(n->left != NIL_NODE) node_inorder(n->left, node_visit);
    node_visit(n);
    if(n->right != NIL_NODE) node_inorder(n->right, node_visit);
}

static void fix_violations(node_t *n)
{
    if(!n) return;

    color_t n_color = node_getcolor(n);
    if(n_color == COLOR_BLACK) return;

    node_t *p = n->parent;

    // case 1: root is red (n is the root)
    if(!p) {
        n->color = COLOR_BLACK;
        return;
    }

    // If the parent is black, we do not have a violation.
    if(node_getcolor(p) == COLOR_BLACK) return;

    node_t *gp = p->parent;
    node_t *u = node_getuncle(n);

    if(!u) return;

    // case 2a: the uncle is red
    if(node_getcolor(u) == COLOR_RED) {
        gp->color = COLOR_RED;
        u->color = COLOR_BLACK;
        p->color = COLOR_BLACK;
        fix_violations(gp);
        return;
    }
    
    /* YOUR JOB: */
    // case 2b1: the uncle is black (left-left / right-right)
    if((p == gp->left && n == p->left) ||
       (p == gp->right && n == p->right)) {

    }
    
    // case 2b2: the uncle is black (left-right / right-left)
    if((p == gp->left && n == p->right) ||
       (p == gp->right && n == p->left)) {

    }
}

/* YOUR JOB: */
static void node_leftrotate(node_t *n)
{
}

/* YOUR JOB: */
static void node_rightrotate(node_t *n)
{
}

static color_t node_getcolor(node_t *n)
{
    if(n == NIL_NODE) return COLOR_BLACK;
    return n->color;
}

static node_t *node_getuncle(node_t *n)
{
    if(!n || !n->parent || !n->parent->parent) return NULL;
    node_t *p = n->parent;
    node_t *gp = n->parent->parent;
    if(p == gp->left) return gp->right;
    return gp->left;
}

