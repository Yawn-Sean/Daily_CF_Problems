#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> cnt(n + 1, 0);
    while (m --) {
        int x, y;
        cin >> x >> y;
        cnt[x] ++;
        cnt[y] ++;
    }

    long long angles = 0;
    for (int i = 1; i <= n; i ++) {
        angles += 1ll * cnt[i] * (n - 1 - cnt[i]);
    }

    cout << (1ll * n * (n - 1) * (n - 2) / 6 - angles / 2);

    return 0;
}