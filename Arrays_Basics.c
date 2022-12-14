//DataStructures Arrays using Pointers basic insertion at specfic index program

#include <stdio.h>
#include <stdlib.h>

struct Array{

    int A[10];
    int size;
    int len;
};
    //inserting the number in bettween array with help of index number
    void insert(struct Array *arr,int index,int val)
    {
        if(index >=0 && index <= arr->len)
        {
            for(int i=arr->len;i>index;i--)
                arr->A[i] = arr->A[i-1];//in loop
            //outof loop
            arr->A[index] = val;
            arr->len++;

        }

    }
//inserting value at end of length
    void append(struct Array *arr,int num)
    {
        if(arr->len <= arr->size)
            arr->A[arr->len++] = num;
    }

//display all array elements
    void display(struct Array arr)
    {
         printf("\n All Array Elements \n");
        for(int i=0 ; i<arr.len; i++)
        {
            printf("%d \n",arr.A[i]);
        }
    }
    //deleting element with index value and shifting all array values to left
    void delete(struct Array *arr,int num)
    {
        printf("Array Before Delete : \n");
        int index = num;
        int x = arr->A[num];
        if(index >= 0 && index <arr->len)
        {

        for(int i=index;i<arr->len-1;i++)
            arr->A[i] = arr->A[i+1];//loop ends
        arr->len -= 1;//decreasing length too -1

        }
        else
            {
        printf("Out Of Bound");

        }

         for(int i=0;i<arr->len;i++)
            printf("%d \n",arr->A[i]);

        printf("Deleted %d \n" , x);

    }
    //linear search with arrays
    // element will be shifted to before index on every sucessess search 
    // best case O(n)
    // wores/avg case O(n)
    int LinearSearch(struct Array *arr,int num)
    {

                for(int i=0;i<arr->len;i++)
                {
                    if(arr->A[i] == num)
                    {
                        //swapping the number if found
                        arr->A[i] = arr->A[i] + arr->A[i-1];
                        arr->A[i-1] = arr->A[i] - arr->A[i-1];
                        arr->A[i] = arr->A[i] - arr->A[i-1];
                        return i;
                    }
                }
                return -1;
    }

    //binary Search Algorithm 
    //best case  o(n)
    // avg or worse O(log n)
    int search(struct Array *arr ,int start,int end,int find)
    {
        //sort array if not in sorted 
        if(end>=start)
        {
            int mid = start+end/2;
            if(arr->A[mid] == find)
                return mid;
            else if(find > arr->A[mid])
                return search(arr,mid+1,end,find);
            else if(find < arr->A[mid])
                return search(arr,start,mid-1,find);

        }
        return -1;
    }
    //reversing the Given Array Elements With Pointers
    int reverseArray(struct Array *arr){
        // swaping method is used to replace elemnts 
        // using 2 variable swaping is performed
        int j = arr->len-1;
        for(int i=0;i<j;i++)
        {
            arr->A[i] = arr->A[i] + arr->A[j];
            arr->A[j] = arr->A[i] - arr->A[j];
            arr->A[i] = arr->A[i] - arr->A[j];
            j--;
        }

         for(int i =0; i<arr->len;i++)
                {
                    printf("%d \t",arr->A[i]);
                }
        return 0;
    }

    int main()
    {

        struct Array arr = {{2,8,6,4,9,7,3},10,7};
        int ch = 1;
        while(ch)
        {
             printf("Enter the number :");
             int cho;
             printf("\n 1. Append Number : ");
             printf("\n 2. Insert number Between Array : ");
             printf("\n 3. Delete Number Between Array : ");
             printf("\n 4. Linear Search Array : ");
             printf("\n 5. Display All Array Elements : ");
             printf("\n 6. Search Element in Array : ");
             printf("\n 7. Reversing All The Element in Array : ");

             scanf("%d",&cho);
             if(cho == 0)
                ch = 0;

         switch(cho)
         {
         case 1 : // inserting elemnt in array at last index if memory space avaliable
                {
                int n;
                printf(" \n enter the number to append ");
                scanf("%d",&n);
                append(&arr,n);
                }
                 break;

         case 2 : //inserting the value in array at perticular index number
                 {
                int index,m;
                printf(" \n enter the Index to Value \n");
                scanf("%d",&index);
                printf(" \n enter the Value to insert \n");
                scanf("%d",&m);
                insert(&arr,index,m);
                }
                break;

         case 3 :
                { //deleting the number at perticular index and re arranging the array
                int u;
                printf(" \n enter the number to Delete ");
                scanf("%d",&u);
                delete(&arr,u);//passing index
                }
                break;

        case 4 :
            {   //linear search function operation
                int num;
                printf(" \n enter the number to Search ");
                scanf("%d",&num);
                printf("%d \n",LinearSearch(&arr,num));
            }

                break;

        case 5 : //displaying the all elements in array
                display(arr);
                break;
        case 7: //reversing array with pointers
                reverseArray(&arr);               
        break;
                 
        case 6 : {
                //Binary Search Algorithm
                int find;
                int start = 0;
                printf("enter the number to find : \n");
                scanf("%d",&find);
                int end = arr.len-1;
                //printf("%d is length of array \n",end);
                int res = search(&arr,start,end,find);
                if(res == -1)
                  printf("Number not found in the array \n", res);
                else
                    printf("Number found at Index[ %d ] : \n",res);

        }
                break;
                 
         default : break;
         }

        }

        printf("%d \n",arr.len);

    }
