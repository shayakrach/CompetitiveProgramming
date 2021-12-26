#include <iostream>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<pair<int, int>> vec;
    for (int i = 1; i <= n; ++i) {
        int num;
        cin >> num;
        vec.push_back(make_pair(num, 1));
    }
    
    sort(vec.begin(), vec.end());
    
    int max = 1; 
    
    for (int i = 0; i < n; ++i) {
        for (int j = i-1; j >= 0; --j) {
            if(vec[i].first % vec[j].first == 0 && vec[j].second >= vec[i].second){
                vec[i].second = vec[j].second +1;
            }
        }
        
        if(vec[i].second > max){
            max = vec[i].second;
        }
    }
    
    cout << max;
    
    return 0;
}