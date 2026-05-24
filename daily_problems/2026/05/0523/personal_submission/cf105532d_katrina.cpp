#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define dbg(x) cerr << #x << " = " << (x) << endl;
#define vdbg(a) cout << #a << " = "; for (auto x : a) cout << x << " "; cout << endl;


void solve() {
    int n; cin >> n;
    vector<pair<int, int>> g(n);
    for (int i = 0; i  < n; ++i) {
        int w, h; cin >> w >> h;
        if (w > h) swap(w, h);
        g[i] = {w, h};
    }

    auto check = [&] (int x) -> bool {
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            auto [w, h] = g[i];
            if (h < x) continue;
            sum += w;
            if (sum >= x) return 1;
        }
        return sum >= x;
    };

    int l = 1, r = 1e9, ans = 0;
    while (l <= r) {
        int mid = l + r >> 1;
        if (check(mid)) {
            ans = mid;
            l = mid + 1;
        }   
        else r = mid - 1;
    }
    cout << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(10);

    int T = 1;
    // cin >> T;
    while (T--) solve();
    return 0;
}
