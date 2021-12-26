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