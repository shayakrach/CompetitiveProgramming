#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n,m,k;
    cin >> n >> m >> k;

    vector<int> applicants;
    vector<int> apartments;
    for (int i = 0; i < n; ++i) {
        int app;
        cin >> app;
        //cout << app << endl;
        applicants.push_back(app);
    }
    for (int i = 0; i < m; ++i) {
        int apa;
        cin >> apa;
        apartments.push_back(apa);
    }

    sort(applicants.begin(), applicants.end());
    sort(apartments.begin(), apartments.end());
    
    int i=0, j=0, pairs=0;
    while(i<n && j<m){
        if(apartments[j] + k < applicants[i])
        {
            j++;
        }
        else if(applicants[i] < apartments[j] - k)
        {
            i++;
        }
        else{
            j++;
            i++;
            pairs++;
        }
    }

    cout << pairs;
    return 0; 
}