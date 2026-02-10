/*Using a text editor, create a file called “myfile.txt”, containing some text
(say one or two paragraphs). Create a program that opens the file
“myfile.txt” for reading, creates a pipe, then forks. The parent process reads
data from the file in blocks of 20 characters, sends it to the child through the
pipe. The child reads the data from the pipe and displays it on the screen.*/


#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
	int fds[2], fd = open("myfile.txt", O_RDONLY);
	int p = pipe(fds);  // Create a pipe
	int id = fork();   // Fork the process
	char str[21];     // Buffer to store read content (20 + 1 for null terminator)
	int successful_bytes_read;
	if (id != 0) {
		close(fds[0]);
		while ((successful_bytes_read = read(fd, str, sizeof(char) * 20)) > 0) {
                write(fds[1], str, successful_bytes_read);  // Write only the bytes that were read
		}
		close(fd);
		close(fds[1]);
	} else {
                close(fds[1]);
                while ((successful_bytes_read = read(fds[0], str, sizeof(char) * 20)) > 0) {
			str[successful_bytes_read] = '\0';
                        printf("%s", str);
                }
                close(fds[0]);
	}

	return 0;
}

 




