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
const int N = 1e5 + 5;
vector<pl> adj1[N], adj2[N];
LL dp[2][N] = {};
int n, m;

void solve()
{
    LL l,r;
    cin >> l >> r;

    print(dp[r/N][r%N] - dp[(l-1)/N][(l-1)%N]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,q;
    cin >> n >> q;
    loop(i, 1, n+1)
    {
        LL x;
        cin >> x;
        dp[i/N][i%N] = dp[(i-1)/N][(i-1)%N] + x;
    }
    while(q--) {
        solve();
    }
    return 0;
}