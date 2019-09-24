#include <stdio.h>
#include <stdlib.h>

#include "galaga.h"

int main(int argc, char *argv[])
{
  int width, height;

  // Require width and height to be passed as arguments
  if(argc != 3) {
    fprintf(stderr, "Usage: %s <width> <height>\n", argv[0]);
    exit(1);
  }

  // Parse width and height as ints
  width = atoi(argv[1]);
  height = atoi(argv[2]);

  start_game(width, height);
  end_game();

  return 0;
}
