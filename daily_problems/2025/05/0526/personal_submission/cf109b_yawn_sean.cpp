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

    vector<int> lucky_numbers;

    auto dfs = [&] (auto &self, long long cur) -> void {
        if (cur >= 1'000'000'000) return ;
        lucky_numbers.emplace_back(cur);
        self(self, cur * 10 + 4);
        self(self, cur * 10 + 7);
    };

    dfs(dfs, 4), dfs(dfs, 7);
    lucky_numbers.emplace_back(0);
    lucky_numbers.emplace_back(1'000'000'001);
    sort(lucky_numbers.begin(), lucky_numbers.end());

    int pl, pr, vl, vr, k, n = lucky_numbers.size();
    cin >> pl >> pr >> vl >> vr >> k;

    auto calc = [&] (int xl, int xr, int yl, int yr) -> int {
        return max(0, min(xr, yr) - max(xl, yl) + 1);
    };

    long long ans = 0;

    for (int i = 0; i < n - k - 1; i ++) {
        int l1 = lucky_numbers[i] + 1, r1 = lucky_numbers[i + 1];
        int l2 = lucky_numbers[i + k], r2 = lucky_numbers[i + k + 1] - 1;

        ans += 1ll * calc(l1, r1, pl, pr) * calc(l2, r2, vl, vr);
        ans += 1ll * calc(l1, r1, vl, vr) * calc(l2, r2, pl, pr);
    }

    if (k == 1) {
        for (int i = 1; i < n - 1; i ++) {
            if (lucky_numbers[i] >= pl && lucky_numbers[i] >= vl && lucky_numbers[i] <= pr && lucky_numbers[i] <= vr) {
                ans --;
            }
        }
    }

    cout << fixed << setprecision(15) << (long double)1.0 * ans / (pr - pl + 1) / (vr - vl + 1);

    return 0;
}