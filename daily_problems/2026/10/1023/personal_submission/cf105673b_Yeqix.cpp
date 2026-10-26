#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;
namespace rgs = ranges;

void solve() {
    i64 n, k;
    cin >> n >> k;
    vector<i64> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    i64 ans = k;
    auto dfs = [&](this auto&& dfs, i64 u, i64 cnt, i64 res) -> void {
        if (res + a[u] < 0) {
            return;
        }
        ans = max(ans, res + a[u]);
        if (u + cnt > n) {
            return;
        }
        dfs(u + cnt, cnt + 1, a[u] + res);
    };

    for (int i = 1; i <= n; i++) {
        dfs(i, 1, k);
    }

    cout << ans << "\n";
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