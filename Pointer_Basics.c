#include <stdio.h>
#include <stdlib.h>

struct Array {

    int nums[10];
    int len;
    int size;

};
// getting array value with given index

int get(struct Array arr,int index)
{
    if(index >= 0 && index <= arr.size){
        return arr.nums[index];
    }
}
//setting vallue at perticular index with index value

int set(struct Array *arr,int index,int val)
{
    if(index >= 0 && index <= arr->size){
        arr->nums[index] = val;
        return arr->nums[index];
    }
}

//finding the max element in unsorted array
int max(struct Array arr)
{
    int max = 0;
    for(int i=0;i<arr.len;i++)
    {
        max = arr.nums[0];
        if(arr.nums[i] > max)
            max = arr.nums[i];
    }
    return max;
}

//finding the minimum number in given unsorted array
int min(struct Array arr)
{

   int min = arr.nums[0];
    for(int i=0;i<arr.len;i++)
    {

        if(arr.nums[i] < min)
            min = arr.nums[i];
    }
    return min;
}

int average(struct Array *arr)
{
    int avg = 0;

    for(int i=0;i<arr->len;i++)
    {
        avg = avg + arr->nums[i];
    }
    avg = avg/arr->len;
    return avg;

}

int main()
{

    struct Array arr={{26,23,4,8,16,79},6,10};
    //int index = 3;
    printf("the element at this index is : %d \n",get(arr,4));
    printf("Inserted Element at index : %d \n",set(&arr,4,16));
    printf("Maximum Element in given Array : %d \n",max(arr));
    printf("minimum number Element at index : %d \n",min(arr));
    printf("average value in an array Element at index : %d \n",average(&arr));
    printf("the element at this index is : %d \n",get(arr,4));

    //printf("size of array is : %d \n",res);
    return 0;
}
