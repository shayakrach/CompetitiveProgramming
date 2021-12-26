#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool sortbyfirst(const pair<int,int> &a,const pair<int,int> &b)
{
    if(a.first != b.first)
        return a.first < b.first;
    return (a.second < b.second);
}

int main() {
    int N;
    cin >> N;
    vector<pair<int, int>> vect;
    
    for(int i =0; i<N; i++){
        int num;
        cin>>num;
        vect.push_back(make_pair(num, i));
    }
    
    sort(vect.begin(), vect.end(), sortbyfirst);
   
    int steps = 0;
    
    for(int i =0; i<N; i++){
        steps = max(steps, vect[i].second - i);
    }

    cout << steps + 1;
    return 0;
}