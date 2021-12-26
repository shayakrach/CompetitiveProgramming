#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <cstdio>
 
using namespace std;
 
typedef long long LL;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<LL> vl;
typedef pair<int, int> pi;
 
#define SIZE(v) (int)v.size()
#define SORT(v) sort(all(v))
#define loop(i,s,e) for(int i=s;i<e;++i)
#define rloop(i,s,e) for(int i=s;i>=e;--i)
#define pb push_back
#define all(x) x.begin(), x.end()
#define foreach(a, b) for (auto&(a) : (b))
#define MAX(a, b) a = max(a, b)
#define MIN(a, b) a = min(a, b)
#define MODULO 1000000007
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
 
    int n;
    cin >> n;
    
    //vector<pi> vect;
    
    vi v;
    
    loop(i,0,n)
    {
        int num;
        cin>>num;
        v.push_back(num);
    }
    
    int max_len = 0;
    int max_end_inx = 0;
    vi dp(n+1);
    
    
    loop(i, 0, n)
    {
        dp[v[i]] = 1 + dp[v[i]-1];
        
        if(dp[v[i]] > max_len)
        {
            max_len = dp[v[i]];   
            max_end_inx = v[i];
        }
    }
    
    int max_begin_inx = max_end_inx - max_len;
    
    cout << n - max_len << endl;
    
    rloop(i, max_begin_inx, 1)
    {
        cout << i << " 0" << endl;
    }
    
    loop(i, max_end_inx + 1, n+1)
    {
        cout << i << " 1"<<endl;
    }

    return 0;
}