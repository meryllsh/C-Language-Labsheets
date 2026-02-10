/*Write a function that has two integer parameters x and y and swaps the values of the two
parameters. Make use of reference parameters, so that the function can be used by other
parts of the program to swap values.*/

#include <stdio.h>
#include <stdlib.h>

int fun(int *ptrx, int *ptry){
int temp=*ptrx;
*ptrx=*ptry;
*ptry=temp;
}

int main(){
int x=10, y=20;
printf("x=%d, y=%d\n", x, y);
fun(&x, &y);
printf("After swapping values in the function.\n");
printf("x=%d, y=%d\n", x, y);
return 0;
}


