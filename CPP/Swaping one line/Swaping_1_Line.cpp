#include<iostream>

using namespace std;

int main() {

    int x = 5, y = 7;
    cout<<"Before swapping: x = "<< x <<" and y = "<< y << endl;

    x = x ^ y ^ (y = x);
    cout<<"After swapping: x = "<< x <<" and y = "<< y << endl;

    return 0;
}

