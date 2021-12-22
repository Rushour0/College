#include<stdio.h>
#include<pthread.h>

void *add(void*);

int main()
{
    pthread_t tid[5];
    int sum = 0, *n, a[]={1,2,3,4,5};
    int i;
    for(i = 0; i < 5 ; i++)
    {
        pthread_create(&tid[i], NULL, (void*)add, (void*)&a[i]);
    }
    for(i = 0; i < 5 ; i++)
    {
        pthread_join(tid[i], (void*)&n);
        sum = sum + *n;
    }
    printf("Sum = %d\n", sum);
    return 0;
}

void *add(void *ele)
{   
    int *a = (int*)ele;
    (*a)++;
    
    return (void*)(a);
}