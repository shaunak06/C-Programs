#include <stdio.h>
#include <stdlib.h>
#include <time.h>

main(void)
{
  int pchoice = 0,computerwins = 0, playerwins = 0;
  int crit = 0,cwins,pwins;
  srand(time(NULL));//random number set
  do
    {
      crit = rand();
      crit %= 3;//get a number between 0-2
      crit++;//add one to get a number between 1-3
      //printf("The computers choice is:%d\n",crit);
      puts("Enter 1 for rock, 2 for paper and 3 for scissors, or 4 to quit\n");
      scanf("%d",&pchoice);
      while(pchoice != 1 && pchoice != 2 && pchoice != 3 && pchoice != 4)//checks that the input is valid
	{
	  puts("Please enter a valid input that is between 1 and 4.\n");
	  scanf("%d\n",&pchoice);
	  fflush(stdin);//clears the input string
	}
      if(pchoice != 4)
	{
	  if(pchoice == 1)
	    printf("Your choice was rock!\n");
	  if(pchoice == 2)
	    printf("Your choice was paper!\n");
	  if(pchoice == 3)
	    printf("Your choice was scissors!\n");
	  
	  //display the computers choice
	  if(crit == 1)
	    puts("I have chosen rock\n");
	  if(crit == 2)
	    puts("I have chosen paper\n");
	  if(crit == 3)
	    puts("I have chosen scissors\n");
	  
	  //code to determine the winner
	  if(pchoice == 1 && crit == 2)
	    {
	      printf("Paper beats rock, I win!\n");
	      computerwins++;
	    }
	  if(pchoice == 1 && crit ==3)
	    {
	      printf("Rock beats scissors, you win!\n");
	      playerwins++;	
	    }
	  if(pchoice == 2 && crit == 1)
	    {
	      printf("Paper beats rock, you win!\n");
	      playerwins++;
	    }
	  if(pchoice == 2 && crit == 3)
	    {
	      printf("Scissors beat paper, I win!\n");
	      computerwins++;
	    }
	  if(pchoice == 3 && crit == 1)
	    {	
	      printf("Rock beats scissors, I win!\n");
	      computerwins++;	
	    }      
	  if(pchoice == 3 && crit == 2)
	    {
	      printf("Scissors beat paper, you win!\n");
	      playerwins++;	
	    }      
	  if(pchoice == crit)
	    printf("It's a tie! Play again!\n");
	  printf("You have won %d times, I have won %d times, play again!\n",playerwins, computerwins);
	}
    }while(pchoice != 4)
    ;printf("You should play again sometime!");
  ;return 0;
}
