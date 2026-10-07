#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define pb push_back
const int N = 5e6 + 5, mod = 1e9 + 7, INF = 2e18 + 5, base = 311, base2 = 367, mod2 = 1e9 + 9;
string n;
int ln, k = 3;
int x[N];
int dp[105][2][5];
int f(int idx, bool smaller, int cnt){
    if(cnt > k){
        return 0;
    }
    // cout << idx << " " << smaller << " " << cnt << endl;
    if(idx < 0){
        if(cnt <= k) return 1;
        return 0;
    }
    int &memo = dp[idx][smaller][cnt];
    if(memo != -1){
        return memo;
    }
    memo = 0;
    int lim = smaller ? 9 : x[idx];
    for(int i = 0; i <= lim; i++){
        memo += f(idx - 1, smaller || i < lim, cnt + (bool)(i != 0));
    }
    return memo;
}
int G(string X){
    int n = X.size();
    if(n == 1){
        return 2;
    }
    for(int i = 0; i < n; i++){
        x[n - i - 1] = X[i] - '0';
    }
    memset(dp, -1, sizeof(dp));
    return f(X.size() - 1, 0, 0);
}
int F(string X){
    int cnt = 0;
    for(int i = 0; i < X.size(); i++){
        cnt += (bool)(X[i] != '0');
        // cout << i << " " << cnt << endl;
        if(cnt > k){
            return 0;
        }
    }
    return 1;
}
void solve() {
    string a, b;
    cin >> a >> b;
    cout << G(b) - G(a) + F(a) << endl;
    // cout << G(b) << " " << G(a) << " " << F(a) << endl;
    // cout << F(a) << endl;
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
