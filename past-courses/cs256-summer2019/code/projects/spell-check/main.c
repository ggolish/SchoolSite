#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define K 1024
#define CHUNK 8

char **read_dictionary(int *r_len);
bool word_lookup(char *word, char **dict, int dict_len);

int main(int argc, char *argv[]) {
  FILE *fd;
  char **dictionary;
  char buffer[K];
  int dict_len = 0;

  // Make sure they pass one command line argument, path to file
  if(argc != 2) {
    fprintf(stderr, "Usage: %s <text-file>\n", argv[0]);
    exit(1);
  }

  // Open the file they gave us
  fd = fopen(argv[1], "r");
  if(fd == NULL) {
    fprintf(stderr, "Error: Unable to open file %s for reading.\n", argv[1]);
    exit(1);
  }

  // Reading the dictionary
  dictionary = read_dictionary(&dict_len);
  if(dictionary == NULL) {
    exit(1);
  }

  // Lookup the words
  while(fscanf(fd, "%s", buffer) == 1) {
    if(word_lookup(buffer, dictionary, dict_len) == false) {
      printf("%s\n", buffer);
    }
  }


  return 0;
}

char **read_dictionary(int *r_len)
{
  FILE *fd;
  char **dict = NULL;
  int len = 0, cap = 0;
  char buffer[K];

  fd = fopen("/usr/dict/words", "r");
  if(fd == NULL) {
    fprintf(stderr, "Error: Unable to read dictionary file.\n");
    return NULL;
  }

  while(fgets(buffer, K, fd) != NULL) {
    // Removing that pesky newline
    int index = strlen(buffer) - 1;
    if(buffer[index] == '\n') {
      buffer[index] = '\0';
    }

    // Add the word to my array
    if(len > cap - 1) {
      // Out of space
      cap = (cap == 0) ? CHUNK : cap * 2;
      dict = realloc(dict, cap * sizeof(char *));
    }

    dict[len++] = strdup(buffer);
  }

  (*r_len) = len;
  return dict;
  
}

bool word_lookup(char *word, char **dict, int dict_len)
{
  int lo = 0;
  int hi = dict_len - 1;

  while(lo <= hi) {
    int mid = (hi + lo) / 2;
    int rv = strcasecmp(word, dict[mid]);
    if(rv == 0) {
      return true;
    } else if(rv < 0) {
      hi = mid - 1;
    } else {
      lo = mid + 1;
    }
  }

  return false;
}
