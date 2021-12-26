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
    //adj[v].pb(u);
    //deb2(u,v);
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

void addWeightEdgeClass(vector <Edge> &adj,  LL u, LL v, LL wt)
{
    Edge e;
    e.src = u;
    e.dest = v;
    e.weight = wt;
    adj.pb(e);
}


// A utility function to do DFS of graph
// recursively from a given vertex u.
void DFSUtil(int u, vi adj[], vi &visited, int c)
{
    visited[u] = c;

    //cout << u << " ";

    for (int i=0; i< SIZE(adj[u]); i++)
    {
        if (!visited[adj[u][i]])
        {
            DFSUtil(adj[u][i], adj, visited, c);
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
    vi comp_num(V, 0);
    int c=0;
    
    // Now process all vertices in order defined by Stack
    while (Stack.empty() == false)
    {
        // Pop a vertex from stack
        int v = Stack.top();
        Stack.pop();
  
        // Print Strongly connected component of the popped vertex
        if (!comp_num[v])
        {
            c++;
            DFSUtil(v, revAdj, comp_num, c);
        }
    }

    cout << c <<endl;
    loop(i, 0, V)
    {
        cout << comp_num[i] << " ";
    }
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