#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
   
int main() {
    int N;
    cin >> N;
    set<int> s;
    for (int i = 0; i < N; ++i) {
        int number;
        cin >> number;
        s.insert(number);
    }
    
    cout << s.size() << "\n";
    return 0;
}
