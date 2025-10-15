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

    vector<vector<int>> ars(n);
    for (int i = 0; i < n; i ++) {
        int k;
        cin >> k;

        while (k --) {
            int x;
            cin >> x;
            ars[i].emplace_back(x);
        }

        sort(ars[i].begin(), ars[i].end());
    }

    int ans = 0;

    auto count_in_interval = [&] (vector<int> &ar, int l, int r) -> int {
        return lower_bound(ar.begin(), ar.end(), r) - lower_bound(ar.begin(), ar.end(), l);
    };

    for (int i = 0; i < n; i ++) {
        for (int j = 1; j < ars[i].size(); j ++) {
            ans += count_in_interval(ars[(i + 1) % n], ars[i][j - 1], ars[i][j]) != count_in_interval(ars[(i + n - 1) % n], ars[i][j - 1], ars[i][j]);
        }
    }
    cout << ans;

    return 0;
}