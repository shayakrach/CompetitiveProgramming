#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    multiset <int> towers;

    for (int i = 0; i < N; ++i) {
        int cube;
        cin >> cube;
        
        auto it = towers.upper_bound(cube);
        
        if(it != towers.end()){
            towers.erase(it);
        }

        towers.insert(cube);
    }
    
    cout << towers.size() ;
    return 0; 
}