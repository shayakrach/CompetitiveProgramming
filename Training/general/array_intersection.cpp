#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int n1, n2;
vector<int> first, second;

void read() {
    cin >> n1 >> n2;
    for (int i = 0; i < n1; ++i) {
        int val;
        cin >> val;
        first.push_back(val);
    }
    for (int i = 0; i < n2; ++i) {
        int val;
        cin >> val;
        second.push_back(val);
    }
}

unordered_map<int, int> getMap(vector<int>& elements) {
    unordered_map<int, int> freqMap;
    for (auto element : elements) {
        freqMap[element] += 1;
    }
    return freqMap;
}

vector<int> mapIntersection(unordered_map<int, int>& a, unordered_map<int, int>& b) {
    vector<int> intersection;
    for (auto it : a) {
        int element = it.first;
        int freq = 0;
        if (b.find(element) != b.end()) {
            freq = min(it.second, b[element]);
        }
        for (int i = 0; i < freq; ++i) {
            intersection.push_back(element);
        }
    }
    return intersection;
}

int main() {
    read();
    
    unordered_map<int, int> firstMap = getMap(first);
    unordered_map<int, int> secondMap = getMap(second);
    vector<int> answer = mapIntersection(firstMap, secondMap);
    
    cout << answer.size() << "\n";
    for (int i = 0; i < (int)answer.size(); ++i) {
        cout << answer[i] << " ";
    }
}