/*Using a text editor, create a file called “lab44.dat”. Write a few sentences in it. Write
a program to read the text from the file and display on the screen.

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int fd;                 // File descriptor for the opened file
    ssize_t nread;          // Number of bytes read
    char buffer[256];       // Buffer to store file content

    // Open the file 'lab44.dat' in read-only mode
    fd = open("lab44.dat", O_RDONLY);
    if (fd == -1) {
        // If the file cannot be opened, display an error message and exit
        perror("Error opening file");
        return 1;
    }

    // Read the content of the file in chunks of 255 characters (1 reserved for null termination)
    while ((nread = read(fd, buffer, sizeof(buffer) - 1)) > 0) {
        // Null-terminate the buffer so it can be treated as a string
        buffer[nread] = '\0';

        // Write the content to the standard output (display on screen)
        write(STDOUT_FILENO, buffer, nread);
    }

    // Check if the read() call encountered an error
    if (nread == -1) {
        perror("Error reading file");
        close(fd);  // Close the file before exiting
        return 1;
    }

    // Close the file
    close(fd);

    return 0;
}


#include <stdio.h>
#include <fcntl.h>

int main() {
	int fd = open("./lab44.dat", O_RDONLY);
	char chr;

	while (read(fd, &chr, 1) > 0) {
		printf("%c", chr);
	}
	close(fd);
	return 0;
}
*/
#include <stdio.h>
#include <fcntl.h>

int main() {
	int fd = open("lab44.dat", O_RDONLY);
	char str[21];
	int successful_bytes_read;

	while ((successful_bytes_read = read(fd, &str, sizeof(char) * 20))>0) {
	        str[successful_bytes_read]='\0';
		printf("%s", str);
	}
	close(fd);
	return 0;
}


