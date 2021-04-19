/**
 * @file Task_id_001.c
 * @author mhmdreda99 (Moreda491999@gmail.com)
 * @brief program that display menu depending of the user input and clear screen after take input showing massege
 * @version 0.1
 * @date 2021-01-09
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include<stdio.h>
#include<stdlib.h>
#include <conio.h>

int main()
{
	char choice ;
       
    printf("a - Good Morning\n\r");
    printf("b - Good evening\n\r");
    printf("c - Exit program\n\r");
    printf("Please enter your choice :");
     
    
    while(1){
        
   
		choice= getch();
		fflush(stdin);
		if (choice=='a')
		{
			system("cls");
			printf(" Good Morning");
            
		}
		else if (choice=='b')
		{
			system("cls");
			printf(" Good evening");
		}
		else if (choice=='c')
		{
			system("cls");
			printf(" Exit program");
		}
		else
		{
			system("cls");
			printf(" Wrong Choice");
			exit(0);
		}

	}
	return 0 ;
}


