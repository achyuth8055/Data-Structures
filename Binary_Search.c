//binary Search algorithm
// Input: arr[] = {1,2,3,4,5,6};, find = 5
// Output: 5
// Input: arr[] = {1,2,3,4,5,6};, find = 10
// Output: -1
#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int arr[] = {1,2,3,4,5,6};
    int beg = 0;
    int end = sizeof(arr)/4;                        //to get lengt of array we divide sizeof array /4 each int takes 4 bytes space
    //printf("%d",end);                             //chech the length of array here
    int res = 0;                                    //optional 
    int find = 67;                                  // we ca use scanf insed of assigning a value
    res = search(&arr,beg,end,find);                // calling the search method with parameters array,beginning=0,end=6,and find=67
    if(res != -1)                                   // after reciving some x value in return will be storedin res variable and compare. it with -1 if its -1 then no element found 
    printf(" found at %d",res);                     // here were printing the index or array position 
    
    else printf("Not Found");                       // if not avaliable

}

int search(int *arr,int beg,int end,int find)       //search function definition contins all 4 parameters 
{
    
    if(end>=beg)                                   //checking end value should be grater or equal to beginning 
    {
        int mid = (beg+end)/2;                      // mid to get mid value we will add both (beginning + end) /2 ex : 0+6/2 = 3 mid = 3
        if(arr[mid]==find)                          //if we found the target value at first iteration then will return mid+1 value to called function
        {
            //printf("Found @ %d",mid+1);
            return mid+1;                           //return ing the mid+1 to main function
        }
            
        else if(find > arr[mid])                    //else the target is > array[middle] value then will assign Begging = middle+1 and call the function with updated parameter values of begging 
        {
             beg = mid + 1;
            return search(arr,beg,end,find);        // calling the searchmethod itself 
        }
     else if(find < arr[mid])                       //else if target is less then middle array then will return search function with array, begging,mid-1,find 
          return search(arr,beg,mid-1,find);        // here we wil not pass end because we have to search the target value between 0 - mid value so end will becomes mid-1
                
    }
    return -1;                                      //if element is not present in complete array it will return -1 that means the target value is not avaliable
}
