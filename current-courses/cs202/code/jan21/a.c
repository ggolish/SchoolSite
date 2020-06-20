#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int as = 1;
    int bs = n;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < as; j++) {
            printf("A");
        }
        for(int j = 0; j < bs; ++j) {
            printf("B");
        }
        printf("C");
        as++;
        bs--;
    }
    printf("\n");

    return 0;

