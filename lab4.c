
#include <stdio.h>
//this program has the user enter words and upon hitting return get the average length of the words used in the sentence.
main(void)
{
  char sentence[10000], curr;//a character array that is really big and a characater to fill the array up with input
  int count =0,i,j=0,s=0;//counter variables
  float avg = 0,current =0, rt= 0;//variables to do the math
  puts("Please enter a sentence");
  while((curr=getchar()) != '\n')//while loop to get input
    {
      sentence[s]=curr;
      s++;
    }
  sentence[s]='\0';//add the end of sentence character
  //printf("%s\n",sentence);
  while(sentence[i] != '\0')//while the part of the senctence is not an end of sentence character
    {
      if(count <80)//the count of words
	{
	  if(sentence[i] == ' ')//check for spaces
	    {//this part of the code takes the deifference of the area of the space and the starting position to get word length
	      current = (float)i-j;
	      j=i+1;
	      count++;
	      //printf("\n%d\n",current);
	    }
	  //printf("%f", avg);
	  rt += current;//the running total
	  current = 0;
	  i++;
	}
    }
  avg = rt / count;//calc the average
  printf("Average word length: %.1f\n",avg);
  return 0;
}
