#include <stdio.h>

int main(int argc, char *argv[])
{
  int n;

  scanf("%d", &n);

  for(int i = n - 1; i >= 0; --i) {
    for(int j = 0; j < n - i - 1; j++) {
      printf(" ");
    }
    for(int j = 0; j < i + 1; j++) {
      printf("*");
    }
    for(int j = 0; j < i; j++) {
      printf("*");
    }
    printf("\n");
  }

  return 0;
}
