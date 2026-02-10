/*Write a program which allows the user to populate a global array with 10 ints. The
program should then allow creation of 2 threads. The first thread should display all the
even numbers in the array. The second thread must display the odd numbers in the array.
The user should be allowed to choose which thread gets to run first. Your program should
use mutex locks to ensure that the first thread which runs is allowed to finish before the
other one starts displaying its elements.*/

#include <stdio.h>      // Standard input/output library
#include <pthread.h>    // For using pthreads (threads and mutexes)
#include <unistd.h>     // For sleep function

// Global array of 10 integers
int arr[10];

// Mutex lock to control thread execution order
pthread_mutex_t lock;

// Function to display even numbers from the array
void* display_even(void* arg) {
    pthread_mutex_lock(&lock);  // Lock to ensure exclusive access to this thread first
    printf("Even numbers: ");
    for (int i = 0; i < 10; i++) {
        if (arr[i] % 2 == 0) {  // Check if the number is even
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
    pthread_mutex_unlock(&lock);  // Unlock to allow the next thread to run
    return NULL;
}

// Function to display odd numbers from the array
void* display_odd(void* arg) {
    pthread_mutex_lock(&lock);  // Lock to ensure exclusive access to this thread first
    printf("Odd numbers: ");
    for (int i = 0; i < 10; i++) {
        if (arr[i] % 2 != 0) {  // Check if the number is odd
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
    pthread_mutex_unlock(&lock);  // Unlock to allow the next thread to run
    return NULL;
}

int main() {
    pthread_t thread1, thread2;  // Thread variables
    int choice;  // Variable to store user choice for which thread runs first
    
    // Initialize the mutex lock
    pthread_mutex_init(&lock, NULL);

    // Populate the array with 10 integers from user input
    printf("Enter 10 integers:\n");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);  // Take user input for each integer in the array
    }

    // Ask the user to choose which thread to run first
    printf("Choose which thread to run first:\n");
    printf("1. Display even numbers\n");
    printf("2. Display odd numbers\n");
    scanf("%d", &choice);  // Get the user's choice

    // Create the two threads based on the user's choice
    if (choice == 1) {
        // If the user chooses to display even numbers first
        pthread_create(&thread1, NULL, display_even, NULL);  // Create the "even numbers" thread
        pthread_create(&thread2, NULL, display_odd, NULL);   // Create the "odd numbers" thread
    } else {
        // If the user chooses to display odd numbers first
        pthread_create(&thread1, NULL, display_odd, NULL);   // Create the "odd numbers" thread
        pthread_create(&thread2, NULL, display_even, NULL);  // Create the "even numbers" thread
    }

    // Wait for the first thread to finish executing
    pthread_join(thread1, NULL);
    // Wait for the second thread to finish executing
    pthread_join(thread2, NULL);

    // Destroy the mutex lock after both threads are done
    pthread_mutex_destroy(&lock);

    return 0;
}

