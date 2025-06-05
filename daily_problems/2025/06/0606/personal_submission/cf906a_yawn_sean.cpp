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
using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's set a bit and flow!
// I came, I divided, I conquered!
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    int msk1 = (1 << 26) - 1, msk2 = 0;
    int flg = 0, ans = 0;

    for (int i = 0; i < n - 1; i ++) {
        char c;
        cin >> c;

        if (c != '.') ans += flg;

        string w;
        cin >> w;

        int cur_msk = 0;
        for (auto &ch: w)
            cur_msk |= 1 << ch - 'a';
        
        if (c == '!') msk1 &= cur_msk;
        else msk2 |= cur_msk;
        
        int val = msk1 - (msk1 & msk2);
        if ((val & -val) == val) flg = 1;
    }

    cout << ans;

    return 0;
}