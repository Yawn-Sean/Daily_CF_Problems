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
// I came, I divided, I conquered!

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for (auto &v: nums)
        cin >> v;
    
    if (k == 1)
        return cout << 1ll * n * (n + 1) / 2, 0;
    
    map<int, int> primes;
    for (int i = 2; i <= k; i ++) {
        while (k % i == 0) {
            primes[i] ++;
            k /= i;
        }
        if (i * i > k) break;
    }

    if (k > 1) primes[k] ++;

    int l = 0, r = 0;
    map<int, int> cur;

    auto check = [&] () -> bool {
        for (auto &[p, _]: primes) {
            if (primes[p] > cur[p]) {
                return false;
            }
        }
        return true;
    };

    long long ans = 0;
    int v;
    while (l < n) {
        while (r < n && !check()) {
            v = nums[r];
            for (auto &[p, _]: primes) {
                while (v % p == 0) {
                    cur[p] ++;
                    v /= p;
                }
            }
            r ++;
        }

        if (!check()) break;
        ans += n + 1 - r;

        v = nums[l];
        for (auto &[p, _]: primes) {
            while (v % p == 0) {
                cur[p] --;
                v /= p;
            }
        }
        l ++;
    }

    cout << ans << '\n';

    return 0;
}