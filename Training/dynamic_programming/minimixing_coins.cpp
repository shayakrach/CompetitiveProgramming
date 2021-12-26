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
#define MAX(a, b) a = max(a, b)
#define MIN(a, b) a = min(a, b)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,x;
    cin >> n >> x;
    
    vi vec(x+1, INT_MAX);
    vi coins;

    int num_of_coins=0;
    loop(i, 0, n)
    {
        int c;
        cin >> c;
        if(c<=x)
        {
            coins.pb(c);
            vec[c] = 1;
            num_of_coins++;
        }
    }

    loop(i, 1, x+1)
    {
        if(vec[i] < INT_MAX)
        {    
            continue;
        }

        loop(j, 0, num_of_coins)
        {
            if(i - coins[j] >= 0 && vec[i - coins[j]] != INT_MAX)
            {
                MIN(vec[i], vec[i - coins[j]] + 1);
            } 
        }


    }

    if(vec[x] == INT_MAX)
    {
        vec[x] = -1;
    }

    cout << vec[x];
    return 0;
}