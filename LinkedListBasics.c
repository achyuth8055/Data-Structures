#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
    }*first;

void insertAtMiddle(struct Node *p)
{

    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    int count = 1;
    int pos,data;
    printf("enter the position to insert in node");
    scanf("%d",&pos);
    printf("enter the data to insert in node");
    scanf("%d",&data);

    while(p)
    {
        p = p->next;
        count++;
        if(count == pos-1)
        {
            temp->data = data;
            temp->next = p->next;
            p->next = temp;
            break;
        }
    }

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

void display(struct Node *p)
{   
    
        if(p)
        {
            printf("%d \n",p->data);
            
            display(p->next);
        }
}

void insertAtLast(struct Node *p){

    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));

    printf("enter the data to insert at last node");
    int data ;
    scanf("%d",&data);
    temp->data = data;
    temp->next = NULL;

    while(p)
    {
        if(p->next == NULL)
        {
            p->next = temp;
            p=temp;
            break;
        }

        p=p->next;
    }

}

void insertAtBeginning(struct Node *p)
{
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));

    int data;
    printf("enter the data");
    scanf("%d",&data);
    temp->data = data;
    temp->next = p;
    p = temp;

    while (p)
    {
        printf("%d \n",p->data);
        p = p->next;
    }
    
}

void insertB(int data)
{
    //normal linked list withut array
    struct Node *temp,*last;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;

    if(first == NULL)    
        first = last = temp;
   
    else{

        last->next = temp;
        last = temp;
    }
     
}

void displayNode(struct Node *p)
{
    while(p)
    {
        printf("%d \n",p->data);
        p = p->next;
    }
}

void insertInSortedList(struct Node *p)
{

        int data = 18;

        struct Node *temp; 
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = data;
       // printf("%d",p->next->data);
        while(p)
        {
       if(data < p->next->data)
       {
            temp->next = p->next;
            p->next = temp;
            break;
       }
       p = p->next;
        }


}

void sort(struct Node *p)
{
    
   struct Node *temp;

   temp = p;

   while(temp)
   {    

        temp->next = p->next;
       
        if(p->data > temp->data)
        {
            printf("%d \n",p->data);
            p = p->next;
            temp = p;            
           
        }

        if(temp->next == NULL)
                printf("end nodes");
        

        temp = temp->next;

   }
        
 
}

void main()
{
        int A[] ={2,6,9,13,17,21,30}; //2,3,4,5,7,9,10
        int length = 7;
        createList(A,length);
            int option;
            printf("1.insert at End \n");
            printf("2.insert at Middle \n");
            printf("3.Sort And Display \n");
            printf("4.create and display node \n");
            printf("5.Insert At Beginning \n");
            printf("6.Insert At Sorted List \n");
            scanf("%d",&option);
            switch(option)
            {
                case 6:
                        insertInSortedList(first);
                        display(first);
                        break;
               case 5:
                       insertAtBeginning(first);
                       display(first);
                        break;
               
                case 4: 
                        insertB(5);
                        insertB(4);
                        insertB(7);
                        insertB(9);
                        insertB(15);
                        displayNode(first);                     
                
                        break;

                case 1:
                        insertAtLast(first);
                        display(first);
                    break;

                case 2:
                        insertAtMiddle(first);
                        display(first);
                    break;

                case 3:
                        sort(first);
                        display(first);
                        break;

                default : printf("default");
            }

            
}
