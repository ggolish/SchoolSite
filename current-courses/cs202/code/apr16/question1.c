#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int acount = 2 * n, bcount = 2 * n - 1;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < acount; j++) {
            printf("A");
        }
        for(int j = 0; j < bcount; j++) {
            printf("B");
        }
        acount -= 2;
        bcount -= 2;
    }
    printf("\n");

    return 0;
}
