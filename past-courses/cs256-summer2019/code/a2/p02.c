#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{
  double a, b, c;
  double r1, r2;

  scanf("%lf", &a);
  scanf("%lf", &b);
  scanf("%lf", &c);

  double d = sqrt((b * b) - (4 * a *c));

  if(d > 0.0) {
    r1 = ((-b) + d) / (2 * a);
    r2 = ((-b) - d) / (2 * a);
    printf("%.2f, %.2f\n", r1, r2);
  } else if(d == 0.0) {
    r1 = (-b) / (2 * a);
    printf("repeated root: %.2f\n", r1);
  } else {
    printf("no real roots exist\n");
  }
  
  return 0;
}
