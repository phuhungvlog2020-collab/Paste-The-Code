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
struct Node {
    int max1 = -1, cnt1 = 0;
    int max2 = -1, cnt2 = 0;
} st[4 * N];
//Gobal Variable 󰅠 󰆧
string s;
bool flag = false;  
//Function 󰊕
Node merge(Node a, Node b) {
    vector<pair<int, int>> fq = {{a.max1, a.cnt1}, {a.max2, a.cnt2}, {b.max1, b.cnt1}, {b.max2, b.cnt2}};
    sort(fq.rbegin(), fq.rend());
    Node res;
    for (auto [val, cnt] : fq) {
        if (val == -1) continue;
        if (res.max1 == -1 || res.max1 == val) { res.max1 = val; res.cnt1 += cnt; }
        else if (res.max2 == -1 || res.max2 == val) { res.max2 = val; res.cnt2 += cnt; }
        else break;
    }
    return res;
}
void build(int id, int start, int end) {
    if (start == end) { st[id] = {a[start], 1, -1, 0}; return; }
    int mid = (start + end) / 2;
    build(2 * id, start, mid); build(2 * id + 1, mid + 1, end);
    st[id] = merge(st[2 * id], st[2 * id + 1]);
}
void update(int id, int start, int end, int idx, int val) {
    if (start == end) { st[id] = {val, 1, -1, 0}; return; }
    int mid = (start + end) / 2;
    if (idx <= mid) update(2 * id, start, mid, idx, val);
    else update(2 * id + 1, mid + 1, end, idx, val);
    st[id] = merge(st[2 * id], st[2 * id + 1]);
}
Node get(int id, int start, int end, int l, int r) {
    if (r < start || end < l) return Node();
    if (l <= start && end <= r) return st[id];
    int mid = (start + end) / 2;
    return merge(get(2 * id, start, mid, l, r), get(2 * id + 1, mid + 1, end, l, r));
}
//↓ Include solution here ↓
void solve(){
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);
    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int p, x; cin >> p >> x;
            update(1, 1, n, p, x);
        } else {
            int l, r; cin >> l >> r;
            cout << get(1, 1, n, l, r).cnt2 << endl;
        }
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
