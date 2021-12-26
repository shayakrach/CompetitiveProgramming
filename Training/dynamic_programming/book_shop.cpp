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

    int n,x;
    cin >> n >> x;
    
    //vector<pi> vect;
    // vvi vec(n, vi(n, 0));
    int h[n+1];
    int s[n+1];

    loop(i,1,n+1)
    {
        int price;
        cin>>price;
        h[i] = price;
    }

    loop(i,1,n+1)
    {
        int pages;
        cin>>pages;
        //vect.pb(mp(num, i));
        s[i] = pages;
    }


    int dp[n+1][x+1] = {};

    loop(i,1,n+1)
    {
        
        loop(j,1,x+1)
        {
            
            dp[i][j] = dp[i-1][j];
            
            if(j - h[i] >= 0)
            {
                MAX(dp[i][j], dp[i-1][j - h[i]] + s[i]);
            }

            //cout << " i " << i << " j " << j << " max -> " << dp[i][j] << endl;
        }
    }

    cout << dp[n][x];
    return 0;
}