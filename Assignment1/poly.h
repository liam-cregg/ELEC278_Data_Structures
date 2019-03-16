#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    double coef;
    int exp;
    Node* next;
} Node;

typedef struct Poly
{
    Node *root;
    int degree;
} Poly;

Node *initNode(int e, Node *nxt)
{
    Node *p = (Node*)malloc(sizeof(Node));
    if(p != NULL)
    {
    p->exp = e;
    p->next = nxt;
    }
    return p;
}//initializing a node (represents a polynomial term)

void initPoly(Poly *p)
{
    p->degree = -1;
    p->root = NULL;
}//initializing a linked list called Poly

void createPoly(Poly *p1, int d)
{
    for (int i = 0; i <= d; i++)
    {
        p1->degree++;
        Node *p = initNode(i, p1->root);
        p1->root = p;
    }//going from 0 to degree, creating nodes witht the corresponding degree
}

double getCoefficient(int n, Poly *p1)
{
    Node *p = p1->root;
    for (int i = 0; i < (p1->degree - n); i++)
    {
        p = p->next;
        if(p == NULL) return 0;
    }
    return p->coef;
}//move degree-n spaces forward in the polynomial, return coef

int setCoefficient(int n, double c, Poly *p1)
{
    Node *p = p1->root;
    for (int i = 0; i < (p1->degree - n); i++)
    {
        p = p->next;
        if(p == NULL) return 0;
    }
    p->coef = c;
}//move degree-n spaces forward in the poly, set coef

Poly *plus(Poly *p1, Poly *p2)
{
    Poly *pNew;
    initPoly(pNew);
    int d;
    if(p1->degree >= p2->degree)
        d = p1->degree;
    else d = p2->degree;
    createPoly(pNew, d);
    for (int i = 0; i <= (pNew->degree); i++)
    {
        setCoefficient(i, getCoefficient(i, p1) + getCoefficient(i, p2), pNew);
    }//setting each coef from 0 to degree to the sum of the corresponding terms in p1 and p2
    return pNew;
}

void display(Poly *p1)
{
    if (p1->degree == -1)
        printf("No polynomial entered\n");
    else
    {
        for (int i = 0; i <= p1->degree; i++)
        {
            printf("%3.1fx^%d + ", getCoefficient(p1->degree - i, p1), p1->degree - i); 
        }
    }
    printf("\n");
}


