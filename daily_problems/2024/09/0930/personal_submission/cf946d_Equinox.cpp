#include <bits/stdc++.h>

// #define DEBUG

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

constexpr int inf32 = 1E9 + 7;
constexpr i64 inf64 = 1E18 + 7;

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<int> f(k + 1);
    int ans = 0;

    for (int i = 0; i < n; ++ i) {
        std::string st;
        std::cin >> st;
        std::vector<int> id;
        for (int j = 0; j < m; ++ j)
            if (st[j] ^ 48)
                id.push_back(j);
        if (id.empty()) continue;

        int gap = id.back() - id[0] + 1;
        ans += gap;

        int len = id.size();
        std::vector<int> max(len + 1);
        max[len] = gap;
        for (int j = 0; j < len; ++ j)
            for (int x = j; x < len; ++ x)
                max[len - (x - j + 1)] = std::max(max[len - (x - j + 1)], gap - (id[x] - id[j] + 1));


        for (int j = k; j; -- j) {
            for (int x = 0, ed = std::min(j, len); x <= len; ++ x) {
                if (j < x) break;
                f[j] = std::max(f[j], f[j - x] + max[x]);
            }
        }
    }
    std::cout << ans - f[k] << '\n';
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