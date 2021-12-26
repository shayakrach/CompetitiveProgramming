#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pi;
typedef long long LL;

#define int int64_t
#define loop(i,s,e) for(int i=s;i<e;++i)
#define pb push_back
#define all(x) x.begin(), x.end()
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