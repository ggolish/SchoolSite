#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define K 1024

typedef struct node {
    char *value;
    struct node *left, *right;
} node_t;

typedef struct {
    node_t *root;
    int size;
} btree_t;

node_t *node_new(char *value);
btree_t *btree_new();
void node_free(node_t *n, bool recurse);
void btree_free(btree_t *bt);

void btree_insert(btree_t *bt, char *value);
void btree_print(btree_t *bt);
void node_print(node_t *n);

int main(int argc, char *argv[])
{
    FILE *fd = fopen("/usr/dict/words", "r");
    if(!fd) {
        fprintf(stderr, "Unable to open '/usr/dict/words' for reading!\n");
        exit(1);
    }

    btree_t *bt = btree_new();
    char line[K];
    while(fgets(line, K, fd) != NULL) {
        line[strlen(line) - 1] = '\0';  // Overwriting the newline
        btree_insert(bt, line);
    }

    btree_print(bt);

    return 0;
}

node_t *node_new(char *value)
{
    node_t *n = (node_t *)malloc(sizeof(node_t));
    if(!n) {
        return NULL;
    }

    n->value = strdup(value);
    n->left = n->right = NULL;
    return n;
}

btree_t *btree_new()
{
    btree_t *bt = (btree_t *)malloc(sizeof(btree_t));
    if(!bt)
        return NULL;

    bt->root = NULL;
    bt->size = 0;
    return bt;
}

void node_free(node_t *n, bool recurse)
{
    if(!n) return;
    if(n->value) free(n->value);
    if(recurse) {
        if(n->left) node_free(n->left, recurse);
        if(n->right) node_free(n->right, recurse);
    }
    free(n);
}

void btree_free(btree_t *bt)
{
    if(!bt) return;
    if(bt->root) node_free(bt->root, true);
    free(bt);
}

void btree_insert(btree_t *bt, char *value)
{
    node_t *n = node_new(value);

    if(!bt->root) {
        bt->root = n;
        return;
    }

    node_t *curr = bt->root;
    for(;;) {
        int cmp = strcmp(n->value, curr->value);
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

void btree_print(btree_t *bt)
{
    node_print(bt->root);
}

void node_print(node_t *n)
{
    if(!n) return;
    if(n->left) node_print(n->left);
    printf("%s\n", n->value);
    if(n->right) node_print(n->right);
}
