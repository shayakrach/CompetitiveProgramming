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
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << ", " << #y << "=" << y << endl
#define deb3(x, y, z) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl
#define print(var)    cout << var << endl
/*****User defined function*****/
const int N = 1e5+5;
bool used[N];
set<int> g[N];
int degree[N];
vector<int> path;


 
void component(int u) 
{
    used[u] = 1;
    for(int v: g[u])
    {
        if(!used[v])
            component(v);
    }
}
 
bool has_euler(int n)
{
    loop(i, 1, n+1) 
    {
        if(degree[i]&1) return false;
    }

    memset(used, 0, sizeof used);
    //cout << sizeof used << endl;
    component(1);
 
    loop(i, 1, n+1) 
        if(!used[i] && degree[i] != 0)
            return false;
 
    return true; 
}
 
void make_path(int u)
 {
   
    while(degree[u]) 
    {
        //deb(u);
        for (auto itr = g[u].begin(); itr != g[u].end(); itr++)
        {
            cout << *itr<<" ";
        }
        //ps;
        int v = *g[u].begin();
        g[u].erase(v);
        g[v].erase(u);
        degree[u]--, degree[v]--;
        //cout << "make path -> " << v << endl;
        make_path(v);
    }
    
    //cout << "push u -> " << u << endl;
    path.pb(u);
}
 
void solve() {
    int n, m;
    cin >> n >> m;
 
    loop(i, 1, m + 1) {
        int u, v;
        cin >> u >> v;
        g[u].insert(v);
        g[v].insert(u);
        degree[u]++, degree[v]++;
    }
 
    if(!has_euler(n))
    {
        print("IMPOSSIBLE");
        return;
    }
 
    make_path(1);
    
    while(!path.empty()) {
        cout << path.back() << " ";
        path.pop_back();
    }
}   
 
/*****main function*****/
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