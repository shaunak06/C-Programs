//This is a program that takes a number the user chooses and reverses the bits and returns the number recieved from the backwards bits
#include <stdio.h>

unsigned int reverse_bits(unsigned int);//the function to reverse the bits

int main(void)
{
  
  unsigned int a,b;
  //user input
  puts("Please enter a number to be reversed:");
  scanf("%u", &a);
  //printf("a = %u\n", a);
  b=reverse_bits(a);
  printf("The reversed number is:%u\n", b);
  return 0;
}

unsigned int reverse_bits(unsigned int val)
{
  //the counter variables and arrays to hold representations of the binary bits
  int i, j=31, original[32], reverse[32];
  unsigned int new;
  //for loop to to get an array representation of the number
  for(i=0;i<32;i++)
    {
      original[i]= val & (1 << i)? : 0;
      reverse[i] = 0;
    }
  //For loop to get the reversed bits

  for(i=0; i<32/2;i++)
    {
      reverse[i]=original[j];
      reverse[j]=original[i];
      // printf("element %d of original: %d, reverse: %d\n element %d of original: %d, reversed: %d",i,original[i],reverse[i],j,original[j],reverse[j]);
      j--;
    }
  //For loop to get an integer of the reversed bit representation array
  for(j=0;j<32;j++)
    {
      if(reverse[j])
	{
	  new |= 1 << j;
	}
    }
  
  return new;
  
}
