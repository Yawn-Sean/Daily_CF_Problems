#include <bits/stdc++.h>
using i64 = long long;
using namespace std;
i64 mod = 1e9+7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
    int n, m;
    cin >> n >> m;
    vector<vector<int>> path(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        --u;--v;
        path[u].push_back(v);
        path[v].push_back(u);
    }

    int k, lim;
    cin >> k >> lim; 
	// dfs(u, fa, fa_col, cnt_m)
    // dp[cnt=k][node] node为根子树内部 有cnt个顶点=k
    vector<vector<i64>> dp1(lim + 1, vector<i64>(n, 0));
    vector<vector<i64>> dp2(lim + 1, vector<i64>(n, 0));
    vector<vector<i64>> dp3(lim + 1, vector<i64>(n, 0));
    for (int i = 0; i < n; i++) {
        dp1[0][i] = k - 1;
        dp2[1][i] = 1;
        dp3[0][i] = m - k;
    }

    function<void(int,int)> dfs = [&](int u, int p) {
        for (auto& v: path[u]) {
            if (v != p) {
                dfs(v, u);
                // 取<k色
                for (int num_k = lim; num_k >= 0; --num_k) {
                    i64 res = 0;
                    for (int i = 0; i <= num_k; i++) {
                        res += (dp1[i][v] + dp2[i][v] + dp3[i][v]) * dp1[num_k - i][u] % mod;
                    }
                    dp1[num_k][u] = res % mod;
                }
                // u取=k色
                for (int num_k = lim; num_k >= 0; --num_k) {
                    i64 res = 0;
                    for (int i = 0; i <= num_k; i++) {
                        res += dp1[i][v] * dp2[num_k - i][u] % mod;
                    }
                    dp2[num_k][u] = res % mod;
                }
                // 取>k色
                for (int num_k = lim; num_k >= 0; --num_k) {
                    i64 res = 0;
                    for (int i = 0; i <= num_k; i++) {
                        res += (dp1[i][v] + dp3[i][v]) * dp3[num_k - i][u] % mod;
                    }
                    dp3[num_k][u] = res % mod;
                }
            }
        }
    };
    dfs(0, -1);
    i64 ans = 0;
    for (int i = 0; i <= lim; i++) {
        ans += (dp1[i][0] + dp2[i][0] + dp3[i][0]) % mod;
    }
    cout << ans % mod;
    return 0;
}
