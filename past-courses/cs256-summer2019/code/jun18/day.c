/*
 * Reads an integer between 1 and 7, prints the
 * day if the week
 *
 */

#include <stdio.h>

int main(int argc, char *argv[])
{
  int day;

  printf("Enter a number between 1 and 7: ");
  scanf("%d", &day);

  if(!((day >= 1) && (day <= 7))) {
    printf("Please enter a digit between 1 and 7.\n");
    return 1;
  }

  switch(day) {
    case 1:
      printf("Sunday\n");
      break;
    case 2:
      printf("Monday\n");
      break;
    case 3:
      printf("Tuesday\n");
      break;
    case 4:
      printf("Wednesday\n");
      break;
    case 5:
      printf("Thursday\n");
      break;
    case 6:
      printf("Friday\n");
      break;
    case 7:
      printf("Saturday\n");
      break;
    default:
      printf("Invalid day number.\n");
      break;
  }

  return 0;
}
