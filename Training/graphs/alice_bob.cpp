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
typedef pair<LL, LL> pl;
typedef vector<pl> vpl;
typedef vector<pi> vpi;


#define SIZE(v) (int)v.size()
#define SORT(v) sort(all(v))
#define loop(i,s,e) for(int i=s;i<e;++i)
#define rloop(i,s,e) for(int i=s;i>=e;--i)
#define pb push_back
#define mp make_pair
#define pf push_front
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define foreach(a, b) for (auto&(a) : (b))
#define MAX(a, b) a = max(a, b)
#define MIN(a, b) a = min(a, b)
#define MODULO 1000000007
#define modsum(a,b) a = (a + b) % MODULO
#define ps cout << endl      
#define INF LLONG_MAX
#define print(var)    cout << var << endl
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << ", " << #y << "=" << y << endl
#define deb3(x, y, z) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl

//void DFSUtil(int u, vi adj[], vb &visited);
bool cycleFound;
bool finishPush;
vi cycleVertices;
const int N = 5;
vector<pl> adj1[N], adj2[N];
int adj_mat[N][N] = {};
//int n, m;
map <string, int> wap_map;
LL bobWins;
LL aliceWins;
LL ties;
vi adj[25];

// A utility function to add an edge in an
// undirected graph.
void addEdge(vi adj[], int u, int v)
{
    adj[u].pb(v);
}

void print_score()
{
    if(bobWins > aliceWins)
    {
        cout << "Bob wins, by winning " << bobWins << " game(s) and tying " << ties<< " game(s)" << endl;
        deb(aliceWins);
    }
    else if(aliceWins > bobWins)
    {
        cout << "Alice wins, by winning " << aliceWins << " game(s) and tying " << ties<< " game(s)" << endl;
    }
    else
    {
         cout << "Alice and Bob tie, each winning " << aliceWins << " game(s) and tying " << ties << " game(s)" << endl;
    }
}


void up_win(int v)
{
    int a = v / N;
    int b = v % N;
    
    if(adj_mat[a][b])
    {
        aliceWins++;
    }
    else if(adj_mat[b][a])
    {
        bobWins++;
    }
    else
    {
        ties++;
    }
}

// A utility function to do DFS of graph
// recursively from a given vertex u.
void DFSDirectedCycleUtil(int u, vi adj[], vb &visited,vb &recStack, vi &cycleVertices)
{
    visited[u] = true;
    recStack[u] = true;
    
    for (int i=0; i < SIZE(adj[u]); i++){
        
        //cout << " parent" << parent << " " <<  u + 1 << ": neighbor -> " << adj[u][i] +1 << endl;
        
        if (visited[adj[u][i]] == false)
        {
            DFSDirectedCycleUtil(adj[u][i], adj, visited, recStack, cycleVertices);
        }
        else if(recStack[adj[u][i]])
        {
            cycleFound = true;
            cycleVertices.pb(adj[u][i]);
            //up_win(adj[u][i]);
            cycleVertices.pb(u);
            up_win(u);
            recStack[u] = false;
            return;
        }

        if(cycleFound)
        {
            if(!finishPush) 
            {
                cycleVertices.pb(u);
                up_win(u);
                finishPush = u == cycleVertices[0];
                //cout << "PUSHED -> " << u + 1 <<  endl;
                //if(finishPush) cout << "FINISHED -> " << u + 1 <<  endl;
            }
            //recStack[u] = false;
            return;
        }
    }

    recStack[u] = false;
    
    if(cycleFound)
    {
        if(!finishPush) 
        {
            cycleVertices.pb(u);
            up_win(u);
            finishPush = u == cycleVertices[0];
        }
        return;
    }
}



int DFS(vector<int> adj[], int V, int u)
{
    vector<bool> visited(V, false);
    vb recStack(V, false);
    cycleFound = false;
    finishPush = false;
    vi cycleVertices;
    bobWins = 0;
    aliceWins = 0;
    ties = 0;
    
    //for (int u=0; u<V; u++)
    //
    //if (visited[u] == false)
    
        //SUtil(u, adj, visited);
        //DFSCycleUtil(u, adj, visited, -1);
    DFSDirectedCycleUtil(u, adj, visited, recStack, cycleVertices);
    
    if(cycleFound) return SIZE(cycleVertices) - 1;
    
    return -1;
    
}

void solve()
{
    string AliceShape, BobShape;
    LL n;
    
    cin >> AliceShape >> BobShape;
    cin >> n;


    int u = wap_map[AliceShape]*5 + wap_map[BobShape];
    int cyc_size = DFS(adj, 25, u);
    
    int modd = n % cyc_size;
    
    int cycles = n / cyc_size;

    deb(cyc_size);

    bobWins *= cycles; 
    aliceWins *= cycles;
    ties *= cycles;

    loop(i, 0, modd)
    {
        up_win(u);
        
        u = adj[u][0];
    }
    
    print_score();
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    wap_map.insert({"Rock", 0});
    wap_map.insert({"Paper", 1});
    wap_map.insert({"Scissors", 2});
    wap_map.insert({"Spock", 3});
    wap_map.insert({"Lizard", 4});
    /*
    next[0] = 1;
    next[1] = 2;
    next[2] = 3;
    next[3] = 4;
    next[4] = 0;
    */
    adj_mat[wap_map["Scissors"]][wap_map["Paper"]] = 1;
    adj_mat[wap_map["Paper"]][wap_map["Rock"]] = 1;
    adj_mat[wap_map["Rock"]][wap_map["Lizard"]] = 1;
    adj_mat[wap_map["Lizard"]][wap_map["Spock"]] = 1;
    adj_mat[wap_map["Spock"]][wap_map["Scissors"]] = 1;
    adj_mat[wap_map["Scissors"]][wap_map["Lizard"]] = 1;
    adj_mat[wap_map["Lizard"]][wap_map["Paper"]] = 1;
    adj_mat[wap_map["Paper"]][wap_map["Spock"]] = 1;
    adj_mat[wap_map["Spock"]][wap_map["Rock"]] = 1;

    loop(alice_v, 0, 5)
    {
        loop(bob_v, 0, 5)
        {
            int v = alice_v*5 + bob_v;
            int u_alice = alice_v, u_bob = wap_map["Spock"];
            if(alice_v == bob_v)
            {
                u_alice = (alice_v + 1) % 5;
                if(bob_v == wap_map["Spock"])
                {
                    u_bob = wap_map["Lizard"];
                }
            }
            else if(adj_mat[bob_v][alice_v])
            {
                u_alice = (bob_v + 1) % 5;
                if(bob_v == wap_map["Spock"])
                {
                     u_bob = wap_map["Rock"];
                }
            }
            else
            {
                if(bob_v == wap_map["Spock"])
                {
                    u_bob = wap_map["Paper"];
                }
            }
            
            int u = u_alice*5 + u_bob;
            addEdge(adj, v, u);
            //deb2(v, u);
        }
    }
    
    int test;
    cin >> test;
    while(test--) {
        solve();
    }
    return 0;
}