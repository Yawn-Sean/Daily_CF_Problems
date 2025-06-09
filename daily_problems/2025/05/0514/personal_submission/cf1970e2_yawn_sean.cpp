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
// I came, I divided, I conquered!

vector<vector<long long>> matrix_mul(vector<vector<long long>> grid1, vector<vector<long long>> grid2, long long mod) {
    int n = grid1.size(), m = grid1[0].size(), x = grid2[0].size();
    vector<vector<long long>> ans(n, vector<long long>(x));
    for (int i = 0; i < n; i ++) 
        for (int j = 0; j < m; j ++)
            for (int k = 0; k < x; k ++)
                ans[i][k] += grid1[i][j] * grid2[j][k], ans[i][k] %= mod;
    return ans;
}

vector<vector<long long>> matrix_pow(vector<vector<long long>> grid, long long power, long long mod) {
    if (power == 1)
        return grid;
    int n = grid.size();
    if (power == 0) {
        vector<vector<long long>> ans(n, vector<long long>(n));
        for (int i = 0; i < n; i ++)
            ans[i][i] = 1;
        return ans;
    }
    vector<vector<long long>> ans = matrix_pow(grid, power / 2, mod);
    if (power & 1)
        return matrix_mul(matrix_mul(ans, ans, mod), grid, mod);
    return matrix_mul(ans, ans, mod);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k, mod = 1e9 + 7;
    cin >> n >> k;

    vector<int> ss(n), ls(n);
    for (int i = 0; i < n; i ++) cin >> ss[i];
    for (int i = 0; i < n; i ++) cin >> ls[i];
    for (int i = 0; i < n; i ++) ss[i] += ls[i];

    vector<vector<long long>> grid(n, vector<long long>(n));
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            grid[i][j] = ss[i] * ss[j] - ls[i] * ls[j];
        }
    }

    auto res = matrix_pow(grid, k, mod);
    
    int ans = 0;
    for (int i = 0; i < n; i ++) {
        ans += res[0][i];
        if (ans >= mod) ans -= mod;
    }

    cout << ans;

    return 0;
}