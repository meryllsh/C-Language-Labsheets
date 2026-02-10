/*Write a function called inputArray() that has as parameters an integer array, A, and an
integer, n. It allows the input of n values into array A. Write a function displayArray()
that also takes as parameters an integer Array, A, and an integer, n, and performs the
display of n values from A. Write the required program code to test your functions.*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void inputArray(int arrayA[], int *n){
for(int i=0; i<*n; i++){
printf("Please input number %d in the array: \n", i+1);
scanf("%d", arrayA + i);
}
}
void displayArray(int arrayA[], int *n){
for(int j=0; j<*n; j++){
printf("array[%d]: %d\n", j, arrayA[j] );
}
}
int main(){
int num;
printf("Please input the number, n, in the array: ");
scanf("%d", &num);
int array[num];
inputArray(array, &num);
displayArray(array, &num);
return 0;
}



