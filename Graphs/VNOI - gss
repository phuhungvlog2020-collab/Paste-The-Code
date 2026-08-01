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
const int N = 2e5 + 5, mod = 1e9 + 7, INF = 2e18 + 5;
//Global Array 󰅠 󰅪
int a[N];
struct Node{
    int mx, mxl, mxr, sum;
} st[4 * N];
//Gobal Variable 󰅠 󰆧
bool flag = false;
//Function 󰊕
Node Merge(Node a, Node b){
    Node t;
    t.mx = max({a.mx, b.mx, a.mxr + b.mxl});
    t.mxl = max(a.mxl, a.sum + b.mxl);
    t.mxr = max(b.mxr, b.sum + a.mxr);
    t.sum = a.sum + b.sum;
    return t;
}
void build(int id, int l, int r){
    if(l == r){
        st[id] = {a[l], a[l], a[l], a[l]};
        return;
    }
    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    st[id] = Merge(st[id * 2], st[id * 2 + 1]);
}
Node get(int id, int l, int r, int u, int v){
    if(u <= l && v >= r) return st[id];
    int mid = (l + r) / 2;
    if (v <= mid) return get(id * 2, l, mid, u, v);
    if (u > mid) return get(id * 2 + 1, mid + 1, r, u, v);
    Node get1 = get(id * 2, l, mid, u, v);
    Node get2 = get(id * 2 + 1, mid + 1, r, u, v);
    return Merge(get1, get2);
}
//↓ Include solution here ↓
void solve(){
    int n, q;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    cin >> q;
    build(1, 1, n);
    while(q--){
        int u, v;
        cin >> u >> v;
        cout << get(1, 1, n, u, v).mx << endl;
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
