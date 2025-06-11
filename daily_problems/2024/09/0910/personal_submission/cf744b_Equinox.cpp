#include <bits/stdc++.h>
// #include <ranges>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

constexpr int P = 1'000'000'007;
constexpr int inf32 = 1E9 + 7;

void solve() {
    int n;
    std::cin >> n;

    auto query = [&](const std::vector<int> &q) -> std::vector<int>{
        std::cout << q.size() << '\n';
        for (int x : q) std::cout << x << ' ';
        std::cout << std::endl;
        
        std::vector<int> res(n);
        for (int i = 0; i < n; ++ i) std::cin >> res[i];
        return res;
    };

    int pcnt = 32 - __builtin_clz(n);

    std::vector<std::vector<int>> f0(n, std::vector<int>(pcnt)), f1(n, std::vector<int>(pcnt));


    for (int i = 0; i < pcnt; ++ i) {
        std::vector<int> q;
        for (int j = 1; j <= n; ++ j)
            if (j >> i & 1)
                q.push_back(j);

        auto res = query(q);
        for (int j = 0; j < n; ++ j)
            f1[j][i] = res[j];

        q.clear();
        for (int j = 1; j <= n; ++ j)
            if (!(j >> i & 1))
                q.push_back(j);

        res = query(q);
        for (int j = 0; j < n; ++ j)
            f0[j][i] = res[j];
    }

    std::cout << -1 << '\n';
    for (int i = 0; i < n; ++ i) {
        int res = inf32;
        for (int j = 0; j < pcnt; ++ j)
            if ((i + 1) >> j & 1)
                res = std::min(res, f0[i][j]);
            else
                res = std::min(res, f1[i][j]);
        std::cout << res << ' ';
    }

    std::cout << std::endl;
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