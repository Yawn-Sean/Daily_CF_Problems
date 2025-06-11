#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mod = 998244353;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, t;
	long double p;
	cin >> n >> p >> t;
	
	vector<vector<long double>> dp(t + 1, vector<long double>(n + 1));
	// dp[t][n]: t秒有n人进入电梯的概率
	dp[0][0] = 1.0;
	
	for (int i = 1; i <= t; i++) {
		for (int j = 0; j <= n; j++) {
			if (j == 0) {
				dp[i][j] += dp[i - 1][j] * ((long double)1.0 - p);
			} else if (j < n) {
				dp[i][j] += dp[i-1][j-1]*p + dp[i-1][j]*((long double)1.0 - p);
			} else {
				dp[i][j] += dp[i-1][j-1]*p + dp[i-1][j];
			}
		}
	}
	
	long double ans = 0.0;
	for (int j = 0; j <= n; j++) {
		ans += dp[t][j] * j;
	}
	cout << fixed << setprecision(10) << ans;
	return 0;
}
