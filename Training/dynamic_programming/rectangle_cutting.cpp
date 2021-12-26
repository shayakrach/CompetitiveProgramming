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
#define MODULO 1000000007
#define modsum(a,b) a = (a + b) % MODULO
#define ps cout << endl       

void solve(vvi &vec, int h, int w)
{
    loop(i, 1, h)
    {
        MIN(vec[h][w], vec[i][w] + vec[h - i][w] + 1);
    }

    loop(j, 1, w)
    {
        MIN(vec[h][w], vec[h][j] + vec[h][w -j] + 1);
    } 

    vec[w][h] = vec[h][w];
}



int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a,b;
    cin >> a >> b;
    
    //vector<pi> vect;
    int n = max(a,b);
    vvi vec(n+1, vi(n+1, n*n));

     loop(i,1,n+1)
     {
         vec[i][i] = 0;
     }

    if(a !=b)
    {
        loop(i,1,n+1)
        {
            loop(j,i,n+1)
            {
                solve(vec, i, j);
                //cout <<" (" << i << "," << j << ") " << vec[i][j] << " ";
            }
        }
    }

    cout << vec[a][b];
    return 0;
}