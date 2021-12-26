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
}

void addWeightEdge(vector <pl> adj[], LL u, LL v, LL wt)
{
    adj[u].pb(mp(v, wt));
}

// Prints shortest paths from src to all other vertices with weights

void dijkstraShortestPath(vector<pl> adj[], LL src, LL V, int k)
{
    priority_queue<pl, vector <pl> , greater<pl>> pq;
  
    // Create a vector for distances and initialize all
    // distances as infinite (INF)
    vector<vl> dist(V, vl(k, LLONG_MAX));
    vb vis(V, false);
  
    // Insert source itself in priority queue and initialize
    // its distance as 0.
    pq.push(mp(0, src));
    dist[src][0] = 0;
  
    //Looping till priority queue becomes empty (or all distances are not finalized)
    while (!pq.empty())
    {
        LL u_d = pq.top().fi;
        LL u = pq.top().se;
        pq.pop();

        deb2(u, u_d);
        ps;

        if(vis[u] || dist[u][k-1] < u_d) continue;
        
        vis[u] = true;
        
        foreach(vd, adj[u])
		{
			LL v = vd.fi;
            LL u_v_d = vd.se;
 
			if(dist[v][k-1] > u_v_d + u_d) 
			{
				dist[v][k-1] = u_v_d + u_d;
				pq.push({dist[v][k-1], v});
				sort(dist[v].begin(), dist[v].end());
			}
		}

        /*
        foreach(vd, adj[u])
        {
            // Get vertex label and weight of current adjacent
            // of u.
            LL v = vd.fi;
            LL u_v_d = vd.se;

            deb2(v, u_v_d);

            if(v == src) continue; ///if it the 1st node, then don't need to visit it

            deb2(dist[v][k-1], u_d + u_v_d);

            //  If there is shorted path to v through u.
            if (dist[v][k-1] > u_d + u_v_d)
            {
                // Updating distance of v
                dist[v][k-1] = u_d + u_v_d;
                cout << " YAAA" <<endl;
                pq.push(mp(dist[v][k-1], v));
                
                if(k > 1)
                {
                    SORT(dist[v]);
                    deb(v);
                    foreach(dd, dist[v]){
                        cout <<dd << " "; 
                    }
                    ps;
                }
            }
        }
        ps;ps;
        */
    }

    loop(i, 0, k) 
    {
        cout << dist[V-1][i] << " ";
    }
}

void solve()
{
    int n,m,k;
    cin >> n >> m >> k;
    
    vector <pl> adj[n];

    loop(i, 0, m)
    {
        LL u,v,w;
        cin >> u >> v >>w;
        u -= 1;
        v -= 1;

        //addEdge(adj, u, v);
        addWeightEdge(adj, u, v, w);
    }

    dijkstraShortestPath(adj, 0, m, k);
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