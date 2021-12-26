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

bool cycleFound = false;
bool finishPush = false;
vi cycleVertices;
int N;
// To add an edge
void addWeightEdge(vector <pair<LL,LL>> adj[], LL u, LL v, LL wt)
{
    adj[u].pb(mp(v, wt));
    adj[v].pb(mp(u, wt));
}

void printPath(vvl path, int v, int u)
{
    if (path[v][u] == v)
        return;

    printPath(path, v, path[v][u]);
    cout << path[v][u] + 1 << " ";
}
void printSolution(vvl cost, vvl path)
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

    //printSolution(cost, path);
    return cost;
}

void solve()
{
    int n,m,q;
    cin >> n >>m >> q;
    N = n;

    vvl adj(n, vl(n, LLONG_MAX));
    
    loop(i, 0, n) adj[i][i] = 0;

    loop(i, 0, m)
    {
        LL v,u,w;
        cin >> v >> u >> w;
        //addWeightEdge(adj, v -1, u-1, w);
        v -= 1;
        u -= 1;
        //addWeightEdge(adj, v,u,w);
        //adj[min(u,v)][max(u,v)] = w;
        adj[u][v] = min(adj[u][v],w);
        adj[v][u] = adj[u][v];
    }

    //printWeightGraph(adj, n);

    //vvl mat(n, vl(n, LLONG_MAX));

    vvl mat;
    mat = floydWarshall(adj);
    vl out_vec;
    
    loop(i, 0, q)
    {
        LL s,t;
        cin >> s >> t;
        //deb2(s,t);
        s -=1;
        t -=1;
        
        LL out = mat[t][s] == LLONG_MAX ? -1: mat[s][t];
        out_vec.pb(out);
    }
    
    loop(i, 0, q)
    {
        cout << out_vec[i] << endl;
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