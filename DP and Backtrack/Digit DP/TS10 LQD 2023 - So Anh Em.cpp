 #include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define pb push_back
const int N = 2e5 + 5, mod = 1e9 + 7, INF = 2e18 + 5, base = 311, base2 = 367, mod2 = 1e9 + 9;
int n, h, l, r;
int x[20], prime[N];
int dp[2][20][200][2000];
void siev(){
    prime[0] = 1;
    prime[1] = 1;
    for(int i = 2; i < N; i++){
        for(int j = i * i; j < N; j += i){
            prime[j] = true;
        }
    }
}
int f(int idx, bool smaller, int sum, int sqsum){
    if(idx < 0){
        if(!prime[sum] && !prime[sqsum]){
            // cout << sum << endl;
            return 1;
        }
        return 0;
    }
    int &memo = dp[smaller][idx][sum][sqsum];
    if(memo != -1){
        return memo;
    }
    memo = 0;
    int lim = smaller ? 9 : x[idx];
    for(int i = 0; i <= lim; i++){
        memo += f(idx - 1, smaller || (i < lim), sum + i, sqsum + i * i);
    }
    return memo;
}
int G(int X){
    if(X <= 0) return 0;
    int n = 0;
    x[n] = 0;
    while(X > 0){
        x[n++] = X % 10;
        X /= 10;
    }
    memset(dp, -1, sizeof(dp));
    return f(n - 1, 0, 0, 0);
}
void solve() {
    siev();
    int l, r;
    cin >> l >> r;
    cout << G(r) - G(l - 1) << endl;
}
signed main() {
    // if (fopen("in.inp", "r")) 
        freopen("ANHEM.out", "w", stdout), freopen("ANHEM.inp", "r", stdin);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int tc = 1; //cin >> tc;
    for (int i = 1; i <= tc; i++) solve();
}
// Top Security script document of Patriots of Democracy, Cancle ICBM Script
// Collected by Platium Five hosted by UNIDB, operation "Ich bin Hund", 29/2/2031
