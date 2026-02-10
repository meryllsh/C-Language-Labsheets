#include <sys/time.h>
#include <stdio.h>
#include <limits.h>

int main(){
struct timeval start, end;
int array[100];
int max=INT_MIN;
for(int i=0; i<100; i++){
printf("Enter number %d", i+1);
scanf("%d", array+i);
}
gettimeofday(&start, NULL);
for(int j=0; j<100; j++){
if(array[j]>max){
max=array[j];
}
}
printf("The largest element is %d\n", max);
gettimeofday(&end, NULL);

double time_seconds=0, time_microseconds;
time_seconds=end.tv_sec-start.tv_sec;
time_microseconds=end.tv_usec-start.tv_usec;

if (time_microseconds < 0) {
        time_seconds -= 1;
        time_microseconds += 1000000;
 }


printf("Time in seconds: %lf \n", time_seconds);
printf("Time in microseconds: %lf \n", time_microseconds);
return 0;
}
//31 microseconds
