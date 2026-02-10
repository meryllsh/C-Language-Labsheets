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

void circle(int *radius, double *area, double *volume){
*area=(4*M_PI*pow(*radius,2));
*volume=((4.0/3)*M_PI*pow(*radius,3));
}

int main(){
int r1=0, r2=0;
double area1=0, area2=0, vol1=0, vol2=0, vol_liquid=0, final_area=0;
printf("Please input the radius for the larger ball: \n");
scanf("%d", &r1);
printf("Please input the radius for the smaller ball: \n");
scanf("%d", &r2);
circle(&r1, &area1, &vol1);
circle(&r2, &area2, &vol2);
vol_liquid=vol1-vol2;
printf("Volume of the liquid: %lf\n", vol_liquid);
final_area=area1-area2;
printf("Total surface area that is in contact with the liquid: %lf\n", final_area);
return 0;
}


