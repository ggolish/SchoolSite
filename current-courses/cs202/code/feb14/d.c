#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define K 1024
#define CHUNK 8

int main(int argc, char *argv[])
{
    char **list = NULL;
    int len = 0, cap = 0;

    char buffer[K];
    while(fgets(buffer, K, stdin) != NULL) {
        size_t sz = strlen(buffer);
        if(buffer[sz - 1] == '\n') {
            // buffer[--len] = '\0';
            buffer[sz - 1] = '\0';
            sz--;
        }
        // This is where we insert buffer into the array
        if(len > cap - 1) {
            cap = (cap == 0) ? CHUNK : cap * 2;
            list = (char **)realloc(list, cap * sizeof(char *));
        }

        list[len++] = strdup(buffer);
    }

    for(int i = 0; i < len; ++i) {
        printf("%s\n", list[i]);
    }

    return 0;
}
