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

    int n;
    cin >> n;
    
    vvl vec2(n, vl(n, 0));
    vvl sum(n, vl(n, 0));
    vl vec;
    
    int opp_turn = n%2;
    
    loop(i,0,n){
        int num;
        cin>>num;
        vec.push_back(num);
        sum[i][i] = num;
        //cout << i << " sum ->" << sum[i][i] << endl; 
        if(opp_turn != 0) vec2[i][i] = num;
    }

    int row = 0, col = 1, diag = 1; 
    while (diag < n)
    {
        if(col == n)
        {
            row = 0;
            col = ++diag;
            continue;
        }

        sum[row][col] = sum[row][col-1] + vec[col];
        
        if(diag % 2 == opp_turn)
        {
            if((sum[row][col - 1] - vec2[row][col - 1]) + vec[col] > (sum[row + 1][col] - vec2[row + 1][col]) + vec[row])
            {
                vec2[row][col] = vec2[row][col - 1];
            }
            else
            {
                vec2[row][col] = vec2[row+1][col];
            }
           
        }
        else
        {
            vec2[row][col] = max(vec2[row][col - 1] + vec[col], vec2[row+1][col] + vec[row]);
            /*
            cout << endl; 
            cout << " row:" << row << " col:" << col << endl;
            cout << endl; 
            cout << row << " " << col - 1 << " left: " << vec2[row][col-1] << " + " << vec[col] << endl; 
            cout << row +1 << " " << col << " down: " << vec2[row+1][col] << " + " << vec[row] << endl; 
            cout << row << " " << col << " sum -> " << sum[row][col] << " vec " << vec2[row][col] << endl; 
            vec2[row][col] = sum[row][col] - vec2[row][col];
            cout << endl; cout << endl; 
            */
        }

        //cout << row << " " << col << " " << vec2[row][col] << endl; 

        row++;
        col++;
    }
    

    cout << vec2[0][n-1];
    return 0;
}