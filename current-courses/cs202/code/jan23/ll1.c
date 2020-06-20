#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node_t;

// Function prototype
node_t *new_node(int data);
void print_ll(node_t *head);

int main(int argc, char *argv[])
{
    node_t *head = NULL;

    int x;
    while(scanf("%d", &x) == 1) {
        // Insert procedure
        node_t *tmp = new_node(x);
        tmp->next = head;
        head = tmp;
    }

    print_ll(head);

    return 0;
}

// Prints a linked list
void print_ll(node_t *head)
{
    node_t *curr = head;
    while(curr) {
        printf(" -> %d", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

// Creates a new node in memory, returns its address
node_t *new_node(int data)
{
    node_t *tmp = (node_t *)malloc(sizeof(node_t));
    
    // Handle error case when computer is out of memory
    if(tmp == NULL) {
        fprintf(stderr, "Error: no more memory.\n");
        return NULL;
    }

    // Short hand for (*tmp).data
    tmp->data = data;
    tmp->next = NULL;
    return tmp;
}
