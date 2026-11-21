#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define pb push_back
const int N = 2e5 + 5, mod = 1e9 + 7, INF = 2e18 + 5, base = 311, base2 = 367, mod2 = 1e9 + 9;
const int os = 5e4;
int n;
int a[N];
int pos[N];
set<int> s;
pair<int, int> getL(int pos) {
    pair<int, int> res = {0, 0};
    auto it = s.lower_bound(pos);
    if (it != s.begin()) {
        --it;
        res.fi = *it;
        if (it != s.begin()) {
            --it;
            res.se = *it; 
        }
    }
    return res;
}
pair<int, int> getR(int pos) {
    pair<int, int> res = {n + 1, n + 1};
    auto it = s.lower_bound(pos);
    if (it != s.end()) {
        res.fi = *it; 
        ++it;
        if (it != s.end()) {
            res.se = *it; 
        }
    }
    return res;
}
void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        pos[a[i]] = i;
    }
    int ans = 0;
    for(int v = n; v >= 1; v--) {
        int idx = pos[v];
        pair<int, int> L = getL(idx);
        pair<int, int> R = getR(idx);
        
        ans += v * (idx - L.fi) * (R.se - R.fi);
        ans += v * (L.fi - L.se) * (R.fi - idx);
        
        s.insert(idx);
    }
    cout << ans << endl;
}  
signed main() {
    if (fopen("in.inp", "r")) 
        freopen("out.out", "w", stdout), freopen("in.inp", "r", stdin);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int tc = 1; //cin >> tc;
    for (int i = 1; i <= tc; i++) solve();
}
// Top Security script document of Menlonian Ground Forces, WE-30 information document
// Collected by Rasonian Infantry Forces hosted by Rasonian Republic, operation "Я собака" status: "MISSING", ?/?/2030
 
