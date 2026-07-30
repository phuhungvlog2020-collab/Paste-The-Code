#include <bits/stdc++.h>
using namespace std;
//Define 󰊕 󰆧
#define int long long
#define endl '\n'
#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(),x.end()
//Const 󰏿
const int N = 1e5 + 5, mod = 1e9 + 7, INF = 2e18 + 5;
//Global Array 󰅠 󰅪
int d[N];
vector<pair<pair<int, int>, int>> E;
vector<int> G[N];
vector<int> reG[N];
int vs1[N];
int vsn[N];
//Gobal Variable 󰅠 󰆧
bool flag = false;
//Function 󰊕
void dfs1(int u){
    vs1[u] = true;
    for(auto v : G[u]) if(!vs1[v]) dfs1(v);
}
void dfsn(int u){
    vsn[u] = true;
    for(auto v : reG[u]) if(!vsn[v]) dfsn(v);
}
//↓ Include solution here ↓
void solve(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u, v, p;
        cin >> u >> v >> p;
        E.pb({{u, v}, p});
        G[u].pb(v);
        reG[v].pb(u);
    }
    dfs1(1); dfsn(n);
    for(int i = 1; i <= n; i++) d[i] = -INF;
    d[1] = 0;
    for(int i = 1; i < n; i++){
        for(auto e : E){
            int u = e.fi.fi;
            int v = e.fi.se;
            int w = e.se;
            if(d[u] != -INF && d[v] < d[u] + w){
                d[v] = d[u] + w;
            }
        }
    }
    for(auto e : E){
        int u = e.fi.fi;
        int v = e.fi.se;
        int w = e.se;
        if(d[u] != -INF && d[v] < d[u] + w){
            if((vs1[u] && vsn[u]) || (vs1[v] && vsn[v])){
                cout << -1 << endl;
                return;
            }
        }
    }
    cout << d[n] << endl;
}
//↑ Include solution here ↑
//Deep function ↓ 󰒓 󰊕
signed main(){
    if (fopen("in.inp", "r")) 
        freopen("out.out", "w", stdout), freopen("in.inp", "r", stdin);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int tc = 1;//cin >> tc;
    while(tc--) solve();
}
//This is the minimal version of Main.cpp
//Cleaner, more good looking, but miss some extensions
//If the problem need some functions, should use the classic Main.cpp
//Made by Emais, or maybe Iamdog(95 || _Hungler), l zbbh rhuqa
