/**
 * @file 8bit_digits.c
 * @author Mohmaed Reda
 * @brief program that count the 1's in a 8bit integer 
 * @version 0.1
 * @date 2020-12-21
 * 
 * @copyright Copyright (c) 2020
 * 
 */


// Libraries
#include<stdio.h> // Library to include Basic C functions for the compiler.
#include<stdlib.h>
// User-defined header files #include
// User-defined header files #define (Macros: Object / Fuction)
// Type definition
// Function prototype
// Declared Structures (if Type definition)
// Declared Functions
// Global variables (Declaration and Inintialization)
// Enum
#define mask (0x01)
void main(void)
{	
	// Declaration and Inintialization
    unsigned char num ;
    int i ,ones_count ; // loop counter and ones counter
  
    printf("Please enter any Number:");
    scanf("%d",&num);
// loop through the number bits 
    for(i=0;i<8;i++)
    {
        if (num & (mask<<i))
        {
            ones_count++; //while condition is true incerement the ones counter
        }

    }
    //print the result
    printf("NUMBER of ones in the Entered number is :%d ",ones_count);
	return 0 ;
	
}