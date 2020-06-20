#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

typedef struct node {
    char *data;
    struct node *next;
} node_t;

void die(const char *mesg);
node_t *new_node(char *data);
void print_ll(node_t *n);
int count_vowels(node_t *head);

int main(int argc, char *argv[])
{
    // Reading a dictionary
    FILE *fd = fopen("/usr/dict/words", "r");
    if(!fd) {
        die("Unable to open file for reading!");
    }

    node_t *head = NULL;
    char buffer[MAX_SIZE];
    while(fgets(buffer, MAX_SIZE, fd) != NULL) {
        node_t *tmp = new_node(buffer);
        tmp->next = head;
        head = tmp;
    }


    printf("%d\n", count_vowels(head));

    return 0;
}

node_t *new_node(char *data)
{
    node_t *tmp = (node_t *)malloc(sizeof(node_t));
    if(!tmp) {
        die("Malloc failed!");
        return NULL;
    }

    tmp->data = strdup(data);
    tmp->next = NULL;
    return tmp;
}

int count_vowels(node_t *head)
{
    // Loop through the list
    int count = 0;
    for(node_t *curr = head; curr; curr = curr->next) {
        switch(curr->data[0]) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                count++;
                break;
        }
    }
    return count;
}

void print_ll(node_t *n)
{
    if(!n) return;
    if(n->next) print_ll(n->next);
    printf("%s", n->data);
}

// Kill program
void die(const char *mesg)
{
    fprintf(stderr, "Error: %s\n", mesg);
    exit(1);
}

