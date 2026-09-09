#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    std::vector<std::pair<int, int>> v(3);
    for (int i = 0; i < 3; i++) {
        std::cin >> v[i].first;
        v[i].second = i;
    }
    std::sort(v.begin(), v.end(), std::greater<>());

    std::vector g(v[1].first, std::vector<int>(v[0].first));

    int u = 0;

    std::vector<int> h(v[2].first);
    std::iota(h.begin(), h.end(), 1);
    for (int i = 0; i < v[1].first; i++) {
        for (int j = 0; j < v[0].first; j++) {
            g[i][j] = h[(i + j) % v[2].first];
        }
    }


    std::vector<std::array<int, 3>> ans(v[0].first * v[1].first);
    int cur = 0;
    for (int i = 0; i < v[0].first; i++) {
        for (int j = 0; j < v[1].first; j++) {
            ans[cur][v[0].second] = i + 1;
            ans[cur][v[1].second] = j + 1;
            ans[cur][v[2].second] = g[j][i] % v[2].first + 1;
            cur++;
        }
    }
    std::cout << ans.size() << "\n";
    for (auto [x, y, z] : ans) {
        std::cout << x << " " << y << " " << z << "\n";
    }

}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
