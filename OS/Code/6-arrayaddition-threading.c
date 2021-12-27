#include<stdio.h>
#include<pthread.h>

// Function declaration
void *add(void*);

// main function - driver code
int main()
{
    // threading array
    pthread_t tid[5];
    int sum = 0, *n, a[]={1,2,3,4,5};
    int i;

    // Create threads
    for(i = 0; i < 5 ; i++)
        pthread_create(&tid[i], NULL, (void*)add, (void*)&a[i]);
    
    // Joining all threads to the pool
    for(i = 0; i < 5 ; i++)
    {
        pthread_join(tid[i], (void*)&n);
        sum = sum + *n;
    }

    printf("Sum = %d\n", sum);
    return 0;
}

// Function definition - add
void *add(void *ele)
{   
    int *a = (int*)ele;
    (*a)++;
    
    return (void*)(a);
}