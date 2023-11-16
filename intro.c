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

void* routine1()
{
    printf("Routine 1 has been called\n");
    sleep(2);
    printf("Routine 1 has been terminated\n");
    
}

void* routine2()
{
    printf("Routine 2 has been called\n");
    sleep(2);
    printf("Routine 2 has been terminated\n");
    
}


int main(int argc, char* argv[]) {
    pthread_t t1,t2;
    pthread_create(&t1,NULL,&routine1,NULL);
    pthread_create(&t1,NULL,&routine2,NULL);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    return 0;
}
