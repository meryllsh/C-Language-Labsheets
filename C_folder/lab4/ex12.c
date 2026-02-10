#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(){

int fd;
char id[11];
char name[21];
char date[11];
char gender[8];
char status[11];
ssize_t n;

fd = open("lab45.dat", O_WRONLY|O_CREAT|O_TRUNC,0640);
/*
open() is used to open the file with the path /home/gps/Labsheets/Lab4P2/lab45.dat.
The flags used:
O_WRONLY: Open the file for writing only.
O_CREAT: If the file doesn’t exist, create it.
O_TRUNC: If the file exists, truncate it (i.e., erase its contents).
0640 sets the file permissions so that the owner has read/write access, the group has read access, and others have no access.
The file descriptor returned by open() is stored in fd. If the file opening fails, fd would be -1.
*/

for(int i=0; i<2;i++){
printf("Enter Name: ");
scanf("%s",name);

printf("Enter Student Id: ");
scanf("%s",id);

printf("Enter date of birth in the format dd/mm/yy: ");
scanf("%s",date);

printf("Enter the gender: ");
scanf("%s",gender);

printf("Enter marital status: ");
scanf("%s",status);

n = write(fd,name,21);
n = write(fd,id,10);
n = write(fd,date,10);
n = write(fd,gender,7);
n = write(fd,status,10);
}
/*
Writing to the file:
After each input is collected, it is written to the file using write(). The write() function takes three arguments:
fd: The file descriptor (the file where data will be written).
name/id/date/gender/status: The data to be written (from the arrays).
Number of bytes: The number of bytes to write (the size of the array). For example, write(fd,name,21) writes 21 bytes (20 characters for the name plus the null terminator).
*/

close(fd);
return 0;
}
