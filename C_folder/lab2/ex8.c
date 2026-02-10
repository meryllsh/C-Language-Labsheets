/*You have to input the surname, first name of n students (n<=20) and their marks in OS.
Write a program that contains the following:
1. A function to perform the input of the surname, first name and marks of a student.
2. A function that has as parameters an array of floats and an integer count, and it
finds the positions of the maximum and minimum values in the array and passes
these to the caller. The integer count represents the number of elements in the
array.
3. A main() function that allows the input of an integer value n. It calls the above
functions to:
a. perform the inputs of surname, first name and marks of n students.
b. Find and display the surname, first name and marks of the student having
scored the highest marks and of the student having scored lowest marks.*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void fun1(char sname[][50], char firstname[][50], float mark[], int num){
printf("Please input your surname: ");
scanf("%s", sname[num]);
printf("Please input your first name: ");
scanf("%s", firstname[num]);
printf("Please input your mark: ");
scanf("%f", &mark[num]);
}
void fun2(float m[], int *number, int *small, int *large){
*small=0;
*large=0;
float x=0;
float y=0;
x=m[0];
y=m[0];
for(int j=0; j<*number; j++){
if(m[j]<x){
x=m[j];
*small=j;
}
if(m[j]>y){
y=m[j];
*large=j;
}
}
}

int main(){
int n, largest, smallest;
do{
printf("Please input the value of n: ");
scanf("%d", &n);
if(n<1 || n>20){
printf("Invalid input. Retry:\n");
}
}
while(n<1 || n>20);

char surname[n][50];
char fname[n][50];
float marks[n];

for(int i=0; i<n; i++){
 printf("Entering the details for student %d: \n", i+1);
 fun1(surname, fname, marks, i);
}
fun2(marks, &n, &smallest, &largest);
printf("Student having scored the highest mark: \n");
printf("Surname: %s, First name: %s, mark: %f\n", surname[largest], fname[largest], marks[largest]);
printf("Student having scored the lowest mark: \n");
printf("Surname: %s, First name: %s, mark: %f\n", surname[smallest], fname[smallest], marks[smallest]);

return 0;
}

/*
//Lab2 ex8
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int * lar_sma(int arr[], int n)

{
   //declaring array to be returned
   int * minmax =(int*)malloc(2*sizeof(int));

    int largest = -99;
    int smallest = 999;
    
    for(int i= 0; i< n; i++ ){ 
     
     if(arr[i]> largest){
        largest= arr[i];
        minmax[1] = i;
     }
     
     if(arr[i] < smallest){
         smallest= arr[i];
        minmax[0] = i;
     }
     
     }
// returning array

return minmax; 

} 


void inputname(char arr[][50], int n)

{
    char buff[50];

    for(int i= 0; i< n; i++ ){ 
    printf("Enter name of student %d \n",(i+1));
    scanf("%s",buff); 
    strcpy(arr[i],buff);
    
   }
}

void inputsurname(char arr[][50], int n)

{
    char buff[50];
    for(int i= 0; i< n; i++ ){ 
    printf("Enter surname of student %d \n",(i+1));
    scanf("%s", buff); 
    strcpy(arr[i],buff);
    
   }
}

void inputmarks(int arr[], int n)

{
    for(int i= 0; i< n; i++ ){ 
    printf("Enter marks of student %d \n",(i+1));
    scanf("%d", &arr[i]); 
    
   }
}


int main() 

{

   int count;
   int * posminmax;
   
   // Input number of inputs
   printf("Enter number of inputs \n");
   scanf("%d", &count);
   
   char arrname[count][50];
   char arrsurname[count][50];
   int arrmks[count];
   
   inputname(arrname,count);
   inputsurname(arrsurname,count);
   inputmarks(arrmks,count);
   
   posminmax = lar_sma(arrmks, count);

   printf("\nName of student with largest mark is : %s",arrname[posminmax[1]]);
   printf("\nSurame of student with largest mark is : %s",arrsurname[posminmax[1]]);
   printf("\nmark of student with largest mark is : %d",arrmks[posminmax[1]]);

   printf("\n\nName of student with lowest mark is : %s",arrname[posminmax[0]]);
   printf("\nSurame of student with lowest mark is : %s",arrsurname[posminmax[0]]);
   printf("\nmark of student with lowest mark is : %d",arrmks[posminmax[0]]);

   free(posminmax);
}*/

