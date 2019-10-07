/*
 Problem Description :
    array,a=[3,4,5] number of rotations,k=2 and indices to check,q=[1,2] .
    First we perform the two rotations:
      [3,4,5]-->[5,3,4]-->[4,5,3]
    Now return the values from the zero-based indices 1 and 2 as indicated in the  array.
      a[1]=5
      a[2]=3
      
  Constraints :
      1< n <10^5  | 1< a[i] <10^5  | 1< k <10^5  | 0<= q <n
  Source :
      https://www.hackerrank.com/challenges/circular-array-rotation/problem
 */
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int m,n,q,i,j,k;
    cin>>n>>m>>q;
    m=m%n;
    k=n-m;
    //input a array
    int arr[n],arr1[q];
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    //input position of array
    for(i=0;i<q;i++)
    {
        cin>>arr1[i];
    }
    int temp;
    //Rotation Forward and Backward
    if(m<=k){
    for(i=0;i<m;i++)
    {
        temp=arr[n-1];
        for(j=n-1;j>0;j--)
        {
            
            arr[j]=arr[j-1];

        }
        arr[0]=temp;
    }}
    else {
        for(i=0;i<k;i++)
    {
        temp=arr[0];
        for(j=0;j<n-1;j++)
        {
            
            arr[j]=arr[j+1];

        }
        arr[n-1]=temp;
    }
    }

    for(i=0;i<q;i++)
    {
        cout<<arr[arr1[i]]<<endl;
    }
}
