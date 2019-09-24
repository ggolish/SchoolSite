/*
 * Checks if an integer is positive, negative, or zero
 *
 */

#include <stdio.h>

int main(int argc, char *argv[])
{
  int x;

  printf("Enter an integer: ");
  scanf("%d", &x);

  if(x < 0) {
    printf("%d is negative.\n", x);
  } else if(x > 0) {
    printf("%d is positive.\n", x);
  } else {
    printf("zero\n");
  }

  return 0;
}
