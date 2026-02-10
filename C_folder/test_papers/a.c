#include <stdio.h>
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


/*#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <stdbool.h>
#include <fcntl.h>  // Required for open() and file handling

#define TIME_LIMIT 5

// Global flag to indicate if the input was successful within the time limit
bool input_success = false;

// Signal handler for the alarm
void handle_timeout(int sig) {
    printf("\nTime limit exceeded! Writing 101 to file.\n");
    input_success = false; // No valid input received
}

// Main function
int main() {
    int num;
    int file; // File descriptor for the output file
    char buffer[50]; // Buffer to hold output data

    // Set up the signal handler for the timeout
    signal(SIGALRM, handle_timeout);

    // Start the countdown for the time limit
    alarm(TIME_LIMIT);

    // Prompt user for input
    printf("Please enter a number (within %d seconds): ", TIME_LIMIT);
    
    // Try to read user input
    if (scanf("%d", &num) == 1) {
        // If input is successful, cancel the alarm
        alarm(0);
        input_success = true;
    }

    // Open the file to write the result
    file = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    
    if (file < 0) { // Check for error in opening the file
        perror("Error opening file");
        return 1;
    }

    // Write either the user input or 101 based on success
    if (input_success) {
        int len = snprintf(buffer, sizeof(buffer), "%d\n", num); // Format the number into the buffer
        write(file, buffer, len); // Write the formatted number to the file
    } else {
        const char *msg = "101\n"; // Prepare the message for timeout case
        write(file, msg, 4); // Write "101" to the file
    }

    // Close the file
    close(file); // Use close() instead of fclose()

    return 0;
}*/
