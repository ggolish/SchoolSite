#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

#define N   1024
#define K   1024
#define P   1057019 

typedef struct bucket {
    char *word;
    struct bucket *next;
} bucket_t;

int hash_fold(void *key, size_t sz);
int hash_insert(bucket_t **htable, char *key);
bucket_t *bucket_new(char *word);
void bucket_free(bucket_t *b);

int ncollisions = 0;

int main()
{
    // Building the hash table, statically sized
    bucket_t *htable[N];
    memset(htable, 0, N * sizeof(bucket_t *));

    // Insert all words from the dictionary into the table
    FILE *fd = fopen("/usr/dict/words", "r");
    if(!fd) {
        fprintf(stderr, "Unable to open dictionary file!\n");
        exit(1);
    }

    char line[K];
    int count = 0;
    while(fgets(line, K, fd) != NULL) {
        line[strlen(line) - 1] = '\0'; // removes newline
        if(hash_insert(htable, line)) {
            count++;
        }
    }

    printf("%0.2lf\n", (double)count / (double)ncollisions);

    return 0;
}

int hash_fold(void *key, size_t sz)
{
    uint8_t *bytes = (uint8_t *)key;
    int nbytes = sz / sizeof(uint8_t);
    
    int hash = 0;

    for(int i = nbytes - 1; i >= 0; i--) {
        hash ^= (P * bytes[i]);
    }

    return hash % N;
}

int hash_insert(bucket_t **htable, char *key)
{
    int len = strlen(key);
    int index = hash_fold((void *)key, len * sizeof(char));

    bucket_t *b = bucket_new(key);
    if(htable[index] == NULL) {
        htable[index] = b;
        return 1;
    }

    ncollisions++;

    // Checking for duplicates
    for(bucket_t *curr = htable[index]; curr; curr = curr->next) {
        if(strcmp(curr->word, b->word) == 0) {
            bucket_free(b);
            return 0;
        }
    }

    b->next = htable[index];
    htable[index] = b;
    return 1;
}

bucket_t *bucket_new(char *word)
{
    bucket_t *b = (bucket_t *)malloc(sizeof(bucket_t));
    b->word = strdup(word);
    b->next = NULL;
    return b;
}

void bucket_free(bucket_t *b)
{
    if(!b) return;
    if(b->word) free(b->word);
    free(b);
}
