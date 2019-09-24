#include <stdlib.h>
#include <unistd.h>
#include "options.h"

options_t parse_options(int argc, char *argv[])
{
  int opt;
  options_t options;

  // Default values
  options.infile = stdin;
  options.outfile = stdout;
  options.encrypt = true;
  options.help = false;

  while((opt = getopt(argc, argv, "f:o:deh")) != -1) {
    switch(opt) {
      case 'f':
        options.infile = fopen(optarg, "r");
        if(options.infile == NULL) {
          fprintf(stderr, "Error: Unable to open %s for reading.\n", optarg);
          exit(1);
        }
        break;
      case 'o':
        options.outfile = fopen(optarg, "w");
        if(options.outfile == NULL) {
          fprintf(stderr, "Error: Unable to open %s for writing.\n", optarg);
          exit(1);
        }
        break;
      case 'd':
        options.encrypt = false;
        break;
      case 'e':
        options.encrypt = true;
        break;
      case 'h':
        options.help = true;
        break;
    }
  }

  return options;
}
