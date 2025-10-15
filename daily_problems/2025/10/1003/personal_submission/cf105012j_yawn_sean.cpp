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

    int n;
    cin >> n;

    vector<long long> nums(n);
    for (auto &v: nums) cin >> v;

    vector<vector<int>> path(n);
    for (int i = 0; i < n - 1; i ++) {
        int u, v;
        cin >> u >> v;
        u --, v --;
        path[u].emplace_back(v);
        path[v].emplace_back(u);
    }

    vector<long long> dp1(n, 0), dp2(n, 0);

    auto f = [&] (long long x, long long y) -> long long {
        int v = sqrt(min(x, y));
        while (v * v < min(x, y)) v ++;
        while (v * v > min(x, y)) v --;
        return max(x, y) + v;
    };

    auto dfs1 = [&] (auto &self, int u, int p) -> void {
        dp1[u] = nums[u];
        for (auto &v: path[u]) {
            if (v != p) {
                self(self, v, u);
                dp1[u] = max(dp1[u], f(dp1[v], nums[u]));
            }
        }
    };

    dfs1(dfs1, 0, -1);

    auto dfs2 = [&] (auto &self, int u, int p) -> void {
        dp2[u] = max(dp2[u], nums[u]);

        long long v1 = dp2[u], v2 = 0;

        for (auto &v: path[u]) {
            if (v != p) {
                long long nv = f(dp1[v], nums[u]);
                if (nv > v1) swap(v1, v2), v1 = nv;
                else if (nv > v2) v2 = nv;
            }
        }

        for (auto &v: path[u]) {
            if (v != p) {
                long long nv = f(dp1[v], nums[u]);
                if (nv == v1) dp2[v] = f(v2, nums[v]);
                else dp2[v] = f(v1, nums[v]);
                self(self, v, u);
            }
        }
    };

    dfs2(dfs2, 0, -1);

    cout << max(*max_element(dp1.begin(), dp1.end()), *max_element(dp2.begin(), dp2.end()));

    return 0;
}