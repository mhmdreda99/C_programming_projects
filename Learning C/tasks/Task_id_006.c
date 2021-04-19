/**
 * @file Task_id_006.c
 * @author mhmdreda99 (Moreda491999@gmail.com)
 * @brief Program keep asking user to input integer numbers and when sum>100 it prints the result 
 * @version 0.1
 * @date 2021-01-09
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include<stdio.h>
#include<stdlib.h>
#include <conio.h>
int main ()
{
    int input , sum =0 ;
    while (!(sum>100))
    {
        printf("Please Enter an integer :");
        scanf("%d",&input);
        sum+=input;
    }
    printf("Sum of numbers you entered is = %d",sum);
   
    return 0 ;


}

	


