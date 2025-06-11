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

    int n, m, c;
    cin >> n >> m >> c;

    int bound = c / 2, not_used = n;
    vector<int> ans(n, -1);

    while (not_used) {
        int v;
        cin >> v;
        if (v <= bound) {
            for (int i = 0; i < n; i ++) {
                if (ans[i] == -1 || ans[i] > v) {
                    cout << i + 1 << endl;
                    not_used -= (ans[i] == -1);
                    ans[i] = v;
                    break;
                }
            }
        }
        else {
            for (int i = n - 1; i >= 0; i --) {
                if (ans[i] == -1 || ans[i] < v) {
                    cout << i + 1 << endl;
                    not_used -= (ans[i] == -1);
                    ans[i] = v;
                    break;
                }
            }
        }
    }

    return 0;
}