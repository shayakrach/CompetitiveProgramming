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


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    
    vi v;
    int max_sum = 0;
    loop(i,0,n)
    {
        int num;
        cin>>num;
        v.pb(num);
        max_sum += num;
    }

    bool dp[n][max_sum +1] = {};

    loop(i,0,n)
    {
        dp[i][0] = true;
    }
    
    vi reachable;

    dp[0][v[0]] = true;

    loop(i,1,n)
    {
        loop(j,1,max_sum+1)
        {
            dp[i][j] = dp[i-1][j];

            if(j - v[i] >= 0)
            {
                dp[i][j] = dp[i][j] || dp[i-1][j - v[i]];
            }

            if(i == n-1 && dp[i][j])
            {
                reachable.pb(j);
            }
        }
    }
    
    if(SIZE(reachable) == 0)
    {
        reachable.pb(v[0]);
    }

    cout << SIZE(reachable) << endl;

    foreach(num, reachable)
    {
        cout << num << " ";
    }
    
    return 0;
}