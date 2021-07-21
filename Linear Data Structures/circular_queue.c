#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int items[SIZE];
int front = -1, rear = -1;

int isFull()
{
  if ((front == rear + 1) || (front == 0 && rear == SIZE - 1))
    return 1;
  return 0;
}

int isEmpty()
{
  if (front == -1)
    return 1;
  return 0;
}

void enQueue(int element)
{ //Addition of element
  printf("\nEnqueue invoked\n");
  if (isFull())
    printf("\n Overflow\n");
  else
  {
    if (front == -1)
      front = 0;
    rear = (rear + 1) % SIZE;
    items[rear] = element;
    printf("\n added: %d\n", element);
  }
}

int deQueue()
{ //Removal of element
  printf("\nDequeue invoked\n");
  int element;
  if (isEmpty())
  {
    printf("\n Underflow \n");
    return (-1);
  }
  else
  {
    element = items[front];
    if (front == rear)
    {
      front = -1;
      rear = -1;
    }

    else
    {
      front = (front + 1) % SIZE;
    }
    printf("\nDequeued: %d \n", element);
    return (element);
  }
}

void display()
{ // Display queue
  printf("\nDisplay invoked\n");
  int i;
  if (isEmpty())
    printf(" \n Empty Queue\n");
  else
  {
    printf("\n Front: %d ", front);
    printf("\n Items: ");
    for (i = front; i != rear; i = (i + 1) % SIZE)
    {
      printf("%d ", items[i]);
    }
    printf("%d ", items[i]);
    printf("\n Rear: %d \n", rear);
  }
}

int main()
{
  deQueue();
  enQueue(1);
  enQueue(2);
  enQueue(3);
  enQueue(4);
  enQueue(5);
  enQueue(6);
  display();
  deQueue();
  display();
  return 0;
}