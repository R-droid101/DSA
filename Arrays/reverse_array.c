/*
  Registration no: 20BCT0127
  Name: Raggav Subramani
  Aim: Program to reverse the given array.
*/

/*
  Algorithm:
  Step 1:  Read size of array from the user.
  Step 2: Input array from the user.
  Step 3: Initialize a variable s(start) to 0 and e(end) to the length of array -1 and a t(temporary variable) to 0.
  Step 4: Repeat steps 5 to 8 while s<e.
  Step 5: t=array[s]
  Step 6: array[s]=array[e]
  Step 7: array[e]=t
  Step 8: Increment s by 1 and decrement e by 1.
  Step 9: Print the array.
*/

#include <stdio.h>

int main()
{
    int n = 0;
    printf("Input size of array\n"); //inputting size of the array
    scanf("%d", &n);
    int arr[n];                              //initializing the variables
    int s = 0;                               //start
    int e = n - 1;                           //end
    int t = 0;                               //temporary variable
    printf("Input array elements below:\n"); //inputting the array
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    while (s < e) //Loop block to reverse the array
    {
        t = arr[s];
        arr[s] = arr[e];
        arr[e] = t;
        s = s + 1;
        e = e - 1;
    }
    printf("The array after reversing is given as follows:\n");
    for (int i = 0; i < n; i++)
    { //Printing the array after reversal
        printf("%d ", arr[i]);
    }
}