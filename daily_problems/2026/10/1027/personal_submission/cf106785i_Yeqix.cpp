#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;
namespace rgs = ranges;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> edge(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    vector<int> dep(n + 1), up(n + 1);
    auto dfs = [&](this auto&& dfs, int u, int fa) -> void {
        up[u] = dep[u] = dep[fa] + 1;
        for (const auto& v : edge[u]) {
            if (v == fa) {
                continue;
            }
            dfs(v, u);
            up[u] = max(up[u], up[v]);
        }
    };
    dfs(k, 0);

    vector<int> mx;
    for (const auto& v : edge[k]) {
        mx.push_back(up[v]);
    }

    rgs::sort(mx, greater<int>());

    while (mx.size() < 2) {
        mx.push_back(0);
    }

    if (mx[0] == mx[1]) {
        cout << "Bob\n";
    } else {
        cout << "Alice\n";
    }
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