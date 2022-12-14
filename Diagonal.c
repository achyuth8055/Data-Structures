
//  EX: matrix  
// 1000
// 0100
// 0010
// 0001
// implementing 2d matrix in single dimension array



#include <stdio.h>
#include<stdlib.h>
//getter and settter 

struct matrix
{
    int A[10];
    int n;
};

void set(struct matrix *m,int i,int j,int x){
    
    //*m is poointer that is used to change the elements in the 
    //structure array
    // i and j are the index values where x is an value
    if(i == j)
        m->A[i-1] = x;
    
    //to set umber at specfic element
}

int get(struct matrix m,int i,int j){
    
    if(i == j)
        return m.A[i-1];
    else 
        return 0;
    
    //to display number present at specfic array
}

void display(struct matrix m)
{
    //display alla the number in the matrix
    
    for(int i=0;i<m.n;i++)
    {
        for(int j=0;j<m.n;j++)
            {
                if(i==j)
                    printf("%d",m.A[i]);
                else 
                    printf("0");
            }
            printf("\n");
    }
}

int main() 
{ //main method
    
    struct matrix m;
    m.n = 4;
    set(&m,1,1,4); 
    set(&m,2,2,9); 
    set(&m,3,3,3); 
    set(&m,4,4,6);
    
    display(m);
    
    int res = get(m,2,2);
    printf("%d",res);
    
    
    return 0;

}
