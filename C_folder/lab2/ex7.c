/*Write a program that performs the input of the surname, first name and
address of a person and displays back these values.*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
char surname[25];
char fname[25];
char addr[25];
printf("Please input your surname: ");
scanf("%s", surname);
printf("Please input your first name: ");
scanf("%s", fname);
printf("Please input your address: ");
scanf("%s", addr);
printf("Surname: %s\n", surname);
printf("First name: %s\n", fname);
printf("Address: %s\n", addr);
return 0;
}


