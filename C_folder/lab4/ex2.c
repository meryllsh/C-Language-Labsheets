/*Question 2
Study the system call gettimeofday(). Write a program that contains the following:
4. A function Power, defined by you to calculate Xn

, where X is of type float and n

is an integer. You can use iteration or recursion, but do not make use of the pre-
defined function pow().

5. A main() function that calculates the value of a polynomial, such as
X100 +X 99+ X98, for some chosen value X.
1. Use gettimeofday() to find out for how long the program runs. (Time should be
displayed in number of seconds and milliseconds).*/

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>

/*
struct timeval{
long tv_sec;
long tv_usec;
};
*/
double Power(double *x, int *n){
double total=1;
for(int i=0; i<*n; i++){
total=total*(*x);
}
return total;
}

int main(){
struct timeval start, end;
gettimeofday(&start, NULL);

double num=0, sum=0;
double total_seconds=0, total_microseconds=0, total_milliseconds=0;
printf("Please input the value of x: \n");
scanf("%lf", &num);

for(int j=100; j>=0; j--){
sum=sum + Power(&num, &j);
}
printf("The polynomial is: %lf \n", sum);
gettimeofday(&end, NULL);

total_seconds=end.tv_sec-start.tv_sec;
total_microseconds=end.tv_usec-start.tv_usec;

if (total_microseconds < 0) {
        total_seconds -= 1;
        total_microseconds += 1000000;
 }

total_milliseconds=total_microseconds/1000;
printf("Time in seconds: %lf \n", total_seconds);
printf("Time in milliseconds: %lf \n", total_milliseconds);
return 0;
}
