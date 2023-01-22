//[]{}() = valid
//() = valid
//[] = valid
// [] (( = Not Valid
// ][ = not valid
// []{(} Not Valid
#include<stdio.h>
#include<stdlib.h>

struct Node {
    char data;
    struct Node *next;
}*first;

char pop(struct Node *p)
{
    struct Node *t;
    char ch;
    t = first;
    t = t->next;
    ch = first->data;
    free(first);
    first = t;
    return ch;
}

void push(char data)
{
    struct Node *temp;
    if(first==NULL)
    {
        first = (struct Node *)malloc(sizeof(struct Node));
        first->data = data;
        first->next = NULL;
    }

    else{
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = data;
        temp->next = first;
        first = temp;
    }
}

int matching(char open,char close)
{   
    int res = 0;

    if(open=='(' && close ==')')
        res = 1;
    if(open=='{' && close =='}')
        res = 1;
    if(open=='[' && close ==']')
        res = 1;

    return res;
}

int validate(char *exp)
{ 
    for(int i=0; exp[i] != '\0'; i++)
    {
            char open,close; //{ = open  } = close
            if(exp[i]=='(' || exp[i]=='[' || exp[i]=='{')
                push(exp[i]);

            else if(exp[i]==')' || exp[i]==']' || exp[i]=='}')
                {
                     open = pop(first);
                     close = exp[i];
                     if(!matching(open,close))
                        return 0;
                }     
    }

    if(first == NULL)
        return 1;
    else
        return 0;
}
void main()
{
    //main method
    char *array = "((";
    int size = 7;
    if(validate(array))
        printf("Valid");
    else
        printf("Not A Valid Expression");


}
