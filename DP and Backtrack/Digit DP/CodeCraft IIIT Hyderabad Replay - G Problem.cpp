#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define pb push_back
const int N = (1 << 15) + 5, mod = 1e9 + 7, INF = 2e18 + 5, base = 311, base2 = 367, mod2 = 1e9 + 9;
const int os = 5e4;
int n, k;
int dp[N][20];
int f(int mask, int last){
    // cout << mask << endl;
    if(mask == (1 << n) - 1){
        return 1;
    }
    int &ans = dp[mask][last];
    if(ans != -1){
        return ans;
    }
    ans = 0;
    for(int i = 0; i < n; i++){
        if(mask & (1 << i)) continue;
        if(abs(i - last) > k) continue;
        ans += f(mask | (1 << i), i);
    }
    return ans;
}
int G(int x){
    memset(dp, -1, sizeof(dp));
    int ans = 0;
    for(int i = 0; i < x; i++){
        ans += f(1 << i, i);
    }
    return ans;
}
void solve() {
    cin >> n >> k;
    cout << G(n) << endl;
}
signed main() {
    if (fopen("in.inp", "r")) 
        freopen("out.out", "w", stdout), freopen("in.inp", "r", stdin);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int tc = 1; cin >> tc;
    for (int i = 1; i <= tc; i++) solve();
}
// Top Security script document of Menlonian Ground Forces, WE-30 information document
// Collected by Rasonian Infantry Forces hosted by Rasonian Republic, operation "Я собака" status: "MISSING", ?/?/2030
