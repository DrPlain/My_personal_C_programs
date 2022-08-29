#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>

int main (int argc, char *argv[])
{
   int arr[] = {3,5,5,2,6,7,3,6,8,3,10};
   int start, end, status, sum = 0, i, sumChild;
   int arrSize = sizeof(arr)/sizeof(int);

   pid_t fd[2], pid, pid_child;
   if (pipe(fd) == -1){
        printf("Error: Unable to create pipe\n");
        return (1);
   }
   pid = fork();
   if (pid == -1){
    printf("Error: Failure to fork\n");
    return (2);
   }
   else if (pid == 0){
    start = 0;
    end = arrSize/2;
   }
   else{
    start = arrSize/2;
    end = arrSize;
   }
   pid_child = wait(&status);
   for (i = start; i <end; i++){
    sum += arr[i];
   }
   if (pid == 0){
    printf("Sum from child process is: %d\n", sum);
    if (close(fd[0]) == -1){
        printf("Error: Unable to close pipe");
        return (4);
    }
    if (write(fd[1], &sum, sizeof(sum)) == -1){
        printf("Error: Unable to write in pipe\n");
        return (3);
    }
    if (close(fd[1]) == -1){
        printf("Error: Unable to close pipe");
        return (4);
    }
   }
   else{
    pid_child  = wait(&status);
    if (close(fd[1]) == -1){
        printf("Error: Unable to close pipe");
        return (4);
    }
    printf("Sum from parent process is: %d\n", sum);
    if (read(fd[0], &sumChild, sizeof(sumChild)) == -1){
        printf("Error: Unable to raed from pipe\n");
        return (3);
    }
    if (close(fd[0]) == -1){
        printf("Error: Unable to close pipe");
        return (4);
    }

    int totalsum = sum + sumChild;
    printf("Total sum is: %d\n", totalsum);
    printf("The pid of child process is: %u\n", pid_child);
   }
   
   return 0;

}