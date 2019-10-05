#include <iostream>
#include <vector>

// This is the recursive solution to our problem.
int fibonacci_naive(int n) {
    if (n <= 1)
        return n;

    return fibonacci_naive(n - 1) + fibonacci_naive(n - 2);
}

/* 
	Here we are using Bottom-Up approach to solve the same problem.
	
	This simple optimization reduces time complexities from exponential to polynomial. 
*/
int fibonacci_fast(int n) {
    // write your code here
    std::vector<int> fib = {0,1};
    if(n==0)
	    return fib[0];
    if(n==1)
	    return fib[1];
    for(int index=2; index <= n; ++index)
	    fib.push_back(fib[index-1]+fib[index-2]);
    
    return fib.back();
}

int main() {
    int n = 0;
    std::cin >> n;

    //std::cout << fibonacci_naive(n) << '\n';
  
    std::cout << fibonacci_fast(n) << '\n';
    return 0;
}
