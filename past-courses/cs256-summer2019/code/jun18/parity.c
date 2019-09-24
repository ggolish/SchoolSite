/*
 * Checks if an integer is even or odd
 *
 */

#include <stdio.h>

int main(int argc, char *argv[])
{
  int x;

  printf("Enter an integer: ");
  scanf("%d", &x);

  if(x % 2 == 0) {
    printf("even\n");
  } else {
    printf("odd\n");
  }

  return 0;
}
