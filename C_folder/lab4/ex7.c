/*Write a program to open the file in question 5 in Append mode and add
information for 5 more students. Use the program in question 3 to read the
information from the file and display on the screen.*/

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
	
	int fd = open("lab45.dat", O_WRONLY | O_CREAT | O_APPEND, 0644);

	if (fd == -1) return -1;

	for (int i=0; i<5; i++) {
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
