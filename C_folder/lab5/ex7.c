/*The formulae for calculating sin(x) and cos(x),by Mc Claurin’s series, where x is in
radians, is given below.

3. Write suitable C-functions for calculating sin(x) and cos(x) using these formulae.
4. Write a main function that allows the input of an angle x in degrees, converts it to
radians, creates two threads. One thread calculates and displays sin(x), while the
other one calculates and displays cos(x).*/

#include <stdio.h>
#include <pthread.h>
#include <math.h>

void *sine(void *args);
void *cosine(void *args);

int main() {
	int degrees;
	pthread_t thread_sin;
	pthread_t thread_cos;

	printf("Enter angle in degrees: ");
	scanf("%d", &degrees);

	double radian = degrees * M_PI / 180.0;

	pthread_create(&thread_sin, NULL, sine, (void*) &radian);
	pthread_create(&thread_cos, NULL, cosine, (void*) &radian);

	pthread_join(thread_sin, NULL);
	pthread_join(thread_cos, NULL);
	//In the provided code, pthread_join(thread_sin, NULL); and pthread_join(thread_cos, NULL); are used to ensure that the main thread waits for the two created threads (thread_sin and thread_cos) to finish their execution before the main program continues or exits. Here’s what these calls do in the context of this program.
	return 0;
}

double factorial(int n) {
	if (n == 0)
		return 1;
	else
		return n*factorial(n-1);
}

void *sine(void *args) {
	double x = *((double*)args);
	double result = 0;
	for (int n=0; n<=15; n++) {
		int temp = 2*n + 1;
		result += (pow(-1, n)/factorial(temp))*pow(x, temp);
	}

	printf("Sin(x) = %f\n", result);
	return NULL;
}

void *cosine(void *args) {
	double x = *((double*)args);
	double result = 0;
	for (int n=0; n<=15; n++) {
			int temp = 2*n;
			result += (pow(-1, n)/factorial(temp))*pow(x, temp);
	}
	printf("Cos(x) = %f\n", result);
	return NULL;
}

