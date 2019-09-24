#include <stdio.h>

int main(int argc, char *argv[])
{
  int a[5] = {10, 20, 30, 40, 50};

  a[0] = 30;

  printf("%d\n", a[0]);
  printf("%d\n", a[1]);
  printf("%d\n", a[2]);
  printf("%d\n", a[3]);
  printf("%d\n", a[4]);

  return 0;
}
