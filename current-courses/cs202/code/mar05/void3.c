#include <stdio.h>

// Pretend this is apart of some other file / library
void insert(void *a, void *b, int (*func)(void *, void *));

// This one is apart of our code, we know what the types really
int our_compare(void *a, void *b);

int main()
{
    int x = 5, y = 6;
    insert((void *)&x, (void *)&y, our_compare);
}

void insert(void *a, void *b, int (*func)(void *, void *))
{
    int cmp = func(a, b);
    if(cmp <= 0) {
        printf("insert left\n");
    } else {
        printf("insert right\n");
    }
}

int our_compare(void *a, void *b)
{
    int x = *((int *)a);
    int y = *((int *)b);
    return y - x;
}
