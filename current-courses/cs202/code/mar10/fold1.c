#include <stdio.h>
#include <stdint.h>

#define NSECTIONS   4
#define BIGPRIME    17
#define TABLESZ     100

typedef
    unsigned int
uint_t;

int hash_fold(uint_t key);

int main(int argc, char *argv[])
{
    for(int i = 300; i < 310; i++) {
        printf("hashing %d...\n", i);
        int x = hash_fold(i);
        printf("hash is %d.\n\n", x);
    }
    return 0;
}

int hash_fold(uint_t key)
{
    int hash = 0;
    int sz = sizeof(uint_t) * 8;
    int currbit = sz;
    uint_t mask = 1 << (sz - 1);
    int secsz = sz / NSECTIONS;
    printf("Each section has %d bits...\n", secsz);
    for(int i = 0; i < NSECTIONS - 1; i++) {
        int curr_value = 0;
        for(int j = 0; j < secsz; j++) {
            if((mask & key)) {
                curr_value += (1 << (secsz - j - 1));
                printf("1");
            } else {
                printf("0");
            }
            mask >>= 1;
            currbit--;
        }
        printf("\n");
        printf("Found %d\n", curr_value);
        hash ^= (curr_value * BIGPRIME);
    }

    int curr_value = 0;
    for(int j = 0; j < currbit; j++) {
        if((mask & key)) {
            curr_value += (1 << (secsz - j - 1));
            printf("1");
        } else {
            printf("0");
        }
        mask >>= 1;
    }
    printf("\n");
    printf("Found %d\n", curr_value);
    hash ^= (curr_value * BIGPRIME);

    return hash % TABLESZ;
}
