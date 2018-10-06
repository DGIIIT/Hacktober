#include<iostream>
 
using namespace std;
 
// A function implementing Binary search on a sorted array.
int BinarySearch(int a[], int start, int end, int item, int iter)
{
	int i, mid;
	iter++;
	// Assigning middle of the array.
	mid = start + (end-start+1)/2;
	// If value is less than value at start index more than end index then item is not in the array. 
	if(item > a[end] || item < a[start] || mid == end)
	{
		cout<<"\nNot found";
		return -1;
	}
	// Return the mid index.
	else if(item == a[mid])
	{
		return mid;
	}
	// Return the start index.
	else if(item == a[start])
	{
		return start;
	}
	// Return the end index.
	else if(item == a[end])
	{
		return end;
	}
	// According to the item value choose the partion to proceed further.
  else if(item > a[mid])
		BinarySearch(a, mid, 19, item, iter);
	else
		BinarySearch(a, start, mid, item, iter);
}
 
int main()
{
	int n, i, flag=0, Bindex, a[20]={1, 9, 18, 24, 27, 35, 38, 41, 49, 53, 55, 66, 67, 72, 75, 77, 81, 89, 90, 97};
	cout<<"\nEnter the number of element in the search sequence: ";
	cin>>n;
	int s[n];
	for(i = 0; i < n; i++)
		cin>>s[i];
 
	// Get the index of the first value in the search sequence found in data set array.	
	Bindex = BinarySearch(a, 0, 19, s[0], 0);
 
	if(Bindex == -1)
	{
		// if return index is -1 then not found.
		cout<<"\nNot found.";
		return 0;
	}
	else
	{
		// If first value found then check for others sequentially.
		for(i = Bindex; i < n+Bindex; i++)
			if(a[i] != s[i-Bindex])
				flag = 5;
 
		if(flag == 5)
			cout<<"\nNot found.";
		else
          cout<<"\nSequence found between index "<<Bindex<<" and "<<Bindex+n<<".";
	}
 
	return 0;
}
