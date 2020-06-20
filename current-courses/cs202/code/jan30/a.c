#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void new_base(int x, int b, char *buffer);
void reverse_string(char *s);

int main(int argc, char *argv[])
{
    int x, b;

    if(argc != 3) {
        fprintf(stderr, "Usage: %s <decimal> <base>\n", argv[0]);
        exit(1);
    }

    x = atoi(argv[1]); 
    b = atoi(argv[2]);

    char buffer[100];
    new_base(x, b, buffer);
    printf("%s\n", buffer);

    return 0;
}

void new_base(int x, int b, char *buffer)
{
    if(b > 10) {
        printf("that's too hard...\n");
        return;
    }

    int index = 0;
    while(x != 0) {
        int y = x % b;
        buffer[index++] = '0' + y;
        x /= b;
    }
    buffer[index] = '\0';
    reverse_string(buffer);
}

// Reversing a string inplace
void reverse_string(char *s)
{
    int slen = strlen(s);
    char *t = (char *)malloc(slen + 1);
    strcpy(t, s);
    for(int i = slen - 1, j = 0; i >= 0; i--, j++) {
        s[j] = t[i];
    }
    free(t);
}

