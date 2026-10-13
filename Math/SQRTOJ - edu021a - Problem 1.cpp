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
void solve() {
    int n;
    cin >> n;
    if(n % 2 != 0){
        cout << n / 2 << " " << n / 2 + 1 << endl;
    }
    else if(n % 4 == 0){
        cout << n / 2 - 1 << " " << n / 2 + 1 << endl;
    }
    else{
        cout << n / 2 - 2 << " " << n / 2 + 2 << endl;
    }
}
signed main() {
    if (fopen("in.inp", "r")) 
        freopen("out.out", "w", stdout), freopen("in.inp", "r", stdin);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int tc = 1; cin >> tc;
    for (int i = 1; i <= tc; i++) solve();
}
// Top Security script document of Royal Nation, Royal Nation's 'Prince' Long Rifle M1886 Information
// Collected by Golden Empire hosted by The Queen, operation "Sono cane" status: "SUCCESS", 31/6/1939
