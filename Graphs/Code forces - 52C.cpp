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
int st[N * 4];
int lz[N * 4];
//Gobal Variable 󰅠 󰆧
bool flag = false;  
//Function 󰊕
void build(int id, int l, int r) {
    if (l == r) {
        st[id] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(2 * id, l, mid);
    build(2 * id + 1, mid + 1, r);
    st[id] = min(st[2 * id], st[2 * id + 1]);
}
void push(int id) {
    st[2 * id] += lz[id];
    lz[2 * id] += lz[id];
    st[2 * id + 1] += lz[id];
    lz[2 * id + 1] += lz[id];
    lz[id] = 0;
}
void update(int id, int l, int r, int u, int v, int val) {
    if (u > r || v < l) return;
    if (u <= l && r <= v) {
        st[id] += val;
        lz[id] += val;
        return;
    }
    push(id);
    int mid = (l + r) / 2;
    update(2 * id, l, mid, u, v, val);
    update(2 * id + 1, mid + 1, r, u, v, val);
    st[id] = min(st[2 * id], st[2 * id + 1]);
}
int get(int id, int l, int r, int u, int v) {
    if (u > r || v < l) return INF;
    if (u <= l && r <= v) return st[id];
    push(id);
    int mid = (l + r) / 2;
    return min(get(2 * id, l, mid, u, v), get(2 * id + 1, mid + 1, r, u, v));
}
//↓ Include solution here ↓
void solve(){
    int n, q;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    cin >> q;
    build(1, 0, n - 1);
    string t;
    getline(cin, t); 
    while(q--){
        getline(cin, t);
        stringstream ss(t);
        vector<int> nums;
        int val;
        while (ss >> val) nums.pb(val);
        int l = nums[0], r = nums[1];
        if (nums.size() == 2) {
            if (l <= r) {
                cout << get(1, 0, n - 1, l, r) << endl;
            } else {
                cout << min(get(1, 0, n - 1, l, n - 1), get(1, 0, n - 1, 0, r)) << endl;
            }
        } else if (nums.size() == 3) {
            int v = nums[2];
            if (l <= r) {
                update(1, 0, n - 1, l, r, v);
            } else {
                update(1, 0, n - 1, l, n - 1, v);
                update(1, 0, n - 1, 0, r, v);
            }
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
