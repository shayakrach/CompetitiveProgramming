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
    if(v==0) adj[v].pb(u);
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
void DFS(vi adj[], int V)
{
    vector<bool> visited(V, false);
    for (int u=0; u<V; u++)
        if (visited[u] == false)
            DFSUtil(u, adj, visited);
}

void BFS(vi adj[], int src, int invalid_node, int V, int pred[], int dist[])
{
    //if(SIZE(adj[src]) == 0 || SIZE(adj[dest]) == 0) return;

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
            if (visited[adj[u][i]] == false && adj[u][i] != invalid_node) {
                visited[adj[u][i]] = true;
                dist[adj[u][i]] = dist[u] + 1;
                pred[adj[u][i]] = u;
                queue.pb(adj[u][i]);
 
                // We stop BFS when we find destination.
                //if (adj[u][i] == dest) return true;
            }
        }
    }
 
    //return false;
}
 
// utility function to print the shortest distance
// between source vertex and destination vertex
void printShortestDistance(vi adj[], vector<pair<int,char>> dir[], int s, vi dest, int V)
{
    // predecessor[i] array stores predecessor of
    // i and distance array stores distance of i
    // from s
    int pred[V], dist[V];
    int pred_M[V], dist_M[V];
    int monster_node = 0;

    BFS(adj, s, monster_node, V, pred, dist);
    BFS(adj, monster_node, -1, V, pred_M, dist_M);

    int crawl = -1;
    foreach(des, dest)
    {
        if(dist[des] < dist_M[des]) 
        {
            crawl = des;
            break;
        }
    }
    
    if(crawl == -1) 
    {
        cout << "NO" << endl;
        return;
    }

    // vector path stores the shortest path
    vi path;
    
    path.push_back(crawl);
    while (pred[crawl] != -1) {
        path.push_back(pred[crawl]);
        crawl = pred[crawl];
    }
 
    // distance from source is in distance array
    cout << "YES" << endl;
    cout << dist[path[0]] << endl;
 
    // printing path from source to destination
    //cout << "\nPath is::\n";
    for (int i = SIZE(path) - 1; i > 0; i--)
    {
        foreach(p, dir[path[i]])
        {
            if(p.fi == path[i-1])
            {
                cout << p.se;
            }
        }
    }   
}



void solve()
{
    int n,m;
    cin >> n >>m;

    vvi map(n, vi(m,-1));;
    
    int V = 1;
    int A;
    vi dest;
    loop(i,0,n)
    {
        loop(j,0,m)
        {
            char c;
            cin >> c;
            if(c !='#')
            {
                if(c == 'M') map[i][j] = 0;
                else
                {
                    map[i][j] = V++;
                    if(c == 'A') A = map[i][j];
                    if(i == 0 || i == n-1 || j == 0 || j == m-1) dest.pb(map[i][j]);
                }
            }
        }
    }
    
    //deb2(A,B);

    vi adj[V];

    vector<pair<int,char>> dir[V];

    loop(i,0,n)
    {
        loop(j,0,m)
        {
            int v = map[i][j];
            if(v!=-1)
            {
                if(i+1 < n && map[i+1][j]!=-1)
                {
                    addEdge(adj, v, map[i+1][j]);
                    dir[v].pb(mp(map[i+1][j],'D'));
                    dir[map[i+1][j]].pb(mp(v, 'U'));
                } 
                if(i-1 >= 0 && map[i-1][j]!=-1) 
                {
                    addEdge(adj, v, map[i-1][j]); 
                }
                if(j+1 < m && map[i][j+1]!=-1) 
                {
                    addEdge(adj, v, map[i][j+1]);
                    dir[v].pb(mp(map[i][j+1],'R'));
                    dir[map[i][j+1]].pb(mp(v, 'L'));
                }
                if(j-1 >= 0 && map[i][j-1]!=-1)
                {
                    addEdge(adj, v, map[i][j-1]);
                }
            } 
        }
    }
    //printGraph(adj, V);
    printShortestDistance(adj, dir, A, dest, V);
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