#include <stdio.h>

#define MAX_SIZE 50

int main(int argc, char *argv[])
{
  int a[MAX_SIZE], tmp;
  int length = 0;

  while(scanf("%d", &tmp) == 1) {
    if(length == MAX_SIZE) {
      printf("Too many numbers.\n");
      break;
    }
    a[length] = tmp;
    length++;
  }

  // Print the array forwards
  for(int i = 0; i < length; i++) {
    printf("%d, ", a[i]);
  }
  printf("\n");

  // Print the array backwards
  for(int i = length - 1; i >= 0; i--) {
    printf("%d, ", a[i]);
  }
  printf("\n");

  return 0;
}
