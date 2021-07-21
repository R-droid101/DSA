/*
  Name: Raggav Subramani
  Registration number: 20BCT0127
  Purpose: To find solution to Tower of Hanoi problem 
*/

/*
  Algorithm:
  Step 1: Move n-1 disks from source to aux.
  Step 2: Move nth disk from source to destination.
  Step 3: Move n-1 disks from aux to destination.
*/
#include <stdio.h>

void towers(int num, char frompeg, char topeg, char auxpeg)
{ //To evaluvate and display steps
  if (num == 1)
  {
    printf("Move disk from peg %c to peg %c.\n", frompeg, topeg);
    return;
  }
  towers(num - 1, frompeg, auxpeg, topeg);
  printf("Move disk %d from peg %c to peg %c.\n", num, frompeg, topeg);
  towers(num - 1, auxpeg, topeg, frompeg);
}

int main()
{ //Main function
  int num;
  printf("Enter number of disks:\n");
  scanf("%d", &num);
  printf("Sequence of moves involved in Tower of Hanoi are:\n");
  towers(num, 'A', 'C', 'B'); //Calling function with necessary parameters
  return 0;
}