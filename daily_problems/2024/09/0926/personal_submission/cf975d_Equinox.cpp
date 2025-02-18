#include <bits/stdc++.h>

// #define DEBUG

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

constexpr int P = 1E9 + 7;
constexpr int inf32 = 1E9 + 7;
constexpr i64 inf64 = 1E18 + 7;

void solve() {
    int n, a, b;
    std::cin >> n >> a >> b;

    std::map<i64, int> lines;
    std::map<std::pair<int, int>, int> cnt;

    i64 res = 0;

    for (int i = 0, x, vx, vy; i < n; ++ i) {
        std::cin >> x >> vx >> vy;
        i64 k = vy - 1LL * vx * a;
        std::pair<int, int> p = std::pair(vx, vy);
        res += lines[k] - cnt[p];
        ++ cnt[p], ++ lines[k];
    }

    std::cout << res * 2;
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