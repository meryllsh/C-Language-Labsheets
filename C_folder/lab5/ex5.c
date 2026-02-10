#include <pthread.h>
#include <stdio.h>
#include <unistd.h>


void * funct1(void * arg);
int main()
{
pthread_t threadid; //pthread_t threadid;: This declares a variable threadid that will hold the thread identifier for the new thread.
int i,j;
int x=1;
pthread_create(&threadid,NULL,funct1,(void *)&x);
/*pthread_create(&threadid, NULL, funct1, (void *)&x);:

This line creates a new thread that will run the funct1 function.
&threadid: The address of the thread identifier is passed to pthread_create so that the system can store the ID of the new thread.
NULL: This is for thread attributes, which are not specified here, so NULL is passed.
funct1: The function that the new thread will execute.
(void *)&x: The argument passed to funct1. It's cast to void * because the function signature of funct1 requires it. However, this argument isn't used in this example.
*/
for (j=0; j <10; j++)
{ for (i=0; i<1000; i++);
printf("Hi I'm the parent\n");
sleep(2);
}
return 0;
}
void * funct1(void * arg)
{ int i,j;
for (j=0;j<10; j++)
{ for (i=0; i<1000; i++);
printf("Hi I'm the created thread\n");

sleep(1);
}
}
