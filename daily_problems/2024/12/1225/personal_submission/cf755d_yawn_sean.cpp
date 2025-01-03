#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/convolution"
// #include "atcoder/dsu"
#include "atcoder/fenwicktree"
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
// I came, I divide, I conquer!

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    k = min(k, n - k);

    atcoder::fenwick_tree<int> fen(n);
    int cur = 0;
    long long res = 1;

    for (int i = 0; i < n; i ++) {
        if (cur + k <= n) res += fen.sum(cur + 1, cur + k) + 1;
        else res += fen.sum(cur + 1, n) + fen.sum(0, cur + k - n) + 1;

        fen.add(cur, 1);
        cur = (cur + k) % n;
        fen.add(cur, 1);

        cout << res << ' ';
    }

    return 0;
}