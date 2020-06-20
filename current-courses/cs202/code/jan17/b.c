#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if(argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(1);
    }
    
    FILE *fd = fopen(argv[1], "r");

    if(fd == NULL) {
        fprintf(stderr, "Error: Unable to open %s for reading.\n",
                argv[1]);
        exit(1);
    }

    int c;
    int line_count = 0;
    int char_count = 0;

    while((c = fgetc(fd)) != EOF) {
        char_count++;
        if(c == '\n') {
            line_count++;
        }
    }

    printf("%d %d %s\n", line_count, char_count, argv[1]);

    return 0;
}
