#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int main(int argc, char *argv[])
{
  int a[MAX_SIZE];
  int length = 0;

  for(int i = 0; i < 10; i++) {
    int rv = scanf("%d", &a[length]);
    if(rv != 1) {
      printf("Error: Only read %d integers.\n", length);
      exit(1);
    }
    length++;
  }

  printf("Successfull\n");

  return 0;
}
