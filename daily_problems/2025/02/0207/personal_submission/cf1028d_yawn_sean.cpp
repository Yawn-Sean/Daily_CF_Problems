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
    cin >> n;

    int mod = 1e9 + 7, l = 0, r = 1e9;
    set<int> st;
    st.emplace(l), st.emplace(r);

    int v = 0;

    while (n --) {
        string op;
        int x;
        cin >> op >> x;

        if (op[1] == 'D') st.emplace(x);
        else {
            auto p = st.lower_bound(x);
            if (x > l && x < r) v ++;
            if (x < l || x > r) return cout << 0, 0;
            p ++;
            r = *p;
            p --, p --;
            l = *p;
            p ++;
            st.erase(p);
        }
    }

    int ans = 1;
    for (auto &x: st) {
        if (x > l && x < r) {
            ans ++;
        }
    }

    for (int i = 0; i < v; i ++) {
        ans += ans;
        if (ans >= mod) ans -= mod;
    }

    cout << ans;

    return 0;
}