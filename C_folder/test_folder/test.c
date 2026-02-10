#include <stdio.h>

int main(){
  int X=5;
  int *ptr_X=&X;
  printf("Value of X is %d\n", X);
  printf("Address of X is %p\n", ptr_X);
  return 0;
}

