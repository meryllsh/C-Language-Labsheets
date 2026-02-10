/*Write a program that repeats the above for 200 seconds and additionally,
each time the alarm is triggered, it displays the no. of seconds and
microseconds elapsed since the program started execution. (Hint: Simply
place the alarm system call in a loop and use gettimeofday()).*/

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>
#include <stdlib.h>

// Global variable to store the start time of the program
struct timeval start;

// Signal handler function to be called when the alarm is triggered
void funct1() {
    struct timeval end;
    gettimeofday(&end, NULL);

    // Calculate the elapsed time in seconds and microseconds
    long seconds_elapsed = end.tv_sec - start.tv_sec;
    long microseconds_elapsed = end.tv_usec - start.tv_usec;

    if (microseconds_elapsed < 0) {
        seconds_elapsed -= 1;
        microseconds_elapsed += 1000000;
    }

    // Display the elapsed time
    printf("Alarm triggered! Time elapsed: %ld seconds and %ld microseconds\n", 
           seconds_elapsed, microseconds_elapsed);

}

int main() {
    // Get the start time of the program
    gettimeofday(&start, NULL);
    
    // Register the signal handler for SIGALRM
        signal(SIGALRM, funct1);

    // Run the program for 200 seconds
    for (int i = 0; i < 200 / 5; i++) {
        // Set the first alarm to go off in 5 seconds
        alarm(5);

        pause();  // Wait for the alarm signal, then trigger the handler
    }

    // After 200 seconds, exit the program
    printf("Program completed after 200 seconds.\n");

    return 0;
}
