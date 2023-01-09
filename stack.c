#include<stdio.h>
#include<stdlib.h>

struct Stack {

    int size;
    int *Array;
    int top;
};

void create(struct Stack *st)
{       
        printf("Enter the Size of Stack :");
        scanf("%d",&st->size);
        st->top = -1;
        st->Array = (int *)malloc(st->size*sizeof(int ));
        //printf("Array size is : %d",st->size);
}

void push(struct Stack *st,int data)
{

    if(st->top == st->size-1)
        printf("Stack Is FULL");
    else
    {
        st->top++;
        st->Array[st->top] = data;
    }

}

int isEmpty(struct Stack *st)
{
    if(st->top == -1)
        return 1;
    return 0;
}

int isFull(struct Stack *st)
{
        if(st->top == st->size-1)
            return 1;
        return 0;
}

void peek(struct Stack *st,int pos)
{

    if(pos < 0 || pos > st->size-1)
        printf("Invalid Index : %d",pos);

    else{
        
        int x = st->Array[st->top - pos + 1];
        printf("%d",x);
    }
}

    void stackTop(struct Stack *st)
    {
        if(st->top == -1)            
                printf("Stack Is Empty \n");
            
        else
            printf("%d is Present at Top Of Stack \n",st->Array[st->top],st->top);
        

    }

    void display(struct Stack st)
    {
            printf("\n");
            for(int i=st.top;i>=0;i--)
            {
                printf("%d \n",st.Array[i]);
                st.top -= 1;
            }
    }

void pop(struct Stack *st)
{   

    if(st->top == -1)
        printf("Can't Pop Coz Stack Is Empty :");
    
    else{
         
         printf("%d is Deleted from the Stack \n",st->Array[st->top]);
         st->top -= 1;
    }

}
 void main()
  {

    struct Stack stack;
    create(&stack);

    //push in to the stack

    push(&stack,10);
    push(&stack,20);
    push(&stack,30);
    push(&stack,40);
    push(&stack,50);
    

    //delete the valu from stack

    //pop(&stack);

    // isFULL

   // printf("%d",isFull(&stack));

    //isEmpty

    //isEmpty(&stack);
    //printf("%d",isEmpty(&stack));
    //value at perticular index

    //peek(&stack,1);
    
    // stack top

     stackTop(&stack);

    //display all the elements in stack

   display(stack);


}
