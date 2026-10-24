#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define pb push_back
const int N = 2e5 + 5, mod = 1e9 + 7, INF = 2e18 + 5, base = 311, base2 = 367, mod2 = 1e9 + 9;
const int os = 5e4;
int a[N];
int st[N * 4];
void build(int id, int l, int r){
    if(l == r){
        st[id] = a[l];
        return;
    }
    int mid = l + r >> 1;
    build(2 * id, l, mid);
    build(2 * id + 1, mid + 1, r);
    st[id] = max(st[2 * id], st[2 * id + 1]);
}
int get(int id, int l, int r, int u, int v){
    if(u > r || l > v){
        return -INF;
    }
    if(u <= l && v >= r){
        return st[id];
    }
    int mid = l + r >> 1;
    int get1 = get(id * 2, l, mid, u, v);
    int get2 = get(id * 2 + 1, mid + 1, r, u, v);
    return max(get1, get2);
}
void solve() {
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);
    while(q--){
        int k;
        cin >> k;
        int l = 1, r = 1, sum = 0, fsum = 0, mx = 0;
        while(r <= n && l <= r){
            sum += a[r];
            fsum = sum - (get(1, 1, n, l, r) >> 1);
            if(fsum <= k){
                mx = max(mx, r - l + 1);
                // cout << l << ' ' << r << ' ' << sum << endl;
            }
            else{
                while(l <= r && fsum > k){
                    sum -= a[l];
                    l++;
                    fsum = sum - (get(1, 1, n, l, r) >> 1);
                }
            }
            r++;
        }
        cout << mx << endl;
    }
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
 
