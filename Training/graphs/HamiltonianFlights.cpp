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
const int N = 20;
LL dp[1<< N][N] = {};
vector<pl> adj1[N], adj2[N];
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
    
    int adj[n][n] = {};
    int big_n = 1 << n;
    dp[1][0] = 1;
    loop(i, 0, m)
    {
        int u,v;
        cin >> u >> v;
        u--; v--;
        adj[u][v] += 1;
    }

    loop(i, 2, big_n)
    {
        loop(j, 0, n)
        {
            //if the j bit in i
            if((i >> j) & 1) 
            {
                int i_minus_j = i ^ (1 << j);
                loop(k, 0, n)
                {
                    if((i_minus_j >> k) & 1 && adj[k][j])
                    {
                        //modsum(dp[i][j], dp[i_minus_j][k]);
                        dp[i][j] += dp[i_minus_j][k] * adj[k][j];
                        while(dp[i][j] >= MODULO) dp[i][j] -= MODULO;
                    }
                }
            }
        }
    }

    print(dp[big_n-1][n-1]);
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