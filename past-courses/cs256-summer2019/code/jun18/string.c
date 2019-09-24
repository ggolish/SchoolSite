#include <stdio.h>

#define MAX_LENGTH 20

int main(int argc, char *argv[])
{
  char s[MAX_LENGTH] = "Hello";
  char s2[MAX_LENGTH] = {'H', 'e', 'l', 'l', 'o', '\0'};

  printf("s1: %s\n", s);
  printf("s2: %s\n", s2);
  
  return 0;
}
