#include <stdio.h>

int main(int argc, char *argv[])
{
  float x, y;

  printf("Enter two numbers: ");
  scanf("%f %f", &x, &y);

  printf("x + y = %.2f\n", x + y);
  printf("x - y = %.2f\n", x - y);
  printf("x * y = %.2f\n", x * y);
  printf("x / y = %.2f\n", x / y);

  return 0;
}
