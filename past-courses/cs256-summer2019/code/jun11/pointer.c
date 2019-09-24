#include <stdio.h>

int main(int argc, char *argv[])
{
  int x, y, z;

  x = 10;
  y = 4;
  z = 250;

  printf("%p: %d\n", &x, x);
  printf("%p: %d\n", &y, y);
  printf("%p: %d\n", &z, z);

  return 0;
}
