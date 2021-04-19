/**
 * @file Task_id_009.c
 * @author mhmdreda99 (Moreda491999@gmail.com)
 * @brief Program that asks user to enter a key and print its ASCIs code 
 * @version 0.1
 * @date 2021-01-10
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
	char ch;
	//infinite loop
	while(1)
	{
		printf("Enter any character:\n\r ");
		//read a single character
		//ch=fgetc(stdin);
		//read a single character
		ch=getch();
		

		// detect if enter key is pressed
		if(ch==0x0A)  // ch==10 in decimal 
		{

			printf("ENTER KEY is pressed.\n");
			break;
		}
		else
		{
			printf("( %c )is pressed.\n\r",ch);
			printf(" its ASCI : %d.\n",ch);
		}
		
		

	}
	return 0;
}

