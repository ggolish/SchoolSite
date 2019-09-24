#include <stdio.h>

#define MAX_LENGTH 20

int main(int argc, char *argv[])
{
  char s[MAX_LENGTH];

  printf("Enter your name: ");
  scanf("%s", s);

  printf("s1: %s\n", s);
  
  return 0;
}
