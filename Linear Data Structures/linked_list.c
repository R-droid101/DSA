/*
  Name: Raggav Subramani
  Registration number: 20BCT0127
  Purpose: To store sales details in the form of a linked list
*/

/*
  Algorithm:
  Step 1: Define structures node and linked list to implement task. The node structure should contain variables serial number of product, Product name and quantity of product and a next pointer.
  Step 2: Create a new list.
  Step 3: Repeat Step 4 and 5 until user choice is not equal to 4. 
  Step 4: Start menu to let user choose operation to perform on list giving the following choices:
        (i) Insert
        (ii) Delete
        (iii) Show
        (iv) Exit
  Step 5: Read user's choice of operation.
     Step (i): If choice is 1, Read serial number of product, Product name and Quantity in store of product 
     from the user. Read the position the node needs to be inserted in the list. Create a new node for the product to store it's details and insert the node. The insert operation does the following:
                        1. If position is 0:
                          a)new_node->next=linked_list->head.
                          b)linked_list->head=new_node.                           
                        2. If position is -1:
                           a) If head points to NULL, new_node->next=linked_list->head, linked_list->head=new_node and return.  
                           b) Use temporary pointer to traverse to end of list and do temp->next=new_node and new_node->next=NULL.
                        3. If it is any other position, Use temporary pointer to traverse to that position of list and do new_node->next=temp->next and temp->next=new_node.
     Step (ii): If user choice is 2, delete a node from the list from a specific postition. Delete operation does the following:
                        1. If position=0, linked_list->head=linked_list->head->next and free linked_list->head from the memory and return from function.
                        2. Else if position=-1, repeat (a) until temp->next->next!=NULL.
                           a) temp=temp->next
                        Do temp->next=NULL, explicitly free from memory and return from functino
                        3. Else, navigate to position to which node needs to be deleted and make the previous node point to next node. Free the current node from memory and return from function. 
     Step (iii): If user choice is 3, function to display stack is invoked. Traverse operation does the following:
                         1. Temporary node is made to point to head.
                         2. Until temporary node is not equal to NULL, details stored in temporary node is  
                            displayed.
                         3. Temporary node is made to point to the next node in the stack.
     Step (iv): If user choice is 4, the menu ends and program is terminated.
  Step 6: Exit.
 
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node
{ //Defining structure of node
    int sr_no;
    char name[100];
    char quantity[10];
    struct node *next;
} node;

typedef struct linked_list
{ //Defining structure of list
    struct node *head;
} list;

list *new_list()
{ //Creation of a list
    list *ll = (list *)malloc(sizeof(list));
    ll->head = NULL;
    return ll;
}

node *new_node(int sr_no, char name[100], char quantity[10])
{ //Function to create new node
    node *z;
    z = malloc(sizeof(struct node));
    z->sr_no = sr_no;
    strcpy(z->name, name);
    strcpy(z->quantity, quantity);
    z->next = NULL;

    return z;
}

void insert_beginning(list *ll, node *n)
{ //To insert node at beginnning
    n->next = ll->head;
    ll->head = n;
}

void insert_end(list *ll, node *n)
{ //To insert node at the end
    if (ll->head == NULL)
    {
        n->next = ll->head;
        ll->head = n;
        return;
    }
    node *temp = ll->head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->next = NULL;
}

void insert_middle(list *ll, node *n, int pos)
{ //To insert node at a particular position
    int i = 1;
    node *temp = ll->head;
    while (i++ != pos)
    {
        temp = temp->next;
    }
    n->next = temp->next;
    temp->next = n;
}

void delete (list *ll, int pos)
{ //function to delete node from list
    node *temp = ll->head;
    if (pos == 0)
    { //To delete from beginning
        ll->head = ll->head->next;
        free(temp);
        return;
    }
    else if (pos == -1)
    { //To delete from end
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = NULL;
        free(temp->next);
        return;
    }
    else
    { //To delete from a specified postition
        for (int i = 1; i < pos; i++)
        {
            if (temp->next != NULL)
            {
                temp = temp->next;
            }
        }
        free(temp->next);
        temp->next = temp->next->next;

        return;
    }
}

void list_traverse(list *ll)
{ //Function to display list details
    struct node *temp = ll->head;
    printf("\n\nList elements are - \n");
    printf("Serial Number\tProduct name\tQuantity\n");
    while (temp != NULL)
    {
        printf("\n%d\t\t%s\t\t%s", temp->sr_no, temp->name, temp->quantity);
        temp = temp->next;
    }
}

int main()
{ //Main function to control flow of execution
    list *ll = new_list();
    int choice = 0;
    printf("\nLinked List operations:\n");
    while (choice != 4)
    { //Menu driven program
        printf("\n\nChoose one from the below options...\n");
        printf("\n1.Insert\n2.Delete\n3.Show\n4.Exit");
        printf("\n Enter your choice \n");
        scanf("%d", &choice);
        switch (choice)
        {
            int sr_no;
            char name[100], quantity[10];
        case 1:
        {
            printf("Input serial number of product, Product name and quantity of product respectively:\n");
            scanf("%d", &sr_no);
            scanf("%s", name);
            scanf("%s", quantity);
            node *ptr = new_node(sr_no, name, quantity);
            printf("Enter position to insert new node.\nIf beginning of the list, input 0; if middle, input the index; if end of list, input -1. \n");
            int pos;
            scanf("%d", &pos);
            if (pos == 0)
            {
                insert_beginning(ll, ptr);
            }
            else if (pos == -1)
            {
                insert_end(ll, ptr);
            }
            else
            {
                insert_middle(ll, ptr, pos);
            }
            break;
        }
        case 2:
        {
            printf("Enter position to delete node.\nIf beginning of the list, input 0; if middle, input the index; if end of list, input -1.  \n");
            int pos;
            scanf("%d", &pos);
            delete (ll, pos);
            break;
        }
        case 3:
        {
            list_traverse(ll);
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
