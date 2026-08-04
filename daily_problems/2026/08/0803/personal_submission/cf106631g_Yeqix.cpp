#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<array<i64, 3>> f;
    f.reserve(q << 1);
    for (int i = 0; i < q; i++) {
        int l, r, x, v;
        cin >> l >> r >> x >> v;
        f.push_back({l, x, -v});
        f.push_back({r + 1, x, v});
    }

    vector<i64> ans(n);
    for (int i = 19; i >= 0; i--) {
        for (const auto& [r, x, v] : f) {
            if (r >> i & 1) {
                i64 h = ((x & r) >> i + 1) << i + 1;
                i64 low = x & ((1 << i) - 1);
                ans[h + low] += v << i - (__builtin_popcount(low));
            }
        }
        for (int j = 0; j < n; j++) {
            if (j >> i & 1) {
                ans[j ^ (1 << i)] += ans[j];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}