/**
 * @file Factorial_Using_Pointer.c
 * @author mhmdreda99 (Moreda491999@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-01-05
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include<stdio.h>           
#include<conio.h>          
//Fcatorial Function Header Declaration
void Factori(int,  long int *);   
int main(){
         long int factorial;
         int num;
         printf("Please Enter an Integer number: ");
         scanf("%d",&num); // ask user to enter a number
         printf("============================================================\n\r");  

         Fact(num, &factorial);      //Function Call
         printf("Factorial of %d is =  %ld", num, factorial);
         
        return 0 ;
        }
/*****************************************************************************
*                          Functions definition
*****************************************************************************/
/**
 * @brief 
 * Function definition for finding Factorial of the given Integer using Pointer
 * @param is an input number
 * @param factorial pointer 
 */
 
void Fact(int n,  long int *factorial){
        int i;

       *factorial =1;
       for(i=1;i<=n;i++)
       *factorial=*factorial*i;
       }

 