#include <stdio.h>

main(void)
{

  int c=0, nA=0, nE=0, nI=0, nO=0, nU=0, nN=0, count=0;//the variables for all the counters
  puts("Enter a string of characters, to end ctrl + d:\n");
  while((c=getchar())!=EOF)//end of file check
    {
      if(count<50)//make sure i dont read more than 50 characters
	{
	  switch(c)
	    {
	      case'a':
		case'A':
		nA++;//increment a if fount
	      break;
	      case'e':
		case'E':
		nE++;//increment e
	      break;
	      case'i':
		case'I':
		nI++;//increment i
	      break;
	      case'o':
		case'O':
		nO++;//increment o
	      break;
	      case'u':
	    case'U':
		nU++;//increment u
	      break;
	      case'0':
		case'1':
		case'2':
		case'3':
		case'4':
		case'5':
		case'6':
		case'7':
		case'8':
		case'9':
		nN++;//increment if it is a number
	      break;
	    default://if it is none of the above
	      break;
	    }
	  count++;
	}
    }
  //the final printout of all of the counts
  printf("#\tletters & digit\n");
  printf("%d\ta's\n",nA);
  printf("%d\te's\n",nE);
  printf("%d\ti's\n",nI);
  printf("%d\to's\n",nO);
  printf("%d\tu's\n",nU);
  printf("%d\tdigits\n",nN);
}
