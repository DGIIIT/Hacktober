/*
Problem Description 
	Task : 
		Given two integers n and m, output Fn mod m (i.e, the remainder of Fn when divided by m).
		
	Input Format : 
		The input consists of two integers n and m given on the same line (separated by a space).

	Constraints :
		1 ≤ n ≤ 10^18, 2 ≤ m ≤ 10^5. 
	Output Format : 
		Output Fn mod m. 
	
	Time Limit : 1 sec
	
	Memory Limit : 512MB
	
Sample 
	Input :
			1 239	  ||  2816213588 30524
	Output :
			1		  ||  10249
			
Source : Algorithmic ToolBox by University of California San Diego &
         National Research University Higher School of Economics   (Coursera)
         
         Programming Assinment (Week 2)
		 
Detailed Explatnaion : https://medium.com/competitive/huge-fibonacci-number-modulo-m-6b4926a5c836
		 
*/




#include <iostream>

using std::cin;
using std::cout;



long long get_pisano_period_length(long long m) {
    long long F1 = 0, F2 = 1, F = F1 + F2;
    for (int i = 0; i < m * m; i++) {
        F = (F1 + F2) % m;
        F1 = F2;
        F2 = F;
        if (F1 == 0 && F2 == 1) return i + 1;
    }
}

long long get_fibonacci_huge_fast(long long n, long long m) {
    long long remainder = n % get_pisano_period_length(m);

    long long F1 = 0, F2 = 1, F = remainder;
    for (int i = 1; i < remainder; i++) {
        F = (F1 + F2) % m;
        F1 = F2;
        F2 = F;
    }
    return F % m;
}

int main() {
    long long n, m;

    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_fast(n, m) << '\n';
}
