#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node *prv;
    int data;
    struct Node *next;
}*first;

void create(int data){

    struct Node *temp,*last;
    if(first == NULL)
    {
        first = (struct Node *)malloc(sizeof(struct Node));
        first->prv = NULL;
        first->data = data;
        first->next = NULL;
        last = first;
    }
    else{
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->prv = last;
        temp->data = data;
        temp->next = NULL;
        last->next = temp;
        last = temp;

    }
}

void DisplayDLL(struct Node *p)
{

    //  int count = 0;
    //  struct Node *temp;
   
    // temp = first;
    // while(temp->next != NULL){    
    //     temp = temp->next;
    //     count += 1;
    // }
    
    // while(temp != first)
    // {
    //     printf("%d \n",temp->data);
    //     temp = temp->prv;
    // }    
    // printf("%d \n",temp->data);

    while(p)
    {
        printf("%d \n",p->data);
        p = p->next;
        
    }
 
}

int length(struct Node *p)
{
    int count = 1;   
    while(p)
    {   count += 1;
        p = p->next;
    }return count;
}

void insert(struct Node *p,int index,int data)
{
    struct Node *follow;
     if(index < 0 || index > length(p))
     {
        printf("Exit Status Code 0:");
        exit(0);
     }
    for(int i=1;i<index-1;i++)
        p = p->next;

    follow = p->next;
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    if(index == 0)
    {
        if(first == NULL)
        {
            temp->prv = NULL;
            temp->next = NULL;
            first = temp;
        }else{
            temp->prv = NULL;
            temp->next = first;
            first->prv = temp;
            first = temp;
        }
    }
    
    else{
        
        temp->prv = p;
        temp->next = p->next;
        if(p->next)
            p->next->prv = temp;
        p->next = temp;

    }
}
void deleteDLL(struct Node *p,int index)
{

    if(index == 0 && p != NULL && p->next != NULL)
    {   
        p = p->next;
        free(first);
        first = p;
    }
   else{
    
     for(int i=0; i<index-1;i++)
        p = p->next;
    if(!p->next)
        {   p->prv->next = NULL;
            free(p);
        }else{
    p->prv->next = p->next;
    p->next->prv = p->prv;
    free(p);

        }
   }
}
void reverseDLL(struct Node *p)
{
    struct Node *temp;
    while(p)
    {
        temp = p->next;
        p->next = p->prv;
        p->prv = temp;
        p = p->prv;

         if(p != NULL && p->next == NULL)
            first = p;
    }
    
}

void circularDLL(struct Node *p)
{
    while(p->next != NULL)    
        p = p->next;
 
   // printf("%d",p->data);
    p->next = first;
    first->prv = p;
}

void displayCDLL(struct Node *p)
{
        struct Node *temp = first;
        do{
            printf("%d \n",p->data);
            p = p->next;
        }while(p != temp);

}

void main()
{
    create(1);
    create(2);
    create(3);
    create(4);
    create(5);
    create(6);
    create(7);
    create(8);
    //insert(first,9,50);
    //deleteDLL(first,8);
   // reverseDLL(first);
    circularDLL(first);
    displayCDLL(first);
    // DisplayDLL(first);
}
