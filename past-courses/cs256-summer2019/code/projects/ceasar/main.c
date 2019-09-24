#include <stdio.h>
#include <stdlib.h>
#include "options.h"
#include "ceasar.h"

int main(int argc, char *argv[]) 
{
  options_t options = parse_options(argc, argv);

  if(options.encrypt) {
    encrypt(options.infile, options.outfile); 
  } else {
    decrypt(options.infile, options.outfile); 
  }

  return 0;
}

