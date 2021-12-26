#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Interval {
    int l, r;
    
    bool operator<(const Interval& other) const {
        return r > other.r || (r == other.r && l < other.l);
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
    
    int num_of_movies = 0, last_movie_end = 0;

    for(auto mov: intervals)
    {
        if(last_movie_end <= mov.l)
        {
            num_of_movies++;
            last_movie_end = mov.r;
        }
    }

    cout << num_of_movies;
    return 0; 
}