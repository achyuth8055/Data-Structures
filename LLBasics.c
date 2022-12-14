#include<stdio.h>
#include<stdlib.h>
struct Node{

    int data;
    struct Node *next;

}*first;

void createNodes(int A[],int size)
{

        struct Node *temp,*last;
        first = (struct Node *)malloc(sizeof(struct Node));
        first->data = A[0];
        first->next = NULL;
        last = first;
        int i = 1;
        while(i < size)
        {
            temp = (struct Node *)malloc(sizeof(struct Node));
            temp->data = A[i];
            temp->next = NULL;
            last->next = temp;
            last = temp;
            i++;
        }
        
}
void sumOfNodes(struct Node *p)
{
        int sum =0;
        while(p)
        {
           sum += p->data;
           p = p->next; 
        }

        printf("%d",sum);

}

void display(struct Node *p)
{

        if(p)
        {
            printf("%d \n",p->data);
            display(p->next);
        }
}

void nodeCount(struct Node *p)
{

        int count =0;
        while(p != NULL)
        {
            count += 1;
            p = p->next;
        }

         printf("%d",count);
}

void nodeMax(struct Node *p)
{

        int max = 0;
        while(p)
        {
            if(max < p->data)
                max = p->data;

           p = p->next; 
        }

        printf("%d",max);
}


void main()
{
    int A[] = {2,8,5,12,19,32,6};

    int size = 7;
    createNodes(A,size);
    int swth;
     
    printf("\nfind sum of all nodes ");
    printf("\nfind max element in all nodes ");
    printf("\ncount number of nodes ");
    printf("\ndisplay ");    
    
    scanf("%d",&swth);   
    switch(swth)
    {
        case 1: 
                sumOfNodes(first);
            break;
        case 2: nodeMax(first);
            break;
        case 3:  nodeCount(first);
            break;
        case 4: 
                display(first);
            break;
        default : printf("default condition");
    }

}



