/*
 * Finds the maximum of two integers
 *
 */

#include <stdio.h>

int main(int argc, char *argv[])
{
  int x, y, max;

  printf("Enter the first number: ");
  scanf("%d", &x);

  printf("Enter the second number: ");
  scanf("%d", &y);

  // do stuff
//   if(x > y) {
//     max = x;
//   } else {
//     max = y;
//   }
  
  max = (x > y) ? x : y;
  
  printf("Max: %d\n", max);

  return 0;
}
