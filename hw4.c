#include <stdio.h>
int sum_divisors(int);

int main(void)
{
  //the variables for the 
  int o[10], sums[10], i=0,x=0,ctr,ctrnum=1;
  // variables for the original user input, the summs for the corresponding inputs, the current input
  puts("Please enter up to 10 numbers (NOTE: NEED TO PRESS EOF 2 TIMES TO GET OUPUT");
  while(scanf("%d\n",&x)!= EOF)//check if the user enterd an end of file character 
    {
      //if invalid input the program should exit
      if(x>100 || x=='\0')
	return 0;
      //printf("\ninput = %d\n", x);
      o[i]=x;//set element of original values to the input value
      sums[i]=sum_divisors(o[i]);
      printf("%d,",o[i]);
      ctr = o[i];
      ctrnum=1;//reset counter
      if(sum_divisors(o[i])==o[i])
	{
	  printf("%d \t",o[i]);
	}
      else
	{
	  while(ctr !=0)
	    {
	      ctr = sum_divisors(ctr);
	      printf("%d,",ctr);
	      ctrnum++;
	    }
	  printf("0 \t");
	}
      printf("%d cycles\n",ctrnum);
      i++;    
    }
  puts("");
}
  int sum_divisors(int n)
    {
      int j,total=0;//increment var and sum of divisors
      if(n <=1)//if the number is less than 1 automatically 0
	return 0;
      else
	{
	  for(j=1;j<n;j++)//for loop to find divisors
	  {
	    if(n%j==0)
	      total+=j;
	  }
	}
      //printf("The sum of the divisors for %d are %d\n",n,total); 
      return total;
}
      
