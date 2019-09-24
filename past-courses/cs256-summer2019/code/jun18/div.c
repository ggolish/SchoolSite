/*
 * Checks if an integer is divisible by both 5 and 11
 *
 */

#include <stdio.h>

int main(int argc, char *argv[])
{
  int x;

  printf("Enter an integer: ");
  scanf("%d", &x);

  if((x % 5 == 0) && (x % 11 == 0)) {
    printf("yes\n");
  } else {
    printf("nope\n");
  }

  return 0;
}
