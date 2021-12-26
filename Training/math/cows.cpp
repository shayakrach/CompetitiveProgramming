#include <bits/stdc++.h>

#define int int64_t

#define vi vector<int>

#define ii pair<int,int>

#define vb vector<bool>

#define vvi vector<vi>

#define vvvi vector<vvi>

#define vvvvi vector<vvvi>

#define vvvvvi vector<vvvvi>

#define vvb vector<vb>

#define vii vector<ii>

#define vvii vector<vii>

#define x first

#define y second

#define pb push_back

#define mp make_pair

#define loop(i,s,e) for(int i=s;i<e;i++)

#define chkmax(a,b) a = max((a),(b))

#define chkmin(a,b) a=min(a,b)

#define all(x) x.begin(),x.end()

using namespace std;

const int INF = 1e18, MOD=1e9+7;



void add(int& a, int b){

    a = (a+b)%MOD;

}

vvi operator*(const vvi& a,const vvi& b){

    vvi mat(a.size(),vi(b[0].size(),0));

    loop(i,0,a.size()){

        loop(j,0,b[0].size()){

            loop(k,0,b.size()){

                add(mat[i][j], a[i][k] * b[k][j]);

            }

        }

    }

    return mat;

}

vvi identity(int n){

    vvi mat(n,vi(n,0));

    loop(i,0,n) mat[i][i] = 1;

    return mat;

}

vvi power(const vvi& b, int p){

    if (p==0) return identity(b.size());

    vvi mat = power(b,p/2);

    mat = mat * mat;

    if (p&1) mat = mat * b;

    return mat;

}

void print(const vvi& a){

    loop(i,0,a.size()) {loop(j,0,a[i].size()) cout<<a[i][j]<<" "; cout<<endl;}

}

int32_t main(){

    ios_base::sync_with_stdio(false);

    int k,n; cin>>k>>n;

    vii pos(n);

    loop(i,0,n) cin>>pos[i].y>>pos[i].x, pos[i].y--;

    pos.pb({k,4});
    
    n++;

    sort(all(pos));

    vvi dp(4,vi(1,0));
    
    dp[0][0]=1;

    vvi mat(4,vi(4,0));

    loop(i,0,4) mat[i][i]=1;

    loop(i,0,3) mat[i][i+1]=mat[i+1][i]=1;

    int last=1;

    for(int i=0;i<n;){

        int y = pos[i].x;

        dp = power(mat, y - last) * dp;

        vb blocked(5,0);

        while(i<n && pos[i].x==y) blocked[pos[i++].y]=1;

        loop(j,0,4) if (blocked[j]) dp[j][0] = 0;

        last = y;

    }

    cout<<dp[0][0]<<endl;

    return 0;

}