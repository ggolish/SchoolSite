#include <stdio.h>

int main()
{
    int x = 10;
    void *ptr = (void *)x;
    int y = (int)ptr;
    printf("%d\n", y);
    return 0;
}
