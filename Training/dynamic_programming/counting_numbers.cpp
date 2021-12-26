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
#define MODULO 1e9 + 7
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

    int n;
    //cin >> n;
    
    //vector<pi> vect;
    // vvi vec(n, vi(n, 0));
    vi vec;
    
    loop(i,0,100)
    {
        //int num;
        //cin>>num;
        //vect.pb(mp(num, i));
        if(i/10 != i%10)
        cout << i << endl; 
    }

    loop(i,0,n)
    {
        //vect.pb(mp(num, i));
        loop(j,0,n)
        {
        
        }
    }

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
    //9 (91 - 9)
/*
    (2 digits)099 ->90 = 739
              199 -> 90 + 

    (3 digits)999 -> 738 +'0' = 739
*/
    

    int out = 0;

    //cout << out;
    return 0;
}