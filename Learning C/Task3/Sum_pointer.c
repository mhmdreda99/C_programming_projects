/**
 * @file Sum_pointer.c
 * @author mhmdreda99 (Moreda491999@gmail.com)
 * @brief C code that ask the user to enter 2 values and save them in two variables, then
 *   the program sends these variables by address to a function that returns the summation of them. 
 *  The program then prints the result.
 * @version 0.1
 * @date 2021-01-05
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>
#include <stdlib.h>
int add(int *, int *);
 
int main()
{
   int first, second, *pfirst, *psecond, sum;
 
   printf("Input two integers to add :\n\r");
   scanf("%ld%ld", &first, &second);
 
   sum = add(&first, &second);
 
   printf("the Sum of : (%d) + (%d) = (%d)\n", first, second, sum);
 
   return 0;
}
/**
 * @brief 
 * add is a function which add to numbers paseed by addressees
 * @param x a pointer which is a direct address to the first num
 * @param y a pointer which is a direct address to the second num
 * @return int sum of two vars.
 */
int add(int *x, int *y) {
   int sum;
   
   sum = *x + *y;
   
   return sum;
}