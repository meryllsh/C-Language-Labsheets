/*Write a program that defines a struct student to hold the following information
for a student: surname, other names, address, age. The program should have
the following functions:
1. A function inputStudent() that takes a student struct as parameter
and allows of input of data that are stored in the struct parameter.
2. A function displayStudent() that takes a student struct as parameter
and displays the attribute values on the screen.

The program should declare two variables of type student, allow input of data for
two students and store them in those variables. The program should then display
the names and address of the older student among the two. If they are of the same
age, the program should display the names and addresses of both of them.*/

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
struct student student1;
struct student student2;
printf("Input data for the first student: \n");
inputStudent(&student1);
printf("Input data for the second student: \n");
inputStudent(&student2);

printf("Displaying the names and address of the older student(s): \n");
if(student1.age>student2.age){
displayStudent(&student1);
}
else if(student2.age>student1.age){
displayStudent(&student2);
}
else{
displayStudent(&student1);
displayStudent(&student2);
}
return 0;
}

