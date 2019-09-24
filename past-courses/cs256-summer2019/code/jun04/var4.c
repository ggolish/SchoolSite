#include <stdio.h>

int main(int argc, char *argv[])
{
  int x = 10;
  float pi = 3.141592;
  double big_pi = 3.1415926535897;
  char c = 'a';

  printf("x: %010d\n", x);
  printf("pi: %.2f\n", pi);
  printf("big_pi: %.10f\n", big_pi);
  printf("c: %c\n", c);

  return 0;
}
