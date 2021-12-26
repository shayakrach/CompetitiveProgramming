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
    
    vi vec;
    set<int> binary_set;

    loop(i,0,n)
    {
        int num;
        cin>>num;
        vec.pb(num);
    }

    loop(i,0,n)
    {
        loop(j,0,i)
        {
            binary_set.insert(vec[i] & vec[j]);
        }
    }
    

    cout << binary_set.size();
    return 0;
}