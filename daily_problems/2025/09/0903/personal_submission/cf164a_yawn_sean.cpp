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

    int n, m;
    cin >> n >> m;

    vector<int> nums(n);
    for (auto &x: nums) cin >> x;

    vector<vector<int>> path(n), rev_path(n);
    for (int i = 0; i < m; i ++) {
        int u, v;
        cin >> u >> v;
        u --, v --;
        path[u].emplace_back(v);
        rev_path[v].emplace_back(u);
    }

    vector<int> vis1(n, 0), vis2(n, 0);

    auto dfs1 = [&] (auto &self, int u) -> void {
        vis1[u] = 1;
        for (auto &v: path[u]) {
            if (!vis1[v] && nums[v] != 1) {
                self(self, v);
            }
        }
    };

    for (int i = 0; i < n; i ++)
        if (nums[i] == 1) dfs1(dfs1, i);
    
    auto dfs2 = [&] (auto &self, int u) -> void {
        vis2[u] = 1;
        if (nums[u] == 1) return ;

        for (auto &v: rev_path[u]) {
            if (!vis2[v]) {
                self(self, v);
            }
        }
    };

    for (int i = 0; i < n; i ++)
        if (nums[i] == 2) dfs2(dfs2, i);
    
    for (int i = 0; i < n; i ++)
        cout << (vis1[i] & vis2[i]) << '\n';

    return 0;
}