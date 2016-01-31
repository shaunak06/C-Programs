#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(void)
{
  int i,j,c1=0,c2=0,c3=0,c4=0,c5=0,c6=0;
  srand(time(NULL));
  int** arr1;
  arr1 = (int**)malloc(5000*sizeof(int));//creating the first part of the 2-d array
  for(i=0;i<5000;i++)
    {
      arr1[i]=(int*)malloc(5000*sizeof(int));//creating the second dimension
    }  
  //for loop to go through and set each element
  for(i=0;i<5000;i++)
    {
      for(j=0;j<5000;j++)
	{
	  arr1[i][j]=(rand()%7);
	  
	  switch(arr1[i][j])
	    {
	    case 1:
	      {
		c1++;
		break;
	      }
	    case 2:
	      {
		c2++;
		break;
	      }
	    case3:
	      {
		c3++;
		break;
	      }
	    case4:
	      {
		c4++;
		break;
	      }
	    case5:
	      {
		c5++;
		break;
	      }
	    default:
	      c6++;
	    }
	}
    }
  //at the end depending on the random numbers the results are printed
  printf("0 appears %d\n1 appears %d\n2 appears %d\n2 appears %d\n3 appears %d\n4 appears %d\n5 appears %d\n6 appears %d",c1,c2,c3,c4,c5,c6);
  return 0;
}
