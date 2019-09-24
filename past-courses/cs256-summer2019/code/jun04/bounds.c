#include <stdio.h>  // for printf
#include <limits.h> // for upper and lower bounds of integers
#include <float.h>  // for upper and lower bounds of floating points

int main(int argc, char *argv[])
{
  // char limits
  printf("char size: %d bytes\n", sizeof(char));
  printf("char lower limit: %d\n", CHAR_MIN);
  printf("char upper limit: %d\n", CHAR_MAX);

  printf("\n");

  // int limits
  printf("int size: %d bytes\n", sizeof(int));
  printf("int lower limit: %d\n", INT_MIN);
  printf("int upper limit: %d\n", INT_MAX);

  printf("\n");

  // short limits
  printf("short size: %d bytes\n", sizeof(short));
  printf("short lower limit: %hd\n", SHRT_MIN);
  printf("short upper limit: %hd\n", SHRT_MAX);

  printf("\n");

  // long limits
  printf("long size: %d bytes\n", sizeof(long));
  printf("long lower limit: %ld\n", LONG_MIN);
  printf("long upper limit: %ld\n", LONG_MAX);

  printf("\n");

  // unsigned int limits
  printf("unsigned int size: %d bytes\n", sizeof(unsigned int));
  printf("unsigned int lower limit: 0\n");
  printf("unsigned int upper limit: %u\n", UINT_MAX);

  printf("\n");

  // float limits
  printf("float size: %d bytes\n", sizeof(float));
  printf("float lower limit: %f\n", FLT_MIN);
  printf("float upper limit: %f\n", FLT_MAX);

  printf("\n");

  // double limits
  printf("double size: %d bytes\n", sizeof(double));
  printf("double lower limit: %f\n", DBL_MIN);
  printf("double upper limit: %f\n", DBL_MAX);

  printf("\n");

  return 0;
}

