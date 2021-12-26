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
typedef map<int, int> mii;
typedef map<string, int> msi;
typedef map<int, string> mis;


#define mp make_pair
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define readc(x) char x; cin >> x
#define reads(x) string x; cin >> x
#define readi(x) int x; cin >> x
#define read2i(x, y) readi(x); readi(y)
#define readl(x) LL x; cin >> x
#define read2l(x, y) readl(x); readl(y)
#define len(v) (int)v.size()
#define all(x) x.begin(), x.end()
#define SORT(v) sort(all(v))
#define loop(i,s,e) for(int i=s;i<e;++i)
#define rloop(i,s,e) for(int i=s;i>=e;--i)
#define foreach(a, b) for (auto&(a) : (b))
#define MAX(a, b) a = max(a, b)
#define MIN(a, b) a = min(a, b)
#define MODULO 1000000007
#define modsum(a,b) a = (a + b) % MODULO
#define ps cout << endl      
#define INF LLONG_MAX
#define print(var)    cout << var << endl
#define print2(var1, var2) cout << var1 << " " << var2 << endl
#define print3(var1, var2, var3) cout << var1 << " " << var2 << " " << var3 << endl
#define printr(var) cout << var << endl; return
#define print2r(var1, var2) cout << var1 << " " << var2 << endl; return
#define print3r(var1, var2, var3) cout << var1 << " " << var2 << " " << var3 << endl; return
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << ", " << #y << "=" << y << endl
#define deb3(x, y, z) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl

//void DFSUtil(int u, vi adj[], vb &visited);
bool cycleFound = false;
bool finishPush = false;
vi cycleVertices;
const int N = 5;
vector<pl> adj1[N], adj2[N];
int adj_mat[N][N];
int n, m;

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

void solve()
{
    cin >> n >> m;
    
    //vl adj[n];
    vector<pl> adj[n];
    
    loop(i, 0, m)
    {
        LL u,v;
        cin >> u >> v >> w;
        u--; v--;
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
    return 0;
}