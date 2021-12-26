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


LL solve(){

    LL n,k;
    cin >> n >>k;
    LL start = 2;
    int start_first = 0;
    LL diff = 1;

    while (true)
    {
       
        /* 
        cout << "s= " << start  << " diff= " << diff  << " start fi= " << start_first << " n = " << n << " half " << half <<  " 1k = " << k << endl; 
        loop(i, 0, half)
        {
            cout << start + (2*diff*i) << " ";
        }
        ps;
        ps;
        ps;
       */

        LL half = (n + start_first) / 2;
        if(k <= half) return start + (2* diff *(k-1));
        
        if(n == 1) return start - diff;
        if(n == 2)
        {
            if(start_first) return start + diff;
            else return start - diff;
        }
        if(n == 3 && start_first) return start + diff;
        
        
        if(n%2 == 1)
        {
            if(start_first) start += 3 * diff;
            else start -= diff;
            
            start_first = 1 - start_first;
        } 
        else start += diff;
        
        n -= half;
        k -= half;
        diff *= 2;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin >> q;

    vl v;

    loop(i, 0, q) v.pb(solve());
    
    loop(i, 0, q) cout << v[i] << endl;

    return 0;
}