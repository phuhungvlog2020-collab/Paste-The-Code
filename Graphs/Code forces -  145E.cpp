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
const int N = 1e6 + 5, mod = 1e9 + 7, INF = 2e18 + 5;
//Global Array 󰅠 󰅪
string a;
struct Node{
    int mx, mx4, mx7, rmx;
} st[N * 4];
bool lz[N * 4];
//Gobal Variable 󰅠 󰆧 
//Function 󰊕
Node Merge(Node a, Node b){
    Node t;
    t.mx = max(a.mx + b.mx7, a.mx4 + b.mx);
    t.mx4 = a.mx4 + b.mx4;
    t.mx7 = a.mx7 + b.mx7;
    t.rmx = max(a.rmx + b.mx4, a.mx7 + b.rmx);
    return t;
}
void build(int id, int l, int r){
    if(l == r){
        if(a[l] == '4'){
            st[id] = {1, 1, 0, 1};
        } else{
            st[id] = {1, 0, 1, 1};
        }
        return;
    }
    int mid = l + r >> 1;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    st[id] = Merge(st[id * 2], st[id * 2 + 1]);
}
void sw(int id){
    swap(st[id].mx4, st[id].mx7);
    swap(st[id].mx, st[id].rmx);
    lz[id] = (lz[id] ? false : true);
}
void push(int id) {
    if (!lz[id]) return;
    sw(id * 2);
    sw(id * 2 + 1);
    lz[id] = false;
}
void update(int id, int l, int r, int u, int v){
    if(u > r || v < l) return;
    if(u <= l && v >= r){
        sw(id);
        return;
    }
    push(id);
    int mid = l + r >> 1;
    update(id * 2, l, mid, u, v);
    update(id * 2 + 1, mid + 1, r, u, v);
    st[id] = Merge(st[id * 2], st[id * 2 + 1]);
}
//↓ Include solution here ↓
void solve(){
    int n, k;
    cin >> n >> k >> a;
    a = "&" + a;
    build(1, 1, n);
    while(k--){
        string t;
        cin >> t;
        if(t[0] == 'c'){
            cout << st[1].mx << endl;
        } else{
            int u, v;
            cin >> u >> v;
            update(1, 1, n, u, v);
        }
    }
}
//↑ Include solution here ↑
//Deep function ↓ 󰒓 󰊕
signed main(){
    if (fopen("in.inp", "r")) 
        freopen("out.out", "w", stdout), freopen("in.inp", "r", stdin);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int tc = 1; //cin >> tc;
    while(tc--) solve();
}
//This is the minimal version of Main.cpp
//Cleaner, more good looking, but miss some extensions
//If the problem need some functions, should use the classic Main.cpp
//Made by Emais, or maybe Iamdog(95 || _Hungler), l zbbh rhuqa
