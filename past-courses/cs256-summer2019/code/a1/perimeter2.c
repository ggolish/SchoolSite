#include <stdio.h>

int main(int argc, char *argv[])
{
  int l, w, perimeter;

  printf("Enter a length: ");
  scanf("%d", &l);

  printf("Enter a width: ");
  scanf("%d", &w);

  perimeter = 2 * (l + w);

  printf("Length x Width: %d x %d\n", l, w);
  printf("Perimeter: %d\n", perimeter);

  return 0;
}
