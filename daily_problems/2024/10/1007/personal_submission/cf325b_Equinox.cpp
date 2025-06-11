#include <bits/stdc++.h>

// #define DEBUG

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

constexpr int inf32 = 1E9 + 7;
constexpr i64 inf64 = 1E18 + 7;

void solve() {
    i64 n;
    std::cin >> n;

    bool f = 0;
    for (int i = 0; i < 60; ++ i) {
        i64 v = 1LL << i;
        i64 lo = 0, hi = std::min(1LL << 31, n / std::max(v - 1, 1LL));

        while (lo < hi) {
            i64 x = lo + (hi - lo) / 2;
            if (x * (v - 1) + x * (x - 1) / 2 >= n) hi = x;
            else lo = x + 1;
        }

        if (hi * (v - 1) + hi * (hi - 1) / 2 == n && (hi & 1)) {
            std::cout << hi * v << '\n';
            f = true;
        }
    }

    if (!f) std::cout << "-1\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

#ifdef DEBUG
    int cur = clock();
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int t = 1;
    // std::cin >> t;

    while (t--) {
        solve();
    }
#ifdef DEBUG
    std::cerr << "run-time: " << clock() - cur << '\n';
#endif
    return 0;
}