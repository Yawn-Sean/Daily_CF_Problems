#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    vector<vector<int>> g(n);
    for (int i = 1, p; i < n; i++) {
        scanf("%d", &p);
        g[p - 1].push_back(i);
    }
    vector<int> orders{0};
    vector<int> ans(q, -1);
    vector<vector<pair<int, int>>> mp(n);
    for (int i = 0, u, k; i < q; i++) {
        scanf("%d%d", &u, &k);
        u -= 1;
        mp[u].emplace_back(k, i);
    }
    auto dfs = [&] (this auto dfs, int u) -> int {
        int res = 1;
        for (auto& v : g[u]) {
            orders.push_back(v);
            res += dfs(v);
        }
        int curr = orders.size() - res;
        for (auto&[k, i] : mp[u]) if (k <= res) {
            ans[i] = orders[curr + k - 1] + 1;
        }
        return res;
    };
    dfs(0);
    for (int i = 0; i < q; i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}

