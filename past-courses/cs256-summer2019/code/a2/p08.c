#include <stdio.h>
#include <stdlib.h>

int read10(int *a);

int main(int argc, char *argv[])
{
  int a[10], b[10];

  if(!read10(a) || !read10(b)) {
    fprintf(stderr, "not enough numbers!\n");
    exit(1);
  }

  int unique = 1;
  for(int i = 0; i < 10; ++i) {
    for(int j = 0; j < 10; ++j) {
      if(a[i] == b[j]) {
        unique = 0;
        printf("%d\n", a[i]);
      }
    }
  }

  if(unique) {
    printf("unique\n");
  }

  return 0;
}

int read10(int *a)
{
  for(int i = 0; i < 10; ++i) {
    int rv = scanf("%d", &a[i]);
    if(rv != 1) {
      return 0;
    }
  }

  return 1;
}

