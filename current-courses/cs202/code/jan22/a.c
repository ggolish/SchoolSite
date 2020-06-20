#include <stdio.h>

int main(int argc, char *argv[])
{
    int k;
    scanf("%d", &k);

    int fact = 1;
    for(int i = 1; i <= k; i++) {
        fact *= i;
        printf("%d\n", fact);
    }

    return 0;
}
