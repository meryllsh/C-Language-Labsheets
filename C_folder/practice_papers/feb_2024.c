#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void* evenElements(void* args);
void* oddElements(void* args);

pthread_mutex_t lock;

int main() {
int array[10];
for(int i=0; i<10; i++){
printf("Please enter number %d\n", i);
scanf("%d", array+i);
}

pthread_t thread1;
pthread_t thread2;
    int option;

    pthread_mutex_init(&lock, NULL);

    printf("Please input 0 for even thread to run first or input 1 for odd thread to run first: ");
    scanf("%d", &option);

if(option == 0){
        pthread_create(&thread1, NULL, evenElements, (void*) array);
        pthread_create(&thread2, NULL, oddElements, (void*) array);
}
else if(option == 1){
        pthread_create(&thread2, NULL, oddElements, (void*) array);
        pthread_create(&thread1, NULL, evenElements, (void*) array);
}
else {
        printf("Invalid option.\n");
        return 1;
    }

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    pthread_mutex_destroy(&lock);

    return 0;
}

void* evenElements(void* args) {
int* array = (int*) args;
    for (int j = 0; j < 10; j++) {
            pthread_mutex_lock(&lock);
            if(*(array+j)%2==0){
            printf("Even: %d\n", *(array+j));
            }
            pthread_mutex_unlock(&lock);
            
        } 
    return NULL;
}


void* oddElements(void* args) {
    int* array = (int*) args;
    for (int j = 0; j < 10; j++) {
            pthread_mutex_lock(&lock);
            if(*(array+j)%2!=0){
            printf("Odd: %d\n", *(array+j));
            }
            pthread_mutex_unlock(&lock);
            
        } 
    return NULL;
}
