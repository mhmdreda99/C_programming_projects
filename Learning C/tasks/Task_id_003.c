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
void displayMenu(void)
{  
    printf("a - Good Morning\n\r");
    printf("b - Good evening\n\r");
    printf("c - Exit program\n\r");
    printf("Please enter your choice :");
    

}
int main()
{
	char choice ;
    
    while(1)
    {
     displayMenu();
     
        choice= getch();
	    fflush(stdin);
        switch (choice)
        {
         case 'a':
         case 'A':

            system("cls");
			printf(" Good Morning\n\r");
            break;
         case 'b':
         case 'B':
        
            system("cls");
			printf(" Good Evening\n\r");
            break;
         case 'c':
         case 'C':
        
            system("cls");
			printf(" Exit Program\n\r");
            break;
         case 'e':
         case 'E':
        
            exit(0);
            break;         
        default:
        printf("Wrong Answer");
        exit(0);
        
            break;
        }
   
	 
    
		
	}
	return 0 ;
}


