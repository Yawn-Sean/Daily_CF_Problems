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

    vector<long long> fac(20, 1);
    for (int i = 1; i < 20; i ++)
        fac[i] = i * fac[i - 1];
    
    int t;
    cin >> t;

    while (t --) {
        long long k;
        cin >> k;

        vector<int> cnt(20);
        int length;

        for (int i = 1; i <= 20; i ++) {
            cnt[k % i] ++, length = i, k /= i;
            if (!k) break;
        }

        long long ans = 0;

        int cur = 0;
        long long to_divide = 1, res = 1;

        for (int i = 0; i < length; i ++) {
            to_divide *= fac[cnt[i]];
            cur += cnt[i];
            res *= cur;
            cur --;
        }

        ans += res / to_divide;

        if (cnt[0]) {
            cnt[0] --;
            length --;

            cur = 0, to_divide = 1, res = 1;

            for (int i = 0; i < length; i ++) {
                to_divide *= fac[cnt[i]];
                cur += cnt[i];
                res *= cur;
                cur --;
            }
    
            ans -= res / to_divide;
        }

        cout << ans - 1 << '\n';
    }

    return 0;
}