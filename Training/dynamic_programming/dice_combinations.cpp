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
typedef vector<LL> vl;
typedef pair<int, int> pi;

#define SIZE(v) (int)v.size()
#define SORT(v) sort(all(v))
#define loop(i,s,e) for(int i=s;i<e;++i)
#define pb push_back
#define all(x) x.begin(), x.end()
#define foreach(a, b) for (auto&(a) : (b))



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vl vec(N+1, 0);
    vi vect;
    
    if(N<7){
        vect.pb(0);
        vect.pb(1);
        vect.pb(2);
        vect.pb(4);
        vect.pb(8);
        vect.pb(16);
        vect.pb(32);
        cout << vect[N];
    }
    else
    {
        vec[0] = 0;
        vec[1] = 1;
        vec[2] = 2;
        vec[3] = 4;
        vec[4] = 8;
        vec[5] = 16;
        vec[6] = 32;

        loop(i,7,N+1){
            loop(j,i-6,i){
                vec[i] = (vec[i] + vec[j]) % 1000000007; 
            }
        }
        
        cout << (vec[N]);
    }
    return 0;
}