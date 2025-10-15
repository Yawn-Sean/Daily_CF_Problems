#include<bits/stdc++.h>

using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> path(n + 1);

    for (int i = 2; i <= n; i ++) {
        int p;
        cin >> p;
        path[p].emplace_back(i);
    }

    int mod = 1e9 + 7;

    auto dfs = [&] (auto &self, int u) -> pair<int, int> {
        if (path[u].size() == 0) return {1, 1};

        int v0 = 0, v1 = 1;

        for (auto &v: path[u]) {
            auto [x0, x1] = self(self, v);
            v0 = (1ll * v1 * x0 + 1ll * v0 * x1) % mod;
            v1 = 1ll * v1 * x1 % mod;
        }

        return {v0, (v0 + v1) % mod};
    };

    cout << dfs(dfs, 1).second;

    return 0;
}
