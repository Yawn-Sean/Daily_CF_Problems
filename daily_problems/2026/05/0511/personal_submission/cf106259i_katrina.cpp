#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define dbg(x) cerr << #x << " = " << (x) << endl;
#define vdbg(a) cout << #a << " = "; for (auto x : a) cout << x << " "; cout << endl;



void solve() {  
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    bool f = 1;
    for (int i = 1; i < n - 1; ++i) {
        if (a[i] <= a[0] || a[i] <= a[n - 1]) f = 0;
    }
    cout << (f == 1 ? "YES\n" : "NO\n");
}   


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(10);
    
    int T = 1;
    cin >> T;  
    while (T--) solve();
    return 0;
}

