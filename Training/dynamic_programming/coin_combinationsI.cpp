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
typedef pair<int, int> pi;

#define SIZE(v) (int)v.size()
#define SORT(v) sort(all(v))
#define loop(i,s,e) for(int i=s;i<e;++i)
#define rloop(i,s,e) for(int i=s;i>=e;--i)
#define pb push_back
#define mp make_pair
#define pf push_front
#define all(x) x.begin(), x.end()
#define foreach(a, b) for (auto&(a) : (b))
#define MAX(a, b) a = max(a, b)
#define MIN(a, b) a = min(a, b)
#define MODULO 1000000007
#define modsum(a,b) a = (a + b) % MODULO


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    cin >> n >> x;
    
    //vector<pi> vect;
    // vvi vec(n, vi(n, 0));
    vi coins;
    vi dp(x+1,0);
    loop(i,0,n)
    {
        int coin;
        cin>>coin;
        coins.pb(coin);
        if(coin <= x) dp[coin] = 1;
    }

    loop(i,1,x+1)
    {
        foreach(coin, coins)
        {
            if(i - coin > 0)
            {
                modsum(dp[i], dp[i - coin]);
            }
        }
    }

    cout << dp[x];
    return 0;
}