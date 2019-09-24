#include <stdio.h>

int main(int argc, char *argv[])
{
  int a, b, c;

  printf("Input a phone number [(xxx) xxx-xxxx]: ");
  scanf("(%3d) %3d-%4d", &a, &b, &c);

  printf("%03d.%03d.%04d\n", a, b, c);

  return 0;
}
