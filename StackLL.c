//stack using linked list 

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
    }*first;

int isNILL(struct Node *p)
{
    if(!p)
        return 1;
    return 0;
}

void create(int data)
{
    struct Node *temp,*last;
    if(isNILL(first))
        {
            first = (struct Node *)malloc(sizeof(struct Node));
            first->data = data;
            first->next = NULL;
        }
        else{
            temp = (struct Node *)malloc(sizeof(struct Node));
            if(temp == NULL)                
                printf("Stack is FULL");
            else
            {  
            temp->data = data;
            temp->next = first;
            first = temp;
            }
        }
}

void display(struct Node *p)
{
    while(p){
        printf("%d \n",p->data);
        p = p->next;
    }
}

void pop(struct Node *p)
{
    struct Node *top = p;

    if(top == NULL)    
        printf("Stack IS Already Empty.");
    else{
        p = p->next;
        free(top);
        first = p;
    }
}
void insertTop(struct Node *p)
{
    struct Node *temp;
    printf("enter the data");
    int data;
    scanf("%d",&data);
    create(data);
  
}

void getTop(struct Node *p)
{
    if(isNILL(p))
        printf("Stack Is Empty");
    else
        printf("%d",p->data);
}

void peek(struct Node *p,int index)
{
    int count=1;
    while(p)
    {   
        if(count == index)
            break;
        else{
        count++;
        p = p->next;
        }
    }
    if(p)
        printf("%d is present at %d pos",p->data,index);
    else
        printf("invalid index");
}

void main()
{
    create(10);
    create(20);
    create(30);
    create(40);
    create(50);

    printf("\n Select Choice : \n");
    printf("1.POP Element From Stack \n");
    printf("2.Check Stack Is Empty.? \n");
    printf("3.Push on TOP \n");
    printf("4.Check Number Present At Perticulat Index.? \n");
    printf("5.Get Top Value Of Stack.? \n");
    printf("6.Display Complete Stack \n");

    int ch;
    scanf("%d",&ch);
    switch(ch)
    {
        case 1: pop(first);
                display(first);
                break;

        case 2: printf("%d",isNILL(first));
                break;
        case 3: insertTop(first);
                display(first);
                break;
        case 4: peek(first,5);
                break;
        case 5: getTop(first);
                break;
        case 6: display(first);
                break;
        default :
                printf("Default :");

    }


}
