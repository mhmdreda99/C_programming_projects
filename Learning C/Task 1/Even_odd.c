/**
 * @file Even_odd.c
 * @author Mohamed Reda 
 * @brief this a simple program that detect an entered number whether it even or odd .
 * @version 0.1
 * @date 2020-12-11
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int num ; 
    char optional ;
    printf("\r\n\tPlease Enter a number:");
    scanf("%d",&num);
    
    if (num%2==0){
        printf("\r\n\tthe number you entered is even");
    }
    else
    {
       printf("\r\n\tthe number you entered is odd");
    }

printf(" \r\n\t do you want to continue press y/n ?? \n");
optional=getche();
while (optional=='y');
getch();
return 0 ;
}
