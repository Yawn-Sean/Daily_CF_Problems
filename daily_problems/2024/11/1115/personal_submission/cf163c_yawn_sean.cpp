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


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, v1, v2;
    long long l;

    cin >> n >> l >> v1 >> v2;
    long long tmp = l * v2;
    l *= v1 + v2;

    map<long long, int> diff;
    for (int i = 0; i < n; i ++) {
        long long x;
        cin >> x;
        x *= v1 + v2;
        if (x + tmp <= l * 2) {
            diff[x] ++;
            diff[x + tmp] --;
        }
        else {
            diff[x] ++;
            diff[l * 2] --;
            diff[0] ++;
            diff[x + tmp - 2 * l] --;
        }
    }

    diff[2 * l] += 0;

    vector<long long> ans(n + 1, 0);
    long long last = 0;
    int cur = 0;

    for (auto &[k, v]: diff) {
        ans[cur] += k - last;
        cur += v;
        last = k;
    }

    cout << fixed << setprecision(30);
    for (auto &x: ans)
        cout << (long double)1.0 * x / (2 * l) << '\n';

    return 0;
}