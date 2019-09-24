/*
 * Prints the type of character inputed
 *
 */

#include <stdio.h>

int main(int argc, char *argv[])
{
  char c;

  printf("Enter a character: ");
  scanf("%c", &c);

  if((c >= 'a') && (c <= 'z')) {
    printf("lowercase\n");
  } else if((c >= 'A') && (c <= 'Z')) {
    printf("uppercase\n");
  } else if((c >= '0') && (c <= '9')) {
    printf("digit\n");
  } else {
    printf("special character\n");
  }

  return 0;
}
