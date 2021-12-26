#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <cstdio>
#include <list>

using namespace std;

typedef long long LL;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<LL> vl;
typedef vector<vl> vvl;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pi;

#define SIZE(v) (int)v.size()
#define SORT(v) sort(all(v))
#define loop(i,s,e) for(int i=s;i<e;++i)
#define rloop(i,s,e) for(int i=s;i>=e;--i)
#define pb push_back
#define mp make_pair
#define pf push_front
#define all(x) x.begin(), x.end()
#define foreach(a, b) for (auto&(a) : (b))
#define MAX(a, b) a = max(a, b)
#define MIN(a, b) a = min(a, b)
#define MODULO 1000000007
#define modsum(a,b) a = (a + b) % MODULO
#define ps cout << endl       


int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int gcdExtended(int a, int b, int *x, int *y)
{
    if (a == 0)
    {
        *x = 0;
        *y = 1;
        return b;
    }
 
    int x1, y1; // To store results of recursive call
    int gcd = gcdExtended(b%a, a, &x1, &y1);
 
    // Update x and y using results of
    // recursive call
    *x = y1 - (b/a) * x1;
    *y = x1;
 
    return gcd;
}

// Returns modulo inverse of a
// with respect to m using
// extended Euclid Algorithm.
int inv(int a, int m)
{
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;
 
    if (m == 1)
        return 0;
 
    // Apply extended Euclid Algorithm
    while (a > 1) {
        // q is quotient
        q = a / m;
 
        t = m;
 
        // m is remainder now, process same as
        // euclid's algo
        m = a % m, a = t;
 
        t = x0;
 
        x0 = x1 - q * x0;
 
        x1 = t;
    }
 
    // Make x1 positive
    if (x1 < 0)
        x1 += m0;
 
    return x1;
}

// k is size of num[] and rem[]. Returns the smallest
// number x such that:
// x % num[0] = rem[0],
// x % num[1] = rem[1],
// ..................
// x % num[k-2] = rem[k-1]
// Assumption: Numbers in num[] are pairwise coprime
// (gcd for every pair is 1)
int findMinX(int num[], int rem[], int k)
{
    // Compute product of all numbers
    int prod = 1;
    for (int i = 0; i < k; i++)
        prod *= num[i];
 
    // Initialize result
    int result = 0;
 
    // Apply above formula
    for (int i = 0; i < k; i++) {
        int pp = prod / num[i];
        result += rem[i] * inv(pp, num[i]) * pp;
    }
 
    return result % prod;
}

unsigned long int binomialCoeff(unsigned int n, unsigned int k)
{
    unsigned long int res = 1;
 
    // Since C(n, k) = C(n, n-k)
    if (k > n - k)
        k = n - k;
 
    // Calculate value of [n*(n-1)*---*(n-k+1)] /
    // [k*(k-1)*---*1]
    for (int i = 0; i < k; ++i) {
        res *= (n - i);
        res /= (i + 1);
    }
 
    return res;
}

unsigned long int catalan(unsigned int n)
{
    // Calculate value of 2nCn
    unsigned long int c = binomialCoeff(2 * n, n);
 
    // return 2nCn/(n+1)
    return c / (n + 1);
}

LL mod_exp(LL a, LL b, LL mod)
{
    if(b ==0) return 1;
    
    LL c = mod_exp(a, b/2, mod);

    LL out = (c * c) % mod;
    
    return (b % 2) ? (a * out) % mod : out; 
}

double doubleRand() {
  return (double(rand()) / (double(RAND_MAX)) * 0.8) -0.4;
}


void primeFactors(int n)
{
    // Print the number of 2s that divide n
    while (n % 2 == 0)
    {
        cout << 2 << " ";
        n = n/2;
    }
 
    // n must be odd at this point. So we can skip
    // one element (Note i = i +2)
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        // While i divides n, print i and divide n
        while (n % i == 0)
        {
            cout << i << " ";
            n = n/i;
        }
    }
 
    // This condition is to handle the case when n
    // is a prime number greater than 2
    if (n > 2)
        cout << n << " ";
}

vi getPrimes(int n){

    set<int> s;
    vi p;
    
    for(int i=2;i*i<=n;++i){

        if (n%i==0){
            s.insert(i);
            s.insert(n/i);
        }
    }   

    for(auto i:s){

        if(n%i==0) p.pb(i);

        while(n%i==0) n/=i;
    }

    if (n>1) p.pb(n);

    return p;
}

vi getDivisors(int n)
{
    vi v;
    // Note that this loop runs till square root
    for (int i=1; i<=sqrt(n); i++)
    {
        if (n%i == 0)
        {
            // If divisors are equal, print only one
            v.pb(i);
            if (n/i != i)
                v.pb(n/i);
        }
    }
    
    SORT(v);
    
    return v;
}

void read(vi &v, int n)
{
    loop(i,0,n)
    {
        int num;
        cin>>num;
        v.pb(num);
    }
}

/*
void solve(vi &vec, int i, int num){
    while(num>0){
        MIN(vec[i], vec[i-num%10] + 1);
        num = num/10;
    }
}
*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int q;
    cin >> q;

    vl v;
    read(v,q);

    loop(i, 0, q) v.pb(solve());
    
    loop(i, 0, q) cout << v[i] << endl;
    
    

    return 0;
}