//This is a program that uses matrices for solving two linear equations.
#include <stdio.h>
#define SIZE 2

int main(void)
{
  float a,b,c,d,e,f,coef[SIZE][SIZE],cons[SIZE],final[SIZE],temp,det;
  puts("Give numbers");
  scanf("%f %f %f %f %f %f",&a, &b, &c, &d, &e, &f);
  coef[0][0]=a;
  coef[0][1]=b;
  coef[1][0]=d;
  coef[1][1]=e;
  cons[0]=c;
  cons[1]=f;
  det=(a*e-b*d);
  if(det==0)
    {
      printf("Too complicated!");
      return 0;
    }
  temp = a/det;
  a=e/det;
  b=-b/det;
  d=-d/det;
  e=temp;

  final[0] = ((e*c-f*b)/det);
  final[1] = ((a*f-c*d)/det);

  printf("x = %f\n",final[0]);
  printf("y = %f\n", final[1]);
}
