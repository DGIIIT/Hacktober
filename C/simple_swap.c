#include <stdio.h> 
  
int main() 
{ 
    int x, y; 
    printf("Enter Value of x "); 
    scanf("%d\n", &x); 
    printf("Enter Value of y "); 
    scanf("%d\n", &y); 
  
    int temp = x; 
    x = y; 
    y = temp; 
  
    printf("\nAfter Swapping: x = %d, y = %d", x, y); 
    return 0; 
} 
