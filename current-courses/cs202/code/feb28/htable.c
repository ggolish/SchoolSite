#include "htable.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static bucket_t *bucket_new(int key, int value);
static int hash_int(int key, int tbl_size);

htable_t *htable_new(int size)
{
    htable_t *ht = (htable_t *)malloc(sizeof(htable_t));
    if(!ht) {
        fprintf(stderr, "Malloc failed!\n");
        return NULL;
    }

    ht->tbl = (bucket_t **)malloc(size * sizeof(bucket_t *));
    memset(ht->tbl, 0, size * sizeof(bucket_t *));
    ht->tbl_cap = size;
    return ht;
}

void htable_free(htable_t *ht)
{
    if(!ht) return;
    if(ht->tbl) free(ht->tbl);
    free(ht);
}

void htable_insert(htable_t *ht, int key, int value)
{
    int index = hash_int(key, ht->tbl_cap);

    // They can have duplicate keys...
    bucket_t *b = bucket_new(key, value);
    b->next = ht->tbl[index];
    ht->tbl[index] = b;
}

bucket_t *htable_lookup(htable_t *ht, int key)
{
    int index = hash_int(key, ht->tbl_cap);

    for(bucket_t *b = ht->tbl[index]; b; b = b->next) {
        if(b->key == key) {
            return b;
        }
    }

    return NULL;
}

int htable_delete(htable_t *ht, int key)
{
    int index = hash_int(key, ht->tbl_cap);

    bucket_t *prev, *b;
    for(b = ht->tbl[index], prev = NULL; b; prev = b, b = b->next) {
        if(b->key == key) {
            if(!prev) {
                ht->tbl[index] = b->next;
            } else {
                prev->next = b->next;
            }
            free(b);
            return 1;
        }
    }

    return 0;
}

void htable_print(htable_t *ht)
{
    for(int i = 0; i < ht->tbl_cap; i++) {
        printf("%p\t", ht->tbl[i]);
        for(bucket_t *b = ht->tbl[i]; b; b = b->next) {
            if(b->next == NULL) {
                printf("(%d, %d)", b->key, b->value);
            } else {
                printf("(%d, %d) -> ", b->key, b->value);
            }
        }
        printf("\n");
    }
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

static int hash_int(int key, int tbl_size)
{
    return key % tbl_size;
}

