#include <stdio.h>

int main(int argc, char *argv[])
{
  float c = 56.0;
  float f = (9.0 / 5.0) * c + 32.0;

  printf("%.2fC --> %.2fF\n", c, f);

  return 0;
}
