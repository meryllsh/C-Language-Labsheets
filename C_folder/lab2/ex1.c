/*A function f(x) is defined as f(x)=x4 + x3 + 3x2 + 2. Write a function poly() that takes an
integer, x, as parameter and it implements the function f(x), i.e for any given value x,
poly(x) should return the value of x4 + x3 + 3x2 + 2. You can make use of pow() function from the math library.

Note: To use the math library, you have to use #include <math.h> in your programs and for compilation you have to use
    gcc <program name> -lm –o <object file>
Eg. gcc prog1.c -lm –o prog1*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
int x=0;
int value=0;
printf("The polynomial is as follows: x4 + x3 + 3x2 + 2.\n");
printf("Please input the value of x: \n");
scanf("%d", &x);
value=(pow(x,4)+pow(x,3)+3*pow(x,2)+2);
printf("The value for the polynomial is as follows: %d\n", value);
return 0;
}

