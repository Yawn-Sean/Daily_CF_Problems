#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define dbg(x) cerr << #x << " = " << (x) << endl;
#define vdbg(a) cout << #a << " = "; for (auto x : a) cout << x << " "; cout << endl;


void solve() {  
    int m, n, r1, c1, r2, c2; cin >> m >> n >> r1 >> c1 >> r2 >> c2;
    int ans = 0;
    if (r1 != r2) {
        if (abs(r1 - r2) & 1) ans ++;
        else ans += 2;
    }
    if (c1 != c2) {
        if (abs(c1 - c2) & 1) ans++;
        else ans += 2;
    }
    cout << ans << "\n";
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

