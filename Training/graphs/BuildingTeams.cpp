#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <cstdio>
#include <list>

using namespace std;

typedef long long LL;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<LL> vl;
typedef vector<vl> vvl;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pi;

#define SIZE(v) (int)v.size()
#define SORT(v) sort(all(v))
#define loop(i,s,e) for(int i=s;i<e;++i)
#define rloop(i,s,e) for(int i=s;i>=e;--i)
#define pb push_back
#define mp make_pair
#define pf push_front
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define foreach(a, b) for (auto&(a) : (b))
#define MAX(a, b) a = max(a, b)
#define MIN(a, b) a = min(a, b)
#define MODULO 1000000007
#define modsum(a,b) a = (a + b) % MODULO
#define ps cout << endl      
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << ", " << #y << "=" << y << endl

bool DFSUtil(int u, vi adj[], vi &visited, int x);



// A utility function to add an edge in an
// undirected graph.
void addEdge(vi adj[], int u, int v)
{
    adj[u].pb(v);
    adj[v].pb(u);
}

// A utility function to do DFS of graph
// recursively from a given vertex u.
bool DFSUtil(int u, vi adj[], vi &visited, int group_id)
{
    bool ok = true;
    visited[u] = group_id;
    //cout << u << " ";
    for (int i=0; i< SIZE(adj[u]) && ok; i++)
        if (visited[adj[u][i]] == 0)
            ok = DFSUtil(adj[u][i], adj, visited, 3 - group_id);
        else if(visited[adj[u][i]] == group_id)
            ok = false;
    
    return ok;
}
 
// This function does DFSUtil() for all
// unvisited vertices.
bool DFS(vi adj[], int V, vi &visited)
{
    bool ok = true;
    
    for (int u=0; u<V && ok; u++)
        if (visited[u] == 0)
            ok = DFSUtil(u, adj, visited, 1);


    return ok;
}



void solve()
{
    int n,m;
    cin >> n >>m;
    vector<int> adj[n];
    
    loop(i, 0, m)
    {
        int v,u;
        cin >> v >> u;
        addEdge(adj, v -1, u-1);
    }
    vector<int> visited(n, 0);
    bool ok = DFS(adj, n, visited);

    if(ok)
    {
        loop(u, 0, n)
        {
            cout << visited[u] << " ";
        }
    }
    else cout << "IMPOSSIBLE" << endl;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    /*
    int q;
    cin >> q;

    vl v;
    read(v,q);

    loop(i, 0, q) v.pb(solve());
    
    loop(i, 0, q) cout << v[i] << endl;
    */
    

    return 0;
}