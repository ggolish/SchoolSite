#include <stdio.h>
#include <ctype.h>

#define MAX_WORD 1024

char *next_word();

int main(int argc, char *argv[])
{
    char *word;

    while((word = next_word()) != NULL) {
        // This is where I would spell check my word
        printf("%s\n", word);
    }

    return 0;
}

char *next_word()
{
    char c;
    static char buffer[MAX_WORD];
    int index = 0;

    while((c = getchar()) != EOF) {
        if(isalnum(c)) {
            buffer[index++] = c;
        } else {
            if(index > 0) {
                buffer[index] = '\0';
                return buffer;
            }
        }
    }

    return NULL;
}
