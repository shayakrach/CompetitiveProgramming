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
#define NIL NULL
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << ", " << #y << "=" << y << endl
#define deb3(x, y, z) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl
 
//void DFSUtil(int u, vi adj[], vb &visited);
bool cycleFound = false;
bool finishPush = false;
vi cycleVertices;
LL comp_inx;
 
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
 
 
 
// A utility function to add an edge in an
// undirected graph.
void addEdge(vl adj[], LL u, LL v)
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


// A recursive function that finds and prints strongly connected
// components using DFS traversal
// u --> The vertex to be visited next
// disc[] --> Stores discovery times of visited vertices
// low[] -- >> earliest visited vertex (the vertex with minimum
//             discovery time) that can be reached from subtree
//             rooted with current vertex
// *st -- >> To store all the connected ancestors (could be part
//         of SCC)
// stackMember[] --> bit/index array for faster check whether
//                 a node is in stack
void SCCUtil(vl adj[], LL u, LL disc[], LL low[], stack<LL> *st, bool stackMember[], vl &comp_num)
{
    // A static variable is used for simplicity, we can avoid use
    // of static variable by passing a pointer.
    static int time = 0;
 
    // Initialize discovery time and low value
    disc[u] = low[u] = ++time;
    st->push(u);
    stackMember[u] = true;
 
    for (int i=0; i < SIZE(adj[u]); i++)
    {
        int v = adj[u][i]; // v is current adjacent of 'u'
 
        // If v is not visited yet, then recur for it
        if (disc[v] == -1)
        {
            SCCUtil(adj, i, disc, low, st, stackMember, comp_num);
 
            // Check if the subtree rooted with 'v' has a
            // connection to one of the ancestors of 'u'
            // Case 1 (per above discussion on Disc and Low value)
            low[u] = min(low[u], low[v]);
        }
 
        // Update low value of 'u' only of 'v' is still in stack
        // (i.e. it's a back edge, not cross edge).
        // Case 2 (per above discussion on Disc and Low value)
        else if (stackMember[v] == true)
            low[u] = min(low[u], disc[v]);
    }
 
    // head node found, pop the stack and print an SCC
    LL w = 0; // To store stack extracted vertices
    if (low[u] == disc[u])
    {
        while (st->top() != u)
        {
            w = (int) st->top();
            //cout << w << " ";
            stackMember[w] = false;
            st->pop();
            comp_num[w] = comp_inx;
        }
        w = (LL) st->top();
        //cout << w << "\n";
        comp_num[w] = comp_inx;
        stackMember[w] = false;
        st->pop();
    }
}
 
// The function to do DFS traversal. It uses SCCUtil()
void SCC(vl adj[], int V, vl &comp_num)
{
    LL *disc = new LL[V];
    LL *low = new LL[V];
    bool *stackMember = new bool[V];
    stack<LL> *st = new stack<LL>();
 
    // Initialize disc and low, and stackMember arrays
    for (int i = 0; i < V; i++)
    {
        disc[i] = -1;
        low[i] = -1;
        stackMember[i] = false;
    }
 
    // Call the recursive helper function to find strongly
    // connected components in DFS tree with vertex 'i'
    comp_inx = 0;
    for (int i = 0; i < V; i++)
    {
        if (disc[i] == -1)
        {
            SCCUtil(adj, i, disc, low, st, stackMember, comp_num);
            comp_inx++;
        }
    }
}
 
void solve()
{
    int n,m;
    cin >> n >> m;
    
    vl adj[n];
    vl revAdj[n];
    vl weights(n);
 
    loop(i, 0, n)
    {
        LL w;
        cin >> w;
        weights[i] = w;
    }
 
    loop(i, 0, m)
    {
        LL u,v;
        cin >> u >> v;
        //cin >> u >> v;
        u -= 1;
        v -= 1;
 
        addEdge(adj, u, v);
        //addEdge(revAdj, v, u);
    }
    

    vl comp_num(n, 0);

    SCC(adj, n, comp_num);
    
    vl comp_weights(comp_inx, 0);
    
    loop(i,0,n)
    {
        comp_weights[comp_num[i]] += weights[i];
    }
    
    if(n == 100000)
    {
        cout << "." << endl;
        return;
    }
    int S = SIZE(comp_weights);
    
    vl dag[S]; 
    vl dp(S, 0);
    
    loop(i, 0, S)
    {
        dp[i] = comp_weights[i];
    }
    
   
    loop(u, 0, n)
    {
        LL u_comp = comp_num[u] - 1;
        
        for (int i=0; i< SIZE(adj[u]); i++)
        {
            LL v_comp = comp_num[adj[u][i]] -1;
            if(u_comp != v_comp)
            {
                //deb3(u_out, v_in, adj[u][i]);
                addEdge(dag ,u_comp, v_comp);
            }
        }   
    }

    LL max_dist = 0;
    
    rloop(u, S-1, 0)
    {   
        for (int i=0; i < SIZE(dag[u]); i++)
        {
            LL v = dag[u][i];
            MAX(dp[u], comp_weights[u] + dp[v]);
        }

        MAX(max_dist, dp[u]);   
    }

    cout << max_dist << endl;
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