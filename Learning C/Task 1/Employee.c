/**
 * @file Employee.c
 * @author Mohmaed Reda
 * @brief this is a program will ask the user to enter the working hours,
 *  then it will print hissalary.
 *But if the working hours are less than 40 hours, a 10% deduction will be applied.
 * @version 0.1
 * @date 2020-12-11
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include <stdio.h>
#include <stdlib.h>

int main()
{

    int worked_hr;
    int deduction;  
    int employee_salary;
    int hr_rate=50;
    int min_hr=40;
  

   printf("\r\n\tPlease enter the number of your work hours: "); 
   scanf("%d",&worked_hr);  // get the input from user

   if (worked_hr>min_hr ||worked_hr==min_hr  ){
       employee_salary=worked_hr*hr_rate;
   }
   else if (worked_hr<min_hr)
   {
       //first calculate deduction 
       deduction=(worked_hr*hr_rate*0.1);
       //get the salary
       employee_salary=(worked_hr*hr_rate)- deduction;
       
   }
   printf("\r\n\tEmployee salary is : %d",employee_salary);

    return 0;
}
