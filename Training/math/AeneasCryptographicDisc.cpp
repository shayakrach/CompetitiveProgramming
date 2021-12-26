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



long double dis(pair <long double, long double> p1, pair <long double, long double> p2)
{
    return sqrt((p1.first - p2.first)*(p1.first - p2.first) + (p1.second - p2.second)*(p1.second - p2.second));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double r;
    cin >> r;

    vector<pair<long double, long double>> v(26);

    loop(i, 0, 26)
    {
        char c;
        long double ang;
        
        cin >> c;
        cin >> ang;
        
        ang = (ang * 3.14159) / 180;
        
        v[c - 'A'] = mp(r * cos(ang) , r * sin(ang));
        //cout << c - 'A' << endl;
        //cout<< v[c - 'A'].first << " " << v[c - 'A'].second <<endl; 
    }
    
    pair <long double, long double> last_po = mp(0,0);
    string str;
    long double sum_len = 0;
    
    while(cin >> str)
    {
        //cout << str <<endl;
        foreach(s, str)
        {
            if (isalpha(s))
            {
                int pos = toupper(s) - 'A';
                sum_len = sum_len + dis(last_po, v[pos]);
                last_po = v[pos];
            }
        }
    }
    
    cout << ceil(sum_len);
    
    return 0;
}