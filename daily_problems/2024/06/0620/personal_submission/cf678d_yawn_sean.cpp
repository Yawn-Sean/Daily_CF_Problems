#include <bits/stdc++.h>
#pragma GCC optimize("O3")
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

    int a, b, x;
    long long n;
    cin >> a >> b >> n >> x;

    vector<vector<long long>> grid = {
        {a, b},
        {0, 1}
    };

    vector<vector<long long>> origin = {
        {x},
        {1}
    };

    int mod = 1e9 + 7;

    cout << matrix_mul(matrix_pow(grid, n, mod), origin, mod)[0][0] << '\n';

    return 0;
}