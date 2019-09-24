#include <stdio.h>

int main(int argc, char *argv[])
{
  int x;
  char c;
  float y;

  printf("Enter a character: ");
  scanf("%c", &c);
  printf("Enter a integer: ");
  scanf("%d", &x);
  printf("Enter a floating point number: ");
  scanf("%f", &y);

  printf("c = '%c'\n", c);
  printf("x = %d\n", x);
  printf("y = %.2f\n", y);

  return 0;
}
