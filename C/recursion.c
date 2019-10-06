
#include<conio.h>
#include<stdio.h>

int factorial(int n)
{
if(n>1)
return(n*factorial(n-1));
return 1;
}
int main()
{
auto unsigned int n;
printf("Hi , I will find factorial for you \n");
printf("Enter the number : ");
scanf("%d",&n);
if(n<=1)
{
printf("The factorial of %d is 1",n);
return 0;
}
else
{
printf("The factorial of %d is %ld",n,factorial(n));
getch();
return 0;
}
}
