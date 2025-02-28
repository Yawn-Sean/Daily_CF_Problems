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

    int n, q;
    cin >> n >> q;

    vector<int> cnt(n + 1, 0), unread(n + 1, 0), stk;
    int pt = 0, ans = 0;

    for (int i = 0; i < q; i ++) {
        int t, x;
        cin >> t >> x;

        if (t == 1) {
            ans ++, cnt[x] ++;
            stk.emplace_back(x);
        }
        else if (t == 2) {
            ans -= cnt[x];
            cnt[x] = 0;
            unread[x] = stk.size();
        }
        else {
            while (pt < x) {
                if (pt >= unread[stk[pt]])
                    ans --, cnt[stk[pt]] --;
                pt ++;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}