/*Write a function that has as parameters an array A of integers and an integer value n
representing the number of elements in the array. The function finds the maximum and
minimum values in the array and passes these to the caller.
Write a program (main() function) that allows a user to input a number of integers in an
array and then uses the above function to find the smallest as well as the largest value in
the array. These values should be displayed.*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int *array(int arrayA[], int *num){
int *ptr = (int *)malloc(2*sizeof(int));
*ptr=arrayA[0]; 
*(ptr+1)=arrayA[0];
for(int i=0; i<*num; i++){
if(arrayA[i]>*ptr){
*ptr=arrayA[i];}
if(arrayA[i]<*(ptr+1)){
*(ptr+1)=arrayA[i];}
}
return ptr;
}

int main(){
int n;
printf("Please input the number of integers you want the array to have: \n");
scanf("%d", &n);
int arrayB[n];
int *ptrr;
for(int j=0; j<n; j++){
printf("Please input the number %d: \n", j+1);
scanf("%d", arrayB + j);
}
ptrr=array(arrayB, &n);
printf("The max number is: %d\n", *ptrr);
printf("The min number is: %d\n", *(ptrr+1));
free(ptrr);
ptrr=NULL;
return 0;
}
