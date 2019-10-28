#include <bits/stdc++.h>

typedef long long ll;

#define pb push_back
#define MS(x,y) memset((x),(y),sizeof((x)))
#define mn 1000000

using namespace std;

int tree[1000001];

void update (int pos, int value, int interval_index, int interval_left, int interval_right) {
    if (interval_left > pos || interval_right < pos || interval_left > interval_right) return;

    if (interval_left == interval_right) {
        if (interval_left == pos) tree[interval_index] = value;

        return;
    }

    int mid = (interval_left + interval_right) / 2;
    update(pos, value, 2*interval_index, interval_left, mid);
    update(pos, value, 2*interval_index+1, mid+1, interval_right);

    tree[interval_index] = tree[2*interval_index] + tree[2*interval_index+1];
}

int query (int from, int to, int interval_index, int interval_left, int interval_right) {
    if (interval_left > to || interval_right < from || interval_left > interval_right) return 0;

    if (from <= interval_left && interval_right <= to) return tree[interval_index];

    int mid = (interval_left + interval_right) / 2;

    return query(from, to, 2*interval_index, interval_left, mid) + query(from, to, 2*interval_index+1, mid+1, interval_right);
}

int main()
{
    MS(tree, 0);

    int n;

    cin>>n;

    int niza[n];

    for (int i = 0; i<n; i++) {
        cin>>niza[i];

        update(i, niza[i], 1, 0, n-1);
    }

    int m;

    cin>>m;

    for (int i = 0; i<m; i++) {
        int a,b,c;

        cin>>a>>b>>c;

        if (a == 0) {
            //change, c na pos b

            update(b, c, 1, 0, n-1);
        } else {
            //query b to c

            cout<<query(b, c, 1, 0, n-1)<<endl;
        }
    }

    return 0;
}
