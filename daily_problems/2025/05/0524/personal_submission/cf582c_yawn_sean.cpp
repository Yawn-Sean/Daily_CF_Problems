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

    int n;
    cin >> n;

    vector<int> nums(n);
    for (auto &v: nums)
        cin >> v;

    vector<int> gcds(n);
    for (int i = 1; i < n; i ++)
        gcds[i] = gcd(i, n);
    
    long long ans = 0;
    for (int i = 1; i < n; i ++) {
        if (n % i == 0) {
            vector<int> ma(i, 0);
            for (int j = 0; j < n; j ++)
                ma[j % i] = max(ma[j % i], nums[j]);

            vector<bool> flg(2 * n, 0);
            for (int j = 0; j < n; j ++)
                if (nums[j] == ma[j % i])
                    flg[j] = 1, flg[j + n] = 1;
            
            vector<int> acc(n + 1, 0);
            int cur = 0;
            for (int j = 2 * n - 1; j >= 0; j --) {
                cur = (flg[j] ? cur + 1 : 0);
                if (j < n) acc[min(cur, n)] ++;
            }


            for (int j = n; j > 0; j --)
                acc[j - 1] += acc[j];
            
            for (int j = i; j < n; j += i)
                if (gcds[j] == i)
                    ans += acc[j];
        }
    }

    cout << ans;

    return 0;
}