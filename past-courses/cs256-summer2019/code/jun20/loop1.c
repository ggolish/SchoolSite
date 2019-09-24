#include <stdio.h>

int main(int argc, char *argv[])
{
  int max;

  printf("Enter an integer: ");
  scanf("%d", &max);

  // The current number
  int i = 0;

  while(i <= max) {
    printf("%d\n", i);
    i++;
  }

  return 0;
}
