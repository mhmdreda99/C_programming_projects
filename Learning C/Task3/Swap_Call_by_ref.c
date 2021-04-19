/**
 * @file Swap_Call_by_ref.c
 * @author mhmdreda99 (Moreda491999@gmail.com)
 * @brief program to swap two numbers using call by reference
 * @version 0.1
 * @date 2021-01-05
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>
// Function prototype
swap (int *, int *);
int main()
{
    // Declaration and Inintialization
    int num1, num2;
    printf("Please Enter two numbers :\n ");
    printf("============================================================\n\r");  
    scanf("%d %d", &num1, &num2);
    printf("Before Swapping:\n");
    printf(" num1 = %d\n num2 = %d\n", num1, num2);
    printf("============================================================\n\r");  
    swap(&num1, &num2);
    printf("After Swapping:\n");
    printf(" num1 = %d\n num2 = %d", num1, num2);
    return 0;
}
/*****************************************************************************
*                          Functions definition
*****************************************************************************/
/**
 * @brief  swap two numbers using call by reference
 * 
 * @param x 
 * @param y 
 */
int swap (int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
