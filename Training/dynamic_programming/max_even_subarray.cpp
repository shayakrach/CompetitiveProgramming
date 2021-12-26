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
typedef vector<vl> vvl;
typedef pair<int, int> pi;

#define SIZE(v) (int)v.size()
#define SORT(v) sort(all(v))
#define loop(i,s,e) for(int i=s;i<e;++i)
#define rloop(i,s,e) for(int i=s;i>=e;--i)
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define foreach(a, b) for (auto&(a) : (b))
#define MAX(a, b) a = max(a, b)
#define MIN(a, b) a = min(a, b)
#define MODULO 1000000007


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    
    //vector<pi> vect;
    vl d(n+1, 0);
    vi vec;
    
    loop(i,0,n)
    {
        int num;
        cin>>num;
        vec.pb(num);
    }

    d[n-2] = vec[n-1] + vec[n-2];
  
    LL max_even_sub =  d[n-2];
    
    rloop(i, n - 3, 0)
    {
        // d[n] == 0
        d[i] =  vec[i] + vec[i+1] + max(d[n], d[i+2]);
        MAX(max_even_sub, d[i]);
    }
    

    cout << max_even_sub;
    return 0;
}