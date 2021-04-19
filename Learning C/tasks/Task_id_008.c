/**
 * @file Task_id_008.c
 * @author mhmdreda99 (Moreda491999@gmail.com)
 * @brief Program that take an input of 4 subjects of 3 students and store it in a 2d arrray 
 * create the sum of each student degree and average of coulmns
 * @version 0.1
 * @date 2021-01-09
 * 
 * @copyright Copyright (c) 2021
 * 
 */
// Libraries
#include<stdio.h>
#include <stdlib.h>// Library to include Basic C functions for the compiler.

// User-defined header files #include
// User-defined header files #define (Macros: Object / Function)
// Type definition
// Function prototype
// Declared Structures (if Type definition)
// Declared Functions
// Global variables (Declaration and Initialization)
// Enum

void main(void)
{
	// Declaration and Initialization
	 unsigned int marks[3][4] ,student,subject;
	 int total, sum ;
	 // ask user to Enter inputs
	 for(student = 0; student < 3; student++) {
	     printf("Enter marks of 4 Subjects of Student #%d: ", (student + 1));
	     fflush(stdin);fflush(stdout);
	     for(subject = 0; subject < 4; subject++)
	     {
	       scanf("%d", &marks[student][subject]);
	       fflush(stdin);fflush(stdout);
	     }// end of inner for
	   }// end of outer for
// get the total
	 for(student=0;student<3;student++)
	 {
		 total =0 ;
		 for(subject = 0; subject < 4; subject++)
		 {
			 total+=marks[student][subject];

		 }
		 // print Sum of each row 
		 printf( "\tThe Sum for student %d is %d\n",
		 		  student + 1,  total );

	 }
	 for(subject = 0; subject < 4; subject++)
	 {
		 int x=0 ; // just an iterator var.
		 sum =0 ;
		 for(student=0;student<3;student++)
		 {

			 sum+=marks[student][subject];

		 }

        
// print average of each column 
		 printf( "\tThe Average for subjects %d is %d\n",
				 		  subject+1,  sum/3 );
						   
						   
	 }


}
