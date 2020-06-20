#include <stdio.h>

// typedef enum {
//     PLAYING,
//     PAUSED,
//     FINISHED
// } state_t;

int main(int argc, char *argv[])
{
    int state = 1;
    
    int count = 0;
    char oldc = getchar();
    char currc;
    while((currc = getchar()) != EOF) {
        if(oldc == ' ' && currc == 'A') {
            count++;
        }
        oldc = currc;
    }

    printf("%d\n", count);

    return 0;
}
