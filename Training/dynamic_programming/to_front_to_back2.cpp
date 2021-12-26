#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> initial_order(n);
    vector<int> position(n);
    for (int i = 0; i < n; i += 1) {
        cin >> initial_order[i];
        initial_order[i] -= 1;
        position[initial_order[i]] = i;
    }

    int best = 0;
    int where = 0;

    for (int i = 0; i < n; i += 1) {
        int current = 1;
        int start = i;
        while (i + 1 != n) {
            if (position[i + 1] < position[i]) {
                break;
            }

            current += 1;
            i += 1;
        }

        if (current > best) {
            best = current;
            where = start;
        }
    }

    cout << n - best << '\n';
    for (int i = where - 1; i >= 0; i -= 1) {
        cout << i + 1 << ' ' << 0 << '\n';
    }

    for (int i = best + where; i < n; i += 1) {
        cout << i + 1<< ' ' << 1 << '\n';
    }
    
    return 0;
}
