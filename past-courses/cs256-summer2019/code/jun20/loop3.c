#include <stdio.h>

int main(int argc, char *argv[])
{
  int max;

  printf("Enter an integer: ");
  scanf("%d", &max);

  // The current number
  int i = 0;
  int sum = 0;

  while(i <= max) {
    sum += i;
    i++;
  }

  printf("%d\n", sum);

  return 0;
}
