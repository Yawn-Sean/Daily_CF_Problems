#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/convolution"
// #include "atcoder/dsu"
// #include "atcoder/fenwicktree"
// #include "atcoder/lazysegtree"
// #include "atcoder/math"
// #include "atcoder/maxflow"
// #include "atcoder/mincostflow"
// #include "atcoder/modint"
// #include "atcoder/scc"
// #include "atcoder/segtree"
// #include "atcoder/string"
// #include "atcoder/twosat"
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;
using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's set a bit and flow!
// I came, I divided, I conquered!

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> path(n);
    vector<string> strs(n);

    for (int i = 1; i < n; i ++) {
        int p;
        cin >> p >> strs[i];
        p --;
        path[p].emplace_back(i);
    }

    string s;
    cin >> s;

    int k = s.size();

    int pw = rng();
    long long mod = rngl();

    pw = (pw % 70 + 70) % 70 + 130;
    mod = abs(mod) & ((1ll << 52) - 1);

    long long hash_s = 0, pws = 1;
    for (auto &c: s)
        hash_s = (hash_s * pw + c) % mod, pws = pws * pw % mod;

    int ans = 0;
    vector<__int128_t> hsh = {0};

    auto dfs = [&] (auto &self, int u) -> void {
        for (auto &c: strs[u]) {
            hsh.emplace_back((hsh.back() * pw + c) % mod);
            if (hsh.size() > k) {
                int l = hsh.size();
                long long res = ((hsh[l - 1] - hsh[l - k - 1] * pws) % mod + mod) % mod;
                if (res == hash_s) ans ++;
            }
        }

        for (auto &v: path[u])
            self(self, v);

        for (int i = 0; i < strs[u].size(); i ++)
            hsh.pop_back();
    };

    dfs(dfs, 0);
    cout << ans;

    return 0;
}