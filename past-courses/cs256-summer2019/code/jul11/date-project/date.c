#include "date.h"
#include <stdio.h>

void print_date(date_t d)
{
  printf("%02d/%02d/%04d\n", d.m, d.d, d.y);
}
