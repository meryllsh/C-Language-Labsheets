/*Write a program to input a number of positive values terminated by -1 and display
the number of even values input as well as the sum of the even values.*/

#include <stdio.h>
#include <stdlib.h>

int main(){
 int i=0, num=0;
 float sum=0;
 do{
 printf("Please enter a positive value(-1 to terminate): \n");
 scanf("%d", &num);
 if(num>0 && num%2==0){
  sum+=num;
  i++;
  }
 }
 while(num!=-1);
 printf("The number of even values are: %d\n", i);
 printf("The sum of the even values are: %f\n", sum);
 return 0;
}


