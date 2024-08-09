#include <bits/stdc++.h>
// #include <ranges>
// #define DEBUG
using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
constexpr int inf32 = 1E9 + 7;
constexpr i64 inf64 = 1E18 + 7;
constexpr double eps = 1E-9;

void solve() {
    int n, m;
    std::cin >> n >> m;

    if (!m) {
        std::cout << "3 ";
        std::cout << 1LL * n * (n - 1) * (n - 2) / 6;
        return;
    }

    std::vector<std::vector<int>> adj(n);

    for (int i = 0, u, v; i < m; ++ i) {
        std::cin >> u >> v;
        -- u, -- v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    std::vector<int> col(n), cnt, cnt1, cnt2;

    auto dfs = [&](auto&& self, int u, int c) -> bool {
        col[u] = c;
        cnt[cnt.size() - 1] ++;
        if (c == 1)
            cnt1[cnt.size() - 1] ++;
        else
            cnt2[cnt.size() - 1] ++;
        for (int v : adj[u]) {
            if (!col[v]) {
                if (!self(self, v, 3 - c))
                    return false;
            }
            else if (col[v] == c) {
                return false;
            }   
        }
        return true;
    };

    int ma = 0;

    for (int i = 0; i < n; ++ i) 
        if (!col[i]) {
            cnt.emplace_back();
            cnt1.emplace_back();
            cnt2.emplace_back();
            if (!dfs(dfs, i, 1)) {
                std::cout << "0 1";
                return;
            }
            ma = std::max(ma, cnt.back());
        }


    if (ma == 2) {
        std::cout << "2 ";
        std::cout << 1LL * m * (n - 2);
    }
    else {
        i64 res = 0;
        for (int i = 0; i < cnt.size(); ++ i) {
            res += 1LL * cnt1[i] * (cnt1[i] - 1) / 2 + 1LL * cnt2[i] * (cnt2[i] - 1) / 2;
        }
        std::cout << "1 ";
        std::cout << res;
    }
}

auto FIO = []{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
} ();

int main() {
    #ifdef DEBUG
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif     

    int t = 1;
    // std::cin >> t;
    while (t --)
        solve();

    return 0;
}