#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;

void soviet() {
	int n; std::cin >> n;
	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i++){
		std::cin >> a[i];
	}
	std::sort(a.begin() + 1, a.end());

	std::vector dp(n + 1, std::vector<long long> (n + 1, 0));
	auto dp_sum = dp;

	for (int i = 1; i <= n; i++) {
		int idx = 1;
		for (int j = i + 1; j <= n; j++) {
			while (idx < i && a[idx] + a[i] <= a[j]) idx++;
			dp[i][j] = (dp_sum[idx - 1][i] + 1) % mod;
			dp_sum[i][j] = (dp_sum[i - 1][j] + dp[i][j]) % mod;
		}
	}

	long long ans = n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			ans = (ans + dp[i][j]) % mod;
		}
	}
	std::cout << ans;
}

int main() {
	int M_T = 1; std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
//	std::cin >> M_T;
	while (M_T--) { soviet(); }
	return 0;
}
