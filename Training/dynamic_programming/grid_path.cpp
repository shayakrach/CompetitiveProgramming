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
typedef pair<int, int> pi;

#define SIZE(v) (int)v.size()
#define SORT(v) sort(all(v))
#define loop(i,s,e) for(int i=s;i<e;++i)
#define pb push_back
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

    int N;
    cin >> N;
    
    //vector<pi> vect;
    vvi vec(N, vi(N, 0));
    vvi grid_count(N, vi(N, 0));
    
    loop(i,0,N){
        loop(j,0,N){
            char grid;
            cin >> grid;
            if(grid == '*'){
                vec[i][j] = 1;
            }
        }
    }


    
    if(!vec[0][0] && !vec[N-1][N-1])
    {
        grid_count[0][0] = 1;
        loop(i,0,N){
            loop(j,0,N){
                if(vec[i][j] == 0){
                    if(i>0) grid_count[i][j] += grid_count[i-1][j];
                    if(j>0) grid_count[i][j] += grid_count[i][j-1];
                    grid_count[i][j] = grid_count[i][j] % MODULO;
                }
            }
        }
    }



    cout << grid_count[N-1][N-1] % MODULO;
    return 0;
}