#include <sys/time.h>
#include <stdio.h>
#include <limits.h>

int main(){
struct timeval start, end;
int array[100];
int max=INT_MIN;
for(int i=0; i<100; i++){
array[i]=i;
}
gettimeofday(&start, NULL);
for(int j=0; j<100; j++){
if(array[j]>max){
max=array[j];
}
}

gettimeofday(&end, NULL);
printf("The largest element is %d\n", max);


double time_seconds=0, time_microseconds, total_time_microseconds;
time_seconds=end.tv_sec-start.tv_sec;
time_microseconds=end.tv_usec-start.tv_usec;

if (time_microseconds < 0) {
        time_seconds -= 1;
        time_microseconds += 1000000;
 }

total_time_microseconds=(time_microseconds)+((time_seconds)*1000000);

printf("The total time in microseconds: %lf \n", total_time_microseconds);
return 0;
}
//31 microseconds
