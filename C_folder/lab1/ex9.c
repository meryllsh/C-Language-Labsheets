/*Write a program that allows the input of an integer value n, followed by n more
integer values. It displays the largest value input among the n integer values.*/

#include <stdio.h>
#include <stdlib.h>

int main(){
int n=0, value=0, large=-99999;
printf("Please input an integer value n: \n");
scanf("%d", &n);
while(n<=0){
printf("Error. Please input a positive value of n: \n");
scanf("%d", &n);
}
for(int i=1; i<=n; i++){
printf("Please input the value for the integer %d: \n", i);
scanf("%d",  &value);
if(value>large){
large=value;
}
}
printf("The largest value is %d\n", large);
return 0;
}


