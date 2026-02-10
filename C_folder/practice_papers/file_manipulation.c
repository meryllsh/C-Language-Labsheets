#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){
int array[100];
for(int i=0; i<100; i++){
array[i]=i;
}
int pid=fork();
if(pid!=0){
int fd=open("./even.txt", O_WRONLY | O_CREAT, 0777);

if(fd==-1){
printf("Error opening file for writing");
return 1;
}
for(int j=0; j<100; j++){
if(array[j]%2==0){
write(fd, &array[j], sizeof(int));
}
}
close(fd);

int ffd=open("./odd.txt", O_WRONLY | O_CREAT, 0777);

if(fd==-1){
printf("Error opening file for writing");
return 1;
}
for(int z=0; z<100; z++){
if(array[z]%2!=0){
write(fd, &array[z], sizeof(int));
}
}
close(ffd);
wait(NULL);
}

if(pid==0){
int num=0;
int fp=open("./even.txt", O_RDONLY);
while(read(fp,&num,sizeof(int))>0)
{printf("Even: %d\n", num);}
close(fp);

int ffp=open("./odd.txt", O_RDONLY);
while(read(ffp,&num,sizeof(int))>0)
{printf("Odd: %d\n", num);}
close(ffp);
}
return 0;
}

