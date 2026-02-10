/**/
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main() {
	int arr[10];

	for (int i=0; i<10; i++) {
		printf("Enter value for index %d: ", i);
		scanf("%d", &arr[i]);
	}

	int id = fork();

	if (id == 0)
		for (int i=1; i<10; i+=2)
			arr[i] = 100;

	if (id != 0)
		for (int i=0; i<10; i++)
			printf("Parent process, %d\n", arr[i]);
	else
		for (int i=0; i<10; i++)
			printf("Child process, %d\n", arr[i]);

	return 0;
}
