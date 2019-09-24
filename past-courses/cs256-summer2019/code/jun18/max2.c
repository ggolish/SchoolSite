/*
 * Finds the maximum of three integers
 *
 */

#include <stdio.h>

int main(int argc, char *argv[])
{
  int x, y, z, max;

  printf("Enter the first number: ");
  scanf("%d", &x);

  printf("Enter the second number: ");
  scanf("%d", &y);

  printf("Enter the third number: ");
  scanf("%d", &z);

  // do stuff
  if(x > y) {
    max = x;
  } else {
    max = y;
  }

  if(z > max) {
    max = z;
  }
  
  printf("Max: %d\n", max);

  return 0;
}
