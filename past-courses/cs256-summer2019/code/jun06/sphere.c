#include <stdio.h>

int main(int argc, char *argv[])
{
  float radius = 15.0;
  float radius_cubed = radius * radius * radius;
  float volume = (4.0 / 3.0) * 3.141592 * radius_cubed;

  printf("  Radius (in): %.2f\n", radius);
  printf("Volume (in^3): %.2f\n", volume);

  return 0;
}
