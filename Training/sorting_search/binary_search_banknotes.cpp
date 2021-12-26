#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int dicreasing_binary_search(ll A, ll B, ll S, ll N){
    ll a = 0, b = N, A_Banknotes = -1;
    while (a <= b) {
        A_Banknotes = (a+b)/2;
        ll B_Banknotes = N - A_Banknotes;
        ll curr_S = (A * A_Banknotes) + (B*B_Banknotes);
        if (curr_S == S) {
            break;
        }
        if (curr_S < S) b = A_Banknotes-1;
        else a = A_Banknotes+1;
    }
    
    return a <= b ? A_Banknotes : -1;
}


int increasing_binary_search(ll A, ll B, ll S, ll N){
    ll a = 0, b = N, A_Banknotes=-1;
    while (a <= b) {
        A_Banknotes = (a+b)/2;
        ll B_Banknotes = N - A_Banknotes;
        ll curr_S = (A*A_Banknotes) + (B*B_Banknotes);
        if (curr_S == S) {
            break;
        }
        if (curr_S > S) b = A_Banknotes-1;
        else a = A_Banknotes+1;
    }
    
    return a <= b ? A_Banknotes : -1;
}


int banknotes(int A, int B, int S, int N) {
    int A_Banknotes;
    if(A>B){
       A_Banknotes = increasing_binary_search(A, B, S, N);
    
    }
    else{
       A_Banknotes = dicreasing_binary_search(A, B, S, N);
    }
    
    return A_Banknotes;
}

int main() {
    int A, B, S, N;
    cin >> A >> B >> S >> N;
    cout << banknotes(A, B, S, N) << "\n";
    return 0;
}
