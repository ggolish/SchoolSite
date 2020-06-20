#include <stdio.h>

/*
 * This program finds the largest integers in stdin
 */

int main(int argc, char *argv[])
{
    int x;
    int max;

    // Reading all integers, finding the max
    scanf("%d", &max);
    while(scanf("%d", &x) == 1) {
       if(x > max) {
        max = x;
       }
    }

    printf("%d\n", max);

    return 0;
}
