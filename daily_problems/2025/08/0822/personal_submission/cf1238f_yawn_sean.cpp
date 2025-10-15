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
        int n;
        cin >> n;

        vector<vector<int>> path(n);
        for (int i = 0; i < n - 1; i ++) {
            int u, v;
            cin >> u >> v;
            u --, v --;
            path[u].emplace_back(v);
            path[v].emplace_back(u);
        }

        int ans = 0, inf = n;
        auto dfs = [&] (auto &self, int u, int p) -> int {
            int x1 = -inf, x2 = -inf;
            for (auto &v: path[u]) {
                if (v != p) {
                    auto res = self(self, v, u);
                    if (res > x1) swap(x1, x2), x1 = res;
                    else if (res > x2) x2 = res;
                }
            }

            int sons_count = path[u].size();
            if (u) sons_count --;

            int to_return = max(1, x1 + 1 + (sons_count - 1));
            ans = max(ans, to_return);
            ans = max(ans, x1 + x2 + 1 + ((int)path[u].size() - 2));

            return to_return;
        };

        dfs(dfs, 0, -1);
        cout << ans << '\n';
    }

    return 0;
}