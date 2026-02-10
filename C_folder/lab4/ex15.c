#include <stdio.h>    // Standard Input/Output library for functions like printf and scanf
#include <stdlib.h>   // Standard library for memory allocation, process control, and conversions (e.g., exit)
#include <fcntl.h>    // File control options, provides file access modes and flags for open()
#include <unistd.h>   // Provides access to the POSIX operating system API, including functions like read, write, and close
#include <signal.h>   // Signal handling library for managing asynchronous events (e.g., handling alarms)

int fd;  // File descriptor

// Signal handler for SIGALRM
void handle_alarm(int sig) {
    char default_value[] = "101";
    
    printf("\nTime's up bro, Writing default value 101 to file.\n");
    
    // Write the default value to the file
    write(fd, &default_value, sizeof(default_value));
    
    // Close the file
    close(fd);
    
    // Forcefully terminate the process
    exit(0);
}

int main() {
    char data[3];

    fd = open("output.dat", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        printf("Error opening file");
        exit(1);
    }

    // Set the alarm signal handler for SIGALRM
    signal(SIGALRM, handle_alarm);

    // Set an alarm for 5 seconds
    alarm(5);

    printf("Enter a data within 5 seconds: ");

    // Try to read input from user
    if (scanf("%s", data) == 1) {
        // User entered a data within the time limit
        printf("You entered: %s\n", data);
	
        write(fd, data, sizeof(data));
        
        // Cancel the alarm since input was received in time
        alarm(0);
    }

    // Close the file
    close(fd);

    printf("Process completed normally.\n");
    return 0;
}
