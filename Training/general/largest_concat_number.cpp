#include <bits/stdc++.h>
using namespace std;

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

bool compareString(string s1, string s2)
{
    return (s1 + s2 < s2 + s1);
}

string largestConcat(vector<string>& v) {
    string largest_concat;
    sort(v.rbegin(), v.rend(), compareString);
    
    for(string str:v){
        largest_concat += str; 
    }
    
    if(largest_concat[0] == '0'){
        largest_concat = "0"; 
    }
    
    return largest_concat;
}
   
int main() {
    int N;
    cin >> N;
    vector<string> v;
    for (int i = 0; i < N; ++i) {
        string number;
        cin >> number;
        v.push_back(number);
    }
    
    cout << largestConcat(v) << "\n";
    return 0;
}
