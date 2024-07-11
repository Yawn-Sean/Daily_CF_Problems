#include <bits/stdc++.h>
using i64 = long long;
using i128 = __int128;
using PII = std::pair<int, int>;
using PIII = std::pair<int, PII>;
const int inf = 1e9 + 7, P = 1e9 + 7;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> g(n);
    for (int i = 0, a, b; i < m; ++ i)
        std::cin >> a >> b,
        -- a, -- b,
        g[a].push_back(b);

    std::vector<int> cnt(n);
    int res = 0;
    for (int i = 0; i < n; ++ i) {
        for (int j : g[i])
            for (int k : g[j])
                ++ cnt[k];
        for (int j = 0; j < n; ++ j) {
            if (i != j)
                res += (cnt[j] - 1) * cnt[j] / 2;
            cnt[j] = 0;
        }
    }
    std::cout << res;
}


int main(int argc, char** argv) {
    std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0);
    int _ = 1;
    // std::cin >> _;
    while (_ --)
        solve();
    return 0;
}