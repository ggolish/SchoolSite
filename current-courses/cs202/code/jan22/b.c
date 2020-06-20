#include <stdio.h>

// typedef enum {
//     PLAYING,
//     PAUSED,
//     FINISHED
// } state_t;

int main(int argc, char *argv[])
{
    int state = 1;
    
    char c;
    int count = 0;
    while((c = getchar()) != EOF) {
        switch(state) {
            case 1:
                if(c == ' ') state++;
                break;
            case 2:
                if(c == 'A') count++;
                if(c != ' ') state = 1;
                break;
        }
    }

    printf("%d\n", count);

    return 0;
}
