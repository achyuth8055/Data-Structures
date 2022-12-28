#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
    }*first,*second,*third;

void merg(struct Node *p,struct Node *q)
{
    //p = first 
   //q = second
  
    struct Node *last;
    if(p->data < q->data)
    {
        third = last = p;
        p = p->next;
        last->next = NULL;
    }
    else
    {
        third = last = q;
        q = q->next;
        last->next = q;
    }
    //loop till last node
    while(p && q)
    {
        if(p->data < q->data)
        {
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        }
        else
        {
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }
    if(p)
        last->next = p;
    else
        last->next = q;
}


void createList(int A[],int size)
{

        struct Node *temp,*last;
        first = (struct Node *)malloc(sizeof(struct Node));
        first->data = A[0];
        first->next = NULL;
        last = first;
        int i = 1;

        while(i<size)
        {
            temp = (struct Node *)malloc(sizeof(struct Node));
            temp->data = A[i];
            temp->next = NULL;
            last->next = temp;
            last = temp;
            i++;
        }

}

void createList2(int B[],int size)
{

        struct Node *temp,*last;
        second = (struct Node *)malloc(sizeof(struct Node));
        second->data = B[0];
        second->next = NULL;
        last = second;
        int i = 1;

        while(i<size)
        {
            temp = (struct Node *)malloc(sizeof(struct Node));
            temp->data = B[i];
            temp->next = NULL;
            last->next = temp;
            last = temp;
            i++;
        }

}

void display(struct Node *p)
{   
    
        if(p)
        {
            printf("%d \n",p->data);
            
            display(p->next);
        }
}
void main()
{
        int A[] ={10,15,45,50,60}; //2,3,4,5,7,9,10
        int B[] ={12,20,30,55,70};
        int length = 5;
        createList(A,length);
        createList2(B,length);
        merg(first,second);
        display(third);
}

