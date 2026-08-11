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
int a[N];
multiset<int> st[4 * N];
//Gobal Variable 󰅠 󰆧
int t;
bool flag = false;  
//Function 󰊕
multiset<int> Megre(multiset<int> a, multiset<int> b){
    multiset<int> t = a;
    for(auto x : b) t.insert(x);
    return t;
}
void build(int id, int l, int r){
    if(l == r){
        st[id].insert(a[l]);
        return;
    }
    int mid = l + r >> 1;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    st[id] = Megre(st[id * 2], st[id * 2 + 1]);
}
void update(int id, int l, int r, int i, int old, int val){
    if(i < l || i > r){
        return;
    } if(l == r){
        st[id].clear();
        st[id].insert(val);
        return;
    }
    int mid = l + r >> 1;
    update(id * 2, l, mid, i, old, val);
    update(id * 2, mid + 1, r, i, old, val);
    st[id].erase(st[id].find(old));
    st[id].insert(val);
}
int get(int id, int l, int r, int u, int v, int val){
    if(u > r || v < l){
        return INF;
    } if(u <= l && v >= r){
        auto it = st[id].lower_bound(val);
        if(it != st[id].end()) return *it;
        return INF;
    }
    int mid = l + r >> 1;
    int get1 = get(id * 2, l, mid, u, v, val);
    int get2 = get(id * 2 + 1, mid + 1, r, u, v, val);
    return min(get1, get2);
}
//↓ Include solution here ↓
void solve(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);
    while(m--){
        int t;
        cin >> t;
        if(t == 1){
            int i, val;
            cin >> i >> val;
            update(1, 1, n, i, a[i], val);
        }
        else{
            int u, v, k;
            cin >> u >> v >> k;
            int ans = get(1, 1, n, u, v, k);
            if(ans == INF) cout << -1 << endl;
            else cout << ans << endl;
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
