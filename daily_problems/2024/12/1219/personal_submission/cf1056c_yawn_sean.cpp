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

    int n, m;
    cin >> n >> m;

    vector<int> powers(2 * n + 1, 0), prs(2 * n + 1, 0), used(2 * n + 1, 0);

    for (int i = 1; i <= 2 * n; i ++)
        cin >> powers[i];

    while (m --) {
        int x, y;
        cin >> x >> y;
        prs[x] = y;
        prs[y] = x;
    }

    int t, last = 0;
    cin >> t;

    for (int i = 0; i < n; i ++) {
        if (t == 2) {
            cin >> last;
            used[last] = 1;
        }

        if (last && prs[last] && !used[prs[last]]) {
            cout << prs[last] << endl;
            used[prs[last]] = 1;
        }
        else {
            int v = -1, chosen = 0;
            for (int i = 1; i <= 2 * n; i ++) {
                if (prs[i] && !used[i] && powers[i] - powers[prs[i]] > v) {
                    v = powers[i] - powers[prs[i]];
                    chosen = i;
                }
            }
            if (!chosen) {
                for (int i = 1; i <= 2 * n; i ++) {
                    if (!used[i] && powers[i] > v) {
                        v = powers[i];
                        chosen = i;
                    }
                }
            }
            cout << chosen << endl;
            used[chosen] = 1;
        }

        if (t == 1) {
            cin >> last;
            used[last] = 1;
        }
    }

    return 0;
}