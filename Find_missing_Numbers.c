#include <stdio.h>
#include <stdlib.h>
int main(){
   int arr [] = {6,7,10,12,13,16,17,18};
   int len = 10;
   //10 14 15
   int dif = 6;
   for(int i=0;i<len;i++)
   {
       if(arr[i] - i != dif)
       {
          while(dif < arr[i]-i){
           printf(" Missing NUmbers Are : %d \n",i+dif);
           dif++;
        }
           
       }
   }
}
       
   
