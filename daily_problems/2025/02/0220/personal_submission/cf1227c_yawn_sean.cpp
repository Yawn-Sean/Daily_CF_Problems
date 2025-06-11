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
        int n, k;
        string s;

        cin >> n >> k >> s;

        string target;
        for (int i = 0; i < k - 1; i ++)
            target += "()";
        target += string(n / 2 - k + 1, '(');
        target += string(n / 2 - k + 1, ')');

        vector<int> p1, p2;
        for (int i = 0; i < n; i ++) {
            if (s[i] != target[i]) {
                if (s[i] == '(') p1.emplace_back(i);
                else p2.emplace_back(i);
            }
        }

        vector<pair<int, int>> ops;

        auto op = [&] (int l, int r) -> void {
            ops.emplace_back(l + 1, r + 1);
            if (l + 1 < r - 1) ops.emplace_back(l + 2, r);
        };

        while (!p1.empty()) {
            int i1 = p1.back(), i2 = p2.back();
            p1.pop_back(), p2.pop_back();
            if (i1 > i2) swap(i1, i2);
            op(i1, i2);
        }

        cout << ops.size() << '\n';
        for (auto &[l, r]: ops)
            cout << l << ' ' << r << '\n';
    }

    return 0;
}