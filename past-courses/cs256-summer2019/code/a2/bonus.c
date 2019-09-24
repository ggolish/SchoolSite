#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
  char word[1024], buffer[1024];

  scanf("%s", word);
  int wlen = strlen(word);
  int count = 0;

  while(fgets(buffer, 1024, stdin) != NULL) {
    int blen = strlen(buffer);
    for(int i = 0; i < blen - wlen - 1; ++i) {
      if(strncasecmp(word, buffer + i, wlen) == 0) {
        count++;
      }
    }
  } 

  printf("%d\n", count);

  return 0;
}
