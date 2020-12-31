

  /**
 * @file Calculator.c
 * @author mhmdreda99 (Moreda491999@gmail.com)
 * @brief 
 * @version 1.1
 * @date 2020-12-28
 * 
 * @copyright Copyright (c) 2020
 * 
 */
 

/*****************************************************************************
*                               Module HEADER FILE
*
*****************************************************************************/
#include "../include/Calculator.h"

/*****************************************************************************
*                             Private  FUNCTIONS Prototypes
*
*****************************************************************************/
static void add(void);//addition
static void subtract(void);//subtraction
static void multiply(void);//multiplication
static void divide(void); //division
static void Calc_logic(void); // operates other function

/*****************************************************************************
*                             Public  FUNCTIONS Definitions
*
*****************************************************************************/
void Calc_App(void){
	User_Interface();
	Get_User_Input();
	Calc_logic();
	Print_Result();

}
/*****************************************************************************
*                              Private FUNCTIONS Definitions
*
*****************************************************************************/
static void Calc_logic(void){
	switch(option){
	case '+':
		add();
		break;
	case '-':
			subtract();
			break;
	case '*':
			multiply();
			break;
	case '/':
			divide();
			break;
	default:
		break;


	}

}

static void add(void){
	result=num1 + num2 ;
}
static void subtract(void){
	result=num1 - num2 ;
}
static void multiply(void){
	result=num1 * num2 ;
}
static void divide(void){
	result=num1 / num2 ;
}
