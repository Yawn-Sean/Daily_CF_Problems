#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/convolution"
// #include "atcoder/dsu"
// #include "atcoder/lazysegtree"
// #include "atcoder/fenwicktree"
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

    vector<int> xs(n), ys(n);
    int r;
    for (int i = 0; i < n; i ++)
        cin >> xs[i] >> ys[i] >> r;

    auto solve = [&] (vector<int> lst) -> void {
        cout << string(n - 1, '(');
        for (int i = 0; i < n; i ++) {
            if (i) cout << '+';
            cout << '(' << lst[i] / 2 << "*((1-abs((t-" << i << ")))+abs((1-abs((t-" << i << "))))))";
            if (i) cout << ')';
        }
        cout << '\n';
    };

    solve(xs);
    solve(ys);

    return 0;
}