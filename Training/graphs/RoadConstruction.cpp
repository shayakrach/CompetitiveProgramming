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

void addWeightEdgeClass(vector <Edge> &adj,  LL u, LL v, LL wt)
{
    Edge e;
    e.src = u;
    e.dest = v;
    e.weight = wt;
    adj.pb(e);
}

// A utility function to find set of an element i
// (uses path compression technique)
LL find(vector <subset> &subsets, LL i)
{
    // find root and make root as parent of i
    // (path compression)
    if (subsets[i].parent != i)
    {   
        subsets[i].parent = find(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}
 
// A function that does union of two sets of x and y
// (uses union by rank)
LL Union(vector <subset> &subsets, LL x, LL y)
{
    LL xroot = find(subsets, x);
    LL yroot = find(subsets, y);

    LL nodes = subsets[yroot].nodes + subsets[xroot].nodes;
    // Attach smaller rank tree under root of high
    // rank tree (Union by Rank)
    if (subsets[xroot].rank <= subsets[yroot].rank)
    {
        subsets[xroot].parent = yroot;
        subsets[yroot].nodes += subsets[xroot].nodes;
        
        if(subsets[xroot].rank == subsets[yroot].rank)
        {
            subsets[xroot].rank++;
        }
    }
    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].nodes += subsets[yroot].nodes;
    }

    return nodes;
}
 
// Compare two edges according to their weights.
// Used in qsort() for sorting an array of edges
LL myComp(Edge a, Edge b)
{
    return a.weight < b.weight;
}
 
// The main function to construct MST using Kruskal's
// algorithm
void KruskalMST(vector<Edge> edges, int V, int E)
{
    vector<Edge> result(V-1); // Tnis will store the resultant MST
    
    //LL e = 0; // An index variable, used for result[]
    LL e = 0; // An index variable, used for sorted edges
 
    // Step 1: Sort all the edges in non-decreasing
    // order of their weight. If we are not allowed to
    // change the given graph, we can create a copy of
    // array of edges
    
    //sort(all(edges), myComp);
    // Allocate memory for creating V ssubsets
    vector <subset> subsets(V);
    
    // Create V subsets with single elements
    for (int v = 0; v < V; ++v)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
        subsets[v].nodes = 1;
    }
    
    LL max_nodes = 1;
    LL num_of_subsets = V;

    // Number of edges to be taken is equal to V-1
    while (e < E)
    {
        // Step 2: Pick the smallest edge. And increment
        // the index for next iteration
        Edge next_edge = edges[e++];
 
        LL x = find(subsets, next_edge.src);
        LL y = find(subsets, next_edge.dest);
 
        // If including this edge does't cause cycle,
        // include it in result and increment the index
        // of result for next edge
        if (x != y) {
            //result[e++] = next_edge;
            MAX(max_nodes, Union(subsets, x, y));
            num_of_subsets -= 1;
        }

        cout << num_of_subsets << " " << max_nodes << endl;
        // Else discard the next_edge
    }
}

void solve()
{
    int n,m;
    cin >> n >> m;
    
    //vl adj[n];
    vector<Edge> edges;
    
    loop(i, 0, m)
    {
        LL u,v;
        cin >> u >> v;
        //cin >> u >> v;
        u -= 1;
        v -= 1;

        //addEdge(adj, u, v);
        addWeightEdgeClass(edges, u, v, 0);
    }

    KruskalMST(edges, n, m);
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