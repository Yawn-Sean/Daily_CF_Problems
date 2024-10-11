#include <bits/stdc++.h>
// #include <ranges>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

constexpr int P = 1'000'000'007;

void solve() {
    int n, m, q;
    std::cin >> n >> m >> q;

    std::vector<int> w(n), cnt(1 << n);

    for (int i = 0; i < n; ++ i) std::cin >> w[i];

    std::vector<int> sum(1 << n);

    for (int i = 1, ed = 1 << n; i < ed; ++ i) {
        int lb = (i & -i);
        sum[i] = sum[i ^ lb] + w[n - 32 + __builtin_clz(lb)];
    }

    std::string s;
    for (int i = 0; i < m; ++ i) {
        std::cin >> s;
        int num = 0;
        for (int j = 0; j < n; ++ j)
            if (s[n - 1 - j] ^ 48)
                num |= 1 << j;
        ++ cnt[num];
    }

    std::vector<std::vector<int>> acc(101, std::vector<int>(1 << n));

    int msk = (1 << n) - 1;

    for (int i = 0, ed = 1 << n; i < ed; ++ i) {
        for (int j = 0, ed = 1 << n; j < ed; ++ j) {
            if (sum[msk ^ (i ^ j)] <= 100)
                acc[sum[msk ^ (i ^ j)]][i] += cnt[j];
        }
        for (int j = 0; j < 100; ++ j)
            acc[j + 1][i] += acc[j][i];
    }

    std::string t;

    for (int i = 0, k; i < q; ++ i) {
        std::cin >> t >> k;
        int num = 0;
        for (int j = 0; j < n; ++ j)
            if (t[n - 1 - j] ^ 48)
                num |= 1 << j;
        std::cout << acc[k][num] << '\n';
    }
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