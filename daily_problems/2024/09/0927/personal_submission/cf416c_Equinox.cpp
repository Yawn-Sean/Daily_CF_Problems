#include <bits/stdc++.h>

// #define DEBUG

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

constexpr int inf32 = 1E9 + 7;
constexpr i64 inf64 = 1E18 + 7;

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> c(n), p(n);
    for (int i = 0; i < n; ++ i)
        std::cin >> c[i] >> p[i];

    int k;
    std::cin >> k;
    std::vector<int> r(k);

    for (int i = 0; i < k; ++ i)
        std::cin >> r[i];

    std::vector<int> id(n);
    std::iota(id.begin(), id.end(), 0);

    std::ranges::sort(id, [&](int i, int j) -> bool{
        return c[i] < c[j];
    });

    std::vector<int> table(k);
    std::iota(table.begin(), table.end(), 0);
    std::ranges::sort(table, [&r](int i, int j){
        return r[i] < r[j];
    });

    std::priority_queue<std::pair<int, int>> pq;
    int res = 0;
    std::vector<std::pair<int, int>> ans;
    int j = 0;
    for (int i : table) {
        while (j < n && c[id[j]] <= r[i]) {
            pq.emplace(p[id[j]], id[j]);
            ++ j;
        }
        if (pq.size()) {
            auto [a, b] = pq.top();
            pq.pop();
            ans.emplace_back(b, i);
            res += a;
        }
    }

    std::cout << ans.size() << ' ' << res << '\n';
    for (auto &[x, y] : ans)
        std::cout << x + 1 << ' ' << y + 1 << '\n';
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