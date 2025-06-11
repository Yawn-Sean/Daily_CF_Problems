#include <bits/stdc++.h>

// #define DEBUG

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

constexpr int inf32 = 1E9 + 7;
constexpr i64 inf64 = 1E18 + 7;

void solve() {
    int n, m, a;
    std::cin >> n >> m >> a;

    std::vector<int> b(n);
    for (int i = 0; i < n; ++ i)
        std::cin >> b[i]; 
    std::vector<int> p(m);
    for (int i = 0; i < m; ++ i)
        std::cin >> p[i];

    std::ranges::sort(b);
    std::ranges::sort(p);

    auto check = [&](int cnt) -> bool {
        i64 res = 0;
        for (int i = 0; i < cnt; ++ i)
            res += std::max(0, p[i] - b[n - cnt + i]);
        return res <= a;
    };

    int lo = 0, hi = std::min(n, m);

    while (lo < hi) {
        int x = (lo + hi + 1) / 2;
        if (check(x)) lo = x;
        else hi = x - 1;
    }

    std::cout << lo << ' ' << std::max(0LL, std::accumulate(p.begin(), p.begin() + lo, 0LL) - a);
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