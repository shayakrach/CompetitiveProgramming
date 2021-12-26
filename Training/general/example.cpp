#include <cmath>

#include <cstdio>

#include <vector>

#include <iostream>

#include <algorithm>

#define int int64_t

using namespace std;

int32_t main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   

    int c,h,o; cin>>c>>h>>o;

    if (h%2) return cout<<"Error"<<endl,0;

    h/=2;

    int v = 2*c+h-o;

    if (v%12) return cout<<"Error"<<endl,0;

    int z = v/12;

    int x = h-6*z, y=c-6*z;

    if (x<0 || y<0 || z<0) return cout<<"Error"<<endl,0;

    cout<<x<<" "<<y<<" "<<z<<endl;

    

    return 0;

}