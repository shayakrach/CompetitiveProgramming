#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> a(n), b(m);

    for (int i = 0; i < n; i += 1) {
        cin >> a[i];
    }

    for (int j = 0; j < m; j += 1) {
        cin >> b[j];
    }
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    

    vector<bool> selected(n, false);  // initialise a vector of size n with false

    int indexA = 0;  // current element from vector a
    bool ok = true;  // we got a valid solution

    for (int i = 0; i < (int)b.size(); i += 1) {
        // get first element from a which is bigger than b[i]
        while (indexA < (int)a.size() && a[indexA] <= b[i]) {
            indexA += 1;
        }
        
        // we can't win againts the i'th sorted pokemon from b.
        // abort missions
        if (indexA == (int)a.size()) {
            ok = false;
            break;
        }
    
        selected[indexA] = true;
        // go to next element since this one is selected.
        // We don't want to select an element multiple times.
        indexA += 1;
    }
    
    // no solution
    if (ok == false) {
        cout << "-1" << '\n';
        return 0;
    }

    // compute the sum for unselected elements
    // sum needs to be int64 (long long)
    long long sum = 0;
    for (int i = 0; i < n; i += 1) {
        if (selected[i] == false) {
            sum += a[i];
        }
    }

    cout << sum << '\n';
    return 0;
}