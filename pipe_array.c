#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <errno.h>

int main()
{
    int arr[] = {1,2,3,4,1,2};
    int fd[2];
    if(pipe(fd) == -1)
    {
        printf("There is an error in creating the pipe");
        return 1;
    }
    
    int id = fork();
    int start,end;
    if(id == 0)
    {
        close(fd[0]);
        for(int i=0;i<6;i++)
        {
            write(fd[1],&arr[i],sizeof(int));
        }
        close(fd[1]);
    }
    else
    {
        close(fd[1]);
        int x,sum;
        for(int i=0;i<6;i++)
        {
            read(fd[0],&x,sizeof(int));
            sum += x;
        }
        printf("The sum of the arr is %d",sum);
    }
    
    return 0;
}
