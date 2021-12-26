#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

#define int int64_t
#define loop(i,s,e) for(int i=s;i<e;++i)
#define vi vector<int>
#define pb push_back
using namespace std;

const int MOD = 1e9+7;

vi getPrimes(int n){

    set<int> s;
    vi p;
    
    for(int i=2;i*i<=n;++i){

        if (n%i==0){
            s.insert(i);
            s.insert(n/i);
        }
    }   

    for(auto i:s){

        if(n%i==0) p.pb(i);

        while(n%i==0) n/=i;
    }

    if (n>1) p.pb(n);

    return p;
}



int getSum(int mult, int x){

    int n = x/mult;

    int v;

    if (n%2) v = (n+1)/2%MOD * (n %MOD)%MOD;

    else v = n/2%MOD * ((n+1) %MOD)%MOD;

    return (mult * v)%MOD;

}

int solve(vi& p, int x, int mult = 1, int cur=0, bool b=true){

    if (cur==p.size()){

        int v = getSum(mult, x);

        return (b?v:MOD-v);

    }

    return (solve(p,x,mult * p[cur], cur+1,!b) + solve(p, x, mult, cur+1, b))%MOD;

}

int32_t main() {

    int t; cin>>t;

    loop(i,0,t){

        int n,a,b; cin>>n>>a>>b;

        vi p = getPrimes(n);

        int v = (solve(p,b) + MOD-solve(p,a-1))%MOD;

        cout<<v<<endl;

    }

    return 0;

}

