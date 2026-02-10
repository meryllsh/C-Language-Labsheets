/*Write a program that opens the above file, allows you to enter an integer value,
(eg. 5) on the terminal, go to that particular student in the file and displays the
information for that student. (Hint: use lseek).*/

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
	int n, fd = open("lab45.dat", O_RDONLY);
	if (fd == -1) return -1;

	struct student s;

	while (1) {
		printf("Enter the student position to display their details(ctrl+c to exit): ");
		//The program enters an infinite loop, allowing the user to continuously request the details of different students by specifying their position in the file.
		scanf("%d", &n);

		int seek = lseek(fd, sizeof(struct student) * n, SEEK_SET);
		read(fd, &s, sizeof(struct student));

		printf("Name: %s, ", s.name);
		printf("ID: %s, ", s.id);
		printf("DoB: %s, ", s.dob);
		printf("Gender: %s, ", s.gender);
		printf("Marital status: %s\n", s.marital_status);
	}

	close(fd);

	return 0;
}

/*whence (Starting Point):

Specifies the reference point for the offset. It determines how offset is interpreted. Possible values are:
SEEK_SET: The offset is set relative to the beginning of the file.
SEEK_CUR: The offset is set relative to the current file pointer position.
SEEK_END: The offset is set relative to the end of the file.
*/
