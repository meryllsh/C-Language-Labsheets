#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include <sys/time.h>

void find_min_max(int n, int* array, int* min, int* max) {
	for (int i=0; i<n; i++) {
		if (*(array + i) < *min) {
			*min = *(array + i);
		}
                if (*(array + i) > *max) { 
                        *max = *(array + i);
                }
	}
}


int main() {
	int n, min = INT_MAX, max = INT_MIN;
	struct timeval start_time;
	struct timeval end_time;

	printf("Enter the size of the array: "); 
	scanf("%d", &n);

	gettimeofday(&start_time, NULL);
	int* array = (int *) malloc(sizeof(int) * n);

	for (int i=0; i<n; i++) {
		*(array + i) = n - i - 10;	
	}

	printf("\n--Min and Max--\n");
	find_min_max(n, array, &min, &max);
	printf("Min = %d, Max = %d\n", min, max);

	gettimeofday(&end_time, NULL);

	double time_difference = end_time.tv_sec - start_time.tv_sec + ((end_time.tv_usec - start_time.tv_usec)/1000000.0);

	printf("Execution time: %f seconds\n", time_difference);

	free(array);
	return 0;
}
