#include <stdio.h>
#include <stdlib.h>

int main()
{
   // int Id[3]={1999,4422,1145};
    int option;
    printf("\n\t\tPlease Enter the student id:");
    scanf("%d",&option); // get the input from user

    switch (option)
    {
    case 1999:
        printf("\n\t\tthe ID you have entered is For Ahmed");
        break;
    case 4422:
        printf("\n\t\tthe ID you have entered is For Aya");
        break;
    case 1145:
        printf("\n\t\tthe ID you have entered is For Hany");
        break;    
    default:
    printf("\n\t\tWrong ID .");
    printf("\n\t\tProgram terminated");
    exit(0); //exit the program
        break;
    }

 
return 0 ;
}
