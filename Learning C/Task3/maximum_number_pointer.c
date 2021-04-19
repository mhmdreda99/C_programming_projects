/**
 * @file maximum_number_pointer.c
 * @author mhmdreda99 (Moreda491999@gmail.com)
 * @brief  program in C to find the maximum number between two numbers using a pointer.
 * @version 0.1
 * @date 2021-01-05
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>
#include <stdlib.h>
int main()
{
 int Num1,Num2;
 int *pNum1=&Num1;
 int *pNum2=&Num2;
 
   printf(" Please Enter the first Input : ");
   scanf("%d", pNum1);
   printf(" Please Enter the second Input : ");
   scanf("%d", pNum2); 
   printf("============================================================\n\r");  
if (*pNum1==*pNum2)
{
   printf("Are You Crazy >> Enter different values");
   return 0 ;
}

 if(*pNum1>*pNum2)
 {
  printf("the First input :%d is the maximum number.\n\n",*pNum1);
 }
 else
 {
  printf("\nthe Second input = %d is the maximum number.\n\n",*pNum2);
 }

}