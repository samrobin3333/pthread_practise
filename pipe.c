#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int fd[2];
    //pipe(fd);
    if (pipe(fd) == -1)
    {
        printf("An error has occured with opening the pipe\n");
        return 1;
    }
    int id = fork();
    if (id == 0)  //this is the child process
    {
        close(fd[0]); //since we don't read inside the child process, we close the read end
        int x;
        printf("Enter a number : ");
        scanf("%d",&x);
        write(fd[1],&x,sizeof(int)); //we send value from the child process to the parent process
        close(fd[1]); //we close the write end after using it in the child process
    }
    else
    {
        close(fd[1]);//since we don't write inside the child process, we close the write end
        int y;
        read(fd[0],&y,sizeof(int)); 
        close(fd[0]); //we close the read end after using it in the parent process
        printf("Got from child proccess %d ",y);  we get values from the child process here
    }

    return 0;
}
