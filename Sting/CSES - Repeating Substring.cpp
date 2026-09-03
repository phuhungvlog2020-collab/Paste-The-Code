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
const int N = 6e5 + 5, mod = 1e9 + 7, INF = 2e18 + 5, base = 311, base2 = 367, mod2 = 1e9 + 9;
//Global Array 󰅠 󰅪
int n;
string s;
int h[N], h2[N], Pow[N], Pow2[N];
pair<pair<int, int>, int> subs[N];
//Gobal Variable 󰅠 󰆧 
//Function 󰊕
inline int getH(int l, int r) {
    return (h[r] - (h[l - 1] * Pow[r - l + 1]) % mod + mod) % mod;
}
inline int getH2(int l, int r) {
    return (h2[r] - (h2[l - 1] * Pow2[r - l + 1]) % mod2 + mod2) % mod2;
}
int check(int len) {
    if (len == 0) return -1;
    int sz = 0;
    for (int i = 1; i <= n - len + 1; ++i) {
        subs[sz++] = {{getH(i, i + len - 1), getH2(i, i + len - 1)}, i - 1};
    }

    sort(subs, subs + sz);

    for (int i = 1; i < sz; ++i) {
        if (subs[i].fi == subs[i - 1].fi) {
            return subs[i].se;
        }
    }
    return -1;
}
//↓ Include solution here ↓
void solve(int tc){
    cin >> s;
    n = s.size();
    Pow[0] = 1;
    Pow2[0] = 1;
    for (int i = 0; i < n; ++i) {
        h[i + 1] = (h[i] * base + (s[i] - 'a' + 1)) % mod;
        h2[i + 1] = (h2[i] * base2 + (s[i] - 'a' + 1)) % mod2;
        Pow[i + 1] = (Pow[i] * base) % mod;
        Pow2[i + 1] = (Pow2[i] * base2) % mod2;
    }
    int l = 1, r = n - 1;
    int len = 0, pos = -1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        int p = check(mid);
        if (p != -1) {
            len = mid;
            pos = p;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    if (len == 0 || pos == -1) {
        cout << -1 << endl;
    } else {
        for (int i = pos; i < pos + len; ++i) {
            cout << s[i];
        }
        cout << endl;
    }
}
//↑ Include solution here ↑
//Deep function ↓ 󰒓 󰊕
signed main(){
    if (fopen("in.inp", "r")) 
        freopen("out.out", "w", stdout), freopen("in.inp", "r", stdin);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int tc = 1; //cin >> tc;
    for(int i = 1; i <= tc; i++) solve(i);
}
//This is the minimal version of Main.cpp
//Cleaner, more good looking, but miss some extensions
//If the problem need some functions, should use the classic Main.cpp
//Made by Emais, or maybe Iamdog(95 || _Hungler), l zbbh rhuqa
