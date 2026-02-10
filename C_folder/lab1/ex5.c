/*Write a program to input the radius of a sphere and output the volume and surface
area of the sphere.*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
 int radius;
 printf("Please input the radius of a sphere: \n");
 scanf("%d", &radius);
 printf("The volume of the sphere is: %f\n", ((4.0/3)*M_PI*radius*radius*radius)); 
 printf("The surface area of a sphere is: %f\n", (4*M_PI*radius*radius));
 return 0;
}

