   
#include <bits/stdc++.h>
using namespace std;
   
struct Child {
    string name;
    int team;

    Child(string name="", int team=0) {
        this->name = name;
        this->team = team;
    }
};
bool compareChild(Child c1, Child c2)
{
    return c1.team > c2.team;
}

void sortChildren(vector<Child>& children) {
    stable_sort(children.rbegin(), children.rend(), compareChild);
}

   
int main() {
    int n;
    cin >> n;
    
    vector<Child> children;
    for (int i = 0; i < n; ++i) {
        string name;
        char team;
        cin >> name >> team;
        children.push_back(Child(name, team == 'B' ?  0 : 1));
    }
    
    sortChildren(children);
    
    for (int i = 0; i < n; ++i) {
        cout << children[i].name << "\n";
    }
}
