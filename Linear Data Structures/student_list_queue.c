/*
  Name: Raggav Subramani
  Registration number: 20BCT0127
  Purpose: To store student details in the form of a queue
*/

/*
  Algorithm:
Step 1: Define structures node and linked list to implement task. The node structure should contain variables age, name and registration number of user and a next pointer. The Linked list structure should contain pointers front and rear for queue implementation.
Step 2: Create a new queue.
Step 3: Repeat Step 4 and 5 until user choice is not equal to 4. 
Step 4: Start menu to let user choose operation to perform on stack giving the following choices:
        (i) Enqueue
        (ii) Dequeue
        (iii) Show
        (iv) Exit
Step 5: Read user's choice of operation.
     Step (i): If choice is 1, Read age, name and registration number of student from the user.    
     Create a new  node for the student to store his details and enqueue the node. The  
     enqueue operation does the following:
                        1. If rear is pointing to NULL, front and rear of queue point towards new node n.
                        2. Otherwise, rear->next points to the new node and rear takes in the   
                            values stored in the new node.
     Step (ii): If user choice is 2, pop a node from the stack. Dequeue operation does the following:
                        1.	If front points to NULL, print 'Underflow' and return from 
                            function.
                        2. Else if front=rear, front points to NULL.
                        3. Else, a temporary node is used to store front node values, front is made to point
                           to front->next and temp is freed from memory. 
     Step (iii): If user choice is 3, function to display stack is invoked. Traverse operation does the 
     following:
                         1. Temporary node is made to point to front.
                         2. Until temporary node is not equal to NULL, details stored in temporary node is  
                            displayed.
                         3. Temporary node is made to point to the next node in the stack.
     Step (iv): If user choice is 4, the menu ends and program is terminated.
Step 6: Exit. 

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{ //Defining node structure
    int age;
    char name[100];
    char reg_no[10];
    struct node *next;
} node;

typedef struct queue
{ //Defining queue structure
    struct node *front, *rear;
} queue;

node *newNode(int k, char name[100], char reg_no[10])
{ // Function to create a new node
    node *temp = (node *)malloc(sizeof(node));
    temp->age = k;
    strcpy(temp->name, name);
    strcpy(temp->reg_no, reg_no);
    temp->next = NULL;
    return temp;
}

queue *new_Queue()
{ //Function to create a new queue
    queue *q = (queue *)malloc(sizeof(queue));
    q->front = q->rear = NULL;
    return q;
}

void enQueue(queue *q, node *temp)
{ //Function to enqueue
    if (q->rear == NULL)
    {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

void deQueue(queue *q)
{ //Function to dequeue
    if (q->front == q->rear)
    {
        free(q->front);
        q->front = NULL;
        printf("Element removed");
        return;
    }
    if (q->front == NULL)
    { //Checking underflow condition
        printf("Underflow");
        return;
    }
    node *temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    printf("Element removed");
    free(temp);
}

void traversal(queue *q)
{                          //Queue traversal
    node *temp = q->front; //temporary pointer to point to head
    printf("Age\tName\tRegistration Number");
    while (temp != NULL)
    { //iterating over stack
        printf("\n%d\t%s\t%s", temp->age, temp->name, temp->reg_no);
        temp = temp->next;
    }
}

int main()
{ //Main function to handle menu-driven program
    queue *q = new_Queue();
    int choice = 0;
    printf("\nQueue operations using linked list\n");
    while (choice != 4)
    { //Displaying menu
        printf("\n\nChose one from the below options...\n");
        printf("\n1.Enqueue\n2.Dequeue\n3.Show\n4.Exit");
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
            node *ptr = newNode(age, name, reg_no);
            enQueue(q, ptr);
            break;
        }
        case 2:
        {
            deQueue(q);
            break;
        }
        case 3:
        {
            traversal(q);
            break;
        }
        case 4:
        {
            printf("Exited");
            break;
        }
        default:
        {
            printf("Please Enter valid choice. ");
        }
        };
    }
    return 0;
}
