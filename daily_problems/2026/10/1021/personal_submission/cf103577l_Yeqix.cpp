#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;
namespace rgs = ranges;

constexpr int N = 1e6;
constexpr i64 inf = 1e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<i64> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<vector<int>> edge(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    bitset<N + 1> bt;
    bt[0] = 1;
    for (int i = 1; i <= q; i++) {
        int x;
        cin >> x;
        bt |= (bt << x);
    }

    vector<i64> lst(N + 2);
    lst[N + 1] = inf;
    for (int i = N; i >= 0; i--) {
        if (bt[i]) {
            lst[i] = i;
        } else {
            lst[i] = lst[i + 1];
        }
    }

    auto dp = a;
    auto dfs = [&](this auto&& dfs, int u, int fa) -> void {
        i64 mx = dp[u];
        for (const auto& v : edge[u]) {
            if (v == fa) {
                continue;
            }
            dfs(v, u);
            mx = max(mx, dp[v]);
        }

        if (mx - dp[u] > N) {
            cout << -1;
            exit(0);
        }
        dp[u] += lst[max(0LL, mx - dp[u])];
        if (dp[u] >= inf) {
            cout << -1;
            exit(0);
        }
    };
    dfs(1, 0);

    i64 ans = accumulate(dp.begin(), dp.end(), 0LL);
    cout << ans;
    return 0;
}