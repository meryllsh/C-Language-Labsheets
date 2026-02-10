/*Write a program that reads the file “input13.dat” (created in question 10), displays
the name, the size of the name, the address and the size of the address for the

person with the longest name as well as for the person with the longest address.
The program should also display the average size of names and average size of
addresses in the file.*/

#include <stdio.h>
#include <fcntl.h>
#include <limits.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
	int fd = open("input13.dat", O_RDONLY), max_name = INT_MIN, max_addr = INT_MIN;
	char name[50], addr[50], nname[50], aname[50], naddr[50], aaddr[50];
	int lname, laddr_for_lname, laddr, lname_for_laddr;
	float total_size_name=0.0f, total_size_addr=0.0f, total=0.0f;
	if (fd == -1) return -1;

	while (read(fd, &lname, sizeof(int)) > 0) {
		read(fd, &name, sizeof(name));
		read(fd, &laddr, sizeof(int));
		read(fd, addr, sizeof(addr));
		
		total_size_name=total_size_name+lname;
		total_size_addr=total_size_addr+laddr;
		total=total+1;

		if (lname > max_name) {
			strcpy(nname, name); // copy name to nname
			strcpy(naddr, addr);
			max_name = lname;
			laddr_for_lname = laddr;
		}
		if (laddr > max_addr) {
			strcpy(aname, name);
			strcpy(aaddr, addr);
			max_addr = laddr;
			lname_for_laddr = lname;
		}
	}
	printf("Longest name - Name: %s, length of name: %d, Address: %s, length of address: %d \n", nname, max_name, naddr, laddr_for_lname);
	printf("Longest addr - Name: %s, length of name: %d, Address: %s, length of address: %d \n", aname, lname_for_laddr, aaddr, max_addr);
	printf("The average size of names: %f \n", total_size_name/total);
	printf("The average size of addresses: %f \n", total_size_addr/total);

	return 0;
}

