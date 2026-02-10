/*Modify the program in question 2 such that after the fork, the child modifies values in
all odd numbered elements. Each process should now display all its elements.*/

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
	id = fork();
	if(id==0){
	for (int a=1; a<10; a+=2){
	number[a]=1;
	}
	}
	if(id==0){
	for (int j=0; j<10; j++) {
		printf("Child process displays: %d\n", number[j]);	
	}
	}
	else{
	for (int k=0; k<10; k++) {      
		printf("Parent process displays: %d\n", number[k]);	
	}
	}

	return 0;
}

