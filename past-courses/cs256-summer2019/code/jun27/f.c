#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1024
#define NVOWELS 5

#define A 0
#define E 1
#define I 2
#define O 3
#define U 4

int isvowel(char c);
char itovowel(int index);

int main(int argc, char *argv[])
{
  char s1[MAX_SIZE];
  int a[NVOWELS];

  // Initialize all counts to 0
  for(int i = 0; i < NVOWELS; ++i) {
    a[i] = 0;
  }

  // Read a string to count 
  if(fgets(s1, MAX_SIZE, stdin) == NULL) {
    printf("Please enter a string.\n");
    exit(1);
  }

  // Calculate length of string
  int len1 = strlen(s1);
  
  printf("%s", s1);

  // Count the vowels
  for(int i = 0; i < len1; i++) {
    char c = tolower(s1[i]);
    int rv = isvowel(c);
    if(rv != -1) {
      a[rv]++;
    }
  }

  // Print vowel count
  for(int i = 0; i < NVOWELS; i++) {
    printf("%c: %d\n", itovowel(i), a[i]);
  }

  return 0;
}

// Translate a vowel to its proper index
int isvowel(char c)
{
  if(c == 'a')
    return A;
  if(c == 'e')
    return E;
  if(c == 'i')
    return I;
  if(c == 'o')
    return O;
  if(c == 'u')
    return U;
  return -1;
}

// Translates an index to its corresponding vowel
char itovowel(int index) 
{
  switch(index) {
    case A:
      return 'a';
    case E:
      return 'e';
    case I:
      return 'i';
    case O:
      return 'o';
    case U:
      return 'u';
    default:
      return -1;
  }
}

