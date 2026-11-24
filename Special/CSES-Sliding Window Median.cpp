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
int n, k, a[N];
multiset<int> lo, hi;
void balance() {
    while (lo.size() > hi.size() + 1) {
        hi.insert(*lo.rbegin());
        lo.erase(prev(lo.end()));
    }
    while (lo.size() < hi.size()) {
        lo.insert(*hi.begin());
        hi.erase(hi.begin());
    }
}
void add(int x) {
    if (lo.empty() || x <= *lo.rbegin()) lo.insert(x);
    else hi.insert(x);
    balance();
}
void del(int x) {
    auto it = lo.find(x);
    if (it != lo.end()) lo.erase(it);
    else hi.erase(hi.find(x));
    balance();
}
void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < k; i++) add(a[i]);
    cout << *lo.rbegin();
    for (int i = k; i < n; i++) {
        add(a[i]);
        del(a[i - k]);
        cout << ' ' << *lo.rbegin();
    }
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
