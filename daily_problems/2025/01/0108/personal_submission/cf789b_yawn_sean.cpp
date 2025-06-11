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

    long long b1;
    int q, l, m;
    cin >> b1 >> q >> l >> m;

    vector<int> nums(m);
    for (auto &v: nums) cin >> v;

    sort(nums.begin(), nums.end());
    set<int> st(nums.begin(), nums.end());

    if (abs(b1) > l) cout << 0;
    else if (b1 == 0) cout << (st.find(b1) != st.end() ? "0" : "inf");
    else if (q == 1) cout << (st.find(b1) != st.end() ? "0" : "inf");
    else if (q == -1) cout << ((st.find(b1) != st.end() && st.find(-b1) != st.end()) ? "0" : "inf");
    else if (q == 0) {
        if (st.find(0) != st.end()) cout << (st.find(b1) != st.end() ? 0 : 1);
        else cout << "inf";
    }
    else {
        int cnt = 0;
        while (abs(b1) <= l) {
            if (st.find(b1) == st.end())
                cnt ++;
            b1 *= q;
        }
        cout << cnt;
    }

    return 0;
}