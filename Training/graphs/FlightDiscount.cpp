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
void addWeightEdge(vector <pl> adj[], LL u, LL v, LL wt)
{
    adj[u].pb(mp(v, wt));
}

/*
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
 
void DFSCycleUtil(int u, vi adj[], vb &visited, int parent)
{
    visited[u] = true;
    
    for (int i=0; i< SIZE(adj[u]); i++){
        
        //cout << " parent" << parent << " " <<  u + 1 << ": neighbor -> " << adj[u][i] +1 << endl;
        
        if (visited[adj[u][i]] == false)
        {
            DFSUtil(adj[u][i], adj, visited, u);
        }
        else if(adj[u][i] != parent)
        {
            cycleFound = true;
            cycleVertices.pb(adj[u][i]);
            cycleVertices.pb(u);
            return;
        }

        if(cycleFound)
        {
            if(!finishPush) 
            {
                cycleVertices.pb(u);
                finishPush = u == cycleVertices[0];
                //cout << "PUSHED -> " << u + 1 <<  endl;
                //if(finishPush) cout << "FINISHED -> " << u + 1 <<  endl;
            }
            return;
        }
    }
}

// This function does DFSUtil() for all
// unvisited vertices.
void DFS(vector<int> adj[], int V)
{
    vector<bool> visited(V, false);
    for (int u=0; u<V; u++)
    {
        if (visited[u] == false)
        {
            DFSUtil(u, adj, visited);
            //DFSCycleUtil(u, adj, visited, -1);
        }

        //if(cycleFound) return;
    }
}
*/

/*
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
*/

/*
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
*/

// Prints shortest paths from src to all other vertices with weights

void dijkstraShortestPath(vector<pl> adj[], LL src, int V)
{
    priority_queue<pl, vector <pl> , greater<pl>> pq;
  
    // Create a vector for distances and initialize all
    // distances as infinite (INF)
    vector<LL> dist(V, LLONG_MAX);
    vb vis(V, false);
  
    // Insert source itself in priority queue and initialize
    // its distance as 0.
    pq.push(mp(0, src));
    dist[src] = 0;
  
    // Looping till priority queue becomes empty (or all distances are not finalized)
    while (!pq.empty())
    {
        //LL x = pq.top().fi;
        LL u = pq.top().se;
        pq.pop();

        if(vis[u]) continue;
        
        vis[u] = true;
        
        foreach(vw, adj[u])
        {
            // Get vertex label and weight of current adjacent
            // of u.
            LL v = vw.fi;

            if(v == 0) continue; ///if it the 1st node,then i don't need to visit it
            
            LL weight = vw.se;
  
            //  If there is shorted path to v through u.
            if (dist[v] > dist[u] + weight)
            {
                // Updating distance of v
                dist[v] = dist[u] + weight;
                pq.push(mp(dist[v], v));
            }
        }
    }

    cout << dist[V-1];
}


void solve()
{
    int n,m;
    cin >> n >>m;
    
    vector<pl> adj[2*n];

    loop(i, 0, m)
    {
        LL u,v,w;
        cin >> u >> v >> w;
        u-=1;
        v-=1;
        
        addWeightEdge(adj, u , v, w);
        addWeightEdge(adj, u , n + v, w/2);
        addWeightEdge(adj, n + u , n + v, w);
    }

    dijkstraShortestPath(adj, 0, 2*n);

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