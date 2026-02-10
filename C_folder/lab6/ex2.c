/*Write a program that reads a number of integer values from the terminal and places
them in an array. The program should then fork. The parent process should display
the values in all the odd numbered elements while the child displays values in the
even numbered elements. For each display the process displaying should indicate
whether it is the parent or the child.*/

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main() {
	int id;
	int number[10];

	for (int i=0; i<10; i++) {
		printf("Please input the number %d: \n", i+1);
		scanf("%d", &number[i]);
	}
	printf("Child process displays even numbered elements\n");
	printf("Parent process displays odd numbered elements\n");
	id = fork();
	if(id==0){
	for (int j=0; j<10; j+=2) {
	      
		printf("Child process displays: %d\n", number[j]);
		
	}
	}
	else{
	for (int k=1; k<10; k+=2) {
	       
		printf("Parent process displays: %d\n", number[k]);
		
	}
	}

	return 0;
}

