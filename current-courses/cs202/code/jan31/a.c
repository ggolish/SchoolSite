#include <stdio.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    uint32_t x;

    scanf("%u", &x);

    int count = 0;
    for(uint32_t mask = 1; mask; mask <<= 1) {
        if((x & mask)) {
            // We found a 1
            count++;
        }
    }
//     uint32_t mask = 1;
//     while(mask) {
//         if((x & mask)) {
//             // We found a 1
//             count++;
//         }
//         mask <<= 1;
//     }

    printf("%d\n", count);

    return 0;
}
