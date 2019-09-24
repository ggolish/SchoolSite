#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 10

bool isunique(int a[], int len1, int nu[], int len2, int i);

int main(int argc, char *argv[])
{
  int a[MAX_SIZE], notunique[MAX_SIZE];
  int len1 = 0, len2 = 0;
  int x;

  while(scanf("%d", &x) == 1) {
    a[len1++] = x;
  }

  if(len1 != MAX_SIZE) {
    printf("Error: Need %d elements.\n", MAX_SIZE);
    exit(1);
  }

  for(int i = 0; i < len1; ++i) {
    if(isunique(a, len1, notunique, len2, i) == true) {
      printf("%d\n", a[i]);
    } else {
      notunique[len2++] = a[i];
    }
  }

  return 0;
}

bool isunique(int a[], int len1, int nu[], int len2, int i)
{
  // Check of the number is in the notunique array
  for(int j = 0; j < len2; ++j) {
    if(a[i] == nu[j]) {
      return false;
    }
  }
  // Check if the number is in the rest of the array
  for(int j = i + 1; j < len1; j++) {
    if(a[j] == a[i]) {
      return false;
    }
  }
  return true;
}
