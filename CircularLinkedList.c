
#include <stdio.h>
#include<stdlib.h>

struct Node{int data;struct Node *next;}*first;

int length(struct Node *p)
{
   int len=0;
    do
    {
    len++;
    p=p->next;
    }while(p != first);
    return len;
}
void InsertCList(struct Node *p,int pos,int data)
{
            struct Node *temp;
   //if the index is 0 or Grater then List size
          if(pos < 0 || pos > length(p))
            printf("Invalid Index \n");
      // Insert at 0 Position
            if(pos == 0)
            {
                temp = (struct Node *)malloc(sizeof(struct Node));
                temp->data = data;
                if(first == NULL)
                {    //if the first node
                    first = temp;
                    first->next = first;                
                }
                else {  //if already nodes exist in the list
                        while(p->next != first) p = p->next;
                        p->next = temp;
                        temp->next = first;
                        first = temp;
                }               

            }
            else{
                  // inserting at specfic position
                for(int i=0;i<pos-1;i++)
                    p = p->next;
                temp = (struct Node *)malloc(sizeof(struct Node));
                temp->data = data;
                temp->next = p->next;
                p->next = temp;
     
            }
        
}

void create(int data)
{
    struct Node *temp,*last;
    if(first == NULL)
    {   
        first = (struct Node *)malloc(sizeof(struct Node));
        first->data = data;
        first->next = NULL;
        last = first;
    }
    else{
    
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    last->next = temp;
    last = temp;
    }
    
    last->next = first;
}

void display(struct Node *p)
{       
        do{
            printf("%d \n",p->data);
            p = p->next;
        }
        while(p != first);
}

void deleteCLL(struct Node *p,int index)
{
    struct Node *temp,*follow;
    temp = first;
    if(index <=0 && index > length(p))
        printf("Invalid Index");
    
    if(index == 1)
    {   
        while(p->next != first)
            p = p->next;
        
        p->next = first->next;
        free(first);
        first = p->next;
    }
    else{

        for(int i=1;i<index-1;i++)
            p = p->next;
        
        follow = p->next;
        p->next = follow->next;
        free(follow);

    }

   
}

int main() {
    
     create(1);
     create(2);
     create(3);
     create(4);
     InsertCList(first,0,5); //pointer ,index ,data
     //deleteCLL(first,1);
     //deleteCLL(first,0);
     deleteCLL(first,5);
     display(first);
    return 0;
}
