/*Write a program that forks to create a child process. Each of the parent and the child
should execute a loop causing it to sleep for 1 second, wake up, display its pid and say
whether it is the parent or the child and also display its parent's pid.
Also use the command ps -a, in a separate console window, to check the pids of
the parent and child processes.*/

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main() {
	int id = fork();
	printf("id: %d \n", id);
	int pid;

	for (int i=0; i<20; i++) {
		if (id != 0) {
			pid = getpid();
			printf("Parent process, ID: %d\n", pid);
			printf("Parent process, PID: %d\n", getppid());
			sleep(1);
		} else {
			pid = getpid();
			printf("Child process, ID: %d\n", pid);
			printf("Child process, PID: %d\n", getppid());
			sleep(1);
		}
	}

	return 0;
}

