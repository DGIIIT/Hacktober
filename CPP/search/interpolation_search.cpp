#include <iostream>
#include <vector>

using namespace std;

int interpolationSearch(vector<int> v, int low, int up, int x){
    if(low>up) return -1;

    int mid = low + ((x-v[low])*(up-low) / (v[up]-v[low]));  //Interpolation

    if(v[mid]==x)
        return mid;

    if(v[mid]>x)
        return interpolationSearch(v,mid+1,up,x);

    return interpolationSearch(v,low,mid-1,x);
}

int main()
{
    vector<int> v = {1,2,3,4,5,6,7,8,9,10};
    cout << interpolationSearch(v,0,v.size()-1,5);
}
