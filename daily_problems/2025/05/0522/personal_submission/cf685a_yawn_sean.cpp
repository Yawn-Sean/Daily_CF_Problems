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

    int n, m;
    cin >> n >> m;

    auto dfs = [&] (auto &self, int idx, int val, int msk, int &digit, int &bound, vector<int> &cnt) -> void {
        if (idx == digit) {
            if (val < bound) cnt[msk] ++;
            return ;
        }
        for (int i = 0; i < 7; i ++) {
            if (msk >> i & 1) continue;
            self(self, idx + 1, val * 7 + i, msk | (1 << i), digit, bound, cnt);
        }
    };

    auto f = [&] (int x) -> vector<int> {
        vector<int> ans(128, 0);
        int tmp = x - 1, length = 0;
        while (tmp) tmp /= 7, length ++;
        length = max(length, 1);

        dfs(dfs, 0, 0, 0, length, x, ans);
        return ans;
    };

    auto cnt1 = f(n), cnt2 = f(m);

    int ans = 0;
    for (int i = 0; i < 128; i ++) {
        for (int j = 0; j < 128; j ++) {
            if (i & j) continue;
            ans += cnt1[i] * cnt2[j];
        }
    }

    cout << ans;

    return 0;
}