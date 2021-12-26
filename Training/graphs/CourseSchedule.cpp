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
bool cycleFound = false;
bool finishPush = false;
vi cycleVertices;

// A utility function to add an edge in an
// undirected graph.
void addEdge(vi adj[], int u, int v)
{
    adj[u].pb(v);
}

// A utility function to do DFS of graph
// recursively from a given vertex u.
void DFSUtil(int u, vi adj[], vb &visited,vb &recStack)
{
    visited[u] = true;
    recStack[u] = true;
    
    for (int i=0; i < SIZE(adj[u]); i++){
        
        //cout << " parent" << parent << " " <<  u + 1 << ": neighbor -> " << adj[u][i] +1 << endl;
        
        if (visited[adj[u][i]] == false)
        {
            DFSUtil(adj[u][i], adj, visited, recStack);
        }
        else if(recStack[adj[u][i]])
        {
            cycleFound = true;
            cycleVertices.pb(adj[u][i]);
            cycleVertices.pb(u);
            recStack[u] = false;
            return;
        }

        if(cycleFound)
        {
            return;
        }
    }

    recStack[u] = false;
    
    if(cycleFound)
    {
        return;
    }
}
 
// This function does DFSUtil() for all
// unvisited vertices.
void DFS(vi adj[], int V)
{
    vb visited(V, false);
    vb recStack(V, false);
    
    for (int u=0; u<V; u++)
    {
        if (visited[u] == false)
            DFSUtil(u, adj, visited, recStack);
        if(cycleFound) return;
    }
}

void topologicalSortUtil(vi adj[], int u, vb &visited, stack<int>& Stack)
{
    // Mark the current node as visited.
    visited[u] = true;
  
    // Recur for all the vertices adjacent to this vertex

    for (int i=0; i < SIZE(adj[u]); i++)
    {
        if (!visited[adj[u][i]]) topologicalSortUtil(adj, adj[u][i], visited, Stack);
    }
    // Push current vertex to stack which stores result
    Stack.push(u);
}

void topologicalSort(vi adj[], int V)
{
    stack<int> Stack;
  
    // Mark all the vertices as not visited
    vb visited(V, false);
  
    // Call the recursive helper function to store Topological
    // Sort starting from all vertices one by one
    for (int i = 0; i < V; i++)
    {
        if (!visited[i]) topologicalSortUtil(adj, i, visited, Stack);
    }
  
    // Print contents of stack
    while (Stack.empty() == false) {
        cout << Stack.top() + 1 << " ";
        Stack.pop();
    }
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
        addEdge(adj, v - 1, u - 1);
    }

    DFS(adj, n);

    //loop(i, 0, n) cout << cycleVertices[i] << " ";
    //ps;
    //ps;

    if(cycleFound)
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
    {
        topologicalSort(adj, n);
    }

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