/**
 * @file bank database.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2020-11-26
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bank database.h"
extern int counter ;
extern customer_t arr[5] ;
/**
 * @brief Create a new customer object
 * 
 */
void create_new_customer(void)
{
    customer_t new_customer ;
    printf("please enter the name of the customer number %i:",counter+1);
    fflush(stdin);
    gets(new_customer.name);

  label:  printf("please enter the cash of the customer number %i:",counter+1);
    scanf("%lf",&(new_customer.cash));
    if(new_customer.cash<0)
    {
      printf("the cash money should be positive number and greater than or equal zero  \n");
      goto label ;
    }

    printf("please enter the type of the customer number %i (debit or credit):",counter+1);
    fflush(stdin);
    gets(new_customer.type);


    printf("please enter the id of the customer number %i:",counter+1);
    scanf("%i",&(new_customer.id));

    printf("\n\n");
    arr[counter]=new_customer ;
    counter++ ;
}
/**
 * @brief 
 * 
 * @param id 
 */
void  edit_customer(int id )
{
    int i ;
    for(i=0;i<=counter;i++)
    {
      if(id==arr[i].id)
      {
    printf("please enter the new name :");
    fflush(stdin);
    gets(arr[i].name);

    printf("please enter the new cash :");
    scanf("%lf",&(arr[i].cash));

    printf("please enter the new type (Debit or credit):");
    fflush(stdin);
    gets(arr[i].type);

    printf("please enter the new id :");
    scanf("%i",&(arr[i].id));

    printf("\n\n");
    break ;
      }
    }

}
/**
 * @brief 
 * 
 * @param id 
 */
  void  print_customer_data(int id)
    { int i ;
        for(i=0;i<=counter;i++)
        {

        if (id==arr[i].id)
        {
            printf("the name of the customer number%i is :%s\n",i+1,arr[i].name);
            printf("the cash of the customer number%i is :%0.2lf\n",i+1,arr[i].cash);
            printf("the type of the customer number%i is :%s\n",i+1,arr[i].type);
            printf("the id of the customer number%i is :%i\n",i+1,arr[i].id);
            printf("\n\n");
            break ;
         }
         }


         }

     void transfer_money(int source_id ,int destination_id,double money)
     {
         int i ;
         int index_from=-1 ;
         int index_to=-1 ;
     L1:    for(i=0;i<=counter;i++)
         {
          if(arr[i].id==source_id)
          {
              index_from=i ;
          }
          else if (arr[i].id==destination_id)
          {
              index_to=i ;
          }
          if((index_from!=-1)&&(index_to!=-1))
          {
             break;
          }

        }
         if((index_from==-1)||(index_to==-1))
         {
             printf("please enter valid id\n");


         }
         if(money>arr[index_from].cash)
        {
            printf("the money transfered is greater than your cash \n");
            printf("please enter the money transfered again and take care :");
            scanf("%lf",&money);
            goto L1;
        }

         arr[index_from].cash=arr[index_from].cash-money;
         arr[index_to].cash=arr[index_to].cash+money;
         }

/**
 * @brief 
 * 
 * @param id 
 */
void delete_customer_data(int id )
{
    int i ;
    int index ;
    for(i=0;i<=counter-1;i++)
        {
        if(arr[i].id==id)
        {
            index=i ;
    for(i=index;i<=counter-1;i++)
        {
        arr[i]=arr[i+1];

        }
        }
        }
        arr[counter].cash=-1; // -1 indicate this is empty place for new customer
        arr[counter].id=-1 ;  // -1 indicate this is empty place for new customer
        strcpy(arr[counter].name,"-1"); // -1 indicate this is empty place for new customer
        strcpy(arr[counter].type,"-1"); // -1 indicate this is empty place for new customer
        counter--;
}


