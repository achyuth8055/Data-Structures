//swaping -ve numbers to left and -Ve number to right side in array using pointers
//inserting the elemet at perticular index in sorted array
#include<stdio.h>
#include<stdlib.h>

struct Array {

       int A[10];
       int size;
       int len;
};


    void sortArray(struct Array *arr)
    {
        int l = arr->len-1;
        int i = 0;

        while(i < l)
        {
            if(arr->A[i] < 0)
               i++;
            else if(arr->A[l]>0)
                    l--;
            else {

                arr->A[i] = arr->A[i] + arr->A[l];
                arr->A[l] = arr->A[i] - arr->A[l];
                arr->A[i] = arr->A[i] - arr->A[l];
            }  

        }
    }

void main()
{
    struct Array arr ={{-6,3,-8,1,-3,4,-7,11},10,8};
    sortArray(&arr);

    for (int i = 0; i < arr.len; i++)   
        printf("%d ",arr.A[i]);

}

//check if array is sorted or not
    // int isSorted(struct Array arr)
    // {
        
    //     for(int i=0;i<arr.len-1;i++)
    //     {
    //         if(arr.A[i] > arr.A[i+1])
    //             return -1;
    //     }
    //     return 1;
    // }
//    int insertElement(struct Array *arr,int indx,int val)
//     {

//         if(indx >=0 && indx <= arr->len)
//         {
//             for(int i=arr->len;i>indx;i--)            
//                 arr->A[i] = arr->A[i-1];
            
//             arr->A[indx] = val;
//             arr->len++;
            
//         }

//         return 0;

//     }
//insert element in sorted array with pointers
//-ve and +ve value re arrangment in array Unsorted
    // int main()
    // {
    //     struct Array arr = {{2,4,6,8,12,33},10,6};
    //     int indx;
    //     int val;

    //     printf("Enter the index to insert value : \n");       
    //     scanf("%d",&indx);

    //     printf("Enter the Value to insert value : \n");
    //     scanf("%d",&val);

    //     insertElement(&arr,indx,val);
    //     printf("Array after insertion :");

    //     for(int i=0;i<arr.len;i++)
    //     {
    //         printf("%d\t",arr.A[i]);
    //     }



    // }



