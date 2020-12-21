/**
 * @file Sum_of_num_digits.c
 * @author Mohamed Reda
 * @brief program that get the some of any number digits 
 * Example : Num=123 ---> sum=1+2+3=6
 * 
 * @version 0.1
 * @date 2020-12-21
 * 
 * @copyright Copyright (c) 2020
 * 
 */


// Libraries
#include<stdio.h> // Library to include Basic C functions for the compiler.

// User-defined header files #include
// User-defined header files #define (Macros: Object / Fuction)
// Type definition
// Function prototype
// Declared Structures (if Type definition)
// Declared Functions
// Global variables (Declaration and Inintialization)
// Enum

int main()
{	
	int num ,i ;
    int digit , sum=0 ;
    //ask user to enter number
    printf("Please enter any number :");
    scanf("%d",&num);

    while(num!=0)
    {
        //get the reminder fro num
        digit= num%10 ;
        sum+=digit; //update sum every itration
        num=num/10 ; //remove last digit  

    }
	printf("Sum of the Entered number Digits is :%d",sum);
    return 0 ;
   

}