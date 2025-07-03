#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's set a bit and flow!
// I came, I divided, I conquered!
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t --) {
        int n, k;
        cin >> n >> k;

        vector<int> parent(n, -1), depth(n, 0);
        vector<vector<int>> path(n);

        for (int i = 1; i < n; i ++) {
            cin >> parent[i];
            parent[i] --;
            depth[i] = depth[parent[i]] + 1;
            path[parent[i]].emplace_back(i);
        }

        int cur = 0;
        for (int i = 0; i < n; i ++) {
            if (depth[i] < k && depth[i] > depth[cur]) {
                cur = i;
            }
        }

        int cnt = depth[cur] + 1;
        vector<bool> vis(n, 0);
        vector<int> ans;

        auto dfs = [&] (auto &self, int u) -> void {
            vis[u] = 1;
            ans.emplace_back(u);
            for (auto &v: path[u]) {
                if (!vis[v] && cnt < k) {
                    cnt ++;
                    self(self, v);
                    ans.emplace_back(u);
                }
            }
        };

        while (cur >= 0) {
            dfs(dfs, cur);
            cur = parent[cur];
        }

        reverse(ans.begin(), ans.end());
        cout << ans.size() - 1 << '\n';
        for (auto &x: ans) cout << x + 1 << ' '; cout << '\n';
    }

    return 0;
}