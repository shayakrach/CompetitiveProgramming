#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> vec;
    for (int i = 1; i <= n; ++i) {
        int num;
        cin >> num;
        vec.push_back(num);
    }
    
    sort(vec.rbegin(), vec.rend());
    
    long sum = 0; 
    int turn = 0; 
    
    for (int i = 0; i < n; ++i) {
        if(turn == 0){
            sum += vec[i];
            if((n - 1 - i) % 2 == 1 && vec[i+1] < 0){
                turn = 1;
            }
        }
        else{
         turn = 0;   
        }
    }
    
    cout << sum;
    
    return 0;
}