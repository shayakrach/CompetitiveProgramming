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
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << ", " << #y << "=" << y << endl
#define deb3(x, y, z) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl

void DFSUtil(int u, vi adj[], vb &visited);
bool cycleFound = false;
bool finishPush = false;
vi cycleVertices;

void addEdge(vl adj[], LL u, LL v)
{
    adj[u].pb(v);
}

vb reachableNodes(vl adj[] , LL src, int V)
{
    // Mark all the vertices as not visited
    // Create a queue for BFS
    queue<LL> queue;
 
    queue.push(src);
    
    vb visited(V,false);
   
    visited[src] = true;
 
    // Vector to store all the reachable nodes from 'src'
    vb reachable_nodes(V, false);
 
    while(!queue.empty())
    {
        // Dequeue a vertex from queue
        int u = queue.front();
        queue.pop();
 
        reachable_nodes[u] = true;
 
        // Get all adjacent vertices of the dequeued
        // vertex u. If a adjacent has not been visited,
        // then mark it visited nd enqueue it
        
        for (int i = 0; i < SIZE(adj[u]); i++)
        {
            if (!visited[adj[u][i]])
            {
                // Assign Component Number to all the
                // reachable nodes
                visited[adj[u][i]] = true;
                queue.push(adj[u][i]);
            }
        }
    }
    return reachable_nodes;
}

void BellmanFord(LL edges_graph[][3],vb reachable_nodes, int V, int E, LL src)
{
    // Initialize distance of all vertices as infinite.
    LL dis[V];

    for (int i = 0; i < V; i++)
    {
        dis[i] = LLONG_MAX;
    }
    // initialize distance of source as 0
    dis[src] = 0;
    
    // Relax all edges |V| - 1 times. A simple
    // shortest path from src to any other
    // vertex can have at-most |V| - 1 edges
    for (int i = 0; i < V - 1; i++)
     {
        for (int j = 0; j < E; j++)
        {
            LL u = edges_graph[j][0];
            LL v = edges_graph[j][1];
            LL w = edges_graph[j][2];
            
            if (dis[u] != LLONG_MAX && dis[u] + w < dis[v])
            {
                dis[v] = dis[u] + w;
            }
        }
    }
 
    // check for negative-weight cycles.
    // The above step guarantees shortest
    // distances if graph doesn't contain
    // negative weight cycle.  If we get a
    // shorter path, then there is a cycle.
    
    for (int i = 0; i < E; i++)
    {
        int u = edges_graph[i][0];
        int v = edges_graph[i][1];
        int w = edges_graph[i][2];

        if (dis[u] != LLONG_MAX && dis[u] + w < dis[v] && reachable_nodes[v])
        {
            //cout << "Graph contains negative weight cycle at vertex " << v << endl;
            cout << - 1 << endl;
            return;
        }
    }

    cout << - dis[V-1] << endl;
}



void solve()
{
    int n,m;
    cin >> n >>m;
    
    //vector<int> adj[n];

    LL edges[m][3];

    vl revUnweightedGraph[n];

    loop(i, 0, m)
    {
        LL u,v,w;
        cin >> u >> v>>w;
        u-= 1;
        v-= 1;

        addEdge(revUnweightedGraph, v, u);
        edges[i][0] = u;
        edges[i][1] = v;
        edges[i][2] = -w;
    }
    
    vb reachable_nodes = reachableNodes(revUnweightedGraph, n-1, n);

    BellmanFord(edges, reachable_nodes, n, m, 0);
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