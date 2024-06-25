https://codeforces.com/contest/1498/submission/263558910

Z dp[M][M][2];
Z cdp[M][M][2];

void solve() {
    int n, k; cin >> n >> k;
    for (int i = 1; i <= n; i++){
    	dp[1][i][0] = dp[1][i][1] = 1;
    	for (int j = 0; j < 2; j++){
    		cdp[1][i][j] = cdp[1][i - 1][j] + dp[1][i][j];
    	}
    }
    for (int j = 2; j <= k; j++){
    	for (int i = 1; i <= n; i++){
    		dp[j][i][0] = 1 + cdp[j - 1][n][1] - cdp[j - 1][i - 1][1];
    		dp[j][i][1] = 1 + cdp[j - 1][i][0] - cdp[j - 1][1][0];

    		for (int q = 0; q < 2; q++){
    			cdp[j][i][q] = cdp[j][i - 1][q] + dp[j][i][q];
    		}
    	}
    }
    cout << dp[k][1][0].val() << "\n";

}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}