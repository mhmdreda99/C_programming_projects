/**
 * @file Task_id_005.c
 * @author mhmdreda99 (Moreda491999@gmail.com)
 * @brief C program to find maximum and minimum element in array
 * @version 0.1
 * @date 2021-01-09
 * 
 * @copyright Copyright (c) 2021
 */

#include <stdio.h>
#define MAX_SIZE 50

// Function to find the minimum and 
// maximum element of the array 
void findMinimumMaximum(int arr[], int arr_size) 
{ 
    int i; 
  
    // variable to store the minimum 
    // and maximum element 
    int min = arr[0], max = arr[0]; 
  
    // Traverse the given array 
    for (i = 0; i < arr_size; i++) { 
  
        // If current element is smaller 
        // than minE then update it 
        if (arr[i] < min) { 
            min = arr[i]; 
        } 
  
        // If current element is greater 
        // than maxE then update it 
        if (arr[i] > max) { 
            max = arr[i]; 
        } 
    } 
  
    // Print the minimum and maximum element 
    printf("The minimum element is %d", min); 
    printf("\n"); 
    printf("The maximum element is %d", max); 
  
    return; 
} 
  
// Driver Code 
int main() 
{ 
    int i,arr_size; int arr [MAX_SIZE];
  // Input size of the array

   printf("Enter size of the array: ");
   scanf("%d", &arr_size);

   // Input array elements
   printf("Enter elements in the array: ");
   for(i=0; i<arr_size; i++){
       scanf("%d", &arr[i]);
   }
  
    // Function call 
    findMinimumMaximum(arr, arr_size); 
  
    return 0; 
} 