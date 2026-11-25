#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define pb push_back
#define pf push_front
const int N = 5e5 + 5, mod = 1e9 + 7, INF = 2e18 + 5, base = 311, base2 = 367, mod2 = 1e9 + 9;
const int os = 5e4;
int n;
int a[N], l[N], r[N], dp[N], dp2[N];
deque<int> ans;
void findl(int pos){
    if(pos == 0){
        return;
    }
    for(int i = l[pos] + 1; i <= pos; i++) ans.pf(a[pos]);
    findl(l[pos]);
}
void findr(int pos){
    if(pos == n + 1){
        return;
    }
    for(int i = pos; i <= r[pos] - 1; i++) ans.pb(a[pos]);
    findr(r[pos]);
}
void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    stack<int> st;
    for(int i = 1; i <= n; i++){
        while(!st.empty() && (a[st.top()] > a[i])){
            st.pop();
            if(st.empty()){
                l[i] = 0;
            }
        }
        if(!st.empty()){
            l[i] = st.top();
        }
        st.push(i);
    }
    while (!st.empty()) {
        st.pop();
    }
    for(int i = n; i >= 1; i--){
        while(!st.empty() && (a[st.top()] > a[i])){
            st.pop();
            if(st.empty()){
                r[i] = n + 1;
            }
        }
        if(!st.empty()){
            r[i] = st.top();
        }
        else{
            r[i] = n + 1;
        }
        st.push(i);
    }
    for(int i = 1; i <= n; i++){
        dp[i] += a[i] * (i - (l[i] + 1) + 1);
        dp[i] += dp[l[i]];
    }
    for(int i = n; i >= 1; i--){
        dp2[i] += a[i] * ((r[i] - 1) - i + 1);
        dp2[i] += dp2[r[i]];
    }
    int mx = -1, pos = 0, pos1 = 0, pos2 = 0;
    for(int i = 1; i <= n; i++){
        if(mx < dp[i] + dp2[i] - a[i]){
            mx = dp[i] + dp2[i] - a[i];
            pos = i;
        }
    }
    findl(pos);
    ans.pop_back();
    findr(pos);
    for(auto x : ans) cout << x << " ";
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
