#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define pb push_back
const int N = 2e5 + 5, mod = 1e9 + 7, INF = 2e18 + 5, base = 311, base2 = 367, mod2 = 1e9 + 9;
int a, b;
string str;
int btw(int id, int p, bool l, bool s) {
    if (id == (int)str.size()) {
        return s ? 1 : 0;
    }

    int ans = 0;
    int n = l ? 9 : (str[id] - '0');

    for (int i = 0; i <= n; i++) {
        if (s && i == p) continue;

        bool ns = s || (i > 0);
        bool nl = l || (i < n);
        int np = ns ? i : -1;

        ans += btw(id + 1, np, nl, ns);
    }

    return ans;
}
int cnt(int num) {
    if (num < 0) return 0;
    if (num == 0) return 1;
    
    str = to_string(num);
    return btw(0, -1, false, false) + 1; 
}
void solve() {
    cin >> a >> b;
    cout << cnt(b) - cnt(a - 1) << endl;
}
signed main() {
    if (fopen("in.inp", "r")) 
        freopen("out.out", "w", stdout), freopen("in.inp", "r", stdin);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int tc = 1; // cin >> tc;
    for (int i = 1; i <= tc; i++) solve();
}
// This is a fucking super minimize version of Main.cpp
// Lose a lot of function, no clean, no fast code, but at least can use
// If the problem need some functions, should use the classic Main.cpp
// Made by Emais, or maybe Iamdog(95 || _Hungler),
