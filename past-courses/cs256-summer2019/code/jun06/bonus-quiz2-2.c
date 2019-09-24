/*
 * Converts a Celsius temperature to Fahrenheit
 *
 */

#include <stdio.h>

int main(int argc, char *argv[])
{
  float c, f;
  
  // Give the user a prompt so they know what to do
  printf("Enter a temperature in Celsius: ");

  // Read the temperature from stdin
  scanf("%f", &c);

  // Calculate the temperature in Fahrenheit
  f = (9.0 / 5.0) * c + 32.0;

  // Print our findings
  printf("%.2fC --> %.2fF\n", c, f);

  return 0;
}
