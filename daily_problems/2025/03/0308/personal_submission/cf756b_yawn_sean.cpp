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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> nums(n + 1, -2000);
    for (int i = 1; i <= n; i ++)
        cin >> nums[i];
    
    vector<int> dp(n + 1, 0);
    int p1 = 0, p2 = 0;

    for (int i = 1; i <= n; i ++) {
        dp[i] = dp[i - 1] + 20;
        while (nums[i] - nums[p1] >= 90) p1 ++;
        dp[i] = min(dp[i], dp[p1 - 1] + 50);
        while (nums[i] - nums[p2] >= 1440) p2 ++;
        dp[i] = min(dp[i], dp[p2 - 1] + 120);
    }

    for (int i = 0; i < n; i ++)
        cout << dp[i + 1] - dp[i] << '\n';

    return 0;
}