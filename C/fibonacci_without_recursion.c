#include<stdio.h>    

int fibo(int n){
	if(n <= 1){
		return n;
	}
	int fibo = 1;
	int fiboPrev = 1;
	for(int i = 2; i < n; ++i){
		int temp = fibo;
		fibo += fiboPrev;
		fiboPrev = temp;
	}
	return fibo;
}

int main(){    
	int n;    
	printf("Calculate Fibonacci number: ");    
	scanf("%d",&n);    
	int fibonacci = fibo(n);
	printf("%d", fibonacci);

	return 0;  
}
