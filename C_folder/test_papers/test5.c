/**/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>


int main() {
	int fd_p1[2];
	int fd_p2[2];

	pipe(fd_p1);
	pipe(fd_p2);

	int p1 = fork();
	int p2 = fork();
	
	// parent process
	if (p1 != 0 && p2 != 0) {
		close(fd_p1[0]);
		close(fd_p2[0]);
		int fd = open("num.dat", O_WRONLY | O_CREAT, 0644);
		for (int i=1; i<=20; i++)
			write(fd, &i, sizeof(int));
		close(fd);
		
		int num;
		fd = open("num.dat", O_RDONLY);
		while (read(fd, &num, sizeof(int)) > 0) {
			if (num%2 == 0) {
				write(fd_p1[1], &num, sizeof(int));
			} else {
				write(fd_p2[1], &num, sizeof(int));
			}
		}

		close(fd_p1[1]);
		close(fd_p2[1]);

		waitpid(p1, NULL, 0);
		waitpid(p2, NULL, 0);
	}

	// process 1
	if (p1 == 0 && p2 != 0) {
		close(fd_p2[0]);
		close(fd_p2[1]);
		close(fd_p1[1]);

		int fd = open("even.dat", O_WRONLY | O_CREAT, 0644);

		int num;		
		while (read(fd_p1[0], &num, sizeof(int)) > 0) {
			printf("Process 1: %d\n", num);
			write(fd, &num, sizeof(int));
		}
		close(fd_p1[0]);
		close(fd);
	}

	// process 2
	if (p1 != 0 && p2 == 0) {
		close(fd_p1[0]);
		close(fd_p1[1]);
		close(fd_p2[1]);

		int fd = open("odd.dat", O_WRONLY | O_CREAT, 0644);

		int num;
		while (read(fd_p2[0], &num, sizeof(int)) > 0) {
			printf("Process 2: %d\n", num);
			write(fd, &num, sizeof(int));
		}
		close(fd_p2[0]);
		close(fd);

	}

	if (p1 == 0 && p2 == 0) return 0;

	return 0;
}
