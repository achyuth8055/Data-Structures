
//Usinf HashMap Method O(n)
#include <stdio.h>
struct Duplicates
{
    int array[10];
    int size;
    int length;
};

void FindDuplicates(struct Duplicates dup,int max)
{
    int H[max+1];
    for(int i=0;i<= max;i++)
        H[i] = 0;
    
    for(int i=0;i<dup.length;i++)
        H[dup.array[i]]++;
    
    for(int i=0;i<max+1;i++)
        {
            if(H[i]>1)
                printf("%d is appearing %d \n",i,H[i]);
        }
    
}


int main()
{
    struct Duplicates dup={{2,2,3,4,4,4,5,6,6,7},10,10};
    FindDuplicates(dup,7);
    
    
}


//normal method O(n2)


#include <stdio.h>

//find duplicates of array

int main() {

    // Write C code here
    int arr [] ={5,5,1,2,7,2,5,3,4,6,7};
    int len = 11;
   
    for(int i=0;i<len;i++)
    {
        if(arr[i] != -1)
        {
         int count =1;
        for(int j=i+1;j<len;j++)
        {
            if(arr[i] == arr[j])
            {
                count++;
                arr[j] = -1;
            }
            
        }
        if(count >1)printf("%d Times %d is Repeated \n",count,arr[i]);
        }
    }
    
   

        
    return 0;
}

