#include <stdio.h>
#include <stdlib.h>

int main()
{
int arr[10] ;
int i ;
int sum ;
int b=0 ;
printf("please enter your grades :");
for (i=0 ;i<10;i++){
     scanf("%d",&arr[i]);
}
while (b<10 )
{
if((85<arr[b])&&(arr[b]<100)){
 printf("A grade. \n");
}
else if ((80<arr[b])&&(arr[b]<85)){
    printf("B grade.\n ");
}
else if ((70<arr[b])&&(arr[b]<79)){
    printf("C grade.\n ");
}

else if ((60<arr[b])&&(arr[b]<69)){
    printf("D grade. \n");
}
else if (i<60){
printf("F grade.\n ");
}
sum+=arr[b] ;


b++;
}
printf("sum= %d",sum);
}



