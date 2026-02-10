#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {

	int fd[2];
	int p;
	int n;
	int x;
	int array[2], array2[2];
	x=pipe(fd);
	p=fork();
	if (p!=0) {
	
	printf("Enter the first value: \n");
	scanf("%d", &array[0]);
	printf("Enter the second value: \n");
	scanf("%d", &array[1]);
	write(fd[1], array, sizeof(array));
	wait(NULL);
	
	int total;
	n=read(fd[0],&total,sizeof(int));
	printf("Display the value: %d\n", total);
	}
	if (p==0) { 
	n=read(fd[0],array2,sizeof(array2));
	int multiply = array2[0] * array2[1];
		write(fd[1],&multiply,sizeof(int));
		sleep(2);
	}
	

	


	return 0;
}
