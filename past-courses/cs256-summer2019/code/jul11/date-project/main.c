#include <stdio.h>
#include "date.h"

int main(int argc, char *argv[])
{
  date_t date1, date2;

  scanf("%d/%d/%d", &date1.m, &date1.d, &date1.y);
  scanf("%d/%d/%d", &date2.m, &date2.d, &date2.y);


  if(date1.y < date2.y) {
    print_date(date1);
  } else if(date1.y == date2.y) {
    if(date1.m < date2.m) {
      print_date(date1);
    } else if(date1.m == date2.m) {
      if(date1.d < date2.d) {
        print_date(date1);
      } else if(date1.d == date2.d) {
        printf("Why did you type the same date twice.\n"); 
      } else {
        print_date(date2);
      }
    } else {
      print_date(date2);
    }
  } else {
    print_date(date2);
  }

  return 0;
}



