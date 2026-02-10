/*The setitimer() call allows the programmer to reset a timer at a regular time
interval. It also provides for finer time intervals than the alarm, since it can
set the timer at milliseconds. Check its use and write a program that opens a
file, triggers a timer every 500 ms, write in the file the total time elapsed
since it started executing, every time the timer is triggered. The program
should run for a total of 30 seconds.

struct timeval    it_interval;     //timer interval 
struct timeval    it_value;       // current value 

*/




#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>
#include <stdlib.h>

// Global variables to store the start time and the file pointer
struct timeval start;
int fd;

// Signal handler function to be called when the timer triggers
void timer_handler(int signum) {
    struct timeval end;
    gettimeofday(&end, NULL);

    // Calculate the elapsed time in seconds and microseconds
    long seconds_elapsed = end.tv_sec - start.tv_sec;
    long microseconds_elapsed = end.tv_usec - start.tv_usec;

    if (microseconds_elapsed < 0) {
        seconds_elapsed -= 1;
        microseconds_elapsed += 1000000;
    }

    // Write the elapsed time to the file
    printf("Alarm triggered! Time elapsed: %ld seconds and %ld microseconds\n", 
           seconds_elapsed, microseconds_elapsed);

    // Flush the file to make sure data is written immediately
    fflush(file);
}

int main() {
    // Get the start time of the program
    gettimeofday(&start, NULL);

    // Open the file to write elapsed time
    int fd = open("elapsed_time.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (fd == -1) 
    return 1;

    // Set up the signal handler for SIGALRM
    signal(SIGALRM, timer_handler);

    // Configure the timer to trigger every 500 milliseconds
    struct itimerval timer;
    timer.it_value.tv_sec = 0;          // Initial delay (0 seconds)
    timer.it_value.tv_usec = 500000;    // Initial delay (500 milliseconds)
    timer.it_interval.tv_sec = 0;       // Interval between triggers (0 seconds)
    timer.it_interval.tv_usec = 500000; // Interval between triggers (500 milliseconds)

    // Start the timer
    if (setitimer(ITIMER_REAL, &timer, NULL) == -1) {
        perror("Error setting timer");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    // Keep the program running for 30 seconds
    sleep(30);

    // Clean up: close the file
    fclose(file);

    printf("Program completed. Check 'elapsed_time.txt' for results.\n");

    return 0;
}
