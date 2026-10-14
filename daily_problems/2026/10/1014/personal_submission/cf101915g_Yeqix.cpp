#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;
namespace rgs = ranges;

constexpr int inf = 1e9;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<vector<array<int, 2>>> edge(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edge[u].push_back({v, w});
        edge[v].push_back({u, w});
    }

    multiset<int> st;
    for (int i = 1; i <= q; i++) {
        int x;
        cin >> x;
        st.insert(x);
    }

    for (int i = 1; i <= n; i++) {
        sort(edge[i].begin(), edge[i].end(), [&](auto x, auto y) { return x[1] > y[1]; });
    }

    auto get = [&](int l, int r, int cl, int cr, int id) -> array<int, 3> { return {max(l, cl), min(r, cr), id}; };

    vector<array<int, 3>> lst(n + 1);
    vector<int> dep(n + 1);
    auto dfs = [&](this auto&& dfs, int u, int fa) -> void {
        dep[u] = dep[fa] + 1;
        auto [l, r, id] = lst[u];
        int pre = inf;
        for (const auto& [v, w] : edge[u]) {
            if (v == fa) {
                continue;
            }
            int cl = w + 1, cr = pre;
            lst[v] = get(l, r, cl, cr, v);
            pre = w;
            dfs(v, u);
        }
    };
    lst[1] = {0, inf, 1};
    dfs(1, 0);

    sort(lst.begin() + 1, lst.end(), [&](auto x, auto y) { return dep[x[2]] > dep[y[2]]; });

    i64 ans = 0;
    for (int i = 1; i <= n; i++) {
        auto [l, r, id] = lst[i];
        if (l > r) {
            continue;
        }
        auto itl = st.lower_bound(l), itr = st.upper_bound(r);
        for (auto it = itl; it != itr; it++) {
            ans += id;
        }
        st.erase(itl, itr);
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