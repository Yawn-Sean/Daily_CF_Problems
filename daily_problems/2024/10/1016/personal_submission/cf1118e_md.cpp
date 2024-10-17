// 1016
#include <bits/stdc++.h>
using pii = std::pair<int, int>;
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 n, k;
    std::cin >> n >> k;
    if (n > k && n > k * (k - 1)) {
        std::cout << "NO\n";
        return 0;
    }

    std::vector<pii> results;
    for (int i = 1; i <= k && size(results) < n; ++i) {
        for (int j = i + 1; j <= k && size(results) < n; ++j) {
            results.emplace_back(i, j);
            results.emplace_back(j, i);
        }
    }

    std::cout << "YES\n";
    for (int i = 0; i < n; ++i) {
        std::cout << results[i].first << ' ' << results[i].second << '\n';
    }

    return 0;
}