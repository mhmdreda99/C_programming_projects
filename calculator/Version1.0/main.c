//********welcome to MR's Calculator ***********

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
  int Num1 ,Num2 , op , result ,x ,y ,result1 = 1 , n;

  char optional ;
  do {
  printf(" \n  \n Enter the operation you want? : \n");
  printf("  press 1 for Addtion  \n")  ;
  printf("  press 2 for Subtraction \n")  ;
  printf("  press 3 for Multiply  \n")  ;
  printf("  press 4 for devision \n")  ;
  printf(" press 5 for get power \n")  ;
  printf("  press 6 for get root \n")  ;
  scanf("%d",& op);


  switch (op){
    case 1 :printf("please enter first number : \n ");
            scanf("%d",& Num1);
            printf("please enter second number : \n ");
            scanf("%d",& Num2);
    result= Num1+Num2 ;
    printf("result= %d",result) ;
         break;
    case 2 :printf("please enter first number : \n ");
            scanf("%d",& Num1);
            printf("please enter second number : \n ");
            scanf("%d",& Num2);
         result= Num1-Num2 ;
   printf("result= %d",result) ;
         break;
    case 3 :printf("please enter first number : \n ");
            scanf("%d",& Num1);
            printf("please enter second number : \n ");
            scanf("%d",& Num2);
   result= Num1*Num2 ;
   printf("result= %d",result) ;
         break;
    case 4:printf("please enter first number : \n ");
           scanf("%d",& Num1);
           printf("please enter second number : \n ");
           scanf("%d",& Num2);
    result= Num1/Num2 ;
    printf("result= %d",result) ;
         break;
    case 5: printf("enter base  value : \n");
            scanf("%d",&x);
            printf("enter power  value : \n");
            scanf("%d",&y);

    for (int i=0 ;i<y ;i++){
    result1*=x ;
  }
     printf("the power of the number is  = %d ",result1);
      break ;
     case 6:printf(" \n enter a number : \n ");
            scanf("%d",&n );
           printf("result = %f" ,sqrt(n))   ;
    default:
printf(" \n wrong input \n");
}
printf(" \n do you want to continue press y/n ?? \n");
optional=getche();
}while (optional=='y');
getch();
return 0 ;

}

