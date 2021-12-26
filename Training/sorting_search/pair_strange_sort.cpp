   
#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Tuple {
    int a, b, c;
};

bool compareTuple_c(Tuple t1, Tuple t2)
{
    if(t1.a != t2.a)
        return t1.a > t2.a;
    if(t1.c != t2.c)
        return t1.c > t2.c;
    return t1.b > t2.b;
}


bool compareTuple(Tuple t1, Tuple t2)
{
    if(t1.a != t2.a)
        return t1.a > t2.a;
    
    return t1.b > t2.b;
}

void add_field(vector<Tuple>& v)
{
    int last_a=-1, last_b=-1, count=0;
    for(auto& tuple : v)
    {
        if(tuple.a == last_a && tuple.b == last_b)
        {
            count++;
            
        }
        else
        {
            count = 0;
        }
        
        last_a = tuple.a;
        last_b = tuple.b;
        tuple.c = count;
    }
}

void strangeSort(vector<Tuple>& v) {
    sort(v.rbegin(), v.rend(), compareTuple);
    add_field(v);
    sort(v.rbegin(), v.rend(), compareTuple_c);
}
   
int main() {
    int n;
    cin >> n;
    vector<Tuple> v(n);
    for (auto& tuple : v) {
        cin >> tuple.a >> tuple.b;
    }
    
    strangeSort(v);
    for (auto& val : v) {
        cout << val.a << " " << val.b << "\n";
    }
    return 0;
}
