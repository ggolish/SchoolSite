#include <stdio.h>

int main(int argc, char *argv[])
{
    char c;
    int count = 0;
    while((c = getchar()) != EOF) {
//         switch(c) {
//             case ',':
//             case '.':
//             case ':':
//                 count++;
//                 break;
//         }

//         count += (c == ',' || c == ':' || c == '.');

        if(c == ',' || c == ':' || c == '.') 
            count++;
    }

    printf("%d\n", count);

    return 0;
}
