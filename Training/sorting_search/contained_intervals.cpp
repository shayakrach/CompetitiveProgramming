   
#include <bits/stdc++.h>
using namespace std;



/*
struct Interval {
    int l, r;
    
    // Sorting is increasing by left end,
    // in case of equality decreasing by right end.
    bool operator<(const Interval& other) const {
        return l < other.l || (l == other.l && r > other.r);
    }
    
    bool operator==(const Interval& other) const {
        return l == other.l && r == other.r;
    }
};
*/


struct Interval {
    int l, r;
};

bool compareIntervalsByLeft(Interval i1, Interval i2)
{
    if(i1.l != i2.l)
        return i1.l > i2.l;
    return i1.r < i2.r;
}

int containedIntervals(vector<Interval>& intervals) {
    
    int last_l = INT_MIN , last_r = INT_MIN, max_r = INT_MIN, contained_intervals = 0;
    bool last_up = false;
    
    sort(intervals.rbegin(), intervals.rend(), compareIntervalsByLeft);
    
    for (auto& interval : intervals) {
        if(last_r == interval.r && last_l == interval.l && !last_up)
                contained_intervals++;
        
        if(interval.r <= max_r){
            last_up = true;
            contained_intervals++;
        }
        else{
            last_up = false;
        }
        
        max_r = max(interval.r, max_r);
        last_r = interval.r;
        last_l = interval.l;
    }
    
    return contained_intervals;
}
   
int main() {
    int N;
    cin >> N;
    vector<Interval> intervals;
    for (int i = 0; i < N; ++i) {
        Interval interval;
        cin >> interval.l >> interval.r;
        intervals.push_back(interval);
    }
    
    cout << containedIntervals(intervals) << "\n";
    return 0;
}
