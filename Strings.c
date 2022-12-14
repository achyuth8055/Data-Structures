//Basic String Concepts With String Operations
//1. convert Given String to Upper - Lower & Lower - Upper
//2.counting Ovel in given String using for and while
//2.counting Number of Words in given String using for and while ex: how are    you.
//3.verifing givie string is valid or not ex: Achyuth123 valid . Achy!123 : invalid

#include<stdio.h>
#include<stdlib.h>

//verifying the given Sting
int verify()
{
    char *string2 = "achyuth123";
    char *string = "achyuth!123";
    for(int i=0;string[i] != '\0';i++)
    {       
        if(!(string[i] >= 65 && string[i] <= 90) && !(string[i] >= 48 && string[i] <= 57) && !(string[i] >=97 && string[i] <= 122))            
            return 0;
    }

   return 1;

}

//word count
void words()
{
    char words[] = "hai Im Achyuth From   Hyderabad";

    int wordCount = 0;

    for(int i=0;words[i] !='\0';i++)
    {
        if(words[i]==' ')
            if(words[i-1] != ' ')
             wordCount += 1;
    }

    printf("%d",wordCount+1);

}

//count Ovels
void countOvels()
{

    char countOvels[] = "Achyuth";
    int ovelCount =0;
    for(int i=0;i<8;i++)
    {   
        char temp = countOvels[i];
         if(temp == 'A' || temp =='a' || temp == 'e' || temp =='E' || temp == 'I' || temp=='i' || temp == 'o' || temp == 'O' || temp =='u' || temp == 'U')
            ovelCount += 1;
    }
   
    printf("No Of Ovels Present in String is %d",ovelCount);
  
}

//converting
void convert()
{
     char string[] = "Achyuth";

    int strLen = 0;
    for(int i=0;string[i] != '\0';i++)
    {
        strLen += 1;
    }
    
    for(int i=0;i<strLen;i++)
    {
        int temp = string[i];
        //printf("%d \n",temp);
         if(temp >= 65 && temp <= 90)
         {
            string[i] = string[i] +  32;
         }
        else if(temp >= 97 && temp <= 122)
         {
            string [i] = string[i] - 32;
         }
    }
    printf("%s",string);
}

void main()
{
   
   printf("\n 1.Upper to Lower Case : ");
   printf("\n 2.Count Ovels In Given String ");
   printf("\n 3.Word Count In String : ");
   printf("\n 4.Upper to Lower Case : ");
   int ch;
  
    scanf("%d",&ch);
    
    switch (ch)
    {
    case 1 : convert();
           break;

    case 2 : 
            countOvels();
            break;
     case 3 : 
            words();
            break;
    case 4 :
            { int res = verify();
            if(res == 1)            
                printf("valid");
            else
                printf("invalid");
            }

            break;
    
    default: printf("default");
        break;
    }

}
