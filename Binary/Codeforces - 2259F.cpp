#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define fi first
#define se second
#define all(x) x.begin(),x.end()
const int N = 2500 + 5, mod = 1e9 + 7, INF = 2e18 + 5, base = 311, base2 = 367, mod2 = 1e9 + 9;
void solve(int tc){
    int n; cin >> n;
    vector<int> a(n);
    int c0 = 0, inv = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] == 0) c0++;
        else inv += c0;
    }
    inv = 0;
    int cnt0 = 0;
    for(int i = n - 1; i >= 0; i--){
        if(a[i] == 0) cnt0++;
        else inv += cnt0;
    }

    cout << inv << " ";

    int l = 0, r = n - 1;
    int rem0 = cnt0, rem1 = n - cnt0;

    string s; cin >> s;
    for(char c : s){
        if(inv > 0){
            if(c == '1'){
                while(l < n && a[l] == 0){
                    rem0--;
                    l++;
                }
                if(l < n){
                    inv -= rem0;
                    rem1--;
                    l++;
                }
            } else {
                while(r >= 0 && a[r] == 1){
                    rem1--;
                    r--;
                }
                if(r >= 0){
                    inv -= rem1;
                    rem0--;
                    r--;
                }
            }
            if(inv < 0) inv = 0;
        }
        cout << inv << " ";
    }
    cout << endl;
}
signed main(){
    if (fopen("in.inp", "r")) 
        freopen("out.out", "w", stdout), freopen("in.inp", "r", stdin);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int tc = 1; cin >> tc;
    for(int i = 1; i <= tc; i++) solve(i);
}
//This is a fucking super minimize version of Main.cpp
//Lose a lot of function, no clean, no fast code, but at least can use
//If the problem need some functions, should use the classic Main.cpp
//Made by Emais, or maybe Iamdog(95 || _Hungler),
