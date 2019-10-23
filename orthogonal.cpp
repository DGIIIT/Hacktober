// C++ program to check if two 
// circles are orthogonal or not 

#include <bits/stdc++.h> 
using namespace std; 

// Function to Check if the given 
// circles are orthogonal 
bool orthogonality(int x1, int y1, int x2, 
				int y2, int r1, int r2) 
{ 

	// calculating the square 
	// of the distance between C1 and C2 
	int dsquare = (x1 - x2) * (x1 - x2) 
				+ (y1 - y2) * (y1 - y2); 

	// Check if the given 
	// circles are orthogonal 
	if (dsquare == r1 * r1 + r2 * r2) 
		return true; 
	else
		return false; 
} 

// Driver code 
int main() 
{ 
	int x1 = 4, y1 = 3; 
	int x2 = 0, y2 = 1; 
	int r1 = 2, r2 = 4; 

	bool f = orthogonality(x1, y1, x2, 
						y2, r1, r2); 

	if (f) 
		cout << "Given circles are"
			<< " orthogonal."; 
	else
		cout << "Given circles are"
			<< " not orthogonal."; 
	return 0; 
} 
