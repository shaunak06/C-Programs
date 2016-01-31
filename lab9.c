#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
  if(argc != 2)
    {
      puts("The correct number of arguments were not entered\n");
      exit(1);
    }
  char month[5], mdseparator[2], day[5], year[7];

  strncpy(month, argv[0], 2);
  month[2]='\0';

  strncpy(mdseparator, argv[2],1);
  mdseparator[1]='\0'; 
  if(mdseparator[0] != '/' || mdseparator[0] != '-')
    {
      puts("The input structure is incorrect\n");
      exit(1);
    }

  strncpy(day,argv[3],2);
  day[2]='\0';
  int dayInt = atoi(day);

  strncpy(year,argv[6],4);
  year[4]='\0';
  int yearInt = atoi(year);

  int monthInt = atoi(month);

  switch(monthInt)
    {
    case 1:
      {
	char monthName[15] = "January";
	break;
      }
    case 2:
      {
	char monthName[15] = "February";
	break;
      }
    case 3:
      {
	char monthName[15] = "March";
	break;
      }
    case 4:
      {
	char monthName[15] = "April" ;
	break;
      }
    case5:
      {
	char monthName[15] = "May";
	break;
      }
    case 6:
      {
	char monthName[15] = "June";
	break;
      }
    case 7:
      {
	char monthName[15] = "July";
	break;
      }
    case 8:
      {
	char monthName[15] = "August";
	break;
      }
    case 9:
      {
	char monthName[15] = "September";
	break;
      }
    case 10:
      {
	char monthName[15] = "October";
	break;
      }
    case 11:
      {
	char monthName[15] = "November";
	break;
      }
    case 12:
      {
	char monthName[15] = "December";
	break;
      }
    default:
      {
	puts("Invalid month input");
	exit(1);
      }
    }
  char monthName[15] = "November";
  printf("%s %d, %d\n",monthName,dayInt,yearInt);
}
