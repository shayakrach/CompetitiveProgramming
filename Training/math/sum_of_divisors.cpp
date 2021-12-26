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

LL mod_exp(LL a, LL b, LL mod)
{
    if(b ==0) return 1;
    
    LL c = mod_exp(a, b/2, mod);

    LL out = (c * c) % mod;
    
    return (b % 2) ? (a * out) % mod : out; 
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n;

    LL total = 0;

    LL i = 1;
    LL next_i = 1;
    LL N1, N2, N;
    while(next_i <= n)
    {
        LL q = n/i;
        next_i = (n / q) + 1;
        
        LL x = next_i-i, y = i+next_i-1; 
		if (x%2 == 0) x /= 2;
		else y /= 2;
		x %= MODULO, y %= MODULO;
		
        N = q%MODULO*x%MODULO*y%MODULO;
        /*
        N1 = (next_i - i) % MODULO; 
        N2 = (i + next_i - 1) % MODULO;
        N = (N1 * N2) % MODULO;
        N = (N * mod_exp(2, MODULO -2, MODULO)) % MODULO;
        N = ((q % MODULO) * N) % MODULO;
        */
        
        modsum(total, N);
    
        //cout << i << " " << next_i -1 << " -> " << q; 
        //ps;
        i = next_i;
    }

    cout << total;

    return 0;
}