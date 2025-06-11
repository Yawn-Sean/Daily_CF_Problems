// 0910
#include <bits/stdc++.h>
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, T;
    std::cin >> n >> T;
    std::vector<std::pair<int, int>> problems(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> problems[i].first >> problems[i].second;
    }

    auto cando = [&](int problemSolved) {
        std::vector<int> candidates;
        for (auto[ki, cost] : problems) {
            if (problemSolved <= ki) {
                candidates.push_back(cost);
            }
        }

        int siz = ssize(candidates);
        if (siz < problemSolved) {
            return false;
        }

        std::sort(begin(candidates), end(candidates));
        auto sum = std::accumulate(begin(candidates), begin(candidates) + problemSolved, 0LL);
        return sum <= T;
    };

    int lo = 0;
    int hi = n;
    while (lo + 1 < hi) {
        auto mid = lo + (hi - lo) / 2;
        if (cando(mid)) {
            lo = mid;
        } else {
            hi = mid;
        }
    }

    int ans = lo;
    if (cando(hi)) {
        ans = hi;
    }

    std::cout << ans << '\n' << ans << std::endl;
    std::vector<std::pair<int, int>> results;
    for (int idx = 1; idx <= n; ++idx) {
        auto[ki, cost] = problems[idx - 1];
        if (ans <= ki) {
            results.emplace_back(cost, idx);
        }
    }

    std::sort(begin(results), end(results));
    for (int i = 0; i < ans; ++i) {
        std::cout << results[i].second << " \n"[i + 1 == ans];
    }

    return 0;
}