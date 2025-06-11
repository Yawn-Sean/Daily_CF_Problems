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

    int t;
    cin >> t;

    while (t --) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> ars(m);
        vector<int> ans(m), cnt(n + 1);
        int chosen = 0;

        for (int i = 0; i < m; i ++) {
            int k;
            cin >> k;
            ars[i] = vector<int>(k);
            for (auto &v: ars[i])
                cin >> v;
            
            ans[i] = ars[i][0];
            cnt[ans[i]] ++;
            if (cnt[ans[i]] > cnt[chosen])
                chosen = ans[i];
        }

        int ma_freq = m - m / 2;
        for (int i = 0; i < m; i ++) {
            if (ans[i] == chosen && cnt[chosen] > ma_freq && ars[i].size() > 1) {
                ans[i] = ars[i][1];
                cnt[chosen] --;
            }
        }

        if (cnt[chosen] <= ma_freq) {
            cout << "YES\n";
            for (auto &v: ans)
                cout << v << ' ';
            cout << '\n';
        }
        else cout << "NO\n";
    }

    return 0;
}