#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m;
	cin >> n >> m;
	
	vector<int> r(n + 1), c(n + 1);
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		r[x]++; c[y]++;
	}
		
	/*		
		行已经放了rc个
		列已经放了cc个
		
		没有影响 p1 = rc*cc / n^2
		新增一行 p2 = (n-rc)*cc/		
		新增一列 p3 = (n-cc)*rc
		新增行+列 (n-rc)(n-cc)/n2
		
		dp[i][j]: 还需要i行,j列有颜色 就到目标状态(n行n列都有颜色)所需要的期望步数
		dp[i][j] = 1 + p1*dp[i][j] + p2 * dp[i - 1][j] + p3 * dp[i][j - 1] + p4 * dp[i - 1][j - 1]
		dp[i][j] = (1 + p2 * dp[i - 1][j] + p3 * dp[i][j - 1] + p4 * dp[i - 1][j - 1]) / (1 - p1)
		答案为dp[rc][cc]
	*/
	
	int rcnt = 0, ccnt = 0;
	for (int i = 1; i <= n; i++) {
		rcnt += (r[i] > 0);
		ccnt += (c[i] > 0);
	}
	
	vector<vector<long double>> dp(n + 2, vector<long double>(n + 2));
	for (int i = 1; i <= n; i++) {
		dp[i][0] = dp[i - 1][0] + (long double)1.0 * n / i;
	}
	for (int j = 1; j <= n; j++) {
		dp[0][j] = dp[0][j - 1] + (long double)1.0 * n / j;
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			long double p4 = (long double)1.0 * (i * j) / (n * n); // 抽中rc都没有
			long double p3 = (long double)1.0 * ((n - i) * j) / (n * n); // 抽中r没有c
			long double p2 = (long double)1.0 * (i * (n - j)) / (n * n); // 抽中c没有r
			dp[i][j] = (long double)1.0 + p4 * dp[i - 1][j - 1] + p3 * dp[i][j - 1] + p2 * dp[i - 1][j];
			dp[i][j] /= ((long double)1.0 - (long double)1.0 * (n - i) * (n - j) / (n * n));
		}
	}
	cout << fixed << setprecision(20) << dp[n - rcnt][n - ccnt];
	return 0;
}

