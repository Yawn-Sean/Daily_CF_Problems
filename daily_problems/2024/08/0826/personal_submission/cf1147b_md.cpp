#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    std::set<std::pair<int, int>> edges;
    for (int i = 0; i < m; ++i) {
        int x, y;
        std::cin >> x >> y;
        --x, --y;
        if (x > y) {
            std::swap(x, y);
        }
        edges.insert({x, y});
    }

    int tmp_n = n;
    for (int i = 2; i <= tmp_n; ++i) {
        bool found{ true };
        if (tmp_n % i == 0) {
            while (tmp_n % i == 0) {
                tmp_n /= i;
            }

            int step = n / i;
            for (auto[u, v] : edges) {
                u = (u + step) % n;
                v = (v + step) % n;
                if (u > v) {
                    std::swap(u, v);
                }

                if (!edges.contains({u, v})) {
                    found = false;
                    break;
                }
            }

            if (found) {
                std::cout << "Yes\n";
                return 0;
            }
        }
    }
    std::cout << "No\n";

    return 0;
}