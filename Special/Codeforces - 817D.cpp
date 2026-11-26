#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define pb push_back
#define pf push_front
const int N = 1e6 + 5, mod = 1e9 + 7, INF = 2e18 + 5, base = 311, base2 = 367, mod2 = 1e9 + 9;
const int os = 5e4;
int n;
int a[N];
pair<int, int> mn[N], mx[N];
void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    stack<int> st;
    for(int i = 1; i <= n; i++){
        while(!st.empty() && (a[st.top()] > a[i])){
            st.pop();
            if(st.empty()){
                mn[i].fi = 0; 
            }
        }
        if(!st.empty()){
            mn[i].fi = st.top();
        }
        st.push(i);
    }
    while (!st.empty()) {
        st.pop();
    }
    for(int i = n; i >= 1; i--){
        while(!st.empty() && (a[st.top()] >= a[i])){
            st.pop();
            if(st.empty()){
                mn[i].se = n + 1;
            }
        }
        if(!st.empty()){
            mn[i].se = st.top();
        }
        else{
            mn[i].se = n + 1;
        }
        st.push(i);
    }
    while (!st.empty()) {
        st.pop();
    }
    for(int i = 1; i <= n; i++){
        while(!st.empty() && (a[st.top()] < a[i])){
            st.pop();
            if(st.empty()){
                mx[i].fi = 0;
            }
        }
        if(!st.empty()){
            mx[i].fi = st.top();
        }
        st.push(i);
    }
    while (!st.empty()) {
        st.pop();
    }
    for(int i = n; i >= 1; i--){
        while(!st.empty() && (a[st.top()] <= a[i])){
            st.pop();
            if(st.empty()){
                mx[i].se = n + 1;
            }
        }
        if(!st.empty()){
            mx[i].se = st.top();
        }
        else{
            mx[i].se = n + 1;
        }
        st.push(i);
    }
    // for(int i = 1; i <= n; i++) cout << mn[i].fi << " ";
    // cout << endl;
    // for(int i = 1; i <= n; i++) cout << mn[i].se << " ";
    // cout << endl;
    // for(int i = 1; i <= n; i++) cout << mx[i].fi << " ";
    // cout << endl;
    // for(int i = 1; i <= n; i++) cout << mx[i].se << " ";
    // cout << endl;
    int sum = 0;
    for(int i = 1; i <= n; i++){
        sum += (i - (mx[i].fi + 1) + 1) * ((mx[i].se - 1) - i + 1) * a[i];
        // cout << mx[i].fi << " " << mx[i].se << endl;
    }
    // cout << endl;
    for(int i = 1; i <= n; i++){
        sum -= (i - (mn[i].fi + 1) + 1) * ((mn[i].se - 1) - i + 1) * a[i];
        // cout << mn[i].fi << " " << mn[i].se << endl;
    }
    cout << sum << endl;
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
