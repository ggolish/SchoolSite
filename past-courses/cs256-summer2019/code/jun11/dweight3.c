/*
 * Calculates the dimensional weight of a 12x8x10 box
 *
 */

#include <stdio.h>

#define UPS_CONSTANT 139.0

int main(int argc, char *argv[])
{
  int length, width, height, volume;
  float dweight;

  // Get dimensions of box from user
  printf("Input length: ");
  scanf("%d", &length);
  printf("Input width: ");
  scanf("%d", &width);
  printf("Input height: ");
  scanf("%d", &height);

  // Calculate the volume and the dimensional weight
  volume = length * width * height;
  dweight = (float)volume / UPS_CONSTANT; // cast volume to a float before calculation

  // Print our findings
  printf("Dimensions (in): %dx%dx%d\n", length, width, height);
  printf("Volume (in^3): %d\n", volume);
  printf("Dimensional Weight (lbs): %.2f\n", dweight);

  return 0;
}
