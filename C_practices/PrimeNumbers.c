/**
 * @file PrimeNumbers.c
 * @author Mohamed Reda
 * @brief program that take number from user and check wheather its prime number or not 
 * A prime number (or a prime) is a natural number greater than 1 that is not a product of two smaller natural numbers.
 *  A natural number greater than 1 that is not prime is called a composite number
 * 
 * @version 0.1
 * @date 2020-12-20
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/*****************************************************************************
* Note that :
consider we have a prime number n and composite = x*y
*x<=y   -->*x
x*x<=y*x -->n= x*y
x^2<=n
n<=sqrt(n)
we get that all factors that make n is less than or equal sqrt(n) 
*****************************************************************************/
int main ()
{
  unsigned int num, i ;
  int count=0 ; // used to check for how many time the program enter loop 
    printf("Please Enter any Number : ");
    scanf("%d",&num); // store the number taken from user in num
    if (num==2) printf("the number you entered is Prime.");
  /* all even numbers are not prime  except 2
  *0,1 also are not prime numbers so
  */

    else if (num<2 ||!(num%2))
    {
      printf("Not Prime.");

    }
    else 
    {
        for (i=3;i<sqrt(num) ;i+=2) // optmize this from i++ to i+=2 
        // give count =49  --> almost to half 
        //after changing the condition to sqrt(n)
        // the count reduced = 4  as-->(num=101)
        {
            count++;
            if (num % i ==0){
                printf("Not Prime.");
                printf("counter = %d",count);
                return 0 ;
            }  
            
        }
        printf("counter = %d\n",count); // for case of num =101 we get count =97 and this is too large time

        printf("the number you entered is Prime.\n");
        
    }
return 0 ;

}