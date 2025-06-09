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

    while (t --) {
        int n;
        cin >> n;

        vector<int> nums(n);
        for (auto &x: nums)
            cin >> x;
        
        int ma = *max_element(nums.begin(), nums.end());
        bool flg = true;

        for (auto &x: nums) {
            if (ma % x) {
                flg = false;
            }
        }

        if (!flg) cout << n << '\n';
        else {
            int ans = 0;

            auto solve = [&] (int v) -> int {
                int cur = 1, cnt = 0;

                for (auto &x: nums) {
                    if (v == x) return 0;
                    if (v % x == 0) {
                        cnt ++;
                        cur = cur / gcd(cur, x) * x;
                    }
                }
                return (cur == v ? cnt : 0);
            };

            for (int i = 2; i * i <= ma; i ++) {
                if (ma % i == 0) {
                    ans = max(ans, solve(i));
                    ans = max(ans, solve(ma / i));
                }
            }

            cout << ans << '\n';
        }
    }

    return 0;
}