/*Write a program which allows creation of a child process. When the parent process
executes, it should display “I am the parent” and the process id of its child. When the
child executes, it should display “I am a child ” and the process id of its parent. Your
program should allow the child and parent processes to display their messages once.
(Hint: Use sleep() accordingly)*/

#include <stdio.h>      // Standard I/O library for printf
#include <unistd.h>     // For fork, getpid, getppid, sleep
#include <sys/types.h>  // For process ID types
#include <sys/wait.h>   // For wait function

int main() {
    pid_t pid;  // Variable to store the process ID returned by fork()

    // Create a new process (child process) using fork
    pid = fork();

    if (pid < 0) {
        // Fork failed
        perror("Fork failed");
        return 1;
    }

    if (pid == 0) {
        // This block is executed by the child process
        sleep(1);  // Slight delay to allow parent to execute first
        printf("I am a child. My parent's PID is %d.\n", getppid());  // Display child's message with parent's PID
    } else {
        // This block is executed by the parent process
        printf("I am the parent. My child's PID is %d.\n", pid);  // Display parent's message with child's PID
        wait(NULL);  // Wait for the child process to finish executing
    }

    return 0;
}

