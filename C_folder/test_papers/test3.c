/*Write a program which allows the user to create two processes P1 and P2. P1 should
allow the user to enter 2 values, A and B and send these values to P2 which will
calculate A*B and send the result back to P1 to be displayed.*/

#include <stdio.h>       // Standard input/output library for printf, scanf, etc.
#include <unistd.h>      // For using pipe, fork, read, write, close, etc.
#include <sys/wait.h>    // For using wait function to synchronize processes

int main() {
    int pipe1[2], pipe2[2];  // pipe1: sends A and B from P1 to P2, pipe2: sends result from P2 to P1
    pid_t pid;               // Variable to store process ID for fork()

    // Create pipe1 and pipe2. If either fails, exit with an error message.
    if (pipe(pipe1) == -1 || pipe(pipe2) == -1) {
        perror("Pipe failed");   // Print error if pipe creation fails
        return 1;
    }
    
    // Create a new child process using fork
    pid = fork();
    
    if (pid < 0) {
        perror("Fork failed");  // Print error if fork fails
        return 1;
    }

    // Parent process (P1) block
    if (pid > 0) {
        // Close unused ends of the pipes in parent process (P1)
        close(pipe1[0]);  // Close read end of pipe1 (P1 only writes to pipe1)
        close(pipe2[1]);  // Close write end of pipe2 (P1 only reads from pipe2)

        int A, B, result;  // Variables for storing input numbers and the result
        
        // Get user input for A and B
        printf("Enter two integers A and B: ");
        scanf("%d %d", &A, &B);

        // Write A and B to child process P2 through pipe1
        write(pipe1[1], &A, sizeof(A));  // Send A
        write(pipe1[1], &B, sizeof(B));  // Send B

        // Read the result (A * B) from P2 through pipe2
        read(pipe2[0], &result, sizeof(result));

        // Display the result
        printf("The product of %d and %d is: %d\n", A, B, result);

        // Close the pipes in the parent process after use
        close(pipe1[1]);  // Close write end of pipe1
        close(pipe2[0]);  // Close read end of pipe2

        // Wait for the child process P2 to finish
        wait(NULL);
    }
    // Child process (P2) block
    else {
        // Close unused ends of the pipes in child process (P2)
        close(pipe1[1]);  // Close write end of pipe1 (P2 only reads from pipe1)
        close(pipe2[0]);  // Close read end of pipe2 (P2 only writes to pipe2)

        int A, B, result;

        // Read A and B from pipe1, which was sent by P1
        read(pipe1[0], &A, sizeof(A));  // Read A
        read(pipe1[0], &B, sizeof(B));  // Read B

        // Calculate A * B
        result = A * B;

        // Write the result back to P1 through pipe2
        write(pipe2[1], &result, sizeof(result));

        // Close the pipes in the child process after use
        close(pipe1[0]);  // Close read end of pipe1
        close(pipe2[1]);  // Close write end of pipe2
    }
    
    return 0;  // Exit the program
}

