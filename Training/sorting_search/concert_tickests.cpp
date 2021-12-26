#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n,m;
    cin >> n >> m;

    multiset<int> prices;
    for (int i = 0; i < n; ++i) {
        int price;
        cin >> price;
        prices.insert(price);
    }
    //sort(prices.begin(), prices.end());

    vector<int> max_prices;
    
    for (int i = 0; i < m; ++i) {
        int max_price;
        cin >> max_price;
       
        max_prices.push_back(max_price);
    }
    
    vector<int> true_prices;

    for (int i = 0; i < m; ++i) {
		auto it = prices.upper_bound(max_prices[i]);
        
        if(it != prices.begin()){
            true_prices.push_back(*(--it)); 
            prices.erase(it);
        }
        else{
            true_prices.push_back(-1); 
        }
    }

    for (int i = 0; i < m; ++i) {
        cout << true_prices[i] << endl; 
    }

    return 0; 
}