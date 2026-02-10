/* Your program aims to create two threads to print even and odd numbers from an array of 10 integers provided by the user. It also uses a mutex to control which thread runs first based on the user's input.


#include <stdio.h>
#include <pthread.h>

void* display_even(void* args);
void* display_odd(void* args);
pthread_mutex_t mutex;
int choice;

int main() {
    int arr[10];

    pthread_t thread_even;
    pthread_t thread_odd;

    // Input values for the array
    for (int i = 0; i < 10; i++) {
        printf("Enter value: ");
        scanf("%d", &arr[i]);
    }

    // Ask user to choose which thread runs first
    do {
        printf("Which thread should run first?\n");
        printf("1. Thread 1 (Even)\n2. Thread 2 (Odd)\n");
        scanf("%d", &choice);
        if (choice < 1 || choice > 2)
            printf("Invalid choice. ");
    } while (choice < 1 || choice > 2);

    // Initialize the mutex
    pthread_mutex_init(&mutex, NULL);

    // Lock the mutex before starting threads
    pthread_mutex_lock(&mutex);

    // Create the threads in the order based on user's choice
    if (choice == 1) {
        pthread_create(&thread_even, NULL, display_even, (void*) arr);
        pthread_create(&thread_odd, NULL, display_odd, (void*) arr);
    } else {
        pthread_create(&thread_odd, NULL, display_odd, (void*) arr);
        pthread_create(&thread_even, NULL, display_even, (void*) arr);
    }

    // Wait for both threads to finish
    pthread_join(thread_even, NULL);
    pthread_join(thread_odd, NULL);

    // Destroy the mutex
    pthread_mutex_destroy(&mutex);

    return 0;
}

void* display_even(void* args) {
    int* arr = (int*) args;  // Cast the pointer to an integer array

    if (choice != 1) pthread_mutex_lock(&mutex);  // Lock if it's not the first thread

    // Print even numbers
    for (int i = 0; i < 10; i++) {
        if (arr[i] % 2 == 0)
            printf("Thread 1 (Even) - %d\n", arr[i]);
    }

    pthread_mutex_unlock(&mutex);  // Unlock when done
    return NULL;
}

void* display_odd(void* args) {
    int* arr = (int*) args;  // Cast the pointer to an integer array

    if (choice != 2) pthread_mutex_lock(&mutex);  // Lock if it's not the first thread

    // Print odd numbers
    for (int i = 0; i < 10; i++) {
        if (arr[i] % 2 != 0)
            printf("Thread 2 (Odd) - %d\n", arr[i]);
    }

    pthread_mutex_unlock(&mutex);  // Unlock when done
    return NULL;
}














#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void* func1(void* args);
void* func2(void* args);

pthread_mutex_t mutex;

int main() {
    pthread_t thread1;
    pthread_t thread2;

    int n = 5;

    pthread_mutex_init(&mutex, NULL);

    pthread_create(&thread1, NULL, func1, (void*) &n);
    pthread_create(&thread2, NULL, func2, (void*) &n);


    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    pthread_mutex_destroy(&mutex);
    return 0;
}

void* func1(void* args) {
    int n = (int) args;

    pthread_mutex_lock(&mutex);
    for (int i=0; i<(*n); i++) {
        printf("Thread 1 - %d\n", i);
        sleep(2);
    }
    pthread_mutex_unlock(&mutex);
    return NULL;    
}

void* func2(void* args) {
    int n = (int) args;
    pthread_mutex_lock(&mutex);
    for (int i=0; i<(*n); i++) {
        printf("Thread 2 - %d\n", i);
        sleep(1);
    }
    pthread_mutex_unlock(&mutex);
    return NULL;    
}*/














#include <stdio.h>
#include <stdlib.h>

int main() {
    int fd[2];
    int fdvar = open("myfile.txt", O_RDONLY);
    pipe(fd);
    int child_id = fork();

    if (child_id != 0) {

        close(fd[0]);
        write(fd[1], "Hello World", 11);
        close(fd[1]);
    } else {
        close(fd[1]);
        char str[11];
        read(fd[0], str, 11);
        close(fd[0]);
        printf("%s\n", str);
    }
    // fd[0] - read
    // fd[1] - write

}
