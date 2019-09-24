#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{
  float radius = 15.0;
  float radius_cubed = pow(radius, 3.0);
  float volume = (4.0 / 3.0) * M_PI * radius_cubed;

  printf("  Radius (in): %.2f\n", radius);
  printf("Volume (in^3): %.2f\n", volume);

  return 0;
}
