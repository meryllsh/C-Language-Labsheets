/*Type in the given program, compile and execute it. Then modify the
program so that triggers it an alarm in 5 seconds. When the alarm occurs,
it displays the message “Alarm triggered” and exits. Change the name of
the signal handler function to funct1().

#include <stdio.h>
#include <unistd.h>
#include<signal.h>
void handler(){
printf("signal handler called\n");
}

int main(){
signal(SIGALRM,handler);
alarm(10);
pause();
}
*/

#include <stdio.h>
#include <unistd.h>
#include<signal.h>
void funct1(){
printf("Alarm triggered\n");
}

int main(){
signal(SIGALRM,funct1);
alarm(5);
pause();
}


