#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
int fd[2];
int p;
int n;
int x;
char line[20];
x=pipe(fd);
p=fork();
if (p==0)
{ printf("Hello- I'm the child\n");
close(fd[1]);
n=read(fd[0],line,12);
printf("Child - Line read was %s \n", line); }
else
{ close(fd[0]);
write(fd[1],"hello world \n",12);
}
exit(0);
}
