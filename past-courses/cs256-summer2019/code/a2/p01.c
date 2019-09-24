#include <stdio.h>
#include <stdbool.h>

bool isvalid(int a, int b, int c);

int main(int argc, char *argv[])
{
  int a, b, c;

  scanf("%d", &a);
  scanf("%d", &b);
  scanf("%d", &c);

  if(isvalid(a, b, c)) {
    printf("valid\n");
  } else {
    printf("not valid\n");
  }

  return 0;
}

bool isvalid(int a, int b, int c)
{
  if((a + b) <= c) {
    return false;
  }
  if((a + c) <= b) {
    return false;
  }
  if((c + b) <= a) {
    return false;
  }

  return true;
}
