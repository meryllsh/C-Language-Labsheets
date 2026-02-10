/*Question 3
In C, programs can take arguments. For that the main can have two
parameters, called argc and argv and is declared as follows:
int main(int argc, char *argv[]){
................... }
When the program is run with arguments, argc will keep count of number
of arguments given (including the program name), while argv will contain
the arguments, as follows: argv[0] will contain the program name, argv[1]
will contain the first argument, argv[2], the second argument etc.
Eg. If my programme is called prog1 and I run it as follows:
prog1 file1 file2
argc will have value 3, argv[0] will have value prog1, argv[1] will have value
file1 and argv[2] will have value file2.
Modify the program in question 2, so that the program runs with two
arguments: an input file and an output file. The parent process reads from
the input file and writes into the pipe, while child reads from the pipe and
writes to the output file.*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	if (argc != 3)
		return 1;

	int fd[2], input_fd = open(argv[1], O_RDONLY), output_fd = open(argv[2], O_WRONLY | O_CREAT, 0644);
	int p = pipe(fd);

	int id = fork();
	int successful_bytes_read;
	char c[21];

	if (id != 0) {
		close(fd[0]);
		while ((successful_bytes_read = read(input_fd, c, sizeof(char) * 20)) > 0) {
                write(fd[1], c, successful_bytes_read);  // Write only the bytes that were read
		}
		close(input_fd);
		close(fd[1]);
	} else {
		close(fd[1]);
		while ((successful_bytes_read = read(fd[0], c, sizeof(char) * 20)) > 0) {
			c[successful_bytes_read] = '\0';
                        write(output_fd, c, successful_bytes_read);
		}
		close(output_fd);
		close(fd[0]);
	}

	return 0;
}
// ./ex3 input.txt output.txt(run this in terminal, input.txt should already be created)
