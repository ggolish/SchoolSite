#include <stdio.h>

int main(int argc, char *argv[])
{
  int x;

  printf("Enter an integer: ");
  scanf("%d", &x);

  while(x > 0) {
    printf("%d", x % 10);
    x /= 10;
  }

  printf("\n");

  return 0;
}
