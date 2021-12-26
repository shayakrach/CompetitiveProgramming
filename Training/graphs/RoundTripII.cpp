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
bool cycleFound = false;
bool finishPush = false;
vi cycleVertices;

// A utility function to add an edge in an
// undirected graph.
void addEdge(vi adj[], int u, int v)
{
    adj[u].pb(v);
}

// A utility function to do DFS of graph
// recursively from a given vertex u.
void DFSUtil(int u, vi adj[], vb &visited,vb &recStack)
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
 
// This function does DFSUtil() for all
// unvisited vertices.
void DFS(vector<int> adj[], int V)
{
    vb visited(V, false);
    vb recStack(V, false);
    
    for (int u=0; u<V; u++)
    {
        if (visited[u] == false)
            DFSUtil(u, adj, visited, recStack);
        if(cycleFound) return;
    }
}


void solve()
{
    int n,m;
    cin >> n >>m;
    
    vector<int> adj[n];

    loop(i, 0, m)
    {
        int v,u;
        cin >> v >> u;
        addEdge(adj, v - 1, u - 1);
    }

    DFS(adj, n);

    //loop(i, 0, n) cout << cycleVertices[i] << " ";
    //ps;
    //ps;

    if(cycleFound)
    {
        reverse(all(cycleVertices));
        int cycle_size = SIZE(cycleVertices);
        cout << cycle_size << endl;
        loop(i, 0, cycle_size) cout << cycleVertices[i] + 1 << " ";
    }
    else
    {
        cout << "IMPOSSIBLE" << endl;
    }

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