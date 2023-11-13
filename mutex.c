// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

static int mails=0;
pthread_mutex_t mutex;

void* routine1()
{
    pthread_mutex_lock(&mutex);
    for(int i=0;i<1000000;i++)
    {
        mails++;
    }
    pthread_mutex_unlock(&mutex);
}

void* routine2()
{
    pthread_mutex_lock(&mutex);
    for(int i=0;i<1000000;i++)
    {
        mails++;
    }
    pthread_mutex_unlock(&mutex);
}

int main(int argc, char* argv[]) {
    
    pthread_t t1,t2;
    pthread_mutex_init(&mutex,NULL);
    pthread_create(&t1,NULL,&routine1,NULL);
    pthread_create(&t2,NULL,&routine2,NULL);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    pthread_mutex_destroy(&mutex);
    printf("The number of mails is %d",mails);
    return 0;
}
