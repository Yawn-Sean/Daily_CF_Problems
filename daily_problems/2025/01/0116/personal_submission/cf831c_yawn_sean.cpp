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

    int n, k;
    cin >> n >> k;

    vector<int> marks(n);
    for (auto &v: marks) cin >> v;

    vector<int> points(k);
    for (auto &v: points) cin >> v;

    for (int i = 1; i < n; i ++)
        marks[i] += marks[i - 1];


    set<int> st(marks.begin(), marks.end());

    int ans = 0;
    for (auto &v: st) {
        int start = points[0] - v;
        bool flg = true;

        for (auto &x: points)
            flg = (flg && st.find(x - start) != st.end());
        
        ans += flg;
    }

    cout << ans << '\n';

    return 0;
}