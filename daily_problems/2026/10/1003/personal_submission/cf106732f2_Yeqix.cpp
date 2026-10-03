#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;
namespace rgs = ranges;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<i64> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<vector<array<i64, 2>>> edge(n + 1);
    for (int i = 1; i < n; i++) {
        i64 u, v, w;
        cin >> u >> v >> w;
        edge[u].push_back({v, w});
        edge[v].push_back({u, w});
    }

    vector<i64> dp(n + 1), ndp(n + 1), down(n + 1);
    auto f = [&](i64 v, i64 w) -> i64 { return down[v] - w * 2; };
    auto g = [&](i64 v, i64 w) -> i64 { return max({w, w + ndp[v], w * 2 - down[v]}); };

    auto dfs = [&](this auto&& dfs, int u, int fa) -> void {
        ndp[u] = dp[u] = max<i64>(0, -a[u]);
        down[u] = a[u];
        if (edge[u].size() == 1 && u != 1) {
            return;
        }

        vector<array<i64, 2>> res;
        for (const auto& [v, w] : edge[u]) {
            if (v == fa) {
                continue;
            }
            dfs(v, u);
            down[u] += down[v] - w * 2;
            res.push_back({v, w});
        }

        int len = res.size();
        if (len) {
            sort(res.begin(), res.end(), [&](auto x, auto y) {
                i64 val1 = f(x[0], x[1]), val2 = f(y[0], y[1]);
                if (val1 >= 0 && val2 >= 0) {
                    return g(x[0], x[1]) < g(y[0], y[1]);
                }
                if (val1 <= 0 && val2 <= 0) {
                    return g(x[0], x[1]) + val1 > g(y[0], y[1]) + val2;
                }
                return val1 > val2;
            });

            i64 all = 0;
            vector<i64> suf(len + 1);
            for (int i = len - 1; i >= 0; i--) {
                auto [v, w] = res[i];
                all += f(v, w);
                suf[i] = max(suf[i + 1] - f(v, w), g(v, w));
            }
            ndp[u] = max<i64>(0, ndp[u] + max<i64>(0, suf[0] - max<i64>(0, a[u])));

            i64 ans = 1e18;
            i64 st = 0, sum = 0;
            for (int i = 0; i < len; i++) {
                auto [v, w] = res[i];
                i64 need = max(suf[i + 1] - sum, st);
                need = max(need, max(w, dp[v] + w) - all + f(v, w));
                ans = min(ans, need);

                st = max(st, g(v, w) - sum);
                sum += f(v, w);
            }

            dp[u] = max<i64>(0, dp[u] + ans - max<i64>(0, a[u]));
        }
    };
    dfs(1, 0);

    cout << dp[1];
    return 0;
}