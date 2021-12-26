#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Interval {
    int l, r;
    
    bool operator<(const Interval& other) const {
        return l > other.l || (l == other.l && r < other.r);
    }
};

int main() {
    int N;
    cin >> N;
    vector<Interval> intervals;
    
    for (int i = 0; i < N; ++i) {
        Interval interval;
        cin >> interval.l >> interval.r;
        intervals.push_back(interval);
    }

    sort(intervals.rbegin(), intervals.rend());
    
    int max_cos = 0, curr_inside=0, last_in=0;

    set <int> exit_cos; 

    while(last_in<N)
    {
        curr_inside++;
        exit_cos.insert(intervals[last_in].r);
        
        while(*exit_cos.begin() <= intervals[last_in].l){
            curr_inside--;
            exit_cos.erase(exit_cos.begin());
        }
        
        last_in++;
        max_cos = max(max_cos, curr_inside);
    }

    cout << max_cos;
    return 0; 
}