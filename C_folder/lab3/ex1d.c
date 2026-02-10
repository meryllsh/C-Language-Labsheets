/*A garage needs to store information about servicing it provides to vehicles. For each
servicing it performs in a day, it wishes to store the servicing number, the
registration number of the vehicle, and the surname of the owner and the cost of the
servicing. Write a program containing the following:


1. A struct servicing containing the following data members,

int servicing_no;
char Reg_no[10];
char surname[15];
float cost;

2. A function Input_serv() to input the data of one servicing record, but not the
cost.
3. A function Disp_serv() to display the data of one servicing record.

4. A function assign_cost() that assigns the cost of a servicing, given the servic-
ing number. The function should also take as parameter an array containing

servicing records.
5. A main program that declares an array for storing information for up to 20
servicing records (structs). The program then displays a menu that allows
users to choose one of the following:
6. Add a new servicing record.
7. To enter a servicing number and the program allows the input of
the cost and assigns the cost to the servicing record.

8. To enter a servicing number and the program displays all infor-
mation for the corresponding record

9. The display of the average costs for records in the array

The program should then perform the task required by the user. Also an option
should be provided for exit the program.*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct servicing{
int servicing_no;
char Reg_no[10];
char surname[15];
float cost;
};

void Input_serv(struct servicing *service){
printf("Please input your servicing number: \n");
scanf("%d", &(service->servicing_no));
printf("Please input your registration number: \n");
scanf("%s", service->Reg_no);
printf("Please input your surname: \n");
scanf("%s", service->surname);
(service->cost)=0;
}

void Disp_serv(struct servicing *service1){
printf("Servicing number: %d\n", service1->servicing_no);
printf("Registration number: %s\n", service1->Reg_no);
printf("Surname: %s\n", service1->surname);
printf("Cost: %f\n", service1->cost);

}

void assign_cost(float price2, int service_no, struct servicing *service2, int countt){
int s_digit=0, i=0;
for(i=0; i<countt; i++){
if((service2+i)->servicing_no==service_no){
s_digit=i;
}
}
(service2+s_digit)->cost=price2;
}

int main(){
struct servicing servicings[20];
int choice, count=0;
int s_no;
float price;
int s_no2, digit;
do{
printf("Here is the menu: \n");
printf("1.Add a new servicing record.\n");
printf("2.To enter a servicing number and the program allows the input of the cost and assigns the cost of the servicing record.\n");
printf("3.To enter a servicing number and the program displays all information for the corresponding record.\n");
printf("4.The display of the average costs for records in the array.\n");
printf("5.Exit.\n");
printf("Please input the task you want to perform(1-5): \n");
scanf("%d", &choice);

if(choice==1){
Input_serv(&servicings[count]);
count++;
}

else if(choice==2){
printf("Please enter a servicing number: \n");
scanf("%d", &s_no);

printf("Please enter the cost you want to assign to the servicing number mentioned: \n");
scanf("%f", &price);
assign_cost(price, s_no, servicings, count);
}

else if(choice==3){
printf("Please enter a servicing number: \n");
scanf("%d", &s_no2);
for(int j=0; j<count; j++){
if(servicings[j].servicing_no==s_no2){
digit=j;
}
}
Disp_serv(&servicings[digit]);
}

else if(choice==4){
float sum=0;
for(int k=0; k<count; k++){
sum+=servicings[k].cost;
}
printf("Average costs for records in the array: %f\n", sum/count);
}

else if(choice<1 || choice>5){
printf("Error input. Retry: \n");
}
}
while(choice!=5);
printf("Exiting the program...\n");
return 0;
}


