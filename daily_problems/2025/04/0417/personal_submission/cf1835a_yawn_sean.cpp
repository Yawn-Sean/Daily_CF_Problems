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
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
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

    int t;
    cin >> t;

    auto find_interval = [&] (int x) -> pair<int, int> {
        int l = 1, r = 10;
        while (x > 1)
            x --, l *= 10, r *= 10;
        return {l, r - 1};
    };

    while (t --) {
        int a, b, c;
        long long k;
        cin >> a >> b >> c >> k;
        auto [la, ra] = find_interval(a);
        auto [lb, rb] = find_interval(b);
        auto [lc, rc] = find_interval(c);

        bool flg = false;

        for (int x = la; x <= ra; x ++) {
            int l = max(lb, lc - x), r = min(rb, rc - x);
            
            if (l <= r) {
                int diff = r - l + 1;
                if (k <= diff) {
                    flg = true;
                    int y = l + k - 1;
                    cout << x << " + " << y << " = " << x + y << '\n';
                    break;
                }
                else k -= diff;
            }
        }

        if (!flg) cout << "-1\n";
    }

    return 0;
}