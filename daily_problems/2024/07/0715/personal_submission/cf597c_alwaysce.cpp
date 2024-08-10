#include <bits/stdc++.h>
using i64 = long long;
i64 mod = 1000000007;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	
	int n, k;
	std::cin >> n >> k;
	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	
	Fenwick<i64> f(n);
	std::vector<i64> dp(n, 1ll);

	for (int l = 0; l < k; l++) {
		f.init(n);
		for (int i = 0; i < n; i++) {
			// 之前以i结尾长度为l的序列个数
			f.add(a[i], dp[i]);
			// 以i结尾长度为l+1的个数= 之前小于a[i]的长度为l序列个数
			dp[i] = f.sum(a[i]);
		}
	}		
	
	i64 ans = 0;
	for (int i = 0; i < n; i++) {
		ans += dp[i];
	}
	std::cout << ans << '\n';

	return 0;
}

