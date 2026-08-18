#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int k, s, e;
    std::cin >> k >> s >> e;
    s--, e--;

    std::vector<int> p;
    for (int i = 0; i < k; i++) {
        if (i != s && i != e) {
            p.push_back(i);
        }
    }

    std::vector<std::pair<int, int>> ans;
    for (int i = k - 1; i > 0; i--) {
        if (i == 1) {
            ans.push_back({s, e});
            continue;
        }
        ans.push_back({s, e});
        int id = k - 1 - i;
        for (int j = id + 1; j < k - 2; j++) {
            ans.push_back({s, p[j]});
        }
        ans.push_back({s, p[id]});

        for (int j = k - 3; j >= id + 1; j--) {
            ans.push_back({p[j], p[id]});
        }
        ans.push_back({e, p[id]});
    }

    for (int i = 2; i < k; i++) {
        int u = k - i - 1;
        ans.push_back({p[u], s});
        for (int j = 0; j < i - 2; j++) {
            ans.push_back({p[u], p[k - 3 - j]});
        }
        ans.push_back({p[u], e});
        for (int j = i - 3; j >= 0; j--) {
            ans.push_back({p[k - 3 - j], e});
        }
        ans.push_back({s, e});
    }

    std::cout << ans.size() << "\n";
    for (auto [x, y] : ans) {
        std::cout << x + 1 << " " << y + 1 << "\n";
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    // std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
