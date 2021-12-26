   
#include <bits/stdc++.h>
using namespace std;

#include <algorithm>
#include <iostream>
#include <vector>


bool previousPermutation(vector<int>& permutation) {
    vector <bool> exist (permutation.size() + 1, false);
    
    for (auto i = permutation.size() - 1; i > 0; i--){
        exist[permutation[i]] = true; 
            
        if(permutation[i - 1] > permutation[i]){
            
            int first_changed_dig = permutation[i-1] - 1;
            exist[permutation[i - 1]] = true;
            
            // find the first changed digit in the change part
            
            while(!exist[first_changed_dig]){
                first_changed_dig--;
            }
            
            permutation[i-1] = first_changed_dig;
            exist[first_changed_dig] = false;
            
            // order in disending order 
            
            int curr = permutation.size(); 
            
            while(i < permutation.size()){
                if(exist[curr]){
                    permutation[i] = curr;
                    i++;
                }
                
                curr--;
            }
            
            return true;
        }
    }
    
    return false;
}
   
int main() {
    int N;
    cin >> N;
    vector<int> permutation;
    for (int i = 0; i < N; ++i) {
        int val;
        cin >> val;
        permutation.push_back(val);
    }
    if (!previousPermutation(permutation)) {
        cout << "-1\n";
    } else {
        for (auto& val : permutation) {
            cout << val << " ";
        }
    }
    return 0;
}
