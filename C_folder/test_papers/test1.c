/*The file words.txt", contains one word per line. Write a program creates 2 processes P1 and P2 and sends all the vowels to the file "vowels.txt", and all the consonants to the file "consonants.txt". The program should display the process ids and the time interval between the creation and termination of each process. The program should then create 2 threads T1 and T2 which display the contents of "vowels.txt" and "consonants.txt" respectively. Which of the two will run depends on the last letter of the last word in "words.txt". If the last letter of the last word is a vowel, T1 will run first then T2, else T2 will run followed by T1.

gcc test1.c -lpthread -o test1
include -lm if cmath library such as power is used*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <pthread.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORDS 100  // Define the maximum number of words

int is_vowel(char c) {
    char vowels[] = "AEIOUaeiou";
    for (int i = 0; vowels[i] != '\0'; i++) {
        if (c == vowels[i]) {
            return 1;
        }
    }
    return 0;
}

void *display_vowels(void *arg) {
    int fd, n;
    char c;
   
    fd = open("vowels.txt", O_RDONLY);
    if (fd == -1) {
        perror("Error opening vowels.txt for reading");
        return NULL;
    }
   
    printf("Contents of vowels.txt:\n");
    while ((n = read(fd, &c, 1)) > 0) {
        printf("%c", c);
    }
   
    close(fd);
    return NULL;
}

void *display_consonants(void *arg) {
    int fd, n;
    char c;
   
    fd = open("consonants.txt", O_RDONLY);
    if (fd == -1) {
        perror("Error opening consonants.txt for reading");
        return NULL;
    }
   
    printf("Contents of consonants.txt:\n");
    while ((n = read(fd, &c, 1)) > 0) {
        printf("%c", c);
    }


   
    close(fd);
    return NULL;
}

void process_file_vowels() {
    int fd_words, fd_vowels;
    ssize_t n;
    char word[50], c;

    fd_words = open("words.txt", O_RDONLY);
    if (fd_words == -1) {
        perror("Error opening words.txt for reading");
        return;
    }

    fd_vowels = open("vowels.txt", O_WRONLY | O_CREAT | O_TRUNC, 0664);
    if (fd_vowels == -1) {
        perror("Error opening vowels.txt for writing");
        close(fd_words);
        return;
    }

    while ((n = read(fd_words, &c, 1)) > 0) {
        if (is_vowel(c)) {
            write(fd_vowels, &c, 1);
        }
    }

    close(fd_words);
    close(fd_vowels);
}

void process_file_consonants() {
    int fd_words, fd_consonants;
    ssize_t n;
    char word[50], c;

    fd_words = open("words.txt", O_RDONLY);
    if (fd_words == -1) {
        perror("Error opening words.txt for reading");
        return;
    }

    fd_consonants = open("consonants.txt", O_WRONLY | O_CREAT | O_TRUNC, 0664);
    if (fd_consonants == -1) {
        perror("Error opening consonants.txt for writing");
        close(fd_words);
        return;
    }

    while ((n = read(fd_words, &c, 1)) > 0) {
        if (isalpha(c) && !is_vowel(c)) {
            write(fd_consonants, &c, 1);
        }
    }

    close(fd_words);
    close(fd_consonants);
}

char get_last_letter_of_last_word() {
    int fd_words;
    ssize_t n;
    char word[50], last_letter;
   
    fd_words = open("words.txt", O_RDONLY);
    if (fd_words == -1) {
        perror("Error opening words.txt for reading");
        return '\0';
    }

    // Read all words and get the last one
    while ((n = read(fd_words, &last_letter, 1)) > 0) {
        if (last_letter == '\n') {
            // Ignore newline characters, we want the last letter of a word
            n = read(fd_words, &last_letter, 1);
        }
    }

    close(fd_words);
    return last_letter;
}

int main() {
    pid_t p1, p2;
    struct timeval start1, end1, start2, end2;

    // Process 1 (P1): Handles vowels
    gettimeofday(&start1, NULL);  // Get start time
    p1 = fork();
    if (p1 == 0) {
        process_file_vowels();
        exit(0);
    }

    // Process 2 (P2): Handles consonants
    gettimeofday(&start2, NULL);  // Get start time
    p2 = fork();
    if (p2 == 0) {
        process_file_consonants();
        exit(0);
    }

    // Wait for both processes to finish
    waitpid(p1, NULL, 0);
    gettimeofday(&end1, NULL);  // Get end time for P1
    printf("P1 (Vowels) Process ID: %d, Time taken: %.6f seconds\n", p1,
           (double)(end1.tv_sec - start1.tv_sec) + (double)(end1.tv_usec - start1.tv_usec) / 1000000.0);

    waitpid(p2, NULL, 0);
    gettimeofday(&end2, NULL);  // Get end time for P2
    printf("P2 (Consonants) Process ID: %d, Time taken: %.6f seconds\n", p2,
           (double)(end2.tv_sec - start2.tv_sec) + (double)(end2.tv_usec - start2.tv_usec) / 1000000.0);

    // Get the last letter of the last word
    char last_letter = get_last_letter_of_last_word();

    // Thread creation based on the last letter
    pthread_t t1, t2;
    if (is_vowel(last_letter)) {
        printf("Last letter is a vowel, T1 (Vowels) will run first.\n");
        pthread_create(&t1, NULL, display_vowels, NULL);
        pthread_create(&t2, NULL, display_consonants, NULL);
    } else {
        printf("Last letter is a consonant, T2 (Consonants) will run first.\n");
        pthread_create(&t2, NULL, display_consonants, NULL);
        pthread_create(&t1, NULL, display_vowels, NULL);
    }

    // Wait for both threads to finish
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
}
