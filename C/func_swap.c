#include <stdio.h> 
  
void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
  
int main() 
{ 
    int x, y; 
    printf("Enter Value of x "); 
    scanf("%d", &x); 
    printf("\nEnter Value of y "); 
    scanf("%d", &y); 
    swap(&x, &y); 
    printf("\nAfter Swapping: x = %d, y = %d", x, y); 
    return 0; 
} 
