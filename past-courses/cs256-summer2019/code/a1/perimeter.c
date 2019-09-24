#include <stdio.h>

int main(int argc, char *argv[])
{
  int l, perimeter;

  printf("Enter a length: ");
  scanf("%d", &l);

  perimeter = 4 * l;

  printf("Length: %d\n", l);
  printf("Perimeter: %d\n", perimeter);

  return 0;
}
