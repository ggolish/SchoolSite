#include <stdio.h>

// The first way: state machine
// state 1: looking for a number
// state 2: looking for a '.'
// state 3: looking for a ' ' 

int main()
{
    char c = '\0';
    int count = 0;
    int state = 1;

    c = getchar();
    while(c != EOF) {
        switch(state) {
            case 1:
                if(c >= '0' && c <= '9') state++;
                break;
            case 2:
                if(c == '.') state++;
                else state--;
                break;
            case 3:
                if(c == ' ') count++;
                state = 1;
                break;
        }
        c = getchar();
    }

    printf("%d\n", count);

    return 0;
}
