#include <bits/stdc++.h>

#define int int64_t

#define vi vector<int>

#define vb vector<bool>

#define ii pair<int,int>

#define vvi vector<vi>

#define vvvi vector<vvi>

#define vvvvi vector<vvvi>

#define vvvvvi vector<vvvvi>

#define vvb vector<vb>

#define vii vector<ii>

#define s first

#define a second

#define pb push_back

#define mp make_pair

#define loop(i,s,e) for(int i=s;i<e;i++)

#define chkmax(a,b) a = max((a),(b))

#define chkmin(a,b) a=min(a,b)

#define all(x) x.begin(),x.end()

using namespace std;

const int INF = 1e18;

const int T = 50;



void solve(){

    int n; cin>>n;

    vector<vii> ends(T);

    loop(i,0,n) {

        int start,end,am; cin>>start>>end>>am;

        ends[end].pb({start,am});

    }

    vi dp(T+1,0);

    loop(i,0,T){

        for(auto& e:ends[i]){

            chkmax(dp[i],dp[e.s]+e.a);

        }

        dp[i+1] = dp[i];

    }

    cout<<dp[T]<<endl;

}

int32_t main(){

    ios_base::sync_with_stdio(false);

    //int t; cin>>t;

    //loop(i,0,t) solve();

    if(1){
        cout << "YAAA";
    }

    return 0;

}

