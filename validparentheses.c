#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack
{
    char *exp;
    int top;
    struct Node *next;
} *first;

int isEmpty()
{
    if(first)
        return 0;
    else 
        return 1;
}
void push(char exp)
{
    struct Stack *temp;
    if (first == NULL)
    {
        first = (struct Stack *)malloc(sizeof(struct Stack));
        first->exp = exp;
        first->next = NULL;
        first->top++;
    }
    else
    {
        temp = (struct Stack *)malloc(sizeof(struct Stack));
        temp->exp = exp;
        temp->next = first;
        temp->top++;
        first = temp;
    }
}

void pop()
{
    struct Stack *t = first;
    if (!first)
        printf("Stack Under Flow \n");
    else{
        t = first;
        t->top = t->top-1;
        t = first->next;
        free(first);
    }
    first = t;
}

void validate(char *exp)
{
        struct Stack *t;
        for(int i=0;exp[i]!='\0';i++)
        {
            if(exp[i]=='(')
                push(exp[i]);
            else if(exp[i] == ')')
            {
                if(!first){
                    printf("Invalid ()");
                    exit(0);}
                else
                    pop();  
            }
        }

        if(isEmpty(first))
            printf("valid()");
        else
            printf("invalid");
}



void main()
{
    struct Stack st;
    char *exp = "((a+b)*(a-b))";
    int size = strlen(exp);
    // create stack
    validate(exp);
}
