#include <stdio.h>

int main(int argc, char *argv[])
{
  int n1, d1, n2, d2;

  printf("Input an expression [n1/d1+n2/d2]: ");
  scanf("%d/%d+%d/%d", &n1, &d1, &n2, &d2);

  int new_n1 = n1 * d2;
  int new_n2 = n2 * d1;
  int new_d = d1 * d2;

  printf("%d/%d+%d/%d = %d/%d\n", n1, d1, n2, d2, new_n1 + new_n2, new_d);

  return 0;
}
