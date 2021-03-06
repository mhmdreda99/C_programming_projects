/**
 * @file User_interface.h
 * @author Mohamed Reda (mhmdreda99@github.com)
 * @brief 
 * @version 0.1
 * @date 2020-12-28
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#ifndef USER_INTERFACE_H_
#define USER_INTERFACE_H_
/*****************************************************************************
*                               COMMON HEADER FILE
*
*****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
/*****************************************************************************
*                               FUNCTIONS PROTOTYPES
*
*****************************************************************************/
void User_Interface(void);
void Get_User_Input(void);
void Print_Result(void);


/*****************************************************************************
*                               Extern Variables
*
*****************************************************************************/
extern float num1,result,num2 ;
extern  char option;

#endif /* USER_INTERFACE_H_ */
