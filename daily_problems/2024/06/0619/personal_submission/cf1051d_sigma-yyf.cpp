#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    int n, k;
    cin >> n >> k;

    vector<vector<mint>> dp(2, vector<mint>(k + 1));
    dp[1][2] = dp[0][1] = 2;
    for (int i = 1; i < n; ++i) {
        vector<vector<mint>> g(2, vector<mint>(k + 3));
        for(int j = 0; j <= k; ++j) {
            if (dp[0][j] != 0) {
                g[0][j] += dp[0][j];
                g[0][j + 1] += dp[0][j];
                g[1][j + 1] += dp[0][j] * 2;
            }
            if (dp[1][j] != 0) {
                g[0][j] += dp[1][j] * 2;
                g[1][j] += dp[1][j];
                g[1][j + 2] += dp[1][j];
            }
        }
        for (int d = 0; d < 2; ++d)
        	for (int j = 0; j <= k; ++j) 
        		dp[d][j] = g[d][j];
    }
    cout << dp[0][k] + dp[1][k] << endl;
    return 0;
}
