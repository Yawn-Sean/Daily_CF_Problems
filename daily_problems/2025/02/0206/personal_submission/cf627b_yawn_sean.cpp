#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/convolution"
// #include "atcoder/dsu"
#include "atcoder/fenwicktree"
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

    int n, k, a, b, q;
    cin >> n >> k >> a >> b >> q;

    vector<int> nums1(n, 0), nums2(n, 0);
    atcoder::fenwick_tree<int> fen1(n), fen2(n);

    while (q --) {
        int t;
        cin >> t;
        if (t == 1) {
            int x, y;
            cin >> x >> y;
            x --;

            int v;
            v = min(nums1[x] + y, b) - nums1[x];
            nums1[x] += v;
            fen1.add(x, v);

            v = min(nums2[x] + y, a) - nums2[x];
            nums2[x] += v;
            fen2.add(x, v);
        }
        else {
            int x;
            cin >> x;
            x --;
            cout << fen1.sum(0, x) + fen2.sum(x + k, n) << '\n';
        }
    }

    return 0;
}