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

    int t;
    cin >> t;

    vector<long long> f(32, 0);
    for (int i = 1; i < 32; i ++)
        f[i] = 4 * f[i - 1] + 1;
    
    while (t --) {
        long long n, k;
        cin >> n >> k;

        if (n > 31) cout << "YES " << n - 1 << '\n';
        else {
            int ans = -1;
            for (int i = 0; i < n; i ++) {
                int cuts = n - i;
                long long left = (1ll << (cuts + 1)) - 2 - cuts;
                long long right = f[n] - ((1ll << (cuts + 1)) - 1) * f[i];
                if (left <= k && k <= right) {
                    ans = i;
                    break;
                }
            }

            if (ans == -1) cout << "NO\n";
            else cout << "YES " << ans << '\n';
        }
    }

    return 0;
}