#include <stdio.h>

// The first way: storing prvious characters

int main()
{
    char c = '\0', prev1 = '\0', prev2 = '\0';
    int count = 0;

    c = getchar();
    while(c != EOF) {
        if(c == ' ' && prev1 == '.' && prev2 >= '0' && prev2 <= '9') {
            count++;
        }
        prev2 = prev1;
        prev1 = c;
        c = getchar();
    }

    printf("%d\n", count);

    return 0;
}
