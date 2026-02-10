#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int num = 0;

void timeout_handler() {
    printf("\nTime's up! Writing 0 to file.\n");

    int fd = open("nums.txt", O_WRONLY | O_CREAT | O_TRUNC, 0664);
    if (fd != -1) {
        int default_num = 0;
        write(fd, &default_num, sizeof(int));
        close(fd);
    }

    exit(0);
}

int main() {
    signal(SIGALRM, timeout_handler); // Set up the timeout signal handler
    alarm(3); // Start the 3-second countdown

    printf("Please input an integer (you have 3 seconds): ");
    if (scanf("%d", &num) == 1) {
        alarm(0); // Cancel the alarm if input is received
    } else {
        num = 0; // If no input, default to 0
    }

    // Write the number to file
    int fd = open("nums.txt", O_WRONLY | O_CREAT | O_TRUNC, 0664);
    if (fd != -1) {
        write(fd, &num, sizeof(int));
        close(fd);
    }

    printf("Written %d to nums.txt\n", num);
    return 0;
}

