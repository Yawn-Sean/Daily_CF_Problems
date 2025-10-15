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

    vector<vector<pair<int, int>>> path(n);
    while (m --) {
        int u, v;
        cin >> u >> v;
        u --, v --;
        path[u].emplace_back(v, 1);
        path[v].emplace_back(u, -1);
    }

    int note = 1e6, ans = 0;
    vector<int> cols(n, note);

    auto dfs = [&] (auto &self, int u) -> void {
        for (auto &[v, w]: path[u]) {
            if (cols[v] == note) {
                cols[v] = cols[u] + w;
                self(self, v);
            }
            else ans = gcd(ans, abs(cols[u] + w - cols[v]));
        }
    };

    for (int i = 0; i < n; i ++) {
        if (cols[i] == note) {
            cols[i] = 0;
            dfs(dfs, i);
        }
    }

    cout << (ans ? ans : n);

    return 0;
}