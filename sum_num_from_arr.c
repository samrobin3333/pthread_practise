#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int primes[10] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 };


void* add(void* arg) {
    
    int index = *(int*)arg;
    
    int start = index * 5;
    int sum = 0;
    for(int i = start;i<(start+5);i++)
    {
        sum += primes[i];
    }
    *(int*)arg = sum;
    return arg;
    
}

int main(int argc, char* argv[]) {
    pthread_t th[2];
    
    int sum = 0;
    
    for(int i=0;i<2;i++)
    {
        int* a = malloc(sizeof(int));
        *a = i;
        pthread_create(&th[i],NULL,&add,a);
    }
    
    for(int i=0;i<2;i++)
    {
        int* r;
        pthread_join(th[i],(void**) &r);
        sum += *r;
    }
    
    
    printf("%d",sum);
    
    return 0;
}
