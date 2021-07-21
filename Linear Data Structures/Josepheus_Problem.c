/*
  Name: Raggav Subramani
  Registration number:20BCT0127
  Purpose: To solve Josepheus problem using circular linked list
*/

/*
  Algorithm:
  Step 1: Read n and k value from user.
  Step 2: Repeat step 3 and step 4 until value of n becomes 1.
  Step 3: If n=1, return 1 and exit from function.
  Step 4: Else, do josepheus(n-1,k)+k-1)%n+1.
  Step 5: Exit.
*/

#include <stdio.h>

int josephus(int n, int k)
{
  if (n == 1)
    return 1;
  else
    return (josephus(n - 1, k) + k - 1) % n + 1; // Adjusting position of recursive call
}

int main() //Main method
{
  int n, k;
  printf("Input n and k respectively: ");
  scanf("%d\t%d", &n, &k);
  printf("\nThe chosen place is %d.", josephus(n, k));
  return 0;
}
