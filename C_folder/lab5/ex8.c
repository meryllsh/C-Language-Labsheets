/*10. Modify the program in question 3 so that it works as follows:
a. The main program declares a 2-D array with 3 columns. In the first column, it
fills in a number of angles of your choice between 0 and 2π radians (you can
choose the intervals eg. 0, π/6, π/3, etc. It then opens a file “angles.dat” for
writing and finally creates two threads.
b. The threads calculate respectively the values of cos and sin for different values
of x and store them in the array, with cos in the 1st column and sin in the second
column. (Note: thread 1 calculates cos and thread 2 calculates sin)
c. Thread 1 reads the different angles and write the angles and their cos values in
the file “angles.dat”.
d. Thread 2 reads the different angles and write the angles and their sin values in
the file.
e. The thread that completes the work last closes the file (You can use a shared
variable to indicate if one thread has already completed the work).
(Note: Either thread should write the values for all the angles before the other one
start writing the values. – Use mutex lock for the purpose).*/

#include <stdio.h>
#include <pthread.h>
#include <math.h>
#include <fcntl.h>
#include <unistd.h>

void *sine(void *args);
void *cosine(void *args);

pthread_mutex_t mutex; //To use a mutex lock, it has to be declared of type pthread_mutex_t.
int changed = 0;
int fd;

int main() {
	double arr[6][3];
        arr[0][0] = 0;
        printf("%lf, ", arr[0][0]);
        for (int i=5; i>0; i--){
                arr[i][0] = M_PI / (15 - ((i-1)*3));
                printf("%lf, ", arr[i][0]);
                }
                printf("\n");

	fd = open("angles.dat", O_WRONLY | O_CREAT, 0644);
	pthread_t thread_sin;
	pthread_t thread_cos;

	pthread_mutex_init(&mutex, NULL); //The mutex lock has to be initialized. This can be achieved at declaration time using the macro PTHREAD_MUTEX_INITIALIZER.


	pthread_create(&thread_sin, NULL, sine, (void*) arr);
	pthread_create(&thread_cos, NULL, cosine, (void*) arr);

	pthread_join(thread_sin, NULL);
	pthread_join(thread_cos, NULL);

	pthread_mutex_destroy(&mutex); //to free any system resources associated with the mutex.

	return 0;
}

double factorial(int n) {
	if (n == 0)
		return 1;
	else
		return n*factorial(n-1);
}

void *sine(void *args) {
	double (*arr)[3] = (double(*)[3])args;

	for (int i=0; i<6; i++) {
		double result = 0;
		for (int n=0; n<=15; n++) {
			int temp = 2*n + 1;
			arr[i][2] += (pow(-1, n)/factorial(temp))*pow(arr[i][0], temp);
		}
		printf("%lf, ", arr[i][2]);
	}
	printf("\n");
	
        pthread_mutex_lock(&mutex);
        for (int i=0; i<6; i++)
                write(fd, &arr[i][2], sizeof(double));
        if (changed == 1)
                close(fd);
        else
                changed = 1;
        pthread_mutex_unlock(&mutex);

	return NULL;
}

void *cosine(void *args) {
        double (*arr)[3] = (double(*)[3])args;

        for (int i=0; i<6; i++) {
                double result = 0;
                for (int n=0; n<=15; n++) {
                        int temp = 2*n;
                        arr[i][1] += (pow(-1, n)/factorial(temp))*pow(arr[i][0], temp);
                }
                printf("%lf, ", arr[i][1]);
        }
        printf("\n");

	pthread_mutex_lock(&mutex);
	for (int i=0; i<6; i++){
		write(fd, &arr[i][1], sizeof(double));
	}
	if (changed == 1)
		close(fd);
	else
		changed = 1;
	pthread_mutex_unlock(&mutex);

	return NULL;
}
// gcc ex8.c -lpthread -lm -o ex8
