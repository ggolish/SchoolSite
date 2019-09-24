#include <stdio.h>

int main(int argc, char *argv[])
{
  int n1, n2;

  scanf("%d %d", &n1, &n2);

  // Iterate over rows
  for(int i = 0; i < n1; i++) {
    // Iterate over columns
    for(int j = 0; j < n2; j++) {
      printf("*");
    }
    printf("\n");
  }

  return 0;
}
