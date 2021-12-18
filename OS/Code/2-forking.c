/*
Platform: Open Source 64-bit Linux
Compiler version:gcc (Debian 10.2.1-6) 10.2.1 20210110
*/


#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

// Helper functions declaration
void swapNum(int *arr,int p1, int p2);
void bubblesort(int *arr, int size);
void reverse(int *arr, int size);


int main()
{   
    int n;

    // Taking size of the array
    printf("Enter size: ");
    scanf("%d",&n);
    
    // Taking input for the array
    int arr[n];
    printf("Enter values:");
    for( int i = 0; i < n; i++) 
        scanf("%d",&arr[i]);

    // Forking the code into another child process
    pid_t pid = fork();

    // If else cases for identifying parent and child process
    if ( pid > 0 )
    {   
        // PARENT PROCESS
        printf("PARENT PROCESS\n\n");

        // Using bubblesort to sort in ascending order
        bubblesort(arr, n);
        printf("ARRAY IS NOW SORTED IN ASCENDING ORDER: ");
        
        // Displaying the array
        for ( int i = 0; i < n; i++)
            printf("%d ",arr[i]);  
        printf("\n");
    }
    else if ( pid == 0 )
    {   
        // CHILD PROCESS
        printf("CHILD PROCESS\n\n");

        // Using bubblesort to sort in ascending order
        bubblesort(arr, n);

        // Reversing the array to get descending order
        reverse(arr,n);
        printf("ARRAY IS NOW SORTED IN DESCENDING ORDER: ");
        
        // Displaying the array
        for ( int i = 0; i < n; i++)
            printf("%d ",arr[i]);  
        printf("\n");

    }
    else
        printf("Child process was not generated\n");
    return 0;
}

// Function definition - bubblesort
void bubblesort(int *arr, int size)
{
	for (int i = 0; i < size - 1; i++)
		for (int j = 1; j < size; j++)
		{
			if(arr[j-1] > arr[j]) 
				swapNum(arr, j-1, j);
		}
}

// Function definition - reverse
void reverse(int *arr, int size)
{
    for(int i = 0; i < size / 2 ; i++)
        swapNum(arr, i, size-i-1);

}

// Function definition - swapNum
void swapNum(int *arr,int p1, int p2)
{
	int temp = arr[p1];
	arr[p1] =  arr[p2];
	arr[p2] = temp;
}
