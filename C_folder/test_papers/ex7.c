/**/

include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <fcntl.h>

int main() {
    char input[100];
    pid_t pid = fork();  // Create a child process
    int file;

    // Open the file in write mode, create if it doesn't exist
    file = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (file < 0) {
        perror("File open failed");
        exit(1);
    }

    if (pid < 0) {
        // Fork failed
        perror("fork failed");
        exit(1);
    } else if (pid == 0) {
        // Child process: sleep for 5 seconds and then write 101 to the file
        sleep(5);
        write(file, "101\n", 4);  // Write 101 to the file
        close(file);  // Close the file
        exit(0);
    } else {
        // Parent process: allow the user to input a string
        printf("Enter a string within 5 seconds: ");
        if (scanf("%s", input) != EOF) {
            // If input is provided before timeout, kill the child process
            kill(pid, SIGKILL);
            wait(NULL);  // Wait for the child to terminate
            // Write the user's input to the file
            write(file, input, sizeof(input));
            write(file, "\n", 1);
        } else {
            // If no input, the child process will write 101
            wait(NULL);  // Wait for the child to finish
        }

        close(file);  // Close the file in the parent process
    }

    return 0;
}
