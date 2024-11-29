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

vector<long double> mul(vector<long double> &v1, vector<long double> &v2) {
    vector<long double> ans(128, 0);
    for (int i = 0; i < 128; i ++) {
        for (int j = 0; j < 128; j ++) {
            ans[i ^ j] += v1[i] * v2[j];
        }
    }
    return ans;
}

vector<long double> quickPow(vector<long double> &grid, int n) {
    if (n == 1) return grid;
    vector<long double> ans = quickPow(grid, n / 2);
    ans = mul(ans, ans);
    if (n & 1) ans = mul(ans, grid);
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    vector<long double> grid(128, 0);
    for (int i = 0; i <= k; i ++) {
        cin >> grid[i];
    }

    cout << fixed << setprecision(20) << ((long double)1.0 - quickPow(grid, n)[0]);

    return 0;
}