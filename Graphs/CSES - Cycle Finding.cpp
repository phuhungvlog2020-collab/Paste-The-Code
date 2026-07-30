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
int p[N];
//Gobal Variable 󰅠 󰆧
bool flag = false;
//Function 󰊕
string nothing(){
    return "nothing";
}
//↓ Include solution here ↓
void solve(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u, v, p;
        cin >> u >> v >> p;
        E.pb({{u, v}, p});
    }
    for(int i = 1; i <= n; i++) d[i] = 0;
    d[1] = 0;
    int start = -1;
    for(int i = 1; i <= n; i++){
        start = -1;
        for(auto e : E){
            int u = e.fi.fi;
            int v = e.fi.se;
            int w = e.se;
            if(d[v] > d[u] + w){
                d[v] = d[u] + w;
                p[v] = u;
                start = v;
            }
        }
    }
    if(start == -1){
        cout << "NO" << endl;
        return;
    }
    else{
        int x = start;
        for(int i = 1; i <= n; i++){
            x = p[x];
        }
        vector<int> ans;
        int i = x;
        while(true){
            ans.pb(i);
            i = p[i];
            if(i == x) break;
        }
        ans.pb(x);
        cout << "YES" << endl;
        reverse(all(ans));
        for(auto a : ans) cout << a << " ";
    }
    
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
