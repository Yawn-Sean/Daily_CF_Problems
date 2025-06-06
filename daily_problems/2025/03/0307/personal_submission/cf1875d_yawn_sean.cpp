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

    int t, inf = 1e8;
    cin >> t;

    while (t --) {
        int n;
        cin >> n;

        vector<int> cnt(n + 1);
        for (int i = 0; i < n; i ++) {
            int x;
            cin >> x;
            if (x < n) cnt[x] ++;
        }

        vector<int> dp(n + 1, inf);
        dp[n] = 0;
        
        for (int i = n - 1; i >= 0; i --) {
            for (int j = i + 1; j <= n; j ++) {
                dp[i] = min(dp[i], dp[j] + j * cnt[i]);
            }
        }

        int ans = dp[0];
        for (int i = 0; i <= n; i ++) {
            if (!cnt[i]) {
                ans -= i;
                break;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}