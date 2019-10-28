#include <cmath>
#include <iostream>
#include <vector>

// This is the recursive solution to our problem.
unsigned int fibonacci_naive(int n) {
    if (n <= 1)
        return n;

    return fibonacci_naive(n - 1) + fibonacci_naive(n - 2);
}

/* 
	Here we are using Bottom-Up approach to solve the same problem.
	
	This simple optimization reduces time complexities from exponential to polynomial. 
*/
unsigned int fibonacci_fast(int n) {
    // write your code here
    std::vector<int> fib = {0, 1};
    if (n == 0)
        return fib[0];
    if (n == 1)
        return fib[1];
    for (int index = 2; index <= n; ++index)
        fib.push_back(fib[index - 1] + fib[index - 2]);

    return fib.back();
}
/* 
 *	Here we are using memorization approach to solve the same problem.
 *	
 *	This simple optimization reduces time complexities, but memory complexity increases,
 *  this method is very util when you need to compute various numbers, once you store 
 *  the result and compute them only once 
*/
unsigned int fibonacci_memorization(int n) {
    static std::vector<int> table;  // our cache
    if (n <= 1) {
        return n;
    } else if (n >= table.size()) {
        table.resize(n + 1);
    }

    if (table[n] == 0) {
        //recalc if we don't have a value
        table[n] = fibonacci_memorization(n - 1) + fibonacci_memorization(n - 2);
    }
    return table[n];
}

/* 
 *	Here we are using a equation to compute fib(n)
 *  fib(n) = ((1 + √5)/2)^(n+1)/√5 + 1/2
 *  High values can break this, return 0
*/
unsigned int fibonacci_sublinear(int n) {
    const double sqrt5 = std::sqrt(5);
    double phi = (1 + sqrt(5)) / 2; 
    return (std::pow(phi, n) / sqrt5);
}

/* 
 *	Here we are using a equation to compute fib(n)
 *  fib(n) = ((1 + √5)/2)^(n+1)/√5 + 1/2
 *  but precompute values, algo making 1/sqrt5 to mutiply and diferenciate
 *  to fibonacci_sublinear function
 *  High values can break this, return 0
*/
unsigned int fibonacci_const_sublinear(int n) {
    const double inversesqrt5 = 0.44721359549995793928183473374626;
    const double phi = 1.6180339887498948482045868343656;
    return (std::pow(phi, n) * inversesqrt5 + 0.5);
}

/* 
 *	Here we are using iterative method to compute fib(n)
*/
unsigned int fibonacci_iterative(int n) {
    int n1 = 0, n2 = 1, fib, i;
    if (n <= 1)
        return n;
    for (i = 2; i <= n; i++) {
        fib = n1 + n2;
        n1 = n2;
        n2 = fib;
    }
    return fib;
}

/* 
 *	Here we are using matrix based method to compute fib(n)
 *  The matrix representation gives the following closed expression for the Fibonacci numbers:
 * |1 1|^n = |fib(n+1) fib(n)|
 * |1 0|     |fib(n) fib(n-1)| 
*/

//declare functions used in this method
void multiply(int F[2][2], int M[2][2]); 
void power(int F[2][2], int n);

unsigned int fibonacci_matrix(int n) {
    int F[2][2] = {{1, 1}, {1, 0}};
    if (n == 0)
        return 0;
    power(F, n - 1);
    return F[0][0];
}

/* function to realize power operation in a 2x2 matrix*/
void power(int F[2][2], int n) {
    if (n == 0 || n == 1)
        return;
    int M[2][2] = {{1, 1}, {1, 0}};

    power(F, n / 2);
    multiply(F, F);

    if (n % 2 != 0)
        multiply(F, M);
}

/* function to realize multiply operation in 2x2 matrix*/
void multiply(int F[2][2], int M[2][2]) {
    int x = F[0][0] * M[0][0] + F[0][1] * M[1][0];
    int y = F[0][0] * M[0][1] + F[0][1] * M[1][1];
    int z = F[1][0] * M[0][0] + F[1][1] * M[1][0];
    int w = F[1][0] * M[0][1] + F[1][1] * M[1][1];

    F[0][0] = x;
    F[0][1] = y;
    F[1][0] = z;
    F[1][1] = w;
}

int main() {
    int n = 0;
    std::cin >> n;

    //std::cout << fibonacci_naive(n) << '\n';
    std::cout << fibonacci_fast(n) << '\n';
    std::cout << fibonacci_memorization(n) << '\n';
    std::cout << fibonacci_sublinear(n) << '\n';
    std::cout << fibonacci_const_sublinear(n) << '\n';
    std::cout << fibonacci_iterative(n) << '\n';
    std::cout << fibonacci_matrix(n) << '\n';
    return 0;
}
