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
typedef pair<LL, LL> pl;
typedef vector<pl> vpl;
typedef vector<pi> vpi;
typedef map<int, int> mii;
typedef map<string, int> msi;
typedef map<int, string> mis;


#define mp make_pair
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define readc(x) char x; cin >> x
#define reads(x) string x; cin >> x
#define readi(x) int x; cin >> x
#define read2i(x, y) readi(x); readi(y)
#define readl(x) LL x; cin >> x
#define read2l(x, y) readl(x); readl(y)
#define len(v) (int)v.size()
#define SIZE(v) (int)v.size()
#define all(x) x.begin(), x.end()
#define SORT(v) sort(all(v))
#define loop(i,s,e) for(int i=s;i<e;++i)
#define rloop(i,s,e) for(int i=s;i>=e;--i)
#define foreach(a, b) for (auto&(a) : (b))
#define MAX(a, b) a = max(a, b)
#define MIN(a, b) a = min(a, b)
#define MODULO 1000000007
#define modsum(a,b) a = (a + b) % MODULO
#define ps cout << endl      
#define INF LLONG_MAX
#define print(var)    cout << var << endl
#define print2(var1, var2) cout << var1 << " " << var2 << endl
#define print3(var1, var2, var3) cout << var1 << " " << var2 << " " << var3 << endl
#define printr(var) cout << var << endl; return
#define print2r(var1, var2) cout << var1 << " " << var2 << endl; return
#define print3r(var1, var2, var3) cout << var1 << " " << var2 << " " << var3 << endl; return
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << ", " << #y << "=" << y << endl
#define deb3(x, y, z) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl

/*
struct Interval {
    int l, r;
    
    bool operator<(const Interval& other) const {
        return l < other.l || (l == other.l && r > other.r);
    }
    
    bool operator==(const Interval& other) const {
        return l == other.l && r == other.r;
    }
};
*/

/*
bool sortbyfirst(const pi &a,const pair<int,int> &b)
{
    if(a.first != b.first)
        return a.first < b.first;
    return (a.second < b.second);
}
*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    
    //vector<pi> vect;
    vi vec;
    
    loop(i,0,N){
        int num;
        cin>>num;
        //vect.push_back(make_pair(num, i));
    }

    //sort(vect.begin(), vect.end(), sortbyfirst);
    sort(all(vec));

    /*
    for (int i = 0; i < N; ++i) {
        cout << vec[i] << endl; 
    }
    */

    int out = 0;

    cout << out;
    return 0;
}