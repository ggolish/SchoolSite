#include <stdio.h>

int main(int argc, char *argv[])
{
  int n;

  scanf("%d", &n);

  // Iterate over rows
  for(int i = 0; i < n; i++) {
    // Iterate over columns
    for(int j = 0; j <= i; j++) {
      printf("*");
    }
    printf("\n");
  }

  return 0;
}
