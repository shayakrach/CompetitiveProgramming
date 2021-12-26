#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n,x;
    cin >> n >> x;

    vector<int> weights;
    for (int i = 0; i < n; ++i) {
        int weight;
        cin >> weight;
        weights.push_back(weight);
    }

    sort(weights.begin(), weights.end());

    int i=0, j=n-1, gondolas=0;
    while(i <= j){
        if(i != j && weights[j] + weights[i] <= x)
        {
            i++;
        }
        gondolas++;
        j--;
    }

    cout << gondolas;
    return 0; 
}