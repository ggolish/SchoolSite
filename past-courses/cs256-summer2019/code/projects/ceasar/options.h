#ifndef OPTION_H_
#define OPTION_H_

#include <stdio.h>
#include <stdbool.h>

typedef struct {
  FILE *infile;
  FILE *outfile;
  bool encrypt;
  bool help;
} options_t;

options_t parse_options(int argc, char *argv[]);

#endif
