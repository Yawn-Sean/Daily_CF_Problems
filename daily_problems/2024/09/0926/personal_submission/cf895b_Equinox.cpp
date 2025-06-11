#include <bits/stdc++.h>

// #define DEBUG

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

constexpr int P = 1E9 + 7;
constexpr int inf32 = 1E9 + 7;
constexpr i64 inf64 = 1E18 + 7;

constexpr int N = 2E5;

void solve() {
    int n, x, k;
    std::cin >> n >> x >> k;

    std::vector<int> a(n);

    for (int i = 0; i < n; ++ i) {
        std::cin >> a[i];
    }

    std::ranges::sort(a);

    i64 res = 0;

    for (int v : a) {
        int o = (v - 1) / x + k;
        res += std::lower_bound(a.begin(), a.end(), 1LL * (o + 1) * x) - std::lower_bound(a.begin(), a.end(), std::max<i64>(1LL * o * x, v));
    }

    std::cout << res;
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