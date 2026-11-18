#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define pb push_back
#define ll long long
const int N = 3e5 + 5, mod = 1e9 + 7, INF = 2e18 + 5, base = 311, base2 = 367, mod2 = 1e9 + 9;
const int os = 3e5;
int a[N];
int cnt[2 * N];
int cnt2[2 * N];
void solve() {
    int n;
    cin >> n;
    for(int j = 1; j <= n; j++){
        string s;
        cin >> s;
        int val = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                val++;
            }
            else val--;
            if(val < 0){
                break;
            }
        }
        // cout << val << " ";
        if(val >= 0){
            cnt[val]++;
            a[j] = val;
        }
        else{
            val = 0;
            for(int i = s.size() - 1; i >= 0; i--){
                if(s[i] == ')'){
                    val++;
                }
                else val--;
                if(val < 0){
                    break;
                }
            }
            // cout << val;
            if(val >= 0){
                cnt2[val]++;
                a[j] = -val;
            }
            else{
                a[j] = -INF;
            }
        }
        // cout << endl;
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(a[i] == -INF) continue;
        else{
            if(a[i] > 0){
                ans += cnt2[a[i]];
            }
            else{
                ans += cnt[a[i]];
            }
        }
    }
    cout << ans << endl;
}
signed main() {
    if (fopen("in.inp", "r")) 
        freopen("out.out", "w", stdout), freopen("in.inp", "r", stdin);
    // ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int tc = 1; //cin >> tc;
    for (int i = 1; i <= tc; i++) solve();
}
// Top Security script document of Royal Nation, Royal Nation's 'Prince' Long Rifle M1886 Information
// Collected by Golden Empire hosted by The Queen, operation "Sono cane" status: "SUCCESS", 31/6/1939
