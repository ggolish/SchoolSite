#include <stdio.h>

int main(int argc, char *argv[])
{
  int dollar_amount;
  int twenties, tens, fives, ones;

  printf("Input a dollar amount: ");
  scanf("%d", &dollar_amount);

  twenties = dollar_amount / 20;
  dollar_amount %= 20;

  tens = dollar_amount / 10;
  dollar_amount %= 10;

  fives = dollar_amount / 5;
  dollar_amount %= 5;

  ones = dollar_amount;

  printf("twenties: %-3d\n", twenties);
  printf("    tens: %-3d\n", tens);
  printf("   fives: %-3d\n", fives);
  printf("    ones: %-3d\n", ones);

  return 0;
}
