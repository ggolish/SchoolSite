#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node *left, *right;
} bnode_t;

bnode_t *new_bnode(int data);
bnode_t *bnode_insert(bnode_t *root, int data);
void bnode_inorder_print(bnode_t *n);
bnode_t *bnode_insert_recurse(bnode_t *tree, int data);
int count_leaves(bnode_t *tree);

int main(int argc, char *argv[])
{
    int x;
    bnode_t *root = NULL;

    while(scanf("%d", &x) == 1) {
       if(root == NULL) {
            root = new_bnode(x);
       } else {
            bnode_insert(root, x);
       }
    }

//     bnode_inorder_print(root);
    printf("%d\n", count_leaves(root));

    return 0;
}

bnode_t *new_bnode(int data)
{
    bnode_t *tmp = (bnode_t *)malloc(sizeof(bnode_t));
    tmp->data = data;
    tmp->left = tmp->right = NULL;
    return tmp;
}

bnode_t *bnode_insert(bnode_t *root, int data)
{
    bnode_t *n = new_bnode(data);
    bnode_t *tmp = root;
    if(!tmp) return NULL;
    for(;;) {
        if(n->data <= tmp->data) {
            // Go left
            if(tmp->left) {
                tmp = tmp->left;
            } else {
                tmp->left = n;
                return n;
            }
        } else {
            // Go right
            if(tmp->right) {
                tmp = tmp->right;
            } else {
                tmp->right = n;
                return n;
            }
        }
    }
}

bnode_t *bnode_insert_recurse(bnode_t *tree, int data)
{
    if(!tree) return NULL;

    bnode_t *n = NULL;
    if(data <= tree->data) {
        if(tree->left) {
            n = bnode_insert_recurse(tree->left, data);
        } else {
            n = new_bnode(data);
            tree->left = n;
        }
    } else {
        if(tree->right) {
            n = bnode_insert_recurse(tree->right, data);
        } else {
            n = new_bnode(data);
            tree->right = n;
        }
    }

    return n;
}

void bnode_inorder_print(bnode_t *n)
{
    if(!n) return;
    if(n->left) bnode_inorder_print(n->left);
    printf("%d\n", n->data);
    if(n->right) bnode_inorder_print(n->right);
}

int count_leaves(bnode_t *tree)
{
    if(!tree) return 0;
    int count = 0;
    int is_leaf = 1;
    if(tree->left) {
        count += count_leaves(tree->left);
        is_leaf = 0;
    }
    if(tree->right) {
        count += count_leaves(tree->right);
        is_leaf = 0;
    }
    return count + is_leaf;
}

