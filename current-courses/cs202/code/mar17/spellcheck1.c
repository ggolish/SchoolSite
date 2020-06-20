#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

#define N   1000
#define K   1024
#define P   1057019 

#define NWORDS      38619
#define NLOOKUP     10000000

typedef struct bucket {
    char *word;
    struct bucket *next;
} bucket_t;

int hash_fold(void *key, size_t sz);
int hash_insert(bucket_t **htable, char *key);
bucket_t *bucket_new(char *word);
char *htable_search(bucket_t **htable, char *word);
void bucket_free(bucket_t *b);
void print_htable(bucket_t **htable);
double timespec_to_seconds(struct timespec *ts);

int ncollisions = 0;

int main()
{
    // Building the hash table, statically sized
    bucket_t *htable[N];
    memset(htable, 0, N * sizeof(bucket_t *));
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
        if(hash_insert(htable, line)) {
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
        htable_search(htable, words[rand_index]);
    }

    clock_gettime(CLOCK_REALTIME, &end);
    end_time = timespec_to_seconds(&end);

    delta = end_time - start_time;
    printf("lookup time: %0.4lf\n", delta);

    printf("collision rate: %0.2lf\n", (double)ncollisions / (double)count);
    printf("load factor: %0.2lf\n", (double)count / (double)N);

    return 0;
}

double timespec_to_seconds(struct timespec *ts)
{
    return (double)ts->tv_sec + (double)(ts->tv_nsec / 10e9);
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

char *htable_search(bucket_t **htable, char *word)
{
    int index = hash_fold((void *)word, strlen(word) * sizeof(char));
    for(bucket_t *curr = htable[index]; curr; curr = curr->next) {
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

void bucket_free(bucket_t *b)
{
    if(!b) return;
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
