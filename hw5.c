#include <stdio.h>

#include <stdlib.h>

int main(int argc,char* argv[])
{
  char c1,c2,c3;
  int count=0;
  //if the number of arguments is wrong the program quits
  if(argc != 4)
    {
      puts("You did not enter the correct arguments please try again");
      exit(1);
    }
  //if the mode entered is not z or d the program quits
  if((strcmp(argv[1],"d"))!=0 && (strcmp(argv[1],"z"))!=0)
    {
      puts("You did not enter the correct arguments please try again");
      exit(1);
    }
  //open file one and if it is null the program quits
  FILE *f1;
  f1 = fopen(argv[2],"r");
  if(f1==NULL)
    {
      printf("Cannot open input file %s\n",argv[2]);
      exit(1);
    }
  //open file 2, and if it is unwriteable it quits
  FILE *f2;
  f2 = fopen(argv[3],"w");
  if(f2==NULL)
    {
      printf("Cannot open output file %s\n",argv[3]);
      exit(1);
    }
  //printf("argv 1: %s\n",argv[1]);
  //if the user specifies they want to get the file compressed
  if(strcmp(argv[1],"z") == 0)
    {
      c1 = fgetc(f1);
      //printf("c1: %c\n",c1);
      //if the file is empty
      if(c1 == EOF)
	{
	  puts("Input file is empty");
	  fclose(f1);
	  fclose(f2);
	  exit(1);
	}

      count=0;
      while((c2=fgetc(f1))!= EOF)
	{
	  //printf("c2 in loop: %c\n",c2);
	  if(c1==c2)//records if there are multiple same letters in a row
	    {
	      count++;
	    }
	  else
	    {
	      fputc(c1,f2);
	      if(count >0)
		{
		  fputc(c1,f2);
		  fputc((count-1),f2);
		  count = 0;
		}
	      c1=c2;//only c2 needs to read from the input file
	    }	    
	}
      //second check to make sure the count is 0
      if(count !=0)
	{
	  fputc(c1,f2);
	  fputc(c1,f2);
	  fputc((count-1),f2);
	}
      else
	{
	  //if count is 0 simply enters the character
	  fputc(c1,f2);
	}
      fclose(f1);
      fclose(f2);
      return 0;
    }
  //if the user wants to decompress a file
  else if((strcmp(argv[1],"d"))==0)
    {
      c1=fgetc(f1);
      //if input file is empty
      if(c1==EOF)
	{
	  puts("Input file is empty");
	  fclose(f1);
	  fclose(f2);
	  exit(1);
	}
      while((c2=fgetc(f1)) != EOF)
	{
	  if(c1==c2)
	    {
	      int s=fgetc(f1);//gets the number of times the chanracter repeats
	      //printf("Number of times %c occurs: %d\n",c1,s);
	      fputc(c1,f2);
	      fputc(c1,f2);
	      while(s>0)
		{
		  fputc(c1,f2);	    
		  s--;
		}
	      //when the file ends
	     if((c1=fgetc(f1))==EOF)
	       {
		 return 0;
	       }
	    }
	  else//if there are no repeating characters
	    {
	      fputc(c1,f2);
	      c1=c2;
	    }
	}
      //when the end of file is reached
      fputc(c1,f2);
      fclose(f1);
      fclose(f2);
      return 0;
    }
}

