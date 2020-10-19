//This sort algorithm is used to find dependency among files . Below is its simple to understand implementation using bfs
#include <bits/stdc++.h>

using namespace std;

int *topoSort(int N, vector<int> adj[]);

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
bool check(int V, int res[], vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return false;
        }
    }
    return true;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }

        int *res = topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }

// The Graph structure is as folows

/*  Function which sorts the graph vertices in topological form
*   N: number of vertices
*   adj[]: input graph
*   NOTE: You must return dynamically allocated array
*/
int* topoSort(int V, vector<int> adj[]) {
    int indegree[V]={0};
    int index=0;
    int *result=new int[V];
    for(int i=0;i<V;i++)
    {
        for(int x:adj[i])
        {
            indegree[x]++;
        }
    }
    queue<int>q;
    for(int i=0;i<V;i++)
    {
        if(indegree[i]==0)
            q.push(i);
    }
    while(!q.empty())
    {
        int t=q.front();
        q.pop();
        result[index++]=t;
        for(int x:adj[t])
        {
            indegree[x]--;
            if(indegree[x]==0)
            {
                q.push(x); 
                
            }
        }
    }
    return result;
   
}
