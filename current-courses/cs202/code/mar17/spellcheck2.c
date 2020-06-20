#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

#define N                   1000
#define K                   1024
#define P                   1057019 
#define MAX_LOAD_FACTOR     0.75

#define NWORDS      38619
#define NLOOKUP     10000000

typedef struct bucket {
    char *word;
    struct bucket *next;
} bucket_t;

typedef struct {
    bucket_t **table;
    int size;
    int cap;
    int ncollisions;
} htable_t;

htable_t *new_htable(int start_size);
int hash_fold(void *key, size_t sz, int table_size);
void check_resize(htable_t **ht);
int hash_insert(htable_t **ht, char *key);
bucket_t *bucket_new(char *word);
char *htable_search(htable_t *ht, char *word);
void htable_free(htable_t *ht);
void bucket_free(bucket_t *b);
void print_htable(bucket_t **htable);
double timespec_to_seconds(struct timespec *ts);

int main()
{
    // Building the hash table, statically sized
    htable_t *ht = new_htable(N);
    char *words[NWORDS];

    // Insert all words from the dictionary into the table
    FILE *fd = fopen("/usr/dict/words", "r");
    if(!fd) {
        fprintf(stderr, "Unable to open dictionary file!\n");
        exit(1);
    }

    struct timespec start, end;
    double start_time, end_time, delta;

    clock_gettime(CLOCK_REALTIME, &start);
    start_time = timespec_to_seconds(&start);
    char line[K];
    int count = 0;
    int index = 0;
    while(fgets(line, K, fd) != NULL) {
        line[strlen(line) - 1] = '\0'; // removes newline
        words[index++] = strdup(line);
        if(hash_insert(&ht, line)) {
            count++;
        }
    }
    clock_gettime(CLOCK_REALTIME, &end);
    end_time = timespec_to_seconds(&end);

    delta = end_time - start_time;
    printf("insertion time: %0.4lf\n", delta);

    clock_gettime(CLOCK_REALTIME, &start);
    start_time = timespec_to_seconds(&start);

    srand(2);
    for(int i = 0; i < NLOOKUP; i++) {
        int rand_index = rand() % NWORDS;
        htable_search(ht, words[rand_index]);
    }

    clock_gettime(CLOCK_REALTIME, &end);
    end_time = timespec_to_seconds(&end);

    delta = end_time - start_time;
    printf("lookup time: %0.4lf\n", delta);

    printf("collision rate: %0.2lf\n", (double)ht->ncollisions / (double)ht->size);
    printf("load factor: %0.2lf\n", (double)ht->size / (double)ht->cap);

    return 0;
}

double timespec_to_seconds(struct timespec *ts)
{
    return (double)ts->tv_sec + (double)(ts->tv_nsec / 10e9);
}

htable_t *new_htable(int start_size)
{
    htable_t *ht = (htable_t *)malloc(sizeof(htable_t));
    ht->table = (bucket_t **)malloc(start_size * sizeof(bucket_t *));
    memset(ht->table, 0, start_size * sizeof(bucket_t *));
    ht->size = 0;
    ht->cap = start_size;
    ht->ncollisions = 0;
    return ht;
}

int hash_fold(void *key, size_t sz, int table_size)
{
    uint8_t *bytes = (uint8_t *)key;
    int nbytes = sz / sizeof(uint8_t);
    
    int hash = 0;

    for(int i = nbytes - 1; i >= 0; i--) {
        hash ^= (P * bytes[i]);
    }

    return hash % table_size;
}

void check_resize(htable_t **ht)
{
    double l = (double)(*ht)->size / (double)(*ht)->cap;
    if(l < MAX_LOAD_FACTOR) return;

    printf("RESIZING!\n");

    // Make a new table, twice the size
    htable_t *new_ht = new_htable((*ht)->cap * 2);

    // Rehash from old table
    for(int i = 0; i < (*ht)->cap; i++) {
        for(bucket_t *curr = (*ht)->table[i]; curr; curr = curr->next) {
            hash_insert(&new_ht, curr->word); 
        }
    }

    htable_free(*ht);
    (*ht) = new_ht;
}

int hash_insert(htable_t **ht, char *key)
{
    check_resize(ht);
    int len = strlen(key);
    int index = hash_fold((void *)key, len * sizeof(char), (*ht)->cap);

    bucket_t *b = bucket_new(key);
    if((*ht)->table[index] == NULL) {
        (*ht)->table[index] = b;
        (*ht)->size++;
        return 1;
    }

    // Checking for duplicates
    for(bucket_t *curr = (*ht)->table[index]; curr; curr = curr->next) {
        if(strcmp(curr->word, b->word) == 0) {
            bucket_free(b);
            return 0;
        }
    }

    (*ht)->ncollisions++;
    b->next = (*ht)->table[index];
    (*ht)->table[index] = b;
    (*ht)->size++;
    return 1;
}

char *htable_search(htable_t *ht, char *word)
{
    int index = hash_fold((void *)word, strlen(word) * sizeof(char), ht->cap);
    for(bucket_t *curr = ht->table[index]; curr; curr = curr->next) {
        if(strcmp(curr->word, word) == 0) {
            return curr->word;
        }
    }
    return NULL;
}

bucket_t *bucket_new(char *word)
{
    bucket_t *b = (bucket_t *)malloc(sizeof(bucket_t));
    b->word = strdup(word);
    b->next = NULL;
    return b;
}

void htable_free(htable_t *ht)
{
    if(!ht) return;
    for(int i = 0; i < ht->cap; i++) {
        bucket_free(ht->table[i]);
    }
    free(ht);
}

void bucket_free(bucket_t *b)
{
    if(!b) return;
    if(b->next) bucket_free(b->next);
    if(b->word) free(b->word);
    free(b);
}

void print_htable(bucket_t **htable)
{
    for(int i = 0; i < N; i++) {
        if(!htable[i]) printf("EMPTY");
        for(bucket_t *curr = htable[i]; curr; curr = curr->next) {
            printf("%s -> ", curr->word);
        }
        printf("\n");
    }
}
