#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int lines;
    cin >> lines;
    
    vector<long> out(lines);

    for (int i = 0; i < lines; i++) {
        long t, a, b, c;
        cin >> t; 
        cin >> a; 
        cin >> b; 
        cin >> c;
        
        long x = min({a,b,c});
        long z = max({a,b,c});
        long y = (a+b+c) - (x+z);
                
        if(z>x+y){
            out[i] = min(t, x+y);
        }
        else{
            out[i] = min(t, (x+y+z)/2);
        }
    }  
    
    for (auto& line : out) {
        cout << line << "\n";
    }
    return 0;
}