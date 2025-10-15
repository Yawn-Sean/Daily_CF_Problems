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
    int total_s = 0, total_l = 0;

    for (auto &x: ss) cin >> x, total_s += x;
    for (auto &x: ls) cin >> x, total_l += x;

    vector<vector<long long>> grid(2, vector<long long>(2, 0));

    for (int i = 0; i < n; i ++) {
        grid[0][0] = (grid[0][0] + (ss[i] + ls[i]) * ss[i]) % mod;
        grid[0][1] = (grid[0][1] + (ss[i] + ls[i]) * ls[i]) % mod;
        grid[1][0] = (grid[1][0] + ss[i] * ss[i]) % mod;
        grid[1][1] = (grid[1][1] + ss[i] * ls[i]) % mod;
    }

    auto res = matrix_pow(grid, k - 1, mod);

    int ans = 0;

    ans += (1ll * ss[0] * res[0][0] % mod + 1ll * ls[0] * res[1][0] % mod) % mod * (total_s + total_l) % mod;
    ans %= mod;

    ans += (1ll * ss[0] * res[0][1] % mod + 1ll * ls[0] * res[1][1] % mod) % mod * total_s % mod;
    ans %= mod;

    cout << ans;

    return 0;
}