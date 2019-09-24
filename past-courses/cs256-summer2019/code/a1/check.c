#include <stdio.h>

#define MAX_NAME 20

int main(int argc, char *argv[])
{
  char c;

  printf("Enter a character: ");
  scanf("%c", &c);

  printf("         %c\n", c);
  printf("        %c\n", c);
  printf("       %c\n", c);
  printf("%c     %c\n", c, c);
  printf(" %c   %c\n", c, c);
  printf("  %c %c\n", c, c);
  printf("   %c\n", c);

  return 0;
}
