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

  for(int i = 0; i < len; i++) {
    printf("%d\n", a[i]);
  } 

  return 0;
}
