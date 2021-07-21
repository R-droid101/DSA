/*
  Name: Raggav Subramani
  Registration number:20BCT0127
  Purpose of code: To reverse string using stack
*/

/*
  Algorithm:
  Step 1: Initialize and read the string from the user.
  Step 2: Initialize stack and top=-1.
  Step 3: Push each character in the string into the stack one by one.
  Step 4: Pop each character from the string and print it.

*/
#include <stdio.h>
#include <string.h>

int top = -1, stack[100]; //declaring stack as an array
void push(char c)
{                  //push operation
    if (top == 99) //checking overflow condition
    {
        printf("Overflow");
    }
    else
        stack[++top] = c;
}

void pop()
{                  //pop operation
    if (top == -1) //Checking underflow condition
    {
        printf("Underflow");
    }
    printf("%c", stack[top--]);
}

int main() //main function
{
    char s[100];
    printf("Input string: ");
    gets(s); //String input
    int l = strlen(s);

    for (int i = 0; i < l; i++)
        push(s[i]); //pushing string into stack

    for (int i = 0; i < l; i++)
        pop(); //popping and printing

    return 0;
}
