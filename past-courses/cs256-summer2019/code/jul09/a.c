#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rand_range(int min, int max);

int main(int argc, char *argv[])
{
  int x;

  srand(time(NULL));

  for(int i = 0; i < 5; i++) {
    x = rand_range(50, 2000);
    printf("%d\n", x);
  }

  return 0;
}

int rand_range(int min, int max)
{
  return (rand() % (max - min + 1)) + min;
}





