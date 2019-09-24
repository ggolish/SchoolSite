#include <stdio.h>

int main(int argc, char *argv[])
{
  int x, product;

  scanf("%d", &x);

  product = 1;
  while(x != 0) {
    product *= x % 10;
    x /= 10;
  }

  printf("%d\n", product);

  return 0;
}
