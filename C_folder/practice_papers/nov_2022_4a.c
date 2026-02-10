#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
int id=fork();
if(id==-1){
printf("Error in ID");
return 1;
}
if(id!=0){
printf("I am the parent and the process ID of the child is %d\n", id);

}
if(id==0){
printf("I am a child and the process ID of parent is %d\n", getppid());

}


return 0;
}
