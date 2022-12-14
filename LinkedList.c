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

void insertAtBegnning(struct Node *p)
{
    int data;
    printf("enter the data");
    scanf("%d",&data);
    struct Node *inv;
    inv = (struct Node *)malloc(sizeof(struct Node)); // creating new node in heap location
    inv->data = data;                                 //assigning/storinng the node data to x data
    inv->next = first;                                //assigning newNode with first Node 
    first = inv;                                      //assign first = new Node to make the new Node as First Node
} 

void insertAtMiddle(struct Node *p)
{
    printf("enter the data to be added");
    int data;
    scanf("%d",&data);
    printf("Node Position");
    int pos;
    scanf("%d",&pos);
    struct Node *iam;                      //insert At Middle
    iam = (struct Node *)malloc(sizeof(struct Node));        // creating new node in heap location
    iam->data = data;                     // assigning data to the newly created node
    int count=0;  
    while(p)                             //looping throuth all nodes untle the position is reached
    {
        count += 1;                      // increamenting the coutn on every node visit
        p = p->next;                     // p pointing to next pointer 

        if(count == pos-1)               // if position is found executing the below instructions
        {
            iam->next = p->next;         // storing the p's next address in the newly created node so that it will point to next node
            p->next = iam;               // assigning the p->next with the newly created node [p->next will store the address of the iam node]
            break;                      // break the loop
        }
       
    }

}

void main()
{
    int A[] = {2,8,5,12,19,32,6};

    int size = 7;
    createNodes(A,size);
    int swth;
     
    printf("\n1.find sum of all nodes ");
    printf("\n2.find max element in all nodes ");
    printf("\n3.count number of nodes ");
    printf("\n4.display ");    
    printf("\n5.insert data at begenning nodes ");
    printf("\n6.insert at middle of nodes ");
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
        case 5: insertAtBegnning(first);
                display(first);
                break;

        case 6: insertAtMiddle(first);
                display(first);
                break;
        case 4: 
                display(first);
            break;
        default : printf("default condition");
    }

}



