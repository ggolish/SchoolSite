#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1024

int main(int argc, char *argv[])
{
    char w1[MAX_SIZE];
    char w2[MAX_SIZE];

    scanf("%s", w1);
    scanf("%s", w2);

    int cmp = strcasecmp(w2, w1);
    if(cmp < 0) {
        // Insert to left
        printf("%s comes before %s in the alphabet\n", w2, w1);
    } else if(cmp == 0) {
        // I have found a match in dictionary lookup function
        printf("%s is the same as %s\n", w2, w1);
    } else {
        // Insert to the right
        printf("%s comes after %s in the alphabet\n", w2, w1);
    }

    return 0;
}
