#include <iostream>

using namespace std;

int binarySearch(int a[], int len, int target, int beg, int end)
{
    int mid,f;
    if(beg<=end)
    {
        mid = (beg+end)/2;
        f = 0;
        if(a[mid] == target)
            f = mid;
        else if(a[mid] < target)
            binarySearch(a,len,target,mid+1,end);
        else
            binarySearch(a,len,target,beg,mid-1);
    }
    else
        return f;

}

int main()
{
    int a[10], len = 10, beg, end, mid, n,val=0;
    beg=0;
    end = len-1;
    int found = 0;
    cout<<"Enter Sorted Numbers : "<<endl;
    for(int i=0;i<10;i++)
    {
        a[i] = ++val;
    }
    for(int i=0;i<10;i++)
    {
        cout<<a[i]<<endl;
    }
    cout<<"Enter number to find : "<<endl;
    cin>>n;

    found = binarySearch(a,len,n,beg,end);

    if(found == 0)
        cout<<"Not Found"<<endl;
    else
        cout<<"Found at :"<<found<<endl;
}


