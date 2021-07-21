/* Name:Raggav Subramani
   Registration number: 20BCT0127
   Purpose: to implement stack using linked list to keep student details
*/
/*
  Algorithm:
  Step 1: Define structures node and linked list to implement task. The node structure should contain variables
          age, name and registration number of user and a next pointer. The Linked list structure should 
          contain pointers head and top for stack implementation.
  Step 2: Create a new stack.
  Step 3: Repeat Step 4 and 5 until user choice is not equal to 4. 
  Step 4: Start menu to let user choose operation to perform on stack giving the following choices:
     (i) Push
     (ii) Pop
     (iii) Show
     (iv) Exit
  Step 5: Read user's choice of operation.
    Step (i): If choice is 1, Read age,name and registration number of student from the user. Create a new
              node for the student to store his details and push the node into the stack. The push operation
              does the following:
                1. If stack is empty, head and top of stack point towards new node n.
                2. Otherwise, stack top next points to the new node and stack top takes in the values stored
                   in the new node.
    Step (ii): If user choice is 2, pop a node from the stack. Pop operation does the following:
                1. If there are no elements in stack, print 'Stack Underflow' and return from function.
                2. Else if there is only one element stack top and head points to NULL.
                3. Else, a temporary node is used to iterate till the end of the node. Once temp->next= stack->top
                   temp->next is pointed to NULL and stack top is freed from memory. 
                4. Stack top is pointed to temp node.
    Step (iii): If user choice is 3, function to display stack is invoked. Traverse operation does the 
                following:
                1. Temporary node is made to point to head of stack.
                2. Until temporary node is not equal to NULL, details stored in temporary node is displayed.
                3. Temporary node is made to point to the next node in the stack.
    Step (iv): If user choice is 4, the menu ends and program is terminated.
  Step 6: Exit.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node
{
  int age;
  char name[100];
  char reg_no[10];
  struct node *next;
} node;

typedef struct linked_list
{
  struct node *head;
  struct node *top;
} stack;

//to make new node
node *new_node(int age, char name[100], char reg_no[10])
{
  node *z;
  z = malloc(sizeof(struct node));
  z->age = age;
  strcpy(z->name, name);
  strcpy(z->reg_no, reg_no);
  z->next = NULL;

  return z;
}

//to make a new stack
stack *new_stack()
{
  stack *s = malloc(sizeof(stack));
  s->head = NULL;
  s->top = NULL;

  return s;
}

void traversal(stack *s)
{
  node *temp = s->head; //temporary pointer to point to head
  printf("Age\tName\tRegistration Number");
  while (temp != NULL)
  { //iterating over stack
    printf("\n%d\t%s\t%s", temp->age, temp->name, temp->reg_no);
    //printf("\nName: %[^/n]s");
    //printf("\nRegistration number: %s");
    temp = temp->next;
  }

  printf("\n");
}

int is_empty(stack *s)
{
  if (s->top == NULL)
    return 1;
  return 0;
}

void push(stack *s, node *n)
{
  if (is_empty(s))
  { //empty
    s->head = n;
    s->top = n;
  }
  else
  {
    s->top->next = n;
    s->top = n;
  }
}

//function to delete
void pop(stack *s)
{
  if (is_empty(s))
  {
    printf("Stack Underflow\n");
    return;
  }
  else
  {
    if (s->top == s->head)
    { // only one node
      free(s->top);
      s->top = NULL;
      s->head = NULL;
    }
    else
    {
      node *temp = s->head;
      while (temp->next != s->top) // iterating to the last element
        temp = temp->next;
      temp->next = NULL;
      free(s->top);
      s->top = temp;
    }
  }
  printf("Popped successfully!");
}

void main()

{
  stack *s = new_stack();
  int choice = 0;
  printf("\nStack operations using linked list\n");
  while (choice != 4)
  {
    printf("\n\nChose one from the below options...\n");
    printf("\n1.Push\n2.Pop\n3.Show\n4.Exit");
    printf("\n Enter your choice \n");
    scanf("%d", &choice);
    switch (choice)
    {
      int age;
      char name[100], reg_no[10];
    case 1:
    {
      printf("Input age, name and reg_no respectively:\n");
      scanf("%d", &age);
      scanf("%s", name);
      scanf("%s", reg_no);
      node *ptr = new_node(age, name, reg_no);
      push(s, ptr);
      break;
    }
    case 2:
    {
      pop(s);
      break;
    }
    case 3:
    {
      traversal(s);
      break;
    }
    case 4:
    {
      printf("Exiting....");
      break;
    }
    default:
    {
      printf("Please Enter valid choice. ");
    }
    };
  }
}
