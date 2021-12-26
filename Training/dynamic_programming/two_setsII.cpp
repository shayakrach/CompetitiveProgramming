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
#define all(x) x.begin(), x.end()
#define foreach(a, b) for (auto&(a) : (b))
#define MAX(a, b) a = max(a, b)
#define MIN(a, b) a = min(a, b)
#define MODULO 1000000007
#define modsum(a,b) a = (a + b) % MODULO
#define ps cout << endl       

void read(vi &v, int n)
{
    loop(i,0,n)
    {
        int num;
        cin>>num;
        v.pb(num);
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    
    vi v;
    int N = (n*n + n) / 2;
    if(N%2 != 0)
    {
        cout << 0;
        return 0;
    }

    int half = N/2;

    vvi dp(n+1, vi(half + 1, 0));
    
    loop(i,0,n)
    {
        dp[i][0] = 1;
    }

    loop(i,1,n+1)
    {
        loop(j,0,half + 1)
        {
            dp[i][j] = dp[i - 1][j];
            
            if(j - i>= 0)
            {
                modsum(dp[i][j], dp[i-1][j - i]);
            }

            //cout << " i " << i  << " j " << j << " dp -> " << dp[i][j];
            
        }

    }

    cout << dp[n-1][half];
    return 0;
}