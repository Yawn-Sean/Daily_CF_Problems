#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

constexpr int inf = 1E9;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    using A = std::array<int, 2>;
    std::vector<std::vector<int>> adj1(n);
    std::vector<std::vector<int>> adj2(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        u--;
        v--;
        adj1[v].push_back(u);
        adj2[u].push_back(v);
    }

    int k;
    std::cin >> k;
    std::vector<int> a(k);
    for (int i = 0; i < k; i++) {
        std::cin >> a[i];
        a[i]--;
    }

    int s = a.front(), t = a.back();
    std::vector<int> d(n, inf);
    std::priority_queue<A, std::vector<A>, std::greater<>> pq;
    d[t] = 0;
    pq.push({d[t], t});
    while (!pq.empty()) {
        auto [_, x] = pq.top();
        pq.pop();

        for (auto &y : adj1[x]) {
            if (chmin(d[y], d[x] + 1)) {
                pq.push({d[y], y});
            }
        }
    }

    std::pair<int, int> ans;
    for (int i = 0; i < k - 1; i++) {
        int x = a[i];
        int min = inf;
        for (auto &y : adj2[x]) {
            if (y == a[i + 1]) {
                continue;
            }
            chmin(min, d[y]);
        }

        if (min < d[a[i + 1]]) {
            ans.first++;
            ans.second++;
        } else if (d[a[i + 1]] == min) {
            ans.second++;
        }
    }
    std::cout << ans.first << " " << ans.second << "\n";

    return 0;
}
