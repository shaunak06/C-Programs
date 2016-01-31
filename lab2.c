#include <stdio.h>
int main(void)//main
{
  int x,y,n,m,gcd;
  //asking user for input
  printf("Please enter a fraction (numerator/denominator):\n");
  if(scanf("%d/%d",&x,&y)!=2)//if the input is not "#/#" it will print invalid
    {
      printf("Invalid Input\n");
    }
  else
    {
      printf("x = %d, y= %d\n",x,y);
      //once you know the input is correct you set the temp variables
      m=x;
      n=y;
      {
	if(y != 0)//if y is not equal to zero then it continues with the program
	  {
	    if(x == 0)//if numerator is 0 the return is 0
	      {
	     printf("0\n");
	     return 0;
	      }
	    else
	      {
		printf("m=%d, n=%d, gcd=%d\n",m,n,gcd);
		while(n!=0)//while loop to get the GCD
		  {
		    gcd=m%n;
		    printf("gcd = %d\n",gcd);
		    m=n;
		    n=gcd;
		  }//divide the numerator and denominator by the GCD, m contains the gcd in this case
		printf("gcd = %d, x=%d, y=%d\n",m,x,y);	      
		x /= m;
		y /= m;
	      }
	    printf("The reduced fraction is:%d/%d\n", x,y);
	    return 0;
	  }//if the y = 0 then it prints undefined
	printf("Undefined\n");
	return 0;
      }
    }
}//main
