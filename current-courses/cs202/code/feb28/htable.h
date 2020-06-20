#ifndef HTABLE_H_
#define HTABLE_H_

typedef struct bucket {
    int key;
    int value;
    struct bucket *next;
} bucket_t;

typedef struct {
    int tbl_cap;
    bucket_t **tbl;
} htable_t;

htable_t *htable_new(int size);
void htable_free(htable_t *ht);
void htable_insert(htable_t *ht, int key, int value);
bucket_t *htable_lookup(htable_t *ht, int key);
int htable_delete(htable_t *ht, int key);
void htable_print(htable_t *ht);

#endif
