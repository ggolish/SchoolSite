#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
  int counts[26];
  char buffer[1024];

  // Initializing all elements to 0
  memset(counts, 0, 26 * sizeof(int));

  while(fgets(buffer, 1024, stdin) != NULL) {
    int n = strlen(buffer);
    for(int i = 0; i < n; ++i) {
      if(isalpha(buffer[i])) {
        counts[tolower(buffer[i]) - 'a']++;
      }
    }
  }

  for(int i = 0; i < 26; ++i) {
    printf("%c: %3d\n", i + 'a', counts[i]);
  }

  return 0;
}
