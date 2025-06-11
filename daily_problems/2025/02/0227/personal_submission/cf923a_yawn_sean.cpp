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

    int M = 1e6;
    vector<int> prime_factor(M + 1);

    iota(prime_factor.begin(), prime_factor.end(), 0);
    for (int i = 2; i <= M; i ++) {
        if (prime_factor[i] == i) {
            for (int j = i; j <= M; j += i) {
                prime_factor[j] = i;
            }
        }
    }

    int x2;
    cin >> x2;

    int ans = x2;

    for (int x1 = x2 - prime_factor[x2] + 1; x1 <= x2; x1 ++) {
        if (prime_factor[x1] != x1) {
            ans = min(ans, x1 - prime_factor[x1] + 1);
        }
    }

    cout << ans;

    return 0;
}