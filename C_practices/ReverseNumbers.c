/**
 * @file ReverseNumbers.c
 * @author Mohamed Reda
 * @brief progrm that Reverse any number entered from
 * @version 0.1
 * @date 2020-12-21
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include<stdio.h>
#include<stdlib.h>

int main()
{
    unsigned int num;
    int rev_num= 0 ,reminder,temp;
    printf("Please Enter a Number :");
    scanf("%d",&num);
   

    while (num!=0)
    {
        reminder=num %10 ;
        // rev_number equation 
        rev_num=rev_num*10 +reminder;
        num/=10 ;

    }
    
    printf("Reverse number is  is =%d",rev_num);

    return 0 ;
}
