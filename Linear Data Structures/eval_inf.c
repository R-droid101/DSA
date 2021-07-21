/*
  Name: Raggav Subramani
  Registration Number: 20BCT0127
  Purpose: To evaluvate infix expressions
*/

/* 
  Algorithms:
  Step 1: Input infix expression from user.
  Step 2: Convert infix expression to postfix expression.
  Step 3: Scan for the given postfix expression from left to right, one element at a time.
  Step 4: Check whether it is an operand or an operator.
     If it is an operand then push the element in to stack
     If it is an operator then pop the two element from the stack. Apply the given operator on them and then push 	back the result in to the stack. 
    <operand 2> operator <operand 1>
  Step 5: Repeat the step 1 to 2 until the whole postfix expression comes to the end.
  Step 6: Pop the element from the stack which should be the only element in the stack and return it from the function as the result of the expression.
  Step 7: Exit.
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXSTACK 100
#define POSTFIXSIZE 100

int stack[MAXSTACK];
int top = -1;
char stack1[MAXSTACK];
int top1 = -1;

void push1(char x)
{
    if (top >= MAXSTACK - 1)
    {
        printf("stack over flow");
        return;
    }
    stack1[++top] = x;
}

char pop1()
{
    if (top == -1)
    {
        return -1;
        printf("Underflow");
    }
    else
        return stack1[top--];
}

int priority(char x)
{
    if (x == '(')
        return 0;
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/')
        return 2;
    return 0;
}

void push(int item)
{
    if (top >= MAXSTACK - 1)
    {
        printf("stack over flow");
        return;
    }
    else
    {
        stack[++top] = item;
    }
}

int pop()
{
    int item;
    if (top < 0)
    {
        printf("stack under flow");
    }
    else
    {
        item = stack[top--];
        return item;
    }
}

void EvalPostfix(char postfix[])
{
    int i;
    char ch;
    int val;
    int A, B;

    for (i = 0; postfix[i] != ')'; i++)
    {
        ch = postfix[i];
        if (ch == ' ')
            continue;

        else if (isdigit(ch))
        {
            int full_num = 0;
            while (isdigit(ch))
            {
                full_num = full_num * 10 + (int)(ch - '0');
                ch = postfix[++i];
            }
            push(full_num);
            i--;
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {

            A = pop();
            B = pop();

            switch (ch)
            {
            case '*':
                val = B * A;
                break;

            case '/':
                val = B / A;
                break;

            case '+':
                val = B + A;
                break;

            case '-':
                val = B - A;
                break;
            }

            push(val);
        }
    }
    printf(" \n Result of expression evaluation : %d \n", pop());
}

int main()
{
    int i;
    char postfix[POSTFIXSIZE];
    char exp[100];
    char *e, x;
    printf("Enter the expression : ");
    gets(exp);
    printf("\n");
    exp[strlen(exp)] = '$';
    e = exp;

    while (*e != '$')
    {
        if (*e == ' ')
            postfix[i++] = ' ';
        else if (isdigit(*e))
            postfix[i++] = *e;
        else if (*e == '(')
            push1(*e);
        else if (*e == ')')
        {
            while ((x = pop1()) != '(')
                postfix[i++] = x;
        }
        else
        {
            while (priority(stack1[top]) >= priority(*e))
                postfix[i++] = pop1();
            push1(*e);
        }
        e++;
    }

    while (top != -1)
        postfix[i++] = pop1();
    postfix[i] = ')';
    EvalPostfix(postfix);
    return 0;
}