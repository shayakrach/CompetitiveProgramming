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

/*
void solve(vi &vec, int i, int num){
    while(num>0){
        MIN(vec[i], vec[i-num%10] + 1);
        num = num/10;
    }
}
*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin >> n >> m;
    
    vi v;
    
    read(v, n);
    
    int dp[n][m+2] = {};

 
    if(v[0] == 0)
    {
        loop(j,1,m+1)
        {
            dp[0][j] = 1;
        }
    }
    else
    {
        dp[0][v[0]] = 1;
    }
    
    ps;
    loop(i,1,n)
    { 
        if(v[i] == 0)
        {
            loop(j,1,m+1)
            {
                
                modsum(dp[i][j], dp[i - 1][j - 1]);
                modsum(dp[i][j], dp[i - 1][j]);
                modsum(dp[i][j], dp[i - 1][j + 1]);
            }
        }   
        else
        {
            modsum(dp[i][v[i]], dp[i - 1][v[i] - 1]);
            modsum(dp[i][v[i]], dp[i - 1][v[i]]);
            modsum(dp[i][v[i]], dp[i - 1][v[i] + 1]);
        }        
    }

    int out = 0;
    
    loop(j,1,m+1)
    {
        modsum(out, dp[n-1][j]);
    }
    
    cout << out;
    return 0;
}