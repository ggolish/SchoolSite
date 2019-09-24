#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10

int main(int argc, char *argv[])
{
  char s1[MAX_SIZE], s2[MAX_SIZE];

  scanf("%s", s1);
  scanf("%s", s2);

  int len1 = strlen(s1);
  int len2 = strlen(s2);

  int rv = strcmp(s1, s2);

  if(rv == 0) {
    printf("Equal.\n");
  } else if(rv < 0) {
    printf("%s: %d\n", s1, len1);
    printf("%s: %d\n", s2, len2);
  } else {
    printf("%s: %d\n", s2, len2);
    printf("%s: %d\n", s1, len1);
  }


  return 0;
}

