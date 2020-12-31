/**
 * @file User_interface.c
 * @author mhmdreda99 (Moreda491999@gmail.com)
 * @brief  
 * this file is for anyone learning c programming
 * Description : in this file we implement the function definition in which
 * we get user inputs and ask him for operation then print the result
 * @version 1.1
 * @date 2020-12-28
 * 
 * @copyright Copyright (c) 2020
 * 
 */


/*****************************************************************************
*                               MODULE HEADER FILE
*
*****************************************************************************/

#include "../include/User_interface.h"

/*****************************************************************************
*                            Global Variables
*
*****************************************************************************/
float num1,num2,result ;
char option ;

/*****************************************************************************
*                               Functions Definitions
*
*****************************************************************************/
/**
 * @brief 
 * this is a printing func. that displays the following massages on screen
 * 
 */

void User_Interface(void){
	printf("\n\n\t\t\t WELCOME to My Calculator ");
	printf("\n\n\t\t\t=====================================");
	printf("\n\n\t\t\tPlease choose an operation: ");
	printf("\n\n\t\t\t1- For Addition please enter:'+' \n\r  ");
	printf("\n\n\t\t\t1- For Subtraction please enter:'-' \n\r  ");
	printf("\n\n\t\t\t1- For Multiplication please enter:'*'\n\r  ");
	printf("\n\n\t\t\t1- For Division please enter:'/' \n\r  ");
}
/**
 * @brief 
 * ask user to choose the operation by enter the operation char.(+,*,-,/)
 * and simply get user input and store the two numbers in num1,num2 
 * 
 */
void Get_User_Input(void){
	printf("\n\n\t\tEnter Your Option :--> ");
	scanf("%c",&option); // get user option
	printf("\n\n\t\t\t Please Enter the 1st number :");
	scanf("%f",&num1); // get user first number
	printf("\n\n\t\t\t Please Enter the 2nd number :");
	scanf("%f",&num2);// get user second number
}
/**
 * @brief printing result on the screen
 * 
 */
void Print_Result(void){
	printf("\n\n\t\t %f  %c  %f = %f  ",num1,option,num2,result); // prints result
}
