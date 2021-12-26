#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<pair<string, int>> words;
    for (int i = 1; i <= n; ++i) {
        string s;
        cin >> s;
        words.push_back(make_pair(s, i));
    }
    
    sort(words.begin(), words.end());
    for (auto& word : words) {
        cout << word.second << " ";
    }
}