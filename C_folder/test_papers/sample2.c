/*// labsheet 1 && labsheet 2 - basics
// #include <stdio.h> - includes the standard input/output library, for example printf, scanf, etc.
// #include <stdlib.h> - includes the standard library for example malloc, free, etc.
// #include <math.h> - includes the math library for example pow, sqrt, M_PI, etc. 
//  - use -lm flag to compile
// #include <limits.h> - includes the limits library for example INT_MIN, INT_MAX
// #include <float.h> - includes the float library for example FLT_MIN, FLT_MAX

// example for using pointers
// int* ptr = (int*) malloc(sizeof(int) * n);
// free(ptr);

// primitives are passed by value
// arrays are passed by reference
// structs are passed by value

// %d - integer
// %f - float
// %c - char
// %s - string
// %p - pointer
// %ld - long
// %lf - double
// %u - unsigned int

// labsheet 3 - structs
// example for using structs
// struct student {
// 	char surname[50];
// 	char othername[50];
// 	char address[50];
// 	int age;
// };

// using pointer with struct
// struct student* ptr = (struct student*) malloc(sizeof(struct student) * n);
// free(ptr);
// ptr->age = 20;

// labsheet 4 - system calls and file handling
// #include <sys/time.h> - includes the time library for example gettimeofday
// #include <sys/types.h> - includes the types library for example pid_t
// #include <unistd.h> - includes the unix standard library for example getpid, fork, exec, etc.
// #include <fcntl.h> - includes the file control library for example open, close, read, write, etc.

// example for using system calls
// process id and parent process id
// int processID = getpid(), parentProcessID = getppid();

// get time of day
// struct timeval start_time;
// gettimeofday(&start_time, NULL);

// example for calculating time difference
// double time_difference = end_time.tv_sec - start_time.tv_sec + ((end_time.tv_usec - start_time.tv_usec)/1000000.0);

// sleep for 1 second
// sleep(1);

// example for using file handling
// O_CREAT - create file if it does not exist
// O_RDWR - read and write
// O_RDONLY - read only
// O_WRONLY - write only
// O_APPEND - append to the end of the file

// int fd = open("file.txt", O_CREAT | O_WRONLY, 0644); - open file for writing only and create if it does not exist
// int fd = open("file.txt", O_CREAT | O_RDWR, 0644); - open file for reading and writing and create if it does not exist
// int fd = open("file.txt", O_CREAT | O_RDONLY, 0644); - open file for reading only and create if it does not exist
// int fd = open("file.txt", O_WRONLY | O_CREAT | O_APPEND, 0644); - open file for reading and writing and create if it does not exist and append to the end of the file
// close(fd); - close file descriptor

// check if file is open
// if(fd == -1) {
// 	printf("Error opening file\n");
// 	exit(1);
// }

// write to file
// write(fd, "Hello World", 11); 1st argument is file descriptor, 2nd argument is the string to write, 3rd argument is the number of bytes to write

// read from file
// char buffer[100];
// read(fd, buffer, 100); 1st argument is file descriptor, 2nd argument is the buffer to read into, 3rd argument is the number of bytes to read

// read from file using a loop with a buffer
// char buffer[100];
// int successful_bytes_read;
// while ((successful_bytes_read = read(fd, buffer, 100)) > 0) {
// 	printf("%s", buffer);
// }

// lseek(fd, 0, SEEK_SET); - move the file pointer to the beginning of the file
// SEEK_SET - move the file pointer to the beginning of the file
// SEEK_CUR - move the file pointer to the current position of the file pointer
// SEEK_END - move the file pointer to the end of the file


// string functions
// strlen - get the length of a string before the null terminator
// strcpy - copy a string from one location to another
// strcat - concatenate two strings
// strcmp - compare two strings

// snprintf - write formatted output to a string
// example for using snprintf
// char buffer[100];
// snprintf(buffer, 100, "Hello %s %d", "World", 2021);

// labsheet 5 - pthreads
// #include <pthread.h> - includes the pthread library for example pthread_create, pthread_join, etc.
// pthread_t thread; - declare a thread
// pthread_create(&thread, NULL, function, args); - create a thread argument 1 is the thread, argument 2 is the thread attributes, argument 3 is the function to run, argument 4 is the arguments to pass to the function
// pthread_join(thread, NULL); - join a thread argument 1 is the thread, argument 2 is the return value of the function
// pthread_exit(NULL); - exit a thread

// example for using pthreads
// void* function(void* args) {
// 	int* arg = (int*) args;
// 	printf("Hello %d\n", *arg);
// 	return NULL;
// }

// int arg = 2021;
// pthread_t thread;
// pthread_create(&thread, NULL, function, (void*) &arg);
// pthread_join(thread, NULL);

// pthread_mutex_t mutex; - declare a mutex
// pthread_mutex_init(&mutex, NULL); - initialise a mutex || pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; - initialise a mutex
// pthread_mutex_lock(&mutex); - lock a mutex
// pthread_mutex_unlock(&mutex); - unlock a mutex
// pthread_mutex_destroy(&mutex); - destroy a mutex

// labsheet 6 - processes (fork)
// #include <sys/types.h> - includes the types library for example pid_t
// #include <unistd.h> - includes the unix standard library for example getpid, fork, exec, etc.

// example for using fork
// int id = fork();
// int pid;
// if (id != 0) {
// 	pid = getppid();
// 	printf("Parent process, ID: %d\n", pid);
// } else {
// 	pid = getpid();
// 	printf("Child process, ID: %d\n", pid);
// }

// labsheet 8 - Pipes
// #include <unistd.h> - includes the unix standard library for example getpid, fork, exec, etc.

// example for using pipes
// int fd[2]; - fd[0] is the read end, fd[1] is the write end
// pipe(fd);
// int id = fork();
// if (id != 0) {
// 	close(fd[0]);
// 	write(fd[1], "Hello World", 11);
// } else {
// 	close(fd[1]);
// 	char buffer[100];
// 	read(fd[0], buffer, 100);
// 	printf("%s\n", buffer);
// }

// labsheet 9 - directories
// #include <dirent.h> - includes the directory library for example opendir, readdir, closedir, etc.

// dirent structure
// struct dirent {
// 	ino_t d_ino; - inode number
// 	off_t d_off; - offset to the next dirent
// 	unsigned short d_reclen; - length of this record
// 	unsigned char d_type; - type of file
// 	char d_name[256]; - filename
// };

// entry->d_type - DT_REG for file, DT_DIR for directory

// example for using directories
// DIR* dir = opendir(".");
// struct dirent* entry;
// while ((entry = readdir(dir)) != NULL) {
// 	printf("%s\n", entry->d_name);
// }
// closedir(dir);

// rmdir("directory"); - remove a directory
// mkdir("directory", 0777); - create a directory
// unlink("file"); - remove a file

// recursive function to list all files in a directory
// void list_files(char* path) {
// 	DIR* dir = opendir(path);
// 	struct dirent* entry;
// 	while ((entry = readdir(dir)) != NULL) {
// 		if (entry->d_type == DT_DIR) {
// 			if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
// 				char new_path[100];
// 				snprintf(new_path, 100, "%s/%s", path, entry->d_name);
// 				list_files(new_path);
// 			}
// 		} else {
// 			printf("%s/%s\n", path, entry->d_name);
// 		}
// 	}
// 	closedir(dir);
// }




#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <float.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>
#include <dirent.h>

// Example for using pointers
void example_pointers() {
    int n = 10;
    int* ptr = (int*) malloc(sizeof(int) * n);
    // Use the pointer
    free(ptr);
}

// Example for using structs
struct student {
    char surname[50];
    char othername[50];
    char address[50];
    int age;
};

void example_structs() {
    int n = 10;
    struct student* ptr = (struct student*) malloc(sizeof(struct student) * n);
    // Use the struct pointer
    free(ptr);
}

// Example for using system calls
void example_system_calls() {
    // Get process id and parent process id
    int processID = getpid();
    int parentProcessID = getppid();

    // Get time of day
    struct timeval start_time;
    gettimeofday(&start_time, NULL);

    // Calculate time difference
    struct timeval end_time;
    double time_difference = end_time.tv_sec - start_time.tv_sec + ((end_time.tv_usec - start_time.tv_usec)/1000000.0);

    // Sleep for 1 second
    sleep(1);

    // Example for using file handling
    int fd = open("file.txt", O_CREAT | O_WRONLY, 0644);
    // Check if file is open
    if(fd == -1) {
        printf("Error opening file\n");
        exit(1);
    }
    // Write to file
    write(fd, "Hello World", 11);
    // Read from file
    char buffer[100];
    read(fd, buffer, 100);
    // Read from file using a loop with a buffer
    int successful_bytes_read;
    while ((successful_bytes_read = read(fd, buffer, 100)) > 0) {
        printf("%s", buffer);
    }
    // Move the file pointer to the beginning of the file
    lseek(fd, 0, SEEK_SET);
    // Close file descriptor
    close(fd);
}

// Example for using string functions
void example_string_functions() {
    // Get the length of a string before the null terminator
    char str[] = "Hello";
    int length = strlen(str);

    // Copy a string from one location to another
    char dest[10];
    strcpy(dest, str);

    // Concatenate two strings
    char str1[] = "Hello";
    char str2[] = "World";
    strcat(str1, str2);

    // Compare two strings
    char str3[] = "Hello";
    char str4[] = "World";
    int result = strcmp(str3, str4);

    // Write formatted output to a string
    char buffer[100];
    snprintf(buffer, 100, "Hello %s %d", "World", 2021);
}

// Example for using pthreads
void* function(void* args) {
    int* arg = (int*) args;
    printf("Hello %d\n", *arg);
    return NULL;
}

void example_pthreads() {
    int arg = 2021;
    pthread_t thread;
    pthread_create(&thread, NULL, function, (void*) &arg);
    pthread_join(thread, NULL);
}

// Example for using processes (fork)
void example_processes() {
    int id = fork();
    int pid;
    if (id != 0) {
        pid = getppid();
        printf("Parent process, ID: %d\n", pid);
    } else {
        pid = getpid();
        printf("Child process, ID: %d\n", pid);
    }
}

// Example for using pipes
void example_pipes() {
    int fd[2];
    pipe(fd);
    int id = fork();
    if (id != 0) {
        close(fd[0]);
        write(fd[1], "Hello World", 11);
    } else {
        close(fd[1]);
        char buffer[100];
        read(fd[0], buffer, 100);
        printf("%s\n", buffer);
    }
}

// Example for using directories
void example_directories() {
    DIR* dir = opendir(".");
    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }
    closedir(dir);
}

// Recursive function to list all files in a directory
void list_files(char* path) {
    DIR* dir = opendir(path);
    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
                char new_path[100];
                snprintf(new_path, 100, "%s/%s", path, entry->d_name);
                list_files(new_path);
            }
        } else {
            printf("%s/%s\n", path, entry->d_name);
        }
    }
    closedir(dir);
}*/
