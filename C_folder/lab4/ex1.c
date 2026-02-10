/*Question 1
The system calls getpid() and gettppid() respectively return the identifier of a process
and the identifier of its parent. The synopsis is as given below. The type pid_t can be
treated as integers. Write a program to display the pid value of a process as well as that of
its parent. Use the ps –a command to check if the pid displayed by the process is the
same as that displayed by the ps –a command. You can use the sleep() system call to
cause the process to sleep for some time to allow you to use the ps -a command.
Note: Use two terminals: One to run your program and another to type in the
command ps –a.

SYNOPSIS
#include <sys/types.h>
#include <unistd.h>
pid_t getpid(void);
pid_t getppid(void);
*/

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(){
int process_id = getpid();
int parentprocess_id = getppid();
printf("Identifer of a process:%d \n", process_id);
printf("Identifer of its parent:%d \n", parentprocess_id);
sleep(10);
return 0;
}
