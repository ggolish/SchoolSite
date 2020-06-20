#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "btree.h"

#define K 1024

int compare_strings(void *a, void *b)
{
    return strcmp((char *)a, (char *)b);
}

void print_node(node_t *n) 
{
    if(!n) return;
    printf("%s %d\n", (char *)n->value, n->color);
}

int main(int argc, char *argv[])
{
    FILE *fd = fopen("/usr/dict/words", "r");
    if(!fd) {
        fprintf(stderr, "Unable to open '/usr/dict/words' for reading!\n");
        exit(1);
    }

    btree_t *bt = btree_new(compare_strings);
    char line[K];
    while(fgets(line, K, fd) != NULL) {
        line[strlen(line) - 1] = '\0';  // Overwriting the newline
        btree_insert(bt, line, true, strlen(line) * sizeof(char));
    }

    printf("depth: %d\n", btree_depth(bt));
    btree_inorder(bt, print_node);

    return 0;
}


