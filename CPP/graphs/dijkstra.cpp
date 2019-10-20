#include <bits/stdc++.h>

typedef long long ll;

#define pb push_back
#define MS(x,y) memset((x),(y),sizeof((x)))
#define mn 1000000

using namespace std;

vector<pair<int,int>> pat[1001];

vector<int> dijkstra(int s) {
    vector<int> dist(1001, INT_MAX);
    dist[s] = 0;

    priority_queue<pair<int,int>> pq;
    pq.push({0, s});

    bool vis[1001];
    MS(vis, 0);

    while (!pq.empty()) {
        int i = pq.top().second;

        pq.pop();

        if (vis[i]) continue;

        vis[i] = true;

        for (auto it:pat[i]) {
            int next = it.first, distBtwn = it.second;

            if (dist[next] > dist[i]+distBtwn) {
                dist[next] = dist[i]+distBtwn;

                pq.push({-dist[next], next});
            }
        }
    }

    return dist;
}

int main()
{
    int n,m;

    cin>>n>>m;

    for (int i = 0; i<m; i++) {
        int a,b,c;

        cin>>a>>b>>c;

        pat[a].pb({b,c});
    }

    int s;

    cin>>s;

    vector<int> dist = dijkstra(s);

    for (int i = 0; i<n; i++) cout<<"dist["<<s<<"]["<<i<<"] = "<<dist[i]<<endl;

    return 0;

    /*
    3
    3
    0 1 5
    0 2 45
    1 2 17
    0

    dist[0][0] = 0
    dist[0][1] = 5
    dist[0][2] = 22

    */
}
