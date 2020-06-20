
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int l;

    printf("Enter the length: ");

    int rv = scanf("%d", &l);

    if(rv != 1) {
        printf("Please enter a number!\n");
        exit(1);
    }

    int area = l * l;

    printf("The area is %d.\n", area);

    return 0;
}
