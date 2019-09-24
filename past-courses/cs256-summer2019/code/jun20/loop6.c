#include <stdio.h>

#define K 1024

int main(int argc, char *argv[])
{
  int a[K], x;

  int len = 0;
  while(scanf("%d", &x) == 1) {
    a[len] = x;
    len++;
  }

  int sum = 0;
  for(int i = 0; i < len; i++) {
    sum += a[i];
  } 

  printf("Sum: %d\n", sum);

  return 0;
}
