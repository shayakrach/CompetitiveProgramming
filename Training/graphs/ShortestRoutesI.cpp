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

bool cycleFound = false;
bool finishPush = false;
vi cycleVertices;

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

// A utility function to add an edge in an
// undirected graph.
void addEdge(vi adj[], int u, int v)
{
    adj[u].pb(v);
    adj[v].pb(u);
}

// To add an edge
void addWeightEdge(vector <pair<LL,LL>> adj[], LL u, LL v, LL wt)
{
    adj[u].pb(mp(v, wt));
    //adj[v].pb(mp(u, wt));
}

/*
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
    vector<pair<int, int> > adj[V];
    addWeightEdge(adj, 0, 1, 10);
    addWeightEdge(adj, 0, 4, 20);
    addWeightEdge(adj, 1, 2, 30);
    addWeightEdge(adj, 1, 3, 40);
    addWeightEdge(adj, 1, 4, 50);
    addWeightEdge(adj, 2, 3, 60);
    addWeightEdge(adj, 3, 4, 70);
    printWeightGraph(adj, V);
}
*/


// Prints shortest paths from src to all other vertices with weights
void dijkstraShortestPath(vector<pair<LL,LL>> adj[], LL src, LL V)
{
    priority_queue<pair<LL,LL>, vector <pair<LL,LL>> , greater<pair<LL,LL>>> pq;
  
    // Create a vector for distances and initialize all
    // distances as infinite (INF)
    vector<LL> dist(V, LLONG_MAX);
    vb vis(V, false);
  
    // Insert source itself in priority queue and initialize
    // its distance as 0.
    pq.push(mp(0, src));
    dist[src] = 0;
  
    /* Looping till priority queue becomes empty (or all
      distances are not finalized) */
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
  
    // Print shortest distances stored in dist[]
    //printf("Vertex  Distance from Source\n");
    for (int i = 0; i < V; ++i)
    {
        cout << dist[i] << " ";
    }
    //printf("%d \t\t %d\n", i, dist[i]);
}

void solve()
{
    int n,m;
    cin >> n >>m;
    
    vector<pair<LL,LL>> adj[n];

    loop(i, 0, m)
    {
        LL v,u,w;
        cin >> v >> u >> w;
        addWeightEdge(adj, v -1, u-1, w);
    }

    dijkstraShortestPath(adj, 0, n);
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