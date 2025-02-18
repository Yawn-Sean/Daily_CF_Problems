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

    cout << "YES\n";

    vector<string> ans(4, string(n, '.'));
    if (k % 2 == 0) {
        for (int i = 1; i <= k / 2; i ++)
            ans[1][i] = '#', ans[2][i] = '#';
    }
    else {
        int v = k / 2;
        ans[1][n / 2] = '#';

        for (int i = 1; i <= 2; i ++) {
            for (int j = 1; j < n / 2; j ++) {
                if (v) {
                    v --;
                    ans[i][j] = '#';
                    ans[i][n - j - 1] = '#';
                }
            }
        }
    }

    for (auto &line: ans)
        cout << line << '\n';

    return 0;
}