/*Write a function that has as parameter the radius of a sphere and it calculates the surface
area and volume of the sphere. These values should be passed to the caller.
A toy is made of two balls, one fitted inside the other one as shown in the diagram
below. The space in-between the balls is filled with a liquid. Write a main function
that allows the input of the radius of each of the balls and it calculates and displays
the volume of the liquid as well as the total surface area that is in contact with the
liquid. Make use of the function defined above.*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double *circle(int *radius){
double *ptr = (double *)malloc(2*sizeof(double));
*ptr=(4*M_PI*pow(*radius,2));
*(ptr+1)=((4.0/3)*M_PI*pow(*radius,3));
return ptr;
}

int main(){
int r1=0, r2=0;
double *arr1, *arr2;
double vol_liquid=0, final_area=0;
printf("Please input the radius for the larger ball: \n");
scanf("%d", &r1);
printf("Please input the radius for the smaller ball: \n");
scanf("%d", &r2);
arr1=circle(&r1);
arr2=circle(&r2);
vol_liquid=*(arr1+1)-*(arr2+1);
printf("Volume of the liquid: %lf\n", vol_liquid);
final_area=*arr1-*arr2;
printf("Total surface area that is in contact with the liquid: %lf\n", final_area);
free(arr1);
arr1=NULL;
free(arr2);
arr2=NULL;
return 0;
}

