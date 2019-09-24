#include "ceasar.h"
#include <ctype.h>

char secret_alphabet[26] = {
  'v','w','k','n','x',
  'r','f','l','m','p',
  'a','t','g','y','e',
  'h','o','q','s','z',
  'u','d','j','b','i',
  'c'
};

void encrypt(FILE *infile, FILE *outfile) 
{
  char c;

  while((c = fgetc(infile)) != EOF) {
    if(isalpha(c)) {
      char secretc = secret_alphabet[tolower(c) - 'a'];
      fputc(secretc, outfile);
    } else {
      fputc(c, outfile);
    }
  }
}

void decrypt(FILE *infile, FILE *outfile) 
{
  printf("decrypt\n");
}

