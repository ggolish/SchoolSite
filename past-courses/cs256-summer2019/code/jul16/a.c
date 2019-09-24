#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  if(argc != 2) {
    fprintf(stderr, "Usage: %s <file-name>\n", argv[0]);
    exit(1);
  }

  FILE *fd;

  fd = fopen(argv[1], "a");
  if(fd == NULL) {
    fprintf(stderr, "Error: Unable to open %s for reading.\n", argv[1]);
    exit(1);
  }

  char c;

  while((c = fgetc(fd)) != EOF) {
    putchar(c);
  }

  fclose(fd);

  return 0;
}



