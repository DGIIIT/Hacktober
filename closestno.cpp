// C++ program to find k closest elements 
#include <bits/stdc++.h> 
using namespace std; 

void printKclosest(int arr[], int n, int x, 
				int k) 
{ 
	// Make a max heap of difference with 
	// first k elements. 
	priority_queue<pair<int, int> > pq; 
	for (int i = 0; i < k; i++) 
		pq.push({ abs(arr[i] - x), i }); 

	// Now process remaining elements. 
	for (int i = k; i < n; i++) { 

		int diff = abs(arr[i] - x); 

		// If difference with current 
		// element is more than root, 
		// then ignore it. 
		if (diff > pq.top().first) 
			continue; 

		// Else remove root and insert 
		pq.pop(); 
		pq.push({ diff, i }); 
	} 

	// Print contents of heap. 
	while (pq.empty() == false) { 
		cout << arr[pq.top().second] << " "; 
		pq.pop(); 
	} 
} 

// Driver program to test above functions 
int main() 
{ 
	int arr[] = { -10, -50, 20, 17, 80 }; 
	int x = 20, k = 2; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	printKclosest(arr, n, x, k); 
	return 0; 
} 
