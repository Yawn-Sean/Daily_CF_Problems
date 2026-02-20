#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using db = double;
#define dbg(x) cerr << #x << " = " << (x) << endl;
#define vdbg(a) cout << #a << " = "; for (auto x : a) cout << x << " "; cout << endl;


const ll INF = 1e12;
void solve() {
    ll n, l, r, k; cin >> n >> l >> r >> k;
    vector<ll> a(n);
    bool f = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (k >= a[i]) f = 1;
    }
    if (f) {
        cout << "-1\n";
        return;
    }
    ll x = a[0];
    for (int i = 1; i < n; ++i) {
        x = lcm(x, a[i]);
        x = min(x, INF);
    }
    // dbg(x);
    ll v = (r - k) / x * x;
    v += k;
    // dbg(v);
    if (v < l || v > r) cout << "-1\n";
    else cout << v << "\n";
}

signed main() {  
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(12);

    int T = 1;
    // cin >> T;  
    while (T--) solve();    
    return 0;
} 
