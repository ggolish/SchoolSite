#include <stdio.h>

int main(int argc, char *argv[])
{
  int x;

  scanf("%d", &x);

  int a = 1;
  int b = 1;
  int c;

  printf("1 ");
  while(a <= x) {
    printf("%d ", a);
    c = a;
    a = a + b;
    b = c;
  }

  printf("\n");

  return 0;
}
