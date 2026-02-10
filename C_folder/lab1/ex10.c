/*Write a program that allows the input on an integer value n, representing the
number of patients that visit a doctor over a given time period. The program
should then allow the input of n sets of three values, representing the patient id,
weight and fast blood sugar (FBS) level of the n patients. It displays the patient id,
FBS and weight of the patient having the highest FBS level and also for the patient
having the highest weight. If the two are the same patient, it should display the
information only once.*/

#include <stdio.h>
#include <stdlib.h>

int main(){
int n=0, pid=0, weight=0, fbs=0, l_weight=-9999999, l_fbs=-9999999;
printf("Please input an integer value n: \n");
scanf("%d", &n);
while(n<=0){
printf("Error. Please input a positive value of n: \n");
scanf("%d", &n);
}
int a_pid[n];
int a_weight[n]; 
int a_fbs[n];
for(int i=0; i<n; i++){
printf("For the patient number %d:\n", i+1);
printf("Please input your patient id: \n");
scanf("%d", &a_pid[i]);
printf("Please input your weight: \n");
scanf("%d", &a_weight[i]);
printf("Please input your fast blood sugar level: \n");
scanf("%d", &a_fbs[i]);
if(a_weight[i]>l_weight){
l_weight=a_weight[i];
}
if(a_fbs[i]>l_fbs){
l_fbs=a_fbs[i];
}
}

for(int i=0; i<n; i++){
if(l_weight==a_weight[i] && l_fbs!=a_fbs[i]){
printf("For the patient having the highest weight: \n");
printf("The patient id is %d\n", a_pid[i]);
printf("The patient weight is %d\n", a_weight[i]);
printf("The patient fast blood sugar level is %d\n", a_fbs[i]);
}
if(l_fbs==a_fbs[i] && l_weight!=a_weight[i]){
printf("For the patient having the highest fast blood sugar level: \n");
printf("The patient id is %d\n", a_pid[i]);
printf("The patient weight is %d\n", a_weight[i]);
printf("The patient fast blood sugar level is %d\n", a_fbs[i]);
}
if(l_weight==a_weight[i] && l_fbs==a_fbs[i]){
printf("For the patient having the highest weight and fast blood sugar level: \n");
printf("The patient id is %d\n", a_pid[i]);
printf("The patient weight is %d\n", a_weight[i]);
printf("The patient fast blood sugar level is %d\n", a_fbs[i]);
}
}
return 0;
}




