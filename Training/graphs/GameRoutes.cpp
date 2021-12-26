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



// A utility function to add an edge in an
// undirected graph.
void addEdge(vi adj[], int u, int v)
{
    adj[u].pb(v);
    //adj[v].pb(u);
}

// To add an edge
void addWeightEdge(vector <pi> adj[], int u, int v, int wt)
{
    adj[u].pb(mp(v, wt));
    //adj[v].pb(mp(u, wt));
}

void addWeightEdge(vector <pl> adj[], LL u, LL v, LL wt)
{
    adj[u].pb(mp(v, wt));
    //adj[v].pb(mp(u, wt));
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
    vi ways(V,0);
    ways[0] = 1;
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
    while (Stack.empty() == false)
    {
        int u = Stack.top();
        foreach(v, adj[u])
        {
            modsum(ways[v], ways[u]);
        }
        Stack.pop();
    }

    cout << ways[V-1] << endl;
}

// Prints shortest paths from src to all other vertices
void Graph::primMST()
{
    // Create a priority queue to store vertices that
    // are being preinMST. This is weird syntax in C++.
    // Refer below link for details of this syntax
    // http://geeksquiz.com/implement-min-heap-using-stl/
    priority_queue< iPair, vector <iPair> , greater<iPair> > pq;
 
    int src = 0; // Taking vertex 0 as source
 
    // Create a vector for keys and initialize all
    // keys as infinite (INF)
    vector<int> key(V, INF);
 
    // To store parent array which in turn store MST
    vector<int> parent(V, -1);
 
    // To keep track of vertices included in MST
    vector<bool> inMST(V, false);
 
    // Insert source itself in priority queue and initialize
    // its key as 0.
    pq.push(make_pair(0, src));
    key[src] = 0;
 
    /* Looping till priority queue becomes empty */
    while (!pq.empty())
    {
        // The first vertex in pair is the minimum key
        // vertex, extract it from priority queue.
        // vertex label is stored in second of pair (it
        // has to be done this way to keep the vertices
        // sorted key (key must be first item
        // in pair)
        int u = pq.top().second;
        pq.pop();
         
          //Different key values for same vertex may exist in the priority queue.
          //The one with the least key value is always processed first.
          //Therefore, ignore the rest.
          if(inMST[u] == true){
            continue;
        }
       
        inMST[u] = true;  // Include vertex in MST
 
        // 'i' is used to get all adjacent vertices of a vertex
        list< pair<int, int> >::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            // Get vertex label and weight of current adjacent
            // of u.
            int v = (*i).first;
            int weight = (*i).second;
 
            //  If v is not in MST and weight of (u,v) is smaller
            // than current key of v
            if (inMST[v] == false && key[v] > weight)
            {
                // Updating key of v
                key[v] = weight;
                pq.push(make_pair(key[v], v));
                parent[v] = u;
            }
        }
    }
 
    // Print edges of MST using parent array
    for (int i = 1; i < V; ++i)
        printf("%d - %d\n", parent[i], i);
}
 


void solve()
{
    int n,m;
    cin >> n >>m;
    
    //vl adj[n];
    vi adj[n];
    loop(i, 0, m)
    {
        int u,v;
        cin >> u >> v;
        //cin >> u >> v;
        u -= 1;
        v -= 1;

        addEdge(adj, u, v);
        //addWeightEdge(adj, u, v, w);
    }

    topologicalSort(adj, n);

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