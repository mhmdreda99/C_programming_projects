/**
 * @file MaxZeroes_between_2ones.c
 * @author mhmdreda99 (Moreda491999@gmail.com)
 * @brief program that count the number of zeros between two 1's (1#000#11#00#11) 
 * @version 0.1
 * @date 2021-04-04
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include<stdio.h>
/*****************************************************************************
*                        Function Prototypes& MACROS 
*****************************************************************************/
#define MASK 0x01 
/**
 * @brief 
 * caculate the maximum number of zeroes bet. 2 ones .
 * @param num input number supplied by yuser
 * @return Max_Zero is the number of maximum zeros between two ones
 */
int Max_Zeroes(int num )
{
    int i,j,zero_Count=0,Max_Zero=0; 
    // loop to check each bit in 32 bit 
    for (i=0;i<32;i++)
    {
        //check if bit equal 1 
        if (num&(MASK<<i))
        {
            //start second loop to continue checking the bits after first one detected
            for(j=i+1;j<32;j++)
            {
                if (num&(MASK<<j))
                {
                    if (Max_Zero<zero_Count)
                    {
                        Max_Zero=zero_Count ;

                    }
                 zero_Count=0 ;
                  break; 

                }
                // if bit not =1 continue counting zeroes 
                else
                {
                        zero_Count++ ;
                }
            }
        }

    }
    return Max_Zero;
}

int main()
{
    // test the function
    //num =19 -------->bin= 0001 0011
    printf("Max number of zeroes is %d ",Max_Zeroes(19));

return 0 ;
}