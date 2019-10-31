#include <iostream>
using namespace std;

int main()
{
    cout<<"Enter no. of input: ";
    int n;
    int count=0;
    srand(time(0));
    cin>>n;
    unsigned short int arr[n];
    
    for (int i=0; i<n; i++)
    {
        arr[i]=rand();
    }
    
    for (int i=0; i<n; i++)
    {
        cout<<arr[i]<<"\n";
    }
    
    cout<<"\n";
    //bubble sort
    for(int i=0;i<n-1;i++)
    {
        for (int j=i,k=j+1; k<n; j++,k++)
        {
            if (arr[j]>arr[k])
            {
                int temp= arr[j];
                arr[j] = arr[k];
                arr[k] = temp;
            }
            count++;
        }
    }
    
    for (int i=0; i<n; i++)
    {
        cout<<arr[i]<<"\n";
    }
    
    cout<<"No. of comparisons: "<<count<<"\n";
    
    return 0;
}
