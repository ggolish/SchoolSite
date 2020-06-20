#ifndef LL_H_
#define LL_H_

#include <stdbool.h>

typedef struct node {
    void *data;
    struct node *next, *prev;
} node_t;

typedef struct {
    node_t *head, *tail;
    int len;
} list_t;

list_t *new_list();
void list_push_front(list_t *li, void *data);
void list_push_back(list_t *li, void *data);
void *list_pop_front(list_t *li);
void *list_pop_back(list_t *li);
bool list_is_empty(list_t *li);
void list_print(list_t *li);

#endif
