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
#define INF INT_MAX      
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << ", " << #y << "=" << y << endl
#define deb3(x, y, z) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl

void DFSUtil(int u, vi adj[], vb &visited);
bool cycleFound = false;
bool finishPush = false;
vi cycleVertices;


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
}

void addWeightEdge(vector <pl> adj[], LL u, LL v, LL wt)
{
    adj[u].pb(mp(v, wt));
}


void WeightTopologicalSortUtil(vector<pi> adj[], int u, vb &visited, stack<int>& Stack)
{
    // Mark the current node as visited.
    visited[u] = true;
  
    // Recur for all the vertices adjacent to this vertex

    for (int i=0; i < SIZE(adj[u]); i++)
    {
        int v = adj[u][i].fi;
        if (!visited[v]) WeightTopologicalSortUtil(adj, v, visited, Stack);
    }
    // Push current vertex to stack which stores result
    Stack.push(u);
}

void DAGShortestPath(vector<pi> adj[], vi &dist, vi &parent, int src, int V)
{
    stack<int> Stack;
  
    // Mark all the vertices as not visited
    vb visited(V, false);
    // Call the recursive helper function to store Topological
    // Sort starting from all vertices one by one
    for (int i = 0; i < V; i++)
    {
        if (!visited[i]) WeightTopologicalSortUtil(adj, i, visited, Stack);
    }

    dist[src] = 0;
    
    while (Stack.empty() == false)
    {
        // Get the next vertex from topological order
        int u = Stack.top();
        Stack.pop();
 
        // Update distances of all adjacent vertices
        
        if (dist[u] != INF)
        {
            for (int i=0; i < SIZE(adj[u]); i++)
            {
                int v = adj[u][i].fi;
                int w = adj[u][i].se;

                //deb3(u, v, w);

                if (dist[v] > dist[u] + w)
                {
                    dist[v] = dist[u] + w;
                    parent[v] = u; 
                }
            }
        }
    }
}

void solve()
{
    int n,m;
    cin >> n >> m;
    
    //vl adj[n];
    vector<pi> graph[n];
    //vector<pi> revGraph[n];

    vi dist(n, INF);
    vi parent(n, -1);

    loop(i, 0, m)
    {
        int u,v,w;
        cin >> u >> v;
        //cin >> u >> v;
        u -= 1;
        v -= 1;

        //addEdge(adj, u, v);
        addWeightEdge(graph, u, v, -1);
    }

    DAGShortestPath(graph, dist, parent, 0, n);

    if(dist[n-1] == INF)
    {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    
    //int dis = dist[n-1];

    //cout << - dist[n-1] + 1 << end; 
    vi out;
    int u = n-1;

    while(u != -1)
    {
        out.pb(u);
        u = parent[u];
    }

    reverse(all(out));

    cout << SIZE(out) << endl;
    loop(i, 0, SIZE(out)) cout << out[i] + 1 << " ";
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