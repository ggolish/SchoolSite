#include <stdio.h>

#define MAX_NAME 20

int main(int argc, char *argv[])
{
  char fname[MAX_NAME], lname[MAX_NAME];

  printf("Enter your first name: ");
  scanf("%s", fname);

  printf("Enter your last name: ");
  scanf("%s", lname);

  printf("Hello %s %s, how are you?\n", fname, lname);

  return 0;
}
