#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

// Helper functions - declaration
void add(int*);
void sub(int*);
void mul(int*);
void div(int*);

// main function - driver code
int main()
{
    // Array of thread pointer
    pthread_t tid[4];

    int arr[3];

    // Taking input
    printf("Enter the two numbers: ");
    for(int i = 0; i < 2; i++)
        scanf("%d", &arr[i]);

    // Creating threads
    pthread_create(&tid[0], NULL, (void*)add, arr);
    pthread_create(&tid[1], NULL, (void*)sub, arr);
    pthread_create(&tid[2], NULL, (void*)mul, arr);
    pthread_create(&tid[3], NULL, (void*)div, arr);

    // Adding threads to the queue
    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);
    pthread_join(tid[2], NULL);
    pthread_join(tid[3], NULL);
}

// Function defintion - add
void add(int *a)
{
    a[2] = a[0] + a[1];
    printf("\nAddition result is %d", a[2]);

}

// Function defintion - sub
void sub(int *a)
{
    a[2] = a[0] - a[1];
    printf("\nSubtraction result is %d", a[2]);
}

// Function defintion - multiply
void mul(int *a)
{
    a[2] = a[0] * a[1];
    printf("\nMultiplication result is %d", a[2]);
}

// Function defintion - division
void div(int *a)
{
    a[2] = a[0] / a[1];
    printf("\nDivision result is %d", a[2]);
}