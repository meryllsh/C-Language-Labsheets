/*To create a directory, the system call which is used is mkdir. This method returns an int
value (0 if the creation is successful). Amend the code above to allow the user to enter a String, dirName, and the program
should create a directory with that name.*/

#include <stdio.h>
#include <sys/stat.h> 

void main()
{
char name[255];
printf("Please specify folder name: \n");
scanf("%s", name);
int val=mkdir(name,0777);
if (val==0)
printf("Directory has been successfully created\n");
else
printf("Error in creation\n");

}


