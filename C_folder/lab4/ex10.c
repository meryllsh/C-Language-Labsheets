/*Write a program that creates a file called “input13.dat”. It then allows you to enter
the names and address of a number of persons. For each person it allows you to
input the name and address, it computes the length of the names and address and
writes in the file “input13.dat”, the length of the name, the name, the length of the
address and the address.*/

#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
	int n, fd = open("input13.dat", O_WRONLY | O_CREAT, 0644);
	char name[50], address[50];

	printf("Enter the number of persons: ");
	scanf("%d", &n);

	for (int i=0; i<n; i++) {
		printf("Name: ");
		scanf("%s", name);
		printf("Address: ");
		scanf("%s", address);

		int len_name = strlen(name);
		int len_addr = strlen(address);

		write(fd, &len_name, sizeof(int));
		write(fd, name, sizeof(name));
		write(fd, &len_addr, sizeof(int));
		write(fd, address, sizeof(address));
	}

	close(fd);


	return 0;
}
