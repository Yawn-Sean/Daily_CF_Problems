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
// I came, I divide, I conquer!

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    vector<int> prime_factor(200001);
    iota(prime_factor.begin(), prime_factor.end(), 0);

    for (int v = 2; v <= 200000; v ++) {
        if (prime_factor[v] == v) {
            for (int x = v; x <= 200000; x += v) {
                prime_factor[x] = min(prime_factor[x], v);
            }
        }
    }

    while (t --) {
        int x, y;
        cin >> x >> y;
        if (x == 1 || y == 1) {
            cout << "-1\n";
            continue;
        }
        long long ans = 1ll * prime_factor[x] * prime_factor[y];
        int g = gcd(x, y);
        if (g > 1) ans = min(ans, (long long)prime_factor[g]);
        cout << ans << '\n';
    }

    return 0;
}