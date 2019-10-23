#include <bits/stdc++.h>

typedef long long ll;

#define pb push_back
#define MS(x,y) memset((x),(y),sizeof((x)))
#define mn 1000000

using namespace std;

vector<int> pat[1001],pat2[1001], komponenti[1001];
bool vis[1001];
vector<pair<int,int>> red;
int t = 0;

void dfs(int i) {
    vis[i] = true;
    t++;

    for (auto it:pat[i]) {
        if (!vis[it]) dfs(it);
    }

    t++;
    red.pb({t,i});
}

void dfs2(int i, int ctr) {
    vis[i] = true;

    for (auto it:pat[i]) {
        if (!vis[it]) dfs2(it,ctr);
    }

    komponenti[ctr].pb(i);
}

int main()
{
    int n,m;

    cin>>n>>m;

    for (int i = 0; i<m; i++) {
        int a,b;

        cin>>a>>b;

        a--; b--;

        pat[a].pb(b);
    }

    MS(vis, 0);

    for (int i = 0; i<n; i++) if (!vis[i]) dfs(i);

    sort(red.rbegin(), red.rend());

    for (int i = 0; i<n; i++) {
        for (auto it2:pat[i]) {
            pat2[it2].pb(i);
        }
    }

    for (int i = 0; i<n; i++) pat[i] = pat2[i];

    MS(vis, 0);

    int ctr = 0;

    for (auto it:red) {
        int pos = it.second;

        if (!vis[pos]) {
            dfs2(pos,ctr);
            ctr++;
        }
    }

    cout<<ctr<<endl<<endl;

    for (int i = 0; i<ctr; i++) {
        for (auto it:komponenti[i]) cout<<it<<" ";

        cout<<endl;
    }

    /*
    7 10
    1 2
    2 1
    3 2
    3 7
    7 6
    6 3
    6 5
    2 5
    5 4
    1 4

    4

    6 5 2
    1 0
    4
    3
    */

    return 0;
}
