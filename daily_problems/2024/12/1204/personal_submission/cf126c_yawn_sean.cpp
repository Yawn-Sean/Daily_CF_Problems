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

    int n;
    cin >> n;

    vector<string> grid(n);
    for (int i = 0; i < n; i ++)
        cin >> grid[i];
    
    int ans = 0;

    vector<int> r0(n, 0), c0(n, 0);

    for (int i = 0; i < n; i ++) {
        for (int j = n - 1; j > i; j --) {
            if (grid[i][j] - '0' != r0[i] ^ c0[j]) {
                ans ++;
                r0[i] ^= 1;
                c0[j] ^= 1;
            }
        }
    }

    vector<int> r1(n, 0), c1(n, 0);

    for (int i = n - 1; i >= 0; i --) {
        for (int j = 0; j < i; j ++) {
            if (grid[i][j] - '0' != r1[i] ^ c1[j]) {
                ans ++;
                r1[i] ^= 1;
                c1[j] ^= 1;
            }
        }
    }

    for (int i = 0; i < n; i ++) {
        if (grid[i][i] - '0' != r0[i] ^ c0[i] ^ r1[i] ^ c1[i]) {
            ans ++;
        }
    }

    cout << ans;

    return 0;
}