#include <stdio.h>

int main(int argc, char *argv[])
{
    int count = 0;

    char prev = '\0';
    char c;

    while((c = getchar()) != EOF) {
        if(prev >= '0' && prev <= '9') {
            if(c >= 'a' && c <= 'z') {
                count++;
            }
        }
        prev = c;
    }

    printf("%d\n", count);

    return 0;

}
