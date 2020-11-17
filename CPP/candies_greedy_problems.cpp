/*Alice is a kindergarten teacher. She wants to give some candies to the children in her class.  All the children sit in a line and each of them has a rating score according to his or her performance in the class.  Alice wants to give at least 1 candy to each child. If two children sit next to each other, then the one with the higher rating must get more candies. Alice wants to minimize the total number of candies she must buy.
For example, assume her students' ratings are [4, 6, 4, 5, 6, 2]. She gives the students candy in the following minimal amounts: [1, 2, 1, 2, 3, 1]. She must buy a minimum of 10 candies.*?


#include <bits/stdc++.h>

using namespace std;

long candies(int n, vector<int> arr) {
    long *help1 = new long[n];
    for(int i=0;i<n;i++){
        help1[i]=1;
    }
    long *help2 = new long[n];
    for(int i=0;i<n;i++){
        help2[i]=1;
    }  
 long long sum=0;
 for(int i=n-2;i>=0;i--){
     if(arr[i]>arr[i+1]){
         help1[i]+=help1[i+1];
     continue;
     }
 }
 for(int i=1;i<n;i++){
     if(arr[i]>arr[i-1]){
         help2[i]+=help2[i-1];
     continue;
     }
 }
 for(int i=0; i<n ;i++){
     sum+=max(help1[i], help2[i]);
 }
 delete []help1;
 delete []help2;
 return sum;
}

int main()
{
int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item;
        cin >> arr_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        arr[i] = arr_item;
    }

    long result = candies(n, arr);

    cout << result << "\n";
    
    return 0;
}


