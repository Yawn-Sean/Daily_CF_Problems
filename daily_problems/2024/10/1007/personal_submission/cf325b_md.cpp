// 1007
#include <bits/stdc++.h>
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 n;
    std::cin >> n;

    std::vector<i64> ans;
    for (i64 i = 0; i < 60; ++i) {
        i64 v = (1ll << i);
        i64 l = 0;
        i64 r = std::min(1ll << 31, n / std::max(v - 1, 1ll));

        auto GetMatchCount = [v](i64 mid) -> i64 {
            return (mid - 1) * mid / 2 + mid * (v - 1);
        };

        while (l + 1 < r) {
            i64 mid = l + (r - l) / 2;
            if (GetMatchCount(mid) <= n) {
                l = mid;
            } else {
                r = mid;
            }
        }

        i64 val = -1;
        if (GetMatchCount(l) == n && (l & 1)) {
            val = l;
        } else if (GetMatchCount(r) == n && (r & 1)) {
            val = r;
        }

        if (val != -1) {
            ans.push_back(v * val);
        }
    }

    if (empty(ans)) {
        std::cout << "-1\n";
    } else {
        for (auto v : ans) {
            std::cout << v << "\n";
        }
    }

    return 0;
}