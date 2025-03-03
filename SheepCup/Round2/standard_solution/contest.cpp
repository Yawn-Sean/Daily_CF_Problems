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

    int n, t, l, r;
    cin >> n >> t >> l >> r;

    vector<int> cnt(100001, 0);
    for (int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        cnt[x] ++;
    }

    int saved = t, total = 0;
    for (int i = 1; i <= 100000; i ++) {
        int d = min(cnt[i], saved / i);
        total += d;
        saved -= i * d;
        cnt[i] = d;
    }
    
    vector<int> dp(r + 1, -n), ndp(r + 1, -n), que(r + 1), vals(r + 1);
    for (int i = 0; i <= min(saved, r); i ++)
        dp[i] = 0;
    
    for (int i = r; i >= 0; i --) {
        if (cnt[i]) {
            for (int j = 0; j <= r; j ++) 
                vals[j] = j >= l ? (j - l) / i + 1 : 0;
            
            for (int j = 0; j < i; j ++) {
                int left = 0, right = 0;
                for (int k = j; k <= r; k += i) {
                    if (left < right && que[left] < k - i * cnt[i])
                        left ++;
                    while (left < right && dp[que[right - 1]] - vals[que[right - 1]] <= dp[k] - vals[k])
                        right --;
                    que[right] = k;
                    right ++;
                    ndp[k] = dp[que[left]] - vals[que[left]] + vals[k];
                }
            }

            for (int j = 0; j <= r; j ++)
                dp[j] = ndp[j];
        }
    }

    cout << 1000000ll * total + *max_element(dp.begin(), dp.end());

    return 0;
}