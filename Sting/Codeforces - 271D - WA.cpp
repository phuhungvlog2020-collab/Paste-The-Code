#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(),x.end()
const int N = 6e5 + 5, mod = 1e9 + 7, INF = 2e18 + 5, base = 311, base2 = 367, mod2 = 1e9 + 9;
string s;
string b;
int Pow[N], Pow2[N], h[N], h2[N];
bool bad[30];
int pref[N];
int k;
int lens, lenb;
int ans;
map<int, bool> vs;
map<int, bool> vs2;
void prepare(){
    Pow[1] = 1, Pow2[1] = 1;
    for(int i = 1; i <= lens; i++) Pow[i] = (Pow[i - 1] * base) % mod;
    for(int i = 1; i <= lens; i++) Pow2[i] = (Pow2[i - 1] * base2) % mod2;
    for(int i = 1; i <= lens; i++) h[i] = (h[i - 1] * base + (s[i] - 'a' + 1)) % mod;
    for(int i = 1; i <= lens; i++) h2[i] = (h2[i - 1] * base2 + (s[i] - 'a' + 1)) % mod2;
}
int getH(int l, int r){
    return (h[r] - h[l - 1] * Pow[r - l + 1] + mod * mod) % mod;
}
int getH2(int l, int r){
    return (h2[r] - h2[l - 1] * Pow2[r - l + 1] + mod2 * mod2) % mod2;
}
void solve(int tc){
    cin >> s;
    cin >> b;
    cin >> k;
    lenb = b.size();
    lens = s.size();
    s = "&" + s;
    prepare();
    for(int i = 0; i < lenb; i++) {
        if(b[i] == '0'){
            bad[i + 1] = 1;
        }
        // cout << bad[i]
    }
    for(int i = 1; i <= lens; i++){
        pref[i] = pref[i - 1] + bad[s[i] - 'a' + 1];
    }
    for(int i = 1; i <= lens; i++){
        for(int j = i; j <= lens; j++){
            int hash = getH(i, j);
            int hash2 = getH2(i, j);
            cout << i << " " << j << " " << hash << " " << hash2 << " ";
            if(pref[j] - pref[i - 1] <= k && (!vs[hash] || !vs2[hash2])){
                cout << "CHOSE";
                vs[hash] = 1;
                vs2[hash2] = 1;
                ans++;
            }
            cout << endl;
        }
    }
    cout << ans << endl;
}
signed main(){
    if (fopen("in.inp", "r")) 
        freopen("out.out", "w", stdout), freopen("in.inp", "r", stdin);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int tc = 1; //cin >> tc;
    for(int i = 1; i <= tc; i++) solve(i);
}
//This is a fucking super minimize version of Main.cpp
//Lose a lot of function, no clean, no fast code, but at least can use
//If the problem need some functions, should use the classic Main.cpp
//Made by Emais, or maybe Iamdog(95 || _Hungler), 
