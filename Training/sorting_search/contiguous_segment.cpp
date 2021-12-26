#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pi;
typedef long long LL;

struct Interval {
    int l, r;
    
    bool operator<(const Interval& other) const {
        return l < other.l || (l == other.l && r > other.r);
    }
    
    bool operator==(const Interval& other) const {
        return l == other.l && r == other.r;
    }
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<Interval> intervals;
    for (int i = 0; i < N; ++i) {
        Interval interval;
        cin >> interval.l >> interval.r;
        intervals.push_back(interval);
    }

    sort(intervals.begin(), intervals.end());

    LL out = 0;
    
    for(int i=1; i<N; i++)
    {   
        
        int min_inter = min(i, N-i);
        int diff = intervals[i].l -intervals[i-1].r; 
        out += min_inter*diff; 
    }
    
    cout << out;
    return 0;
}