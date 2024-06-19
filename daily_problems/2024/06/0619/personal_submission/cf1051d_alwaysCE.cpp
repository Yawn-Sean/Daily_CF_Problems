#include <bits/stdc++.h>

using i64 = long long;

i64 mod = 998244353;

int add[4][4] = {{0, 0, 0, 1}, {1, 0, 2, 1}, {1, 2, 0, 1}, {1, 0, 0, 0}};

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, k;
	std::cin >> n >> k;
	
	std::vector<std::vector<i64> > dp(4, std::vector<i64>(k + 1, 0));
	dp[0][0] = dp[1][0] = dp[2][0] = dp[3][0] = 1;

	for (int i = 1; i < n; i++) {
		// 前面有j个分量
		std::vector<std::vector<i64> > ndp(4, std::vector<i64>(k + 1, 0));	
		// 00 01 10 11
		for (int pre = 0; pre < 4; pre++) {
			for (int cur = 0; cur < 4; cur++) {
				for (int j = add[pre][cur]; j <= k; j++) {
					ndp[cur][j] += dp[pre][j - add[pre][cur]] % mod;
				}
			}	
		}	
		
		dp = ndp;
	}
	
	
	// 最后一列的颜色
	// 00|11 +1
	// 01|10 +2
	i64 res = 0;
	for (int cur = 0; cur < 4; cur++) {
		int st;
		if (cur == 0 or cur == 3) {
			st = 1;
		} else {
			st = 2;
		}
		if (k >= st) {
			res += dp[cur][k - st] % mod;
		}
	}
			
	std::cout << res % mod << '\n';
			
	return 0;	
}
