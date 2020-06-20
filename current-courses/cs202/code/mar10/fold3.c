#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define BIGPRIME    17
#define TABLESZ     100

int hash_fold(void *key, size_t sz);

int main(int argc, char *argv[])
{
    int x = 8;
    char s[] = "hello, world!";
    printf("%d\n", hash_fold((void *)&x, sizeof(int)));
    printf("%d\n", hash_fold((void *)s, strlen(s) * sizeof(char)));
}

int hash_fold(void *key, size_t sz)
{
    uint8_t *bytes = (uint8_t *)key;
    int nbytes = sz / sizeof(uint8_t);
    
    int hash = 0;

    for(int i = nbytes - 1; i >= 0; i--) {
        hash ^= (BIGPRIME * bytes[i]);
    }

    return hash % TABLESZ;
}
