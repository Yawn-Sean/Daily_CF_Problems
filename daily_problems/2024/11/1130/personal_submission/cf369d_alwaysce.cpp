#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf = 1000000007;

i64 mod = 1e9+7;

i64 pow(i64 base, i64 exp, i64 mod) {
	i64 ans = 1ll;
	base %= mod;
	while (exp) {
		if (exp & 1) {
			ans = ans * base % mod;
		}
		base = base * base % mod;
		exp >>= 1;
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, k;
	cin >> n >> k;
	
	vector<int> p(n);
	for (auto& x: p) { cin >> x; }
	
	/*
		每一轮操作 hit数字最小的人
		除了mn以外的剩余所有人都会打mn
		mn 会打 mn+1
		所以每一轮 -1 / -2 / -0
	
		dp[i][j]: 最后剩下的人里 两个最小为 i,j 标号人的概率
		
		从(i,j)转移的可能有
		i寄了 j没有寄 (>=j有一个干掉了i && p[i]!=100)
		
		j寄了 i没有寄 (p[i]!= 0 and >=j后面不能有100 )
		
		ij都寄了 (>=j后面 至少有大于0的 && p[i]!=0 )
			
	*/
	vector<int> must(n + 1, 0), cant(n + 1, 1);
	for (int i = n - 1; i >= 0; i--) {
		must[i] = must[i + 1] | (p[i] == 100);
		cant[i] = cant[i + 1] & (p[i] == 0);
	}
	
	vector<vector<int>> dp(n + 2, vector<int>(n + 2, inf));
	dp[0][1] = 0;
	
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (dp[i][j] < n) {
				// j寄了
				if (must[j] == 0 and p[i] > 0) {
					dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + 1);
				}
				// i寄了
				if (cant[j] == 0 and p[i] < 100) {
					dp[j][j + 1] = min(dp[j][j + 1], dp[i][j] + 1);
				}
				// ij都寄了
				if (cant[j] == 0 and p[i] > 0) {
					dp[j + 1][j + 2] = min(dp[j + 1][j + 2], dp[i][j] + 1);
				}
			}
		}
	}
	
	int ans = 0;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n + 1; j++) {
			ans += (dp[i][j] <= k);
		}
	}
	cout << ans;
	return 0;
}
