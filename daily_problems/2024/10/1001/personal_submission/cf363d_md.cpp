// 1001
#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m; 
    i64 a;
    std::cin >> n >> m >> a;

    std::vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> b[i];
    }
    std::sort(begin(b), end(b), std::greater<int>());

    std::vector<int> p(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> p[i];
    }

    std::sort(begin(p), end(p));

    auto cando = [&](int k) -> bool {
        i64 sum = 0;
        for (int i = 0; i < k; ++i) {
            sum += std::max(0, p[i] - b[k - i - 1]);
        }
        return sum <= a;
    };

    int lo = 0;
    int hi = std::min(n, m);
    while (lo + 1 < hi) {
        auto mid = lo + (hi - lo) / 2;
        if (cando(mid)) {
            lo = mid;
        } else {
            hi = mid;
        }
    }

    auto minCost = [&](int k) -> i64 {
        i64 sum = 0;
        i64 cost = 0;
        for (int i = 0; i < k; ++i) {
            cost += p[i];
            sum += std::max(0, p[i] - b[k - i - 1]);
        }

        return std::max(0ll, cost - a);
    };

    if (cando(hi)) {
        std::cout << hi << ' ' << minCost(hi) << '\n';
    } else {
        std::cout << lo << ' ' << minCost(lo) << '\n';
    }

     

    return 0;
}