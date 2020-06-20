#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define K 1024

int main(int argc, char *argv[])
{
    FILE *fd = NULL;
    if(argc == 1) {
        fd = stdin;
    } else {
        fd = fopen(argv[1], "r");
        if(!fd) {
            fprintf(stderr, "Unable to open file '%s'\n", argv[1]);
            exit(1);
        }
    }

    char buffer[K];
    while(fgets(buffer, K, fd) != NULL) {
        size_t len = strlen(buffer);
        if(buffer[len - 1] == '\n') {
            // buffer[--len] = '\0';
            buffer[len - 1] = '\0';
            len--;
        }
        // This is where you would insert the buffer into your dictionary
        printf("%s\n", buffer);
    }

    fclose(fd);

    return 0;
}
