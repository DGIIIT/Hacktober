#include<iostream>
using namespace std;
int binary_search(int v,int n);
int a[100];
int main(){
	int n,v;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cin>>v;
	int ans= binary_search(v,n);
	cout<<ans;
}
int binary_search(int v,int n){
	int lo=0;
	int hi=n-1;
	while(hi-lo>1){
	
	int mid=(lo+hi)/2;
	if(a[mid]==v){
		return mid;
	}
	if(a[mid]>v){
		hi=mid;
	}
	else if(a[mid]<v){
		lo=mid+1;
	}
	if(a[lo]==v){
		return lo;
	}
	if(a[hi]==v){
		return hi;
	}
	return n;	
	}
}
