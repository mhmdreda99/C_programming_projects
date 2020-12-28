/*
 ============================================================================
 Name        : Calculator.c
 Author      : Mohamed Reda
 Version     :
 Copyright   : Your copyright notice
 Description : in this file we implement main funiction that operates the calculator
  
 ============================================================================
 */

/*****************************************************************************
*                               Module HEADER FILE
*
*****************************************************************************/
#include "Calculator.h"

/*****************************************************************************
*                             Private  FUNCTIONS Prototypes
*
*****************************************************************************/
static void add(void);//addition
static void sub(void);//subtraction
static void mul(void);//multiplication
static void div(void); //division
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
			sub();
			break;
	case '*':
			mul();
			break;
	case '/':
			div();
			break;
	default:
		break;


	}

}

static void add(void){
	result=num1 + num2 ;
}
static void sub(void){
	result=num1 - num2 ;
}
static void mul(void){
	result=num1 * num2 ;
}
static void div(void){
	result=num1 / num2 ;
}
