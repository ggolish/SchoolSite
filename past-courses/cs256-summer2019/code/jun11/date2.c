#include <stdio.h>

void print_date(int m, int d, int y)
{
  printf("%02d/%02d/%04d\n", m, d, y);
}

int main(int argc, char *argv[])
{
  int m1, d1, y1, m2, d2, y2;

  scanf("%d/%d/%d", &m1, &d1, &y1);
  scanf("%d/%d/%d", &m2, &d2, &y2);

  if(y1 < y2) {
    print_date(m1, d1, y1);
  } else if(y1 == y2) {
    if(m1 < m2) {
      print_date(m1, d1, y1);
    } else if(m1 == m2) {
      if(d1 < d2) {
        print_date(m1, d1, y1);
      } else if(d1 == d2) {
        printf("Why did you type the same date twice.\n"); 
      } else {
        print_date(m2, d2, y2);
      }
    } else {
      print_date(m2, d2, y2);
    }
  } else {
    print_date(m2, d2, y2);
  }

  return 0;
}
