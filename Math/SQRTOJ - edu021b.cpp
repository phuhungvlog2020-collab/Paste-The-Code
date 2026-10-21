#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define pb push_back
const int N = 1e6 + 5, mod = 1e9 + 7, INF = 2e18 + 5, base = 311, base2 = 367, mod2 = 1e9 + 9;
const int os = 5e4;
int a[N];
int r[N];
int pref[N];
void solve() {
    int n, k, m;
    cin >> n >> k >> m;
    int spc = 0, slc = 0, sm = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        spc += (a[i] / k) + (bool)(a[i] % k != 0);
        sm += a[i];
    }
    for(int i = 1; i <= n; i++){
        r[i] = a[i] % k;
        if(r[i] == 0) r[i] = k;
    }
    sort(r + 1, r + n + 1);
    int i = 1;
    while(i <= n && spc > ((sm / k) + (bool)(sm % k != 0)) && slc + r[i] <= m){
        spc--;
        slc += r[i];
        i++;
    }
    cout << spc << " " << slc << endl;
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
