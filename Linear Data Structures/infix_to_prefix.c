#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void push(int);
char pop();
void infix_to_prefix();
int precedence(char);
char stack[20], infix[20], prefix[20];
int top = -1;

int main()
{
    printf("\nInfix expression: ");
    scanf("%s", infix);
    infix_to_prefix();
    return 0;
}

void push(int position)
{
    if (top == 19)
    {
        printf("\nSTACK OVERFLOW\n");
    }
    else
    {
        stack[++top] = infix[position];
    }
}

char pop()
{
    char ch;
    ch = stack[top];
    stack[top--] = '\0';
    return (ch);
}

void infix_to_prefix()
{
    int i = 0, j = 0;
    //strrev(infix);
    while (infix[i] != '\0')
    {
        if (infix[i] >= 'a' && infix[i] <= 'z')
        {
            prefix[j++] = infix[i++];
        }
        else if (infix[i] == ')' || infix[i] == '}' || infix[i] == ']')
        {
            push(i++);
        }
        else if (infix[i] == '(' || infix[i] == '{' || infix[i] == '[')
        {
            if (infix[i] == '(')
            {
                while (stack[top] != ')')
                {
                    prefix[j++] = pop();
                }
                pop();
                i++;
            }
            else if (infix[i] == '[')
            {
                while (stack[top] != ']')
                {
                    prefix[j++] = pop();
                }
                pop();
                i++;
            }
            else if (infix[i] == '{')
            {
                while (stack[top] != '}')
                {
                    prefix[j] = pop();
                    j++;
                }
                pop();
                i++;
            }
        }
        else
        {
            if (top == -1)
            {
                push(i++);
            }
            else if (precedence(infix[i]) < precedence(stack[top]))
            {
                prefix[j++] = pop();
                while (precedence(stack[top]) > precedence(infix[i]))
                {
                    prefix[j++] = pop();
                    if (top < 0)
                        break;
                }
                push(i);
                i++;
            }
            else if (precedence(infix[i]) >= precedence(stack[top]))
            {
                push(i);
                i++;
            }
        }
    }
    while (top != -1)
    {
        prefix[j++] = pop();
    }
    // strrev(prefix);
    prefix[j] = '\0';
    printf("Prefix notation for the given infix expression: %s ", prefix);
}

int precedence(char operand)
{
    if (operand == '+' || operand == '-')
    {
        return (0);
    }
    if (operand == '*' || operand == '/')
    {
        return (1);
    }
    return -1;
}