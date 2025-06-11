#include <bits/stdc++.h>
using i64 = long long;
i64 mod = 1000000007;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	// dp[l][x]: 长度为l 字符和为x的字符串个数
	int n = 100;
	std::vector<std::vector<i64>> dp(n + 1, std::vector<i64>(25 * n + 2));
	dp[0][0] = 1;
	
	std::vector<i64> dp_acc(25 * n + 2);
	
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= 25 * n; j++) {
			dp_acc[j + 1] = (dp_acc[j] + dp[i - 1][j]) % mod;
		}
		
		for (int j = 0; j <= 25 * i; j++) {
			dp[i][j] = (dp_acc[j + 1] - dp_acc[std::max(j - 25, 0)] + mod) % mod;
		}
	}
	
	int t;
	std::cin >> t;
	while (t--) {
		std::string s;
		std::cin >> s;
		int l = (int)s.size(), x = 0;
		for (auto& c: s) {
			x += (c - 'a');
		}
		std::cout << (dp[l][x] > 0 ? dp[l][x] - 1 : mod - 1) << '\n';
	}
	return 0;
}
