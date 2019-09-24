#include <stdio.h>

int main(int argc, char *argv[])
{
  int a[5] = {3, 2, 6, 7, 2};

  for(int i = 0; i < 5; i++) {
    if(i < 4) {
      printf("%d, ", a[i]); 
    } else {
      printf("%d\n", a[i]); 
    }
  }

  return 0;
}
