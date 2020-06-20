#include <stdio.h>

unsigned short reverse_bytes(unsigned short x);

int main(int argc, char *argv[])
{
    unsigned short x;
    scanf("%hd", &x);
    printf("0x%04x\n", x);
    x = reverse_bytes(x);
    printf("0x%04x\n", x);
    return 0;
}

unsigned short reverse_bytes(unsigned short x)
{
    return ((x >> 8) | (x << 8));
}
