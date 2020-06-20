#include <stdio.h>
#include <stdint.h>

int main()
{
    int x = 10;
    void *addr = (void *)&x;
    uint8_t *bytes = (uint8_t *)addr;
    int nbytes = sizeof(int) / sizeof(uint8_t);

    for(int i = nbytes - 1; i >= 0; i--) {
        printf("0x%02x ", bytes[i]);
    }

    printf("\n");

    return 0;
}
