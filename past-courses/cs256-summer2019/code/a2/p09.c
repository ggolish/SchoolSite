#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
  char s[1024];

  scanf("%s", s);

  int i = 0;
  int j = strlen(s) - 1;

  while(i < j) {
    if(s[i] != s[j]) {
      printf("no\n");
      exit(0);
    }
    i++;
    j--;
  }

  printf("yes\n");

  return 0;
}

