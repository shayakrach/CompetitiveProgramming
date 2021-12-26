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



void solve(){

    int B,N;
    cin >> B >> N;
    
    vi v(N);

    loop(i,0,N)
    {
        int num;
        cin>>num;
        v[i] = num;
    }

    cout << "WHY";
    vvi vect(N);
    
    loop(i,0,N)
    {
        loop(j,0,v[i])
        {
            int num;
            cin >> num;
            vect[i].pb(num);
        }
    }

    bool dp[N][B+1] = {};
    
    for(int num: vect[0])
    {
        if(num <= B){
            dp[0][num] = true;  
        }
    }


    loop(i,1,N)
    {
        loop(j,0,B+1)
        {
            for(int num: vect[i])
            {
                if(j - num >= 0 &&  dp[i][j - num])
                {
                    dp[i][j] = true;
                }
            }
        }
        //cout << " i " << i  << " j " << j << " dp -> " << dp[i][j];
    }

    int max_val = 0;
    rloop(j, B, 0)
    {
        if(dp[N-1][j])
        {
            max_val = j;
            break;
        }
    }
    
    cout << max_val;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    
    int t; 
    cin>>t;

    loop(i,0,t) solve();
    
    
    return 0;
}