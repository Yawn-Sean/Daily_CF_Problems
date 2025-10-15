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

    int n;
    string k;

    cin >> n >> k;

    int r = k.size() - 1;
    long long tmp = 1, ans = 0;

    while (r >= 0) {
        int l = r;
        long long cur = k[r] - '0', v = 1;

        for (int i = r - 1; i >= max(0, r - 17); i --) {
            v *= 10;
            if (v * (k[i] - '0') + cur < n) {
                l = i;
                cur += v * (k[i] - '0');
            }
            else break;
        }

        while (l < r && k[l] == '0')
            l ++;
        
        ans += cur * tmp;
        tmp *= n;

        r = l - 1;
    }

    cout << ans;

    return 0;
}