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

/*
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
*/

/*
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
*/

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

void addWeightEdge(vector <pl> adj[], LL u, LL v, LL wt)
{
    adj[u].pb(mp(v, wt));
}



void BellmanFord(LL edges_graph[][3], int V, int E, LL src)
{
    // Initialize distance of all vertices as infinite.
    vl dist(V, LLONG_MAX);
    vl parent(V, -1);

    // initialize distance of source as 0
    dist[src] = 0;
 
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
            
            if (dist[u] != LLONG_MAX && dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                parent[v] = u;
            }
        }
    }
 
    // check for negative-weight cycles.
    // The above step guarantees shortest
    // distances if graph doesn't contain
    // negative weight cycle.  If we get a
    // shorter path, then there is a cycle.

    LL first = -1;
    
    for (int i = 0; i < E; i++)
    {
        int u = edges_graph[i][0];
        int v = edges_graph[i][1];
        int w = edges_graph[i][2];
        
        //deb3(u,v,w);
        //deb2(dist[u], dist[v]);
        if (dist[u] != LLONG_MAX && dist[u] + w < dist[v])
        {
            //cout << "Graph contains negative weight cycle" << endl;
            first = v;
            parent[v] = u;
            break;
        }
    }
 
    if (first != -1) {
        vb vis(V, false);

        while(!vis[first])
        {
            vis[first] = true;
            first = parent[first];
        }
        
        vl cycle;
        cycle.push_back(first);
        LL last =  parent[first];

        while(last != first)
        {
            cycle.push_back(last);
            last = parent[last];
        }
        cycle.push_back(first);
        
        reverse(cycle.begin(), cycle.end());
 
        cout << "YES" << endl;
        for (int v : cycle) cout << v << ' ';
    }
    else
    {
        cout << "NO" << endl;
    }
}


void solve()
{
    int n,m;
    cin >> n >>m;
    
    //vector<int> adj[n];

    LL edges[m + n][3];

    loop(i, 0, n)
    {
        edges[i][0] = 0;
        edges[i][1] = i;
        edges[i][2] = 0;
    }

    loop(i, n, m + n)
    {
        LL u,v,w;
        cin >> u >> v>> w;

        edges[i][0] = u;
        edges[i][1] = v;
        edges[i][2] = w;
    }

    BellmanFord(edges, n + 1, m + n, 0);
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