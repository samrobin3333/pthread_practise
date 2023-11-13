// program to try out pthread_mutex_destroy
// Program casts 8 dies simultaneously and then notes their output

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>

int mails=0;
pthread_mutex_t mutex;

void* roll_dice()
{
    //pthread_mutex_lock(&mutex);
    int ans = (rand()%6)+1;
    int* res = malloc(sizeof(int));
    *res = ans;
    //pthread_mutex_unlock(&mutex);
    return (void*) res;
}


int main(int argc, char* argv[]) {
    int* result;
    int num = 8;
    pthread_t die[num];
    //pthread_mutex_init(&mutex,NULL);
    for(int i=0;i<num;i++)
    {
        pthread_create(die+i,NULL,&roll_dice,NULL);
        printf("the die %d has been cast\n",(i+1));
    }
    
    for(int i=0;i<num;i++)
    {
        pthread_join(die[i],(void**) &result);
        printf("the die %d has output %d\n",(i+1),*result);
    }
    //pthread_mutex_destroy(&mutex);
    return 0;
}
