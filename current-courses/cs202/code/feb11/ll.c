#include <stdio.h>
#include <stdlib.h>

#include "ll.h"

static node_t *new_node(void *data, node_t *prev);

list_t *new_list()
{
    list_t *tmp = (list_t *)malloc(sizeof(list_t));
    if(!tmp) {
        fprintf(stderr, "Error: malloc failed!\n");
        return NULL;
    }   
    tmp->head = tmp->tail = NULL;
    tmp->len = 0;
    return tmp;
}

// Inserts a node at the beginning of a list
void list_push_front(list_t *li, void *data)
{
    node_t *n = new_node(data, NULL);
    if(list_is_empty(li)) {
        li->head = li->tail = n;
        return;
    }
    n->next = li->head;
    li->head->prev = n;
    li->head = n;
}

// Inserts a node at the end of a list
void list_push_back(list_t *li, void *data)
{
    if(list_is_empty(li)) {
        li->head = li->tail = new_node(data, NULL);
    }
    node_t *n = new_node(data, li->tail);
    li->tail->next = n;
    li->tail = n;
}

void *list_pop_front(list_t *li)
{
    if(list_is_empty(li)) {
        return NULL;
    }

    node_t *tmp = li->head;
    li->head = li->head->next;

    if(li->head == NULL) {
        li->tail = NULL;
    } else {
        li->head->prev = NULL;
    }

    void *data = tmp->data;
    free(tmp);
    return data;
}

void *list_pop_back(list_t *li)
{
    if(list_is_empty(li)) {
        return NULL;
    }

    node_t *tmp = li->tail;
    li->tail = li->tail->prev;
    if(li->tail == NULL) {
        li->head = NULL;
    } else {
        li->tail->next = NULL;
    }

    void *data = tmp->data;
    free(tmp);
    return data;
}

bool list_is_empty(list_t *li)
{
    return (li->head == NULL && li->tail == NULL);
}

void list_print(list_t *li)
{
    for(node_t *curr = li->head; curr; curr = curr->next) {
        printf("%p\n", curr->data);
    }
}

static node_t *new_node(void *data, node_t *prev)
{
    node_t *tmp = (node_t *)malloc(sizeof(node_t));
    if(!tmp) {
        fprintf(stderr, "Error: malloc failed!\n");
        return NULL;
    }   
    tmp->data = data;
    tmp->next = NULL;
    tmp->prev = prev;
    return tmp;
}
