#ifndef DATE_H_
#define DATE_H_

typedef struct {
  int m;
  int d;
  int y;
} date_t;

void print_date(date_t d);

#endif
