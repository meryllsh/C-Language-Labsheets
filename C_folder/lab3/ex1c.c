/*Modify the program in question 2 so that it uses an array of pointers to struct.
Note: In C, we use malloc() to allocate memory and free() to release the
memory.*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct student {
char surname[25];
char othername[25];
char addr[25];
int age;
};

void inputStudent(struct student *stud){
printf("Please enter your surname: \n");
scanf("%s", stud->surname);
printf("Please enter your othername: \n");
scanf("%s", stud->othername);
printf("Please enter your address: \n");
scanf("%s", stud->addr);
printf("Please enter your age: \n");
scanf("%d", &(stud->age));
}

void displayStudent(struct student *stud1){
printf("Surname: %s\n", stud1->surname);
printf("Other name: %s\n", stud1->othername);
printf("Address: %s\n", stud1->addr);
printf("Age: %d\n", stud1->age);
}

int main(){
int n, young=0;
do{
printf("Please input the value of n representing the number of records for a student: \n");
scanf("%d", &n);
if(n<1 || n>20){
printf("Error input. Retry: /n");
}
}
while(n<1 || n>20);

struct student *students=(struct student *)malloc(n*sizeof(struct student));
printf("Input data: \n");
for(int i=0; i<n; i++){
inputStudent(&(*(students+i)));
}

printf("Display data: \n");
for(int j=0; j<n; j++){
displayStudent(&(*(students+j)));
}
printf("Displaying the name, address and age of the youngest student: \n");
int int_young=0;
young=students->age;
for(int k=0; k<n; k++){
if((students+k)->age<young){
young=(students+k)->age;
int_young=k;
}
}
displayStudent(&(*(students+int_young)));
free(students);
students=NULL;
return 0;
}

