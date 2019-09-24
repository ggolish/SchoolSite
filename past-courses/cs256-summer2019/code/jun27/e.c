#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10

int main(int argc, char *argv[])
{
  char s1[MAX_SIZE];

  scanf("%s", s1);

  int len1 = strlen(s1);

  for(int i = 0; i < len1; i++) {
    printf("%c\n", s1[i]);
  }

  return 0;
}

