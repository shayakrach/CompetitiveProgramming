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

void DFSUtil(int u, vi adj[], vb &visited);

vi HeadsOfconnectedComponents(vi adj[], int V)
{
    vi heads;
    
    // Mark all the vertices as not visited
    //bool* visited = new bool[V];
    
    vb visited(V, false);
    // To store the number of connected components
    
    //for (int v = 0; v < V; v++)visited[v] = false;
 
    for (int v = 0; v < V; v++) {
        if (visited[v] == false)
         {
            DFSUtil(v, adj, visited);
            heads.pb(v);
        }
    }
 
    return heads;
}

// A utility function to add an edge in an
// undirected graph.
void addEdge(vi adj[], int u, int v)
{
    adj[u].pb(v);
    adj[v].pb(u);
}


// A utility function to do DFS of graph
// recursively from a given vertex u.
void DFSUtil(int u, vi adj[], vb &visited)
{
    visited[u] = true;
    //cout << u << " ";
    for (int i=0; i< adj[u].size(); i++)
        if (visited[adj[u][i]] == false)
            DFSUtil(adj[u][i], adj, visited);
}
 
// This function does DFSUtil() for all
// unvisited vertices.
void DFS(vector<int> adj[], int V)
{
    vector<bool> visited(V, false);
    for (int u=0; u<V; u++)
        if (visited[u] == false)
            DFSUtil(u, adj, visited);
}

bool BFS(vi adj[], int src, int dest, int V, int pred[], int dist[])
{
    if(SIZE(adj[src]) == 0 || SIZE(adj[dest]) == 0) return false;

    //deb2(SIZE(adj[src]), SIZE(adj[dest]));
    //ps;
    // a queue to maintain queue of vertices whose
    // adjacency list is to be scanned as per normal
    // DFS algorithm
    list<int> queue;
 
    // boolean array visited[] which stores the
    // information whether ith vertex is reached
    // at least once in the Breadth first search
    bool visited[V];
 
    // initially all vertices are unvisited
    // so v[i] for all i is false
    // and as no path is yet constructed
    // dist[i] for all i set to infinity
    for (int i = 0; i < V; i++) {
        visited[i] = false;
        dist[i] = INT_MAX;
        pred[i] = -1;
    }
 
    // now source is first to be visited and
    // distance from source to itself should be 0
    visited[src] = true;
    dist[src] = 0;
    queue.pb(src);
 
    // standard BFS algorithm
    while (!queue.empty()) {
        int u = queue.front();
        queue.pop_front();
        for (int i = 0; i < SIZE(adj[u]); i++) {
            if (visited[adj[u][i]] == false) {
                visited[adj[u][i]] = true;
                dist[adj[u][i]] = dist[u] + 1;
                pred[adj[u][i]] = u;
                queue.pb(adj[u][i]);
 
                // We stop BFS when we find destination.
                if (adj[u][i] == dest)
                    return true;
            }
        }
    }
 
    return false;
}
 
// utility function to print the shortest distance
// between source vertex and destination vertex
void printShortestDistance(vi adj[], int s, int dest, int V)
{
    // predecessor[i] array stores predecessor of
    // i and distance array stores distance of i
    // from s
    int pred[V], dist[V];
 
    if (BFS(adj, s, dest, V, pred, dist) == false) {
        cout << "NO" << endl;
        return;
    }
 
    // vector path stores the shortest path
    vi path;
    int crawl = dest;
    path.push_back(crawl);
    while (pred[crawl] != -1) {
        path.push_back(pred[crawl]);
        crawl = pred[crawl];
    }
 
    // distance from source is in distance array
    cout << "YES" << endl;
    cout << dist[dest] << endl;
 
    // printing path from source to destination
    cout << "\nPath is::\n";
    for (int i = SIZE(path) - 1; i >= 0; i--)
    {
        cout << path[i] << " ";
    }
        
}

void solve()
{
    int n,m;
    cin >> n >> m;

    vector<int> adj[n];
    
    loop(i, 0, m)
    {
        int v,u;
        cin >> v >> u;
        addEdge(adj, v -1, u-1);
    }

    vi heads = HeadsOfconnectedComponents(adj, n);

    int size = SIZE(heads) -1;
    cout<< size <<endl;

    loop(i, 0, size)
    {
        cout << heads[i] + 1<< " " << heads[i+1] +1<<endl;  
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}