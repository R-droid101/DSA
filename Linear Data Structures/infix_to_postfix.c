/* Name: Raggav Subramani
   Registration number: 20BCT0127
   Purpose: To convert infix to postfix expression using stack
*/

/*
  Algorithm:
  Step 1: Read infix expression as string from user.
  Step 2: Initialize stack and variable top=-1 to navigate through the stack.
  Step 3: Repeat steps 4-step 8, iterating through each character in the string.
  Step 4: If character is an alpha-numeric character,print it.
  Step 5: Else if character is '(', push it onto the stack.
  Step 6: Else if character is ')', repeat steps (i) and (ii) until popped character is not equal to '('.
        Step (i): Pop character from stack and store in temporary variable.
        Step (ii): Print the popped character.
   Step 7: Else repeat step (i) until precedence of operator(stack[top])>=precendence of operator(character) and then push character to stack.
        Step (i): Pop character from stack and print it.
   Step 8: Goto next character in the string.
   Step 9: Pop all characters from stack and print them.
*/

#include <stdio.h>
#include <ctype.h>

char stack[100]; //Initialising stack
int top = -1;

void push(char x) //Function to push character into stack
{
    if (top == 99)
    { //Checking overflow condition
        printf("Stack Overflow");
        return;
    }
    stack[++top] = x;
}

char pop() //Function to pop character from stack
{
    if (top == -1)
    { //Checking underflow condition
        printf("Stack Underflow");
        return -1;
    }
    else
        return stack[top--];
}

int priority(char x) //Function to rank the precedence of operator
{
    if (x == '(')
        return 0;
    if (x == '+' || x == '-') //Has second highest precedence
        return 1;
    if (x == '*' || x == '/') //Has highest precendence
        return 2;
    return 0;
}

void in_to_post(char exp[])
{ //Function to convert expression from infix to postfix
    char *e, x;
    e = exp;
    while (*e != '\0') //Loop to iterate through the string expression
    {
        if (isalnum(*e)) //Checks if character is alpha-numerical
            printf("%c ", *e);
        else if (*e == '(') //Checks if character is opening bracket
            push(*e);
        else if (*e == ')') //Check if character is closing bracket
        {
            while ((x = pop()) != '(')
                printf("%c ", x);
        }
        else
        {
            while (priority(stack[top]) >= priority(*e)) //checks precedence of operator
                printf("%c ", pop());
            push(*e);
        }
        e++;
    }

    while (top != -1) //Popping all the characters that are still in the stack
    {
        printf("%c ", pop());
    }
}

int main() //Main function to navigate flow of control
{
    char exp[100]; //String that contains infix expression
    char *e, x;
    printf("Enter the expression : ");
    scanf("%s", exp); //Reading the expression from the user
    printf("\n");
    in_to_post(exp); //Calling the function to convert from infix to postfix
    return 0;
}
