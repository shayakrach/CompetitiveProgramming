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


const int N = 1e5+5;
bool used[N];
stack<LL> g[N];
LL degree[N];
vector<LL> path;
int SS_PLUS = 0;
int SS_MINUS = 0;

void make_path(int u)
 {
    //deb(u);
    while(degree[u]) 
    {
        int v = g[u].top();
        g[u].pop();

        //g[v].erase(u);
        degree[u]--;
       
        if(degree[u])
        {
            int w = g[u].top();
            if(degree[w] >= degree[v])
            {
                g[u].pop();
                g[u].push(v); 
                v = w;
            }
        }
     /**/
        
        deb2(u, v);
        //cout << "make path -> " << v << endl;
        make_path(v);
    }

    //cout << "back track from " << u << endl;
    path.pb(u&1);
   
}
 
void solve() {
    int n;
    cin >> n;
    
    if(n == 1)
    {
        cout << 10 <<endl;
        return;
    }

    //cout << "FUCK" << endl;
    int V = 1 << (n - 1);
    int mask = V-1;
    //deb(V);
    //cout << "FUCK" << endl;
    deb(mask);
    for(int u = 0; u<V; u++) 
    {
        int v_0 = (u << 1) & mask;
        //g[u].insert(v_0);
        int v_1 = v_0 + 1;
        g[u].push(v_0);
        g[u].push(v_1);
       
        //g[u].insert(v_1);
        degree[u] += 2;
        //cout << u << endl;
    }
    //cout << "FUCK YOU" << endl;
    make_path(0);
    
    // add leading zeros
    loop(i, 0, n-2)
    {
        cout << 0;
    }

    while(!path.empty()) {
        cout << path.back();
        path.pop_back();
    }
}   

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test = 1;
    //cin >> test;
    while(test--) 
    {
        solve();
    }
    //int x = 1 << 14;
    //print(x);
    return 0;
} 
