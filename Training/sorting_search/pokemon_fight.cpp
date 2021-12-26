#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n>> m;
    
    vector<int> alex_pok, ben_pok;
    for (int i = 1; i <= n; ++i) {
        int num;
        cin >> num;
        alex_pok.push_back(num);
    }
    sort(alex_pok.begin(), alex_pok.end());
    
    for (int i = 1; i <= m; ++i) {
        int num;
        cin >> num;
        ben_pok.push_back(num);
    }
    
    sort(ben_pok.begin(), ben_pok.end());
    int64_t sum = 0;
    int i=0,j=0;
    
    while(i<n){
        if(j<m && alex_pok[i] > ben_pok[j]){
            j++;
        }
        else{
            sum += alex_pok[i];
        }
        
        i++;
    }
    
    // All ben_pok where beaten 
    if(j==m){
        cout << sum;
    }
    else{
        cout << -1;
    }
    return 0;
}