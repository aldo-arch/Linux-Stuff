#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define P1_READ     0
#define P2_WRITE    1
#define P2_READ     2
#define P1_WRITE    3
#define NUM_PIPES   2
int main(int argc, char *argv[])
{
    int fd[2*NUM_PIPES];
    int val = 0, len, i,c;
    pid_t pid;
    int fact=1;
    for (i=0; i<NUM_PIPES; ++i)
    {
        if (pipe(fd+(i*2)) ==-1)
        {
            perror("Failed to allocate pipes");
            exit(EXIT_FAILURE);
        }
    }
if ((pid = fork()) < 0)
    {
        perror("Failed to fork process");
        return EXIT_FAILURE;
    }
if (pid == 0)
    {
        close(fd[P1_READ]);
        close(fd[P1_WRITE]);
pid = getpid();
len = read(fd[P2_READ], &val, sizeof(val));
        if (len < 0)
        {
            perror("Child: Failed to read data from pipe");
            exit(EXIT_FAILURE);
        }
        else if (len == 0)
        {
          fprintf(stderr, "Child: Read EOF from pipe");
        }
        else
        {
printf("Child(%d): Received %d\n", pid, val);

            
            for(c=1;c<=val;c++){
            fact=fact*c;}
            val=fact;
printf("Child(%d): Sending %d back\n", pid, val);
            if (write(fd[P2_WRITE], &val, sizeof(val)) < 0)
            {
                perror("Child: Failed to write response value");
                exit(EXIT_FAILURE);
            }
        }
close(fd[P2_READ]);
        close(fd[P2_WRITE]);
        return EXIT_SUCCESS;
    }
close(fd[P2_READ]);
    close(fd[P2_WRITE]);

  
    pid = getpid();
printf("jep vleren:");
    scanf("%d",&val);
    printf("Parent(%d): Sending %d to child\n", pid, val);
    if (write(fd[P1_WRITE], &val, sizeof(val)) != sizeof(val))
    {
        perror("Parent: Failed to send value to child ");
        exit(EXIT_FAILURE);
    }
len = read(fd[P1_READ], &val, sizeof(val));
    if (len < 0)
    {
        perror("Parent: failed to read value from pipe");
        exit(EXIT_FAILURE);
    }
    else if (len == 0)
    {
       
        fprintf(stderr, "Parent(%d): Read EOF from pipe", pid);
    }
    else
    {
           printf("Parent(%d): Received %d\n", pid, val);
    }
close(fd[P1_READ]);
    close(fd[P1_WRITE]);
wait(NULL);
return EXIT_SUCCESS;