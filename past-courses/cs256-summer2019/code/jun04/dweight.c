/*
 * Calculates the dimensional weight of a 12x8x10 box
 *
 */

#include <stdio.h>

int main(int argc, char *argv[])
{
  int length, width, height, volume, dweight;

  // Defining the dimensions of the box
  length = 12;
  width = 8;
  height = 10;

  // Calculate the volume and the dimensional weight
  volume = length * width * height;
  dweight = volume / 139;

  // Print our findings
  printf("Dimensions (in): %dx%dx%d\n", length, width, height);
  printf("Volume (in^3): %d\n", volume);
  printf("Dimensional Weight (lbs): %d\n", dweight);

  return 0;
}
