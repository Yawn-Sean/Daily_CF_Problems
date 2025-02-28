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

// Let's flow!

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> ans(n + 1);
    iota(ans.begin(), ans.end(), 0);

    auto solve = [&] (auto &self, int l, int r) -> void {
        if (l > r) return ;
        int length = r - l + 1;
        int v = 1 << (31 - __builtin_clz(length));

        for (int i = l; i <= r - v; i ++)
            ans[i] ^= v;
        
        for (int i = l + v; i <= r; i ++)
            ans[i] ^= v;
        
        for (int i = r - v + 1; i <= r; i ++)
            ans[i] ^= v - 1;
        
        self(self, l, r - v);
    };
    
    solve(solve, 0, n);

    cout << 1ll * n * (n + 1) << '\n';
    for (auto &v: ans)
        cout << v << ' ';

    return 0;
}