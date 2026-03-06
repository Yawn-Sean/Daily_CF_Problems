#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {  
    int n; cin >> n;
    vector<array<ll, 3>> g(n);
    ll tot = 0;
    for (int i = 0; i < n; ++i) {
        ll v, t; cin >> v >> t;
        g[i] = {t, v, i};
        tot += v;
    }
    sort(g.begin(), g.end());
    vector<db> ans(n);
    db cur = tot - g[0][1], tim = g[0][0], cur_t = tim;
    ans[g[0][2]] = tim;
    for (int i = 1; i < n; ++i) {
        auto [t, v, idx] = g[i];
        // db p = (t - tim) * v, q = v * tot / cur;
        // // dbg(p); dbg(q);
        // tim += p / q;
        tim += (t - cur_t) * cur / tot;
        cur -= v;
        cur_t = t;
        ans[idx] = tim;
    }
    for (int i = 0; i < n; ++i) cout << ans[i] << '\n';
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
