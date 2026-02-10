#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	if (argc != 3)
		return 1;

	int fd[2], input_fd = open(argv[1], O_RDONLY), output_fd = open(argv[2], O_WRONLY | O_CREAT, 0644);
	int p = pipe(fd);

	int id = fork();
	char c;

	if (id != 0) {
		close(fd[0]);
		while (read(input_fd, &c, sizeof(char)) > 0) {
			write(fd[1], &c, sizeof(char));
		}
		close(input_fd);
		close(fd[1]);
	} else {
		close(fd[1]);
		while (read(fd[0], &c, sizeof(char)) > 0) { 
				write(output_fd, &c, sizeof(char));
		}
		close(output_fd);
		close(fd[0]);
	}

	return 0;
}
