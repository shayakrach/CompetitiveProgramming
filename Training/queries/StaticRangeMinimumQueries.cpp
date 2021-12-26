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

const int N = 2*1e5 + 5;
vl arr(N, INF);
vl min_arr(N, INF);
int n,q;
const int block_size = 450;

void solve()
{
    LL l,r;
    cin >> l >> r;

    LL out = INF;
    if(r-l < block_size)
    {
        loop(i, l, r+1)
        {
            MIN(out, arr[i]);
        }
    }
    else{
        for(int i = l+block_size-1; i<r; i+= block_size)
        {
            MIN(out, min_arr[i]);
        }
        
        MIN(out, min_arr[r]);
    }

    print(out);
}

void preprocessing()
{
    set<LL> my_set;
    loop(i, 0, n+1)
    {
        LL x;
        cin >> x;
        arr[i] = x;
        //print(x);
        my_set.insert(arr[i]);
        
        if(i >= block_size)   
        {
            my_set.erase(arr[i - block_size]);
        }
        LL first = *(my_set.begin());
        //deb(first);
        min_arr[i] = first;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;
    preprocessing();
    
    while(q--) {
        solve();
    }
    
    return 0;
}