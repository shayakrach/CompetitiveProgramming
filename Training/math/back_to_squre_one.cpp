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


int solve(int k){
    
    double v[k-1];
    double sum = 1;
    double expect = 1;    

    loop(i, 0, k-1)
    {
        double prob;
        cin >> prob;
        v[i] = prob;
    }

    rloop(i, k-2, 0)
    {
        expect = expect/v[i];
        modsum(sum, expect);
    }

    return round(sum);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin >> q;    
    vi v;
    
    while(q!= 0)
    {
        v.pb(solve(q));
        cin >> q;
    }
    
    loop(i, 0, SIZE(v)) cout << v[i] << endl;
    
    return 0;
}