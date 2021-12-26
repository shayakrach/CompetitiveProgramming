#include <bits/stdc++.h>
using namespace std;

int largestSquare(const vector<vector<int>>& A) {
    
    int n = (int)A[0].size();
    
    vector<vector<int>> dp (n, vector<int>(n,1));
    
    int max_sq = 1;
    cout << n << "EHYY";
    int i = 1, j = 1, diag = 1; 
    
    while (diag < n)
    {
        if(i==n){
            break;
        }

        if(i == 0 || j == n)
        {
            j = 1;
            i = ++diag;
            continue;
        }
        
        //cout << i << j << "WHY ?? " << endl;
        if(A[i][j] == A[i-1][j-1] && A[i][j] == A[i][j-1] && A[i][j] == A[i-1][j])
        {
            dp[i][j] += min({dp[i-1][j-1], dp[i][j-1],dp[i-1][j]});
            max_sq = max(max_sq, dp[i][j]);
        }
        
        i--;
        j++;
    }
    
     return max_sq;
}
   
int main() {
    int N;
    cin >> N;
    vector<vector<int>> A;
    for (int i = 0; i < N; ++i) {
        vector<int> row;
        for (int j = 0; j < N; ++j) {
            int val;
            cin >> val;
            row.push_back(val);
        }
        A.push_back(row);
    }
    
    cout << largestSquare(A) << "\n";
    return 0;
}
