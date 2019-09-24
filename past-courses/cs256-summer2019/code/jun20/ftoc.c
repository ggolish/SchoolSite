#include <stdio.h>

int main(int argc, char *argv[])
{
  float f = 0.0;
  printf("%10s %10s\n", "Fahren", "Celsius");
  while(f <= 100.0) {
    float c = (f - 32.0) * (5.0 / 9.0);
    printf("%10.2f %10.2f\n", f, c);
    f += 10.0;
  }

  return 0;
}
