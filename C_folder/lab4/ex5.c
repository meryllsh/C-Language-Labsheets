/*Write a program that opens a file called “lab45.dat” for writing. If the file does not
exist, the program creates it. If it exists already, the program will simply overwrite
it. Your program should then read data for 5 students from the terminal and write
them into the file. Your data should consist of the names of students (20
characters), a student id (10 characters), date of birth (10 characters), gender (7
characters (male/female)) and marital status (10 characters(single/married)). Write
the data in the file as individual fields.*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

struct student {
	char name[20];
	char id[10];
	char dob[10];
	char gender[7];
	char marital_status[10];
};

int main() {
	struct student s;
	
	int fd = open("lab45.txt", O_WRONLY | O_CREAT | O_TRUNC, 0664); 

	if (fd == -1) {
	printf("Error opening file");
	return -1;
	}

	for (int i=0; i<2; i++) {
		printf("Enter name: ");
		scanf("%s", s.name);
		printf("Enter id: ");
		scanf("%s", s.id);
		printf("Enter DoB: ");
		scanf("%s", s.dob);
		printf("Enter gender: ");
		scanf("%s", s.gender);
		printf("Enter marital status: ");
		scanf("%s", s.marital_status);

		write(fd, &s, sizeof(struct student));
	}

	close(fd);

	return 0;
}
