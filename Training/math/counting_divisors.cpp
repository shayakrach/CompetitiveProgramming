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


/**/
int solve()
{
    int num; 
    cin >> num;
    
    int total = 0;
    int sq = (int)sqrt(num);
    
    loop(i, 1, sq+1)
    {
        if(num%i == 0)
        {
            total += 2 - (num / i == i);
        } 
    }

    return total;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin >> q;

    vl v;

    loop(i, 0, q) v.pb(solve());

    loop(i, 0, q) cout << v[i] << endl;
    
    //cout << (int)sqrt(8);
    
    /*int n;
    cin >> n;
    
    //vector<pi> vect;
    // vvi dp(n, vi(n, 0));
    vi v;
    
    read(v, n)
    
    
    loop(i,0,n)
    {
        int num;
        cin>>num;
        //vect.pb(mp(num, i));
        v.pb(num);
    }
   

    loop(i,0,n)
    {
        //vect.pb(mp(num, i));
        loop(j,0,n)
        {
        
        }
        //cout << " i " << i  << " j " << j << " dp -> " << dp[i][j];
    }
    */
    // run on diagonals from the main diagonal up.
    /*
    int row = 0, col = 0, diag = 0; 
    while (diag < n)
    {
        if(col == n)
        {
            row = 0;
            col = ++diag;
            continue;
        }



        row++;
        col++;
    }
    */
    

    return 0;
}