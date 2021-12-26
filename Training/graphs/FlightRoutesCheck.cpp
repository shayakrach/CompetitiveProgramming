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
typedef pair<LL, LL> pl;


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
#define INF LLONG_MAX
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << ", " << #y << "=" << y << endl
#define deb3(x, y, z) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl

void DFSUtil(int u, vi adj[], vb &visited);
bool cycleFound = false;
bool finishPush = false;
vi cycleVertices;

class Edge {
public:
    LL src, dest, weight;
};

class subset {
public:
    LL parent;
    LL rank;
    LL nodes;
};

// A utility function to add an edge in an
// undirected graph.
void addEdge(vi adj[], int u, int v)
{
    adj[u].pb(v);
    //adj[v].pb(u);
    //deb2(u,v);
}


// A utility function to do DFS of graph
// recursively from a given vertex u.
void DFSUtil(int u, vi adj[], vb &visited)
{
    visited[u] = true;
    //cout << u << " ";

    for (int i=0; i< SIZE(adj[u]); i++)
    {
        if (visited[adj[u][i]] == false)
        {
            DFSUtil(adj[u][i], adj, visited);
        }
    }
}

void fillOrder(int u, vi adj[], vb &visited, stack<int> &Stack)
{
    // Mark the current node as visited and print it
    visited[u] = true;
  
    // Recur for all the vertices adjacent to this vertex
    for (int i=0; i< SIZE(adj[u]); i++)
    {
        if (visited[adj[u][i]] == false)
        {
            fillOrder(adj[u][i], adj, visited, Stack);
        }
    }
           
    // All vertices reachable from u are processed by now, push u 
    Stack.push(u);
}


void printSCCs(vi adj[], vi revAdj[], int V)
{
    stack<int> Stack;
  
    // Mark all the vertices as not visited (For first DFS)
    vb visited(V, false);
  
    // Fill vertices in stack according to their finishing times
    for(int i = 0; i < V; i++)
    {
        if(visited[i] == false)
        {
            fillOrder(i, adj, visited, Stack);
        }
    }
  
    // Mark all the vertices as not visited (For second DFS)
    for(int i = 0; i < V; i++)
        visited[i] = false;
    
    int src = Stack.top();
    DFSUtil(src, revAdj, visited);
    
    loop(i, 0, V) 
    {
        if(visited[i] == false)
        {
            cout << "NO" << endl;
            cout << i + 1 << " " << src + 1<< endl;
            return;
        }
    }

    cout << "YES" << endl;
}


void solve()
{
    int n,m;
    cin >> n >> m;
    
    vi adj[n];
    vi revAdj[n];
    
    loop(i, 0, m)
    {
        int u,v;
        cin >> u >> v;
        //cin >> u >> v;
        u -= 1;
        v -= 1;

        addEdge(adj, u, v);
        addEdge(revAdj, v, u);
    }

    printSCCs(adj, revAdj, n);
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