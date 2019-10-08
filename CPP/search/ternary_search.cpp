// C++ Program to perform Ternary search on an array.
// Complexity : O(log3(n))
#include <iostream> 
#include<algorithm>
using namespace std;
int ternarySearch(int l, int r, int key, int arr[]) 
{ 
	while (l <= r) 
	{ 

		// Find the mid1 and mid2 
		int mid1 = l + (r - l) / 3; 
		int mid2 = r - (r - l) / 3; 

		// Check if key is present at any mid 
		if (arr[mid1] == key)
			return mid1; 
		if (arr[mid2] == key) 
			return mid2; 

		// Since key is not present at mid, 
		// check in which region it is present 
		// then repeat the Search operation 
		// in that region 

		if (key < arr[mid1])
		{ 
			// The key lies in between l and mid1 
			r = mid1 - 1; 
		}
		else if (key > arr[mid2])
		{ 

			// The key lies in between mid2 and r 
			l = mid2 + 1; 
		} 
		else
		{ 

			// The key lies in between mid1 and mid2 
			l = mid1 + 1; 
			r = mid2 - 1; 
		} 
	} 
	// Key not found 
	return -1; 
}  
int main() 
{ 
	int l, r, p, key; 

	// Get the array 
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int n = sizeof(arr)/sizeof(int); // n = 10
	sort(arr, arr + n); 	// Sort the array if not sorted 
	l = 0; // Starting Index
	r = 9; // Last Index 

	// Checking for 5
	// Key to be searched in the array 
	key = 5; 
	// Search the key using ternarySearch 
	p = ternarySearch(l, r, key, arr); 
	if(p == -1)
		cout << "Element Not Found in Array" << endl;
	else 
		cout << "Element found at index : " << p << endl;
} 
