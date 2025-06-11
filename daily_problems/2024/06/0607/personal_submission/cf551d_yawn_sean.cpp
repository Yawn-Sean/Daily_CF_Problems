#include <bits/stdc++.h>
using namespace std;

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

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long n, k;
    int l, mod;

    cin >> n >> k >> l >> mod;

    vector<vector<long long>> grid(4, vector<long long>(4));

    for (int i = 0; i < 2; i ++)
        for (int j = 0; j < 2; j ++)
            for (int ni = 0; ni < 2; ni ++)
                grid[i * 2 + j][ni * 2 + (j | (i & ni))] ++;


    grid = matrix_pow(grid, n, mod);

    vector<vector<long long>> orig(1, vector<long long>(4));
    orig[0][0] = 1;

    orig = matrix_mul(orig, grid, mod);

    int c0 = (orig[0][0] + orig[0][2]) % mod;
    int c1 = (orig[0][1] + orig[0][3]) % mod;

    if (64 - __builtin_clzll(k) > l && k)
        cout << 0 << '\n';
    else {
        long long ans = 1 % mod;
        for (int i = 0; i < l; i ++) 
            ans *= (k >> i & 1 ? c1 : c0), ans %= mod;
        cout << ans << '\n';
    }

    return 0;
}