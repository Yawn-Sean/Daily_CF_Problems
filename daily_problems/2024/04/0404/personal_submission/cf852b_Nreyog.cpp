#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

vector<vector<int>> mat_mul(vector<vector<int>>& a, vector<vector<int>>& b) { // 给定n x p和p x m的两个矩阵a和b, 求a x b
    int n = a.size(), p = a[0].size(), m = b[0].size();
    int mod = 1e9 + 7;
    vector<vector<int>> c(n, vector<int> (m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < p; k++) {
                c[i][j] = (((a[i][k] * b[k][j]) % mod + c[i][j]) % mod + mod) % mod;
            }
        }
    }
    return c;
}

vector<vector<int>> mat_pow(vector<vector<int>>& a, int b) {    // 求矩阵a的b次方
    int n = a.size();
    vector<vector<int>> res(n, vector<int> (n));
    for (int i = 0; i < n; i++) {   // 把res初始化为n阶单位矩阵
        res[i][i] = 1;
    }
    while (b) {
        if (b & 1) {
            res = mat_mul(res, a);
        }
        a = mat_mul(a, a);
        b >>= 1;
    } 
    return res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(15);
    int n, l, m;
    cin >> n >> l >> m;
    vector<vector<int>> dp;
    vector<int> b(n);
    for (int i = 0; i < m; i++) {
        dp.push_back({0});
    }
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        dp[a % m][0]++;
    }
    vector<vector<int>> g(m, vector<int> (m));
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        a %= m;
        b[i] = a;
        for (int j = 0; j < m; j++) {
            g[j][(j - a + m) % m]++;
        }
    }
    g = mat_pow(g, l - 2);
    dp = mat_mul(g, dp);
    int res = 0, mod = 1e9 + 7;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        a %= m;
        res = (res + dp[(2 * m - a - b[i]) % m][0]) % mod;
    }
    cout << res << endl;
    return 0;
}
