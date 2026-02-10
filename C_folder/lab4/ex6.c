/*Write a program to open the file in question 5, read all the data and display them on the screen.*/

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
	int fd = open("lab45.txt", O_RDONLY);
	struct student s;
	

	if (fd<0)
	{
		printf("Error opening file");
		return 1;
	}

	while (read(fd, &s, sizeof(struct student)) > 0) {
		printf("Name: %s, ", s.name);
		printf("ID: %s, ", s.id);
		printf("DoB: %s, ", s.dob);
		printf("Gender: %s, ", s.gender);
		printf("Marital status: %s\n", s.marital_status);
	
	}

	close(fd);

	return 0;
}



