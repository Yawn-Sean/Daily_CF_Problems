#include <bits/stdc++.h>
// #include <ranges>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

constexpr int P = 998244353;
constexpr int inf32 = 1E9 + 7;
constexpr i64 inf64 = 1E18 + 7;

void solve() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(m);
    std::vector<std::vector<int>> vals(n);

    i64 tot = 0;

    for (int i = 0; i < m; ++ i) {
        std::cin >> a[i];
        -- a[i];
        if (i && a[i] != a[i - 1]) {
            vals[a[i]].push_back(a[i - 1]);
            vals[a[i - 1]].push_back(a[i]);
            tot += abs(a[i] - a[i - 1]);
        }
    }

    i64 res = tot;

    for (int i = 0; i < n; ++ i) {
        if (vals[i].empty()) continue;
        std::ranges::sort(vals[i]);
        int m = vals[i][vals[i].size() / 2];
        i64 s = 0, t = 0;
        for (int x : vals[i])
            s += abs(x - m), t += abs(x - i);
        if (tot + s - t < res) res = tot + s - t;
    }

    std::cout << res;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t = 1;
    // std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}