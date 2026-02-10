#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;
    ssize_t bytesRead;
    char buffer[256]; // Buffer to store a line of text from the file

    // Open the file in read-only mode
    fd = open("write.dat", O_RDONLY);

    if (fd < 0) {
        printf("Error opening file\n");
        return 1;
    }

    // Read the file content line by line
    while ((bytesRead = read(fd, buffer, sizeof(buffer) - 1)) > 0) {
        buffer[bytesRead] = '\0'; // Null-terminate the string
        printf("%s", buffer); // Print the content of the buffer to the screen
    }

    if (bytesRead < 0) {
        printf("Error reading file\n");
        close(fd);
        return 1;
    }

    // Close the file
    close(fd);
    
    return 0;
}
