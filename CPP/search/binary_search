#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int> v, int low, int up, int x){
    if(up>=low){
    int mid = low + (up-low)/2;

    if(v[mid]==x){
        return mid;
    }

    if(v[mid]>x) return binarySearch(v,low,mid-1,x);

    return binarySearch(v,mid+1,up,x);
    }
    else return -1; //Element doesn't exist
}

int main()
{
    vector<int> v = {1,2,3,4,5,6,7,8,9,10};
    cout << binarySearch(v,0,v.size()-1,5);
}
