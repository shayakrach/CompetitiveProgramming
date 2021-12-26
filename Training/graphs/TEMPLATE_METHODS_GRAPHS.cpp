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
typedef vector<pl> vpl;
typedef vector<pi> vpi;


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
#define print(var)    cout << var << endl
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
void printWeightGraph(vector<pi> adj[], int V){
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

// A utility function to do DFS of graph
// recursively from a given vertex u.
void DFSDirectedCycleUtil(int u, vi adj[], vb &visited,vb &recStack)
{
    visited[u] = true;
    recStack[u] = true;
    
    for (int i=0; i < SIZE(adj[u]); i++){
        
        //cout << " parent" << parent << " " <<  u + 1 << ": neighbor -> " << adj[u][i] +1 << endl;
        
        if (visited[adj[u][i]] == false)
        {
            DFSUtil(adj[u][i], adj, visited, recStack);
        }
        else if(recStack[adj[u][i]])
        {
            cycleFound = true;
            cycleVertices.pb(adj[u][i]);
            cycleVertices.pb(u);
            recStack[u] = false;
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
            //recStack[u] = false;
            return;
        }
    }

    recStack[u] = false;
    
    if(cycleFound)
    {
        if(!finishPush) 
        {
            cycleVertices.pb(u);
            finishPush = u == cycleVertices[0];
        }
        return;
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
    vb recStack(V, false);

    for (int u=0; u<V; u++)
    {
        if (visited[u] == false)
        {
            DFSUtil(u, adj, visited);
            //DFSCycleUtil(u, adj, visited, -1);
            //DFSDirectedCycleUtil(u, adj, visited, recStack);
        }

        //if(cycleFound) return;
    }
}

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

// Prints shortest paths from src to all other vertices with weights
void dijkstraShortestPath(vector<pl> adj[], LL src, LL V)
{
    priority_queue<pl, vector <pl> , greater<pl>> pq;
  
    // Create a vector for distances and initialize all
    // distances as infinite (INF)
    vl dist(V, LLONG_MAX);
    vb vis(V, false);
    vl parent(V, -1);
    // Insert source itself in priority queue and initialize
    // its distance as 0.
    pq.push(mp(0, src));
    dist[src] = 0;
  
    //Looping till priority queue becomes empty (or all distances are not finalized)
    while (!pq.empty())
    {
        //LL d = pq.top().fi;
        LL u = pq.top().se;
        pq.pop();

        if(vis[u]) continue;
        
        vis[u] = true;
        
        foreach(vw, adj[u])
        {
            // Get vertex label and weight of current adjacent
            // of u.
            LL v = vw.fi;

            if(v == src) continue; ///if it the 1st node,then i don't need to visit it
            
            LL weight = vw.se;
  
            //  If there is shorted path to v through u.
            if (dist[v] > dist[u] + weight)
            {
                // Updating distance of v
                dist[v] = dist[u] + weight;
                pq.push(mp(dist[v], v));
                // parent[v] = u;
            }
        }
    }
}

void printPath(vvl path, int v, int u)
{
    if (path[v][u] == v)
        return;

    printPath(path, v, path[v][u]);
    cout << path[v][u] + 1 << " ";
}

void printPathSolution(vvl cost, vvl path)
{
    for (int v = 0; v < N; v++)
    {
        for (int u = 0; u < N; u++)
        {
            if (u != v && path[v][u] != -1)
            {
                cout << "Shortest Path from " << v + 1 << " -> " << u + 1 << " is (" << v+1 << " ";
                printPath(path, v, u);
                cout << u+1 << ") cost: " << cost[v][u] << endl;
            }
        }
    }
}

vvl floydWarshall(vvl adjMatrix)
{
    vvl cost(N, vl(N, LLONG_MAX));
    vvl path(N, vl(N, LLONG_MAX));
    
    for (int v = 0; v < N; v++)
    {
        for (int u = 0; u < N; u++)
        {
            cost[v][u] = adjMatrix[v][u];

            if (v == u)
                path[v][u] = 0;
            else if (cost[v][u] != LLONG_MAX)
                path[v][u] = v;
            else
                path[v][u] = -1;
        }
    }

    for (int k = 0; k < N; k++)
    {
        for (int v = 0; v < N; v++)
        {
            for (int u = 0; u < N; u++)
            {
                if (cost[v][k] != LLONG_MAX && cost[k][u] != LLONG_MAX && cost[v][k] + cost[k][u] < cost[v][u])
                {
                    cost[v][u] = cost[v][k] + cost[k][u];
                    path[v][u] = path[k][u];
                }
            }

            if (cost[v][v] < 0)
            {
                cout << "Negative Weight Cycle Found!!";
                return {};
            }
        }
    }

    //printPathSolution(cost, path);
    return cost;
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

    cout << "Vertex Distance from Source" << endl;
    for (int i = 0; i < V; i++)
    {
        cout << i << "\t\t" << dis[i] << endl;
    }
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
    while (Stack.empty() == false) {
        cout << Stack.top() + 1 << " ";
        Stack.pop();
    }
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
void Union(vector <subset> &subsets, LL x, LL y)
{
    LL xroot = find(subsets, x);
    LL yroot = find(subsets, y);

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
    
    LL e = 0; // An index variable, used for result[]
    LL i = 0; // An index variable, used for sorted edges
 
    // Step 1: Sort all the edges in non-decreasing
    // order of their weight. If we are not allowed to
    // change the given graph, we can create a copy of
    // array of edges
    
    sort(all(edges), myComp);
    // Allocate memory for creating V ssubsets
    vector <subset> subsets(V);
    
    // Create V subsets with single elements
    for (int v = 0; v < V; ++v)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
        subsets[v].nodes = 1;
    }
 
    // Number of edges to be taken is equal to V-1
    while (e < V - 1 && i < E)
    {
        // Step 2: Pick the smallest edge. And increment
        // the index for next iteration
        Edge next_edge = edges[i++];
 
        LL x = find(subsets, next_edge.src);
        LL y = find(subsets, next_edge.dest);
 
        // If including this edge does't cause cycle,
        // include it in result and increment the index
        // of result for next edge
        if (x != y) {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
        // Else discard the next_edge
    }
 
    // print the contents of result[] to display the
    // built MST
    //cout << "Following are the edges in the constructed MST\n";
    int minimumCost = 0;
    if(e < V - 1)
    {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    for (i = 0; i < V - 1; ++i)
    {
        //cout << result[i].src + 1 << " -- " << result[i].dest + 1 << " == " << result[i].weight << endl;
        minimumCost = minimumCost + result[i].weight;
    }
    
    // return;
    cout << minimumCost << endl;
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

// Prints shortest paths from src to all other vertices
void primMST(vl adj[], int V)
{
    priority_queue< pl, vector <pl> , greater<pl> > pq;
 
    int src = 0; // Taking vertex 0 as source
 
    // Create a vector for keys and initialize all
    // keys as infinite (INF)
    vl key(V, INF);
 
    // To store parent array which in turn store MST
    vl parent(V, -1);
 
    // To keep track of vertices included in MST
    vl inMST(V, false);
 
    // Insert source itself in priority queue and initialize
    // its key as 0.
    pq.push(mp(0, src));
    key[src] = 0;
 
    while (!pq.empty())
    {
        // The first vertex in pair is the minimum key
        // vertex, extract it from priority queue.
        // vertex label is stored in second of pair (it
        // has to be done this way to keep the vertices
        // sorted key (key must be first item
        // in pair)
        int u = pq.top().se;
        pq.pop();
         
          //Different key values for same vertex may exist in the priority queue.
          //The one with the least key value is always processed first.
          //Therefore, ignore the rest.
        if(inMST[u] == true)
        {
            continue;
        }
       
        inMST[u] = true;  // Include vertex in MST
 

        loop(i, 0, SIZE(adj[u]))
        {
            // Get vertex label and weight of current adjacent
            // of u.
            int v = adj[u][i].first;
            int weight = adj[u][i].second;
 
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



void solve()
{
    int n,m;
    cin >> n >>m;
    
    //vl adj[n];
    vector<pl> adj[n];
    
    loop(i, 0, m)
    {
        LL u,v,w;
        cin >> u >> v >> w;
        //cin >> u >> v;
        u -= 1;
        v -= 1;

        //addEdge(adj, u, v);
        addWeightEdge(adj, u, v, w);
    }


}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test = 1;
    //cin >> test;
    while(test--) {
        solve();
    }
    
    //loop(i, 0, q) cout << v[i] << endl;

    return 0;
}