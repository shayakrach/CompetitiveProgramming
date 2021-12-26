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
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define loop(i,s,e) for(int i=s;i<e;i++)
#define chkmax(a,b) a = max((a),(b))
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;

const int INF = 1e18;
const int MAXF = 101;

void solve(){
    int n; cin>>n;
    map<string,int> mapi;

    vi fs(n);

    loop(i,0,n){
        string name; 
        int f;
        cin>>name>>f;
        mapi[name]=i;
        fs[i]=f;
    }

    int s = mapi["strat"], e = mapi["end"];

//    cout<<"hi"<<endl;

    int m; cin>>m;

    vector<vii> g(n);

    loop(i,0,m){

        string s1,s2; cin>>s1>>s2;

        int a=mapi[s1],b=mapi[s2];

        int w; cin>>w;

        if (w>100) continue;

        g[a].pb({b,w});

        g[b].pb({a,w});

    }

    vector<vi> dist(n,vi(MAXF,INF));

    dist[s][fs[s]] = 0;

    dist[s][0] = 0;

    set<pair<int,ii>> seti;

    loop(i,0,n) loop(f,0,MAXF) seti.insert({dist[i][f],{i,f}});

    while(seti.size()){

        auto tmp = *seti.begin(); seti.erase(seti.begin());

        ii cur = tmp.y;

        int cost  = tmp.x;

        //cout<<"COST"<<cost<<endl;

        if (cost==INF) break;

        if (cur.x==e){

            cout<<cost<<endl;

            return;

        }

        for(auto nei:g[cur.x]){

            int nextF = cur.y-nei.y;

            int nextC = cost + nei.y;

            if (nextF<0) continue;

            if (dist[nei.x][nextF]>nextC ){

                seti.erase({dist[nei.x][nextF],{nei.x,nextF} });

                dist[nei.x][nextF] = nextC;

                seti.insert({dist[nei.x][nextF],{nei.x,nextF} });

            }

            nextF+=fs[nei.x];

            chkmin(nextF, MAXF - 1);

            if (dist[nei.x][nextF]>nextC){

                seti.erase({dist[nei.x][nextF],{nei.x,nextF} });

                dist[nei.x][nextF] = nextC;

                seti.insert({dist[nei.x][nextF],{nei.x,nextF} });

            }

        }

    }

    cout<<"Impossible"<<endl;

    /*int ans=INF;

    loop(f,0,MAXF) chkmin(ans,dist[e][f]);

    if (ans>=INF/2) cout<<"Impossible"<<endl;

    else cout<<ans<<endl;*/

}



int32_t main(){

    ios_base::sync_with_stdio(false);

    int t; cin>>t;

    loop(i,0,t) solve();

    return 0;

}