#include "htable.h"

#include <stdlib.h>

static bucket_t *bucket_new(int key, int value);

htable_t *htable_new(int size)
{

}

void htable_free(htable_t *ht)
{
}

void htable_insert(htable_t *ht, int key, int value)
{
}

int htable_lookup(htable_t *ht, int key)
{
}

int htable_delete(htable_t *ht, int key)
{
}

static bucket_t *bucket_new(int key, int value)
{
    bucket_t *b = (bucket_t *)malloc(sizeof(bucket_t));

    if(!b) {
        fprintf(stderr, "Malloc failed!\n");
        return NULL;
    }

    b->key = key;
    b->value = value;
    b->next = NULL;
    return b;
}

