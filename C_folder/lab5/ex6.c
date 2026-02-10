/*Write a program that creates an array of 10 student names and an array of 10 student
ids. You can choose to input the values or directly assign them. The program should
then create two threads. The first created thread executes a loop that displays all the
names, while the second thread should execute a loop displaying the ids. In the mean
time the parent thread should sleep for 5 seconds, then display “Parent Thread
Exiting” and then exits.*/

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void * display_name(void* arg);
void * display_id(void* arg);

int main(){
int ids[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
char names[10][10] = {"Aaron", "Jay", "Sarah", "John", "Meryl", "Darren", "Ronnie", "Joseph", "Doris", "Patricia"};

pthread_t thread_id;
pthread_t thread_name;

pthread_create(&thread_id,NULL,display_id,(void *) ids);
pthread_create(&thread_name,NULL,display_name,(void *) names);

sleep(5);

printf("Parent Thread Exiting\n");

return 0;
 
}

void* display_id(void* arg){
int *ids = (int*) arg;
for(int i=0; i<10; i++)
printf("ID: %d\n", ids[i]);
return NULL;
}

void* display_name(void* arg){
char (*names)[10] = (char (*)[10]) arg; //char (*names)[10]: This declares a pointer names that points to an array of 10 characters.
for(int i=0; i<10; i++)
printf("Name: %s\n", names[i]);
return NULL;
}

