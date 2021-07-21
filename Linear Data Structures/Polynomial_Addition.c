/*
  Name: Raggav Subramani
  Registration Number: 20BCT0127
  Purpose: To perform polynomial addition
*/

/*
  Algorithm:
  Step 1: Read polynomial 1 and 2 from user.
  Step 2: Loop around all values of linked list and follow step 3 & 4.
  Step 2: If the value of exponent is greater, copy this the to result and head to next term.
  Step 3: If the values of both exponent is same, add the coefficients and then copy added value to the result.
  Step 4: Print the resultant node. 
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{ //defining structure of node
    int coeff;
    int expon;
    struct node *link;
};

typedef struct node *node;

node new_node()
{ //to create a new node
    node x;
    x = (node)malloc(sizeof(struct node));
    return x;
}

node attach(int coeff, int expon, node head)
{ //to create each term of the polynomial and attach the coefficient, term and exponent
    node temp, cur;
    temp = new_node();
    temp->coeff = coeff;
    temp->expon = expon;
    cur = head->link;
    while (cur->link != head)
    {
        cur = cur->link;
    }
    cur->link = temp;
    temp->link = head;
    return head;
}

node read_poly(node head)
{ //to input poolynomial from user
    int i = 1, coeff, expon;
    printf("\nEnter the coefficient as -999 to end the polynomial ");
    while (1)
    {
        printf("\nEnter the %d term:\n", i++);
        printf("\n\tCo-efficient = ");
        scanf("%d", &coeff);
        if (coeff == -999)
            break;
        printf("\n\tPower of x = ");
        scanf("%d", &expon);
        head = attach(coeff, expon, head);
    }
    return head;
}

node poly_add(node poly1, node poly2, node res)
{ //function to add two polynomials
    node a, b;
    int coeff;
    a = poly1->link;
    b = poly2->link;
    while (a != poly1 && b != poly2)
    {
        if (a->expon == b->expon)
        {
            coeff = a->coeff - b->coeff;
            if (coeff != 0)
                res = attach(coeff, a->expon, res);
            a = a->link;
            b = b->link;
        }
        else if (a->expon > b->expon)
        {
            res = attach(a->coeff, a->expon, res);
            a = a->link;
        }
        else
        {
            res = attach(b->coeff, b->expon, res);
            b = b->link;
        }
    }
    while (a != poly1)
    {
        res = attach(a->coeff, a->expon, res);
        a = a->link;
    }
    while (b != poly2)
    {
        res = attach(b->coeff, b->expon, res);
        b = b->link;
    }
    return res;
};

void display(node head)
{ //function to display the polynomials
    node temp;
    if (head->link == head)
    {
        printf("\nPolynomial does not exist");
        return;
    }
    temp = head->link;
    while (temp != head)
    {
        printf("%dx^%d", temp->coeff, temp->expon);
        temp = temp->link;
        if (temp != head)
            printf(" + ");
    }
}

int main()
{ //Main function
    node poly1, poly2, res;
    poly1 = new_node();
    poly2 = new_node();
    res = new_node();
    poly1->link = poly1;
    poly2->link = poly2;
    res->link = res;

    printf("\nEnter the first polynomial \n");
    poly1 = read_poly(poly1); //inputting polynomial 1
    printf("\nEnter the second polynomial \n");
    poly2 = read_poly(poly2); //inputting polynomial 2

    res = poly_add(poly1, poly2, res); //Calculating resultant polynomial

    printf("\nPolynomial 1:\t");
    display(poly1); //displaying polynomial 1
    printf("\nPolynomial 2:\t");
    display(poly2); //displaying polynomial 2
    printf("\nPolynomial Result:\t");
    display(res); //displaying resultant polynomiam
    return 0;
}