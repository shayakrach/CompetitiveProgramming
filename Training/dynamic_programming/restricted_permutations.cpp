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
#define pf push_front
#define mp make_pair
#define all(x) x.begin(), x.end()
#define foreach(a, b) for (auto&(a) : (b))
#define MAX(a, b) a = max(a, b)
#define MIN(a, b) a = min(a, b)
#define MODULO 1000000007
#define modsum(a,b) a = (a + b) % MODULO

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    
    vi v;
    vi sum;

    loop(i,0,n-1)
    {
        int num;
        cin>>num;
        v.pb(num);
    }
    
    sum.pb(1);
    
    int sum_size=1;
    
    loop(i, 0, n-1)
    {
        sum_size++;
        
        if(v[i] == 1)
        {
           sum.insert(sum.begin(), 0);
           
           loop(j, 1, sum_size)
           {
                modsum(sum[j], sum[j-1]);   
           }
        }
        else
        {
            sum.pb(0);
           
            rloop(j, sum_size - 2, 0)
            {
                modsum(sum[j], sum[j+1]);   
            }    
        }
    }
    
    int out = 0;
    
    loop(i, 0, n)
    {
       modsum(out, sum[i]);
    }
    
    cout << out;
    return 0;
}