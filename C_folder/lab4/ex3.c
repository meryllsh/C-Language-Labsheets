/*Question 3
Write a program that executes a loop causing it to sleep for 2 seconds (using the sleep()
system call), wakes up and displays its pid as well as the total number of milliseconds
elapsed since it started. It can run the loop any number of times you choose. Your output
can be in the form:
Program with pid <pid> has run for <number of milliseconds> milliseconds.
Note: Make use of sleep() and gettimeofday() system calls.*/

#include <stdio.h>
#include <sys/time.h>  // For gettimeofday()
#include <unistd.h>    // For sleep() and getpid()

int main() {
    // Get the process ID (pid)
    int pid = getpid();

    // Get the start time
    struct timeval start, end;
    gettimeofday(&start, NULL);

    // Define number of iterations for the loop
    int loop_count = 5;  // You can change this to any number

    // Loop to execute the sleep() and measure time
    for (int i = 0; i < loop_count; i++) {
        // Sleep for 2 seconds
        sleep(2);

        // Get the current time after waking up
        gettimeofday(&end, NULL);

        // Calculate the total time elapsed in milliseconds
        long seconds_elapsed = end.tv_sec - start.tv_sec;
        long microseconds_elapsed = end.tv_usec - start.tv_usec;

        // Adjust if microseconds are negative (due to crossing second boundary)
        if (microseconds_elapsed < 0) {
            seconds_elapsed -= 1;
            microseconds_elapsed += 1000000;
        }

        // Total time in milliseconds
        long total_milliseconds = seconds_elapsed * 1000 + microseconds_elapsed / 1000;

        // Display the process ID and the time elapsed
        printf("Program with pid %d has run for %ld milliseconds.\n", pid, total_milliseconds);
    }

    return 0;
}

