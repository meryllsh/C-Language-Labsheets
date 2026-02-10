/*Modify the program in question 2, so that the main() function declares an array
of size 20 of the struct student, allows the input of an integer value n, and
performs the input of data for n students, then displays them back. The
program should then display the name, address and age of the youngest
student in the array. If there are several students with the youngest age, the
program will display only the first one.*/

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
struct student *students;
int n, young=0;
do{
printf("Please input the value of n representing the number of records for a student: \n");
scanf("%d", &n);
if(n<1 || n>20){
printf("Error input. Retry: /n");
}
}
while(n<1 || n>20);

printf("Input data: \n");
for(int i=0; i<n; i++){
inputStudent(&students[i]);
}

printf("Display data: \n");
for(int j=0; j<n; j++){
displayStudent(&students[j]);
}
printf("Displaying the name, address and age of the youngest student: \n");
int int_young=0;
young=students[0].age;
for(int k=0; k<n; k++){
if(students[k].age<young){
young=students[k].age;
int_young=k;
}
}
displayStudent(&students[int_young]);

return 0;
}

