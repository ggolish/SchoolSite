#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  if(argc != 4) {
    fprintf(stderr, "Usage: %s <int> <int> <int>\n", argv[0]);
    exit(1);
  }

  int x, y, z;

  x = atoi(argv[1]);
  y = atoi(argv[2]);
  z = atoi(argv[3]);

  printf("%d\n", x + y + z);

  return 0;
}
