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

// A utility function to print the adjacency list
// representation of graph
void printGraph(vi adj[], int V)
{
    for (int v = 0; v < V; ++v)
    {
        cout << "\n Adjacency list of vertex "
             << v << "\n head ";
        for (auto x : adj[v])
           cout << "-> " << x;
        printf("\n");
    }
}

// Print adjacency list representation ot graph with weights
void printWeightGraph(vector<pi> adj[], int V)
{
    int v, w;
    for (int u = 0; u < V; u++)
    {
        cout << "Node " << u << " makes an edge with \n";
        for (auto it = adj[u].begin(); it!=adj[u].end(); it++)
        {
            v = it->first;
            w = it->second;
            cout << "\tNode " << v << " with edge weight ="
                 << w << "\n";
        }
        cout << "\n";
    }
}

int NumberOfconnectedComponents(vi adj[], int V)
{
    int count = 0;
    
    // Mark all the vertices as not visited
    //bool* visited = new bool[V];
    
    vb visited(V, false);
    // To store the number of connected components
    
    //for (int v = 0; v < V; v++)visited[v] = false;
 
    for (int v = 0; v < V; v++) {
        if (visited[v] == false) {
            DFSUtil(v, adj, visited);
            count += 1;
        }
    }
 
    return count;
}

// A utility function to add an edge in an
// undirected graph.
void addEdge(vi adj[], int u, int v)
{
    adj[u].pb(v);
    adj[v].pb(u);
}

// To add an edge
void addWeightEdge(vector <pi> adj[], int u, int v, int wt)
{
    adj[u].pb(mp(v, wt));
    adj[v].pb(mp(u, wt));
}


// A utility function to do DFS of graph
// recursively from a given vertex u.
void DFSUtil(int u, vi adj[], vb &visited)
{
    visited[u] = true;
    //cout << u << " ";
    for (int i=0; i< SIZE(adj[u]); i++)
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

void DFSTemplate()
{
    int V = 5;
    vector<int> adj[V];
 
    // Vertex numbers should be from 0 to 4.
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    DFS(adj, V);
} 

void WeightGraphTemplate()
{
    int V = 5;
    vector<pi> adj[V];
    addWeightEdge(adj, 0, 1, 10);
    addWeightEdge(adj, 0, 4, 20);
    addWeightEdge(adj, 1, 2, 30);
    addWeightEdge(adj, 1, 3, 40);
    addWeightEdge(adj, 1, 4, 50);
    addWeightEdge(adj, 2, 3, 60);
    addWeightEdge(adj, 3, 4, 70);
    printWeightGraph(adj, V);
}

void solve()
{
    int n,m;
    cin >> n >>m;

    int map[n][m] = {};
    
    int V = 0;
    
    loop(i,0,n)
    {
        loop(j,0,m)
        {
            char c;
            cin >> c;
            if(c =='.')
            {
                map[i][j] = ++V;
            }
        }
    }

    vector<int> adj[V];
    loop(i,0,n)
    {
        loop(j,0,m)
        {
            int v = map[i][j];
            if(v)
            {
                if(i+1 < n && map[i+1][j]) addEdge(adj, v - 1, map[i+1][j] - 1);
                if(i-1 >= 0 && map[i-1][j]) addEdge(adj, v - 1, map[i-1][j] - 1);
                if(j+1 < m && map[i][j+1]) addEdge(adj, v - 1, map[i][j+1] - 1);
                if(j-1 >= 0 && map[i][j-1]) addEdge(adj, v - 1, map[i][j-1] - 1);
            }
            
        }
    }
    //printGraph(adj, V);
    cout << NumberOfconnectedComponents(adj, V);
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