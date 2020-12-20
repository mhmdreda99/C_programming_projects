#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Ask user to enter no_rows
    printf("Please Enter Number of Rows: \n");
    int no_rows;
    scanf("%d",&no_rows);
    int i, j;
    for(i=0;i<no_rows;i++)
    {
        for(j=0;j<no_rows;j++)
        {
            // print * if --> i == j
            //            --> j == (no_rows -i -1)
            if(i == j || j ==(no_rows - i -1))
            {
                printf("*");
            }
            else{
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}
