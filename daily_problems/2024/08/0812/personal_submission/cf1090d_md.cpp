// 0812
#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    std::set<std::pair<int, int>> st;

    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u; --v;
        // keep u <= v
        if (u > v) {
            std::swap(u, v);
        }
        st.insert({u, v});
    }

    if (m == n * (n - 1) / 2) {
        std::cout << "NO\n";
        return 0;
    }

    bool found = false;
    std::optional<int> x = std::nullopt;
    std::optional<int> y = std::nullopt;
    for (int i = 0; i < n && !found; ++i) {
        for (int j = i + 1; j < n && !found; ++j) {
            if (!st.contains(std::make_pair(i, j))) {
                found = true;
                x = i;
                y = j;
            }
        }
    }

    std::vector<int> ret(n, 0);
    int cur = 0;
    for (int i = 0; i < n; ++i) {
        if (i == x.value() || i == y.value()) {
            continue;
        }
        ret[i] = ++cur;
    }

    ret[x.value()] = ++cur;
    ret[y.value()] = ++cur;
    
    std::cout << "YES\n";
    for (auto e : ret) {
        std::cout << e << ' ';
    }
    std::cout << '\n';

    ret[x.value()] = ret[y.value()];
    for (auto e : ret) {
        std::cout << e << ' ';
    }
    std::cout << '\n';
    

    return 0;
}