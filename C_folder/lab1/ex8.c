/*Write a program that allows the input of an integer n, validates that n is positive
and displays whether n is prime.*/

#include <stdio.h>
#include <stdlib.h>

int main(){
int n=0;
printf("Please input an integer n: \n");
scanf("%d", &n);
while(n<=0){
printf("Error. Please input a positive value of n: \n");
scanf("%d", &n);
}
printf("%d is a positive integer.\n", n);
if(n==1){
printf("%d is not a prime number.\n", n);
}
else if(n==2 || n==3){
printf("%d is a prime number.\n", n);
}
else{
for(int i=2; i<=(n/2); i++){
if(n%i==0){
printf("%d is not a prime number.\n", n); 
return -1;
}
}
printf("%d is a prime number.\n", n);
}
return 0;
}

