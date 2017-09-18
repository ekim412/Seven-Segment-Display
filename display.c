#include <stdio.h>
#include <stdlib.h>

/*
 * Author: Edward Kim
 * Seven Segment integer display to turn any integer from -9 to 9 into seven
 * segment display.
 */

void display();
const unsigned char segments [11][3][4] = 
{ 
  { /* 0 */
    {' ','_',' '},
    {'|',' ','|'},
    {'|','_','|'}
  },
  { /* 1 */
    {' ',' ',' '},
    {' ',' ','|'},
    {' ',' ','|'}
  },
  { /* 2 */
    {' ','_',' '},
    {' ','_','|'},
    {'|','_',' '}
  },
  { /* 3 */
    {' ','_',' '},
    {' ','_','|'},
    {' ','_','|'}
  },
  { /* 4 */
    {' ',' ',' '},
    {'|','_','|'},
    {' ',' ','|'}
  },
  { /* 5 */
    {' ','_',' '},
    {'|','_',' '},
    {' ','_','|'}
  },
  { /* 6 */
    {' ','_',' '},
    {'|','_',' '},
    {'|','_','|'}
  },
  { /* 7 */
    {' ','_',' '},
    {' ',' ','|'},
    {' ',' ','|'}
  },
  { /* 8 */
    {' ','_',' '},
    {'|','_','|'},
    {'|','_','|'}
  },
  { /* 9 */
    {' ','_',' '},
    {'|','_','|'},
    {' ',' ','|'}
  },
  { /* minus sign for negative integers */
    {' ',' ',' '},
    {' ','_',' '},
    {' ',' ',' '}
  },
};

int main(){

  char more = 'y';                    /* Set more to y and use while loop to ask to continue */
  while(more == 'y' || more == 'Y'){  /* While more is y or Y, continue */
    display();
    printf("\nWould you like to continue? (Y or N): ");
    scanf(" %c", & more);
    if(more == 'y' || more == 'Y'){   /* If user inputs y or Y, continue */
      continue;
    }
    else{                             /* If user doesn't input y or Y, exit */
      more = 'n';
      exit(0);
    }
  }
  return 0;
}

/*
 * This is the display function that takes the user's desired number
 * and prints it into seven segment display using the array that I have
 * created at the beginning.
 */
void display(){
  int number;
  printf("Enter number to be displayed: ");
  scanf(" %d", &number);
  if(number < 0 && number > -10){              /* If number is negative, need to include minus sign */
    number = number * (-1);
    for(int i = 0; i < 3; i++){
      for(int j = 0; j < 3; j++){
	printf("%c",segments[10][i][j]);       /* Print the minus sign first(when j goes 0 to 2) */
      }
      for(int k = 0; k < 3; k++){              /* Then print number right after (when k goes 0 to 2) */
	printf("%c", segments[number][i][k]); 
      }
      putchar('\n');                           /* Then jump to next line to for each time i goes up */
    }
  }
  else if(number >= 0 && number < 10){         /* Else if for when number is single digit positive integer */
    for(int i = 0; i < 3; i++){
      for(int j = 0; j < 3; j++){
	printf("%c", segments[number][i][j]);  /* Same concept as above, just no negative sign */
      }
      putchar('\n');
    }
  }
  else{                                        /* Else is when input number isn't between -9 and 9 */
    printf("Error: Number needs to be between -9 and 9.");
  }
}



































































