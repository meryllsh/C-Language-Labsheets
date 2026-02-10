#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h> 
#include <unistd.h>
int main(){
	int fd;
	fd=open("write.txt",O_WRONLY|O_CREAT|O_TRUNC,0644);

	ssize_t byteswritten;
	char name[20];
	char id[10];
	char dob[10];
        char gender[7];
        char marital_status[10];
        
	if (fd<0)
	{
		printf("Error opening file");
		return 1;
	}
	
	for (int i=1;i<=2;i++){
	
	printf("Enter student name: ");
	scanf("%s",name);
        
        printf("Enter student id: ");
	scanf("%s",id);
	
      	printf("Enter student dob: ");
	scanf("%s",dob);
	
	printf("Enter student gender: ");
	scanf("%s",gender);
	
	printf("Enter student marital_status: ");
	scanf("%s",marital_status);
	
	byteswritten=write(fd,name,sizeof(name));
	if (byteswritten<0)
	{
	  printf("Error writing to file");
	  close(fd);
	  return 1;
	  
	}
	
	if (write(fd," ", 1) < 0) {
            printf("Error writing space to file");
            close(fd);
            return 1;
        }
        	        
	byteswritten=write(fd,id,sizeof(id));
	if (byteswritten<0)
	{
	  printf("Error writing to file");
	}
	
	if (write(fd," ", 1) < 0) {
            printf("Error writing space to file");
            close(fd);
            return 1;
        }
        
        byteswritten=write(fd,dob,sizeof(dob));
	if (byteswritten<0)
	{
	  printf("Error writing to file");
	}
	
	if (write(fd," ", 1) < 0) {
            printf("Error writing space to file");
            close(fd);
            return 1;
        }
        	        
	byteswritten=write(fd,gender,sizeof(gender));
	if (byteswritten<0)
	{
	  printf("Error writing to file");
	}
	
	              
	 if (write(fd," ", 1) < 0) {
            printf("Error writing space to file");
            close(fd);
            return 1;
        }
        
        byteswritten=write(fd,marital_status,sizeof(marital_status));
	if (byteswritten<0)
	{
	  printf("Error writing to file");
	}
	
	              
	 if (write(fd,"\n", 1) < 0) {
            printf("Error writing newline to file");
            close(fd);
            return 1;
        }
        
	}
	close(fd);

return 0;
}
