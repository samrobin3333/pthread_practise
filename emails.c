// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

int mails=0;
pthread_mutex_t mutex;

void* routine()
{
    pthread_mutex_lock(&mutex);
    for(int i=0;i<10000;i++)
    {
        mails++;
    }
    pthread_mutex_unlock(&mutex);
}

/**void* routine2()
{
    pthread_mutex_lock(&mutex);
    for(int i=0;i<1000000;i++)
    {
        mails++;
    }
    pthread_mutex_unlock(&mutex);
}**/

int main(int argc, char* argv[]) {
    
    pthread_t th[4];
    pthread_mutex_init(&mutex,NULL);
    for(int i=0;i<4;i++)
    {
        pthread_create(th+i,NULL,&routine,NULL);
        printf("the thread %d has been created\n",i);
    }
    
    for(int i=0;i<4;i++)
    {
        pthread_join(th[i],NULL);
        printf("the thread %d has been joined",i);
    }
    pthread_mutex_destroy(&mutex);
    printf("The number of mails is %d",mails);
    return 0;
}
