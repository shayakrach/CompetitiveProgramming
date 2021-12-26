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

//void DFSUtil(int u, vi adj[], vb &visited);
bool cycleFound = false;
bool finishPush = false;
vi cycleVertices;
int n, m;
map <string, int> name_map;
int countx;


// A utility function to add an edge in an
// undirected graph.
void addEdge(vi adj[], int u, int v)
{
    adj[u].pb(v);
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

void DFSUtil(int u, vi adj[], vb &visited)
{
    visited[u] = true;
    countx++;
    //cout << u << " ";
    for (int i=0; i< SIZE(adj[u]); i++)
    {
        if (visited[adj[u][i]] == false)
        {
            DFSUtil(adj[u][i], adj, visited);
        }
    }
}

void printSCCs(vi adj[], vi revAdj[], int V, int m)
{
    vi count_scc;
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
    for(int i = 0; i < V; i++)
        visited[i] = false;
  
    // Now process all vertices in order defined by Stack
    while (Stack.empty() == false)
    {
        // Pop a vertex from stack
        int v = Stack.top();
        Stack.pop();
  
        // Print Strongly connected component of the popped vertex
        if (visited[v] == false)
        {
            countx = 0;
            DFSUtil(v, revAdj, visited);
            //cout << endl;
            count_scc.pb(countx);
        }
    }

    SORT(count_scc);
    reverse(count_scc.begin(), count_scc.end());
    
    int S = SIZE(count_scc);

    loop(i, 0, m)
    {
        if(i < S)
        {
            print(count_scc[i]);
        }
        else
        {
            print("Does not apply!");
        }
    }
}


void solve()
{
    int n, m;
    cin >> n >> m;
    vi adj[n];
    vi revAdj[n];
    int V = n;

    while (true)
    {
        string u, v;
        cin >> u;

        if(u.compare("END") == 0)
        {
            break;
        }

        if(name_map.find(u) == name_map.end())
        {
            name_map[u] = --n;
        }

        cin >> v;

        if(name_map.find(v) == name_map.end())
        {
            name_map[v] = --n;
        }

        addEdge(adj, name_map[u], name_map[v]);
        addEdge(revAdj, name_map[v], name_map[u]);
    }
    
    printSCCs(adj, revAdj, V, m);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test = 1;
    //cin >> test;
    while(test--) {
        solve();
    }
    return 0;
}