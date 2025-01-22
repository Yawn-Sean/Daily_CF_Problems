#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 mod = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n,m,k;
	cin >> n >> m >> k;
	
	string s, t;
	cin >> s >> t;
	
	/*
		k很小 nmk^2不能接受
		假设[i][j]选择了 
		i+1,j+1开始的任意长度字符串
		(i,j) -> (i',j')
	*/
	vector<vector<int>> dp(n + 1, vector<int>(m + 1));
	for (int c = 1; c <= k; c++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (s[i - 1] == t[j - 1]) {
					dp[i][j] = dp[i - 1][j - 1] + 1;
				}
			}
		}
		
		// (i,j)不发生匹配
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				dp[i][j] = max(dp[i][j], max(dp[i - 1][j], dp[i][j - 1]));
			}
		}
	}
	
	cout << dp[n][m];
    return 0;
}
